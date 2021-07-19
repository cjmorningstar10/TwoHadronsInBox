#include "box_quant.h"
#include "utils.h"

using namespace std;

// ****************************************************************


DecayChannelInfo::DecayChannelInfo(const std::string& particle1_name, 
                     const std::string& particle2_name,
                     uint spin1_times_two, uint spin2_times_two,
                     bool identical, bool same_intrinsic_parities)
     : m_name1(tidyString(particle1_name)), m_name2(tidyString(particle2_name))
{
 check_encode(spin1_times_two,spin2_times_two,identical,same_intrinsic_parities);
}


void DecayChannelInfo::check_encode(uint spin1_times_two, uint spin2_times_two,
                                    bool identical, bool same_intrinsic_parities)
{
 if ((spin1_times_two>=32768)||(spin2_times_two>=32768)
        ||(m_name1.empty())||(m_name2.empty()))
    throw(std::invalid_argument("Invalid DecayChannelInfo: empty name, or spin too large"));
 if ((identical)&&((m_name1!=m_name2)||(spin1_times_two!=spin2_times_two)))
    throw(std::invalid_argument("DecayChannelInfo identical particles but different properties"));
 m_store=spin1_times_two;
 m_store<<=15; m_store|=spin2_times_two;
 m_store<<=1; if (identical) m_store|=1u;
 m_store<<=1; if (same_intrinsic_parities) m_store|=1u;
}


DecayChannelInfo::DecayChannelInfo(XMLHandler& xmlin)
{
 uint spin1_times_two, spin2_times_two;
 bool identical, same_intrinsic_parities;
 try{
 XMLHandler xmlinfo(xmlin,"DecayChannelInfo");
 xmlreadchild(xmlinfo,"Particle1Name",m_name1);
 xmlreadchild(xmlinfo,"Spin1TimesTwo",spin1_times_two);
 if (xml_tag_count(xmlinfo,"Identical")>0){
    string name2(m_name1);
    xmlreadifchild(xmlinfo,"Particle2Name",name2);
    uint s2=spin1_times_two;
    xmlreadifchild(xmlinfo,"Spin2TimesTwo",s2);
    string ipprod("same");
    xmlreadifchild(xmlinfo,"IntrinsicParities",ipprod);
    if ((name2!=m_name1)||(s2!=spin1_times_two)||(ipprod!="same"))
       throw(std::invalid_argument(string("Input not consistent with identical particles")));
    m_name2=m_name1;
    spin2_times_two=spin1_times_two;
    identical=true;
    same_intrinsic_parities=true;}
 else{
    identical=false;
    xmlreadchild(xmlinfo,"Particle2Name",m_name2);
    xmlreadchild(xmlinfo,"Spin2TimesTwo",spin2_times_two);
    string reply;
    xmlreadchild(xmlinfo,"IntrinsicParities",reply);
    if (reply=="same") same_intrinsic_parities=true;
    else if (reply=="opposite") same_intrinsic_parities=false;
    else throw(std::invalid_argument("Invalid IntrinsicParities tag"));}
 check_encode(spin1_times_two,spin2_times_two,identical,same_intrinsic_parities);}
 catch(const std::exception& xp){
    throw(std::invalid_argument(string("Invalid input to DecayChannelInfo: ")+xp.what()));}
}



DecayChannelInfo::DecayChannelInfo(const DecayChannelInfo& dcinfo)
                : m_name1(dcinfo.m_name1), m_name2(dcinfo.m_name2),
                  m_store(dcinfo.m_store)
{}


DecayChannelInfo& DecayChannelInfo::operator=(const DecayChannelInfo& dcinfo)
{
 m_name1=dcinfo.m_name1; 
 m_name2=dcinfo.m_name2;
 m_store=dcinfo.m_store;
 return *this;
}


string DecayChannelInfo::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string DecayChannelInfo::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void DecayChannelInfo::output(XMLHandler& xmlout) const
{
 xmlout.set_root("DecayChannelInfo");
 xmlout.put_child("Particle1Name",m_name1);
 xmlout.put_child("Spin1TimesTwo",make_string(getSpin1timestwo()));
 if (areIdentical())
    xmlout.put_child("Identical");
 else{
    xmlout.put_child("Particle2Name",m_name2);
    xmlout.put_child("Spin2TimesTwo",make_string(getSpin2timestwo()));
    if (sameIntrinsicParities())
       xmlout.put_child("IntrinsicParities","same");
    else
       xmlout.put_child("IntrinsicParities","opposite");}
}


ostream& operator<<(ostream& os, const DecayChannelInfo& dcinfo)  
{  
 os << dcinfo.output();  
 return os;  
}


// *******************************************************************

BoxQuantBasisState::BoxQuantBasisState(BoxMatrix *boxmat, uint channel_index,
                                       uint Stimestwo, uint Jtimestwo,
                                       uint L, uint occurrence)
   : m_boxmat(boxmat)
{
 check_encode(channel_index,Stimestwo,Jtimestwo,L,occurrence);
}


//   m_store encodes the channel index (6 bits),
//   total S times two (6 bits), total J times two (7 bits)
//   L (7 bits), occurrence index (6 bits)


void BoxQuantBasisState::check_encode(uint channel_index, uint Stimestwo, 
                                      uint Jtimestwo, uint L, uint occurrence)
{
 if ((channel_index>=64)||(Stimestwo>=64)||(Jtimestwo>=128)||(L>=128)
      ||(occurrence>=64))
    throw(std::invalid_argument("Unsupported BoxQuantBasisState value"));
 m_store=channel_index;
 m_store<<=6; m_store|=Stimestwo;
 m_store<<=7; m_store|=Jtimestwo;
 m_store<<=7; m_store|=L;
 m_store<<=6; m_store|=occurrence;
}


