#ifndef BOX_MATRIX_H
#define BOX_MATRIX_H

#include "cmframe.h"
#include "zeta.h"

// ***********************************************************************
// *                                                                     *
// *   The important class "BoxMatrix" is defined in this file.  This    *
// *   class computes the numerical values of all of the box matrix      *
// *   elements for a given block in the block diagonal basis.           *
// *                                                                     *
// *   The block is specified by a momentum ray (a string), the total    *
// *   intrinsic spin times two (to make an integer), and the little     *
// *   group irrep (a string).  The momentum ray can take the values     *
// *   "ar" at rest P=0, "oa" on-axis P=(0,0,n), "pd" planar-diagonal    *
// *   P=(0,n,n), or "cd" cubic-diagonal P=(n,n,n).                      *
// *                                                                     *
// *   The constructor also need to know Lmax, the maximum orbital       *
// *   angular momentum to use, and an object of the class               *
// *   "EcmTransform" (see the file "cmframe.h" for more details)        *
// *   which holds the total momentum in terms of dx,dy,dz, where        *
// *   total momentum is  P  = (2*Pi/L) * (dx,dy,dz), the spatial        *
// *   length of the lattice "mref_L" in terms of a reference mass,      *
// *   and the masses of particles 1 and 2 as ratios over mref           *
// *   "m1_over_mref" and "m2_over_mref".                                *
// *                                                                     *
// *   The constructor also needs an object of the class                 *
// *   "WZetaRGLCalculator" which is used for calculating the RGL        *
// *   zeta functions. This object stores a map of values already        *
// *   computed so that re-calculations do not occur.  In the            *
// *   quantization determinant, several box matrix objects might be     *
// *   needed due to having several total spin values, so for            *
// *   efficiency, it is best to allow these different "BoxMatrix"       *
// *   objects to access the same "WZetaRGLCalculator" object.  Hence,   *
// *   it must be declared and exist outside of this class.              *
// *                                                                     *
// *   Currently, Lmax up to 6 is supported, and total spin S up to 2    *
// *   is supported for "ar" and "oa", but only up to 3/2 for            *
// *   "pd" and "cd" momrays.                                            *
// *                                                                     *
// *   The particle masses and the lattice length can be reset using     *
// *   the member functions (use the first if the two masses are not     *
// *   equal, use the second if they are equal):                         *
// *                                                                     *
// *     resetMasses(mref_L,m1_over_mref,m2_over_mref);                  *
// *     resetMasses(mref_L,m1_over_mref);                               *
// *                                                                     *
// *   Once the particle masses and lattice length are set, one then     *
// *   first uses one of the members below:                              *
// *                                                                     *
// *      setElementsFromElab(Elab_over_mref);                           *
// *      setElementsFromEcm(Ecm_over_mref);                             *
// *      setElementsFromQcmsq(qcmsq_over_mrefsq);                       *
// *                                                                     *
// *   which computes all matrix elements, storing them internally.      *
// *   To get an individual matrix elements, then use                    *
// *                                                                     *
// *      getElement(BoxMatrixQuantumNumbers(2J',L',n',2J,L,n));         *
// *                                                                     *
// *   which returns a complex value.  If the quantum numbers given      *
// *   are not allowed, a zero value is returned.                        *
// *                                                                     *
// *   Alternatively, one can use                                        *
// *                                                                     *
// *     getElementsFromElab(Elab,results);                              *
// *     getElementsFromEcm(Ecm,results);                                *
// *     getElementsFromQcmsq(qcmsq,results);                            *
// *                                                                     *
// *   The matrix elements are returned in "results" as a vector         *
// *   of complex values.  The corresponding "J'L'n'JLn" quantum         *
// *   numbers of the j-th element of this vector can be found           *
// *   using the member                                                  *
// *                                                                     *
// *     getQuantumNumbers(j)                                            *
// *                                                                     *
// *   Only the diagonal elements and one half of the off-diagonal       *
// *   elements are returned.  For the other half of the off-diagonal    *
// *   elements, use the relationship:                                   *
// *        -- Hermitian if usq>=0 or Lp-L odd                           *
// *        -- antiHermitian otherwise                                   *
// *                                                                     *
// ***********************************************************************




  //  The box matrix rows and columns are each labelled by (2J,L,n),
  //  so an element must be specified by (2J',L',n',2J,L,n) involving
  //  six non-negative integers (remember that J is integral or half-integral).  
  //  Since each integer will be less than 32, we can use 5 bits for each 
  //  integer, storing them in a single 32-bit unsigned integer.

