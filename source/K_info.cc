#include "K_matrix.h"

using namespace std;

// ****************************************************************

KIndex::KIndex(uint L, uint Stimestwo, uint channel_index)
{
 check_encode(L,Stimestwo,channel_index);
}

KIndex::KIndex(XMLHandler& xmlin)
{
 uint L,Stimestwo,chan;
 XMLHandler xmlk(xmlin,"KIndex");
 uint count=0;
 if (xmlreadifchild(xmlk,"L",L)) count++;
 if (xmlreadifchild(xmlk,"Sx2",Stimestwo)) count++;
 if (xmlreadifchild(xmlk,"Chan",chan)) count++;
 if (count==0){
    string kstr; xmlread(xmlin,"KIndex",kstr,"KIndex");
    count=sscanf(kstr.c_str(),"L(%d) 2S(%d) chan(%d)",&L,&Stimestwo,&chan);}
 if (count!=3)
    throw(std::invalid_argument("Invalid XML for KIndex"));
 check_encode(L,Stimestwo,chan);
}
 


//   m_store encodes the channel index (6 bits),
//   total S times two (6 bits), total J times two (7 bits)
//   L (7 bits), occurrence index (6 bits)


void KIndex::check_encode(uint L, uint Stimestwo, uint channel_index)
{
 if ((channel_index>=16)||(Stimestwo>=16)||(L>=16))
    throw(std::invalid_argument("Unsupported KIndex value"));
 m_store=L;
 m_store<<=4; m_store|=Stimestwo;
 m_store<<=4; m_store|=channel_index;
}


string KIndex::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string KIndex::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void KIndex::output(XMLHandler& xmlout) const
{
 string ststr(" L("); ststr+=make_string(getL())+")";
 ststr+=" 2S("+make_string(getStimestwo())+")";
 ststr+=" chan("+make_string(getChannelIndex())+")";
 xmlout.set_root("KIndex",ststr);
}


// ****************************************************************

KElementInfo::KElementInfo(uint Jtimestwo, 
                 uint rowL, uint rowStimestwo, uint rowchannelindex,
                 uint colL, uint colStimestwo, uint colchannelindex)
{
 check_encode(Jtimestwo,rowL,rowStimestwo,rowchannelindex,
              colL,colStimestwo,colchannelindex);
}


KElementInfo::KElementInfo(XMLHandler& xmlin)
{
 XMLHandler xmlk(xmlin,"KElementInfo");
 uint Jtimestwo;
 xmlreadchild(xmlk,"JTimesTwo",Jtimestwo);
 list<XMLHandler> ki=xmlk.find_among_children("KIndex");
 if ((ki.size()<1)||(ki.size()>2))
    throw(std::invalid_argument("Invalid XML to KElementInfo"));
 uint rowL,rowStimestwo,rowchan,colL,colStimestwo,colchan;
 KIndex row(ki.front());
 rowL=row.getL(); rowStimestwo=row.getStimestwo();
 rowchan=row.getChannelIndex();
 if (ki.size()==1){
    colL=rowL; colStimestwo=rowStimestwo; colchan=rowchan;}
 else{
    KIndex col(*(++(ki.begin())));
    colL=col.getL(); colStimestwo=col.getStimestwo();
    colchan=col.getChannelIndex();}
 check_encode(Jtimestwo,rowL,rowStimestwo,rowchan,
              colL,colStimestwo,colchan);
}




void KElementInfo::check_encode(uint Jtimestwo, 
                 uint rowL, uint rowStimestwo, uint rowchannelindex,
                 uint colL, uint colStimestwo, uint colchannelindex)
{
 if (  (invalidJLS(Jtimestwo,rowL,rowStimestwo))
     or(invalidJLS(Jtimestwo,colL,colStimestwo)))
    throw(std::invalid_argument("Invalid JLS in KElementInfo"));
 KIndex krow(rowL,rowStimestwo,rowchannelindex);
 KIndex kcol(colL,colStimestwo,colchannelindex);
 if (krow<kcol)
    encode(Jtimestwo,krow,kcol);
 else
    encode(Jtimestwo,kcol,krow);
}


  //     m_store encodes 
  //       J (four bits)  (L'S'a') (12 bits),  (Lsa) (12 bits)
  //  Since K is real and symmetric, the (L'S'a') and (LSa)
  //  order is sorted according to how stored in "KIndex"