string BoxQuantBasisState::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string BoxQuantBasisState::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void BoxQuantBasisState::output(XMLHandler& xmlout) const
{
 xmlout.set_root("BoxQuantBasisState");
 string ststr(" chan("); ststr+=make_string(getChannelIndex())+")";
 ststr+=" 2S("+make_string(getStimestwo())+")";
 ststr+=" 2J("+make_string(getJtimestwo())+")";
 ststr+=" L("+make_string(getL())+")";
 ststr+=" n("+make_string(getOccurrence())+") ";
 xmlout.put_child("Ket",ststr);
}


// ****************************************************************

// *     <BoxQuantization>
// *       <TotalMomentumRay>oa</TotalMomentumRay> 
// *           ["ar"=at rest (0,0,0), "oa"=on axis (0,0,1), 
// *            "pd"=planar diagonal (0,1,1),
// *            "cd"=cubic diagonal (1,1,1)]
// *       <TotalMomentumIntSquared>2</TotalMomentumIntSquared>
// *           [if total momentum is (2*Pi/L)(1,1,1), then IntSquared = 3]
// *       <LGIrrep>T1u</LGIrrep>
// *       <DecayChannel>
// *         <DecayChannelInfo>...</DecayChannelInfo>
// *         <Lmax>4</Lmax>
// *       </DecayChannel>
// *        .... (other decay channels)
// *     </BoxQuantization>
// *      

BoxQuantization::BoxQuantization(XMLHandler& xmlin,
                                 KtildeMatrixCalculator *Kmatptr)
               :   m_Kmat(Kmatptr), m_Kinv(0)
{
 xmlinitialize(xmlin);
}


BoxQuantization::BoxQuantization(XMLHandler& xmlin,
                                 KtildeInverseCalculator *Kinvptr)
               :   m_Kmat(0), m_Kinv(Kinvptr)
{
 xmlinitialize(xmlin);
}


BoxQuantization::BoxQuantization(XMLHandler& xmlin,
                                 KtildeMatrixCalculator *Kmatptr,
                                 KtildeInverseCalculator *Kinvptr)
               :   m_Kmat(Kmatptr), m_Kinv(Kinvptr)
{
 if ((m_Kmat!=0)&&(m_Kinv!=0))
    throw(std::invalid_argument(string("One of the pointers must be null in BoxQuantization constructor with ")
               +string("KtildeMatrixCalculator and KtildeInverseCalculator pointers")));
 xmlinitialize(xmlin);
}


void BoxQuantization::xmlinitialize(XMLHandler& xmlin)
{
 try{
    XMLHandler xmlinfo(xmlin,"BoxQuantization");
    xmlreadchild(xmlinfo,"TotalMomentumRay",m_momray);
    uint mom_int_sq=0;
    xmlreadchild(xmlinfo,"TotalMomentumIntSquared",mom_int_sq);
    set_dvector(mom_int_sq);
    xmlreadchild(xmlinfo,"LGIrrep",m_lgirrep);
    list<XMLHandler> dcxml=xmlinfo.find_among_children("DecayChannel");
    for (list<XMLHandler>::iterator it=dcxml.begin();it!=dcxml.end();it++){
       DecayChannelInfo dctemp(*it);
       m_decay_infos.push_back(dctemp);
       int lmax;
       xmlreadchild(*it,"Lmax",lmax);
       m_Lmaxes.push_back(lmax);}
    initialize();}
 catch(const std::exception& xp){
    clear();
    throw(std::invalid_argument(string("Invalid input to BoxQuantization: ")+xp.what()));}
}


BoxQuantization::BoxQuantization(const std::string& mom_ray, uint mom_int_sq,
                    const std::string& lgirrep, 
                    const std::vector<DecayChannelInfo>& chan_infos,
                    const std::vector<uint> lmaxes,
                    KtildeMatrixCalculator *Kmatptr)
               :   m_lgirrep(lgirrep), m_momray(mom_ray), m_decay_infos(chan_infos),
                   m_Lmaxes(lmaxes), m_Kmat(Kmatptr), m_Kinv(0)
{
 set_dvector(mom_int_sq);
 if (m_decay_infos.size()!=m_Lmaxes.size())
    throw(std::invalid_argument("Size mismatch between decay infos and L-maxes"));
 initialize();
}


BoxQuantization::BoxQuantization(const std::string& mom_ray, uint mom_int_sq,
                    const std::string& lgirrep, 
                    const std::vector<DecayChannelInfo>& chan_infos,
                    const std::vector<uint> lmaxes,
                    KtildeInverseCalculator *Kinvptr)
               :   m_lgirrep(lgirrep), m_momray(mom_ray), m_decay_infos(chan_infos),
                   m_Lmaxes(lmaxes), m_Kmat(0), m_Kinv(Kinvptr)
{
 set_dvector(mom_int_sq);
 if (m_decay_infos.size()!=m_Lmaxes.size())
    throw(std::invalid_argument("Size mismatch between decay infos and L-maxes"));
 initialize();
}