class BoxMatrixQuantumNumbers
{
    uint m_store;

 public:

    BoxMatrixQuantumNumbers(uint rowJtimestwo, uint rowL, uint rownocc, 
                            uint colJtimestwo, uint colL, uint colnocc);

    BoxMatrixQuantumNumbers(const BoxMatrixQuantumNumbers& inbqn);

    BoxMatrixQuantumNumbers& operator=(const BoxMatrixQuantumNumbers& inbqn);

    ~BoxMatrixQuantumNumbers() {}

    uint getRowJtimestwo() const;

    uint getRowL() const;

    uint getRowNocc() const;

    uint getColumnJtimestwo() const;

    uint getColumnL() const;

    uint getColumnNocc() const;

    void takeAdjoint();   // interchanges row and column quantum numbers

    bool isDiffLParity() const;

    bool isDiagElement() const;

    std::string output() const;

    bool operator==(const BoxMatrixQuantumNumbers& rhs) const;

    bool operator!=(const BoxMatrixQuantumNumbers& rhs) const;

    bool operator<(const BoxMatrixQuantumNumbers& rhs) const;
};


std::ostream& operator<<(std::ostream& os, const BoxMatrixQuantumNumbers& bqn);

inline BoxMatrixQuantumNumbers::BoxMatrixQuantumNumbers(
                           uint rowJtimestwo, uint rowL, uint rown, 
                           uint colJtimestwo, uint colL, uint coln)
{
 if ((rowJtimestwo>=32)||(rowL>=32)||(rown>=32)
   ||(colJtimestwo>=32)||(colL>=32)||(coln>=32)){
    throw(std::invalid_argument("Unsupported J'L'n'JLn values"));}
 m_store=rowJtimestwo;
 m_store<<=5; m_store|=rowL;
 m_store<<=5; m_store|=rown;
 m_store<<=5; m_store|=colJtimestwo;
 m_store<<=5; m_store|=colL;
 m_store<<=5; m_store|=coln;
}


inline BoxMatrixQuantumNumbers::BoxMatrixQuantumNumbers(
          const BoxMatrixQuantumNumbers& inbqn)
 : m_store(inbqn.m_store) {}

inline BoxMatrixQuantumNumbers& BoxMatrixQuantumNumbers::operator=(
          const BoxMatrixQuantumNumbers& inbqn)
{
 m_store=inbqn.m_store;
 return *this;
}


inline uint BoxMatrixQuantumNumbers::getRowJtimestwo() const
{
 return (m_store>>25) & 0x1Fu;
}

inline uint BoxMatrixQuantumNumbers::getRowL() const
{
 return (m_store>>20) & 0x1Fu;
}

inline uint BoxMatrixQuantumNumbers::getRowNocc() const
{
 return (m_store>>15) & 0x1Fu;
}

inline uint BoxMatrixQuantumNumbers::getColumnJtimestwo() const
{
 return (m_store>>10) & 0x1Fu;
}

inline uint BoxMatrixQuantumNumbers::getColumnL() const
{
 return (m_store>>5) & 0x1Fu;
}

inline uint BoxMatrixQuantumNumbers::getColumnNocc() const
{
 return m_store & 0x1Fu;
}

inline void BoxMatrixQuantumNumbers::takeAdjoint()
{
 uint temp=m_store;
 m_store=temp & 0x7FFFu;
 m_store<<=15;
 m_store|=temp>>15;
}

inline bool BoxMatrixQuantumNumbers::isDiffLParity() const
{
 return (((m_store>>20)&0x1u)!=((m_store>>5)&0x1u))?true:false;
}

