#include "box_quant.h"
#include <fstream>
using namespace std;

//  Example driver program 1.  Needs input XML file 
//  of form given in "input1.xml".

//  Name of input XML file should be given as command argument
//  when running program.


int main(int argc, const char* argv[])
{
 if (argc!=2){
    cout << "Needs one command line argument: name of input XML file"<<endl;
    return 0;}

string fname(argv[1]);
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

uint count=0;
list<XMLHandler> testxml=xmlin.find_among_children("DoValue");
cout.precision(15);

for (list<XMLHandler>::iterator it=testxml.begin();it!=testxml.end();it++,count++){

   cout <<endl<<endl<< "Count "<<count<<endl<<endl;

   xmlread(*it,"LengthReference",L_mref,"Main");
   xmlread(*it,"LabEnergyOverReference",Elab_over_mref,"Main");
   xmlread(*it,"OmegaMu",mu,"Main");

   BQ.setRefMassL(L_mref);
   cout << "ref mass times L = "<<BQ.getRefMassL() <<endl;

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

   double Ecm=BQ.getEcmOverMrefFromElab(Elab_over_mref);
   cout << "     Elab/mref = "<<Elab_over_mref<<endl;
   cout << "      Ecm/mref = "<<Ecm<<endl;
   cout << "            mu = "<<mu<<endl;
   cout << "         Omega = "<< BQ.getOmegaFromElab(mu,Elab_over_mref)<<endl<<endl;
   }

return 0;
}
