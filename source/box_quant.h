#ifndef BOX_QUANT_H
#define BOX_QUANT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <map>
#include <vector>
#include <complex>
#include "cmframe.h"
#include "xml_handler.h"
#include "box_matrix.h"
#include "K_matrix_calc.h"
#include "matrix.h"

typedef unsigned int  uint;
typedef std::complex<double> cmplx;


// ***********************************************************************
// *                                                                     *
// *   The important class "BoxQuantization" is defined in this file.    *
// *   This class computes                                               *
// *                                                                     *
// *         det(Ktildeinverse-B)   or   det(1-Ktilde*B)                 *
// *                                                                     *
// *   where B is the all-important box matrix, and Ktilde is related    *
// *   to the scattering K-matrix through the effective range            *
// *   expansion                                                         *
// *                                                                     *
// *       Kinv[aL',bL] = u_a^(L'+1/2) Ktildeinv[aL',bL] u_b^(L+1/2).    *
// *                                                                     *
// *   A separate object of this class is needed for each **block** for  *
// *   a single ensemble of Monte Carlo configurations.  A block is      *
// *   specified by total momentum P, little group irrep Lambda, and     *
// *   details of each channel: for each decay channel, we need to know  *
// *   the two particle spins, whether or not they are identical, and    *
// *   the product of their intrinsic parities.                          *
// *                                                                     *
// *   An object of this class can be constructed from input XML of the  *
// *   form                                                              *
// *                                                                     *
// *    <BoxQuantization>                                                *
// *      <TotalMomentumRay>oa</TotalMomentumRay>                        *
// *          ["ar"=at rest (0,0,0), "oa"=on axis (0,0,1),               *
// *           "pd"=planar diagonal (0,1,1),                             *
// *           "cd"=cubic diagonal (1,1,1)]                              *
// *      <TotalMomentumIntSquared>2</TotalMomentumIntSquared>           *
// *          [if total momentum is (2*Pi/L)(1,1,1), then IntSquared=3]  *
// *      <LGIrrep>T1u</LGIrrep>                                         *
// *      <DecayChannel>                                                 *
// *        <DecayChannelInfo>...</DecayChannelInfo>                     *
// *        <Lmax>4</Lmax>                                               *
// *      </DecayChannel>                                                *
// *       .... (other decay channels)                                   *
// *    </BoxQuantization>                                               *
// *                                                                     *
// *   The block is specified by a momentum ray (a string).  The         *
// *   momentum ray can take the values "ar" at rest P=0, "oa" on-axis   *
// *   P=(0,0,n), "pd" planar-diagonal P=(0,n,n), or "cd" cubic-diagonal *
// *   P=(n,n,n). The total momentum P is given in terms of three        *
// *   integers dx,dy,dz,  where P  = (2*Pi/L) * (dx,dy,dz), and "L"     *
// *   is the spatial length of the lattice                              *
// *                                                                     *
// *   For each decay channel, a maximum orbital angular momentum must   *
// *   be given, in addition to some necessary information.  Currently,  *
// *   Lmax up to 6 is supported.  The XML format for each decay channel *
// *   information is                                                    *
// *                                                                     *
// *    <DecayChannelInfo>                                               *
// *      <Particle1Name>pion</Particle1Name>                            *
// *      <Spin1TimesTwo>0</Spin1TimesTwo>                               *
// *      <Identical/> (if identical, do not include tags below)         *
// *      <Particle2Name>eta</Particle2Name>                             *
// *      <Spin2TimesTwo>2</Spin2TimesTwo>                               *
// *      <IntrinsicParities>same</IntrinsicParities> (or "opposite")    *
// *    </DecayChannelInfo>                                              *
// *                                                                     *
// *   The tag for each <IntrinsicParities> must match the tags in all   *
// *   other decay channels or an exception is thrown.                   *
// *                                                                     *
// *   The constructor also requires that the end user supply either     *
// *   a pointer to a KtildeMatrixCalculator object or a                 *
// *   KtildeInverseCalculator object.  If a KtildeMatrixCalculator is   *
// *   given, then  det(1-B*Ktilde) is computed.  If a                   *
// *   KtildeInverseCalculator pointer is given, then  det(Ktildeinv-B)  *
// *   is computed.                                                      *
// *                                                                     *
// *                                                                     *
// *   Once constructed, the most important tasks are to reset the       *
// *   decay particle masses, the length of the lattice, and to          *
// *   compute the quantization determinant for a given lab frame        *
// *   energy.  All energies and lengths are expressed in terms of       *
// *   some reference scale "mref".                                      *
// *                                                                     *
// *   To reset the length of the lattice and the decay particle         *
// *   masses of channel "a", where a=0,1,..., use member functions      *
// *                                                                     *
// *       setRefMassL(mref_L);                                          *
// *       setMassesOverRef(channel_index,mass1_over_ref,                *
// *                        mass2_over_ref);                             *
// *                                                                     *
// *   Some of the quantities that can be computed are below:            *
// *                                                                     *
// *      //  computes Omega(mu,Ktildeinv-B) or                          *
// *      //  Omega(mu,1-B*K)   (depending on K or Kinv mode)            *
// *                                                                     *
// *     double getOmegaFromElab(mu, Elab_over_mref);                    *
// *     double getOmegaFromEcm(mu, Ecm_over_mref);                      *
// *     ComplexHermitianMatrix B;                                       *
// *     RealSymmetricMatrix Kv;                                         *
// *     double getOmega(mu,Kv,B);                                       *
// *                                                                     *
// *      //  computes [det(Ktildeinv-B)]^(1/Ndet) or                    *
// *      //  [det(1-B*K)]^(1/Ndet) where Ndet is positive odd integer   *
// *      //    (depending on K or Kinv mode)                            *
// *                                                                     *
// *     double getDeterminantRootFromElab(Elab_over_mref, Ndet);        *
// *     double getDeterminantRootFromEcm(Ecm_over_mref, Ndet);          *
// *                                                                     *
// *   For the residual determinant fitting method, extract the          *
// *   box matrix at the observed energy, then the Ktilde or Ktildeinv   *
// *   separately, then there is a determinant routine that uses these   *
// *   extracted matrices:                                               *
// *                                                                     *
// *     ComplexHermitianMatrix B;                                       *
// *     RealSymmetricMatrix Kv;                                         *
// *     BQ.getBoxMatrixFromElab(Elab_over_mref,B);                      *
// *     BQ.getKtildeOrInverseFromElab(Elab_over_mref,Kv);               *
// *     double detroot=BQ.getDeterminantRoot(Kv,B,Ndet);                *
// *                                                                     *
// *      //  computes the real eigenvalues of Ktildeinv-B  or           *
// *      //  the eigenvalues of (B - B*K*B), divided by |detB|^(1/N)    *
// *      //  for NxN matrices (depending on K or Kinv mode)             *
// *                                                                     *
// *     vector<double> getEigenvaluesFromElab(Elab_over_mref);          *
// *     vector<double> getEigenvaluesFromEcm(Ecm_over_mref);            *
// *                                                                     *
// *                                                                     *
// *                                                                     *
// ***********************************************************************




  //  Contains information related to a particular decay channel:
  //  names of each particle (such as "pion", "eta", "pion+"),
  //  spins of each particle (times two to make a nonnegative integer),
  //  and booleans telling if the particles are identical and if they
  //  have the same intrinsic parities.

  //  Construction by XML:
  //    <DecayChannelInfo>
  //      <Particle1Name>pion</Particle1Name>
  //      <Spin1TimesTwo>0</Spin1TimesTwo>
  //      <Identical/> (if identical, do not include tags below)
  //      <Particle2Name>eta</Particle2Name>
  //      <Spin2TimesTwo>2</Spin2TimesTwo>
  //      <IntrinsicParities>same</IntrinsicParities> (or "opposite")
  //    </DecayChannelInfo>

  //  Implementation: m_store contains 15 bits spin1timestwo,
  //  15 bits spin2timestwo, 1 bit identical, 1 bit same intrinsic parities.