inline bool BoxMatrixQuantumNumbers::isDiagElement() const
{
 return ((m_store&0x7FFFu)==(m_store>>15))?true:false;
}

inline bool BoxMatrixQuantumNumbers::operator==(const BoxMatrixQuantumNumbers& rhs) const
{
 return (m_store==rhs.m_store);   
}

inline bool BoxMatrixQuantumNumbers::operator!=(const BoxMatrixQuantumNumbers& rhs) const
{
 return (m_store!=rhs.m_store);   
}

inline bool BoxMatrixQuantumNumbers::operator<(const BoxMatrixQuantumNumbers& rhs) const
{
 return (m_store<rhs.m_store);
}



// ************************************************
// *                                              *
// *   Declaration of the class "BoxMatrix".      *
// *                                              *
// ************************************************


class BoxMatrix
{
    std::string m_momray, m_lgirrep;
    uint m_total_spin_times_two;
    EcmTransform m_cmt;
    uint m_lmax;
    uint m_nelem;
    std::map<BoxMatrixQuantumNumbers,uint> m_indexmap;
    std::vector<BoxMatrixQuantumNumbers> m_quantnums;
    WZetaRGLCalculator& m_wzetas;
    std::vector<cmplx> m_results;   //  internal storage of results

       // Prevent copying and no default.

   BoxMatrix(const BoxMatrix&);
   BoxMatrix& operator=(const BoxMatrix&);
   BoxMatrix();

 public:

    BoxMatrix(const EcmTransform &incm, WZetaRGLCalculator& wzetacalc,
              uint total_spin_times_two, const std::string& lgirrep, uint Lmax);

    ~BoxMatrix(){}

    void resetMasses(double mref_L_val, double m1_over_mref_val, 
                     double m2_over_mref_val);

    void resetMasses(double mref_L_val, double m1_over_mref_val);

    std::string getMomRay() const {return m_momray;}
 
    std::string getLittleGroupIrrep() const {return m_lgirrep;}

    uint getTotalSpinTimesTwo() const {return m_total_spin_times_two;}

    uint getLmax() const {return m_lmax;}

    uint getNumberOfIndepElements() const {return m_nelem;}

    uint getElementIndex(const BoxMatrixQuantumNumbers& bqn) const; 

    int getElementIndexNegIfFail(const BoxMatrixQuantumNumbers& bqn) const;  // negative if not found

    BoxMatrixQuantumNumbers getQuantumNumbers(uint index) const;

    double getEcmOverMrefFromElab(double Elab_over_mref) const;

    const EcmTransform& getEcmTransform() const {return m_cmt;}



    void setElementsFromElab(double Elab_over_mref);

    void setElementsFromEcm(double Ecm_over_mref);

    void setElementsFromQcmsq(double qcmsq_over_mrefsq);


    cmplx getElement(const BoxMatrixQuantumNumbers& bqn) const;


    void getElementsFromElab(double Elab_over_mref, std::vector<cmplx>& results);

    void getElementsFromEcm(double Ecm_over_mref, std::vector<cmplx>& results);

    void getElementsFromQcmsq(double qcmsq_over_mrefsq, std::vector<cmplx>& results);


 private:

   void barrier_rescale(double usq);

   typedef void (*EvaluatorPtr)(WZetaRGLCalculator& wzeta, uint n_elems, 
                                std::vector<cmplx>& results);
   EvaluatorPtr m_evalptr;
   typedef void (*BlockSetupPtr)(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);

   static std::map<std::string, EvaluatorPtr> evaluatorMap;
   static std::map<std::string, EvaluatorPtr> initializeEvalPtrs();
   static std::map<std::string, BlockSetupPtr> blockSetupMap;
   static std::map<std::string, BlockSetupPtr> initializeBlockSetupPtrs();

            //  evaluator and quantum number setup subroutines

            //  at rest (total zero momentum)
#if (AR_LMAX>=0)
#if (AR_SX2MAX>=0)

