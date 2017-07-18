#ifndef CMFRAME_H
#define CMFRAME_H
#include <vector>
#include <list>
#include <string>
#include <stdexcept>

  // *******************************************************************
  // *                                                                 *
  // *   The class "EcmTransform" handles transformations between      *
  // *   the lab and c-m frames.  The lab frame has total momentum     *
  // *                                                                 *
  // *               P  = (2*Pi/L) * (dx,dy,dz)                        *
  // *                                                                 *
  // *   and energies and masses are expressed in terms of a reference *
  // *   "mref" which is specified as a product with the spatial       *
  // *   length "L" of the lattice:  mref_L.  The masses of particle   *
  // *   1 and 2 as ratios over mref are "m1_over_mref" and            *
  // *   "m2_over_mref".                                               *
  // *                                                                 *
  // *   The relationship between a lab frame energy and a c-m         *
  // *   frame energy is                                               *
  // *                                                                 *
  // *         Ecm/mref = sqrt( (Elab/mref)^2 - P^2/mref^2 )           *
  // *                                                                 *
  // *   For d^2 = dx^2 + dy^2 + dz^2, then                            *
  // *                                                                 *
  // *     P^2/mref^2 = (2*Pi)^2 * d^2 /  ((m1_L+m2_L)/2)^2            *
  // *                                                                 *
  // *   Other useful quantities are  gamma, qcm/mref, u^2, and        *
  // *   svec, defined by                                              *
  // *                                                                 *
  // *        gamma = Elab / Ecm                                       *
  // *                                                                 *
  // *        sqrt(qcm^2+m1^2)+sqrt(qcm^2+m2^2) = Ecm                  *
  // *                                                                 *
  // *        u^2 = qcm^2 * L^2 / (2*Pi)^2                             *
  // *                                                                 *
  // *        svec = (1 + (m1^2-m2^2)/Ecm^2) (dx,dy,dz)                *
  // *                                                                 *
  // *   Note the following minimum values:                            *
  // *                                                                 *
  // *         qcm^2/mref^2 >= -min(m1^2/mref^2, m2^2/mref^2)          *
  // *         Ecm/mref >= sqrt( abs( (m1^2-m2^2) )/mref,              *
  // *         Elab/mref >= sqrt( abs(m1^2-m2^2)/mref^2+P^2/mref^2 )   *
  // *                                                                 *
  // *                                                                 *
  // *   Usage:                                                        *
  // *     int dx=1, dy=2, dz=-3;                                      *
  // *     double m1_over_mref=4.315, m2_over_mref=3.835;              *
  // *     double mref_L=24.0;                                         *
  // *                                                                 *
  // *     EcmTransform ECM(dx,dy,dz,mref_L,m1_over_mref,              *
  // *                      m2_over_mref);                             *
  // *                                                                 *
  // *     cout << "mref*L = "<<ECM.getMrefL()<<endl;                  *
  // *     cout << "m1/mref = "<<ECM.getMass1OverMref()<<endl;         *
  // *     cout << "m2/mref = "<<ECM.getMass2OverMref()<<endl;         *
  // *     cout << "(P/mref)^2 = "<<ECM.getPsqOverMrefsq()<<endl;      *
  // *     vector<int> dvec=ECM.getdvec();                             *
  // *     cout << "dvec = ("<<dvec[0]<<", "<<dvec[1]<<", "            *
  // *                      <<dvec[2]<<")"<<endl;                      *
  // *     cout << "min Elab/mref = "<<ECM.getMinElabOverMref()<<endl; *
  // *     cout << "min Ecm/mref = "<<ECM.getMinEcmOverMref()<<endl;   *
  // *                                                                 *
  // *                                                                 *
  // *******************************************************************


class EcmTransform
{

    int dx,dy,dz;
    double mref_L, m1_over_mref, m2_over_mref;
    double Psq_over_mrefsq;
    double min_Elab_over_mref;
    double min_Ecm_over_mref;
    double min_Qcmsq_over_mrefsq;
    bool equalmasses;

    EcmTransform();

 public:

    EcmTransform(int dxval, int dyval, int dzval, double mref_L_val,
                 double m1_over_mref_val, double m2_over_mref_val);

    EcmTransform(int dxval, int dyval, int dzval, double mref_L_val,
                 double m1_over_mref_val);

    EcmTransform(const EcmTransform& in);

    EcmTransform& operator=(const EcmTransform& in);

    void set(int dxval, int dyval, int dzval, double mref_L_val,
             double m1_over_mref_val, double m2_over_mref_val);

    void set(int dxval, int dyval, int dzval, double mref_L_val,
             double m1_over_mref_val);

    void set(double mref_L_val, double m1_over_mref_val, 
             double m2_over_mref_val);

    void set(double mref_L_val, double m1_over_mref_val);

    double getMrefL() const {return mref_L;}

    double getMass1OverMref() const {return m1_over_mref;}

    double getMass2OverMref() const {return m2_over_mref;}

    double getPsqOverMrefsq() const {return Psq_over_mrefsq;}

    std::vector<int> getdvec() const; 

    double getEcmOverMref(double Elab_over_mref) const;

    double getEcmOverMrefFromQcmsq(double Qcmsq_over_mrefsq) const;

    double getQcmsqOverMrefsq(double Elab_over_mref) const;

    double getQcmsqOverMrefsqFromEcm(double Ecm_over_mref) const;

    double getUsquared(double Elab_over_mref) const;

    double getUsquaredFromQcmsq(double Qcmsq_over_mrefsq) const;

    double getMinElabOverMref() const {return min_Elab_over_mref;}

    double getMinEcmOverMref() const {return min_Ecm_over_mref;}

    double getMinQcmsqOverMrefsq() const {return min_Qcmsq_over_mrefsq;}

    double getElabOverMref(double Ecm_over_mref) const;

    double getGamma(double Elab_over_mref) const;

    std::vector<double> getsvec(double Elab_over_mref) const;

    void getGammaSvecUsq(double Elab_over_mref, double& gam, 
                     std::vector<double>& svec, double& usq) const;

    void getGammaSvecUsqFromEcm(double Ecm_over_mref, double& gam, 
                     std::vector<double>& svec, double& usq) const;

    void getGammaSvecUsqFromQcmsq(double Qcmsq_over_mrefsq, double& gam,
                     std::vector<double>& svec, double& usq) const;

    bool isAtRest() const {return ((dx==0)&&(dy==0)&&(dz==0));}

    bool areEqualMasses() const {return equalmasses;}

    std::list<double> getFreeTwoParticleEnergies(double min_Elab_over_mref, 
                                                 double max_Elab_over_mref) const;


 private:

    void assertlabmin(double Elab_over_mref) const
     {if (Elab_over_mref<min_Elab_over_mref) 
         throw(std::runtime_error("Elab/mref too small"));}

    void assertcmmin(double Ecm_over_mref) const
     {if (Ecm_over_mref<min_Ecm_over_mref)
         throw(std::runtime_error("Ecm/mref too small"));}

    void assertqcmmin(double Qcmsq_over_mrefsq) const
     {if (Qcmsq_over_mrefsq<min_Qcmsq_over_mrefsq)
         throw(std::runtime_error("(Qcm/mref)^2 too small"));}

    double sqr(double x) const {return x*x;}

    void initialize();

    static bool double_near(double first, double second);

};


// ************************************************************************
#endif