void BoxQuantization::set_dvector(uint mom_int_sq)
{
 if (m_momray=="ar"){  // at rest
    if (mom_int_sq!=0)
       throw(std::invalid_argument("At rest ray with nonzero momentum squared!"));
    m_dx=m_dy=m_dz=0;}
 else if (m_momray=="oa"){ // on-axis
    m_dx=m_dy=0;
    if (mom_int_sq==1) m_dz=1;
    else if (mom_int_sq==4) m_dz=2;
    else if (mom_int_sq==9) m_dz=3;
    else if (mom_int_sq==16) m_dz=4;
    else if (mom_int_sq==25) m_dz=5;
    else if (mom_int_sq==36) m_dz=6;
    else throw(std::invalid_argument("Supported momentum squared"));}
 else if (m_momray=="pd"){   // planar-diagonal
    if (mom_int_sq==2) m_dz=1;
    else if (mom_int_sq==8) m_dz=2;
    else if (mom_int_sq==18) m_dz=3;
    else if (mom_int_sq==32) m_dz=4;
    else if (mom_int_sq==50) m_dz=5;
    else if (mom_int_sq==72) m_dz=6;
    else throw(std::invalid_argument("Supported momentum squared"));
    m_dx=0; m_dy=m_dz;}
 else if (m_momray=="cd"){   // cubic-diagonal
    if (mom_int_sq==3) m_dz=1;
    else if (mom_int_sq==12) m_dz=2;
    else if (mom_int_sq==27) m_dz=3;
    else if (mom_int_sq==48) m_dz=4;
    else if (mom_int_sq==75) m_dz=5;
    else if (mom_int_sq==108) m_dz=6;
    else throw(std::invalid_argument("Supported momentum squared"));
    m_dx=m_dy=m_dz;}
 else{
    throw(std::invalid_argument("Unsupported momentum ray"));} 
}


void BoxQuantization::clear()
{
 m_decay_infos.clear(); 
 m_Lmaxes.clear();
 m_masses1.clear();
 m_masses2.clear();
 for (list<pair<BoxMatrix*,uint> >::iterator it=m_boxes.begin();it!=m_boxes.end();it++)
    delete it->first;
 m_boxes.clear();
 for (list<WZetaRGLCalculator*>::iterator it=m_wzetas.begin();it!=m_wzetas.end();it++)
    delete (*it);
 m_wzetas.clear();
 m_basis.clear();
}



BoxQuantization::~BoxQuantization()
{
 clear();
}



void BoxQuantization::initialize()
{
     // set up default values of masses; these can be changed later
 uint nchan=m_decay_infos.size();
 if (nchan==0)
    throw(std::invalid_argument("Must have at least ONE decay channel"));
 bool ipprod=m_decay_infos[0].sameIntrinsicParities();
 for (uint a=1;a<nchan;a++){
    if (ipprod!=m_decay_infos[a].sameIntrinsicParities())
       throw(std::invalid_argument("All channels must have same product of intrinsic parities"));}
 if (ipprod)
    m_lgirrepB=m_lgirrep;
 else
    m_lgirrepB=getLGIrrepParityFlip();
 m_mref_L=6.0;    // arbitrary default value; should be reset
 m_masses1.resize(nchan);
 m_masses2.resize(nchan);
 for (uint k=0;k<nchan;k++)
    m_masses1[k]=m_masses2[k]=1.0;   // arbitrary default values
   // set up the basis states
 setup_basis();
   // initialize size of parameters
 m_kappa_params.resize(getNumberOfKtildeParameters());
}


void BoxQuantization::setRefMassL(double mref_L)
{
 if (mref_L<=0.0)
    throw(std::invalid_argument("Unsupported reference mass: zero or negative"));
 m_mref_L=mref_L;
 for (list<pair<BoxMatrix*,uint> >::iterator it=m_boxes.begin();it!=m_boxes.end();it++){
    uint chan=it->second;
    if (m_decay_infos[chan].areIdentical())
       it->first->resetMasses(m_mref_L,m_masses1[chan]);
    else
       it->first->resetMasses(m_mref_L,m_masses1[chan],m_masses2[chan]);}
}


void BoxQuantization::setMassesOverRef(uint channel_index, double mass1_over_ref,
                                       double mass2_over_ref)
{
 if ((mass1_over_ref<=0.0)||(mass2_over_ref<=0.0))
    throw(std::invalid_argument("Unsupported particle masses: zero or negative"));
 m_masses1.at(channel_index)=mass1_over_ref;
 m_masses2.at(channel_index)=mass2_over_ref;
 for (list<pair<BoxMatrix*,uint> >::iterator it=m_boxes.begin();it!=m_boxes.end();it++){
    uint chan=it->second;
    if (chan==channel_index){
       if (m_decay_infos[chan].areIdentical()){
          if (mass1_over_ref!=mass2_over_ref)
             throw(std::invalid_argument("Identical particles cannot have different masses"));
          it->first->resetMasses(m_mref_L,m_masses1[chan]);}
       else
          it->first->resetMasses(m_mref_L,m_masses1[chan],m_masses2[chan]);}}
}


void BoxQuantization::setKtildeParameters(std::vector<double> kappa_params)
{
 if (kappa_params.size()!=getNumberOfKtildeParameters())
    throw(std::invalid_argument("Could not set KtildeParameters"));
 m_kappa_params=kappa_params;
}


string BoxQuantization::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string BoxQuantization::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void BoxQuantization::output(XMLHandler& xmlout) const
{
 xmlout.set_root("BoxQuantization");
 xmlout.put_child("TotalMomentumRay",getMomRay());
 xmlout.put_child("TotalMomentumIntSquared",make_string(getTotalMomentumIntegerSquared()));
 xmlout.put_child("LGIrrep",getLittleGroupIrrep());
 uint nchan=m_decay_infos.size();
 for (uint chan=0;chan<nchan;chan++){
    XMLHandler xmlci; m_decay_infos[chan].output(xmlci);
    XMLHandler xmlc("DecayChannel");
    xmlc.put_child(xmlci);
    xmlc.put_child("Lmax",make_string(m_Lmaxes[chan]));
    xmlout.put_child(xmlc);}
}


void BoxQuantization::outputBasis(XMLHandler& xmlout) const
{
 xmlout.set_root("BoxQuantizationBasis");
 for (std::set<BoxQuantBasisState>::iterator it=m_basis.begin();it!=m_basis.end();it++){
    XMLHandler xmlb;
    it->output(xmlb);
    xmlout.put_child(xmlb);}
}


string BoxQuantization::outputBasis(int indent) const
{
 XMLHandler xmlout;
 outputBasis(xmlout);
 return xmlout.output(indent);
}


