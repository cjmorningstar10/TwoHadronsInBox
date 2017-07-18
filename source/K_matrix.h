#ifndef KSCAT_MATRIX_H
#define KSCAT_MATRIX_H

#include "xml_handler.h"
#include <map>

// ***********************************************************************
// *                                                                     *
// *   The important classes "KtildeMatrixCalculator" and                *
// *   "KtildeInverseCalculator" are defined in this file.  Objects of   *
// *   these classes compute the numerical values of all of the matrix   *
// *   elements of the K-matrix or its inverse for a given block in      *
// *   the block diagonal basis.                                         *
// *                                                                     *
// *   Construction by XML content:                                      *
// *                                                                     *
// *   <KtildeMatrix> or <KtildeMatrixInverse>                           *
// *     <Element>                                                       *
// *       <KElementInfo>...</KElementInfo>                              *
// *       <FitForm>...</FitForm>                                        *
// *     </Element>                                                      *
// *      ......                                                         *
// *   </KtildeMatrix> or </KtildeMatrixInverse>                         *
// *                                                                     *
// *   where                                                             *
// *                                                                     *
// *   <KElementInfo>                                                    *
// *      <JTimesTwo>6</JTimesTwo>                                       *
// *      <KIndex>...</KIndex>                                           *
// *      <KIndex>...</KIndex>    ( must have 1 or 2 <KIndex> tags)      *
// *   </KElementInfo>                                                   *
// *                                                                     *
// *   and                                                               *
// *                                                                     *
// *   <KIndex><L>3</L><Sx2>1<Sx2><Chan>0</Chan></KIndex>  OR            *
// *   <KIndex>L(3) 2S(1) chan(0)</KIndex> (order matters in this form)  *
// *                                                                     *
// *   The <FitForm> tag currently may include one or both of the        *
// *   following (if both, the full form is a SUM of the two subforms):  *
// *                                                                     *
// *   <Polynomial>           or      <Polynomial>                       *
// *     <Degree>3</Degree>             <Powers>0 1 2</Powers>           *
// *   </Polynomial>                  </Polynomial>                      *
// *                                                                     *
// *      -- form on left includes all power 0,1,...Degree               *
// *      -- form on right includes only those powers actually listed    *
// *                                                                     *
// *   <SumOfPoles>           or         <SumOfPoles>                    *
// *     <NumberOfPoles>2</NumberOfPoles>  <PoleIndices>0 2</PoleIndices>*
// *   </SumOfPoles>                     </SumOfPoles>                   *
// *                                                                     *
// *      -- form on left includes all pole indices 0,1,...Number-1      *
// *      -- form on right includes only those pole indices listed       *
// *                                                                     *
// *   Note: "KtildeMatrixCalculator" can use both <Polynomial> and      *
// *   <SumOfPoles> in <FitForm>,  BUT "KtildeInverseCalculator" can     *
// *   ONLY use <Polynomial>.                                            *
// *                                                                     *
// ***********************************************************************






  //  This class is a compound index containing (L, 2S, a)
  //     m_store encodes the L (4 bits), total S times two (4 bits),
  //     channel index (4 bits)
  //  Construction by XML:
  //    <KIndex><L>3</L><Sx2>1<Sx2><Chan>0</Chan></KIndex>
  //  or <KIndex>L(3) 2S(1) chan(0)</KIndex>  (order matters in this form)


class KIndex
{
    uint m_store;

    KIndex() = delete;  // no default value

 public:

    KIndex(XMLHandler& xmlin);

    KIndex(uint L, uint Stimestwo, uint channel_index);

    KIndex(const KIndex& in)
           : m_store(in.m_store) {}

    KIndex& operator=(const KIndex& in)
       {m_store=in.m_store; return *this;}

    ~KIndex() {}

    uint getL() const;

    uint getStimestwo() const;
 
    uint getChannelIndex() const;

    bool operator==(const KIndex& rhs) const;

