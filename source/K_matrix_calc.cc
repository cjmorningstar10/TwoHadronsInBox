#include "K_matrix_calc.h"

using namespace std;

// ****************************************************************


KtildeMatrixCalculator::~KtildeMatrixCalculator()
{
 for (std::map<KElementInfo,FitForm*>::iterator 
    it=m_fit.begin();it!=m_fit.end();it++)
       delete it->second;
}


KtildeMatrixCalculator::KtildeMatrixCalculator(XMLHandler& xmlin)
{
 XMLHandler xmlk(xmlin,"KtildeMatrix");
 list<XMLHandler> kelems=xmlk.find_among_children("Element");
 initialize(kelems);
}


uint KtildeMatrixCalculator::getNumberOfParameters() const
{
 return m_paraminfo.size();
}


int KtildeMatrixCalculator::getParameterIndex(const KFitParamInfo& kinfo) const 
{
 std::map<KFitParamInfo,uint>::const_iterator it;
 it=m_paramindices.find(kinfo);
 if (it==m_paramindices.end()) return -1;
 return it->second;
}


set<KElementInfo> KtildeMatrixCalculator::getElementInfos() const
{
 set<KElementInfo> res;
 std::map<KElementInfo,FitForm*>::const_iterator it;
 for (it=m_fit.begin();it!=m_fit.end();it++)
    res.insert(it->first);
 return res;
}


string KtildeMatrixCalculator::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string KtildeMatrixCalculator::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void KtildeMatrixCalculator::output(XMLHandler& xmlout) const
{
 xmlout.set_root("KtildeMatrixCalculator");
 XMLHandler xmlk("KtildeMatrix");
 for (map<KElementInfo,FitForm*>::const_iterator it=m_fit.begin();it!=m_fit.end();it++){
    XMLHandler xmle; (it->first).output(xmle);
    XMLHandler xmlf; (it->second)->output(xmlf);
    XMLHandler xmlc("Element");
    xmlc.put_child(xmle);
    xmlc.put_child(xmlf);
    xmlk.put_child(xmlc);}
 xmlout.put_child(xmlk);
 XMLHandler xmlps("FitParameterInfos");
 for (uint k=0;k<m_paraminfo.size();k++){
    XMLHandler xmlp("FitParameterInfo");
    XMLHandler xmlpp; m_paraminfo[k].output(xmlpp);
    xmlp.put_child(xmlpp);
    xmlp.put_child("Index",make_string(k));
    xmlps.put_child(xmlp);}
 xmlout.put_child(xmlps);
}



void KtildeMatrixCalculator::initialize(list<XMLHandler>& kelems)
{
 try{
 for (list<XMLHandler>::iterator it=kelems.begin();it!=kelems.end();it++){
    KElementInfo keinfo(*it);
    if (m_fit.find(keinfo)!=m_fit.end())
       throw(std::invalid_argument("Duplicate KElementInfo tag"));
    initialize_a_fitform(keinfo,*it);}
 m_paraminfo.resize(m_paramindices.size());
 for (std::map<KFitParamInfo,uint>::iterator 
    it=m_paramindices.begin();it!=m_paramindices.end();it++)
       m_paraminfo[it->second]=it->first;}
 catch(const std::exception& xp){
    throw(std::invalid_argument(string("Could not construct Kmatrix: ")+xp.what()));}
}


    //  very important class that sets up m_fit and m_paramindices

void KtildeMatrixCalculator::initialize_a_fitform(const KElementInfo& kinfo, XMLHandler& xmlin)
{
 FitForm *fptr=0;
 try{
    XMLHandler xmle(xmlin,"FitForm");
    uint count1=xmle.count_among_children("Polynomial");
    uint count2=xmle.count_among_children("SumOfPoles");
    uint count3=xmle.count_among_children("SumOfPolesPlusPolynomial");
    if ((count1+count2+count3)!=1)
       throw(std::invalid_argument("FitForm has invalid XML content"));
    if (count1==1){
       XMLHandler xmlf(xmle,"Polynomial");
       fptr=new Polynomial(xmlf);}
    else if (count2==1){
       XMLHandler xmlf(xmle,"SumOfPoles");
       fptr=new SumOfPoles(xmlf);}
    else {
       XMLHandler xmlf(xmle,"SumOfPolesPlusPolynomial");
       fptr=new SumOfPolesPlusPolynomial(xmlf);}
    fptr->Kinitialize(kinfo,m_paramindices);
    m_fit.insert(make_pair(kinfo,fptr));}

 catch(const std::exception& xp){
    delete fptr;
    throw(std::invalid_argument(string("Could not initialize a fit form: ")+xp.what()));}
}