void BoxQuantization::outputKFitParams(XMLHandler& xmlout) const  // XML output
{
 xmlout.set_root("BoxQuantizationKFitParams");
 const std::vector<KFitParamInfo>& fref=getFitParameterInfos();
 for (std::vector<KFitParamInfo>::const_iterator it=fref.begin();it!=fref.end();it++){
    XMLHandler xmlk;
    it->output(xmlk);
    xmlout.put_child(xmlk);}
}


std::string BoxQuantization::outputKFitParams(int indent) const // XML output 
{
 XMLHandler xmlout;
 outputKFitParams(xmlout);
 return xmlout.output(indent);
}





const std::vector<KFitParamInfo>& BoxQuantization::getFitParameterInfos() const
{
 if (m_Kmat) return m_Kmat->getFitParameterInfos();
 else return m_Kinv->getFitParameterInfos();
}


int BoxQuantization::getParameterIndex(const KFitParamInfo& kinfo) const  // returns -1 if not found
{
 if (m_Kmat) return m_Kmat->getParameterIndex(kinfo);
 else return m_Kinv->getParameterIndex(kinfo);
}


double BoxQuantization::getParameterValue(const KFitParamInfo& kinfo) const
{
 if (m_Kmat) return m_kappa_params.at(m_Kmat->getParameterIndex(kinfo));
 else return m_kappa_params.at(m_Kinv->getParameterIndex(kinfo));
}

set<KElementInfo> BoxQuantization::getElementInfos() const
{
 if (m_Kmat) return m_Kmat->getElementInfos();
 else return m_Kinv->getElementInfos();
}


string BoxQuantization::getLGIrrepParityFlip()
{
 if (m_momray=="ar"){
    string res(m_lgirrep);
    uint n=res.length();
    if (res[n-1]=='g') res[n-1]='u';
    else if (res[n-1]=='u') res[n-1]='g';
    else throw(std::invalid_argument("Unsupported irrep"));
    return res;}
 else if (m_momray=="oa"){
    if (m_lgirrep=="A1") return string("A2");
    else if (m_lgirrep=="A2") return string("A1");
    else if (m_lgirrep=="B1") return string("B2");
    else if (m_lgirrep=="B2") return string("B1");
    else if ((m_lgirrep=="E")||(m_lgirrep=="G1")||(m_lgirrep=="G2")) return m_lgirrep;
    else throw(std::invalid_argument("Unsupported irrep"));}
 else if (m_momray=="pd"){
    if (m_lgirrep=="A1") return string("A2");
    else if (m_lgirrep=="A2") return string("A1");
    else if (m_lgirrep=="B1") return string("B2");
    else if (m_lgirrep=="B2") return string("B1");
    else if (m_lgirrep=="G") return m_lgirrep;
    else throw(std::invalid_argument("Unsupported irrep"));}
 else if (m_momray=="cd"){
    if (m_lgirrep=="A1") return string("A2");
    else if (m_lgirrep=="A2") return string("A1");
    else if (m_lgirrep=="F1") return string("F2");
    else if (m_lgirrep=="F2") return string("F1");
    else if ((m_lgirrep=="E")||(m_lgirrep=="G")) return m_lgirrep;
    else throw(std::invalid_argument("Unsupported irrep"));}
 else
    throw(std::invalid_argument("Unsupported momentum ray"));
}



// *  Loop over the channels
// *  For each channel, 
// *      - create a Ecmtransform object
// *      - create a WZetaRGLCalculator object
// *      - loop over allowed values of S  (|s1-s2|,...,s1+s2)
// *           - create box matrix for each
// *           - each box matrix creates the n J L basis states

// *   Basis states in the current block are labelled by
// *      irrep occurrence  J L S channel_index
// *  (irrep_row=1 always taken here)

// *   Lastly, looks for states whose K-matrix elements are
// *   all zero.  These states are excluded from the basis


void BoxQuantization::setup_basis()
{
 uint nchan=m_decay_infos.size();
 for (uint chan=0;chan<nchan;chan++){
    EcmTransform Ecm(m_dx,m_dy,m_dz,m_mref_L,m_masses1[chan],m_masses2[chan]);
    WZetaRGLCalculator* mzptr=new WZetaRGLCalculator;
    m_wzetas.push_back(mzptr);
    uint s1timestwo=m_decay_infos[chan].getSpin1timestwo();
    uint s2timestwo=m_decay_infos[chan].getSpin2timestwo();
    uint Stimestwomax=s1timestwo+s2timestwo;
    uint Stimestwomin=std::abs(int(s1timestwo)-int(s2timestwo));
    for (uint Stimestwo=Stimestwomin;Stimestwo<=Stimestwomax;Stimestwo+=2){
       BoxMatrix *mbptr=new BoxMatrix(Ecm,*mzptr,Stimestwo,m_lgirrepB,m_Lmaxes[chan]);
       uint nelem=mbptr->getNumberOfIndepElements();
       if (nelem>0){
          m_boxes.push_back(make_pair(mbptr,chan));
          for (uint i=0;i<nelem;i++){
             BoxMatrixQuantumNumbers bqm(mbptr->getQuantumNumbers(i));
             m_basis.insert(BoxQuantBasisState(mbptr,chan,Stimestwo, 
                     bqm.getRowJtimestwo(),bqm.getRowL(),bqm.getRowNocc()));
             m_basis.insert(BoxQuantBasisState(mbptr,chan,Stimestwo, 
                     bqm.getColumnJtimestwo(),bqm.getColumnL(),bqm.getColumnNocc()));}}
       else{
          delete mbptr;}}}
 if (m_basis.empty()){
    throw(std::invalid_argument(string("Null basis in BoxQuantization even before Kmatrix exclusions")));}
   // look for states to exclude due to K-matrix
 set<BoxQuantBasisState> exclusions;
 if (m_Kmat!=0) exclusions=find_excluded_states_from_ktilde(m_Kmat);
 else exclusions=find_excluded_states_from_ktilde(m_Kinv);
   // if ALL states excluded, this means Kmatrix is zero; end user needs to know
   // which K matrix elements should be set; throw this information
 if (exclusions.size()==m_basis.size()){
    set<KElementInfo> kelems;
    for (set<BoxQuantBasisState>::iterator rt=m_basis.begin();rt!=m_basis.end();rt++)
    for (set<BoxQuantBasisState>::iterator ct=rt;ct!=m_basis.end();ct++){
       try{
          KElementInfo kel(rt->getJtimestwo(),
                           rt->getL(),rt->getStimestwo(),rt->getChannelIndex(),
                           ct->getL(),ct->getStimestwo(),ct->getChannelIndex());
          kelems.insert(kel);}
       catch(const std::exception& xp){}}
    string kstr;
    for (std::set<KElementInfo>::const_iterator it=kelems.begin();it!=kelems.end();it++){
       XMLHandler xmle("Element");
       XMLHandler xmli; it->output(xmli);
       xmle.put_child(xmli);
       xmle.put_child("FitForm","..."); 
       kstr+=xmle.output(1);}
    throw(std::invalid_argument(string("Null basis in BoxQuantization after Kmatrix exclusions: need K elements follow: ")+kstr));}
 for (set<BoxQuantBasisState>::iterator it=exclusions.begin();it!=exclusions.end();it++){
    m_basis.erase(*it);}
}


