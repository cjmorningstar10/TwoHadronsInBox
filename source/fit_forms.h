#ifndef FIT_FORMS_H
#define FIT_FORMS_H

#include "xml_handler.h"
#include "K_matrix_info.h"
#include <map>

// ***********************************************************************
// *                                                                     *
// *   This file contains classes that describe the various fit forms    *
// *   available for the elements of the Ktilde matrix and its inverse.  *
// *   Each fit form class is derived from a base class "FitForm".       *
// *                                                                     *
// ***********************************************************************


    //  "FitForm" is a mostly virtual base class for fitting forms.
    //  The two key public members are "evaluate" and "output".
    //  Given a vector of real parameters and an Ecm, the
    //  "evaluate" function should return a real number.
    //  Derived classes store information about the indices
    //  of the parameters needed in the parameter vector and
    //  how to evaluate the fit function.
    //
    //  The key private class is "Kinitialize" which can only
    //  be called by an object of the class "KtildeMatrixCalculator"
    //  or "KtildeInverseCalculator".  The routine actually
    //  does the work of associating the parameters needed for
    //  this fit form with the indices in the parameter vector.


class FitForm
{
 public:

    FitForm(){}
    virtual ~FitForm(){}
    virtual double evaluate(const std::vector<double>& params, double Ecm) const = 0;
    std::string output(int indent=0) const;  // XML output 
    std::string str() const;  // XML output 
    virtual void output(XMLHandler& xmlout) const = 0;  // XML output

 private:

    virtual void Kinitialize(const KElementInfo& kelem,
                             std::map<KFitParamInfo,uint>& paramindices) = 0;
    friend class KtildeMatrixCalculator;
    friend class KtildeInverseCalculator;

};



    //  The class "Polynomial" describes a polynomial in powers of Ecm.
    //  An object of this class can be constructed in the following ways:
    //
    //   -- by specifying the degree of the power
    //   -- by a set of specific powers to use
    //   -- by XML of the form:
    //         <Polynomial>          or   <Polynomial>
    //           <Degree>3</Degree>         <Powers>0 2</Powers>
    //         </Polynomial>              </Polynomial>
    //
    //  Implementation:
    //    -- powers are stored in the set "m_powers"
    //    -- params[m_coef_indices[n]] is coef of Ecm^n
    //    -- m_coef_indices[n]<0 means coef = 0 for the power n


class Polynomial : public FitForm
{
    std::set<uint> m_powers;
    std::vector<int> m_coef_indices;  // set by K matrix

 public:

    Polynomial();
    Polynomial(uint degree);
    Polynomial(const std::set<uint>& powers);
    Polynomial(XMLHandler& xmlin);
    Polynomial(const Polynomial& in);
    Polynomial& operator=(const Polynomial& in);
    virtual ~Polynomial() {}
    virtual double evaluate(const std::vector<double>& params, double Ecm) const;
    virtual void output(XMLHandler& xmlout) const;  // XML output
    using FitForm::output;

 private:

    void initialize(XMLHandler& xmlin);
    virtual void Kinitialize(const KElementInfo& kelem,
                             std::map<KFitParamInfo,uint>& paramindices);
    friend class KtildeMatrixCalculator;
    friend class KtildeInverseCalculator;
    friend class SumOfPolesPlusPolynomial;
};



inline Polynomial::Polynomial()
{
 m_powers.insert(0);
}


inline Polynomial::Polynomial(const Polynomial& in)
   : m_powers(in.m_powers), m_coef_indices(in.m_coef_indices)
{}


inline Polynomial& Polynomial::operator=(const Polynomial& in)
{
 m_powers=in.m_powers;
 m_coef_indices=in.m_coef_indices;
 return *this;
}


inline double Polynomial::evaluate(const std::vector<double>& params, double Ecm) const
{
 double res=params[m_coef_indices[m_coef_indices.size()-1]];
 for (int k=m_coef_indices.size()-2;k>=0;k--){
    res*=Ecm; 
    int kk=m_coef_indices[k]; 
    if (kk>=0) res+=params[kk];}
 return res;
}


    //  The class "SumOfPoles" describes a fit function of the form
    //
    //                    rowg[p] * colg[p]
    //             sum_p -------------------
    //                   (Ecm^2 - pole[p]^2)
    //
    //  An object of this class can be constructed in the following ways:
    //
    //   -- by specifying the number of poles
    //   -- by a set of pole indices to use
    //   -- by XML of the form:
    //         <SumOfPoles>                     
    //           <NumberOfPoles>2</NumberOfPoles
    //         </SumOfPoles>                    
    //               (includes all pole indices 0,1,...Number-1)
    //     or
    //         <SumOfPoles>
    //           <PoleIndices>0 2</PoleIndices>
    //         </SumOfPoles>
    //
    //  Implementation:
    //    -- pole indices are stored in the set "m_poleindices"
    //    -- evaluated using
    //         params[m_rowg[k]]*params[m_colg[k]]
    //               /(Ecm^2-params[m_poles[k]]^2)
   

