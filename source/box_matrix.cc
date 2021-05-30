#include "box_matrix.h"
#include <algorithm>
using namespace std;

// ****************************************************************


std::string BoxMatrixQuantumNumbers::output() const
{
 stringstream os;
 os << "("<<getRowJtimestwo()<<","<<getRowL()<<","<<getRowNocc()
    <<"|"<<getColumnJtimestwo()<<","<<getColumnL()<<","<<getColumnNocc()<<")";
 return os.str();
}

ostream& operator<<(ostream& os, const BoxMatrixQuantumNumbers& bqn)  
{  
 os << bqn.output();  
 return os;  
}


// ****************************************************************

#include <iostream>

BoxMatrix::BoxMatrix(const EcmTransform &incm,  WZetaRGLCalculator& wzetacalc,
                     uint total_spin_times_two, const std::string& lgirrep, 
                     uint Lmax)
     :  m_cmt(incm), m_wzetas(wzetacalc)
{
 if (Lmax>6)
    throw(std::runtime_error("Unsupported L max"));
 m_lmax=Lmax;
 uint st2max=0;
 vector<int> dvec(incm.getdvec());
 if ((dvec[0]==0)&&(dvec[1]==0)&&(dvec[2]==0)){
    m_momray="ar"; st2max=4;
    if (Lmax>AR_LMAX)
       throw(std::runtime_error("Increase AR_LMAX macro"));}
 else if ((dvec[0]==0)&&(dvec[1]==0)&&(dvec[2]>0)){
    m_momray="oa"; st2max=4;
    if (Lmax>OA_LMAX)
       throw(std::runtime_error("Increase OA_LMAX macro"));}
 else if ((dvec[0]==0)&&(dvec[1]>0)&&(dvec[2]==dvec[1])){
    m_momray="pd"; st2max=3;
    if (Lmax>PD_LMAX)
       throw(std::runtime_error("Increase PD_LMAX macro"));}
 else if ((dvec[0]>0)&&(dvec[1]==dvec[0])&&(dvec[2]==dvec[0])){
    m_momray="cd"; st2max=3;
    if (Lmax>CD_LMAX)
       throw(std::runtime_error("Increase CD_LMAX macro"));}
 else
    throw(std::runtime_error("Unsupported momentum ray"));
 if (total_spin_times_two>st2max){
    throw(std::runtime_error("Unsupported total spin"));}
 m_lgirrep=lgirrep;
 m_total_spin_times_two=total_spin_times_two;
 string block_id(m_momray);
 stringstream s; s<<total_spin_times_two;
 block_id+=string("_")+s.str()+string("_")+lgirrep;
 std::map<std::string, EvaluatorPtr>::iterator eit=evaluatorMap.find(block_id);
 std::map<std::string, BlockSetupPtr>::iterator iit=blockSetupMap.find(block_id);
 if ((eit==evaluatorMap.end())||(iit==blockSetupMap.end())){
    m_nelem=0; m_evalptr=0; return;}  // Forbidden block
 m_evalptr=eit->second;
 BlockSetupPtr m_blocksetupptr=iit->second;   
 (*m_blocksetupptr)(m_lmax,m_quantnums);
 m_nelem=m_quantnums.size();
 for (uint k=0;k<m_nelem;k++)
    m_indexmap.insert(make_pair(m_quantnums[k],k));
}


void BoxMatrix::resetMasses(double mref_L_val, double m1_over_mref_val, 
                            double m2_over_mref_val)
{
 m_cmt.set(mref_L_val,m1_over_mref_val,m2_over_mref_val);
}


void BoxMatrix::resetMasses(double mref_L_val, double m1_over_mref_val)
{
 m_cmt.set(mref_L_val,m1_over_mref_val);
}


uint BoxMatrix::getElementIndex(const BoxMatrixQuantumNumbers& bqn) const
{
 std::map<BoxMatrixQuantumNumbers,uint>::const_iterator it=m_indexmap.find(bqn);
 if (it==m_indexmap.end())
    throw(std::runtime_error(string("Quantum numbers not found ")+bqn.output()));
 return it->second;
}

int BoxMatrix::getElementIndexNegIfFail(const BoxMatrixQuantumNumbers& bqn) const
{
 std::map<BoxMatrixQuantumNumbers,uint>::const_iterator it=m_indexmap.find(bqn);
 if (it==m_indexmap.end()) return -1;
 return it->second;
}