double BoxQuantization::getEcmOverMrefFromElab(double Elab_over_mref) const
{
 return m_boxes.front().first->getEcmOverMrefFromElab(Elab_over_mref);
}



void BoxQuantization::getBoxMatrixFromElab(double Elab_over_mref, ComplexHermitianMatrix& B)
{
 CMatrix dummy;
 get_box_matrix(Elab_over_mref,B,dummy,true,true);
}


void BoxQuantization::getBoxMatrixFromElab(double Elab_over_mref, CMatrix& B)
{
 ComplexHermitianMatrix dummy;
 get_box_matrix(Elab_over_mref,dummy,B,true,false);
}


void BoxQuantization::getBoxMatrixFromEcm(double Ecm_over_mref, ComplexHermitianMatrix& B)
{
 CMatrix dummy;
 get_box_matrix(Ecm_over_mref,B,dummy,false,true);
}


void BoxQuantization::getBoxMatrixFromEcm(double Ecm_over_mref, CMatrix& B)
{
 ComplexHermitianMatrix dummy;
 get_box_matrix(Ecm_over_mref,dummy,B,false,false);
}



void BoxQuantization::getKtildeFromElab(double Elab_over_mref, RealSymmetricMatrix& Ktilde)
{
 if (m_Kmat==0) throw(std::runtime_error("Cannot evaluate Ktilde in Ktildeinverse mode"));
 RMatrix dummy;
 get_ktilde_matrix(Elab_over_mref,Ktilde,dummy,true,true,m_Kmat);
}


void BoxQuantization::getKtildeFromElab(double Elab_over_mref, RMatrix& Ktilde)
{
 if (m_Kmat==0) throw(std::runtime_error("Cannot evaluate Ktilde in Ktildeinverse mode"));
 RealSymmetricMatrix dummy;
 get_ktilde_matrix(Elab_over_mref,dummy,Ktilde,true,false,m_Kmat);
}


void BoxQuantization::getKtildeFromEcm(double Ecm_over_mref, RealSymmetricMatrix& Ktilde)
{
 if (m_Kmat==0) throw(std::runtime_error("Cannot evaluate Ktilde in Ktildeinverse mode"));
 RMatrix dummy;
 get_ktilde_matrix(Ecm_over_mref,Ktilde,dummy,false,true,m_Kmat);
}


void BoxQuantization::getKtildeFromEcm(double Ecm_over_mref, RMatrix& Ktilde)
{
 if (m_Kmat==0) throw(std::runtime_error("Cannot evaluate Ktilde in Ktildeinverse mode"));
 RealSymmetricMatrix dummy;
 get_ktilde_matrix(Ecm_over_mref,dummy,Ktilde,false,false,m_Kmat);
}


void BoxQuantization::getKtildeinvFromElab(double Elab_over_mref, RealSymmetricMatrix& Ktildeinv)
{
 if (m_Kinv==0) throw(std::runtime_error("Cannot evaluate Ktildeinverse in Ktilde mode"));
 RMatrix dummy;
 get_ktilde_matrix(Elab_over_mref,Ktildeinv,dummy,true,true,m_Kinv);
}


void BoxQuantization::getKtildeinvFromElab(double Elab_over_mref, RMatrix& Ktildeinv)
{
 if (m_Kinv==0) throw(std::runtime_error("Cannot evaluate Ktildeinverse in Ktilde mode"));
 RealSymmetricMatrix dummy;
 get_ktilde_matrix(Elab_over_mref,dummy,Ktildeinv,true,false,m_Kinv);
}


void BoxQuantization::getKtildeinvFromEcm(double Ecm_over_mref, RealSymmetricMatrix& Ktildeinv)
{
 if (m_Kinv==0) throw(std::runtime_error("Cannot evaluate Ktildeinverse in Ktilde mode"));
 RMatrix dummy;
 get_ktilde_matrix(Ecm_over_mref,Ktildeinv,dummy,false,true,m_Kinv);
}


void BoxQuantization::getKtildeinvFromEcm(double Ecm_over_mref, RMatrix& Ktildeinv)
{
 if (m_Kinv==0) throw(std::runtime_error("Cannot evaluate Ktildeinverse in Ktilde mode"));
 RealSymmetricMatrix dummy;
 get_ktilde_matrix(Ecm_over_mref,dummy,Ktildeinv,false,false,m_Kinv);
}