KtildeMatrixCalculator::KtildeMatrixCalculator(const std::list<std::pair<KElementInfo,Polynomial> >& pelems,
                           const std::list<std::pair<KElementInfo,SumOfPoles> >& selems,
                           const std::list<std::pair<KElementInfo,SumOfPolesPlusPolynomial> >& spelems)
{
 FitForm *fptr=0;
 try{
 for (std::list<std::pair<KElementInfo,Polynomial> >::const_iterator 
    it=pelems.begin();it!=pelems.end();it++){
    const KElementInfo& keinfo(it->first);
    if (m_fit.find(keinfo)!=m_fit.end())
       throw(std::invalid_argument("Duplicate KElementInfo tag"));
    fptr=new Polynomial(it->second);
    fptr->Kinitialize(keinfo,m_paramindices);
    m_fit.insert(make_pair(keinfo,fptr));}
 for (std::list<std::pair<KElementInfo,SumOfPoles> >::const_iterator 
    it=selems.begin();it!=selems.end();it++){
    const KElementInfo& keinfo(it->first);
    if (m_fit.find(keinfo)!=m_fit.end())
       throw(std::invalid_argument("Duplicate KElementInfo tag"));
    fptr=new SumOfPoles(it->second);
    fptr->Kinitialize(keinfo,m_paramindices);
    m_fit.insert(make_pair(keinfo,fptr));}
 for (std::list<std::pair<KElementInfo,SumOfPolesPlusPolynomial> >::const_iterator 
    it=spelems.begin();it!=spelems.end();it++){
    const KElementInfo& keinfo(it->first);
    if (m_fit.find(keinfo)!=m_fit.end())
       throw(std::invalid_argument("Duplicate KElementInfo tag"));
    fptr=new SumOfPolesPlusPolynomial(it->second);
    fptr->Kinitialize(keinfo,m_paramindices);
    m_fit.insert(make_pair(keinfo,fptr));}
 m_paraminfo.resize(m_paramindices.size());
 for (std::map<KFitParamInfo,uint>::iterator 
    it=m_paramindices.begin();it!=m_paramindices.end();it++)
       m_paraminfo[it->second]=it->first;}
 catch(const std::exception& xp){
    throw(std::invalid_argument(string("Could not construct Kmatrix: ")+xp.what()));}
}


void KtildeMatrixCalculator::setKtildeParameters(const std::vector<double>& kappa_params)
{
 if (kappa_params.size()!=getNumberOfParameters())
    throw(std::invalid_argument("Could not set KtildeParameters"));
 m_kappa_params=kappa_params;
}


double KtildeMatrixCalculator::calculate(uint Jtimestwo, 
                       uint Lp, uint Sptimestwo, uint chanp,
                       uint L, uint Stimestwo, uint chan, 
                       double Ecm_over_mref) const
{
 if (m_kappa_params.size()<m_paraminfo.size())
    throw(std::invalid_argument("Insufficient number of parameter values in KtildeMatrixCalculator::calculate"));
 KElementInfo kelem(Jtimestwo,Lp,Sptimestwo,chanp,L,Stimestwo,chan);
 std::map<KElementInfo,FitForm*>::const_iterator it=m_fit.find(kelem);
 if (it==m_fit.end()) return 0.0;
 return (it->second)->evaluate(m_kappa_params,Ecm_over_mref);
}


bool KtildeMatrixCalculator::isZero(uint Jtimestwo, 
                       uint Lp, uint Sptimestwo, uint chanp,
                       uint L, uint Stimestwo, uint chan) const
{
 KElementInfo kelem(Jtimestwo,Lp,Sptimestwo,chanp,L,Stimestwo,chan);
 std::map<KElementInfo,FitForm*>::const_iterator it=m_fit.find(kelem);
 return (it==m_fit.end());
}


// ***************************************************************************************


KtildeInverseCalculator::~KtildeInverseCalculator()
{
 for (std::map<KElementInfo,FitForm*>::iterator 
    it=m_fit.begin();it!=m_fit.end();it++)
       delete it->second;
}


KtildeInverseCalculator::KtildeInverseCalculator(XMLHandler& xmlin)
{
 XMLHandler xmlk(xmlin,"KtildeMatrixInverse");
 list<XMLHandler> kelems=xmlk.find_among_children("Element");
 initialize(kelems);
}


uint KtildeInverseCalculator::getNumberOfParameters() const
{
 return m_paraminfo.size();
}


int KtildeInverseCalculator::getParameterIndex(const KFitParamInfo& kinfo) const 
{
 std::map<KFitParamInfo,uint>::const_iterator it;
 it=m_paramindices.find(kinfo);
 if (it==m_paramindices.end()) return -1;
 return it->second;
}


set<KElementInfo> KtildeInverseCalculator::getElementInfos() const
{
 set<KElementInfo> res;
 std::map<KElementInfo,FitForm*>::const_iterator it;
 for (it=m_fit.begin();it!=m_fit.end();it++)
    res.insert(it->first);
 return res;
}