class DecayChannelInfo
{
    std::string m_name1, m_name2;
    uint m_store;

 public:

    DecayChannelInfo(const std::string& particle1_name, const std::string& particle2_name,
                     uint spin1_times_two, uint spin2_times_two,
                     bool identical, bool same_intrinsic_parities);

    DecayChannelInfo(XMLHandler& xmlin);

    DecayChannelInfo(const DecayChannelInfo& dcinfo);

    DecayChannelInfo& operator=(const DecayChannelInfo& dcinfo);

    ~DecayChannelInfo() {}

    std::string getParticle1Name() const {return m_name1;}

    std::string getParticle2Name() const {return m_name2;}

    uint getSpin1timestwo() const;

    uint getSpin2timestwo() const;

    bool areIdentical() const;

    bool sameIntrinsicParities() const;

    std::string output(int indent=0) const;  // XML output 

    std::string str() const;  // XML output 

    void output(XMLHandler& xmlout) const;  // XML output

    bool operator==(const DecayChannelInfo& rhs) const;

    bool operator!=(const DecayChannelInfo& rhs) const;

   // bool operator<(const DecayChannelInfo& rhs) const;

 private:

    void check_encode(uint spin1_times_two, uint spin2_times_two,
                      bool identical, bool same_intrinsic_parities);
};