BoxMatrixQuantumNumbers BoxMatrix::getQuantumNumbers(uint index) const
{
 if (index>m_nelem)
    throw(std::runtime_error("Invalid index"));
 return m_quantnums[index];
}

void BoxMatrix::setElementsFromElab(double Elab_over_mref)
{
 double gam,usq;
 vector<double> svec;
 m_cmt.getGammaSvecUsq(Elab_over_mref,gam,svec,usq);
 m_wzetas.reset_if_diff(svec,gam,usq);
 (*m_evalptr)(m_wzetas,m_nelem,m_results);
 barrier_rescale(usq);
}


void BoxMatrix::setElementsFromEcm(double Ecm_over_mref)
{
 double gam,usq;
 vector<double> svec;
 m_cmt.getGammaSvecUsqFromEcm(Ecm_over_mref,gam,svec,usq);
 m_wzetas.reset_if_diff(svec,gam,usq);
 (*m_evalptr)(m_wzetas,m_nelem,m_results);
 barrier_rescale(usq);
}

void BoxMatrix::setElementsFromQcmsq(double qcmsq_over_mrefsq)
{
 double gam,usq;
 vector<double> svec;
 m_cmt.getGammaSvecUsqFromQcmsq(qcmsq_over_mrefsq,gam,svec,usq);
 m_wzetas.reset_if_diff(svec,gam,usq);
 (*m_evalptr)(m_wzetas,m_nelem,m_results);
 barrier_rescale(usq);
}

  //  multiplies m_results by  u^(rowL+colL+1)

void BoxMatrix::barrier_rescale(double usq_re)
{
 vector<cmplx> u_powers(std::max(2*m_lmax+1,2u));
 u_powers[1]=cmplx(usq_re,0.0);
 if (usq_re>=0.0) u_powers[0]=cmplx(sqrt(usq_re),0.0);
 else u_powers[0]=cmplx(0.0,sqrt(-usq_re));
 for (uint k=2;k<u_powers.size();k++)
    u_powers[k]=u_powers[1]*u_powers[k-2];
 for (uint k=0;k<m_quantnums.size();k++){
    BoxMatrixQuantumNumbers& bref=m_quantnums[k];
    m_results[k]*=u_powers.at(bref.getRowL()+bref.getColumnL());}
}


double BoxMatrix::getEcmOverMrefFromElab(double Elab_over_mref) const
{
 return m_cmt.getEcmOverMref(Elab_over_mref);
}


cmplx BoxMatrix::getElement(const BoxMatrixQuantumNumbers& bqn) const
{
 std::map<BoxMatrixQuantumNumbers,uint>::const_iterator it=m_indexmap.find(bqn);
 if (it!=m_indexmap.end())
    return m_results[it->second];
 BoxMatrixQuantumNumbers bqna(bqn);
 bqna.takeAdjoint();
 it=m_indexmap.find(bqna);
 if (it!=m_indexmap.end())
    return conj(m_results[it->second]);
 return cmplx(0.0,0.0);
}


void BoxMatrix::getElementsFromElab(double Elab_over_mref, std::vector<cmplx>& results)
{
 setElementsFromElab(Elab_over_mref);
 results=m_results;
}

void BoxMatrix::getElementsFromEcm(double Ecm_over_mref, std::vector<cmplx>& results)
{
 setElementsFromEcm(Ecm_over_mref);
 results=m_results;
}

void BoxMatrix::getElementsFromQcmsq(double qcmsq_over_mrefsq, std::vector<cmplx>& results)
{
 setElementsFromQcmsq(qcmsq_over_mrefsq);
 results=m_results;
}

