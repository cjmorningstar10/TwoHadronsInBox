#include "box_quant.h"
#include <fstream>
using namespace std;

//  driver program.  XML input from file "input1.xml"


int main(){

string fname("input1.xml");
XMLHandler xmlin;
xmlin.set_from_file(fname);

KtildeMatrixCalculator *Kmat=0;
KtildeInverseCalculator *Kinv=0;

int k1=xmlin.count_among_children("KtildeMatrix");
int k2=xmlin.count_among_children("KtildeMatrixInverse");
if ((k1+k2)!=1)
   throw(std::invalid_argument("A single KtildeMatrix or KtildeMatrixInverse tag must be present"));
if (k1==1){
   Kmat=new KtildeMatrixCalculator(xmlin);}
else{
   Kinv=new KtildeInverseCalculator(xmlin);}

if (Kmat!=0) cout <<Kmat->output()<<endl;
else cout <<Kinv->output()<<endl;

XMLHandler xmlb(xmlin,"BoxQuantization");

BoxQuantization BQ(xmlin,Kmat,Kinv);
cout << BQ.output()<<endl;
cout << BQ.outputBasis(2)<<endl;

double Elab_over_mref, L_mref, mu;
uint Ndet;

uint count=0;
list<XMLHandler> testxml=xmlin.find_among_children("ATest");
uint ntests=testxml.size();
vector<ComplexHermitianMatrix> Bs(ntests);
vector<RealSymmetricMatrix> Kvs(ntests);

for (list<XMLHandler>::iterator it=testxml.begin();it!=testxml.end();it++,count++){

   cout <<endl<<endl<< "Count "<<count<<endl<<endl;

   xmlread(*it,"LengthReference",L_mref,"Main");
   xmlread(*it,"LabEnergyOverReference",Elab_over_mref,"Main");
   xmlread(*it,"DetRoot",Ndet,"Main");
   xmlread(*it,"OmegaMu",mu,"Main");

   BQ.setRefMassL(L_mref);
   cout << "ref mass times L = "<<BQ.getRefMassL() <<endl;
   cout << "Ndet = "<<Ndet<<endl;
   cout << "mu = "<<mu<<endl;

   XMLHandler xmlch(*it,"ChannelMasses");
   list<XMLHandler> xmlm=xmlch.find("DecayChannel");
   uint chan=0;
   for (list<XMLHandler>::iterator it=xmlm.begin();it!=xmlm.end();it++,chan++){
      double m1,m2;
      xmlread(*it,"Mass1OverRef",m1,"Main");
      xmlread(*it,"Mass2OverRef",m2,"Main");
      BQ.setMassesOverRef(chan,m1,m2);
      cout << "channel "<<chan<<": mass1 = "<<BQ.getMass1OverRef(chan)<<"   "
           << "mass2 = "<<BQ.getMass2OverRef(chan)<<endl;}

   cout.precision(15);
   double Ecm=BQ.getEcmOverMrefFromElab(Elab_over_mref);
   cout << "Ecm = "<<Ecm<<endl;
   
   string outputfile("quant_maple");
   outputfile+=make_string(count)+string(".mpl");
   ofstream fout(outputfile);
   BQ.outputKBMatricesFromElab(Elab_over_mref,fout);
   fout << "Ndet:="<<Ndet<<":"<<endl;
   fout << "mu:="<<mu<<":"<<endl;
   fout.close();

   cout << "Determinant root = "<< BQ.getDeterminantRootFromElab(Elab_over_mref,Ndet)<<endl;
   cout << "Determinant root = "<< BQ.getDeterminantRootFromEcm(Ecm,Ndet)<<endl;
   cout << "Omega = "<< BQ.getOmegaFromElab(mu,Elab_over_mref)<<endl;
   cout << "Omega = "<< BQ.getOmegaFromEcm(mu,Ecm)<<endl;

   vector<double> lam=BQ.getEigenvaluesFromElab(Elab_over_mref);
   vector<double> lam2=BQ.getEigenvaluesFromEcm(Ecm);
   for (uint k=0;k<lam.size();k++){
      cout << " lam["<<k<<"] = "<<lam[k]<<endl;
      cout << "lam2["<<k<<"] = "<<lam2[k]<<endl;}
   double detrt=1.0;
   for (uint k=0;k<lam.size();k++){
      detrt*=std::pow(std::abs(lam[k]),1.0/double(Ndet))*((lam[k]>0.0)?1.0:-1.0);}

   BQ.getBoxMatrixFromElab(Elab_over_mref,Bs[count]);
   BQ.getKtildeOrInverseFromEcm(Ecm,Kvs[count]);

   double detBrt=BQ.getBoxMatrixDeterminantRootFromElab(Elab_over_mref,Ndet);
   cout << "detBroot = "<<detBrt<<endl;
   cout << "detBroot = "<<BQ.getBoxMatrixDeterminantRootFromEcm(Ecm,Ndet)<<endl;
   cout << "detBroot = "<<BQ.getBoxMatrixDeterminantRoot(Bs[count],Ndet)<<endl;

//   if (BQ.isKtildeMode()) detrt/=detBrt;
   cout << "detroot = "<<detrt<<endl;

   }

cout <<endl<<endl<<"Ndet = "<<Ndet<<endl;
for (uint j=0;j<ntests;j++)
for (uint k=0;k<ntests;k++)
    cout <<"DetRoot["<<j<<","<<k<<"] = "<< BQ.getDeterminantRoot(Kvs[j],Bs[k],Ndet)<<endl;

cout <<endl<<endl<<"mu = "<<mu<<endl;
for (uint j=0;j<ntests;j++)
for (uint k=0;k<ntests;k++)
    cout <<"Omega["<<j<<","<<k<<"] = "<< BQ.getOmega(mu,Kvs[j],Bs[k])<<endl;

return 0;
}