std::ostream& operator<<(std::ostream& os, const DecayChannelInfo& dcinfo);



inline uint DecayChannelInfo::getSpin1timestwo() const
{
 return m_store>>17;
}

inline uint DecayChannelInfo::getSpin2timestwo() const
{
 return (m_store>>2) & 0x7FFFu;
}

inline bool DecayChannelInfo::areIdentical() const
{
 return (m_store>>1) & 0x1u;
}

inline bool DecayChannelInfo::sameIntrinsicParities() const
{
 return m_store & 0x1u;
}


inline bool DecayChannelInfo::operator==(const DecayChannelInfo& rhs) const
{
 return  (m_store==rhs.m_store)&&(m_name1==rhs.m_name1)&&(m_name2==rhs.m_name2)
       &&(m_name1==rhs.m_name1)&&(m_name2==rhs.m_name2);
}

inline bool DecayChannelInfo::operator!=(const DecayChannelInfo& rhs) const
{
 return  (m_store!=rhs.m_store)||(m_name1!=rhs.m_name1)||(m_name2!=rhs.m_name2)
       ||(m_name1!=rhs.m_name1)||(m_name2!=rhs.m_name2);
}


  //  Specifies a basis state for the Kinverse-B matrix in the quantization
  //  condition:
  //        | a S J L n >    a = channel index, n = occurrence

  //   m_store encodes the channel index (6 bits),
  //   total S times two (6 bits), total J times two (7 bits)
  //   L (7 bits), occurrence index (6 bits)
  //  Each state maintains a pointer to a BoxMatrix object.



class BoxQuantBasisState
{
    BoxMatrix *m_boxmat;
    uint m_store;

    BoxQuantBasisState() = delete;  // no default value

 public:

    BoxQuantBasisState(BoxMatrix *boxmat, uint channel_index,
                       uint Stimestwo, uint Jtimestwo,
                       uint L, uint occurrence);

    BoxQuantBasisState(const BoxQuantBasisState& in)
           : m_boxmat(in.m_boxmat), m_store(in.m_store) {}

    BoxQuantBasisState& operator=(const BoxQuantBasisState& in)
       {m_boxmat=in.m_boxmat; m_store=in.m_store; return *this;}

    ~BoxQuantBasisState() {}

    BoxMatrix* getBoxMatrixPtr() const {return m_boxmat;}

    uint getChannelIndex() const;

    uint getStimestwo() const;
 
    uint getJtimestwo() const;

    uint getL() const;