class SumOfPoles : public FitForm
{
    std::set<uint> m_poleindices;
    std::vector<uint> m_rowg, m_colg, m_poles;  

 public:

    SumOfPoles();
    SumOfPoles(uint numpoles);
    SumOfPoles(const std::set<uint>& poleindices);
    SumOfPoles(XMLHandler& xmlin);
    SumOfPoles(const SumOfPoles& in);
    SumOfPoles& operator=(const SumOfPoles& in);
    virtual ~SumOfPoles() {}
    virtual double evaluate(const std::vector<double>& params, double Ecm) const;
    virtual void output(XMLHandler& xmlout) const;  // XML output
    using FitForm::output;

 private:

    void initialize(XMLHandler& xmlin);
    virtual void Kinitialize(const KElementInfo& kelem,
                             std::map<KFitParamInfo,uint>& paramindices);
    friend class KtildeMatrixCalculator;
    friend class KtildeInverseCalculator;
    friend class SumOfPolesPlusPolynomial;
};



inline SumOfPoles::SumOfPoles()
{
 m_poleindices.insert(0);
}


inline SumOfPoles::SumOfPoles(const SumOfPoles& in)
   : m_poleindices(in.m_poleindices), m_rowg(in.m_rowg),
     m_colg(in.m_colg), m_poles(in.m_poles) 
{}


inline SumOfPoles& SumOfPoles::operator=(const SumOfPoles& in)
{
 m_poleindices=in.m_poleindices;
 m_rowg=in.m_rowg;
 m_colg=in.m_colg;
 m_poles=in.m_poles;
 return *this;
}


inline double SumOfPoles::evaluate(const std::vector<double>& params, double Ecm) const
{
 double res=0.0;
 for (uint k=0;k<m_poles.size();k++){
    double en=params[m_poles[k]];
    res+=params[m_rowg[k]]*params[m_colg[k]]/(Ecm*Ecm-en*en);}
 return res;
}




    //  The class "SumOfPolesPlusPolynomial" describes a fit function 
    //  that is a sum of a polynomial background plus a sum of poles.

    //  XML input:
    //
    //       <SumOfPolesPlusPolynomial>
    //         <SumOfPoles>...</SumOfPoles>
    //         <Polynomial>...</Polynomial>
    //       </SumOfPolesPlusPolynomial>


class SumOfPolesPlusPolynomial : public FitForm
{
    SumOfPoles m_sumpoles;
    Polynomial m_poly;

 public:

    SumOfPolesPlusPolynomial(){}
    SumOfPolesPlusPolynomial(const SumOfPoles& sumpoles, const Polynomial& poly);
    SumOfPolesPlusPolynomial(XMLHandler& xmlin);
    SumOfPolesPlusPolynomial(const SumOfPolesPlusPolynomial& in);
    SumOfPolesPlusPolynomial& operator=(const SumOfPolesPlusPolynomial& in);
    virtual ~SumOfPolesPlusPolynomial() {}
    virtual double evaluate(const std::vector<double>& params, double Ecm) const;
    virtual void output(XMLHandler& xmlout) const;  // XML output
    using FitForm::output;

 private:

    virtual void Kinitialize(const KElementInfo& kelem,
                             std::map<KFitParamInfo,uint>& paramindices);
    friend class KtildeMatrixCalculator;
    friend class KtildeInverseCalculator;
};


inline SumOfPolesPlusPolynomial::SumOfPolesPlusPolynomial(const SumOfPoles& sumpoles, 
                                                          const Polynomial& poly)
    : m_sumpoles(sumpoles), m_poly(poly)
{}


inline SumOfPolesPlusPolynomial::SumOfPolesPlusPolynomial(const SumOfPolesPlusPolynomial& in)
   : m_sumpoles(in.m_sumpoles), m_poly(in.m_poly)
{}


inline SumOfPolesPlusPolynomial& SumOfPolesPlusPolynomial::operator=(const SumOfPolesPlusPolynomial& in)
{
 m_sumpoles=in.m_sumpoles;
 m_poly=in.m_poly;
 return *this;
}


inline double SumOfPolesPlusPolynomial::evaluate(const std::vector<double>& params, double Ecm) const
{
 return m_sumpoles.evaluate(params,Ecm)
       +m_poly.evaluate(params,Ecm);
}


#endif
