#include "cmframe.h"
#include <map>
#include <utility>
#include <cmath>
using namespace std;


 // ****************************************************************


EcmTransform::EcmTransform(int dxval, int dyval, int dzval, double mref_L_val,
                           double m1_over_mref_val, double m2_over_mref_val)
             : dx(dxval), dy(dyval), dz(dzval), mref_L(mref_L_val),
               m1_over_mref(m1_over_mref_val), m2_over_mref(m2_over_mref_val),
               equalmasses(fabs(m1_over_mref_val-m2_over_mref_val)<1e-15)
{
 if ((mref_L_val<=0.0)||(m1_over_mref_val<=0.0)||(m2_over_mref_val<=0.0))
    throw(std::invalid_argument("Invalid particle masses"));
 initialize();
}


EcmTransform::EcmTransform(int dxval, int dyval, int dzval, double mref_L_val,
                           double m1_over_mref_val)
             : dx(dxval), dy(dyval), dz(dzval), mref_L(mref_L_val),
               m1_over_mref(m1_over_mref_val), m2_over_mref(m1_over_mref_val),
               equalmasses(true)
{
 if ((mref_L_val<=0.0)||(m1_over_mref_val<=0.0))
    throw(std::invalid_argument("Invalid particle masses"));
 initialize();
}


void EcmTransform::initialize()
{
 const double twopisquared=39.478417604357434476;
 int dsq=dx*dx+dy*dy+dz*dz;
 Psq_over_mrefsq=twopisquared*double(dsq)/(mref_L*mref_L);
 min_Qcmsq_over_mrefsq=-sqr(min(m1_over_mref, m2_over_mref));
 double minEcmsq=abs(m1_over_mref-m2_over_mref)*(m1_over_mref+m2_over_mref);
 min_Ecm_over_mref=sqrt(minEcmsq);
 min_Elab_over_mref=sqrt(minEcmsq+Psq_over_mrefsq);
}


EcmTransform::EcmTransform(const EcmTransform& in)
             : dx(in.dx), dy(in.dy), dz(in.dz), mref_L(in.mref_L),
               m1_over_mref(in.m1_over_mref), m2_over_mref(in.m2_over_mref),
               Psq_over_mrefsq(in.Psq_over_mrefsq),
               min_Elab_over_mref(in.min_Elab_over_mref),
               min_Ecm_over_mref(in.min_Ecm_over_mref),
               min_Qcmsq_over_mrefsq(in.min_Qcmsq_over_mrefsq),
               equalmasses(in.equalmasses)
{}


EcmTransform& EcmTransform::operator=(const EcmTransform& in)
{
 dx=in.dx;
 dy=in.dy; 
 dz=in.dz;
 mref_L=in.mref_L;
 m1_over_mref=in.m1_over_mref; 
 m2_over_mref=in.m2_over_mref;
 Psq_over_mrefsq=in.Psq_over_mrefsq;
 min_Elab_over_mref=in.min_Elab_over_mref;
 min_Ecm_over_mref=in.min_Ecm_over_mref;
 min_Qcmsq_over_mrefsq=in.min_Qcmsq_over_mrefsq;
 equalmasses=in.equalmasses;
 return *this;
}


void EcmTransform::set(int dxval, int dyval, int dzval, double mref_L_val,
                       double m1_over_mref_val, double m2_over_mref_val)
{
 if ((mref_L_val<=0.0)||(m1_over_mref_val<=0.0)||(m2_over_mref_val<=0.0))
    throw(std::invalid_argument("Invalid particle masses"));
 dx=dxval;
 dy=dyval; 
 dz=dzval;
 mref_L=mref_L_val;
 m1_over_mref=m1_over_mref_val; 
 m2_over_mref=m2_over_mref_val;
 equalmasses=(fabs(m1_over_mref_val-m2_over_mref_val)<1e-15);
 initialize();
}


void EcmTransform::set(int dxval, int dyval, int dzval, double mref_L_val,
                       double m1_over_mref_val)
{
 if ((mref_L_val<=0.0)||(m1_over_mref_val<=0.0))
    throw(std::invalid_argument("Invalid particle masses"));
 dx=dxval;
 dy=dyval; 
 dz=dzval;
 mref_L=mref_L_val;
 m1_over_mref=m1_over_mref_val; 
 m2_over_mref=m1_over_mref_val;
 equalmasses=true;
 initialize();
}


void EcmTransform::set(double mref_L_val, double m1_over_mref_val, 
                       double m2_over_mref_val)
{
 if ((mref_L_val<=0.0)||(m1_over_mref_val<=0.0)||(m2_over_mref_val<=0.0))
    throw(std::invalid_argument("Invalid particle masses"));
 mref_L=mref_L_val;
 m1_over_mref=m1_over_mref_val; 
 m2_over_mref=m2_over_mref_val;
 equalmasses=(fabs(m1_over_mref_val-m2_over_mref_val)<1e-15);
 initialize();
}