void KElementInfo::encode(uint Jtimestwo, 
              const KIndex& kl, const KIndex& kr)
{
 if (Jtimestwo>=16)
    throw(std::invalid_argument("Unsupported KElementInfo value"));
 m_store=Jtimestwo;
 m_store<<=12; m_store|=kl.m_store;
 m_store<<=12; m_store|=kr.m_store;
}


bool KElementInfo::invalidJLS(uint Jtimestwo, uint L, uint Stimestwo)
{
 return (((Jtimestwo%2)!=(Stimestwo%2)) 
  || ((2*L)<((Jtimestwo>=Stimestwo)?(Jtimestwo-Stimestwo):(Stimestwo-Jtimestwo)))
  || ((2*L)>(Jtimestwo+Stimestwo)));
}


string KElementInfo::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string KElementInfo::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void KElementInfo::output(XMLHandler& xmlout) const
{
 xmlout.set_root("KElementInfo");
 xmlout.put_child("JTimesTwo",make_string(getJtimestwo()));
 XMLHandler xmli; getRow().output(xmli);
 xmlout.put_child(xmli);
 getColumn().output(xmli);
 xmlout.put_child(xmli);
}


// ****************************************************************


KFitParamInfo::KFitParamInfo(XMLHandler& xmlin)
{
 XMLHandler xmlk(xmlin,"KFitParamInfo");
 uint count1=xmlk.count_among_children("PolynomialTerm");
 uint count2=xmlk.count_among_children("PoleEnergy");
 uint count3=xmlk.count_among_children("PoleCoupling");
 if ((count1+count2+count3)!=1)
    throw(std::invalid_argument("Invalid KFitParamInfo XML"));
 if (count1==1){
    XMLHandler xmlt(xmlk,"PolynomialTerm");
    uint power;
    xmlreadchild(xmlt,"Power",power);
    KElementInfo keleminfo(xmlt);
    set_poly_power(keleminfo,power);}
 else if (count2==1){
    XMLHandler xmlt(xmlk,"PoleEnergy");
    uint poleindex,Jtimestwo;
    xmlreadchild(xmlt,"Index",poleindex);
    xmlreadchild(xmlt,"JTimesTwo",Jtimestwo);
    set_pole_energy(poleindex,Jtimestwo);}
 else{
    XMLHandler xmlt(xmlk,"PoleCoupling");
    uint poleindex,Jtimestwo;
    xmlreadchild(xmlt,"Index",poleindex);
    xmlreadchild(xmlt,"JTimesTwo",Jtimestwo);
    KIndex kindex(xmlt);
    set_pole_coupling(kindex,poleindex,Jtimestwo);}
}

   //    m_store1: left-most 4 bits encode the type of parameter
   //         0 = term in a polynomial
   //         1 = pole energy
   //         2 = coupling in pole residue

   //    if polynomial: 
   //         - rightmost 28 bits of m_store1 contains "n"
   //               where parameter is coefficient of Ecm^n
   //         - m_store2 contains the m_store of the K-matrix element
   //               the polynomial is associated with

void KFitParamInfo::set_poly_power(const KElementInfo& keleminfo, uint power)
{
 if (power>32)
    throw(std::invalid_argument("Unsupported power in KFitParamInfo"));
 m_store1=power;
 m_store2=keleminfo.m_store;
}

   //    if pole energy:
   //         - m_store2 contains the integer index identifying the pole (14 bits)
   //            and total J times two (14 bits)
   //

void KFitParamInfo::set_pole_energy(uint pole_index, uint Jtimestwo)
{
 if ((pole_index>32)||(Jtimestwo>128))
    throw(std::invalid_argument("Unsupported pole information in KFitParamInfo"));
 m_store1=1;
 m_store1<<=14; m_store1|=pole_index;
 m_store1<<=14; m_store1|=Jtimestwo;
}

   //    if coupling in pole residue
   //         - rightmost 28 bits of m_store1 contain integer index
   //              identify the pole (14 bits) and total J times two (14 bits)
   //         - m_store2 contains m_store of the KIndex associated
   //              with this parameter