    uint getOccurrence() const;

    bool operator==(const BoxQuantBasisState& rhs) const;

    bool operator!=(const BoxQuantBasisState& rhs) const;

    bool operator<(const BoxQuantBasisState& rhs) const;

    std::string output(int indent=0) const;  // XML output 

    std::string str() const;  // XML output 

    void output(XMLHandler& xmlout) const;  // XML output

 private:

    void check_encode(uint channel_index, uint Stimestwo, uint Jtimestwo,
                      uint L, uint occurrence);

};


inline uint BoxQuantBasisState::getChannelIndex() const
{
 return m_store>>26;
}

inline uint BoxQuantBasisState::getStimestwo() const
{
 return (m_store>>20)& 0x3Fu;
}

inline uint BoxQuantBasisState::getJtimestwo() const
{
 return (m_store>>13) & 0x7Fu;
}

inline uint BoxQuantBasisState::getL() const
{
 return (m_store>>6) & 0x7Fu;
}

inline uint BoxQuantBasisState::getOccurrence() const
{
 return m_store & 0x3Fu;
}


inline bool BoxQuantBasisState::operator==(const BoxQuantBasisState& rhs) const
{
 return (m_boxmat==rhs.m_boxmat)&&(m_store==rhs.m_store);
}


inline bool BoxQuantBasisState::operator!=(const BoxQuantBasisState& rhs) const
{
 return (m_boxmat!=rhs.m_boxmat)||(m_store!=rhs.m_store);
}


inline bool BoxQuantBasisState::operator<(const BoxQuantBasisState& rhs) const
{
 return   ((m_boxmat<rhs.m_boxmat) || ((m_boxmat==rhs.m_boxmat)
        && (m_store<rhs.m_store) ));
}


// ******************************************************
// *                                                    *
// *   Declaration of the class "BoxQuantization".      *
// *                                                    *
// ******************************************************

   //  Implementation details:
  
   //  "m_basis" contains information about the basis of states.
   //  "m_wzetas" contains pointers to the created "WZetaRGLCalculator"
   //    objects; there is one for each channel since for a given
   //    Elab, there is a different qcmsq,svec,usq for each channel.
   //  "m_boxes" contains pointers to the "BoxMatrix" objects created;
   //    there is one for each channel and each total S in each channel;
   //    the elements of this list are a pair containing the pointer
   //    to a "BoxMatrix" object and the index of the associated channel;
   //    this channel index is needed for resetting masses in the
   //    "BoxMatrix" objects.




class BoxQuantization
{

    std::string m_lgirrep, m_lgirrepB;
    std::string m_momray;
    uint m_dx,m_dy,m_dz;
    std::vector<DecayChannelInfo> m_decay_infos;
    std::vector<uint> m_Lmaxes;

    double m_mref_L;
    std::vector<double> m_masses1, m_masses2;

    std::set<BoxQuantBasisState> m_basis;
    std::list<std::pair<BoxMatrix*,uint> > m_boxes;
    std::list<WZetaRGLCalculator*> m_wzetas;

    std::vector<double> m_kappa_params;
    KtildeMatrixCalculator* m_Kmat;
    KtildeInverseCalculator* m_Kinv;

       // Prevent copying and no default.

    BoxQuantization(const BoxQuantization&);
    BoxQuantization& operator=(const BoxQuantization&);
    BoxQuantization();

 public:

    BoxQuantization(XMLHandler& xmlin,
                    KtildeMatrixCalculator *Kmatptr);

    BoxQuantization(XMLHandler& xmlin,
                    KtildeInverseCalculator *Kinvptr);

    BoxQuantization(XMLHandler& xmlin,
                    KtildeMatrixCalculator *Kmatptr,
                    KtildeInverseCalculator *Kinvptr);  // one of the pointers must be null

    BoxQuantization(const std::string& mom_ray, uint mom_int_sq,
                    const std::string& lgirrep, 
                    const std::vector<DecayChannelInfo>& chan_infos,
                    const std::vector<uint> lmaxes,
                    KtildeMatrixCalculator *Kmatptr);