    bool operator!=(const KIndex& rhs) const;

    bool operator<(const KIndex& rhs) const;

    std::string output(int indent=0) const;  // XML output 

    std::string str() const;  // XML output 

    void output(XMLHandler& xmlout) const;  // XML output

 private:

    KIndex(uint store) : m_store(store) {}

    void check_encode(uint L, uint Stimestwo, uint channel_index);

    friend class KElementInfo;

    friend class KFitParamInfo;

};


inline uint KIndex::getL() const
{
 return (m_store>>8) & 0xFu;
}

inline uint KIndex::getStimestwo() const
{
 return (m_store>>4)& 0xFu;
}

inline uint KIndex::getChannelIndex() const
{
 return m_store & 0xFu;
}

inline bool KIndex::operator==(const KIndex& rhs) const
{
 return (m_store==rhs.m_store);
}


inline bool KIndex::operator!=(const KIndex& rhs) const
{
 return (m_store!=rhs.m_store);
}


inline bool KIndex::operator<(const KIndex& rhs) const
{
 return (m_store<rhs.m_store);
}




  //  This class identifies an element of the K-matrix using
  //          J (L'S'a', LSa)
  //     m_store encodes 
  //       J (four bits)  (L'S'a') (12 bits),  (Lsa) (12 bits)
  //  Since K is real and symmetric, the (L'S'a') and (LSa)
  //  order is sorted according to how stored in "KIndex".
  //  The constructor also checks that J,L,S are allowed values.
  //  XML input for constructor must have form
  //    <KElementInfo>
  //       <JTimesTwo>6</JTimesTwo>
  //       <KIndex>...</KIndex>
  //       <KIndex>...</KIndex>    ( must have 1 or 2 <KIndex> tags)
  //    </KElementInfo>


class KElementInfo
{
    uint m_store;

    KElementInfo() = delete;  // no default value

 public:

    KElementInfo(XMLHandler& xmlin);

    KElementInfo(uint Jtimestwo, 
                 uint rowL, uint rowStimestwo, uint rowchannelindex,
                 uint colL, uint colStimestwo, uint colchannelindex);

    KElementInfo(const KElementInfo& in)
           : m_store(in.m_store) {}

    KElementInfo& operator=(const KElementInfo& in)
       {m_store=in.m_store; return *this;}

    ~KElementInfo() {}

    uint getJtimestwo() const;

    uint getRowL() const;

    uint getRowStimestwo() const;
 
    uint getRowChannelIndex() const;

    KIndex getRow() const;

    uint getColumnL() const;

    uint getColumnStimestwo() const;
 
    uint getColumnChannelIndex() const;

    KIndex getColumn() const;

    bool operator==(const KElementInfo& rhs) const;

    bool operator!=(const KElementInfo& rhs) const;

    bool operator<(const KElementInfo& rhs) const;

    std::string output(int indent=0) const;  // XML output 

    std::string str() const;  // XML output 

    void output(XMLHandler& xmlout) const;  // XML output

 private:

    void check_encode(uint Jtimestwo, 
             uint rowL, uint rowStimestwo, uint rowchannelindex,
             uint colL, uint colStimestwo, uint colchannelindex);

    void encode(uint Jtimestwo, const KIndex& kl,
                const KIndex& kr);

    bool invalidJLS(uint Jtimestwo, uint L, uint Stimestwo);

    KElementInfo(uint store) : m_store(store) {}

    friend class KFitParamInfo;

};


inline uint KElementInfo::getJtimestwo() const
{
 return (m_store>>24)& 0xFu;
}

inline uint KElementInfo::getRowL() const
{
 return (m_store>>20) & 0xFu;
}

inline uint KElementInfo::getRowStimestwo() const
{
 return (m_store>>16)& 0xFu;
}

inline uint KElementInfo::getRowChannelIndex() const
{
 return (m_store>>12) & 0xFu;
}

inline KIndex KElementInfo::getRow() const
{
 return KIndex((m_store>>12) & 0xFFFu);
}

