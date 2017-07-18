#include "K_matrix_info.h"

using namespace std;

// ****************************************************************

KIndex::KIndex(uint L, uint Stimestwo, uint channel_index)
{
 check_encode(L,Stimestwo,channel_index);
}

KIndex::KIndex(XMLHandler& xmlin)
{
 uint L,Stimestwo,chan;
 XMLHandler xmlk(xmlin,"KIndex");
 uint count=0;
 if (xmlreadifchild(xmlk,"L",L)) count++;
 if (xmlreadifchild(xmlk,"Sx2",Stimestwo)) count++;
 if (xmlreadifchild(xmlk,"Chan",chan)) count++;
 if (count==0){
    string kstr; xmlread(xmlin,"KIndex",kstr,"KIndex");
    count=sscanf(kstr.c_str(),"L(%d) 2S(%d) chan(%d)",&L,&Stimestwo,&chan);}
 if (count!=3)
    throw(std::invalid_argument("Invalid XML for KIndex"));
 check_encode(L,Stimestwo,chan);
}
 


//   m_store encodes the channel index (6 bits),
//   total S times two (6 bits), total J times two (7 bits)
//   L (7 bits), occurrence index (6 bits)


void KIndex::check_encode(uint L, uint Stimestwo, uint channel_index)
{
 if ((channel_index>=16)||(Stimestwo>=16)||(L>=16))
    throw(std::invalid_argument("Unsupported KIndex value"));
 m_store=L;
 m_store<<=4; m_store|=Stimestwo;
 m_store<<=4; m_store|=channel_index;
}


string KIndex::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string KIndex::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void KIndex::output(XMLHandler& xmlout) const
{
 string ststr(" L("); ststr+=make_string(getL())+")";
 ststr+=" 2S("+make_string(getStimestwo())+")";
 ststr+=" chan("+make_string(getChannelIndex())+")";
 xmlout.set_root("KIndex",ststr);
}


// ****************************************************************

KElementInfo::KElementInfo(uint Jtimestwo, 
                 uint rowL, uint rowStimestwo, uint rowchannelindex,
                 uint colL, uint colStimestwo, uint colchannelindex)
{
 check_encode(Jtimestwo,rowL,rowStimestwo,rowchannelindex,
              colL,colStimestwo,colchannelindex);
}


KElementInfo::KElementInfo(uint Jtimestwo, const KIndex& row, const KIndex& col)
{
 if (row<col)
    encode(Jtimestwo,row,col);
 else
    encode(Jtimestwo,col,row);
}



KElementInfo::KElementInfo(XMLHandler& xmlin)
{
 XMLHandler xmlk(xmlin,"KElementInfo");
 uint Jtimestwo;
 xmlreadchild(xmlk,"JTimesTwo",Jtimestwo);
 list<XMLHandler> ki=xmlk.find_among_children("KIndex");
 if ((ki.size()<1)||(ki.size()>2))
    throw(std::invalid_argument("Invalid XML to KElementInfo"));
 uint rowL,rowStimestwo,rowchan,colL,colStimestwo,colchan;
 KIndex row(ki.front());
 rowL=row.getL(); rowStimestwo=row.getStimestwo();
 rowchan=row.getChannelIndex();
 if (ki.size()==1){
    colL=rowL; colStimestwo=rowStimestwo; colchan=rowchan;}
 else{
    KIndex col(*(++(ki.begin())));
    colL=col.getL(); colStimestwo=col.getStimestwo();
    colchan=col.getChannelIndex();}
 check_encode(Jtimestwo,rowL,rowStimestwo,rowchan,
              colL,colStimestwo,colchan);
}




void KElementInfo::check_encode(uint Jtimestwo, 
                 uint rowL, uint rowStimestwo, uint rowchannelindex,
                 uint colL, uint colStimestwo, uint colchannelindex)
{
 if (  (invalidJLS(Jtimestwo,rowL,rowStimestwo))
     or(invalidJLS(Jtimestwo,colL,colStimestwo)))
    throw(std::invalid_argument("Invalid JLS in KElementInfo"));
 KIndex krow(rowL,rowStimestwo,rowchannelindex);
 KIndex kcol(colL,colStimestwo,colchannelindex);
 if (krow<kcol)
    encode(Jtimestwo,krow,kcol);
 else
    encode(Jtimestwo,kcol,krow);
}


  //     m_store encodes 
  //       J (four bits)  (L'S'a') (12 bits),  (Lsa) (12 bits)
  //  Since K is real and symmetric, the (L'S'a') and (LSa)
  //  order is sorted according to how stored in "KIndex"


void KElementInfo::encode(uint Jtimestwo, 
              const KIndex& kl, const KIndex& kr)
{
 if (Jtimestwo>=16)
    throw(std::invalid_argument("Unsupported KElementInfo value"));
 m_store=Jtimestwo;
 m_store<<=12; m_store|=kl.m_store;
 m_store<<=12; m_store|=kr.m_store;
}


bool KElementInfo::invalidJLS(uint Jtimestwo, uint L, uint Stimestwo)
{
 return (((Jtimestwo%2)!=(Stimestwo%2)) 
  || ((2*L)<((Jtimestwo>=Stimestwo)?(Jtimestwo-Stimestwo):(Stimestwo-Jtimestwo)))
  || ((2*L)>(Jtimestwo+Stimestwo)));
}