void BoxQuantization::getKtildeOrInverseFromElab(double Elab_over_mref, RealSymmetricMatrix& KtildeOrInverse)
{
 RMatrix dummy;
 if (m_Kmat!=0)
    get_ktilde_matrix(Elab_over_mref,KtildeOrInverse,dummy,true,true,m_Kmat);
 else
    get_ktilde_matrix(Elab_over_mref,KtildeOrInverse,dummy,true,true,m_Kinv);
}


void BoxQuantization::getKtildeOrInverseFromElab(double Elab_over_mref, RMatrix& KtildeOrInverse)
{
 RealSymmetricMatrix dummy;
 if (m_Kmat!=0)
    get_ktilde_matrix(Elab_over_mref,dummy,KtildeOrInverse,true,false,m_Kmat);
 else
    get_ktilde_matrix(Elab_over_mref,dummy,KtildeOrInverse,true,false,m_Kinv);
}


void BoxQuantization::getKtildeOrInverseFromEcm(double Ecm_over_mref, RealSymmetricMatrix& KtildeOrInverse)
{
 RMatrix dummy;
 if (m_Kmat!=0)
    get_ktilde_matrix(Ecm_over_mref,KtildeOrInverse,dummy,false,true,m_Kmat);
 else
    get_ktilde_matrix(Ecm_over_mref,KtildeOrInverse,dummy,false,true,m_Kinv);
}


void BoxQuantization::getKtildeOrInverseFromEcm(double Ecm_over_mref, RMatrix& KtildeOrInverse)
{
 RealSymmetricMatrix dummy;
 if (m_Kmat!=0)
    get_ktilde_matrix(Ecm_over_mref,dummy,KtildeOrInverse,false,false,m_Kmat);
 else
    get_ktilde_matrix(Ecm_over_mref,dummy,KtildeOrInverse,false,false,m_Kinv);
}


void BoxQuantization::outputKBMatricesFromElab(double Elab_over_mref, std::ostream& fout)
{
 output_matrices(Elab_over_mref,true,fout);
}


void BoxQuantization::outputKBMatricesFromEcm(double Ecm_over_mref, std::ostream& fout)
{
 output_matrices(Ecm_over_mref,false,fout);
}


             //  computes Omega(mu,Ktildeinv-B) or Omega(mu,1-B*K)
             //         (depending on K or Kinv mode)

double BoxQuantization::getOmegaFromElab(double mu, double Elab_over_mref)
{
 return get_omega(mu,Elab_over_mref,true);
}

double BoxQuantization::getOmegaFromEcm(double mu, double Ecm_over_mref)
{
 return get_omega(mu,Ecm_over_mref,false);
}

double BoxQuantization::getOmega(double mu, const RealSymmetricMatrix& KtildeOrInverse,
                                 const ComplexHermitianMatrix& B)
{
 uint N=B.size();
 if (KtildeOrInverse.size()!=N)
    throw(std::invalid_argument("Mismatch in Kv, B matrix sizes"));
 return get_omega(mu,N,KtildeOrInverse,B);
}




             //  computes [det(Ktildeinv-B)]^(1/Ndet) or [det(1-B*K)]^(1/Ndet)
             //  where Ndet is positive odd integer (depending on K or Kinv mode)

double BoxQuantization::getDeterminantRootFromElab(double Elab_over_mref, uint Ndet)
{
 return get_determinant(Elab_over_mref,true,Ndet);
}


double BoxQuantization::getDeterminantRootFromEcm(double Ecm_over_mref, uint Ndet)
{
 return get_determinant(Ecm_over_mref,false,Ndet);
}


double BoxQuantization::getDeterminantRoot(const RealSymmetricMatrix& KtildeOrInverse,
                                           const ComplexHermitianMatrix& B, uint Ndet)
{
 uint N=B.size();
 if (KtildeOrInverse.size()!=N)
    throw(std::invalid_argument("Mismatch in Kv, B matrix sizes"));
 return get_determinant(N,KtildeOrInverse,B,Ndet);
}


         //  computes the real eigenvalues of Ktildeinv-B  or
         //  the eigenvalues of (B - B*K*B), divided by |detB|^(1/N)
         //  for NxN matrices (depending on K or Kinv mode)

std::vector<double> BoxQuantization::getEigenvaluesFromElab(double Elab_over_mref)
{
 return get_eigenvalues(Elab_over_mref,true);
}

std::vector<double> BoxQuantization::getEigenvaluesFromEcm(double Ecm_over_mref)
{
 return get_eigenvalues(Ecm_over_mref,false);
}



double BoxQuantization::getBoxMatrixDeterminantRootFromElab(double Elab_over_mref, uint Ndet)
{
 ComplexHermitianMatrix B;
 getBoxMatrixFromElab(Elab_over_mref,B);
 RealDeterminantRoot DR;
 return DR.getDeterminantOddRoot(B,Ndet);
}

double BoxQuantization::getBoxMatrixDeterminantRootFromEcm(double Ecm_over_mref, uint Ndet)
{
 ComplexHermitianMatrix B;
 getBoxMatrixFromEcm(Ecm_over_mref,B);
 RealDeterminantRoot DR;
 return DR.getDeterminantOddRoot(B,Ndet);
}


double BoxQuantization::getBoxMatrixDeterminantRoot(const ComplexHermitianMatrix& B, uint Ndet)
{
 RealDeterminantRoot DR;
 return DR.getDeterminantOddRoot(B,Ndet);
}




void BoxQuantization::assign(const cmplx& value, uint row, uint col, bool herm, 
                             ComplexHermitianMatrix& Bh, CMatrix& B)
{
 if (herm) Bh.put(row,col,value);
 else{
    B.put(row,col,value);
    B.put(col,row,conj(value));}
}