inline uint KElementInfo::getColumnL() const
{
 return (m_store>>8) & 0xFu;
}

inline uint KElementInfo::getColumnStimestwo() const
{
 return (m_store>>4)& 0xFu;
}

inline uint KElementInfo::getColumnChannelIndex() const
{
 return m_store & 0xFu;
}

inline KIndex KElementInfo::getColumn() const
{
 return KIndex(m_store & 0xFFFu);
}


inline bool KElementInfo::operator==(const KElementInfo& rhs) const
{
 return (m_store==rhs.m_store);
}


inline bool KElementInfo::operator!=(const KElementInfo& rhs) const
{
 return (m_store!=rhs.m_store);
}


inline bool KElementInfo::operator<(const KElementInfo& rhs) const
{
 return (m_store<rhs.m_store);
}


   //  This stores information about a given K-matrix fit parameter.
   //  This class is mainly informational for the end user.
   //    
   //    m_store1: left-most 4 bits encode the type of parameter
   //         0 = term in a polynomial
   //         1 = pole energy
   //         2 = coupling in pole residue
   //
   //    if polynomial: 
   //         - rightmost 28 bits of m_store1 contains "n"
   //               where parameter is coefficient of Ecm^n
   //         - m_store2 contains the m_store of the K-matrix element
   //               the polynomial is associated with
   //
   //    if pole energy:
   //         - m_store2 contains the integer index identifying the pole (14 bits)
   //            and total J times two (14 bits)
   //
   //    if coupling in pole residue
   //         - rightmost 28 bits of m_store1 contain integer index
   //              identify the pole (14 bits) and total J times two (14 bits)
   //         - m_store2 contains m_store of the KIndex associated
   //              with this parameter
   //
   //  Construction by XML input of the form:
   //
   //    <KFitParamInfo>
   //      <PolynomialTerm>
   //         <Power>3</Power>
   //         <KElementInfo>...</KElementInfo>
   //      </PolynomialTerm>
   //    </KFitParamInfo>
   //
   //    <KFitParamInfo>
   //      <PoleEnergy>
   //         <Index>3</Index>
   //         <JTimesTwo>2</JTimesTwo>
   //      </PoleEnergy>
   //    </KFitParamInfo>
   //
   //    <KFitParamInfo>
   //      <PoleCoupling>
   //         <Index>3</Index>
   //         <JTimesTwo>2</JTimesTwo>
   //         <KIndex>...</KIndex>
   //      </PoleCoupling>
   //    </KFitParamInfo>


class KFitParamInfo
{

    uint m_store1;
    uint m_store2;

 public:

    KFitParamInfo();    // default 0,0

    KFitParamInfo(XMLHandler& xmlin);

    KFitParamInfo(const KElementInfo& keleminfo, uint power);

    KFitParamInfo(uint pole_index, uint Jtimestwo);

    KFitParamInfo(const KIndex& kindex, uint pole_index, uint Jtimestwo);

    KFitParamInfo(const KFitParamInfo& in);

    KFitParamInfo& operator=(const KFitParamInfo& in);

    ~KFitParamInfo() {}

    void setPolynomialPower(const KElementInfo& keleminfo, uint power);

    void setPoleEnergy(uint pole_index, uint Jtimestwo);

    void setPoleCoupling(const KIndex& kindex, uint pole_index, uint Jtimestwo);


    bool operator==(const KFitParamInfo& rhs) const;

    bool operator!=(const KFitParamInfo& rhs) const;

    bool operator<(const KFitParamInfo& rhs) const;

    std::string output(int indent=0) const;  // XML output 

    std::string str() const;  // XML output 

    void output(XMLHandler& xmlout) const;  // XML output


 private:

    void set_poly_power(const KElementInfo& keleminfo, uint power);

    void set_pole_energy(uint pole_index, uint Jtimestwo);

