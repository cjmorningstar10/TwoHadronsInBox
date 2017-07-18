#include "fit_forms.h"

using namespace std;

// ****************************************************************

std::string FitForm::output(int indent) const 
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


std::string FitForm::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}

// ****************************************************************


Polynomial::Polynomial(uint degree)
{
 for (uint k=0;k<=degree;k++) 
    m_powers.insert(k);
}
    

Polynomial::Polynomial(const std::set<uint>& powers)
    : m_powers(powers)
{
 if (powers.empty())
    throw(std::invalid_argument("One power of nonzero coefficient required in Polynomial"));
}
 

Polynomial::Polynomial(XMLHandler& xmlin)
{
 initialize(xmlin);
}


void Polynomial::initialize(XMLHandler& xmlin)
{
 m_powers.clear();
 m_coef_indices.clear();
 try{
    XMLHandler xmlf(xmlin,"Polynomial");
    uint count1=xmlf.count_among_children("Degree");
    uint count2=xmlf.count_among_children("Powers");
    if ((count1+count2)!=1)
       throw(std::invalid_argument("Polynomial must have either <Degree> or <Powers> tag"));
    if (count1==1){
       uint deg;
       xmlreadchild(xmlf,"Degree",deg);
       for (uint k=0;k<=deg;k++) m_powers.insert(k);}
    else{
       vector<uint> ipowers; 
       xmlreadchild(xmlf,"Powers",ipowers);
       if (ipowers.empty())
          throw(std::invalid_argument("One power of nonzero coefficient required in Polynomial"));
       for (uint k=0;k<ipowers.size();k++) m_powers.insert(ipowers[k]);}}
 catch(const std::exception& xp){
    throw(std::invalid_argument(string("Could not initialize Polynomial: ")+xp.what()));}
}


void Polynomial::output(XMLHandler& xmlout) const
{
 xmlout.set_root("Polynomial");
 uint deg=0;
 for (set<uint>::iterator it=m_powers.begin();it!=m_powers.end();it++)
    if ((*it)>deg) deg=(*it);
 if (m_powers.size()==(deg+1)){
    xmlout.put_child("Degree",make_string(deg));
    return;}
 vector<uint> ipow(m_powers.begin(),m_powers.end());
 xmlout.put_child("Powers",make_string(ipow));
}

   //  sets up m_coef_indices and modifies the paramindices map

void Polynomial::Kinitialize(const KElementInfo& kinfo,
                             std::map<KFitParamInfo,uint>& paramindices)
{
 uint deg=0;
 for (set<uint>::iterator st=m_powers.begin();st!=m_powers.end();st++)
    if ((*st)>deg) deg=(*st);
 m_coef_indices.resize(deg+1);
 for (uint k=0;k<=deg;k++){
    if (m_powers.find(k)==m_powers.end())
       m_coef_indices[k]=-1;
    else{
       uint nextindex=paramindices.size();
       m_coef_indices[k]=nextindex;
       KFitParamInfo kpinfo(kinfo,k);
       paramindices.insert(make_pair(kpinfo,nextindex));}}
}
 
// ***************************************************************************************


SumOfPoles::SumOfPoles(uint numpoles)
{
 if (numpoles<1)
   throw(std::invalid_argument("Must have at least one pole in SumOfPoles"));
 for (uint k=0;k<numpoles;k++) 
    m_poleindices.insert(k);
}
    

SumOfPoles::SumOfPoles(const std::set<uint>& poleindices)
    : m_poleindices(poleindices)
{
 if (poleindices.empty())
   throw(std::invalid_argument("Must have at least one pole in SumOfPoles"));
}
 

SumOfPoles::SumOfPoles(XMLHandler& xmlin)
{
 initialize(xmlin);
}