map<string, BoxMatrix::EvaluatorPtr> BoxMatrix::initializeEvalPtrs()
{
 map<string, BoxMatrix::EvaluatorPtr> m;

#if (AR_LMAX>=0)
#if (AR_SX2MAX>=0)
 m["ar_0_A1g"]=&BoxMatrix::evaluate___ar_0_A1g;
 m["ar_0_A2g"]=&BoxMatrix::evaluate___ar_0_A2g;
 m["ar_0_A2u"]=&BoxMatrix::evaluate___ar_0_A2u;
 m["ar_0_Eg"]=&BoxMatrix::evaluate___ar_0_Eg;
 m["ar_0_Eu"]=&BoxMatrix::evaluate___ar_0_Eu;
 m["ar_0_T1g"]=&BoxMatrix::evaluate___ar_0_T1g;
 m["ar_0_T1u"]=&BoxMatrix::evaluate___ar_0_T1u;
 m["ar_0_T2g"]=&BoxMatrix::evaluate___ar_0_T2g;
 m["ar_0_T2u"]=&BoxMatrix::evaluate___ar_0_T2u;
#endif
#if (AR_SX2MAX>=1)
 m["ar_1_G1g"]=&BoxMatrix::evaluate___ar_1_G1g;
 m["ar_1_G1u"]=&BoxMatrix::evaluate___ar_1_G1u;
 m["ar_1_G2g"]=&BoxMatrix::evaluate___ar_1_G2g;
 m["ar_1_G2u"]=&BoxMatrix::evaluate___ar_1_G2u;
 m["ar_1_Hg"]=&BoxMatrix::evaluate___ar_1_Hg;
 m["ar_1_Hu"]=&BoxMatrix::evaluate___ar_1_Hu;
#endif
#if (AR_SX2MAX>=2)
 m["ar_2_A1g"]=&BoxMatrix::evaluate___ar_2_A1g;
 m["ar_2_A1u"]=&BoxMatrix::evaluate___ar_2_A1u;
 m["ar_2_A2g"]=&BoxMatrix::evaluate___ar_2_A2g;
 m["ar_2_A2u"]=&BoxMatrix::evaluate___ar_2_A2u;
 m["ar_2_Eg"]=&BoxMatrix::evaluate___ar_2_Eg;
 m["ar_2_Eu"]=&BoxMatrix::evaluate___ar_2_Eu;
 m["ar_2_T1g"]=&BoxMatrix::evaluate___ar_2_T1g;
 m["ar_2_T1u"]=&BoxMatrix::evaluate___ar_2_T1u;
 m["ar_2_T2g"]=&BoxMatrix::evaluate___ar_2_T2g;
 m["ar_2_T2u"]=&BoxMatrix::evaluate___ar_2_T2u;
#endif
#if (AR_SX2MAX>=3)
 m["ar_3_G1g"]=&BoxMatrix::evaluate___ar_3_G1g;
 m["ar_3_G1u"]=&BoxMatrix::evaluate___ar_3_G1u;
 m["ar_3_G2g"]=&BoxMatrix::evaluate___ar_3_G2g;
 m["ar_3_G2u"]=&BoxMatrix::evaluate___ar_3_G2u;
 m["ar_3_Hg"]=&BoxMatrix::evaluate___ar_3_Hg;
 m["ar_3_Hu"]=&BoxMatrix::evaluate___ar_3_Hu;
#endif
#if (AR_SX2MAX>=4)
 m["ar_4_A1g"]=&BoxMatrix::evaluate___ar_4_A1g;
 m["ar_4_A1u"]=&BoxMatrix::evaluate___ar_4_A1u;
 m["ar_4_A2g"]=&BoxMatrix::evaluate___ar_4_A2g;
 m["ar_4_A2u"]=&BoxMatrix::evaluate___ar_4_A2u;
 m["ar_4_Eg"]=&BoxMatrix::evaluate___ar_4_Eg;
 m["ar_4_Eu"]=&BoxMatrix::evaluate___ar_4_Eu;
 m["ar_4_T1g"]=&BoxMatrix::evaluate___ar_4_T1g;
 m["ar_4_T1u"]=&BoxMatrix::evaluate___ar_4_T1u;
 m["ar_4_T2g"]=&BoxMatrix::evaluate___ar_4_T2g;
 m["ar_4_T2u"]=&BoxMatrix::evaluate___ar_4_T2u;
#endif
#endif

#if (OA_LMAX>=0)
#if (OA_SX2MAX>=0)
 m["oa_0_A1"]=&BoxMatrix::evaluate___oa_0_A1;
 m["oa_0_A2"]=&BoxMatrix::evaluate___oa_0_A2;
 m["oa_0_B1"]=&BoxMatrix::evaluate___oa_0_B1;
 m["oa_0_B2"]=&BoxMatrix::evaluate___oa_0_B2;
 m["oa_0_E"]=&BoxMatrix::evaluate___oa_0_E;
#endif
#if (OA_SX2MAX>=1)
 m["oa_1_G1"]=&BoxMatrix::evaluate___oa_1_G1;
 m["oa_1_G2"]=&BoxMatrix::evaluate___oa_1_G2;
#endif
#if (OA_SX2MAX>=2)
 m["oa_2_A1"]=&BoxMatrix::evaluate___oa_2_A1;
 m["oa_2_A2"]=&BoxMatrix::evaluate___oa_2_A2;
 m["oa_2_B1"]=&BoxMatrix::evaluate___oa_2_B1;
 m["oa_2_B2"]=&BoxMatrix::evaluate___oa_2_B2;
 m["oa_2_E"]=&BoxMatrix::evaluate___oa_2_E;
#endif
#if (OA_SX2MAX>=3)
 m["oa_3_G1"]=&BoxMatrix::evaluate___oa_3_G1;
 m["oa_3_G2"]=&BoxMatrix::evaluate___oa_3_G2;
#endif
#if (OA_SX2MAX>=4)
 m["oa_4_A1"]=&BoxMatrix::evaluate___oa_4_A1;
 m["oa_4_A2"]=&BoxMatrix::evaluate___oa_4_A2;
 m["oa_4_B1"]=&BoxMatrix::evaluate___oa_4_B1;
 m["oa_4_B2"]=&BoxMatrix::evaluate___oa_4_B2;
 m["oa_4_E"]=&BoxMatrix::evaluate___oa_4_E;
#endif
#endif

#if (PD_LMAX>=0)
#if (PD_SX2MAX>=0)
 m["pd_0_A1"]=&BoxMatrix::evaluate___pd_0_A1;
 m["pd_0_A2"]=&BoxMatrix::evaluate___pd_0_A2;
 m["pd_0_B1"]=&BoxMatrix::evaluate___pd_0_B1;
 m["pd_0_B2"]=&BoxMatrix::evaluate___pd_0_B2;
#endif
#if (PD_SX2MAX>=1)
 m["pd_1_G"]=&BoxMatrix::evaluate___pd_1_G;
#endif
#if (PD_SX2MAX>=2)
 m["pd_2_A1"]=&BoxMatrix::evaluate___pd_2_A1;
 m["pd_2_A2"]=&BoxMatrix::evaluate___pd_2_A2;
 m["pd_2_B1"]=&BoxMatrix::evaluate___pd_2_B1;
 m["pd_2_B2"]=&BoxMatrix::evaluate___pd_2_B2;
#endif
#if (PD_SX2MAX>=3)
 m["pd_3_G"]=&BoxMatrix::evaluate___pd_3_G;
#endif
#endif

#if (CD_LMAX>=0)
#if (CD_SX2MAX>=0)
 m["cd_0_A1"]=&BoxMatrix::evaluate___cd_0_A1;
 m["cd_0_A2"]=&BoxMatrix::evaluate___cd_0_A2;
 m["cd_0_E"]=&BoxMatrix::evaluate___cd_0_E;
#endif
#if (CD_SX2MAX>=1)
 m["cd_1_F1"]=&BoxMatrix::evaluate___cd_1_F1;
 m["cd_1_F2"]=&BoxMatrix::evaluate___cd_1_F2;
 m["cd_1_G"]=&BoxMatrix::evaluate___cd_1_G;
#endif
#if (CD_SX2MAX>=2)
 m["cd_2_A1"]=&BoxMatrix::evaluate___cd_2_A1;
 m["cd_2_A2"]=&BoxMatrix::evaluate___cd_2_A2;
 m["cd_2_E"]=&BoxMatrix::evaluate___cd_2_E;
#endif
#if (CD_SX2MAX>=3)
 m["cd_3_F1"]=&BoxMatrix::evaluate___cd_3_F1;
 m["cd_3_F2"]=&BoxMatrix::evaluate___cd_3_F2;
 m["cd_3_G"]=&BoxMatrix::evaluate___cd_3_G;
#endif
#endif

 return m;
}