void EcmTransform::set(double mref_L_val, double m1_over_mref_val)
{
 if ((mref_L_val<=0.0)||(m1_over_mref_val<=0.0))
    throw(std::invalid_argument("Invalid particle masses"));
 mref_L=mref_L_val;
 m1_over_mref=m1_over_mref_val; 
 m2_over_mref=m1_over_mref_val;
 equalmasses=true;
 initialize();
}


vector<int> EcmTransform::getdvec() const
{
 vector<int> dv(3); 
 dv[0]=dx; dv[1]=dy; dv[2]=dz;
 return dv;
}

double EcmTransform::getEcmOverMref(double Elab_over_mref) const
{
 assertlabmin(Elab_over_mref); 
 return sqrt(Elab_over_mref*Elab_over_mref-Psq_over_mrefsq);
}


double EcmTransform::getEcmOverMrefFromQcmsq(double Qcmsq_over_mrefsq) const
{
 assertqcmmin(Qcmsq_over_mrefsq);
 return sqrt(Qcmsq_over_mrefsq+sqr(m1_over_mref))
       +sqrt(Qcmsq_over_mrefsq+sqr(m2_over_mref));
}
 

double EcmTransform::getQcmsqOverMrefsq(double Elab_over_mref) const
{
 assertlabmin(Elab_over_mref); 
 double Ecmsq=Elab_over_mref*Elab_over_mref-Psq_over_mrefsq;
 double mm1=m1_over_mref*m1_over_mref;
 double mm2=m2_over_mref*m2_over_mref;
 return 0.25*Ecmsq-0.5*(mm1+mm2)+0.25*sqr(mm1-mm2)/Ecmsq;
}


double EcmTransform::getQcmsqOverMrefsqFromEcm(double Ecm_over_mref) const
{
 assertcmmin(Ecm_over_mref); 
 double Ecmsq=Ecm_over_mref*Ecm_over_mref;
 double mm1=m1_over_mref*m1_over_mref;
 double mm2=m2_over_mref*m2_over_mref;
 return 0.25*Ecmsq-0.5*(mm1+mm2)+0.25*sqr(mm1-mm2)/Ecmsq;
}


double EcmTransform::getUsquared(double Elab_over_mref) const
{
 const double invtwopisquared=0.025330295910584442860;
 assertlabmin(Elab_over_mref); 
 double Ecmsq=Elab_over_mref*Elab_over_mref-Psq_over_mrefsq;
 double mm1=m1_over_mref*m1_over_mref;
 double mm2=m2_over_mref*m2_over_mref;
 double qcmsq=0.25*Ecmsq-0.5*(mm1+mm2)+0.25*sqr(mm1-mm2)/Ecmsq;
 return qcmsq*mref_L*mref_L*invtwopisquared;
}


double EcmTransform::getUsquaredFromQcmsq(double Qcmsq_over_mrefsq) const
{
 const double invtwopisquared=0.025330295910584442860;
 assertqcmmin(Qcmsq_over_mrefsq);
 return Qcmsq_over_mrefsq*mref_L*mref_L*invtwopisquared;
}


double EcmTransform::getElabOverMref(double Ecm_over_mref) const
{
 assertcmmin(Ecm_over_mref); 
 return sqrt(Ecm_over_mref*Ecm_over_mref+Psq_over_mrefsq);
}


double EcmTransform::getGamma(double Elab_over_mref) const
{
 assertlabmin(Elab_over_mref); 
 return 1.0/sqrt(1.0-Psq_over_mrefsq/(Elab_over_mref*Elab_over_mref));
}


vector<double> EcmTransform::getsvec(double Elab_over_mref) const
{
 assertlabmin(Elab_over_mref); 
 double Ecmsq=Elab_over_mref*Elab_over_mref-Psq_over_mrefsq;
 double mm1=m1_over_mref*m1_over_mref;
 double mm2=m2_over_mref*m2_over_mref;
 double sc=1.0+(mm1-mm2)/Ecmsq;
 vector<double> svec(3);
 svec[0]=sc*dx; svec[1]=sc*dy; svec[2]=sc*dz;
 return svec;
}