    BoxQuantization(const std::string& mom_ray, uint mom_int_sq,
                    const std::string& lgirrep, 
                    const std::vector<DecayChannelInfo>& chan_infos,
                    const std::vector<uint> lmaxes,
                    KtildeInverseCalculator *Kinvptr);

    ~BoxQuantization();

    std::string getMomRay() const 
         {return m_momray;}
 
    std::string getLittleGroupIrrep() const 
         {return m_lgirrep;}

    std::string getLittleGroupBoxIrrep() const 
         {return m_lgirrepB;}

    uint getTotalMomentumIntegerSquared() const 
         {return m_dx*m_dx+m_dy*m_dy+m_dz*m_dz;}

    DecayChannelInfo getDecayChannelInfo(uint channel_index) const
         {return m_decay_infos.at(channel_index);}

    uint getLmax(uint channel_index) const 
         {return m_Lmaxes.at(channel_index);}

    void setRefMassL(double mref_L);

    void setMassesOverRef(uint channel_index, double mass1_over_ref,
                          double mass2_over_ref);

    void setKtildeParameters(std::vector<double> kappa_params);



    double getRefMassL() const {return m_mref_L;}

    double getMass1OverRef(uint channel_index) const
         {return m_masses1.at(channel_index);}

    double getMass2OverRef(uint channel_index) const
         {return m_masses2.at(channel_index);}

    bool isKtildeInverseMode() const
         {return (m_Kinv!=0);}

    bool isKtildeMode() const
         {return (m_Kmat!=0);}

    uint getNumberOfKtildeParameters() const
         {if (m_Kmat!=0) return m_Kmat->getNumberOfParameters();
          else return m_Kinv->getNumberOfParameters();}


    std::string output(int indent=0) const;  // XML output 

    std::string str() const;  // XML output 

    void output(XMLHandler& xmlout) const;  // XML output

    void outputBasis(XMLHandler& xmlout) const;  // XML output

    std::string outputBasis(int indent=0) const;  // XML output 

    void outputKFitParams(XMLHandler& xmlout) const;  // XML output

    std::string outputKFitParams(int indent=0) const;  // XML output 


    const std::vector<KFitParamInfo>& getFitParameterInfos() const;

    int getParameterIndex(const KFitParamInfo& kinfo) const;  // returns -1 if not found

    double getParameterValue(const KFitParamInfo& kinfo) const;

    std::set<KElementInfo> getElementInfos() const;


    double getEcmOverMrefFromElab(double Elab_over_mref) const;

    void getBoxMatrixFromElab(double Elab_over_mref, ComplexHermitianMatrix& B);

    void getBoxMatrixFromElab(double Elab_over_mref, CMatrix& B);

    void getBoxMatrixFromEcm(double Ecm_over_mref, ComplexHermitianMatrix& B);

    void getBoxMatrixFromEcm(double Ecm_over_mref, CMatrix& B);

    void getKtildeFromElab(double Elab_over_mref, RealSymmetricMatrix& Ktilde);

    void getKtildeFromElab(double Elab_over_mref, RMatrix& Ktilde);

    void getKtildeFromEcm(double Ecm_over_mref, RealSymmetricMatrix& Ktilde);

    void getKtildeFromEcm(double Ecm_over_mref, RMatrix& Ktilde);

    void getKtildeinvFromElab(double Elab_over_mref, RealSymmetricMatrix& Ktildeinv);

    void getKtildeinvFromElab(double Elab_over_mref, RMatrix& Ktildeinv);

    void getKtildeinvFromEcm(double Ecm_over_mref, RealSymmetricMatrix& Ktildeinv);

    void getKtildeinvFromEcm(double Ecm_over_mref, RMatrix& Ktildeinv);

            // gets Ktilde or Ktildeinv, depending on mode
    void getKtildeOrInverseFromElab(double Elab_over_mref, RealSymmetricMatrix& KtildeOrInverse);