void KFitParamInfo::set_pole_coupling(const KIndex& kindex, uint pole_index, uint Jtimestwo)
{
 if ((pole_index>32)||(Jtimestwo>128))
    throw(std::invalid_argument("Unsupported pole information in KFitParamInfo"));
 m_store1=2;
 m_store1<<=14; m_store1|=pole_index;
 m_store1<<=14; m_store1|=Jtimestwo;
 m_store2=kindex.m_store;
}

string KFitParamInfo::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string KFitParamInfo::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void KFitParamInfo::output(XMLHandler& xmlout) const
{
 xmlout.set_root("KFitParamInfo");
 uint type=m_store1>>28;
 if (type==0){
    uint power=m_store1 & 0xFFFFFFFu;
    KElementInfo keleminfo(m_store2);
    XMLHandler xmlt("PolynomialTerm");
    xmlt.put_child("Power",make_string(power));
    XMLHandler xmlk; keleminfo.output(xmlk);
    xmlt.put_child(xmlk);
    xmlout.put_child(xmlt);}
 else if (type==1){
    uint Jtimestwo=m_store1 & 0x3FFFu;
    uint poleindex=(m_store1>>14) & 0x3FFFu;
    XMLHandler xmlt("PoleEnergy");
    xmlt.put_child("Index",make_string(poleindex));
    xmlt.put_child("JTimesTwo",make_string(Jtimestwo));
    xmlout.put_child(xmlt);}
 else if (type==2){
    uint Jtimestwo=m_store1 & 0x3FFFu;
    uint poleindex=(m_store1>>14) & 0x3FFFu;
    XMLHandler xmlt("PoleCoupling");
    xmlt.put_child("Index",make_string(poleindex));
    xmlt.put_child("JTimesTwo",make_string(Jtimestwo));
    KIndex kindex(m_store2);
    XMLHandler xmlk; kindex.output(xmlk);
    xmlt.put_child(xmlk);
    xmlout.put_child(xmlt);}
}


// ****************************************************************


KtildeMatrixCalculator::~KtildeMatrixCalculator()
{
 for (std::map<KElementInfo,std::list<FitForm*> >::iterator 
    it=m_fit.begin();it!=m_fit.end();it++)
    for (std::list<FitForm*>::iterator 
       lt=(it->second).begin();lt!=(it->second).end();lt++)
          delete *lt;
}


KtildeMatrixCalculator::KtildeMatrixCalculator(XMLHandler& xmlin)
{
 XMLHandler xmlk(xmlin,"KtildeMatrix");
 list<XMLHandler> kelems=xmlk.find_among_children("Element");
 bool allow_polynomial=true;
 bool allow_sumofpoles=true;
 initialize(kelems,allow_polynomial,allow_sumofpoles,m_fit,m_paraminfo,m_paramindices);
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
 std::map<KElementInfo,std::list<FitForm*> >::const_iterator it;
 for (it=m_fit.begin();it!=m_fit.end();it++)
    res.insert(it->first);
 return res;
}



void KtildeMatrixCalculator::initialize(list<XMLHandler>& kelems, bool allow_polynomial,
                          bool allow_sumofpoles,
                          std::map<KElementInfo,std::list<FitForm*> >& fit,
                          std::vector<KFitParamInfo>& paraminfo,
                          std::map<KFitParamInfo,uint>& paramindices)
{
 try{
 for (list<XMLHandler>::iterator it=kelems.begin();it!=kelems.end();it++){
    KElementInfo keinfo(*it);
    if (fit.find(keinfo)!=fit.end())
       throw(std::invalid_argument("Duplicate KElementInfo tag"));
    initialize_a_fitform(keinfo,*it,allow_polynomial,allow_sumofpoles,fit,paramindices);}
 paraminfo.resize(paramindices.size());
 for (std::map<KFitParamInfo,uint>::iterator 
    it=paramindices.begin();it!=paramindices.end();it++)
       paraminfo[it->second]=it->first;}
 catch(const std::exception& xp){
    throw(std::invalid_argument(string("Could not construct Kmatrix: ")+xp.what()));}
}


    //  very important class that sets up m_fit and m_paramindices
    //  written as static class so can be used by KtildeInverseCalculator too