    void set_pole_coupling(const KIndex& kindex, uint pole_index, uint Jtimestwo);

};



inline KFitParamInfo::KFitParamInfo()
    : m_store1(0), m_store2(0) 
{}    // default value


inline KFitParamInfo::KFitParamInfo(const KElementInfo& keleminfo, uint power)
{
 set_poly_power(keleminfo,power);
}


inline KFitParamInfo::KFitParamInfo(uint pole_index, uint Jtimestwo)
{
 set_pole_energy(pole_index,Jtimestwo);
}


inline KFitParamInfo::KFitParamInfo(const KIndex& kindex, uint pole_index, uint Jtimestwo)
{
 set_pole_coupling(kindex,pole_index,Jtimestwo);
}


inline KFitParamInfo::KFitParamInfo(const KFitParamInfo& in)
           : m_store1(in.m_store1), m_store2(in.m_store2) 
{}

inline KFitParamInfo& KFitParamInfo::operator=(const KFitParamInfo& in)
{
 m_store1=in.m_store1; 
 m_store2=in.m_store2; 
 return *this;
}


inline void KFitParamInfo::setPolynomialPower(const KElementInfo& keleminfo, uint power)
{
 set_poly_power(keleminfo,power);
}


inline void KFitParamInfo::setPoleEnergy(uint pole_index, uint Jtimestwo)
{
 set_pole_energy(pole_index,Jtimestwo);
}
 

inline void KFitParamInfo::setPoleCoupling(const KIndex& kindex, uint pole_index, 
                                           uint Jtimestwo)
{
 set_pole_coupling(kindex,pole_index,Jtimestwo);
}


inline bool KFitParamInfo::operator==(const KFitParamInfo& rhs) const
{
 return (m_store1==rhs.m_store1)&&(m_store2==rhs.m_store2);
}


inline bool KFitParamInfo::operator!=(const KFitParamInfo& rhs) const
{
 return (m_store1!=rhs.m_store1)||(m_store2!=rhs.m_store2);
}


inline bool KFitParamInfo::operator<(const KFitParamInfo& rhs) const
{
 return (m_store1<rhs.m_store1)
       ||((m_store1==rhs.m_store1)&&(m_store2<rhs.m_store2));
}



  // *************************************************************************


class KtildeMatrixCalculator
{


    // private nested classes


    //  purely virtual base class for fitting forms

   class FitForm
   {
  public:
     FitForm(){}
     virtual ~FitForm(){}
     virtual double evaluate(const std::vector<double>& params, double Ecm) const = 0;
   //  std::string output(int indent=0) const;  // XML output 
  //   std::string str() const;  // XML output 
  //   virtual void output(XMLHandler& xmlout) const = 0;  // XML output
   };

   class Polynomial : public FitForm
   {
  public:                                   // params[m_coef_indices[n]] is coef of Ecm^n
     std::vector<int> m_coef_indices;       // m_coef_indices[n]<0 means coef = 0
     Polynomial(std::vector<int>& power_indices)
       : m_coef_indices(power_indices) {}
     virtual ~Polynomial() {}
     virtual double evaluate(const std::vector<double>& params, double Ecm) const
      {double res=params[m_coef_indices[m_coef_indices.size()-1]];
       for (int k=m_coef_indices.size()-2;k>=0;k--){
          res*=Ecm; int kk=m_coef_indices[k]; if (kk>=0) res+=params[kk];}
       return res;}

  //  virtual void output(XMLHandler& xmlout) const = 0;  // XML output
   };

   class SumOfPoles : public FitForm
   {
  public:              //  params[m_rowg[k]]*params[m_colg[k]]/(Ecm^2-params[m_energy]^2)
     std::vector<uint> m_rowg, m_colg, m_energy;  
     SumOfPoles(std::vector<uint>& rowg, std::vector<uint>& colg, std::vector<uint>& energy)
       : m_rowg(rowg), m_colg(colg), m_energy(energy) {}
     virtual ~SumOfPoles() {}
     virtual double evaluate(const std::vector<double>& params, double Ecm) const
      {double res=0.0;
       for (uint k=0;k<m_energy.size();k++){
          double en=params[m_energy[k]];
          res+=params[m_rowg[k]]*params[m_colg[k]]/(Ecm*Ecm-en*en);}
       return res;}