void SumOfPoles::initialize(XMLHandler& xmlin)
{
 m_poleindices.clear();
 m_rowg.clear(); m_colg.clear(); m_poles.clear();  
 try{
    XMLHandler xmlf(xmlin,"SumOfPoles");
    uint count1=xmlf.count_among_children("NumberOfPoles");
    uint count2=xmlf.count_among_children("PoleIndices");
    if ((count1+count2)!=1)
       throw(std::invalid_argument("SumOfPoles must have either <NumberOfPoles> or <PoleIndices> tag"));
    if (count1==1){
       uint numpoles;
       xmlreadchild(xmlin,"NumberOfPoles",numpoles);
       if (numpoles<1)
          throw(std::invalid_argument("Must have at least one pole in SumOfPoles"));
       for (uint k=0;k<numpoles;k++) m_poleindices.insert(k);}
    else{
       vector<uint> ipoles;
       xmlreadchild(xmlf,"PoleIndices",ipoles);
       if (ipoles.empty())
          throw(std::invalid_argument("Must have at least one pole in SumOfPoles"));
       for (uint k=0;k<ipoles.size();k++) m_poleindices.insert(ipoles[k]);}}
 catch(const std::exception& xp){
    throw(std::invalid_argument(string("Could not initialize SumOfPoles: ")+xp.what()));}
}


void SumOfPoles::output(XMLHandler& xmlout) const
{
 xmlout.set_root("SumOfPoles");
 uint maxpoles=0;
 for (set<uint>::iterator it=m_poleindices.begin();it!=m_poleindices.end();it++)
    if ((*it)>maxpoles) maxpoles=(*it);
 if (m_poleindices.size()==(maxpoles+1)){
    xmlout.put_child("NumberOfPoles",make_string(m_poleindices.size()));
    return;}
 vector<uint> ipow(m_poleindices.begin(),m_poleindices.end());
 xmlout.put_child("PoleIndices",make_string(ipow));
}

   //  sets up m_rowg, m_colg, m_poles, and modifies the paramindices map

void SumOfPoles::Kinitialize(const KElementInfo& kinfo,
                             std::map<KFitParamInfo,uint>& paramindices)
{
 uint npoles=m_poleindices.size();
 m_rowg.resize(npoles);
 m_colg.resize(npoles);
 m_poles.resize(npoles);
 std::map<KFitParamInfo,uint>::iterator kt;
 vector<uint> poleindices(m_poleindices.begin(),m_poleindices.end());
 for (uint k=0;k<npoles;k++){
    uint Jtimestwo=kinfo.getJtimestwo();
    KFitParamInfo kpenergy(poleindices[k],Jtimestwo);
    KFitParamInfo krowg(kinfo.getRow(),poleindices[k],Jtimestwo);
    KFitParamInfo kcolg(kinfo.getColumn(),poleindices[k],Jtimestwo);
    vector<KFitParamInfo*> kptrs(3);
    kptrs[0]=&kpenergy; kptrs[1]=&krowg; kptrs[2]=&kcolg;
    vector<uint*> iptrs(3);
    iptrs[0]=&(m_poles[k]); iptrs[1]=&(m_rowg[k]); iptrs[2]=&(m_colg[k]);
    for (uint kk=0;kk<3;kk++){
       kt=paramindices.find(*(kptrs[kk]));
       if (kt!=paramindices.end()){
          (*(iptrs[kk]))= kt->second;}
       else{
          (*(iptrs[kk]))=paramindices.size(); 
          paramindices.insert(make_pair(*(kptrs[kk]),(*(iptrs[kk]))));}}}
}
    
// ***************************************************************************************


SumOfPolesPlusPolynomial::SumOfPolesPlusPolynomial(XMLHandler& xmlin)
{
 try{
    XMLHandler xmlf(xmlin,"SumOfPolesPlusPolynomial");
    m_sumpoles.initialize(xmlf);
    m_poly.initialize(xmlf);}
 catch(const std::exception& xp){
    throw(std::invalid_argument(string("Could not initialize SumOfPolesPlusPolynomial: ")
         +xp.what()));}
}


void SumOfPolesPlusPolynomial::output(XMLHandler& xmlout) const
{
 xmlout.set_root("SumOfPolesPlusPolynomial");
 XMLHandler xmls; 
 m_sumpoles.output(xmls);
 xmlout.put_child(xmls);
 m_poly.output(xmls);
 xmlout.put_child(xmls);
}

   //  sets up m_rowg, m_colg, m_poles, and modifies the paramindices map

void SumOfPolesPlusPolynomial::Kinitialize(const KElementInfo& kinfo,
                             std::map<KFitParamInfo,uint>& paramindices)
{
 m_sumpoles.Kinitialize(kinfo,paramindices);
 m_poly.Kinitialize(kinfo,paramindices);
}
    

// ***************************************************************************************
