#include "box_quant.h"
#include <fstream>
using namespace std;

//  Example driver program 2.  This done exactly the same things
//  as "driver1.cc", but does not need an XML input program.
//  The quantities are built up in the code.


int main()
{

set<uint> powers; powers.insert(1); powers.insert(3);
list<pair<KElementInfo,Polynomial> > pelems;
pelems.push_back(make_pair( KElementInfo(2,  1,0,0, 1,0,0), Polynomial(powers) ));
pelems.push_back(make_pair( KElementInfo(6,  3,0,0, 3,0,0), Polynomial(0) ));
pelems.push_back(make_pair( KElementInfo(10, 5,0,0, 5,0,0), Polynomial(0) ));
KtildeInverseCalculator Kinv(pelems);
cout << Kinv.output()<<endl;

vector<double> Kpars;
Kpars.resize(Kinv.getNumberOfParameters());
Kinv.setKtildeParameters(Kpars);

string mom_ray("ar");
uint mom_int_sq=0;
string lgirrep("T1u");
vector<DecayChannelInfo> chan_infos;
vector<uint> lmaxes;
chan_infos.push_back(DecayChannelInfo("pion","pion",0,0,false,true));
lmaxes.push_back(5);

BoxQuantization BQ(mom_ray,mom_int_sq,lgirrep,chan_infos,lmaxes,&Kinv, true);
cout << BQ.output()<<endl;
cout << BQ.outputBasis(2)<<endl;

double Elab_over_mref, Ecm, L_mref, mu, m1, m2;
uint chan=0;
cout.precision(15);

L_mref=6.63; Elab_over_mref=3.81234; mu=8.0;  m1=0.673; m2=1.527;
cout <<endl<<endl<< "Count 0"<<endl<<endl;
BQ.setRefMassL(L_mref);
BQ.setMassesOverRef(chan,m1,m2);
cout << "ref mass times L = "<<BQ.getRefMassL() <<endl;
cout << "channel "<<chan<<": mass1 = "<<BQ.getMass1OverRef(chan)<<"   "
     << "mass2 = "<<BQ.getMass2OverRef(chan)<<endl;
Ecm=BQ.getEcmOverMrefFromElab(Elab_over_mref);
cout << "     Elab/mref = "<<Elab_over_mref<<endl;
cout << "      Ecm/mref = "<<Ecm<<endl;
cout << "            mu = "<<mu<<endl;
cout << "         Omega = "<< BQ.getOmegaFromElab(mu,Elab_over_mref)<<endl<<endl;

L_mref=6.63; Elab_over_mref=4.452; mu=8.0;  m1=1.00; m2=1.00;
cout <<endl<<endl<< "Count 1"<<endl<<endl;
BQ.setRefMassL(L_mref);
BQ.setMassesOverRef(chan,m1,m2);
cout << "ref mass times L = "<<BQ.getRefMassL() <<endl;
cout << "channel "<<chan<<": mass1 = "<<BQ.getMass1OverRef(chan)<<"   "
     << "mass2 = "<<BQ.getMass2OverRef(chan)<<endl;
Ecm=BQ.getEcmOverMrefFromElab(Elab_over_mref);
cout << "     Elab/mref = "<<Elab_over_mref<<endl;
cout << "      Ecm/mref = "<<Ecm<<endl;
cout << "            mu = "<<mu<<endl;
cout << "         Omega = "<< BQ.getOmegaFromElab(mu,Elab_over_mref)<<endl<<endl;


return 0;
}