void EcmTransform::getGammaSvecUsq(double Elab_over_mref,
         double& gam, vector<double>& svec, double& usq) const
{
 assertlabmin(Elab_over_mref); 
 const double invtwopisquared=0.025330295910584442860;
 double Ecmsq=Elab_over_mref*Elab_over_mref-Psq_over_mrefsq;
 double mm1=m1_over_mref*m1_over_mref;
 double mm2=m2_over_mref*m2_over_mref;
 double sc=1.0+(mm1-mm2)/Ecmsq;
 svec.resize(3);
 svec[0]=sc*dx; svec[1]=sc*dy; svec[2]=sc*dz;
 double qcmsq=0.25*Ecmsq-0.5*(mm1+mm2)+0.25*sqr(mm1-mm2)/Ecmsq;
 usq=qcmsq*mref_L*mref_L*invtwopisquared;
 gam=Elab_over_mref/sqrt(Ecmsq);
}



void EcmTransform::getGammaSvecUsqFromEcm(double Ecm_over_mref,
         double& gam, vector<double>& svec, double& usq) const
{
 assertcmmin(Ecm_over_mref); 
 const double invtwopisquared=0.025330295910584442860;
 double Ecmsq=Ecm_over_mref*Ecm_over_mref;
 double mm1=m1_over_mref*m1_over_mref;
 double mm2=m2_over_mref*m2_over_mref;
 double sc=1.0+(mm1-mm2)/Ecmsq;
 svec.resize(3);
 svec[0]=sc*dx; svec[1]=sc*dy; svec[2]=sc*dz;
 double qcmsq=0.25*Ecmsq-0.5*(mm1+mm2)+0.25*sqr(mm1-mm2)/Ecmsq;
 usq=qcmsq*mref_L*mref_L*invtwopisquared;
 gam=sqrt((Ecmsq+Psq_over_mrefsq)/Ecmsq);
}



void EcmTransform::getGammaSvecUsqFromQcmsq(double Qcmsq_over_mrefsq,
         double& gam, vector<double>& svec, double& usq) const
{
 assertqcmmin(Qcmsq_over_mrefsq);
 const double invtwopisquared=0.025330295910584442860;
 double mm1=m1_over_mref*m1_over_mref;
 double mm2=m2_over_mref*m2_over_mref;
 double Ecm=sqrt(Qcmsq_over_mrefsq+mm1)
           +sqrt(Qcmsq_over_mrefsq+mm2);
 double Ecmsq=Ecm*Ecm;
 double sc=1.0+(mm1-mm2)/Ecmsq;
 svec.resize(3);
 svec[0]=sc*dx; svec[1]=sc*dy; svec[2]=sc*dz;
 usq=Qcmsq_over_mrefsq*mref_L*mref_L*invtwopisquared;
 gam=sqrt(Ecmsq+Psq_over_mrefsq)/Ecm;
}



bool EcmTransform::double_near(double first, double second)
{ return (fabs(first-second)<1e-12); }


list<double> EcmTransform::getFreeTwoParticleEnergies(double min_Elab_over_mref, 
                                                      double max_Elab_over_mref) const
{
 double mm1=m1_over_mref; mm1*=mm1;
 double mm2=m2_over_mref; mm2*=mm2;
 double pfac=6.2831853071795864770/mref_L; pfac*=pfac;
 double eps=1e-12;
 double Emin=min_Elab_over_mref-eps;
 double Emax=max_Elab_over_mref+eps;
 map<pair<int,int>,double> Efreemap;
 map<pair<int,int>,double>::iterator it;

 pair<int,int> zp;
 double Epole;
 int nmax=int(ceil(max_Elab_over_mref/sqrt(pfac))); 
 for (int nx=-nmax;nx<=nmax;nx++){
  int n1xsq=nx*nx; int n2xsq=dx-nx; n2xsq*=n2xsq; 
  for (int ny=-nmax;ny<=nmax;ny++){
   int n1xysq=n1xsq+ny*ny; int n2xysq=dy-ny; n2xysq*=n2xysq; n2xysq+=n2xsq; 
   for (int nz=-nmax;nz<=nmax;nz++){
    zp.first=n1xysq+nz*nz; int n2zz=dz-nz; zp.second=n2zz*n2zz+n2xysq;
    if ((equalmasses)&&(zp.first>zp.second)){
       unsigned int tmp=zp.first; zp.first=zp.second; zp.second=tmp;}
    it=Efreemap.find(zp);
    if (it==Efreemap.end()){  // not yet in map
       Epole=sqrt(pfac*double(zp.first)+mm1)+sqrt(pfac*double(zp.second)+mm2);
       if ((Epole>=Emin)&&(Epole<=Emax)){
          Efreemap.insert(make_pair(zp,Epole));}}}}}

 list<double> Efree;
 for (it=Efreemap.begin();it!=Efreemap.end();it++)
    Efree.push_back(it->second);
 Efree.sort();
 Efree.unique(double_near);
 return Efree;
}


// ******************************************************************
