#ifndef RGL_ZETA_H
#define RGL_ZETA_H
#include <vector>
#include <complex>
#include <map>

typedef unsigned int  uint;
typedef std::complex<double> cmplx;


  // ******************************************************************
  // *                                                                *
  // *   This routine evaluates the Rummukainen-Gottlieb-Luescher     *
  // *   (RGL) shifted zeta function.                                 *
  // *                                                                *
  // *       l = orbital angular momentum quantum number l=0,1,2...   *
  // *       m = z-axis projection of orb ang momentum m=0,1,..,l     *
  // *       s = shift vector                                         *
  // *       gam = boost factor from lab to cm frame                  *
  // *       usq = u^2 = (L qstar/(2 Pi))^2 for L^3 spatial lattice   *
  // *                                                                *
  // *   Recall that                                                  *
  // *                                                                *
  // *     Total momentum P = (2 Pi / L) d   d = vector of integers   *
  // *     Energy E evaluated in lab frame from MC simulations        *
  // *     Mass of particle 1 is m1, mass of particle 2 is m2         *
  // *                                                                *
  // *        Estar = sqrt(E^2 - P^2)                                 *
  // *        gam = E / Estar                                         *
  // *        s = (1 + (m1^2-m2^2)/Estar^2) * d                       *
  // *        qstar^2 = Estar^2/4 - (m1^2+m2^2)/2                     *
  // *                   + (m1^2-m2^2)^2/(4 Estar^2)                  *
  // *        u^2 = L^2 qstar^2 / (2 Pi)^2                            *
  // *                                                                *
  // *                                                                *
  // *   Currently, only l <= 12 is supported, and m must be          *
  // *   non-negative.  For negative values, use                      *
  // *        zetaRLG( -m ) = (-1)^m * conj( zetaRLG( m ) )           *
  // *                                                                *
  // ******************************************************************



cmplx zetaRGL(int l, int m, const std::vector<double>& s, 
              double gam, double usq);



double zetaRGL_re(int l, int m, const std::vector<double>& s, 
                  double gam, double usq);

double zetaRGL_im(int l, int m, const std::vector<double>& s, 
                  double gam, double usq);





  // ****************************************************************

    //  The Y_LM polynomials


class YLMpoly
{
   int m_lval, m_mval;
   double m_cf;
   bool m_x3flag;
   int m_pdeg;
   std::vector<double> m_pcf;
   mutable std::vector<double> m_buf;

 public:

   YLMpoly(int lvalue, int mvalue);
   YLMpoly(const YLMpoly& in);
   YLMpoly& operator=(const YLMpoly& in);
   ~YLMpoly(){}

   cmplx value(double x1, double x2, double x3) const;
   double realpart(double x1, double x2, double x3) const;
   double imagpart(double x1, double x2, double x3) const;

 private:

   double polarpoly(double zz, double rr) const;
   cmplx azimuthal(double x1, double x2) const;
   double azimuthal_realpart(double x1, double x2) const;
   double azimuthal_imagpart(double x1, double x2) const;

};


// *************************************************************
// *                                                           *
// *   This class is useful when you need to compute and       *
// *   use several w-zeta functions for different l,m but the  *
// *   SAME svec, gam, usq.  It computes them and stores their *
// *   values in a map so that they are not recomputed over    *
// *   and over again.  If the values of svec, gam, usq are    *
// *   changed, the map is cleared and started over again      *
// *   as calculations are requested.                          *
// *                                                           *
// *   Recall that the w-zeta functions are defined by         *
// *                                                           *
// *                     Re( Zeta[l,m](s,gam,u^2) )            *
// *       wr[l,m] =     --------------------------            *
// *                        gam*Pi^(3/2) u^(l+1)               *
// *                                                           *
// *                     Im( Zeta[l,m](s,gam,u^2) )            *
// *       wi[l,m] =     --------------------------            *
// *                        gam*Pi^(3/2) u^(l+1)               *
// *                                                           *
// *   If u^2>=0, then these functions are real.  If u^2<0,    *
// *   then it may occur that these functions are pure         *
// *   imaginary.                                              *
// *                                                           *
// *************************************************************


class WZetaRGLCalculator
{
    double m_gam, m_usq;
    std::vector<double> m_svec;

    std::map<uint,cmplx> m_wr_lm_values;
    std::map<uint,cmplx> m_wi_lm_values;

       // Prevent copying.

    WZetaRGLCalculator(const WZetaRGLCalculator&);
    WZetaRGLCalculator& operator=(const WZetaRGLCalculator&);


 public:

    WZetaRGLCalculator();

    WZetaRGLCalculator(const std::vector<double>& s, 
                       double gam, double usq);

    ~WZetaRGLCalculator() {}

    void reset(const std::vector<double>& s, 
               double gam, double usq);

    void reset_if_diff(const std::vector<double>& s, 
                       double gam, double usq);

    void clear();

    double getGamma() const {return m_gam;}

    double getUsq() const {return m_usq;}

    std::vector<double> getSVector() const {return m_svec;}

    cmplx& eval_wr_lm(uint l, uint m);

    cmplx& eval_wi_lm(uint l, uint m);


 private:

    uint encode_lm(uint l, uint m) const
     {uint icode=l; icode<<=16; icode|=m;
      return icode;}

    static cmplx uint_power_from_sq(double xsq, uint n);

};

// **************************************************************
#endif