void KtildeMatrixCalculator::initialize_a_fitform(const KElementInfo& kinfo, XMLHandler& xmlin, 
                          bool allow_polynomial, bool allow_sumofpoles,
                          std::map<KElementInfo,std::list<FitForm*> >& fit,
                          std::map<KFitParamInfo,uint>& paramindices)
{
 list<FitForm*> fptrs;
 try{
 XMLHandler xmle(xmlin,"FitForm");
 uint count1=xmle.count_among_children("Polynomial");
 uint count2=xmle.count_among_children("SumOfPoles");
 uint countmax=0;
 if (allow_polynomial) countmax++;
 if (allow_sumofpoles) countmax++;
 if ((count1>1)||(count2>1)||((count1+count2)>countmax)||((count1+count2)==0))
    throw(std::invalid_argument("FitForm has invalid XML content"));

 if ((count1==1)&&(allow_polynomial)){
    XMLHandler xmlf(xmle,"Polynomial");
    uint count3=xmlf.count_among_children("Degree");
    uint count4=xmlf.count_among_children("Powers");
    if ((count3+count4)!=1)
       throw(std::invalid_argument("Polynomial must have either <Degree> or <Powers> tag"));
    set<uint> polypowers;
    if (count3==1){
       uint deg;
       xmlreadchild(xmlf,"Degree",deg);
       for (uint k=0;k<=deg;k++) polypowers.insert(k);}
    else{
       vector<uint> ipowers;
       xmlreadchild(xmlf,"Powers",ipowers);
       for (uint k=0;k<ipowers.size();k++) polypowers.insert(ipowers[k]);}
    uint deg=0;
    for (set<uint>::iterator st=polypowers.begin();st!=polypowers.end();st++)
       if ((*st)>deg) deg=(*st);
    vector<int> coef_indices(deg+1);
    for (uint k=0;k<=deg;k++){
       if (polypowers.find(k)==polypowers.end())
          coef_indices[k]=-1;
       else{
          uint nextindex=paramindices.size();
          coef_indices[k]=nextindex;
          KFitParamInfo kpinfo(kinfo,k);
          paramindices.insert(make_pair(kpinfo,nextindex));}}
    FitForm *fptr=new Polynomial(coef_indices);
    fptrs.push_back(fptr);}

 if ((count2==1)&&(allow_sumofpoles)){
    XMLHandler xmlf(xmle,"SumOfPoles");
    uint count3=xmlf.count_among_children("NumberOfPoles");
    uint count4=xmlf.count_among_children("PoleIndices");
    if ((count3+count4)!=1)
       throw(std::invalid_argument("SumOfPoles must have either <NumberOfPoles> or <PoleIndices> tag"));
    set<uint> poleset;
    if (count3==1){
       uint numpoles;
       xmlreadchild(xmlin,"NumberOfPoles",numpoles);
       for (uint k=0;k<numpoles;k++) poleset.insert(k);}
    else{
       vector<uint> ipoles;
       xmlreadchild(xmlf,"PoleIndices",ipoles);
       for (uint k=0;k<ipoles.size();k++) poleset.insert(ipoles[k]);}
    vector<uint> poleindices(poleset.begin(),poleset.end());
    uint npoles=poleindices.size();
    vector<uint> rowg(npoles),colg(npoles),energy(npoles);
    std::map<KFitParamInfo,uint>::iterator kt;
    for (uint k=0;k<npoles;k++){
       uint Jtimestwo=kinfo.getJtimestwo();
       KFitParamInfo kpenergy(poleindices[k],Jtimestwo);
       KFitParamInfo krowg(kinfo.getRow(),poleindices[k],Jtimestwo);
       KFitParamInfo kcolg(kinfo.getColumn(),poleindices[k],Jtimestwo);
       vector<KFitParamInfo*> kptrs(3);
       kptrs[0]=&kpenergy; kptrs[1]=&krowg; kptrs[2]=&kcolg;
       vector<uint*> iptrs(3);
       iptrs[0]=&(energy[k]); iptrs[1]=&(rowg[k]); iptrs[2]=&(colg[k]);
       for (uint kk=0;kk<3;kk++){
          kt=paramindices.find(*(kptrs[kk]));
          if (kt!=paramindices.end()){
             (*(iptrs[kk]))= kt->second;}
          else{
             (*(iptrs[kk]))=paramindices.size();
             paramindices.insert(make_pair(*(kptrs[kk]),(*(iptrs[kk]))));}}}
    FitForm *fptr=new SumOfPoles(rowg,colg,energy);
    fptrs.push_back(fptr);}

 fit.insert(make_pair(kinfo,fptrs));}

 catch(const std::exception& xp){
    for (list<FitForm*>::iterator it=fptrs.begin();it!=fptrs.end();it++)
       delete (*it);
    throw(std::invalid_argument(string("Could not initialize a fit form: ")+xp.what()));}
}