   static void evaluate___ar_0_A1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_0_A1g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_0_A2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_0_A2g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_0_A2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_0_A2u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_0_Eg(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_0_Eg(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_0_Eu(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_0_Eu(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_0_T1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_0_T1g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_0_T1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_0_T1u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_0_T2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_0_T2g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_0_T2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_0_T2u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (AR_SX2MAX>=1)
   static void evaluate___ar_1_G1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_1_G1g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_1_G1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_1_G1u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_1_G2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_1_G2g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_1_G2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_1_G2u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_1_Hg(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_1_Hg(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_1_Hu(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_1_Hu(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (AR_SX2MAX>=2)
   static void evaluate___ar_2_A1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_A1g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_2_A1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_A1u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_2_A2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_A2g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_2_A2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_A2u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_2_Eg(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_Eg(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_2_Eu(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_Eu(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_2_T1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_T1g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_2_T1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_T1u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_2_T2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_T2g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_2_T2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_2_T2u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (AR_SX2MAX>=3)
   static void evaluate___ar_3_G1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_3_G1g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_3_G1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_3_G1u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_3_G2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_3_G2g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_3_G2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_3_G2u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_3_Hg(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_3_Hg(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_3_Hu(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_3_Hu(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (AR_SX2MAX>=4)
   static void evaluate___ar_4_A1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_A1g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_4_A1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_A1u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_4_A2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_A2g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_4_A2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_A2u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_4_Eg(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_Eg(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_4_Eu(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_Eu(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_4_T1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_T1g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_4_T1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_T1u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_4_T2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_T2g(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___ar_4_T2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___ar_4_T2u(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#endif
              //  on-axis total momentum
#if (OA_LMAX>=0)
#if (OA_SX2MAX>=0)

   static void evaluate___oa_0_A1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_0_A1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_0_A2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_0_A2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_0_B1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_0_B1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_0_B2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_0_B2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_0_E(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_0_E(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (OA_SX2MAX>=1)
   static void evaluate___oa_1_G1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_1_G1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_1_G2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_1_G2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (OA_SX2MAX>=2)
   static void evaluate___oa_2_A1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_2_A1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_2_A2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_2_A2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_2_B1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_2_B1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_2_B2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_2_B2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_2_E(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_2_E(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (OA_SX2MAX>=3)
   static void evaluate___oa_3_G1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_3_G1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_3_G2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_3_G2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (OA_SX2MAX>=4)
   static void evaluate___oa_4_A1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_4_A1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_4_A2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_4_A2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_4_B1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_4_B1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_4_B2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_4_B2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___oa_4_E(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___oa_4_E(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#endif


              //  planar diagonal total momentum
#if (PD_LMAX>=0)
#if (PD_SX2MAX>=0)

   static void evaluate___pd_0_A1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_0_A1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___pd_0_A2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_0_A2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___pd_0_B1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_0_B1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___pd_0_B2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_0_B2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (PD_SX2MAX>=1)
   static void evaluate___pd_1_G(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_1_G(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (PD_SX2MAX>=2)
   static void evaluate___pd_2_A1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_2_A1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___pd_2_A2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_2_A2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___pd_2_B1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_2_B1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___pd_2_B2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_2_B2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (PD_SX2MAX>=3)
   static void evaluate___pd_3_G(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___pd_3_G(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#endif


              //  cubic diagonal total momentum
#if (CD_LMAX>=0)
#if (CD_SX2MAX>=0)


   static void evaluate___cd_0_A1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_0_A1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___cd_0_A2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_0_A2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___cd_0_E(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_0_E(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (CD_SX2MAX>=1)
   static void evaluate___cd_1_F1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_1_F1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___cd_1_F2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_1_F2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___cd_1_G(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_1_G(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (CD_SX2MAX>=2)
   static void evaluate___cd_2_A1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_2_A1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___cd_2_A2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_2_A2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___cd_2_E(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_2_E(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#if (CD_SX2MAX>=3)
   static void evaluate___cd_3_F1(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_3_F1(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___cd_3_F2(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_3_F2(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
   static void evaluate___cd_3_G(WZetaRGLCalculator& wzeta, uint n_elems,
                                   std::vector<cmplx>& results);
   static void setup___cd_3_G(uint lmax,
               std::vector<BoxMatrixQuantumNumbers>& quantnums);
#endif
#endif
};

#endif