string KtildeInverseCalculator::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string KtildeInverseCalculator::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void KtildeInverseCalculator::output(XMLHandler& xmlout) const
{
 xmlout.set_root("KtildeInverseCalculator");
 XMLHandler xmlk("KtildeMatrixInverse");
 for (map<KElementInfo,FitForm*>::const_iterator it=m_fit.begin();it!=m_fit.end();it++){
    XMLHandler xmle; (it->first).output(xmle);
    XMLHandler xmlf; (it->second)->output(xmlf);
    XMLHandler xmlc("Element");
    xmlc.put_child(xmle);
    xmlc.put_child(xmlf);
    xmlk.put_child(xmlc);}
 xmlout.put_child(xmlk);
 XMLHandler xmlps("FitParameterInfos");
 for (uint k=0;k<m_paraminfo.size();k++){
    XMLHandler xmlp("FitParameterInfo");
    XMLHandler xmlpp; m_paraminfo[k].output(xmlpp);
    xmlp.put_child(xmlpp);
    xmlp.put_child("Index",make_string(k));
    xmlps.put_child(xmlp);}
 xmlout.put_child(xmlps);
}


void KtildeInverseCalculator::initialize(list<XMLHandler>& kelems)
{
 try{
 for (list<XMLHandler>::iterator it=kelems.begin();it!=kelems.end();it++){
    KElementInfo keinfo(*it);
    if (m_fit.find(keinfo)!=m_fit.end())
       throw(std::invalid_argument("Duplicate KElementInfo tag"));
    initialize_a_fitform(keinfo,*it);}
 m_paraminfo.resize(m_paramindices.size());
 for (std::map<KFitParamInfo,uint>::iterator 
    it=m_paramindices.begin();it!=m_paramindices.end();it++)
       m_paraminfo[it->second]=it->first;}
 catch(const std::exception& xp){
    throw(std::invalid_argument(string("Could not construct Kmatrix: ")+xp.what()));}
}


    //  very important class that sets up m_fit and m_paramindices
    //  written as static class so can be used by KtildeInverseCalculator too


void KtildeInverseCalculator::initialize_a_fitform(const KElementInfo& kinfo, XMLHandler& xmlin)
{
 FitForm *fptr=0;
 try{
    XMLHandler xmle(xmlin,"FitForm");
    uint count1=xmle.count_among_children("Polynomial");
    if (count1!=1)
       throw(std::invalid_argument("FitForm has invalid XML content"));
    XMLHandler xmlf(xmle,"Polynomial");
    fptr=new Polynomial(xmlf);
    fptr->Kinitialize(kinfo,m_paramindices);
    m_fit.insert(make_pair(kinfo,fptr));}

 catch(const std::exception& xp){
    delete fptr;
    throw(std::invalid_argument(string("Could not initialize a fit form: ")+xp.what()));}
}



KtildeInverseCalculator::KtildeInverseCalculator(const std::list<std::pair<KElementInfo,Polynomial> >& pelems)
{
 FitForm *fptr=0;
 try{
 for (std::list<std::pair<KElementInfo,Polynomial> >::const_iterator 
    it=pelems.begin();it!=pelems.end();it++){
    const KElementInfo& keinfo(it->first);
    if (m_fit.find(keinfo)!=m_fit.end())
       throw(std::invalid_argument("Duplicate KElementInfo tag"));
    fptr=new Polynomial(it->second);
    fptr->Kinitialize(keinfo,m_paramindices);
    m_fit.insert(make_pair(keinfo,fptr));}
 m_paraminfo.resize(m_paramindices.size());
 for (std::map<KFitParamInfo,uint>::iterator 
    it=m_paramindices.begin();it!=m_paramindices.end();it++)
       m_paraminfo[it->second]=it->first;}
 catch(const std::exception& xp){
    throw(std::invalid_argument(string("Could not construct Kmatrix: ")+xp.what()));}
}


void KtildeInverseCalculator::setKtildeParameters(const std::vector<double>& kappa_params)
{
 if (kappa_params.size()!=getNumberOfParameters())
    throw(std::invalid_argument("Could not set KtildeInvParameters"));
 m_kappa_params=kappa_params;
}


double KtildeInverseCalculator::calculate(uint Jtimestwo, 
                       uint Lp, uint Sptimestwo, uint chanp,
                       uint L, uint Stimestwo, uint chan, 
                       double Ecm_over_mref) const
{
 if (m_kappa_params.size()<m_paraminfo.size())
    throw(std::invalid_argument("Insufficient number of parameter values in KtildeInverseCalculator::calculate"));
 KElementInfo kelem(Jtimestwo,Lp,Sptimestwo,chanp,L,Stimestwo,chan);
 std::map<KElementInfo,FitForm*>::const_iterator it=m_fit.find(kelem);
 if (it==m_fit.end()) return 0.0;
 return (it->second)->evaluate(m_kappa_params,Ecm_over_mref);
}


bool KtildeInverseCalculator::isZero(uint Jtimestwo, 
                       uint Lp, uint Sptimestwo, uint chanp,
                       uint L, uint Stimestwo, uint chan) const
{
 KElementInfo kelem(Jtimestwo,Lp,Sptimestwo,chanp,L,Stimestwo,chan);
 std::map<KElementInfo,FitForm*>::const_iterator it=m_fit.find(kelem);
 return (it==m_fit.end());
}

// ***************************************************************************************
