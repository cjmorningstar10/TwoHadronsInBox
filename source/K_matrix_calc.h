#ifndef K_MATRIX_CALC_H
#define K_MATRIX_CALC_H

#include "xml_handler.h"
#include "fit_forms.h"
#include "K_matrix_info.h"
#include "K_matrix_base.h"
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
// *   Alternatively, an object of one of these classes can be           *
// *   constructed via                                                   *
// *                                                                     *
// *   list<pair<KElementInfo,Polynomial> > pelems;                      *
// *   list<pair<KElementInfo,SumOfPoles> > selems;                      *
// *   list<pair<KElementInfo,SumOfPolesPlusPolynomial> > spelems;       *
// *   KtildeMatrixCalculator KC(pelems,selemn,spelems);                 *
// *                                                                     *
// ***********************************************************************



class KtildeMatrixCalculator : public KtildeMatrixBase
{

    std::map<KElementInfo,FitForm*> m_fit;
    std::vector<KFitParamInfo> m_paraminfo;
    std::map<KFitParamInfo,uint> m_paramindices;
    std::vector<double> m_kappa_params;

        // prevent copying, no default

    KtildeMatrixCalculator(const KtildeMatrixCalculator& inK);
    KtildeMatrixCalculator& operator=(const KtildeMatrixCalculator& inK);
    KtildeMatrixCalculator();

 public:

    KtildeMatrixCalculator(XMLHandler& xmlin);

    KtildeMatrixCalculator(const std::list<std::pair<KElementInfo,Polynomial> >& pelems,
                           const std::list<std::pair<KElementInfo,SumOfPoles> >& selems,
                           const std::list<std::pair<KElementInfo,SumOfPolesPlusPolynomial> >& spelems);

    ~KtildeMatrixCalculator();

    uint getNumberOfParameters() const;

    const std::vector<KFitParamInfo>& getFitParameterInfos() const
     {return m_paraminfo;}

    int getParameterIndex(const KFitParamInfo& kinfo) const;  // returns -1 if not found

    std::set<KElementInfo> getElementInfos() const;

    std::string output(int indent=0) const;  // XML output 

    std::string str() const;  // XML output 

    void output(XMLHandler& xmlout) const;  // XML output


    void setKtildeParameters(const std::vector<double>& kappa_params);

    double calculate(uint Jtimestwo, 
                     uint Lp, uint Sptimestwo, uint chanp,
                     uint L, uint Stimestwo, uint chan,
                     double Ecm_over_mref) const;

    bool isZero(uint Jtimestwo, 
                uint Lp, uint Sptimestwo, uint chanp,
                uint L, uint Stimestwo, uint chan) const;


 private:

    void initialize(std::list<XMLHandler>& xelems);

    void initialize_a_fitform(const KElementInfo& kinfo, XMLHandler& xmlin);

    friend class KtildeInverseCalculator;

};



  // *************************************************************************



class KtildeInverseCalculator : public KtildeMatrixBase
{

    std::map<KElementInfo,FitForm*> m_fit;
    std::vector<KFitParamInfo> m_paraminfo;
    std::map<KFitParamInfo,uint> m_paramindices;
    std::vector<double> m_kappa_params;

         // disallow copying, no default

    KtildeInverseCalculator(const KtildeInverseCalculator& inK);
    KtildeInverseCalculator& operator=(const KtildeInverseCalculator& inK);
    KtildeInverseCalculator();


 public:

    KtildeInverseCalculator(XMLHandler& xmlin);

    KtildeInverseCalculator(const std::list<std::pair<KElementInfo,Polynomial> >& polyelems);

    ~KtildeInverseCalculator();

    uint getNumberOfParameters() const;

    const std::vector<KFitParamInfo>& getFitParameterInfos() const
     {return m_paraminfo;}

    int getParameterIndex(const KFitParamInfo& kinfo) const;  // returns -1 if not found

    std::set<KElementInfo> getElementInfos() const;

    std::string output(int indent=0) const;  // XML output 

    std::string str() const;  // XML output 

    void output(XMLHandler& xmlout) const;  // XML output


    void setKtildeParameters(const std::vector<double>& kappa_params);

    double calculate(uint Jtimestwo, 
                     uint Lp, uint Sptimestwo, uint chanp,
                     uint L, uint Stimestwo, uint chan,
                     double Ecm_over_mref) const;

    bool isZero(uint Jtimestwo, 
                uint Lp, uint Sptimestwo, uint chanp,
                uint L, uint Stimestwo, uint chan) const;


 private:

    void initialize(std::list<XMLHandler>& xelems);

    void initialize_a_fitform(const KElementInfo& kinfo, XMLHandler& xmlin);
};


#endif