  //  virtual void output(XMLHandler& xmlout) const = 0;  // XML output
   };



    std::map<KElementInfo,std::list<FitForm*> > m_fit;
    std::vector<KFitParamInfo> m_paraminfo;
    std::map<KFitParamInfo,uint> m_paramindices;

        // prevent copying

    KtildeMatrixCalculator(const KtildeMatrixCalculator& inK);
    KtildeMatrixCalculator& operator=(const KtildeMatrixCalculator& inK);
    KtildeMatrixCalculator();

 public:

    KtildeMatrixCalculator(XMLHandler& xmlin);

    ~KtildeMatrixCalculator();

    uint getNumberOfParameters() const;

    const std::vector<KFitParamInfo>& getFitParameterInfos() const
     {return m_paraminfo;}

    int getParameterIndex(const KFitParamInfo& kinfo) const;  // returns -1 if not found

    std::set<KElementInfo> getElementInfos() const;

    double calculate(uint Jtimestwo, 
                     uint Lp, uint Sptimestwo, uint chanp,
                     uint L, uint Stimestwo, uint chan,
                     const std::vector<double>& kappa_params,
                     double Ecm_over_mref) const;

    bool isZero(uint Jtimestwo, 
                uint Lp, uint Sptimestwo, uint chanp,
                uint L, uint Stimestwo, uint chan) const;

//    std::string output() const;

 private:

       //  these routines below are static so that they can be used by
       //  object of class KtildeInverseCalculator too (so they do not
       //  need to be rewritten for that class)

    static void initialize(std::list<XMLHandler>& xelems, bool allow_polynomial,
                           bool allow_sumofpoles,
                           std::map<KElementInfo,std::list<FitForm*> >& fit,
                           std::vector<KFitParamInfo>& paraminfo,
                           std::map<KFitParamInfo,uint>& paramindices);

    static void initialize_a_fitform(const KElementInfo& kinfo, XMLHandler& xmlin, 
                           bool allow_polynomial, bool allow_sumofpoles,
                           std::map<KElementInfo,std::list<FitForm*> >& fit,
                           std::map<KFitParamInfo,uint>& paramindices);

    friend class KtildeInverseCalculator;

};



  // *************************************************************************



class KtildeInverseCalculator
{

    typedef KtildeMatrixCalculator::FitForm   FitForm;

    std::map<KElementInfo,std::list<FitForm*> > m_fit;
    std::vector<KFitParamInfo> m_paraminfo;
    std::map<KFitParamInfo,uint> m_paramindices;

         // disallow copying

    KtildeInverseCalculator(const KtildeInverseCalculator& inK);
    KtildeInverseCalculator& operator=(const KtildeInverseCalculator& inK);
    KtildeInverseCalculator();  // no default


 public:

    KtildeInverseCalculator(XMLHandler& xmlin);

    ~KtildeInverseCalculator();

    uint getNumberOfParameters() const;

    const std::vector<KFitParamInfo>& getFitParameterInfos() const
     {return m_paraminfo;}

    int getParameterIndex(const KFitParamInfo& kinfo) const;  // returns -1 if not found

    std::set<KElementInfo> getElementInfos() const;

    double calculate(uint Jtimestwo, 
                     uint Lp, uint Sptimestwo, uint chanp,
                     uint L, uint Stimestwo, uint chan,
                     const std::vector<double>& kappa_params,
                     double Ecm_over_mref) const;

    bool isZero(uint Jtimestwo, 
                uint Lp, uint Sptimestwo, uint chanp,
                uint L, uint Stimestwo, uint chan) const;

//    std::string output() const;

};


#endif