    void getKtildeOrInverseFromElab(double Elab_over_mref, RMatrix& KtildeOrInverse);

    void getKtildeOrInverseFromEcm(double Ecm_over_mref, RealSymmetricMatrix& KtildeOrInverse);

    void getKtildeOrInverseFromEcm(double Ecm_over_mref, RMatrix& KtildeOrInverse);


    void outputKBMatricesFromElab(double Elab_over_mref, std::ostream& fout);

    void outputKBMatricesFromEcm(double Ecm_over_mref, std::ostream& fout);


             //  computes Omega(mu,Ktildeinv-B) or Omega(mu,1-B*K)
             //         (depending on K or Kinv mode)

    double getOmegaFromElab(double mu, double Elab_over_mref);

    double getOmegaFromEcm(double mu, double Ecm_over_mref);

    double getOmega(double mu, const RealSymmetricMatrix& KtildeOrInverse,
                    const ComplexHermitianMatrix& B);


             //  computes [det(Ktildeinv-B)]^(1/Ndet) or [det(1-B*K)]^(1/Ndet)
             //  where Ndet is positive odd integer (depending on K or Kinv mode)

    double getDeterminantRootFromElab(double Elab_over_mref, uint Ndet);

    double getDeterminantRootFromEcm(double Ecm_over_mref, uint Ndet);

    double getDeterminantRoot(const RealSymmetricMatrix& KtildeOrInverse,
                              const ComplexHermitianMatrix& B, uint Ndet);


             //  computes the real eigenvalues of Ktildeinv-B  or
             //  the eigenvalues of (B - B*K*B), divided by |detB|^(1/N)
             //  for NxN matrices (depending on K or Kinv mode)

    std::vector<double> getEigenvaluesFromElab(double Elab_over_mref);

    std::vector<double> getEigenvaluesFromEcm(double Ecm_over_mref);


             //  computes [det(B)]^(1/Ndet) 

    double getBoxMatrixDeterminantRootFromElab(double Elab_over_mref, uint Ndet);

    double getBoxMatrixDeterminantRootFromEcm(double Ecm_over_mref, uint Ndet);

    double getBoxMatrixDeterminantRoot(const ComplexHermitianMatrix& B, uint Ndet);


 private:

    void clear();

    void set_dvector(uint mom_int_sq);

    void xmlinitialize(XMLHandler& xlmin);

    void initialize();

    void setup_basis();

    std::string getLGIrrepParityFlip();

    void assign(const cmplx& value, uint row, uint col, bool herm, 
                ComplexHermitianMatrix& Bh, CMatrix& B);

    void assign(double value, uint row, uint col, bool herm, 
                RealSymmetricMatrix& Kh, RMatrix& K);

    void assign_matrices(double E_over_mref, bool Elab, ComplexHermitianMatrix& B,
                         RealSymmetricMatrix& Kv);

    void get_box_matrix(double E_over_mref, ComplexHermitianMatrix& Bh, CMatrix& B,
                        bool Elab, bool herm);

    template<typename T>
    void get_ktilde_matrix(double E_over_mref, RealSymmetricMatrix& Kh, RMatrix& K,
                           bool Elab, bool herm, T* evalptr);

    template<typename T>
    std::set<BoxQuantBasisState> find_excluded_states_from_ktilde(T* evalptr);

    void output_matrices(double E_over_mref, bool Elab, std::ostream& fout);

    double get_determinant(double E_over_mref, bool Elab, uint Ndet);

    double get_determinant(uint N, const RealSymmetricMatrix& Kv,
                           const ComplexHermitianMatrix& B, uint Ndet);

    std::vector<double> get_eigenvalues(double E_over_mref, bool Elab);

    double get_omega(double mu, double E_over_mref, bool Elab);
  
    double get_omega(double mu, uint N, const RealSymmetricMatrix& Kv,
                     const ComplexHermitianMatrix& B);

};

#endif