void BoxQuantization::assign(double value, uint row, uint col, bool herm, 
                             RealSymmetricMatrix& Bh, RMatrix& B)
{
 if (herm) Bh(row,col)=value;
 else{
    B(row,col)=value;
    B(col,row)=value;}
}


void BoxQuantization::assign_matrices(double E_over_mref, bool Elab, ComplexHermitianMatrix& B,
                                      RealSymmetricMatrix& Kv)
{
 if (Elab){
    getBoxMatrixFromElab(E_over_mref,B);
    if (m_Kmat!=0)
       getKtildeFromElab(E_over_mref,Kv);
    else
       getKtildeinvFromElab(E_over_mref,Kv);}
 else{
    getBoxMatrixFromEcm(E_over_mref,B);
    if (m_Kmat!=0)
       getKtildeFromEcm(E_over_mref,Kv);
    else
       getKtildeinvFromEcm(E_over_mref,Kv);}
}



void BoxQuantization::get_box_matrix(double E_over_mref, ComplexHermitianMatrix& Bh, CMatrix& B,
                                     bool Elab, bool herm)
{
 if (Elab)
    for (list<pair<BoxMatrix*,uint> >::const_iterator it=m_boxes.begin();it!=m_boxes.end();it++){
       it->first->setElementsFromElab(E_over_mref);}
 else
    for (list<pair<BoxMatrix*,uint> >::const_iterator it=m_boxes.begin();it!=m_boxes.end();it++){
       it->first->setElementsFromEcm(E_over_mref);}
 uint bsize=m_basis.size();
 if (herm)
    Bh.resize(bsize);
 else
    B.resize(bsize,bsize);
 uint row=0;
 for (set<BoxQuantBasisState>::iterator rt=m_basis.begin();rt!=m_basis.end();rt++,row++){
    BoxMatrix* bptr=rt->getBoxMatrixPtr();
    uint col=0;
    for (set<BoxQuantBasisState>::iterator ct=m_basis.begin();ct!=m_basis.end();ct++,col++){
       if ((rt->getChannelIndex()!=ct->getChannelIndex())||(rt->getStimestwo()!=ct->getStimestwo()))
          assign(complex<double>(0,0),row,col,herm,Bh,B);
       else{
          BoxMatrixQuantumNumbers bqn(rt->getJtimestwo(),rt->getL(),rt->getOccurrence(),
                                      ct->getJtimestwo(),ct->getL(),ct->getOccurrence());
          assign(bptr->getElement(bqn),row,col,herm,Bh,B);}
       }}
}


template <typename T>
void BoxQuantization::get_ktilde_matrix(double E_over_mref, RealSymmetricMatrix& Kh, RMatrix& K,
                                        bool Elab, bool herm, T* evalptr)
{
 double Ecm=(Elab) ? m_boxes.front().first->getEcmOverMrefFromElab(E_over_mref) : E_over_mref;
 if (Ecm < m_boxes.front().first->getEcmTransform().getMinEcmOverMref())
    throw(std::invalid_argument("Ecm less than minimum not allowed"));
 uint bsize=m_basis.size();
 if (herm)
    Kh.resize(bsize);
 else
    K.resize(bsize,bsize);
 uint row=0;
 for (set<BoxQuantBasisState>::iterator rt=m_basis.begin();rt!=m_basis.end();rt++,row++){
    uint col=0;
    for (set<BoxQuantBasisState>::iterator ct=m_basis.begin();ct!=m_basis.end();ct++,col++){
       if ((rt->getJtimestwo()!=ct->getJtimestwo())||(rt->getOccurrence()!=ct->getOccurrence())
          ||(evalptr->isZero(rt->getJtimestwo(),
                              rt->getL(),rt->getStimestwo(),rt->getChannelIndex(),
                              ct->getL(),ct->getStimestwo(),ct->getChannelIndex()))){
          assign(0.0,row,col,herm,Kh,K);}
       else{
          double kres=evalptr->calculate(rt->getJtimestwo(),
                          rt->getL(),rt->getStimestwo(),rt->getChannelIndex(),
                          ct->getL(),ct->getStimestwo(),ct->getChannelIndex(),m_kappa_params,Ecm); 
          assign(kres,row,col,herm,Kh,K);}
       }}
}


template <typename T>
set<BoxQuantBasisState> BoxQuantization::find_excluded_states_from_ktilde(T* evalptr)
{
 set<BoxQuantBasisState> exclusions;
 for (set<BoxQuantBasisState>::iterator rt=m_basis.begin();rt!=m_basis.end();rt++){
    bool exclude=true;
    for (set<BoxQuantBasisState>::iterator ct=m_basis.begin();ct!=m_basis.end();ct++){
       if ((rt->getJtimestwo()==ct->getJtimestwo())&&(rt->getOccurrence()==ct->getOccurrence())
          &&(!(evalptr->isZero(rt->getJtimestwo(),
                              rt->getL(),rt->getStimestwo(),rt->getChannelIndex(),
                              ct->getL(),ct->getStimestwo(),ct->getChannelIndex())))){
          exclude=false; break;}}
    if (exclude) 
       exclusions.insert(*rt);}
 return exclusions;
}



