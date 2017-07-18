#include "zeta.h"
#include <stdexcept>
using namespace std;



// ***********************************************************


YLMpoly::YLMpoly(const YLMpoly& in) :  m_lval(in.m_lval),
      m_mval(in.m_mval), m_cf(in.m_cf), m_x3flag(in.m_x3flag),
      m_pdeg(in.m_pdeg), m_pcf(in.m_pcf),
      m_buf(in.m_buf)
{}

YLMpoly& YLMpoly::operator=(const YLMpoly& in)
{
 m_lval=in.m_lval;
 m_mval=in.m_mval;
 m_cf=in.m_cf;
 m_x3flag=in.m_x3flag;
 m_pdeg=in.m_pdeg;
 m_pcf=in.m_pcf;
 m_buf=in.m_buf;
 return *this;
}


   //   constructor

YLMpoly::YLMpoly(int lvalue, int mvalue)
{
 if ((lvalue<0)||(lvalue>12)){
    throw(std::invalid_argument("Unsupported value of L in YLMpoly"));}
 if ((mvalue<0)||(mvalue>lvalue)){
    throw(std::invalid_argument("Unsupported or invalid value of M in YLMpoly"));}
 m_lval=lvalue;
 m_mval=mvalue;
 m_pdeg=(lvalue-mvalue)/2;
 m_pcf.resize(m_pdeg+1);
 m_buf.resize(m_pdeg+1);
 m_x3flag=(m_lval-m_mval)>(2*m_pdeg);

 if (m_lval==1){
  if (m_mval==0){
     m_cf=  0.48860251190291992159;
     m_pcf[0]=1.0;}
  else if (m_mval==1){
     m_cf= -0.34549414947133547927;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==2){
  if (m_mval==0){
     m_cf=  0.31539156525252000603;
     m_pcf[0]=-1.0;
     m_pcf[1]=3.0;}
  else if (m_mval==1){
     m_cf= -0.77254840404637916068;
     m_pcf[0]=1.0;}
  else if (m_mval==2){
     m_cf=  0.38627420202318958034;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==3){
  if (m_mval==0){
     m_cf=  0.37317633259011539141;
     m_pcf[0]=-3.0;
     m_pcf[1]=5.0;}
  else if (m_mval==1){
     m_cf= -0.32318018411415065301;
     m_pcf[0]=-1.0;
     m_pcf[1]=5.0;}
  else if (m_mval==2){
     m_cf=  1.02198547643328236340;
     m_pcf[0]=1.0;}
  else if (m_mval==3){
     m_cf= -0.41722382363278408972;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==4){
  if (m_mval==0){
     m_cf=  0.10578554691520430380;
     m_pcf[0]=3.0;
     m_pcf[1]=-30.0;
     m_pcf[2]=35.0;}
  else if (m_mval==1){
     m_cf= -0.47308734787878000905;
     m_pcf[0]=-3.0;
     m_pcf[1]=7.0;}
  else if (m_mval==2){
     m_cf=  0.33452327177864458398;
     m_pcf[0]=-1.0;
     m_pcf[1]=7.0;}
  else if (m_mval==3){
     m_cf= -1.25167147089835226917;
     m_pcf[0]=1.0;}
  else if (m_mval==4){
     m_cf=  0.44253269244498263276;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==5){
  if (m_mval==0){
     m_cf=  0.11695032245342359644;
     m_pcf[0]=15.0;
     m_pcf[1]=-70.0;
     m_pcf[2]=63.0;}
  else if (m_mval==1){
     m_cf= -0.32028164857621512754;
     m_pcf[0]=1.0;
     m_pcf[1]=-14.0;
     m_pcf[2]=21.0;}
  else if (m_mval==2){
     m_cf=  1.69477118326089927582;
     m_pcf[0]=-1.0;
     m_pcf[1]=3.0;}
  else if (m_mval==3){
     m_cf= -0.34594371914684021317;
     m_pcf[0]=-1.0;
     m_pcf[1]=9.0;}
  else if (m_mval==4){
     m_cf=  1.46771489830575116305;
     m_pcf[0]=1.0;}
  else if (m_mval==5){
     m_cf= -0.46413220344085816066;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==6){
  if (m_mval==0){
     m_cf=  0.06356920226762842593;
     m_pcf[0]=-5.0;
     m_pcf[1]=105.0;
     m_pcf[2]=-315.0;
     m_pcf[3]=231.0;}
  else if (m_mval==1){
     m_cf= -0.41197551630114077740;
     m_pcf[0]=5.0;
     m_pcf[1]=-30.0;
     m_pcf[2]=33.0;}
  else if (m_mval==2){
     m_cf=  0.32569524293385786878;
     m_pcf[0]=1.0;
     m_pcf[1]=-18.0;
     m_pcf[2]=33.0;}
  else if (m_mval==3){
     m_cf= -0.65139048586771573757;
     m_pcf[0]=-3.0;
     m_pcf[1]=11.0;}
  else if (m_mval==4){
     m_cf=  0.35678126285399802762;
     m_pcf[0]=-1.0;
     m_pcf[1]=11.0;}
  else if (m_mval==5){
     m_cf= -1.67345245810009790124;
     m_pcf[0]=1.0;}
  else if (m_mval==6){
     m_cf=  0.48308411358006622697;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==7){
  if (m_mval==0){
     m_cf=  0.06828427691200494191;
     m_pcf[0]=-35.0;
     m_pcf[1]=315.0;
     m_pcf[2]=-693.0;
     m_pcf[3]=429.0;}
  else if (m_mval==1){
     m_cf= -0.06387409227708014771;
     m_pcf[0]=-5.0;
     m_pcf[1]=135.0;
     m_pcf[2]=-495.0;
     m_pcf[3]=429.0;}
  else if (m_mval==2){
     m_cf=  0.15645893386229403365;
     m_pcf[0]=15.0;
     m_pcf[1]=-110.0;
     m_pcf[2]=143.0;}
  else if (m_mval==3){
     m_cf= -0.11063317311124565819;
     m_pcf[0]=3.0;
     m_pcf[1]=-66.0;
     m_pcf[2]=143.0;}
  else if (m_mval==4){
     m_cf=  0.73385744915287558153;
     m_pcf[0]=-3.0;
     m_pcf[1]=13.0;}
  else if (m_mval==5){
     m_cf= -0.36692872457643779076;
     m_pcf[0]=-1.0;
     m_pcf[1]=13.0;}
  else if (m_mval==6){
     m_cf=  1.87097672671296873676;
     m_pcf[0]=1.0;}
  else if (m_mval==7){
     m_cf= -0.50003956357055066401;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==8){
  if (m_mval==0){
     m_cf=  0.00908677049156499629;
     m_pcf[0]=35.0;
     m_pcf[1]=-1260.0;
     m_pcf[2]=6930.0;
     m_pcf[3]=-12012.0;
     m_pcf[4]=6435.0;}
  else if (m_mval==1){
     m_cf= -0.07710380440405712066;
     m_pcf[0]=-35.0;
     m_pcf[1]=385.0;
     m_pcf[2]=-1001.0;
     m_pcf[3]=715.0;}
  else if (m_mval==2){
     m_cf=  0.32254835519288300832;
     m_pcf[0]=-1.0;
     m_pcf[1]=33.0;
     m_pcf[2]=-143.0;
     m_pcf[3]=143.0;}
  else if (m_mval==3){
     m_cf= -0.87346507497971411844;
     m_pcf[0]=3.0;
     m_pcf[1]=-26.0;
     m_pcf[2]=39.0;}
  else if (m_mval==4){
     m_cf=  0.33829156888902454737;
     m_pcf[0]=1.0;
     m_pcf[1]=-26.0;
     m_pcf[2]=65.0;}
  else if (m_mval==5){
     m_cf= -2.43945519537307291241;
     m_pcf[0]=-1.0;
     m_pcf[1]=5.0;}
  else if (m_mval==6){
     m_cf=  0.37641610872849456372;
     m_pcf[0]=-1.0;
     m_pcf[1]=15.0;}
  else if (m_mval==7){
     m_cf= -2.06171593758913723890;
     m_pcf[0]=1.0;}
  else if (m_mval==8){
     m_cf=  0.51542898439728430973;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==9){
  if (m_mval==0){
     m_cf=  0.00960642726438659162;
     m_pcf[0]=315.0;
     m_pcf[1]=-4620.0;
     m_pcf[2]=18018.0;
     m_pcf[3]=-25740.0;
     m_pcf[4]=12155.0;}
  else if (m_mval==1){
     m_cf= -0.04556728549830323415;
     m_pcf[0]=7.0;
     m_pcf[1]=-308.0;
     m_pcf[2]=2002.0;
     m_pcf[3]=-4004.0;
     m_pcf[4]=2431.0;}
  else if (m_mval==2){
     m_cf=  0.42745902806723021361;
     m_pcf[0]=-7.0;
     m_pcf[1]=91.0;
     m_pcf[2]=-273.0;
     m_pcf[3]=221.0;}
  else if (m_mval==3){
     m_cf= -0.32647722543505590250;
     m_pcf[0]=-1.0;
     m_pcf[1]=39.0;
     m_pcf[2]=-195.0;
     m_pcf[3]=221.0;}
  else if (m_mval==4){
     m_cf=  2.88336878334462107576;
     m_pcf[0]=1.0;
     m_pcf[1]=-10.0;
     m_pcf[2]=17.0;}
  else if (m_mval==5){
     m_cf= -0.34462848611151939988;
     m_pcf[0]=1.0;
     m_pcf[1]=-30.0;
     m_pcf[2]=85.0;}
  else if (m_mval==6){
     m_cf=  0.88982692489239246776;
     m_pcf[0]=-3.0;
     m_pcf[1]=17.0;}
  else if (m_mval==7){
     m_cf= -0.38530636096409977367;
     m_pcf[0]=-1.0;
     m_pcf[1]=17.0;}
  else if (m_mval==8){
     m_cf=  2.24670285555956488965;
     m_pcf[0]=1.0;}
  else if (m_mval==9){
     m_cf= -0.52955294149244957955;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==10){
  if (m_mval==0){
     m_cf=  0.00504969037678360395;
     m_pcf[0]=-63.0;
     m_pcf[1]=3465.0;
     m_pcf[2]=-30030.0;
     m_pcf[3]=90090.0;
     m_pcf[4]=-109395.0;
     m_pcf[5]=46189.0;}
  else if (m_mval==1){
     m_cf= -0.05296159947690310237;
     m_pcf[0]=63.0;
     m_pcf[1]=-1092.0;
     m_pcf[2]=4914.0;
     m_pcf[3]=-7956.0;
     m_pcf[4]=4199.0;}
  else if (m_mval==2){
     m_cf=  0.04586609057205472385;
     m_pcf[0]=7.0;
     m_pcf[1]=-364.0;
     m_pcf[2]=2730.0;
     m_pcf[3]=-6188.0;
     m_pcf[4]=4199.0;}
  else if (m_mval==3){
     m_cf= -0.46774418167824218419;
     m_pcf[0]=-7.0;
     m_pcf[1]=105.0;
     m_pcf[2]=-357.0;
     m_pcf[3]=323.0;}
  else if (m_mval==4){
     m_cf=  0.33074508272523752775;
     m_pcf[0]=-1.0;
     m_pcf[1]=45.0;
     m_pcf[2]=-255.0;
     m_pcf[3]=323.0;}
  else if (m_mval==5){
     m_cf= -0.20918155726251223766;
     m_pcf[0]=15.0;
     m_pcf[1]=-170.0;
     m_pcf[2]=323.0;}
  else if (m_mval==6){
     m_cf=  0.11693604541956054605;
     m_pcf[0]=3.0;
     m_pcf[1]=-102.0;
     m_pcf[2]=323.0;}
  else if (m_mval==7){
     m_cf= -0.96427933341374470909;
     m_pcf[0]=-3.0;
     m_pcf[1]=19.0;}
  else if (m_mval==8){
     m_cf=  0.39366538939579466020;
     m_pcf[0]=-1.0;
     m_pcf[1]=19.0;}
  else if (m_mval==9){
     m_cf= -2.42671643887567141485;
     m_pcf[0]=1.0;}
  else if (m_mval==10){
     m_cf=  0.54263029194422146074;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==11){
  if (m_mval==0){
     m_cf=  0.00528468396465430642;
     m_pcf[0]=-693.0;
     m_pcf[1]=15015.0;
     m_pcf[2]=-90090.0;
     m_pcf[3]=218790.0;
     m_pcf[4]=-230945.0;
     m_pcf[5]=88179.0;}
  else if (m_mval==1){
     m_cf= -0.01517909905105581218;
     m_pcf[0]=-21.0;
     m_pcf[1]=1365.0;
     m_pcf[2]=-13650.0;
     m_pcf[3]=46410.0;
     m_pcf[4]=-62985.0;
     m_pcf[5]=29393.0;}
  else if (m_mval==2){
     m_cf=  0.17306835713159482562;
     m_pcf[0]=21.0;
     m_pcf[1]=-420.0;
     m_pcf[2]=2142.0;
     m_pcf[3]=-3876.0;
     m_pcf[4]=2261.0;}
  else if (m_mval==3){
     m_cf= -0.32378124843913115867;
     m_pcf[0]=1.0;
     m_pcf[1]=-60.0;
     m_pcf[2]=510.0;
     m_pcf[3]=-1292.0;
     m_pcf[4]=969.0;}
  else if (m_mval==4){
     m_cf=  0.70936917386918596788;
     m_pcf[0]=-5.0;
     m_pcf[1]=85.0;
     m_pcf[2]=-323.0;
     m_pcf[3]=323.0;}
  else if (m_mval==5){
     m_cf= -0.06702908649261443896;
     m_pcf[0]=-5.0;
     m_pcf[1]=255.0;
     m_pcf[2]=-1615.0;
     m_pcf[3]=2261.0;}
  else if (m_mval==6){
     m_cf=  0.22565353001535279375;
     m_pcf[0]=15.0;
     m_pcf[1]=-190.0;
     m_pcf[2]=399.0;}
  else if (m_mval==7){
     m_cf= -0.35678955845284249367;
     m_pcf[0]=1.0;
     m_pcf[1]=-38.0;
     m_pcf[2]=133.0;}
  else if (m_mval==8){
     m_cf=  3.11041925881287707794;
     m_pcf[0]=-1.0;
     m_pcf[1]=7.0;}
  else if (m_mval==9){
     m_cf= -0.40155339963683633758;
     m_pcf[0]=-1.0;
     m_pcf[1]=21.0;}
  else if (m_mval==10){
     m_cf=  2.60236345961048133525;
     m_pcf[0]=1.0;}
  else if (m_mval==11){
     m_cf= -0.55482575380661930186;
     m_pcf[0]=1.0;}
  }
 else if (m_lval==12){
  if (m_mval==0){
     m_cf=  0.00137741597545838937;
     m_pcf[0]=231.0;
     m_pcf[1]=-18018.0;
     m_pcf[2]=225225.0;
     m_pcf[3]=-1021020.0;
     m_pcf[4]=2078505.0;
     m_pcf[5]=-1939938.0;
     m_pcf[6]=676039.0;}
  else if (m_mval==1){
     m_cf= -0.01720392001939923763;
     m_pcf[0]=-231.0;
     m_pcf[1]=5775.0;
     m_pcf[2]=-39270.0;
     m_pcf[3]=106590.0;
     m_pcf[4]=-124355.0;
     m_pcf[5]=52003.0;}
  else if (m_mval==2){
     m_cf=  0.10674751643623661281;
     m_pcf[0]=-3.0;
     m_pcf[1]=225.0;
     m_pcf[2]=-2550.0;
     m_pcf[3]=9690.0;
     m_pcf[4]=-14535.0;
     m_pcf[5]=7429.0;}
  else if (m_mval==3){
     m_cf= -0.08715898219271343236;
     m_pcf[0]=45.0;
     m_pcf[1]=-1020.0;
     m_pcf[2]=5814.0;
     m_pcf[3]=-11628.0;
     m_pcf[4]=7429.0;}
  else if (m_mval==4){
     m_cf=  0.06536923664453507427;
     m_pcf[0]=5.0;
     m_pcf[1]=-340.0;
     m_pcf[2]=3230.0;
     m_pcf[3]=-9044.0;
     m_pcf[4]=7429.0;}
  else if (m_mval==5){
     m_cf= -0.76232974855408528513;
     m_pcf[0]=-5.0;
     m_pcf[1]=95.0;
     m_pcf[2]=-399.0;
     m_pcf[3]=437.0;}
  else if (m_mval==6){
     m_cf=  0.06791373178178368022;
     m_pcf[0]=-5.0;
     m_pcf[1]=285.0;
     m_pcf[2]=-1995.0;
     m_pcf[3]=3059.0;}
  else if (m_mval==7){
     m_cf= -0.72512022862157020307;
     m_pcf[0]=5.0;
     m_pcf[1]=-70.0;
     m_pcf[2]=161.0;}
  else if (m_mval==8){
     m_cf=  0.36256011431078510154;
     m_pcf[0]=1.0;
     m_pcf[1]=-42.0;
     m_pcf[2]=161.0;}
  else if (m_mval==9){
     m_cf= -1.10763944520067655360;
     m_pcf[0]=-3.0;
     m_pcf[1]=23.0;}
  else if (m_mval==10){
     m_cf=  0.40902297233181657223;
     m_pcf[0]=-1.0;
     m_pcf[1]=23.0;}
  else if (m_mval==11){
     m_cf= -2.77412876903309650928;
     m_pcf[0]=1.0;}
  else if (m_mval==12){
     m_cf=  0.56626666374219117095;
     m_pcf[0]=1.0;}
  }
}


cmplx YLMpoly::value(double x1, double x2, double x3) const
{
 if (m_lval==0) return cmplx(0.28209479177387814348,0.0);
 double rr=x1*x1+x2*x2+x3*x3;
 double zz=x3*x3;
 cmplx res=azimuthal(x1,x2);
 if (m_pdeg>0) res*=polarpoly(zz,rr);
 if (m_x3flag) res*=x3;
 return res;
}



double YLMpoly::realpart(double x1, double x2, double x3) const
{
 if (m_lval==0) return 0.28209479177387814348;
 double rr=x1*x1+x2*x2+x3*x3;
 double zz=x3*x3;
 double res=azimuthal_realpart(x1,x2);
 if (m_pdeg>0) res*=polarpoly(zz,rr);
 if (m_x3flag) res*=x3;
 return res;
}



double YLMpoly::imagpart(double x1, double x2, double x3) const
{
 if (m_lval==0) return 0.0;
 double rr=x1*x1+x2*x2+x3*x3;
 double zz=x3*x3;
 double res=azimuthal_imagpart(x1,x2);
 if (m_pdeg>0) res*=polarpoly(zz,rr);
 if (m_x3flag) res*=x3;
 return res;
}



double YLMpoly::polarpoly(double zz, double rr) const
{
 m_buf[m_pdeg]=1.0;
 for (int k=m_pdeg-1;k>=0;k--)
    m_buf[k]=m_buf[k+1]*rr;
 double res=m_buf[0]*m_pcf[0];
 double zzpow=1.0;
 for (int k=1;k<=m_pdeg;k++){
    zzpow*=zz;
    res+=m_buf[k]*zzpow*m_pcf[k];}
 return res;
}

   //  This evaluates  m_cf * (x1 + I * x2) ^ m_mvalue

cmplx YLMpoly::azimuthal(double x1, double x2) const
{
 if (m_mval==0) return cmplx(m_cf,0.0);
 else if (m_mval==1) return cmplx(m_cf*x1,m_cf*x2);
 cmplx xy(x1,x2),res(1.0,0.0);
 int powkey=m_mval;
 while (powkey>0){
    if (powkey & 1){
       res*=xy;}
    xy*=xy; powkey>>=1;}
 return m_cf*res;
}


double YLMpoly::azimuthal_realpart(double x1, double x2) const
{
 switch (m_mval){
 case 0:
    return m_cf;
 case 1:
    return m_cf*x1;
 case 2:
    return m_cf*(x1*x1-x2*x2);
 case 3:
    return m_cf*(x1*x1-3.0*x2*x2)*x1;
 case 4:
   {double xx1=x1*x1, xx2=x2*x2;
    return m_cf*(xx1-2.0*x1*x2-xx2)*(xx1+2.0*x1*x2-xx2);}
 case 5:
   {double xx1=x1*x1, xx2=x2*x2;
    return m_cf*(5.0*xx2*xx2+(xx1-10.0*xx2)*xx1)*x1;}
 case 6:
   {double xx1=x1*x1, xx2=x2*x2;
    return m_cf*(x1-1.0*x2)*(x1+x2)*(xx1-4.0*x1*x2+xx2)*(xx1+4.0*x1*x2+xx2);}
 default:
   {cmplx xy(x1,x2),res(1.0,0.0);
    int powkey=m_mval;
    while (powkey>0){
       if (powkey & 1){
          res*=xy;}
       xy*=xy; powkey>>=1;}
    return real(m_cf*res);}}
}



double YLMpoly::azimuthal_imagpart(double x1, double x2) const
{
 switch (m_mval){
 case 0:
    return 0.0;
 case 1:
    return m_cf*x2;
 case 2:
    return m_cf*2.0*x1*x2;
 case 3:
    return m_cf*x2*(3.0*x1*x1-x2*x2);
 case 4:
    return m_cf*4.0*x1*x2*(x1-x2)*(x1+x2);
 case 5:
   {double xx1=x1*x1, xx2=x2*x2;
    return m_cf*x2*(xx2*xx2+(5.0*xx1-10.0*xx2)*xx1);}
 case 6:
   {double xx1=x1*x1, xx2=x2*x2;
    return m_cf*2.0*x1*x2*(xx1-3.0*xx2)*(3.0*xx1-1.0*xx2);}
 default:
   {cmplx xy(x1,x2),res(1.0,0.0);
    int powkey=m_mval;
    while (powkey>0){
       if (powkey & 1){
          res*=xy;}
       xy*=xy; powkey>>=1;}
    return imag(m_cf*res);}}
}


// *********************************************************************

     //  From Numerical Recipes   dawson(x) = exp(-x^2) int( exp(t^2), t=0..x)

double dawson(double x)
{
 const int NMAX=24;
 const double A1=2.0/3.0;
 const double A2=0.4;
 const double A3=2.0/7.0;
 const double A4=2.0/9.0;
 const double A5=2.0/11.0;
 const double A6=2.0/13.0;
 const double A7=2.0/15.0;
 const double H=0.2;
 const double cf=0.564189583547756286948079;
 int i,n0;
 double d1,d2,e1,e2,sum,xp,xx,ans;
 static double c[NMAX+1];
 static int init = 0;

 if (init == 0){
    init=1;
    for (i=1;i<=NMAX;i++){
       d1=H*(2.0*i-1.0);  
       c[i]=exp(-d1*d1);}}
 if (std::abs(x) < 0.2){     // power series
    xx=x*x;
    ans=x*(1.0-A1*xx*(1.0-A2*xx*(1.0-A3*xx*(1.0-A4*xx*(1.0
         -A5*xx*(1.0-A6*xx*(1.0-A7*xx)))))));} 
 else{
    xx=std::abs(x);              // Rybicki sampling
    n0=2*(int)(0.5*xx/H+0.5);
    xp=xx-n0*H;
    e1=exp(2.0*xp*H);
    e2=e1*e1;
    d1=n0+1;
    d2=d1-2.0;
    sum=0.0;
    for (i=1;i<=NMAX;i++,d1+=2.0,d2-=2.0,e1*=e2)
       sum += c[i]*(e1/d1+1.0/(d2*e1));
    ans=cf*exp(-xp*xp)*sum;
    if (x<0.0) ans=-ans;}
 return ans;
}
 


double lzero_func(double usq)
{
 if (usq>=0.0){
    double u=sqrt(usq);
    return exp(usq)*(2.0*u*dawson(u)-1.0);}
 else{
    double u=sqrt(-usq);
    const double pisqrt=1.772453850905516027298;
    return -pisqrt*u*erf(u)-exp(usq);}
}


double lzero_func2(double usq)
{
 double eps=1e-12;
 double res=-1.0;
 double add=1.0;
 double term=1.0;
 int n=0;
 while (fabs(add)>abs(res)*eps){
    n++;
    term*=usq/double(n);
    add=term/(2.0*double(n)-1.0);
    res+=add;} 
 return res;
}

// ****************************************************************

bool zetaRGL_RestFrame_IsZero(int l, int m)
{
 if ((l%2)==1) return true;          // zero if l is odd
 if ((m%4)!=0) return true;          // zero if m not multiple of 
 if (l==2) return true;              // zero if l is 2
 return false;
}

// *********************************************************************

   //   Summation routines.


   // does sub-sum for |n1| + |n2| + |n3| = nntotal
   // class T must have member K T(n1,n2,n3) --> return type K
   // class K must must have += defined, K=0 must assign to zero
   // and abs(K) must be defined.

template <typename T, typename K>
inline void do_nn_subsum(K& res, T& summand, int nntotal)
{
 for (int n3abs=0;n3abs<=nntotal;n3abs++){
    int n3step=(n3abs!=0)?2*n3abs:1;
    for (int n2abs=0;n2abs<=(nntotal-n3abs);n2abs++){
       int n2step=(n2abs!=0)?2*n2abs:1;
       int n1abs=nntotal-n3abs-n2abs;
       int n1step=(n1abs!=0)?2*n1abs:1;
    for (int n1=-n1abs;n1<=n1abs;n1+=n1step)
    for (int n2=-n2abs;n2<=n2abs;n2+=n2step)
    for (int n3=-n3abs;n3<=n3abs;n3+=n3step)
       res+=summand(n1,n2,n3);}}
}

    //  Does the summation over n1, n2, n3.  Sum is done in order
    //  of increasing  |n1|+|n2|+|n3|=nn.  All terms up to "nnmin"
    //  are included, then after that, sum continues until convergence
    //  attained based on requested tolerances.

template <typename T, typename K>
inline void do_sum(K& res, T& summand, int nnmin, double abstol, double reltol, 
                   bool oexclude=false)
{
 res=(oexclude)?0:summand(0,0,0);
 for (int nn=1;nn<=nnmin;nn++){
    do_nn_subsum<T,K>(res,summand,nn);}
 const int nnmax=1024;
 K add;
 for (int nn=nnmin+1;nn<=nnmax;nn++){
    add=0;
    do_nn_subsum<T,K>(add,summand,nn);
    res+=add;
    double addmag=abs(add);
    double resmag=abs(res);
    if ((addmag<abstol)||(addmag<reltol*resmag)) return;}
 throw(std::runtime_error("sum failed to converge"));
}

    //  Simple summation: no convergence check

template <typename T, typename K>
inline void do_simple_sum(K& res, T& summand, int nmax, 
                          int offset1=0, int offset2=0, int offset3=0)
{
 res=0; 
 for (int n1=offset1-nmax;n1<=nmax+offset1;n1++)
 for (int n2=offset2-nmax;n2<=nmax+offset2;n2++)
 for (int n3=offset3-nmax;n3<=nmax+offset3;n3++)
    res+=summand(n1,n2,n3);
}

template <typename T, typename K>
inline void do_simple_sum_oexclude(K& res, T& summand, int nmax, 
                                   int offset1=0, int offset2=0, int offset3=0)
{
 res=0;
 for (int n1=offset1-nmax;n1<=nmax+offset1;n1++)
 for (int n2=offset2-nmax;n2<=nmax+offset2;n2++)
 for (int n3=offset3-nmax;n3<=nmax+offset3;n3++)
    if ((n1!=0)&&(n2!=0)&&(n3!=0)) res+=summand(n1,n2,n3);
}

// ***********************************************************

   // Gaussian quadrature vector

template <typename T>
class GQvec
{
   static const int m_ngauss=32;
   vector<T> m_store;

 public:

   GQvec() : m_store(m_ngauss) {}

   GQvec(const GQvec<T>& in) : m_store(in.m_store) {}

   GQvec(int c) : m_store(m_ngauss,T(c)) {}

   GQvec<T>& operator=(const GQvec<T>& in)
    {m_store=in.m_store; return *this;}

   GQvec<T>& operator=(int c)
    {for (int k=0;k<m_ngauss;k++) m_store[k]+=T(c); return *this;}

   GQvec<T>& operator+=(const GQvec<T>& add)
    {for (int k=0;k<m_ngauss;k++) m_store[k]+=add.m_store[k]; return *this;}

   int npoints() const {return m_ngauss;}

   double abs() const
    {double res=0.0;
     for (int k=0;k<m_ngauss;k++){
        double xx=std::abs(m_store[k]);
        if (xx>res) res=xx;}
     return res;}

   const T& operator[](int k) const {return m_store[k];}

   T& operator[](int k) {return m_store[k];}

};

template <typename T>
double abs(const GQvec<T>& in)
{
 return in.abs();
}


void assign_gq_abscissae_weights(GQvec<double>& abscissae,
                                 GQvec<double>& weights)
{
 abscissae[ 0]=  0.001368069075259218227509;  weights[  0]=  0.003509305004735048294500;
 abscissae[ 1]=  0.007194244227365832299912;  weights[  1]=  0.008137197365452835311006;
 abscissae[ 2]=  0.017618872206246784613094;  weights[  2]=  0.012696032654631029765878;
 abscissae[ 3]=  0.032546962031130155414540;  weights[  3]=  0.017136931456510716555404;
 abscissae[ 4]=  0.051839422116973938017346;  weights[  4]=  0.021417949011113340279872;
 abscissae[ 5]=  0.075316193133715014933153;  weights[  5]=  0.025499029631188088088508;
 abscissae[ 6]=  0.102758102016028796518451;  weights[  6]=  0.029342046739267773554389;
 abscissae[ 7]=  0.133908940629855159806287;  weights[  7]=  0.032911111388180923418612;
 abscissae[ 8]=  0.168477866534892399512442;  weights[  8]=  0.036172897054424253112176;
 abscissae[ 9]=  0.206142121379618835479627;  weights[  9]=  0.039096947893535153236086;
 abscissae[10]=  0.246550045533885304988126;  weights[ 10]=  0.041655962113473377611097;
 abscissae[11]=  0.289324361934682327317940;  weights[ 11]=  0.043826046502201905571388;
 abscissae[12]=  0.334065698858936175110042;  weights[ 12]=  0.045586939347881942356434;
 abscissae[13]=  0.380356318873931462727698;  weights[ 13]=  0.046922199540402282819590;
 abscissae[14]=  0.427764019208601753257407;  weights[ 14]=  0.047819360039637429709541;
 abscissae[15]=  0.475846167156130841882594;  weights[ 15]=  0.048270044257363900283382;
 abscissae[16]=  0.524153832843869158117406;  weights[ 16]=  0.048270044257363900283382;
 abscissae[17]=  0.572235980791398246742593;  weights[ 17]=  0.047819360039637429709541;
 abscissae[18]=  0.619643681126068537272302;  weights[ 18]=  0.046922199540402282819590;
 abscissae[19]=  0.665934301141063824889958;  weights[ 19]=  0.045586939347881942356434;
 abscissae[20]=  0.710675638065317672682060;  weights[ 20]=  0.043826046502201905571388;
 abscissae[21]=  0.753449954466114695011874;  weights[ 21]=  0.041655962113473377611097;
 abscissae[22]=  0.793857878620381164520373;  weights[ 22]=  0.039096947893535153236086;
 abscissae[23]=  0.831522133465107600487558;  weights[ 23]=  0.036172897054424253112176;
 abscissae[24]=  0.866091059370144840193713;  weights[ 24]=  0.032911111388180923418612;
 abscissae[25]=  0.897241897983971203481549;  weights[ 25]=  0.029342046739267773554389;
 abscissae[26]=  0.924683806866284985066847;  weights[ 26]=  0.025499029631188088088508;
 abscissae[27]=  0.948160577883026061982654;  weights[ 27]=  0.021417949011113340279872;
 abscissae[28]=  0.967453037968869844585460;  weights[ 28]=  0.017136931456510716555404;
 abscissae[29]=  0.982381127793753215386906;  weights[ 29]=  0.012696032654631029765878;
 abscissae[30]=  0.992805755772634167700088;  weights[ 30]=  0.008137197365452835311006;
 abscissae[31]=  0.998631930924740781772491;  weights[ 31]=  0.003509305004735048294500;
}
/*
void assign_gq_abscissae_weights(GQvec<double>& abscissae,
                                 GQvec<double>& weights)
 abscissae[ 0]=  0.000614496373786940699729;  weights[  0]=  0.001576673026155008503200;
 abscissae[ 1]=  0.003234913866824621226036;  weights[  1]=  0.003663776950666149277350;
 abscissae[ 2]=  0.007937708138586571127708;  weights[  2]=  0.005738617289622212345074;
 abscissae[ 3]=  0.014704203726876374769294;  weights[  3]=  0.007789657861441853379128;
 abscissae[ 4]=  0.023506148419784569638520;  weights[  4]=  0.009808080228715613437210;
 abscissae[ 5]=  0.034306654646722833442913;  weights[  5]=  0.011785380419568279119624;
 abscissae[ 6]=  0.047060431642215163588963;  weights[  6]=  0.013713254854188918531323;
 abscissae[ 7]=  0.061713989862876057047153;  weights[  7]=  0.015583613916411056588286;
 abscissae[ 8]=  0.078205869187803234644455;  weights[  8]=  0.017388611282389094163839;
 abscissae[ 9]=  0.096466897985278686458723;  weights[  9]=  0.019120675532914933319873;
 abscissae[10]=  0.116420483742129830373072;  weights[ 10]=  0.020772541471732020449686;
 abscissae[11]=  0.137982934538092672662759;  weights[ 11]=  0.022337280428347154754836;
 abscissae[12]=  0.161063810183668047394074;  weights[ 12]=  0.023808329246245221401385;
 abscissae[13]=  0.185566301611743188002418;  weights[ 13]=  0.025179517776927238125942;
 abscissae[14]=  0.211387636958013648091095;  weights[ 14]=  0.026445094742596834057610;
 abscissae[15]=  0.238419512638883483160887;  weights[ 15]=  0.027599751849992081410365;
 abscissae[16]=  0.266548547624520797727536;  weights[ 16]=  0.028638646050201607850234;
 abscissae[17]=  0.295656759004641635041887;  weights[ 17]=  0.029557419849197817872816;
 abscissae[18]=  0.325622056853919630920091;  weights[ 18]=  0.030352219582946940026474;
 abscissae[19]=  0.356318756322272211632057;  weights[ 19]=  0.031019711579946331952098;
 abscissae[20]=  0.387618104802655469387567;  weights[ 20]=  0.031557096143127012828563;
 abscissae[21]=  0.419388821965554140971781;  weights[ 21]=  0.031962119292324093311953;
 abscissae[22]=  0.451497650395268650534973;  weights[ 22]=  0.032233082217975041103252;
 abscissae[23]=  0.483809914518565318983339;  weights[ 23]=  0.032368848406341961251512;
 abscissae[24]=  0.516190085481434681016661;  weights[ 24]=  0.032368848406341961251512;
 abscissae[25]=  0.548502349604731349465027;  weights[ 25]=  0.032233082217975041103252;
 abscissae[26]=  0.580611178034445859028219;  weights[ 26]=  0.031962119292324093311953;
 abscissae[27]=  0.612381895197344530612433;  weights[ 27]=  0.031557096143127012828563;
 abscissae[28]=  0.643681243677727788367943;  weights[ 28]=  0.031019711579946331952098;
 abscissae[29]=  0.674377943146080369079909;  weights[ 29]=  0.030352219582946940026474;
 abscissae[30]=  0.704343240995358364958113;  weights[ 30]=  0.029557419849197817872816;
 abscissae[31]=  0.733451452375479202272464;  weights[ 31]=  0.028638646050201607850234;
 abscissae[32]=  0.761580487361116516839113;  weights[ 32]=  0.027599751849992081410365;
 abscissae[33]=  0.788612363041986351908905;  weights[ 33]=  0.026445094742596834057610;
 abscissae[34]=  0.814433698388256811997582;  weights[ 34]=  0.025179517776927238125942;
 abscissae[35]=  0.838936189816331952605926;  weights[ 35]=  0.023808329246245221401385;
 abscissae[36]=  0.862017065461907327337241;  weights[ 36]=  0.022337280428347154754836;
 abscissae[37]=  0.883579516257870169626928;  weights[ 37]=  0.020772541471732020449686;
 abscissae[38]=  0.903533102014721313541277;  weights[ 38]=  0.019120675532914933319873;
 abscissae[39]=  0.921794130812196765355545;  weights[ 39]=  0.017388611282389094163839;
 abscissae[40]=  0.938286010137123942952847;  weights[ 40]=  0.015583613916411056588286;
 abscissae[41]=  0.952939568357784836411037;  weights[ 41]=  0.013713254854188918531323;
 abscissae[42]=  0.965693345353277166557087;  weights[ 42]=  0.011785380419568279119624;
 abscissae[43]=  0.976493851580215430361480;  weights[ 43]=  0.009808080228715613437210;
 abscissae[44]=  0.985295796273123625230706;  weights[ 44]=  0.007789657861441853379128;
 abscissae[45]=  0.992062291861413428872292;  weights[ 45]=  0.005738617289622212345074;
 abscissae[46]=  0.996765086133175378773964;  weights[ 46]=  0.003663776950666149277350;
 abscissae[47]=  0.999385503626213059300271;  weights[ 47]=  0.001576673026155008503200;
}
*/
// ***********************************************************


class ZetaSummand1
{
    double usq;
    YLMpoly ylm;

 public:

    ZetaSummand1(int lval, int mval, double usq);
    cmplx operator()(int n1, int n2, int n3) const;
};


ZetaSummand1::ZetaSummand1(int lval, int mval, double uu) : ylm(lval,mval)
{
 usq=uu;
}

inline cmplx ZetaSummand1::operator()(int n1, int n2, int n3) const
{
 double z1=n1;
 double z2=n2;
 double z3=n3;
 double zz=z1*z1+z2*z2+z3*z3;
 return ylm.value(z1,z2,z3)/(zz-usq)*exp(-(zz-usq));
}


class ZetaSummand1s
{
    double alpha,b1,b2,b3,usq;
    YLMpoly ylm;

 public:

    ZetaSummand1s(int lval, int mval, const vector<double>& s, double ss,
                  double gam, double usq);
    cmplx operator()(int n1, int n2, int n3) const;
};


ZetaSummand1s::ZetaSummand1s(int lval, int mval, const vector<double>& s,
                             double ss, double gam, double uu) : ylm(lval,mval)
{
 b1=-s[0]/(2.0*gam);
 b2=-s[1]/(2.0*gam);
 b3=-s[2]/(2.0*gam);
 alpha=4.0*gam*(1.0-gam)/ss;
 usq=uu;
}

inline cmplx ZetaSummand1s::operator()(int n1, int n2, int n3) const
{
 double zb=1.0+alpha*(n1*b1+n2*b2+n3*b3);
 double z1=n1+zb*b1;
 double z2=n2+zb*b2;
 double z3=n3+zb*b3;
 double zz=z1*z1+z2*z2+z3*z3;
 return ylm.value(z1,z2,z3)/(zz-usq)*exp(-(zz-usq));
}


  // *****

class ZetaSummand1_re
{
    double usq;
    YLMpoly ylm;

 public:

    ZetaSummand1_re(int lval, int mval, double usq);
    double operator()(int n1, int n2, int n3) const;
};


ZetaSummand1_re::ZetaSummand1_re(int lval, int mval, double uu) : ylm(lval,mval)
{
 usq=uu;
}

inline double ZetaSummand1_re::operator()(int n1, int n2, int n3) const
{
 double z1=n1;
 double z2=n2;
 double z3=n3;
 double zz=z1*z1+z2*z2+z3*z3;
 return ylm.realpart(z1,z2,z3)/(zz-usq)*exp(-(zz-usq));
}


class ZetaSummand1s_re
{
    double alpha,b1,b2,b3,usq;
    YLMpoly ylm;

 public:

    ZetaSummand1s_re(int lval, int mval, const vector<double>& s, double ss,
                     double gam, double usq);
    double operator()(int n1, int n2, int n3) const;
};


ZetaSummand1s_re::ZetaSummand1s_re(int lval, int mval, const vector<double>& s,
                                   double ss, double gam, double uu) : ylm(lval,mval)
{
 b1=-s[0]/(2.0*gam);
 b2=-s[1]/(2.0*gam);
 b3=-s[2]/(2.0*gam);
 alpha=4.0*gam*(1.0-gam)/ss;
 usq=uu;
}

inline double ZetaSummand1s_re::operator()(int n1, int n2, int n3) const
{
 double zb=1.0+alpha*(n1*b1+n2*b2+n3*b3);
 double z1=n1+zb*b1;
 double z2=n2+zb*b2;
 double z3=n3+zb*b3;
 double zz=z1*z1+z2*z2+z3*z3;
 return ylm.realpart(z1,z2,z3)/(zz-usq)*exp(-(zz-usq));
}



  // *****

class ZetaSummand1_im
{
    double usq;
    YLMpoly ylm;

 public:

    ZetaSummand1_im(int lval, int mval, double usq);
    double operator()(int n1, int n2, int n3) const;
};


ZetaSummand1_im::ZetaSummand1_im(int lval, int mval, double uu) : ylm(lval,mval)
{
 usq=uu;
}

inline double ZetaSummand1_im::operator()(int n1, int n2, int n3) const
{
 double z1=n1;
 double z2=n2;
 double z3=n3;
 double zz=z1*z1+z2*z2+z3*z3;
 return ylm.imagpart(z1,z2,z3)/(zz-usq)*exp(-(zz-usq));
}


class ZetaSummand1s_im
{
    double alpha,b1,b2,b3,usq;
    YLMpoly ylm;

 public:

    ZetaSummand1s_im(int lval, int mval, const vector<double>& s, double ss,
                     double gam, double usq);
    double operator()(int n1, int n2, int n3) const;
};


ZetaSummand1s_im::ZetaSummand1s_im(int lval, int mval, const vector<double>& s,
                                   double ss, double gam, double uu) : ylm(lval,mval)
{
 b1=-s[0]/(2.0*gam);
 b2=-s[1]/(2.0*gam);
 b3=-s[2]/(2.0*gam);
 alpha=4.0*gam*(1.0-gam)/ss;
 usq=uu;
}

inline double ZetaSummand1s_im::operator()(int n1, int n2, int n3) const
{
 double zb=1.0+alpha*(n1*b1+n2*b2+n3*b3);
 double z1=n1+zb*b1;
 double z2=n2+zb*b2;
 double z3=n3+zb*b3;
 double zz=z1*z1+z2*z2+z3*z3;
 return ylm.imagpart(z1,z2,z3)/(zz-usq)*exp(-(zz-usq));
}


// ***************************************************************

class ZetaSummand2
{
    double usq;
    YLMpoly ylm;
    GQvec<double> tvals;
    mutable GQvec<cmplx> summands;

 public:

    ZetaSummand2(int lval, int mval, double usq, const GQvec<double>& tvalues);
    const GQvec<cmplx>& operator()(int n1, int n2, int n3) const;
};


ZetaSummand2::ZetaSummand2(int lval, int mval, double uu,
                           const GQvec<double>& tvalues) 
                     : ylm(lval,mval), tvals(tvalues)
{
 usq=uu;
}

inline const GQvec<cmplx>& ZetaSummand2::operator()(int n1, int n2, int n3) const
{
 const double pipi=9.86960440108935861883447;
 double w1=n1;
 double w2=n2;
 double w3=n3;
 double ww=w1*w1+w2*w2+w3*w3;
 cmplx ylmval=ylm.value(w1,w2,w3);
 for (int k=0;k<tvals.npoints();k++)
    summands[k]=ylmval*exp(-pipi*ww/tvals[k]);
 return summands;
}


class ZetaSummand2s
{
    double alpha,s1,s2,s3,usq;
    YLMpoly ylm;
    GQvec<double> tvals;
    mutable GQvec<cmplx> summands;

 public:

    ZetaSummand2s(int lval, int mval, const vector<double>& s, double ss,
                  double gam, double usq, const GQvec<double>& tvalues);
    const GQvec<cmplx>& operator()(int n1, int n2, int n3) const;
};


ZetaSummand2s::ZetaSummand2s(int lval, int mval, const vector<double>& s,
                            double ss, double gam, double uu,
                            const GQvec<double>& tvalues) 
                           : ylm(lval,mval), tvals(tvalues)
{
 s1=s[0]; s2=s[1]; s3=s[2];
 alpha=(gam-1.0)/ss;
 usq=uu;
}

inline const GQvec<cmplx>& ZetaSummand2s::operator()(int n1, int n2, int n3) const
{
 const double pi=3.14159265358979323846264;
 const double pipi=9.86960440108935861883447;
 double wb=n1*s1+n2*s2+n3*s3;
 cmplx phase(cos(pi*wb),sin(pi*wb));
 wb*=alpha;
 double w1=n1+wb*s1;
 double w2=n2+wb*s2;
 double w3=n3+wb*s3;
 double ww=w1*w1+w2*w2+w3*w3;
 phase*=ylm.value(w1,w2,w3);
 for (int k=0;k<tvals.npoints();k++)
    summands[k]=phase*exp(-pipi*ww/tvals[k]);
 return summands;
}


   // *********


class ZetaSummand2_re
{
    double usq;
    YLMpoly ylm;
    GQvec<double> tvals;
    mutable GQvec<double> summands;

 public:

    ZetaSummand2_re(int lval, int mval, double usq, const GQvec<double>& tvalues);
    const GQvec<double>& operator()(int n1, int n2, int n3) const;
};


ZetaSummand2_re::ZetaSummand2_re(int lval, int mval, double uu,
                                 const GQvec<double>& tvalues) 
                     : ylm(lval,mval), tvals(tvalues)
{
 usq=uu;
}

inline const GQvec<double>& ZetaSummand2_re::operator()(int n1, int n2, int n3) const
{
 const double pipi=9.86960440108935861883447;
 double w1=n1;
 double w2=n2;
 double w3=n3;
 double ww=w1*w1+w2*w2+w3*w3;
 double ylmval=ylm.realpart(w1,w2,w3);
 for (int k=0;k<tvals.npoints();k++)
    summands[k]=ylmval*exp(-pipi*ww/tvals[k]);
 return summands;
}


class ZetaSummand2s_re
{
    double alpha,s1,s2,s3,usq;
    YLMpoly ylm;
    GQvec<double> tvals;
    mutable GQvec<double> summands;

 public:

    ZetaSummand2s_re(int lval, int mval, const vector<double>& s, double ss,
                     double gam, double usq, const GQvec<double>& tvalues);
    const GQvec<double>& operator()(int n1, int n2, int n3) const;
};


ZetaSummand2s_re::ZetaSummand2s_re(int lval, int mval, const vector<double>& s,
                                   double ss, double gam, double uu,
                                   const GQvec<double>& tvalues) 
                           : ylm(lval,mval), tvals(tvalues)
{
 s1=s[0]; s2=s[1]; s3=s[2];
 alpha=(gam-1.0)/ss;
 usq=uu;
}

inline const GQvec<double>& ZetaSummand2s_re::operator()(int n1, int n2, int n3) const
{
 const double pi=3.14159265358979323846264;
 const double pipi=9.86960440108935861883447;
 double wb=n1*s1+n2*s2+n3*s3;
 double phase_re=cos(pi*wb);
 double phase_im=sin(pi*wb);
 wb*=alpha;
 double w1=n1+wb*s1;
 double w2=n2+wb*s2;
 double w3=n3+wb*s3;
 double ww=w1*w1+w2*w2+w3*w3;
 cmplx ylmval=ylm.value(w1,w2,w3);
 double phase=phase_re*ylmval.real()-phase_im*ylmval.imag();    
 for (int k=0;k<tvals.npoints();k++)
    summands[k]=phase*exp(-pipi*ww/tvals[k]);
 return summands;
}

   // *********


class ZetaSummand2_im
{
    double usq;
    YLMpoly ylm;
    GQvec<double> tvals;
    mutable GQvec<double> summands;

 public:

    ZetaSummand2_im(int lval, int mval, double usq, const GQvec<double>& tvalues);
    const GQvec<double>& operator()(int n1, int n2, int n3) const;
};


ZetaSummand2_im::ZetaSummand2_im(int lval, int mval, double uu,
                                 const GQvec<double>& tvalues) 
                     : ylm(lval,mval), tvals(tvalues)
{
 usq=uu;
}

inline const GQvec<double>& ZetaSummand2_im::operator()(int n1, int n2, int n3) const
{
 const double pipi=9.86960440108935861883447;
 double w1=n1;
 double w2=n2;
 double w3=n3;
 double ww=w1*w1+w2*w2+w3*w3;
 double ylmval=ylm.imagpart(w1,w2,w3);
 for (int k=0;k<tvals.npoints();k++)
    summands[k]=ylmval*exp(-pipi*ww/tvals[k]);
 return summands;
}


class ZetaSummand2s_im
{
    double alpha,s1,s2,s3,usq;
    YLMpoly ylm;
    GQvec<double> tvals;
    mutable GQvec<double> summands;

 public:

    ZetaSummand2s_im(int lval, int mval, const vector<double>& s, double ss,
                     double gam, double usq, const GQvec<double>& tvalues);
    const GQvec<double>& operator()(int n1, int n2, int n3) const;
};


ZetaSummand2s_im::ZetaSummand2s_im(int lval, int mval, const vector<double>& s,
                                   double ss, double gam, double uu,
                                   const GQvec<double>& tvalues) 
                           : ylm(lval,mval), tvals(tvalues)
{
 s1=s[0]; s2=s[1]; s3=s[2];
 alpha=(gam-1.0)/ss;
 usq=uu;
}

inline const GQvec<double>& ZetaSummand2s_im::operator()(int n1, int n2, int n3) const
{
 const double pi=3.14159265358979323846264;
 const double pipi=9.86960440108935861883447;
 double wb=n1*s1+n2*s2+n3*s3;
 double phase_re=cos(pi*wb);
 double phase_im=sin(pi*wb);
 wb*=alpha;
 double w1=n1+wb*s1;
 double w2=n2+wb*s2;
 double w3=n3+wb*s3;
 double ww=w1*w1+w2*w2+w3*w3;
 cmplx ylmval=ylm.value(w1,w2,w3);
 double phase=phase_im*ylmval.real()+phase_re*ylmval.imag();    
 for (int k=0;k<tvals.npoints();k++)
    summands[k]=phase*exp(-pipi*ww/tvals[k]);
 return summands;
}

// ***************************************************************


cmplx zeta_noshift(int l, int m, double usq)
{
 if (zetaRGL_RestFrame_IsZero(l,m)) return cmplx(0.0,0.0);
 const double pi=3.14159265358979323846264;

 bool oexclude=((fabs(usq)>1e-12)||(l==0))?false:true;
 cmplx res1;
 ZetaSummand1 summand1(l,m,usq);
 int nnmin=ceil(sqrt(std::abs(usq)));
 nnmin+=6;
 double abstol=1e-18, reltol=1e-12;
 do_sum<ZetaSummand1,cmplx>(res1,summand1,nnmin,abstol,reltol,oexclude);

 GQvec<double> tvals,wts;
 assign_gq_abscissae_weights(tvals,wts);
 ZetaSummand2 summand2(l,m,usq,tvals);
 GQvec<cmplx> intgrand;
 nnmin=6;
 do_sum<ZetaSummand2,GQvec<cmplx> >(intgrand,summand2,nnmin,abstol,reltol,true);

 cmplx res2(0.0,0.0);
 for (int k=0;k<tvals.npoints();k++){
    res2+=wts[k]*intgrand[k]*exp(tvals[k]*usq)/pow(tvals[k],1.5+double(l));}
 cmplx I(0.0,1.0),Il(1.0,0.0);
 for (int k=1;k<=l;k++) Il*=I;
 res2*=Il*pow(pi,1.5+double(l));

 if (l==0){
    res2+=pi*lzero_func(usq);}

 return res1+res2;
}


cmplx zeta_shifted(int l, int m, const vector<double>& s, double ss, 
                   double gam, double usq)
{
 const double pi=3.14159265358979323846264;

 cmplx res1;
 ZetaSummand1s summand1(l,m,s,ss,gam,usq);
 int nnmin=ceil(std::abs(s[0]));
 int nn=ceil(std::abs(s[1])); if (nn>nnmin) nnmin=nn;
 nn=ceil(std::abs(s[2])); if (nn>nnmin) nnmin=nn;
 nn=ceil(sqrt(std::abs(usq))); if (nn>nnmin) nnmin=nn;
 nnmin+=6;
 double abstol=1e-18, reltol=1e-12;
 do_sum<ZetaSummand1s,cmplx>(res1,summand1,nnmin,abstol,reltol);

 GQvec<double> tvals,wts;
 assign_gq_abscissae_weights(tvals,wts);
 ZetaSummand2s summand2(l,m,s,ss,gam,usq,tvals);
 GQvec<cmplx> intgrand;
 nnmin=6;
 do_sum<ZetaSummand2s,GQvec<cmplx> >(intgrand,summand2,nnmin,abstol,reltol,true);

 cmplx res2(0.0,0.0);
 for (int k=0;k<tvals.npoints();k++){
    res2+=wts[k]*intgrand[k]*exp(tvals[k]*usq)/pow(tvals[k],1.5+double(l));}
 cmplx I(0.0,1.0),Il(1.0,0.0);
 for (int k=1;k<=l;k++) Il*=I;
 res2*=Il*gam*pow(pi,1.5+double(l));

 if (l==0){
    res2+=gam*pi*lzero_func(usq);}

 return res1+res2;
}


 // ***********



double high_zeta_noshift_re(int l, int m, double usq, double abstol, double reltol)
{
 const double pi=3.14159265358979323846264;
 GQvec<double> tvals,wts;
 assign_gq_abscissae_weights(tvals,wts);
 ZetaSummand2_re summand2(l,m,usq,tvals);
 GQvec<double> intgrand;
 int nnmin=6;
 do_sum<ZetaSummand2_re,GQvec<double> >(intgrand,summand2,nnmin,abstol,reltol,true);
 double res2=0.0;
 for (int k=0;k<tvals.npoints();k++){
    res2+=wts[k]*intgrand[k]*exp(tvals[k]*usq)/pow(tvals[k],1.5+double(l));}
 res2*=pow(pi,1.5+double(l));
 return res2;
}

double high_zeta_noshift_im(int l, int m, double usq, double abstol, double reltol)
{
 const double pi=3.14159265358979323846264;
 GQvec<double> tvals,wts;
 assign_gq_abscissae_weights(tvals,wts);
 ZetaSummand2_im summand2(l,m,usq,tvals);
 GQvec<double> intgrand;
 int nnmin=6;
 do_sum<ZetaSummand2_im,GQvec<double> >(intgrand,summand2,nnmin,abstol,reltol,true);
 double res2=0.0;
 for (int k=0;k<tvals.npoints();k++){
    res2+=wts[k]*intgrand[k]*exp(tvals[k]*usq)/pow(tvals[k],1.5+double(l));}
 res2*=pow(pi,1.5+double(l));
 return res2;
}


double high_zeta_shifted_re(int l, int m, const vector<double>& s, double ss, 
                            double gam, double usq, double abstol, double reltol)
{
 const double pi=3.14159265358979323846264;
 GQvec<double> tvals,wts;
 assign_gq_abscissae_weights(tvals,wts);
 ZetaSummand2s_re summand2(l,m,s,ss,gam,usq,tvals);
 GQvec<double> intgrand;
 int nnmin=6;
 do_sum<ZetaSummand2s_re,GQvec<double> >(intgrand,summand2,nnmin,abstol,reltol,true);
 double res2=0.0;
 for (int k=0;k<tvals.npoints();k++){
    res2+=wts[k]*intgrand[k]*exp(tvals[k]*usq)/pow(tvals[k],1.5+double(l));}
 res2*=gam*pow(pi,1.5+double(l));
 return res2;
}

double high_zeta_shifted_im(int l, int m, const vector<double>& s, double ss, 
                            double gam, double usq, double abstol, double reltol)
{
 const double pi=3.14159265358979323846264;
 GQvec<double> tvals,wts;
 assign_gq_abscissae_weights(tvals,wts);
 ZetaSummand2s_im summand2(l,m,s,ss,gam,usq,tvals);
 GQvec<double> intgrand;
 int nnmin=6;
 do_sum<ZetaSummand2s_im,GQvec<double> >(intgrand,summand2,nnmin,abstol,reltol,true);
 double res2=0.0;
 for (int k=0;k<tvals.npoints();k++){
    res2+=wts[k]*intgrand[k]*exp(tvals[k]*usq)/pow(tvals[k],1.5+double(l));}
 res2*=gam*pow(pi,1.5+double(l));
 return res2;
}






double zeta_noshift_re(int l, int m, double usq)
{
 if (zetaRGL_RestFrame_IsZero(l,m)) return 0.0;
 const double pi=3.14159265358979323846264;
 bool oexclude=((fabs(usq)>1e-12)||(l==0))?false:true;
 double res1;
 ZetaSummand1_re summand1(l,m,usq);
 int nnmin=ceil(sqrt(std::abs(usq)));
 nnmin+=6;
 double abstol=1e-18, reltol=1e-12;
 do_sum<ZetaSummand1_re,double>(res1,summand1,nnmin,abstol,reltol,oexclude);

 double res2=0.0;
 int p=l%4;   // apply I^L
 if (p==0)
    res2=high_zeta_noshift_re(l,m,usq,abstol,reltol);
 else if (p==1)
    res2=-high_zeta_noshift_im(l,m,usq,abstol,reltol);
 else if (p==2)
    res2=-high_zeta_noshift_re(l,m,usq,abstol,reltol);
 else
    res2=high_zeta_noshift_im(l,m,usq,abstol,reltol);
 if (l==0){
    res2+=pi*lzero_func(usq);}
 return res1+res2;
}


double zeta_shifted_re(int l, int m, const vector<double>& s, double ss, 
                      double gam, double usq)
{
 const double pi=3.14159265358979323846264;
 double res1;
 ZetaSummand1s_re summand1(l,m,s,ss,gam,usq);
 int nnmin=ceil(std::abs(s[0]));
 int nn=ceil(std::abs(s[1])); if (nn>nnmin) nnmin=nn;
 nn=ceil(std::abs(s[2])); if (nn>nnmin) nnmin=nn;
 nn=ceil(sqrt(std::abs(usq))); if (nn>nnmin) nnmin=nn;
 nnmin+=6;
 double abstol=1e-18, reltol=1e-12;
 do_sum<ZetaSummand1s_re,double>(res1,summand1,nnmin,abstol,reltol);

 double res2=0.0;
 int p=l%4;   // apply I^L
 if (p==0)
    res2=high_zeta_shifted_re(l,m,s,ss,gam,usq,abstol,reltol);
 else if (p==1)
    res2=-high_zeta_shifted_im(l,m,s,ss,gam,usq,abstol,reltol);
 else if (p==2)
    res2=-high_zeta_shifted_re(l,m,s,ss,gam,usq,abstol,reltol);
 else
    res2=high_zeta_shifted_im(l,m,s,ss,gam,usq,abstol,reltol);
 if (l==0){
    res2+=gam*pi*lzero_func(usq);}
 return res1+res2;
}


 // *******


double zeta_noshift_im(int l, int m, double usq)
{
 if (zetaRGL_RestFrame_IsZero(l,m)) return 0.0;
 bool oexclude=((fabs(usq)>1e-12)||(l==0))?false:true;
 double res1;
 ZetaSummand1_im summand1(l,m,usq);
 int nnmin=ceil(sqrt(std::abs(usq)));
 nnmin+=6;
 double abstol=1e-18, reltol=1e-12;
 do_sum<ZetaSummand1_im,double>(res1,summand1,nnmin,abstol,reltol,oexclude);

 double res2=0.0;
 int p=l%4;   // apply I^L
 if (p==0)
    res2=high_zeta_noshift_im(l,m,usq,abstol,reltol);
 else if (p==1)
    res2=high_zeta_noshift_re(l,m,usq,abstol,reltol);
 else if (p==2)
    res2=-high_zeta_noshift_im(l,m,usq,abstol,reltol);
 else
    res2=-high_zeta_noshift_re(l,m,usq,abstol,reltol);
 return res1+res2;
}


double zeta_shifted_im(int l, int m, const vector<double>& s, double ss, 
                       double gam, double usq)
{
 double res1;
 ZetaSummand1s_im summand1(l,m,s,ss,gam,usq);
 int nnmin=ceil(std::abs(s[0]));
 int nn=ceil(std::abs(s[1])); if (nn>nnmin) nnmin=nn;
 nn=ceil(std::abs(s[2])); if (nn>nnmin) nnmin=nn;
 nn=ceil(sqrt(std::abs(usq))); if (nn>nnmin) nnmin=nn;
 nnmin+=6;
 double abstol=1e-18, reltol=1e-12;
 do_sum<ZetaSummand1s_im,double>(res1,summand1,nnmin,abstol,reltol);

 double res2=0.0;
 int p=l%4;   // apply I^L
 if (p==0)
    res2=high_zeta_shifted_im(l,m,s,ss,gam,usq,abstol,reltol);
 else if (p==1)
    res2=high_zeta_shifted_re(l,m,s,ss,gam,usq,abstol,reltol);
 else if (p==2)
    res2=-high_zeta_shifted_im(l,m,s,ss,gam,usq,abstol,reltol);
 else
    res2=-high_zeta_shifted_re(l,m,s,ss,gam,usq,abstol,reltol);
 return res1+res2;
}



 // *******************************************************************


cmplx zetaRGL(int l, int m, const vector<double>& s, double gam, double usq)
{
 double ss=s[0]*s[0]+s[1]*s[1]+s[2]*s[2];
 if (ss<1e-15){
    return zeta_noshift(l,m,usq);}
 return zeta_shifted(l,m,s,ss,gam,usq);
}

double zetaRGL_re(int l, int m, const vector<double>& s, double gam, double usq)
{
 double ss=s[0]*s[0]+s[1]*s[1]+s[2]*s[2];
 if (ss<1e-15){
    return zeta_noshift_re(l,m,usq);}
 return zeta_shifted_re(l,m,s,ss,gam,usq);
}

double zetaRGL_im(int l, int m, const vector<double>& s, double gam, double usq)
{
 double ss=s[0]*s[0]+s[1]*s[1]+s[2]*s[2];
 if (ss<1e-15){
    return zeta_noshift_im(l,m,usq);}
 return zeta_shifted_im(l,m,s,ss,gam,usq);
}



// ********************************************************************


WZetaRGLCalculator::WZetaRGLCalculator(const std::vector<double>& s, 
                                       double gam, double usq)
   : m_gam(gam), m_usq(usq), m_svec(s)  {}


WZetaRGLCalculator::WZetaRGLCalculator()
   : m_gam(1.0), m_usq(0.0), m_svec(vector<double>(3,0.0))  {}


void WZetaRGLCalculator::reset(const std::vector<double>& s, 
                               double gam, double usq)
{
 m_wr_lm_values.clear();
 m_wi_lm_values.clear();
 m_gam=gam;
 m_usq=usq;
 m_svec=s;
}


void WZetaRGLCalculator::reset_if_diff(const std::vector<double>& s, 
                                       double gam, double usq)
{
 const double eps=1e-10;
 if ((std::abs(m_gam-gam)>eps)||(std::abs(m_usq-usq)>eps)||
     (std::abs(m_svec[0]-s[0])>eps)||(std::abs(m_svec[1]-s[1])>eps)||
     (std::abs(m_svec[2]-s[2])>eps)){
    m_wr_lm_values.clear();
    m_wi_lm_values.clear();
    m_gam=gam;
    m_usq=usq;
    m_svec=s;}
}


void WZetaRGLCalculator::clear()
{
 m_wr_lm_values.clear();
 m_wi_lm_values.clear();
}


  //  evaluates  x^n  given x^2 and integer n>=0

cmplx WZetaRGLCalculator::uint_power_from_sq(double xsq, uint n)
{
 uint nn=n;
 bool flag=nn&0x1u;
 double rr,ri;
 if (flag){
    if (xsq>=0.0){
       rr=sqrt(xsq); ri=0.0;}
    else{
       rr=0.0; ri=sqrt(-xsq);}}
 else{
    rr=1.0; ri=0.0;}
 double v=xsq;
 double p=1.0;
 nn>>=1;
 while (nn){
    if (nn&0x1u) p*=v; 
    v*=v; nn>>=1;}
 return cmplx(rr*p,ri*p);
}



cmplx& WZetaRGLCalculator::eval_wr_lm(uint l, uint m)
{
 uint lmcode=encode_lm(l,m);
 std::map<uint,cmplx>::iterator it=m_wr_lm_values.find(lmcode);
 if (it!=m_wr_lm_values.end()){
    //cout << "wr["<<l<<","<<m<<"] got from map"<<endl;
    return it->second;}
 double res=zetaRGL_re(l,m,m_svec,m_gam,m_usq);
 res*=0.17958712212516656169/m_gam;   // multiply by 1/(gam*pi^(3/2))
 cmplx zres(res/uint_power_from_sq(m_usq,l+1));
 std::pair<std::map<uint,cmplx>::iterator,bool> rt
     =m_wr_lm_values.insert(make_pair(lmcode,zres));
 if (!(rt.second)) 
    throw(std::runtime_error("Could not insert into map"));
 //cout << "wr["<<l<<","<<m<<"] computed "<<rt.first->second<<endl;
 return rt.first->second;
}

 
cmplx& WZetaRGLCalculator::eval_wi_lm(uint l, uint m)
{
 uint lmcode=encode_lm(l,m);
 std::map<uint,cmplx>::iterator it=m_wi_lm_values.find(lmcode);
 if (it!=m_wi_lm_values.end()){
    //cout << "wi["<<l<<","<<m<<"] got from map"<<endl;
    return it->second;}
 double res=zetaRGL_im(l,m,m_svec,m_gam,m_usq);
 res*=0.17958712212516656169/m_gam;   // multiply by 1/(gam*pi^(3/2))
 cmplx zres(res/uint_power_from_sq(m_usq,l+1));
 std::pair<std::map<uint,cmplx>::iterator,bool> rt
     =m_wi_lm_values.insert(make_pair(lmcode,zres));
 if (!(rt.second)) 
    throw(std::runtime_error("Could not insert into map"));
 //cout << "wi["<<l<<","<<m<<"] computed"<<rt.first->second<<endl;
 return rt.first->second;
}


// **********************************************************************