map<string, BoxMatrix::BlockSetupPtr> BoxMatrix::initializeBlockSetupPtrs()
{
 map<string, BoxMatrix::BlockSetupPtr> m;

#if (AR_LMAX>=0)
#if (AR_SX2MAX>=0)
 m["ar_0_A1g"]=&BoxMatrix::setup___ar_0_A1g;
 m["ar_0_A2g"]=&BoxMatrix::setup___ar_0_A2g;
 m["ar_0_A2u"]=&BoxMatrix::setup___ar_0_A2u;
 m["ar_0_Eg"]=&BoxMatrix::setup___ar_0_Eg;
 m["ar_0_Eu"]=&BoxMatrix::setup___ar_0_Eu;
 m["ar_0_T1g"]=&BoxMatrix::setup___ar_0_T1g;
 m["ar_0_T1u"]=&BoxMatrix::setup___ar_0_T1u;
 m["ar_0_T2g"]=&BoxMatrix::setup___ar_0_T2g;
 m["ar_0_T2u"]=&BoxMatrix::setup___ar_0_T2u;
#endif
#if (AR_SX2MAX>=1)
 m["ar_1_G1g"]=&BoxMatrix::setup___ar_1_G1g;
 m["ar_1_G1u"]=&BoxMatrix::setup___ar_1_G1u;
 m["ar_1_G2g"]=&BoxMatrix::setup___ar_1_G2g;
 m["ar_1_G2u"]=&BoxMatrix::setup___ar_1_G2u;
 m["ar_1_Hg"]=&BoxMatrix::setup___ar_1_Hg;
 m["ar_1_Hu"]=&BoxMatrix::setup___ar_1_Hu;
#endif
#if (AR_SX2MAX>=2)
 m["ar_2_A1g"]=&BoxMatrix::setup___ar_2_A1g;
 m["ar_2_A1u"]=&BoxMatrix::setup___ar_2_A1u;
 m["ar_2_A2g"]=&BoxMatrix::setup___ar_2_A2g;
 m["ar_2_A2u"]=&BoxMatrix::setup___ar_2_A2u;
 m["ar_2_Eg"]=&BoxMatrix::setup___ar_2_Eg;
 m["ar_2_Eu"]=&BoxMatrix::setup___ar_2_Eu;
 m["ar_2_T1g"]=&BoxMatrix::setup___ar_2_T1g;
 m["ar_2_T1u"]=&BoxMatrix::setup___ar_2_T1u;
 m["ar_2_T2g"]=&BoxMatrix::setup___ar_2_T2g;
 m["ar_2_T2u"]=&BoxMatrix::setup___ar_2_T2u;
#endif
#if (AR_SX2MAX>=3)
 m["ar_3_G1g"]=&BoxMatrix::setup___ar_3_G1g;
 m["ar_3_G1u"]=&BoxMatrix::setup___ar_3_G1u;
 m["ar_3_G2g"]=&BoxMatrix::setup___ar_3_G2g;
 m["ar_3_G2u"]=&BoxMatrix::setup___ar_3_G2u;
 m["ar_3_Hg"]=&BoxMatrix::setup___ar_3_Hg;
 m["ar_3_Hu"]=&BoxMatrix::setup___ar_3_Hu;
#endif
#if (AR_SX2MAX>=4)
 m["ar_4_A1g"]=&BoxMatrix::setup___ar_4_A1g;
 m["ar_4_A1u"]=&BoxMatrix::setup___ar_4_A1u;
 m["ar_4_A2g"]=&BoxMatrix::setup___ar_4_A2g;
 m["ar_4_A2u"]=&BoxMatrix::setup___ar_4_A2u;
 m["ar_4_Eg"]=&BoxMatrix::setup___ar_4_Eg;
 m["ar_4_Eu"]=&BoxMatrix::setup___ar_4_Eu;
 m["ar_4_T1g"]=&BoxMatrix::setup___ar_4_T1g;
 m["ar_4_T1u"]=&BoxMatrix::setup___ar_4_T1u;
 m["ar_4_T2g"]=&BoxMatrix::setup___ar_4_T2g;
 m["ar_4_T2u"]=&BoxMatrix::setup___ar_4_T2u;
#endif
#endif

#if (OA_LMAX>=0)
#if (OA_SX2MAX>=0)
 m["oa_0_A1"]=&BoxMatrix::setup___oa_0_A1;
 m["oa_0_A2"]=&BoxMatrix::setup___oa_0_A2;
 m["oa_0_B1"]=&BoxMatrix::setup___oa_0_B1;
 m["oa_0_B2"]=&BoxMatrix::setup___oa_0_B2;
 m["oa_0_E"]=&BoxMatrix::setup___oa_0_E;
#endif
#if (OA_SX2MAX>=1)
 m["oa_1_G1"]=&BoxMatrix::setup___oa_1_G1;
 m["oa_1_G2"]=&BoxMatrix::setup___oa_1_G2;
#endif
#if (OA_SX2MAX>=2)
 m["oa_2_A1"]=&BoxMatrix::setup___oa_2_A1;
 m["oa_2_A2"]=&BoxMatrix::setup___oa_2_A2;
 m["oa_2_B1"]=&BoxMatrix::setup___oa_2_B1;
 m["oa_2_B2"]=&BoxMatrix::setup___oa_2_B2;
 m["oa_2_E"]=&BoxMatrix::setup___oa_2_E;
#endif
#if (OA_SX2MAX>=3)
 m["oa_3_G1"]=&BoxMatrix::setup___oa_3_G1;
 m["oa_3_G2"]=&BoxMatrix::setup___oa_3_G2;
#endif
#if (OA_SX2MAX>=4)
 m["oa_4_A1"]=&BoxMatrix::setup___oa_4_A1;
 m["oa_4_A2"]=&BoxMatrix::setup___oa_4_A2;
 m["oa_4_B1"]=&BoxMatrix::setup___oa_4_B1;
 m["oa_4_B2"]=&BoxMatrix::setup___oa_4_B2;
 m["oa_4_E"]=&BoxMatrix::setup___oa_4_E;
#endif
#endif

#if (PD_LMAX>=0)
#if (PD_SX2MAX>=0)
 m["pd_0_A1"]=&BoxMatrix::setup___pd_0_A1;
 m["pd_0_A2"]=&BoxMatrix::setup___pd_0_A2;
 m["pd_0_B1"]=&BoxMatrix::setup___pd_0_B1;
 m["pd_0_B2"]=&BoxMatrix::setup___pd_0_B2;
#endif
#if (PD_SX2MAX>=1)
 m["pd_1_G"]=&BoxMatrix::setup___pd_1_G;
#endif
#if (PD_SX2MAX>=2)
 m["pd_2_A1"]=&BoxMatrix::setup___pd_2_A1;
 m["pd_2_A2"]=&BoxMatrix::setup___pd_2_A2;
 m["pd_2_B1"]=&BoxMatrix::setup___pd_2_B1;
 m["pd_2_B2"]=&BoxMatrix::setup___pd_2_B2;
#endif
#if (PD_SX2MAX>=3)
 m["pd_3_G"]=&BoxMatrix::setup___pd_3_G;
#endif
#endif

#if (CD_LMAX>=0)
#if (CD_SX2MAX>=0)
 m["cd_0_A1"]=&BoxMatrix::setup___cd_0_A1;
 m["cd_0_A2"]=&BoxMatrix::setup___cd_0_A2;
 m["cd_0_E"]=&BoxMatrix::setup___cd_0_E;
#endif
#if (CD_SX2MAX>=1)
 m["cd_1_F1"]=&BoxMatrix::setup___cd_1_F1;
 m["cd_1_F2"]=&BoxMatrix::setup___cd_1_F2;
 m["cd_1_G"]=&BoxMatrix::setup___cd_1_G;
#endif
#if (CD_SX2MAX>=2)
 m["cd_2_A1"]=&BoxMatrix::setup___cd_2_A1;
 m["cd_2_A2"]=&BoxMatrix::setup___cd_2_A2;
 m["cd_2_E"]=&BoxMatrix::setup___cd_2_E;
#endif
#if (CD_SX2MAX>=3)
 m["cd_3_F1"]=&BoxMatrix::setup___cd_3_F1;
 m["cd_3_F2"]=&BoxMatrix::setup___cd_3_F2;
 m["cd_3_G"]=&BoxMatrix::setup___cd_3_G;
#endif
#endif

 return m;
}


// *************************************************************************

         //   Initialize the static map of function pointers.
 
map<string, BoxMatrix::EvaluatorPtr> BoxMatrix::evaluatorMap(
        BoxMatrix::initializeEvalPtrs());

map<string, BoxMatrix::BlockSetupPtr> BoxMatrix::blockSetupMap(
        BoxMatrix::initializeBlockSetupPtrs());


// ***************************************************************************************