void BoxQuantization::output_matrices(double E_over_mref, bool Elab, std::ostream& fout)
{
 fout.precision(15);
 ComplexHermitianMatrix B;
 RealSymmetricMatrix Kv;
 assign_matrices(E_over_mref,Elab,B,Kv);
 string Kname;
 if (Elab){
    fout << "Elab:="<<E_over_mref<<":"<<endl;
    Kname=(m_Kmat!=0) ? "Ktilde" : "Ktildeinv";}
 else{
    fout << "Ecm:="<<E_over_mref<<":"<<endl;
    Kname=(m_Kmat!=0) ? "Ktilde" : "Ktildeinv";}
 uint row=0;
 for (set<BoxQuantBasisState>::iterator rt=m_basis.begin();rt!=m_basis.end();rt++,row++){
    uint ap=rt->getChannelIndex();
    uint Spx2=rt->getStimestwo();
    uint Jpx2=rt->getJtimestwo();
    uint Lp=rt->getL();
    uint np=rt->getOccurrence();
    uint col=0;
    for (set<BoxQuantBasisState>::iterator ct=m_basis.begin();ct!=m_basis.end();ct++,col++){
       uint a=ct->getChannelIndex();
       uint Sx2=ct->getStimestwo();
       uint Jx2=ct->getJtimestwo();
       uint L=ct->getL();
       uint n=ct->getOccurrence();
       fout << "B[["<<ap<<","<<Spx2<<","<<Jpx2<<","<<Lp<<","<<np<<"],["
                   <<a<<","<<Sx2<<","<<Jx2<<","<<L<<","<<n<<"]]:=cmplx"
                   << B(row,col)<<":" <<endl;}}
 row=0;
 for (set<BoxQuantBasisState>::iterator rt=m_basis.begin();rt!=m_basis.end();rt++,row++){
    uint ap=rt->getChannelIndex();
    uint Spx2=rt->getStimestwo();
    uint Jpx2=rt->getJtimestwo();
    uint Lp=rt->getL();
    uint np=rt->getOccurrence();
    uint col=0;
    for (set<BoxQuantBasisState>::iterator ct=m_basis.begin();ct!=m_basis.end();ct++,col++){
       uint a=ct->getChannelIndex();
       uint Sx2=ct->getStimestwo();
       uint Jx2=ct->getJtimestwo();
       uint L=ct->getL();
       uint n=ct->getOccurrence();
       fout << Kname<<"[["<<ap<<","<<Spx2<<","<<Jpx2<<","<<Lp<<","<<np<<"],["
                   <<a<<","<<Sx2<<","<<Jx2<<","<<L<<","<<n<<"]]:="
                   << Kv(row,col)<<":" <<endl;}}
}



double BoxQuantization::get_determinant(double E_over_mref, bool Elab, uint Ndet)
{
 ComplexHermitianMatrix B;
 RealSymmetricMatrix Kv;
 assign_matrices(E_over_mref,Elab,B,Kv);
 uint N=B.size();
 return get_determinant(N,Kv,B,Ndet);
}


double BoxQuantization::get_determinant(uint N, const RealSymmetricMatrix& Kv,
                                        const ComplexHermitianMatrix& B, uint Ndet)
{
 RealDeterminantRoot DR;
 if (m_Kinv!=0){                       //   det( Kinv - B )
    ComplexHermitianMatrix Q(N);
    for (uint row=0;row<N;row++)
    for (uint col=row;col<N;col++)
       Q.put(row,col,Kv(row,col)-B(row,col));
    return DR.getDeterminantOddRoot(Q,Ndet);}
 else{                                          //  det( 1 - K*B ) = det( 1 - B*K )
    return DR.getDeterminantOddRoot(Kv,B,Ndet);}
}



std::vector<double> BoxQuantization::get_eigenvalues(double E_over_mref, bool Elab)
{
 ComplexHermitianMatrix B;
 RealSymmetricMatrix Kv;
 Diagonalizer D;
 vector<double> eigvals;
 assign_matrices(E_over_mref,Elab,B,Kv);
 uint N=B.size();
 ComplexHermitianMatrix Q(N);
 if (m_Kinv!=0){                       //   Q = Kinv - B
    for (uint row=0;row<N;row++)
    for (uint col=row;col<N;col++)
       Q.put(row,col,Kv(row,col)-B(row,col));
    D.getEigenvalues(Q,eigvals);}
 else{                                 //  Q = B - B*K*B
    CMatrix KB(N,N);
    for (uint row=0;row<N;row++)
    for (uint col=0;col<N;col++){
       cmplx elem(0.0,0.0);
       for (uint k=0;k<N;k++)
          elem+=Kv(row,k)*B(k,col);
       KB.put(row,col,elem);}
    for (uint row=0;row<N;row++)
    for (uint col=row;col<N;col++){
       cmplx elem(0.0,0.0);
       for (uint k=0;k<N;k++)
          elem+=B(row,k)*KB(k,col);
       if (row==col) elem=cmplx(elem.real(),0.0);
       Q.put(row,col,B(row,col)-elem);}
    vector<double> Beigvals;
    D.getEigenvalues(B,Beigvals);
    double rescale=1.0;
    double root=1.0/double(N);
    for (uint k=0;k<N;k++)
       rescale*=std::pow(std::abs(Beigvals[k]),root);
    rescale=1.0/rescale;
    D.getEigenvalues(Q,eigvals);
    for (uint k=0;k<N;k++)
       eigvals[k]*=rescale;}
 return eigvals;
}


double BoxQuantization::get_omega(double mu, double E_over_mref, bool Elab)
{
 ComplexHermitianMatrix B;
 RealSymmetricMatrix Kv;
 assign_matrices(E_over_mref,Elab,B,Kv);
 uint N=B.size();
 return get_omega(mu,N,Kv,B);
}


double BoxQuantization::get_omega(double mu, uint N, const RealSymmetricMatrix& Kv,
                                  const ComplexHermitianMatrix& B)
{
 RealDeterminantRoot DR;
 if (m_Kinv!=0){                       //   det( Kinv - B )
    ComplexHermitianMatrix Q(N);
    for (uint row=0;row<N;row++)
    for (uint col=row;col<N;col++)
       Q.put(row,col,Kv(row,col)-B(row,col));
    return DR.getOmega(mu,Q);}
 else{                                          //  det( 1 - K*B ) = det( 1 - B*K )
    return DR.getOmega(mu,Kv,B);}
}



// ***************************************************************************************