string KElementInfo::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string KElementInfo::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void KElementInfo::output(XMLHandler& xmlout) const
{
 xmlout.set_root("KElementInfo");
 xmlout.put_child("JTimesTwo",make_string(getJtimestwo()));
 XMLHandler xmli; getRow().output(xmli);
 xmlout.put_child(xmli);
 getColumn().output(xmli);
 xmlout.put_child(xmli);
}


// ****************************************************************


KFitParamInfo::KFitParamInfo(XMLHandler& xmlin)
{
 XMLHandler xmlk(xmlin,"KFitParamInfo");
 uint count1=xmlk.count_among_children("PolynomialTerm");
 uint count2=xmlk.count_among_children("PoleEnergy");
 uint count3=xmlk.count_among_children("PoleCoupling");
 if ((count1+count2+count3)!=1)
    throw(std::invalid_argument("Invalid KFitParamInfo XML"));
 if (count1==1){
    XMLHandler xmlt(xmlk,"PolynomialTerm");
    uint power;
    xmlreadchild(xmlt,"Power",power);
    KElementInfo keleminfo(xmlt);
    set_poly_power(keleminfo,power);}
 else if (count2==1){
    XMLHandler xmlt(xmlk,"PoleEnergy");
    uint poleindex,Jtimestwo;
    xmlreadchild(xmlt,"Index",poleindex);
    xmlreadchild(xmlt,"JTimesTwo",Jtimestwo);
    set_pole_energy(poleindex,Jtimestwo);}
 else{
    XMLHandler xmlt(xmlk,"PoleCoupling");
    uint poleindex,Jtimestwo;
    xmlreadchild(xmlt,"Index",poleindex);
    xmlreadchild(xmlt,"JTimesTwo",Jtimestwo);
    KIndex kindex(xmlt);
    set_pole_coupling(kindex,poleindex,Jtimestwo);}
}

   //    m_store1: left-most 4 bits encode the type of parameter
   //         0 = term in a polynomial
   //         1 = pole energy
   //         2 = coupling in pole residue

   //    if polynomial: 
   //         - rightmost 28 bits of m_store1 contains "n"
   //               where parameter is coefficient of Ecm^n
   //         - m_store2 contains the m_store of the K-matrix element
   //               the polynomial is associated with

void KFitParamInfo::set_poly_power(const KElementInfo& keleminfo, uint power)
{
 if (power>32)
    throw(std::invalid_argument("Unsupported power in KFitParamInfo"));
 m_store1=power;
 m_store2=keleminfo.m_store;
}

   //    if pole energy:
   //         - rightmost 28 bits of m_store1 contain the integer index 
   //           identifying the pole (14 bits) and total J times two (14 bits)
   //         - m_store2 = 0

void KFitParamInfo::set_pole_energy(uint pole_index, uint Jtimestwo)
{
 if ((pole_index>32)||(Jtimestwo>128))
    throw(std::invalid_argument("Unsupported pole information in KFitParamInfo"));
 m_store1=1;
 m_store1<<=14; m_store1|=pole_index;
 m_store1<<=14; m_store1|=Jtimestwo;
 m_store2=0;
}

   //    if coupling in pole residue
   //         - rightmost 28 bits of m_store1 contain integer index
   //              identify the pole (14 bits) and total J times two (14 bits)
   //         - m_store2 contains m_store of the KIndex associated
   //              with this parameter

void KFitParamInfo::set_pole_coupling(const KIndex& kindex, uint pole_index, uint Jtimestwo)
{
 if ((pole_index>32)||(Jtimestwo>128))
    throw(std::invalid_argument("Unsupported pole information in KFitParamInfo"));
 m_store1=2;
 m_store1<<=14; m_store1|=pole_index;
 m_store1<<=14; m_store1|=Jtimestwo;
 m_store2=kindex.m_store;
}

string KFitParamInfo::output(int indent) const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.output(indent);
}


string KFitParamInfo::str() const
{
 XMLHandler xmlout;
 output(xmlout);
 return xmlout.str();
}


void KFitParamInfo::output(XMLHandler& xmlout) const
{
 xmlout.set_root("KFitParamInfo");
 uint type=m_store1>>28;
 if (type==0){
    uint power=m_store1 & 0xFFFFFFFu;
    KElementInfo keleminfo(m_store2);
    XMLHandler xmlt("PolynomialTerm");
    xmlt.put_child("Power",make_string(power));
    XMLHandler xmlk; keleminfo.output(xmlk);
    xmlt.put_child(xmlk);
    xmlout.put_child(xmlt);}
 else if (type==1){
    uint Jtimestwo=m_store1 & 0x3FFFu;
    uint poleindex=(m_store1>>14) & 0x3FFFu;
    XMLHandler xmlt("PoleEnergy");
    xmlt.put_child("Index",make_string(poleindex));
    xmlt.put_child("JTimesTwo",make_string(Jtimestwo));
    xmlout.put_child(xmlt);}
 else if (type==2){
    uint Jtimestwo=m_store1 & 0x3FFFu;
    uint poleindex=(m_store1>>14) & 0x3FFFu;
    XMLHandler xmlt("PoleCoupling");
    xmlt.put_child("Index",make_string(poleindex));
    xmlt.put_child("JTimesTwo",make_string(Jtimestwo));
    KIndex kindex(m_store2);
    XMLHandler xmlk; kindex.output(xmlk);
    xmlt.put_child(xmlk);
    xmlout.put_child(xmlt);}
}


// ****************************************************************