double KtildeMatrixCalculator::calculate(uint Jtimestwo, 
                       uint Lp, uint Sptimestwo, uint chanp,
                       uint L, uint Stimestwo, uint chan, 
                       const vector<double>& kappa,
                       double Ecm_over_mref) const
{
 if (kappa.size()<m_paraminfo.size())
    throw(std::invalid_argument("Insufficient number of parameter values in KtildeMatrixCalculator::calculate"));
 KElementInfo kelem(Jtimestwo,Lp,Sptimestwo,chanp,L,Stimestwo,chan);
 std::map<KElementInfo,std::list<FitForm*> >::const_iterator it=m_fit.find(kelem);
 if (it==m_fit.end()) return 0.0;
 double res=0.0;
 for (std::list<FitForm*>::const_iterator 
    ft=(it->second).begin();ft!=(it->second).end();ft++)
       res+=(*ft)->evaluate(kappa,Ecm_over_mref);
 return res;
}


bool KtildeMatrixCalculator::isZero(uint Jtimestwo, 
                       uint Lp, uint Sptimestwo, uint chanp,
                       uint L, uint Stimestwo, uint chan) const
{
 KElementInfo kelem(Jtimestwo,Lp,Sptimestwo,chanp,L,Stimestwo,chan);
 std::map<KElementInfo,std::list<FitForm*> >::const_iterator it=m_fit.find(kelem);
 return (it==m_fit.end());
}


// ***************************************************************************************


KtildeInverseCalculator::~KtildeInverseCalculator()
{
 for (std::map<KElementInfo,std::list<FitForm*> >::iterator 
    it=m_fit.begin();it!=m_fit.end();it++)
    for (std::list<FitForm*>::iterator 
       lt=(it->second).begin();lt!=(it->second).end();lt++)
          delete *lt;
}


KtildeInverseCalculator::KtildeInverseCalculator(XMLHandler& xmlin)
{
 XMLHandler xmlk(xmlin,"KtildeMatrixInverse");
 list<XMLHandler> kelems=xmlk.find_among_children("Element");
 bool allow_polynomial=true;
 bool allow_sumofpoles=false;
 KtildeMatrixCalculator::initialize(kelems,allow_polynomial,allow_sumofpoles,
                                    m_fit,m_paraminfo,m_paramindices);
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
 std::map<KElementInfo,std::list<FitForm*> >::const_iterator it;
 for (it=m_fit.begin();it!=m_fit.end();it++)
    res.insert(it->first);
 return res;
}


double KtildeInverseCalculator::calculate(uint Jtimestwo, 
                       uint Lp, uint Sptimestwo, uint chanp,
                       uint L, uint Stimestwo, uint chan, 
                       const vector<double>& kappa,
                       double Ecm_over_mref) const
{
 if (kappa.size()<m_paraminfo.size())
    throw(std::invalid_argument("Insufficient number of parameter values in KtildeInverseCalculator::calculate"));
 KElementInfo kelem(Jtimestwo,Lp,Sptimestwo,chanp,L,Stimestwo,chan);
 std::map<KElementInfo,std::list<FitForm*> >::const_iterator it=m_fit.find(kelem);
 if (it==m_fit.end()) return 0.0;
 double res=0.0;
 for (std::list<FitForm*>::const_iterator 
    ft=(it->second).begin();ft!=(it->second).end();ft++)
       res+=(*ft)->evaluate(kappa,Ecm_over_mref);
 return res;
}


bool KtildeInverseCalculator::isZero(uint Jtimestwo, 
                       uint Lp, uint Sptimestwo, uint chanp,
                       uint L, uint Stimestwo, uint chan) const
{
 KElementInfo kelem(Jtimestwo,Lp,Sptimestwo,chanp,L,Stimestwo,chan);
 std::map<KElementInfo,std::list<FitForm*> >::const_iterator it=m_fit.find(kelem);
 return (it==m_fit.end());
}

// ***************************************************************************************
