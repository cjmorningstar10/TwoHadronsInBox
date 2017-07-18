#include "box_matrix.h"
using namespace std;

            //  evaluator and quantum number setup subroutines    
            //  at rest (total momentum zero)

#if (AR_LMAX>=0)


#if (AR_SX2MAX>=0)
void BoxMatrix::setup___ar_0_A1g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=0)
 if (lmax>=0){
    quantnums.push_back(BoxMatrixQuantumNumbers(0,0,1,0,0,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(0,0,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(0,0,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::evaluate___ar_0_A1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=0)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = 0.130930734141595428e1 * wr_4_0;
 results[k++] = wr_0_0 + 0.755244755244755245e0 * wr_4_0 + 0.201709162263719681e1 * wr_6_0 
             + 0.949789860282143113e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = -0.282842712474619010e1 * wr_6_0;
 results[k++] = -0.933731983660173633e0 * wr_4_0 + 0.145556742958893117e1 * wr_6_0 
             - 0.467229483932561166e0 * wr_8_0 - 0.122405612519683903e1 * wr_10_0;
 results[k++] = wr_0_0 - 0.673796791443850267e0 * wr_4_0 - 0.162366508323737204e0 * wr_6_0 
             + 0.974784330289567934e0 * wr_8_0 - 0.124356879809274107e1 * wr_10_0 
             + 0.820891102436397900e0 * wr_12_0 - 0.157405043220569014e1 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::setup___ar_0_A2g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::evaluate___ar_0_A2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=6)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = wr_0_0 + 0.352941176470588235e0 * wr_4_0 - 0.178603159156110924e1 * wr_6_0 
             - 0.510601315865964156e0 * wr_8_0 - 0.159887416897638138e1 * wr_10_0 
             + 0.266523085206622695e0 * wr_12_0 + 0.112432173728977867e1 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::setup___ar_0_A2u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,3,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::evaluate___ar_0_A2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=3)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = wr_0_0 - 0.109090909090909091e1 * wr_4_0 + 0.201709162263719681e1 * wr_6_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::setup___ar_0_Eg(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,4,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::evaluate___ar_0_Eg(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 + 0.857142857142857143e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.899766653282533658e0 * wr_4_0 - 0.131013944022344018e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.107892107892107892e0 * wr_4_0 - 0.161367329810975744e1 * wr_6_0 
             + 0.664852902197500178e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.904082105634267101e0 * wr_4_0 + 0.608480019297509491e0 * wr_6_0 
             + 0.900477500277928840e0 * wr_8_0;
 results[k++] = -0.417577637645974228e0 * wr_4_0 - 0.139489187931235238e1 * wr_6_0 
             - 0.597003935523058590e0 * wr_8_0 - 0.821121811264537568e0 * wr_10_0;
 results[k++] = wr_0_0 + 0.609625668449197861e0 * wr_4_0 + 0.487099524971211612e0 * wr_6_0 
             + 0.324928110096522644e0 * wr_8_0 + 0.710610741767280614e0 * wr_10_0 
             + 0.820891102436397900e0 * wr_12_0 + 0.224864347457955735e0 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::setup___ar_0_Eu(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::evaluate___ar_0_Eu(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=5)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = wr_0_0 - 0.461538461538461538e0 * wr_4_0 + 0.522070772917862704e0 * wr_6_0 
             - 0.659854008196015215e0 * wr_8_0 + 0.125723438928057340e1 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::setup___ar_0_T1g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::evaluate___ar_0_T1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=4)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = wr_0_0 + 0.377622377622377622e0 * wr_4_0 - 0.100854581131859840e0 * wr_6_0 
             - 0.759831888225714491e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = -0.676553097759318853e0 * wr_4_0 + 0.502218476229899290e0 * wr_6_0 
             + 0.806047437927905811e-1 * wr_8_0 + 0.101361476964046979e1 * wr_10_0;
 results[k++] = wr_0_0 - 0.513368983957219251e0 * wr_4_0 - 0.811832541618686021e-1 * wr_6_0 
             + 0.139254904327081133e0 * wr_8_0 + 0.384914151790610333e0 * wr_10_0 
             - 0.703620944945483914e0 * wr_12_0 + 0.134918608474773441e1 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::setup___ar_0_T1u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,2,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,10,5,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::evaluate___ar_0_T1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = 0.872871560943969523e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.545454545454545455e0 * wr_4_0 + 0.840454842765498668e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.957460353484693581e0 * wr_4_0 + 0.371772412169085734e0 * wr_6_0;
 results[k++] = -0.188813728012340256e0 * wr_4_0 + 0.188523021561231925e1 * wr_6_0;
 results[k++] = 0.337510349597137224e0 * wr_4_0 + 0.851837610030578529e0 * wr_6_0 
             + 0.865878733146398095e0 * wr_8_0;
 results[k++] = 0.741645600740016947e0 * wr_4_0 - 0.111989761404128896e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.597285067873303167e0 * wr_4_0 + 0.844526250308307314e0 * wr_6_0 
             + 0.307284954797163949e0 * wr_8_0 + 0.409833759250775150e0 * wr_10_0;
 results[k++] = -0.917814575270787234e-1 * wr_4_0 - 0.681311546692623108e0 * wr_6_0 
             + 0.318933738373014214e0 * wr_8_0 + 0.962551629216992021e0 * wr_10_0;
 results[k++] = -0.917814575270787234e-1 * wr_4_0 - 0.681311546692623108e0 * wr_6_0 
             + 0.318933738373014214e0 * wr_8_0 + 0.962551629216992021e0 * wr_10_0;
 results[k++] = wr_0_0 - 0.597285067873303167e0 * wr_4_0 + 0.112603500041107642e0 * wr_6_0 
             + 0.407556887415185868e0 * wr_8_0 - 0.776527122790942392e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::setup___ar_0_T2g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,4,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,12,6,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::evaluate___ar_0_T2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 - 0.571428571428571429e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = -0.449883326641266828e0 * wr_4_0 + 0.174685258696458690e1 * wr_6_0;
 results[k++] = wr_0_0 - 0.701298701298701299e0 * wr_4_0 + 0.504272905659299201e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.534255422861975530e0 * wr_4_0 - 0.161807966991178101e1 * wr_6_0 
             - 0.967500597749501105e-1 * wr_8_0;
 results[k++] = 0.684370371966191773e0 * wr_4_0 + 0.727272727272727273e0 * wr_6_0 
             - 0.717517646929399964e0 * wr_8_0;
 results[k++] = 0.185071507323227349e0 * wr_4_0 - 0.137382166616739348e0 * wr_6_0 
             - 0.595335857561785023e0 * wr_8_0 + 0.129394967636797587e1 * wr_10_0;
 results[k++] = -0.374325554349554337e0 * wr_4_0 - 0.114852566919005767e1 * wr_6_0 
             + 0.392455900992311927e0 * wr_8_0 + 0.436190346920822969e0 * wr_10_0;
 results[k++] = wr_0_0 - 0.268907563025210084e0 * wr_4_0 + 0.893015795780554622e0 * wr_6_0 
             - 0.559230012615103599e0 * wr_8_0 - 0.634473876577929119e-1 * wr_10_0 
             + 0.352318135492183143e0 * wr_12_0 - 0.706716520582146596e0 * wr_12_4;
 results[k++] = -0.602289178058106667e0 * wr_10_0 + 0.903106690039128915e0 * wr_6_0 
             + 0.983563819801095610e-1 * wr_8_0 - 0.391552690540350600e0 * wr_12_0 
             + 0.226621802508652802e0 * wr_4_0 + 0.519783470156710070e0 * wr_12_4;
 results[k++] = -0.602289178058106667e0 * wr_10_0 + 0.903106690039128915e0 * wr_6_0 
             + 0.983563819801095610e-1 * wr_8_0 - 0.391552690540350600e0 * wr_12_0 
             + 0.226621802508652802e0 * wr_4_0 + 0.519783470156710070e0 * wr_12_4;
 results[k++] = wr_0_0 + 0.482811306340718105e0 * wr_4_0 - 0.487099524971211612e0 * wr_6_0 
             + 0.486286967491394431e-1 * wr_8_0 + 0.152273730378702989e0 * wr_10_0 
             - 0.558429321385304694e0 * wr_12_0 - 0.642469564165587813e0 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::setup___ar_0_T2u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=0)
void BoxMatrix::evaluate___ar_0_T2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=3)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = wr_0_0 - 0.181818181818181818e0 * wr_4_0 - 0.151281871697789760e1 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = -0.463863607042713265e0 * wr_4_0 - 0.117073881400992708e1 * wr_6_0 
             + 0.630019319247989485e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.307692307692307692e0 * wr_4_0 - 0.130517693229465676e1 * wr_6_0 
             - 0.274939170081673006e0 * wr_8_0 - 0.471462895980215024e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::setup___ar_1_G1g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=0)
 if (lmax>=0){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,0,1,1,0,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,0,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,0,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,9,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,0,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,0,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::evaluate___ar_1_G1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=0)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.872871560943969523e0 * wr_4_0;
 results[k++] = 0.975900072948533181e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.545454545454545455e0 * wr_4_0 + 0.840454842765498668e0 * wr_6_0;
 results[k++] = -0.187642068041940394e0 * wr_4_0 - 0.105241592984782933e1 * wr_6_0 
             - 0.849517876772359836e0 * wr_8_0;
 results[k++] = -0.187642068041940394e0 * wr_4_0 - 0.105241592984782933e1 * wr_6_0 
             - 0.849517876772359836e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.587412587412587413e0 * wr_4_0 + 0.107578219873983830e1 * wr_6_0 
             + 0.189957972056428623e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.192153784566104560e1 * wr_6_0;
 results[k++] = -0.207549808665108331e1 * wr_6_0;
 results[k++] = -0.792932460858518658e0 * wr_4_0 + 0.933926490897709026e0 * wr_6_0 
             - 0.167527184538488964e0 * wr_8_0;
 results[k++] = 0.276022653573735937e0 * wr_8_0 - 0.491370145796497878e0 * wr_6_0 
             + 0.141844070723667118e0 * wr_4_0 + 0.111568484295605893e1 * wr_10_0;
 results[k++] = 0.114195326003877767e0 * wr_4_0 - 0.457754779579312507e0 * wr_6_0 
             + 0.269384270801751066e0 * wr_8_0 + 0.111207154529504140e1 * wr_10_0;
 results[k++] = -0.219040560575246240e0 * wr_8_0 + 0.102357080416477535e1 * wr_6_0 
             - 0.210410332941172608e0 * wr_10_0 - 0.817115237303744318e0 * wr_4_0;
 results[k++] = -0.118652448390423341e0 * wr_6_0 + 0.524883870155921194e0 * wr_8_0 
             - 0.366693363540167240e0 * wr_10_0 + wr_0_0 - 0.587412587412587413e0 * wr_4_0;
 results[k++] = 0.145728752819169980e1 * wr_12_4 + 0.799762323949962181e-1 * wr_4_0 
             - 0.759997482360065668e0 * wr_12_0 + 0.404713553289239347e-1 * wr_6_0 
             - 0.416526888888649633e0 * wr_8_0 + 0.811828902305563328e0 * wr_10_0;
 results[k++] = 0.145728752819169980e1 * wr_12_4 + 0.799762323949962181e-1 * wr_4_0 
             - 0.759997482360065668e0 * wr_12_0 + 0.404713553289239347e-1 * wr_6_0 
             - 0.416526888888649633e0 * wr_8_0 + 0.811828902305563328e0 * wr_10_0;
 results[k++] = -0.124897314095182465e0 * wr_6_0 + 0.589155364460727869e0 * wr_8_0 
             - 0.491961282761963500e0 * wr_10_0 + wr_0_0 - 0.599753187988482106e0 * wr_4_0 
             + 0.117270157490913986e0 * wr_12_0 - 0.224864347457955735e0 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::setup___ar_1_G1u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,1,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,7,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,11,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::evaluate___ar_1_G1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = -0.872871560943969523e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.545454545454545455e0 * wr_4_0 + 0.840454842765498668e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.975900072948533181e0 * wr_4_0;
 results[k++] = 0.192153784566104560e1 * wr_6_0;
 results[k++] = -0.187642068041940394e0 * wr_4_0 - 0.105241592984782933e1 * wr_6_0 
             - 0.849517876772359836e0 * wr_8_0;
 results[k++] = -0.792932460858518658e0 * wr_4_0 + 0.933926490897709026e0 * wr_6_0 
             - 0.167527184538488964e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.587412587412587413e0 * wr_4_0 + 0.107578219873983830e1 * wr_6_0 
             + 0.189957972056428623e0 * wr_8_0;
 results[k++] = 0.276022653573735937e0 * wr_8_0 - 0.491370145796497878e0 * wr_6_0 
             + 0.141844070723667118e0 * wr_4_0 + 0.111568484295605893e1 * wr_10_0;
 results[k++] = 0.276022653573735937e0 * wr_8_0 - 0.491370145796497878e0 * wr_6_0 
             + 0.141844070723667118e0 * wr_4_0 + 0.111568484295605893e1 * wr_10_0;
 results[k++] = -0.118652448390423341e0 * wr_6_0 + 0.524883870155921194e0 * wr_8_0 
             - 0.366693363540167240e0 * wr_10_0 + wr_0_0 - 0.587412587412587413e0 * wr_4_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::setup___ar_1_G2g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,5,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,7,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,13,6,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::evaluate___ar_1_G2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 - 0.571428571428571429e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = -0.174685258696458690e1 * wr_6_0 + 0.449883326641266828e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.701298701298701299e0 * wr_4_0 + 0.504272905659299201e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.476249839970396865e0 * wr_8_0 - 0.350647927568116765e0 * wr_4_0 
             - 0.884995357737419554e0 * wr_6_0;
 results[k++] = 0.538546700015016549e0 * wr_4_0 + 0.362461445012065531e0 * wr_6_0 
             - 0.520144966255374709e0 * wr_8_0;
 results[k++] = -0.163790878039425522e0 * wr_8_0 + 0.583785187956745341e0 * wr_4_0 
             - 0.149415941441317134e1 * wr_6_0;
 results[k++] = -0.303670013058354917e0 * wr_4_0 - 0.766428462031902497e0 * wr_6_0 
             + 0.412444459962637232e0 * wr_8_0;
 results[k++] = -0.222265832776852350e0 * wr_8_0 + 0.830913933369348937e0 * wr_6_0 
             - 0.434781004474398071e0 * wr_10_0 + 0.248744065779883549e0 * wr_4_0;
 results[k++] = -0.142414874119328111e0 * wr_4_0 + 0.245264184937118472e0 * wr_6_0 
             + 0.537525705942194151e0 * wr_8_0 - 0.129442391119290237e1 * wr_10_0;
 results[k++] = wr_0_0 + 0.307692307692307692e0 * wr_4_0 - 0.130517693229465676e1 * wr_6_0 
             - 0.274939170081673006e0 * wr_8_0 - 0.471462895980215024e0 * wr_10_0;
 results[k++] = -0.892709048414806787e0 * wr_10_0 - 0.268106999246486734e0 * wr_8_0 
             + 0.885539807103108004e0 * wr_12_4 - 0.492350816065567021e0 * wr_6_0 
             - 0.555968013362272780e-1 * wr_4_0 + 0.371137274274696145e0 * wr_12_0;
 results[k++] = -0.297090800658261781e0 * wr_4_0 + 0.329983482046604409e0 * wr_12_0 
             - 0.632740007772760404e0 * wr_12_4 + 0.620379193667145091e0 * wr_10_0 
             - 0.676532283310745401e-1 * wr_6_0 - 0.112976622695966655e0 * wr_8_0;
 results[k++] = -0.892709048414806787e0 * wr_10_0 - 0.268106999246486734e0 * wr_8_0 
             + 0.885539807103108004e0 * wr_12_4 - 0.492350816065567021e0 * wr_6_0 
             - 0.555968013362272780e-1 * wr_4_0 + 0.371137274274696145e0 * wr_12_0;
 results[k++] = -0.779379523228630353e0 * wr_10_0 - 0.979436679243188943e0 * wr_6_0 
             - 0.214123132459920452e0 * wr_8_0 + 0.282893856479363666e0 * wr_12_4 + wr_0_0 
             + 0.444022770398481973e0 * wr_4_0 - 0.204391682117594953e0 * wr_12_0;
 results[k++] = 0.109509687218609874e0 * wr_4_0 - 0.322856085159836687e0 * wr_12_0 
             + 0.103103983874452310e0 * wr_8_0 - 0.155915444273328215e0 * wr_10_0 
             + 0.697703356774230436e-1 * wr_12_4 + 0.969789314732298067e0 * wr_6_0;
 results[k++] = -0.297090800658261781e0 * wr_4_0 + 0.329983482046604409e0 * wr_12_0 
             - 0.632740007772760404e0 * wr_12_4 + 0.620379193667145091e0 * wr_10_0 
             - 0.676532283310745401e-1 * wr_6_0 - 0.112976622695966655e0 * wr_8_0;
 results[k++] = 0.109509687218609874e0 * wr_4_0 - 0.322856085159836687e0 * wr_12_0 
             + 0.103103983874452310e0 * wr_8_0 - 0.155915444273328215e0 * wr_10_0 
             + 0.697703356774230436e-1 * wr_12_4 + 0.969789314732298067e0 * wr_6_0;
 results[k++] = 0.904498290786079462e0 * wr_6_0 - 0.532140329190334853e0 * wr_8_0 
             - 0.259205407046625931e0 * wr_10_0 + wr_0_0 - 0.184870158304693409e0 * wr_4_0 
             + 0.264803581431096097e0 * wr_12_0 - 0.507758203937319402e0 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::setup___ar_1_G2u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,7,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,11,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::evaluate___ar_1_G2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=3)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = wr_0_0 - 0.571428571428571429e0 * wr_4_0;
 results[k++] = -0.174685258696458690e1 * wr_6_0 + 0.449883326641266828e0 * wr_4_0;
 results[k++] = -0.174685258696458690e1 * wr_6_0 + 0.449883326641266828e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.701298701298701299e0 * wr_4_0 + 0.504272905659299201e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.476249839970396865e0 * wr_8_0 - 0.350647927568116765e0 * wr_4_0 
             - 0.884995357737419554e0 * wr_6_0;
 results[k++] = -0.303670013058354917e0 * wr_4_0 - 0.766428462031902497e0 * wr_6_0 
             + 0.412444459962637232e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.307692307692307692e0 * wr_4_0 - 0.130517693229465676e1 * wr_6_0 
             - 0.274939170081673006e0 * wr_8_0 - 0.471462895980215024e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::setup___ar_1_Hg(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,3,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,3,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,5,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,5,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,9,4,2));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,13,6,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::evaluate___ar_1_Hg(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0;
 results[k++] = 0.699854212223765171e0 * wr_4_0;
 results[k++] = 0.699854212223765171e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.285714285714285714e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.521640530957301061e0 * wr_4_0;
 results[k++] = -0.348478126363603589e0 * wr_4_0 - 0.112758849626553142e1 * wr_6_0;
 results[k++] = -0.406557814090870854e0 * wr_4_0 + 0.338276548879659426e0 * wr_6_0;
 results[k++] = -0.142265599351991199e0 * wr_4_0 - 0.966705759488954500e0 * wr_6_0;
 results[k++] = -0.887181884498666528e-1 * wr_4_0 - 0.155017789106946847e1 * wr_6_0;
 results[k++] = -0.651942877818760169e0 * wr_4_0 + 0.210952491314662323e0 * wr_6_0;
 results[k++] = wr_0_0 + 0.779220779220779221e-1 * wr_4_0 - 0.672363874212398935e0 * wr_6_0;
 results[k++] = -0.293645124009971400e0 * wr_4_0 - 0.288215972327715282e0 * wr_6_0 
             + 0.542850121464134724e0 * wr_8_0;
 results[k++] = 0.224275168038398085e0 * wr_4_0 - 0.817620458377699485e0 * wr_6_0 
             + 0.355378824660767050e0 * wr_8_0;
 results[k++] = -0.293645124009971400e0 * wr_4_0 - 0.288215972327715282e0 * wr_6_0 
             + 0.542850121464134724e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.629370629370629371e-1 * wr_4_0 - 0.201709162263719681e0 * wr_6_0 
             - 0.332426451098750089e0 * wr_8_0;
 results[k++] = 0.343349827294393607e0 * wr_4_0 - 0.616231669626417006e0 * wr_6_0 
             + 0.725413988174075357e-1 * wr_8_0;
 results[k++] = 0.224275168038398085e0 * wr_4_0 - 0.817620458377699485e0 * wr_6_0 
             + 0.355378824660767050e0 * wr_8_0;
 results[k++] = 0.343349827294393607e0 * wr_4_0 - 0.616231669626417006e0 * wr_6_0 
             + 0.725413988174075357e-1 * wr_8_0;
 results[k++] = wr_0_0 - 0.356643356643356643e0 * wr_4_0 - 0.336181937106199468e0 * wr_6_0 
             + 0.237447465070535778e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.841654636156864964e0 * wr_4_0 + 0.326806194281060772e0 * wr_6_0;
 results[k++] = 0.105724328114469154e0 * wr_4_0 + 0.266836140256488293e0 * wr_6_0 
             + 0.789771012824305115e0 * wr_8_0;
 results[k++] = 0.266154565349599958e0 * wr_4_0 - 0.103345192737964565e1 * wr_6_0;
 results[k++] = -0.217314292606253389e0 * wr_4_0 + 0.843809965258649291e0 * wr_6_0;
 results[k++] = 0.926438002785050983e0 * wr_6_0 + 0.490997898022496292e-1 * wr_8_0;
 results[k++] = 0.255434531033839350e0 * wr_4_0 - 0.584516765871072240e0 * wr_6_0 
             + 0.214326294584428938e0 * wr_8_0;
 results[k++] = -0.570183175313635682e-1 * wr_6_0 + 0.797777156026058151e0 * wr_8_0;
 results[k++] = 0.817487249086610008e0 * wr_4_0 + 0.596753804123634368e0 * wr_6_0 
             + 0.162845580059380376e0 * wr_8_0;
 results[k++] = -0.354610176809167795e0 * wr_4_0 - 0.894995622700763991e0 * wr_6_0 
             - 0.214058384404121748e0 * wr_8_0;
 results[k++] = -0.115815198770744764e0 * wr_4_0 - 0.859718665741711648e0 * wr_6_0 
             - 0.120734760482975128e0 * wr_8_0 - 0.759127383055424236e-1 * wr_10_0;
 results[k++] = -0.342504301239655061e0 * wr_8_0 - 0.844841397348696016e0 * wr_10_0;
 results[k++] = 0.336412752057597128e0 * wr_4_0 - 0.188681644241007573e0 * wr_6_0 
             - 0.236919216440511367e0 * wr_8_0;
 results[k++] = 0.244680221763430283e0 * wr_6_0 - 0.213806228093411684e0 * wr_8_0 
             + 0.960228625863300786e0 * wr_10_0 - 0.228899884862929071e0 * wr_4_0;
 results[k++] = -0.209790209790209790e0 * wr_4_0 + 0.415283569366481695e-1 * wr_6_0 
             + 0.393246328116817149e0 * wr_8_0 - 0.628617194640286698e0 * wr_10_0;
 results[k++] = -0.508787759614378005e0 * wr_6_0 + 0.489954578929328284e-1 * wr_8_0 
             - 0.865235909512705278e0 * wr_10_0 + 0.182774072061582215e0 * wr_4_0;
 results[k++] = -0.522320417221818925e0 * wr_4_0 + 0.830846932286034823e-1 * wr_6_0 
             + 0.206690556561268114e0 * wr_8_0 + 0.187484189096530958e0 * wr_10_0;
 results[k++] = -0.397202470044171409e0 * wr_8_0 + 0.514073252739369151e0 * wr_10_0;
 results[k++] = -0.300611730830246983e0 * wr_6_0 - 0.375927593709637587e0 * wr_8_0 
             - 0.511215255123733988e0 * wr_10_0 - 0.110614837458585444e0 * wr_4_0;
 results[k++] = 0.321465994623904169e-1 * wr_4_0 - 0.511350938353463646e-2 * wr_6_0 
             - 0.295453727750027569e0 * wr_8_0 - 0.463560924668510281e0 * wr_10_0;
 results[k++] = -0.371793044986049154e0 * wr_4_0 - 0.124195132229646562e1 * wr_6_0 
             - 0.752188373206320078e-1 * wr_8_0 - 0.722552049835772213e-1 * wr_10_0;
 results[k++] = wr_0_0 + 0.531468531468531469e0 * wr_4_0 + 0.355957345171270024e0 * wr_6_0 
             + 0.174961290051973731e0 * wr_8_0 + 0.209539064880095566e0 * wr_10_0;
 results[k++] = 0.884553191655490724e-1 * wr_4_0 + 0.656620977021305295e0 * wr_6_0 
             - 0.790394541322280911e-1 * wr_8_0 - 0.364441387091594360e0 * wr_10_0;
 results[k++] = -0.408378200597669717e0 * wr_6_0 + 0.812837831159613022e-1 * wr_8_0 
             - 0.329261787871247418e0 * wr_12_4 + 0.277339918677106273e0 * wr_10_0 
             + 0.198769483933514504e0 * wr_4_0 + 0.226663801735574650e0 * wr_12_0;
 results[k++] = 0.120064104674212667e0 * wr_8_0 + 0.399362566353400808e0 * wr_10_0 
             + 0.320992249181413544e0 * wr_12_4 + 0.725410017973569501e0 * wr_12_0 
             + 0.137014259975985409e-1 * wr_4_0 + 0.254806158429950229e0 * wr_6_0;
 results[k++] = 0.884553191655490724e-1 * wr_4_0 + 0.656620977021305295e0 * wr_6_0 
             - 0.790394541322280911e-1 * wr_8_0 - 0.364441387091594360e0 * wr_10_0;
 results[k++] = 0.355957345171270024e0 * wr_6_0 - 0.299933640089097825e0 * wr_8_0 
             + 0.209539064880095566e0 * wr_10_0 + wr_0_0 - 0.391608391608391608e0 * wr_4_0;
 results[k++] = -0.222656079422374490e0 * wr_6_0 + 0.337064367131500768e0 * wr_8_0 
             - 0.564730933076615260e0 * wr_12_0 - 0.804562302164672660e-1 * wr_4_0 
             + 0.696052245321847803e-1 * wr_10_0 + 0.108286588397763938e1 * wr_12_4;
 results[k++] = -0.286547951697645744e-1 * wr_8_0 + 0.331745636794163242e0 * wr_10_0 
             + 0.176457530330781644e0 * wr_12_0 - 0.338355539557861937e0 * wr_12_4 
             - 0.567326323988454999e0 * wr_6_0 - 0.606587986825185634e-1 * wr_4_0;
 results[k++] = -0.408378200597669717e0 * wr_6_0 + 0.812837831159613022e-1 * wr_8_0 
             - 0.329261787871247418e0 * wr_12_4 + 0.277339918677106273e0 * wr_10_0 
             + 0.198769483933514504e0 * wr_4_0 + 0.226663801735574650e0 * wr_12_0;
 results[k++] = -0.222656079422374490e0 * wr_6_0 + 0.337064367131500768e0 * wr_8_0 
             - 0.564730933076615260e0 * wr_12_0 - 0.804562302164672660e-1 * wr_4_0 
             + 0.696052245321847803e-1 * wr_10_0 + 0.108286588397763938e1 * wr_12_4;
 results[k++] = 0.389340428181637782e0 * wr_10_0 + 0.285142924632397702e-1 * wr_6_0 
             - 0.111902465451031332e0 * wr_8_0 + 0.394573288935658175e0 * wr_12_4 + wr_0_0 
             - 0.388798770596772817e0 * wr_4_0 - 0.177346807640633215e0 * wr_12_0;
 results[k++] = -0.168624394422195538e0 * wr_10_0 + 0.266344014647437637e0 * wr_12_4 
             + 0.576511292192755788e-1 * wr_8_0 + 0.539402707330648918e0 * wr_6_0 
             + 0.920569053609993493e-1 * wr_12_0 + 0.119171647545943241e0 * wr_4_0;
 results[k++] = 0.120064104674212667e0 * wr_8_0 + 0.399362566353400808e0 * wr_10_0 
             + 0.320992249181413544e0 * wr_12_4 + 0.725410017973569501e0 * wr_12_0 
             + 0.137014259975985409e-1 * wr_4_0 + 0.254806158429950229e0 * wr_6_0;
 results[k++] = -0.286547951697645744e-1 * wr_8_0 + 0.331745636794163242e0 * wr_10_0 
             + 0.176457530330781644e0 * wr_12_0 - 0.338355539557861937e0 * wr_12_4 
             - 0.567326323988454999e0 * wr_6_0 - 0.606587986825185634e-1 * wr_4_0;
 results[k++] = -0.168624394422195538e0 * wr_10_0 + 0.266344014647437637e0 * wr_12_4 
             + 0.576511292192755788e-1 * wr_8_0 + 0.539402707330648918e0 * wr_6_0 
             + 0.920569053609993493e-1 * wr_12_0 + 0.119171647545943241e0 * wr_4_0;
 results[k++] = 0.714035588129062015e-1 * wr_6_0 + 0.190456514045795048e0 * wr_8_0 
             + 0.375932678336972110e0 * wr_10_0 + wr_0_0 + 0.559099058544119587e0 * wr_4_0 
             + 0.885057792384256496e-1 * wr_12_0 - 0.169708941477702441e0 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::setup___ar_1_Hu(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,3,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,7,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,11,5,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=1)
void BoxMatrix::evaluate___ar_1_Hu(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = 0.699854212223765171e0 * wr_4_0;
 results[k++] = -0.521640530957301061e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.285714285714285714e0 * wr_4_0;
 results[k++] = -0.348478126363603589e0 * wr_4_0 - 0.112758849626553142e1 * wr_6_0;
 results[k++] = -0.348478126363603589e0 * wr_4_0 - 0.112758849626553142e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.779220779220779221e-1 * wr_4_0 - 0.672363874212398935e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = -0.406557814090870854e0 * wr_4_0 + 0.338276548879659426e0 * wr_6_0;
 results[k++] = -0.887181884498666528e-1 * wr_4_0 - 0.155017789106946847e1 * wr_6_0;
 results[k++] = 0.841654636156864964e0 * wr_4_0 + 0.326806194281060772e0 * wr_6_0;
 results[k++] = 0.266154565349599958e0 * wr_4_0 - 0.103345192737964565e1 * wr_6_0;
 results[k++] = -0.142265599351991199e0 * wr_4_0 - 0.966705759488954500e0 * wr_6_0;
 results[k++] = -0.293645124009971400e0 * wr_4_0 - 0.288215972327715282e0 * wr_6_0 
             + 0.542850121464134724e0 * wr_8_0;
 results[k++] = -0.651942877818760169e0 * wr_4_0 + 0.210952491314662323e0 * wr_6_0;
 results[k++] = 0.224275168038398085e0 * wr_4_0 - 0.817620458377699485e0 * wr_6_0 
             + 0.355378824660767050e0 * wr_8_0;
 results[k++] = 0.105724328114469154e0 * wr_4_0 + 0.266836140256488293e0 * wr_6_0 
             + 0.789771012824305115e0 * wr_8_0;
 results[k++] = -0.354610176809167795e0 * wr_4_0 - 0.894995622700763991e0 * wr_6_0 
             - 0.214058384404121748e0 * wr_8_0;
 results[k++] = -0.217314292606253389e0 * wr_4_0 + 0.843809965258649291e0 * wr_6_0;
 results[k++] = 0.336412752057597128e0 * wr_4_0 - 0.188681644241007573e0 * wr_6_0 
             - 0.236919216440511367e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.629370629370629371e-1 * wr_4_0 - 0.201709162263719681e0 * wr_6_0 
             - 0.332426451098750089e0 * wr_8_0;
 results[k++] = 0.343349827294393607e0 * wr_4_0 - 0.616231669626417006e0 * wr_6_0 
             + 0.725413988174075357e-1 * wr_8_0;
 results[k++] = -0.115815198770744764e0 * wr_4_0 - 0.859718665741711648e0 * wr_6_0 
             - 0.120734760482975128e0 * wr_8_0 - 0.759127383055424236e-1 * wr_10_0;
 results[k++] = 0.244680221763430283e0 * wr_6_0 - 0.213806228093411684e0 * wr_8_0 
             + 0.960228625863300786e0 * wr_10_0 - 0.228899884862929071e0 * wr_4_0;
 results[k++] = 0.343349827294393607e0 * wr_4_0 - 0.616231669626417006e0 * wr_6_0 
             + 0.725413988174075357e-1 * wr_8_0;
 results[k++] = wr_0_0 - 0.356643356643356643e0 * wr_4_0 - 0.336181937106199468e0 * wr_6_0 
             + 0.237447465070535778e0 * wr_8_0;
 results[k++] = -0.342504301239655061e0 * wr_8_0 - 0.844841397348696016e0 * wr_10_0;
 results[k++] = -0.209790209790209790e0 * wr_4_0 + 0.415283569366481695e-1 * wr_6_0 
             + 0.393246328116817149e0 * wr_8_0 - 0.628617194640286698e0 * wr_10_0;
 results[k++] = -0.115815198770744764e0 * wr_4_0 - 0.859718665741711648e0 * wr_6_0 
             - 0.120734760482975128e0 * wr_8_0 - 0.759127383055424236e-1 * wr_10_0;
 results[k++] = -0.342504301239655061e0 * wr_8_0 - 0.844841397348696016e0 * wr_10_0;
 results[k++] = wr_0_0 + 0.531468531468531469e0 * wr_4_0 + 0.355957345171270024e0 * wr_6_0 
             + 0.174961290051973731e0 * wr_8_0 + 0.209539064880095566e0 * wr_10_0;
 results[k++] = 0.884553191655490724e-1 * wr_4_0 + 0.656620977021305295e0 * wr_6_0 
             - 0.790394541322280911e-1 * wr_8_0 - 0.364441387091594360e0 * wr_10_0;
 results[k++] = 0.244680221763430283e0 * wr_6_0 - 0.213806228093411684e0 * wr_8_0 
             + 0.960228625863300786e0 * wr_10_0 - 0.228899884862929071e0 * wr_4_0;
 results[k++] = -0.209790209790209790e0 * wr_4_0 + 0.415283569366481695e-1 * wr_6_0 
             + 0.393246328116817149e0 * wr_8_0 - 0.628617194640286698e0 * wr_10_0;
 results[k++] = 0.884553191655490724e-1 * wr_4_0 + 0.656620977021305295e0 * wr_6_0 
             - 0.790394541322280911e-1 * wr_8_0 - 0.364441387091594360e0 * wr_10_0;
 results[k++] = 0.355957345171270024e0 * wr_6_0 - 0.299933640089097825e0 * wr_8_0 
             + 0.209539064880095566e0 * wr_10_0 + wr_0_0 - 0.391608391608391608e0 * wr_4_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_A1g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_A1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=4)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = wr_0_0 + 0.377622377622377622e0 * wr_4_0 - 0.100854581131859840e0 * wr_6_0 
             - 0.759831888225714491e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = -0.676553097759318853e0 * wr_4_0 + 0.502218476229899290e0 * wr_6_0 
             + 0.806047437927905811e-1 * wr_8_0 + 0.101361476964046979e1 * wr_10_0;
 results[k++] = wr_0_0 - 0.513368983957219251e0 * wr_4_0 - 0.811832541618686021e-1 * wr_6_0 
             + 0.139254904327081133e0 * wr_8_0 + 0.384914151790610333e0 * wr_10_0 
             - 0.703620944945483914e0 * wr_12_0 + 0.134918608474773441e1 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_A1u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(0,1,1,0,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(0,1,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(0,1,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(0,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_A1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = -0.872871560943969523e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.545454545454545455e0 * wr_4_0 + 0.840454842765498668e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.975900072948533181e0 * wr_4_0;
 results[k++] = 0.192153784566104560e1 * wr_6_0;
 results[k++] = -0.187642068041940394e0 * wr_4_0 - 0.105241592984782933e1 * wr_6_0 
             - 0.849517876772359836e0 * wr_8_0;
 results[k++] = -0.792932460858518658e0 * wr_4_0 + 0.933926490897709026e0 * wr_6_0 
             - 0.167527184538488964e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.587412587412587413e0 * wr_4_0 + 0.107578219873983830e1 * wr_6_0 
             + 0.189957972056428623e0 * wr_8_0;
 results[k++] = 0.276022653573735937e0 * wr_8_0 - 0.491370145796497878e0 * wr_6_0 
             + 0.141844070723667118e0 * wr_4_0 + 0.111568484295605893e1 * wr_10_0;
 results[k++] = 0.276022653573735937e0 * wr_8_0 - 0.491370145796497878e0 * wr_6_0 
             + 0.141844070723667118e0 * wr_4_0 + 0.111568484295605893e1 * wr_10_0;
 results[k++] = -0.118652448390423341e0 * wr_6_0 + 0.524883870155921194e0 * wr_8_0 
             - 0.366693363540167240e0 * wr_10_0 + wr_0_0 - 0.587412587412587413e0 * wr_4_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_A2g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,6,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_A2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 - 0.571428571428571429e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = -0.174685258696458690e1 * wr_6_0 + 0.449883326641266828e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.701298701298701299e0 * wr_4_0 + 0.504272905659299201e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.477852577146909011e0 * wr_4_0 + 0.120604537831105449e1 * wr_6_0 
             - 0.649019131451869355e0 * wr_8_0;
 results[k++] = 0.724878319027841628e0 * wr_4_0 - 0.130098500509078673e1 * wr_6_0 
             - 0.320883646717966313e0 * wr_8_0;
 results[k++] = 0.413832471073086495e0 * wr_4_0 + 0.104446593573418703e1 * wr_6_0 
             - 0.562067055379430822e0 * wr_8_0;
 results[k++] = -0.558011590160597050e-1 * wr_4_0 + 0.497067381331433183e0 * wr_6_0 
             + 0.438779036394868322e0 * wr_8_0 - 0.136549177358184673e1 * wr_10_0;
 results[k++] = -0.893015795780554622e0 * wr_6_0 - 0.729430451237091651e-1 * wr_8_0 
             + 0.494889623730784713e0 * wr_10_0 + wr_0_0 + 0.268907563025210084e0 * wr_4_0 
             - 0.228448358748533738e0 * wr_12_0 - 0.963704346248381719e0 * wr_12_4;
 results[k++] = -0.414073809914948332e0 * wr_10_0 + 0.301035563346376305e0 * wr_6_0 
             + 0.262283685280292162e0 * wr_8_0 - 0.587329035810525899e0 * wr_12_0 
             + 0.407919244515575044e0 * wr_4_0 + 0.433152891797258391e0 * wr_12_4;
 results[k++] = -0.414073809914948332e0 * wr_10_0 + 0.301035563346376305e0 * wr_6_0 
             + 0.262283685280292162e0 * wr_8_0 - 0.587329035810525899e0 * wr_12_0 
             + 0.407919244515575044e0 * wr_4_0 + 0.433152891797258391e0 * wr_12_4;
 results[k++] = 0.129893206658989763e1 * wr_6_0 - 0.437658270742254989e0 * wr_8_0 
             - 0.406063281009874637e0 * wr_10_0 + wr_0_0 - 0.550038197097020626e-1 * wr_4_0 
             + 0.223371728554121878e-1 * wr_12_0 - 0.385481738499352686e0 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_A2u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_A2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=3)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = wr_0_0 - 0.181818181818181818e0 * wr_4_0 - 0.151281871697789760e1 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = -0.630019319247989485e0 * wr_8_0 + 0.117073881400992708e1 * wr_6_0 
             + 0.463863607042713265e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.307692307692307692e0 * wr_4_0 - 0.130517693229465676e1 * wr_6_0 
             - 0.274939170081673006e0 * wr_8_0 - 0.471462895980215024e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_Eg(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,4,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_Eg(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 - 0.571428571428571429e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.246411246246886702e0 * wr_4_0 + 0.956790566516759144e0 * wr_6_0;
 results[k++] = -0.376399396004920483e0 * wr_4_0 + 0.146152173176090980e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.539460539460539461e-1 * wr_4_0 + 0.806836649054878721e-1 * wr_6_0 
             - 0.531882321758000144e0 * wr_8_0;
 results[k++] = -0.494423751303926793e0 * wr_4_0 + 0.277304251331887653e0 * wr_6_0 
             + 0.348198714323556171e0 * wr_8_0;
 results[k++] = -0.494423751303926793e0 * wr_4_0 + 0.277304251331887653e0 * wr_6_0 
             + 0.348198714323556171e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.377622377622377622e0 * wr_4_0 + 0.322734659621951489e0 * wr_6_0 
             - 0.227949566467714347e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = -0.343604066372024752e0 * wr_4_0 + 0.133418070128244146e1 * wr_6_0;
 results[k++] = 0.797325472097299287e0 * wr_4_0 + 0.114991914915213794e0 * wr_6_0 
             - 0.680697007698427277e0 * wr_8_0;
 results[k++] = 0.116354894776547920e1 * wr_6_0 - 0.246665221366869486e0 * wr_8_0;
 results[k++] = -0.451345069259141656e0 * wr_4_0 + 0.253142989577594788e0 * wr_6_0 
             + 0.317860483882181508e0 * wr_8_0;
 results[k++] = 0.766045534972260299e-1 * wr_4_0 - 0.181968142962626730e0 * wr_6_0 
             + 0.394273009035443234e0 * wr_8_0 - 0.114769272513366877e1 * wr_10_0;
 results[k++] = -0.302563743395579521e0 * wr_4_0 - 0.481283422459893048e0 * wr_6_0 
             + 0.102992963674076550e0 * wr_8_0 + 0.679953458374164153e0 * wr_10_0;
 results[k++] = -0.980230095177719784e0 * wr_6_0 + 0.544052700198614817e0 * wr_10_0 
             + 0.117993263021073232e0 * wr_8_0 - 0.132049643491375073e0 * wr_4_0;
 results[k++] = 0.278318164225627959e0 * wr_4_0 - 0.903451194267977527e0 * wr_10_0 
             + 0.213164431324507721e0 * wr_8_0 - 0.531259629886857666e0 * wr_6_0;
 results[k++] = -0.485872020893367867e0 * wr_4_0 - 0.135252081535041617e0 * wr_6_0 
             + 0.434152063118565508e0 * wr_8_0 - 0.151653241187958269e-1 * wr_10_0;
 results[k++] = 0.355957345171270024e0 * wr_6_0 - 0.299933640089097825e0 * wr_8_0 
             + 0.209539064880095566e0 * wr_10_0 + wr_0_0 - 0.391608391608391608e0 * wr_4_0;
 results[k++] = -0.120544280751235613e0 * wr_4_0 + 0.496649893950627840e0 * wr_10_0 
             + 0.107712619650469957e0 * wr_8_0 - 0.894823557790455136e0 * wr_6_0;
 results[k++] = 0.587036174788056518e-1 * wr_4_0 + 0.433219976644855256e-1 * wr_6_0 
             - 0.330270664385340287e0 * wr_8_0 + 0.325032656546411606e-1 * wr_10_0 
             - 0.113449680203699394e1 * wr_12_4 + 0.591657237582726803e0 * wr_12_0;
 results[k++] = -0.120544280751235613e0 * wr_4_0 + 0.496649893950627840e0 * wr_10_0 
             + 0.107712619650469957e0 * wr_8_0 - 0.894823557790455136e0 * wr_6_0;
 results[k++] = 0.243549762485605806e0 * wr_6_0 + 0.464183014423603777e-1 * wr_8_0 
             - 0.219950943880348762e0 * wr_10_0 + wr_0_0 + 0.464476699770817418e0 * wr_4_0 
             - 0.703620944945483914e0 * wr_12_0 - 0.192740869249676344e0 * wr_12_4;
 results[k++] = 0.252980776136598888e0 * wr_4_0 - 0.558750441294459161e0 * wr_12_4 
             + 0.569315027589359082e-1 * wr_8_0 - 0.634760725426870784e0 * wr_6_0 
             + 0.198434567482597836e0 * wr_10_0;
 results[k++] = 0.587036174788056518e-1 * wr_4_0 + 0.433219976644855256e-1 * wr_6_0 
             - 0.330270664385340287e0 * wr_8_0 + 0.325032656546411606e-1 * wr_10_0 
             - 0.113449680203699394e1 * wr_12_4 + 0.591657237582726803e0 * wr_12_0;
 results[k++] = 0.252980776136598888e0 * wr_4_0 - 0.558750441294459161e0 * wr_12_4 
             + 0.569315027589359082e-1 * wr_8_0 - 0.634760725426870784e0 * wr_6_0 
             + 0.198434567482597836e0 * wr_10_0;
 results[k++] = -0.274774091009401422e0 * wr_6_0 - 0.117831072892145574e0 * wr_8_0 
             + 0.484152373511773605e0 * wr_10_0 + wr_0_0 - 0.372333548804137039e0 * wr_4_0 
             - 0.206111185893121551e0 * wr_12_0 + 0.192740869249676344e0 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_Eu(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,4,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_Eu(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = -0.699854212223765171e0 * wr_4_0;
 results[k++] = -0.521640530957301061e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.285714285714285714e0 * wr_4_0;
 results[k++] = 0.348478126363603589e0 * wr_4_0 + 0.112758849626553142e1 * wr_6_0;
 results[k++] = 0.348478126363603589e0 * wr_4_0 + 0.112758849626553142e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.779220779220779221e-1 * wr_4_0 - 0.672363874212398935e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.111169017897833037e1 * wr_6_0 + 0.296907847610082194e0 * wr_4_0;
 results[k++] = 0.153285692406380499e1 * wr_6_0 - 0.394771016975861392e0 * wr_4_0;
 results[k++] = 0.841654636156864964e0 * wr_4_0 + 0.326806194281060772e0 * wr_6_0;
 results[k++] = -0.623376623376623377e0 * wr_4_0 - 0.352991033961509441e0 * wr_6_0;
 results[k++] = 0.841932743878263462e0 * wr_6_0 - 0.594662513740651885e0 * wr_8_0 
             - 0.268060097202771992e-1 * wr_4_0;
 results[k++] = -0.322329185610152119e0 * wr_4_0 + 0.125157243754948776e1 * wr_6_0;
 results[k++] = -0.498980748569848039e0 * wr_4_0 + 0.279860104912576495e0 * wr_6_0 
             + 0.351407986906002065e0 * wr_8_0;
 results[k++] = -0.789771012824305115e0 * wr_8_0 - 0.266836140256488293e0 * wr_6_0 
             - 0.105724328114469154e0 * wr_4_0;
 results[k++] = -0.354610176809167795e0 * wr_4_0 - 0.894995622700763991e0 * wr_6_0 
             - 0.214058384404121748e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.839160839160839161e-1 * wr_4_0 - 0.860625758991870638e0 * wr_6_0 
             + 0.132970580439500036e0 * wr_8_0;
 results[k++] = -0.446301949306364473e0 * wr_4_0 + 0.250314487509897552e0 * wr_6_0 
             + 0.314308858623270646e0 * wr_8_0;
 results[k++] = 0.352688809554713608e0 * wr_8_0 + 0.470887306334979341e0 * wr_6_0 
             + 0.634345968686814926e-1 * wr_4_0 + 0.748424145094777556e0 * wr_10_0;
 results[k++] = -0.446301949306364473e0 * wr_4_0 + 0.250314487509897552e0 * wr_6_0 
             + 0.314308858623270646e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.307692307692307692e0 * wr_4_0 + 0.156621231875358811e0 * wr_6_0 
             + 0.131970801639203043e0 * wr_8_0 - 0.104769532440047783e1 * wr_10_0;
 results[k++] = 0.117234456031259402e0 * wr_8_0 - 0.973926299276136078e0 * wr_6_0 
             - 0.131200440834221806e0 * wr_4_0 + 0.540553932716745391e0 * wr_10_0;
 results[k++] = 0.352688809554713608e0 * wr_8_0 + 0.470887306334979341e0 * wr_6_0 
             + 0.634345968686814926e-1 * wr_4_0 + 0.748424145094777556e0 * wr_10_0;
 results[k++] = 0.117234456031259402e0 * wr_8_0 - 0.973926299276136078e0 * wr_6_0 
             - 0.131200440834221806e0 * wr_4_0 + 0.540553932716745391e0 * wr_10_0;
 results[k++] = wr_0_0 + 0.531468531468531469e0 * wr_4_0 + 0.355957345171270024e0 * wr_6_0 
             + 0.174961290051973731e0 * wr_8_0 + 0.209539064880095566e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_T1g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=0)
 if (lmax>=0){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,0,1,2,0,1));
    }
#endif
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,2,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,2,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,6,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,0,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,0,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,0,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,0,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,10,4,2));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,0,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,0,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,0,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,0,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,14,6,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_T1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=0)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=2)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0;
 results[k++] = -0.699854212223765171e0 * wr_4_0;
 results[k++] = -0.699854212223765171e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.285714285714285714e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.666666666666666667e0 * wr_4_0;
 results[k++] = -0.755928946018454454e0 * wr_4_0;
 results[k++] = 0.819920061690787761e0 * wr_4_0;
 results[k++] = -0.161690416690888649e0 * wr_4_0;
 results[k++] = 0.336717514850736916e0 * wr_4_0;
 results[k++] = -0.224941663320633414e0 * wr_4_0 - 0.727855244568577877e0 * wr_6_0;
 results[k++] = -0.534522483824848769e0 * wr_4_0;
 results[k++] = 0.115543438054953189e1 * wr_6_0 + 0.357083820386169351e0 * wr_4_0;
 results[k++] = -0.306980966003839377e0 * wr_6_0 - 0.210825831146344877e0 * wr_4_0;
 results[k++] = 0.375973363728038027e0 * wr_6_0 + 0.258207855453355024e0 * wr_4_0;
 results[k++] = 0.415754145800021424e-1 * wr_4_0 - 0.155667761723288971e1 * wr_6_0;
 results[k++] = -0.494286314696756499e0 * wr_6_0 + 0.567386215865894880e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.350649350649350649e0 * wr_4_0 + 0.210113710691374667e0 * wr_6_0;
 results[k++] = 0.309243659734822276e0 * wr_4_0 + 0.100063552596183110e1 * wr_6_0;
 results[k++] = -0.774050407889904530e-1 * wr_4_0 - 0.434136645513023668e0 * wr_6_0 
             - 0.772262162828854309e0 * wr_8_0;
 results[k++] = -0.170089918856649098e0 * wr_4_0 + 0.570752673693840881e0 * wr_6_0;
 results[k++] = 0.309243659734822276e0 * wr_4_0 + 0.100063552596183110e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.188811188811188811e0 * wr_4_0 + 0.504272905659299201e-2 * wr_6_0 
             + 0.607865510580571594e0 * wr_8_0;
 results[k++] = -0.204794488150479604e0 * wr_4_0 - 0.257547936528153482e0 * wr_8_0 
             - 0.114861759904726578e1 * wr_6_0;
 results[k++] = 0.334627003810298109e0 * wr_4_0 - 0.543625068498875992e0 * wr_6_0 
             + 0.292545434970860531e0 * wr_8_0;
 results[k++] = -0.774050407889904530e-1 * wr_4_0 - 0.434136645513023668e0 * wr_6_0 
             - 0.772262162828854309e0 * wr_8_0;
 results[k++] = -0.204794488150479604e0 * wr_4_0 - 0.257547936528153482e0 * wr_8_0 
             - 0.114861759904726578e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.488687782805429864e0 * wr_4_0 + 0.522070772917862704e0 * wr_6_0 
             + 0.106152984384474819e0 * wr_8_0;
 results[k++] = -0.421174410682712467e0 * wr_6_0 + 0.110177109619768546e0 * wr_8_0 
             - 0.750939197948825921e-1 * wr_4_0;
 results[k++] = -0.170089918856649098e0 * wr_4_0 + 0.570752673693840881e0 * wr_6_0;
 results[k++] = 0.334627003810298109e0 * wr_4_0 - 0.543625068498875992e0 * wr_6_0 
             + 0.292545434970860531e0 * wr_8_0;
 results[k++] = -0.421174410682712467e0 * wr_6_0 + 0.110177109619768546e0 * wr_8_0 
             - 0.750939197948825921e-1 * wr_4_0;
 results[k++] = wr_0_0 - 0.488687782805429864e0 * wr_4_0 + 0.696094363890483603e-1 * wr_6_0 
             + 0.140792379288882391e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = -0.290627863517575250e0 * wr_6_0;
 results[k++] = -0.147375225236722405e1 * wr_6_0;
 results[k++] = 0.163299316185545207e1 * wr_6_0;
 results[k++] = 0.175411603861405843e1 * wr_6_0;
 results[k++] = 0.866055475677212416e0 * wr_4_0 + 0.130775866515022832e0 * wr_6_0;
 results[k++] = -0.767519463953629002e0 * wr_8_0 - 0.634605044037084019e-1 * wr_4_0 
             - 0.411858184669882087e0 * wr_6_0;
 results[k++] = -0.170788443023222589e0 * wr_4_0 + 0.663154680005880533e0 * wr_6_0;
 results[k++] = -0.139448179790430990e0 * wr_4_0 + 0.541463528851021698e0 * wr_6_0;
 results[k++] = 0.115470053837925153e1 * wr_6_0;
 results[k++] = -0.254696279400239002e0 * wr_4_0 + 0.771389215839870028e0 * wr_6_0 
             - 0.253680796882396842e0 * wr_8_0;
 results[k++] = -0.799286669497027599e0 * wr_8_0;
 results[k++] = 0.831634580949746732e0 * wr_4_0 + 0.559720209825152991e0 * wr_6_0 
             + 0.175703993453001033e0 * wr_8_0;
 results[k++] = -0.496138938356833826e0 * wr_6_0;
 results[k++] = 0.108998755143396343e0 * wr_8_0 + 0.109435076424608614e0 * wr_4_0 
             - 0.331441974681927257e0 * wr_6_0;
 results[k++] = 0.274792044752928579e0 * wr_4_0 + 0.475572867574214045e0 * wr_6_0 
             + 0.181279460095324761e0 * wr_8_0;
 results[k++] = -0.104853961490935311e1 * wr_6_0 - 0.186950934687903540e0 * wr_4_0 
             - 0.235108024125630697e0 * wr_8_0;
 results[k++] = -0.374125324614651829e0 * wr_10_0 - 0.183607528717485819e0 * wr_8_0 
             - 0.991353045258219211e-1 * wr_4_0 - 0.294360231263072651e0 * wr_6_0;
 results[k++] = -0.190567857661473688e0 * wr_8_0 + 0.152335680752373749e-1 * wr_4_0 
             - 0.878685400142492073e0 * wr_10_0 + 0.237471629062362498e0 * wr_6_0;
 results[k++] = 0.603828331050064971e0 * wr_4_0 - 0.625228228277004144e0 * wr_6_0;
 results[k++] = 0.305471263895445743e0 * wr_4_0 - 0.496259521403542453e0 * wr_6_0 
             + 0.267056223047834985e0 * wr_8_0;
 results[k++] = -0.190567857661473688e0 * wr_8_0 + 0.152335680752373749e-1 * wr_4_0 
             - 0.878685400142492073e0 * wr_10_0 + 0.237471629062362498e0 * wr_6_0;
 results[k++] = 0.991353045258219211e-1 * wr_4_0 - 0.392480308350763535e-1 * wr_6_0 
             - 0.243521564404244349e0 * wr_8_0 + 0.708869036111971888e0 * wr_10_0;
 results[k++] = -0.219694014552435889e0 * wr_8_0 + 0.668042657122684936e0 * wr_6_0 
             - 0.220573448209986185e0 * wr_4_0;
 results[k++] = -0.490209291421591158e0 * wr_4_0 + 0.173281836855825140e0 * wr_6_0 
             - 0.139056394027547966e-1 * wr_8_0 - 0.839352771563546767e0 * wr_10_0;
 results[k++] = 0.452041820901896753e0 * wr_10_0 + 0.253193633369154314e0 * wr_4_0 
             - 0.601441731212669375e0 * wr_6_0 + 0.126695382319831190e0 * wr_8_0;
 results[k++] = 0.119833098846783212e0 * wr_4_0 + 0.493719780508292088e0 * wr_10_0 
             + 0.190616639289627139e0 * wr_6_0 - 0.571078087584327493e0 * wr_8_0;
 results[k++] = -0.363673656331445738e0 * wr_10_0 - 0.240259139805274080e0 * wr_8_0 
             - 0.213852317964767134e0 * wr_6_0 - 0.640192598904983857e-1 * wr_4_0;
 results[k++] = 0.339480030377690608e0 * wr_6_0 + 0.381399560481032796e0 * wr_8_0 
             + 0.577314031823145546e0 * wr_10_0 + 0.101627424473202518e0 * wr_4_0;
 results[k++] = 0.216756341357069772e0 * wr_10_0 + 0.157594630984732739e0 * wr_8_0 
             + 0.368217792050618641e0 * wr_6_0 + 0.110230418589513623e0 * wr_4_0;
 results[k++] = 0.347803707146682474e0 * wr_4_0 - 0.100416653823416694e0 * wr_10_0 
             + 0.665958864495586925e-2 * wr_8_0 + 0.116181644550839651e1 * wr_6_0;
 results[k++] = -0.842431611100467356e-2 * wr_4_0 + 0.126634045568394593e0 * wr_6_0 
             - 0.149045827792201544e0 * wr_8_0 - 0.100497473410106323e1 * wr_10_0;
 results[k++] = -0.187224621322310612e0 * wr_4_0 - 0.358139331718548245e0 * wr_10_0 
             + 0.603075945758387581e0 * wr_6_0 - 0.236602916573954656e0 * wr_8_0;
 results[k++] = 0.703505020246824569e0 * wr_4_0 - 0.759111163901351299e0 * wr_6_0 
             + 0.163311205952418668e0 * wr_8_0 + 0.149406402293408154e-1 * wr_10_0;
 results[k++] = -0.211675185733167040e0 * wr_4_0 + 0.118757967252198877e0 * wr_6_0 
             + 0.202433968814779797e0 * wr_8_0 - 0.253384722874454961e0 * wr_10_0;
 results[k++] = 0.575813352482936804e0 * wr_6_0 + 0.139674979453256340e0 * wr_8_0 
             + 0.683056265417958583e-1 * wr_10_0 + wr_0_0 + 0.506787330316742081e0 * wr_4_0;
 results[k++] = -0.778751760835819473e-1 * wr_4_0 - 0.464530600017697574e0 * wr_6_0 
             + 0.144969881078642824e0 * wr_8_0 + 0.160425271536165337e0 * wr_10_0;
 results[k++] = -0.549038672016896604e0 * wr_6_0 + 0.115656531380521242e0 * wr_8_0 
             + 0.231133107354964282e0 * wr_4_0 + 0.412655837072798572e0 * wr_10_0;
 results[k++] = -0.119886297683389877e0 * wr_8_0 - 0.742739602052467146e0 * wr_12_0 
             - 0.464565669040005904e0 * wr_10_0 - 0.133181662025103105e-1 * wr_4_0 
             - 0.242677066974672721e0 * wr_12_4 - 0.117942216830918285e0 * wr_6_0;
 results[k++] = -0.320217091715704815e-1 * wr_10_0 - 0.136008007469207387e0 * wr_12_0 
             + 0.260793986321623783e0 * wr_12_4 - 0.849982872589664164e-1 * wr_4_0 
             - 0.124235043602099529e0 * wr_8_0 + 0.243147548609807875e0 * wr_6_0;
 results[k++] = -0.778751760835819473e-1 * wr_4_0 - 0.464530600017697574e0 * wr_6_0 
             + 0.144969881078642824e0 * wr_8_0 + 0.160425271536165337e0 * wr_10_0;
 results[k++] = 0.767751136643915740e-1 * wr_6_0 + 0.185253130643266304e0 * wr_8_0 
             - 0.129421187131823732e0 * wr_10_0 + wr_0_0 - 0.506787330316742081e0 * wr_4_0;
 results[k++] = 0.109392152290215789e0 * wr_4_0 + 0.450702434784818340e0 * wr_10_0 
             - 0.521320584444745177e0 * wr_8_0 + 0.174008388624590513e0 * wr_6_0;
 results[k++] = -0.420220447032703119e-1 * wr_4_0 + 0.907560773248204121e-1 * wr_12_0 
             + 0.215219216536719294e0 * wr_10_0 - 0.372136301102585028e0 * wr_6_0 
             - 0.506612072853832272e-2 * wr_8_0 - 0.174023865424336096e0 * wr_12_4;
 results[k++] = -0.153996737673822542e0 * wr_8_0 + 0.132246688288398536e1 * wr_12_4 
             + 0.255748398728274928e-1 * wr_4_0 + 0.543069893917307881e0 * wr_10_0 
             - 0.380388406710462766e-1 * wr_6_0 - 0.689686477138490911e0 * wr_12_0;
 results[k++] = -0.549038672016896604e0 * wr_6_0 + 0.115656531380521242e0 * wr_8_0 
             + 0.231133107354964282e0 * wr_4_0 + 0.412655837072798572e0 * wr_10_0;
 results[k++] = 0.109392152290215789e0 * wr_4_0 + 0.450702434784818340e0 * wr_10_0 
             - 0.521320584444745177e0 * wr_8_0 + 0.174008388624590513e0 * wr_6_0;
 results[k++] = -0.405916270809343010e-1 * wr_6_0 + 0.198935577610115905e-1 * wr_8_0 
             - 0.119140094601855579e0 * wr_10_0 + wr_0_0 - 0.391138273491214668e0 * wr_4_0 
             + 0.603103667096129069e0 * wr_12_0 - 0.115644521549805807e1 * wr_12_4;
 results[k++] = -0.662699134377098233e0 * wr_6_0 - 0.371881371323265605e0 * wr_12_4 
             + 0.207168482285631799e0 * wr_10_0 - 0.933793652316796247e-1 * wr_12_0 
             - 0.748327227607291238e-1 * wr_4_0 - 0.481159017848029629e-1 * wr_8_0;
 results[k++] = -0.132938055302965768e0 * wr_4_0 + 0.202749068373888071e0 * wr_12_0 
             + 0.470120396137358917e0 * wr_8_0 - 0.388769299309034824e0 * wr_12_4 
             - 0.599750157873127005e0 * wr_10_0 - 0.581365358282377990e-1 * wr_6_0;
 results[k++] = -0.119886297683389877e0 * wr_8_0 - 0.742739602052467146e0 * wr_12_0 
             - 0.464565669040005904e0 * wr_10_0 - 0.133181662025103105e-1 * wr_4_0 
             - 0.242677066974672721e0 * wr_12_4 - 0.117942216830918285e0 * wr_6_0;
 results[k++] = -0.420220447032703119e-1 * wr_4_0 + 0.907560773248204121e-1 * wr_12_0 
             + 0.215219216536719294e0 * wr_10_0 - 0.372136301102585028e0 * wr_6_0 
             - 0.506612072853832272e-2 * wr_8_0 - 0.174023865424336096e0 * wr_12_4;
 results[k++] = -0.662699134377098233e0 * wr_6_0 - 0.371881371323265605e0 * wr_12_4 
             + 0.207168482285631799e0 * wr_10_0 - 0.933793652316796247e-1 * wr_12_0 
             - 0.748327227607291238e-1 * wr_4_0 - 0.481159017848029629e-1 * wr_8_0;
 results[k++] = 0.355305370883640307e0 * wr_10_0 + 0.570135746606334842e0 * wr_4_0 
             + 0.987912235832548122e-1 * wr_12_0 + 0.196385121486909290e0 * wr_8_0 
             - 0.134918608474773441e0 * wr_12_4 + 0.137387045504700711e0 * wr_6_0 + wr_0_0;
 results[k++] = 0.321532955002964030e-1 * wr_4_0 + 0.401222114224598715e-1 * wr_12_0 
             - 0.890138589581494187e-1 * wr_10_0 + 0.284741224284298141e0 * wr_6_0 
             + 0.206739077675507385e-1 * wr_8_0 + 0.159785868829663148e0 * wr_12_4;
 results[k++] = -0.320217091715704815e-1 * wr_10_0 - 0.136008007469207387e0 * wr_12_0 
             + 0.260793986321623783e0 * wr_12_4 - 0.849982872589664164e-1 * wr_4_0 
             - 0.124235043602099529e0 * wr_8_0 + 0.243147548609807875e0 * wr_6_0;
 results[k++] = -0.153996737673822542e0 * wr_8_0 + 0.132246688288398536e1 * wr_12_4 
             + 0.255748398728274928e-1 * wr_4_0 + 0.543069893917307881e0 * wr_10_0 
             - 0.380388406710462766e-1 * wr_6_0 - 0.689686477138490911e0 * wr_12_0;
 results[k++] = -0.132938055302965768e0 * wr_4_0 + 0.202749068373888071e0 * wr_12_0 
             + 0.470120396137358917e0 * wr_8_0 - 0.388769299309034824e0 * wr_12_4 
             - 0.599750157873127005e0 * wr_10_0 - 0.581365358282377990e-1 * wr_6_0;
 results[k++] = 0.321532955002964030e-1 * wr_4_0 + 0.401222114224598715e-1 * wr_12_0 
             - 0.890138589581494187e-1 * wr_10_0 + 0.284741224284298141e0 * wr_6_0 
             + 0.206739077675507385e-1 * wr_8_0 + 0.159785868829663148e0 * wr_12_4;
 results[k++] = -0.999178512761459717e-1 * wr_6_0 + 0.387159239502764029e0 * wr_8_0 
             - 0.234267277505696906e0 * wr_10_0 + wr_0_0 - 0.542633836751483810e0 * wr_4_0 
             + 0.301551833548064535e-1 * wr_12_0 - 0.578222607749029033e-1 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_T1u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,2,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_T1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = -0.534522483824848769e0 * wr_4_0;
 results[k++] = -0.690065559342354218e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.909090909090909091e-1 * wr_4_0 - 0.630341132074124001e0 * wr_6_0;
 results[k++] = 0.352089395109765171e0 * wr_4_0 + 0.113927366324455231e1 * wr_6_0;
 results[k++] = 0.352089395109765171e0 * wr_4_0 + 0.113927366324455231e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.272727272727272727e0 * wr_4_0 - 0.420227421382749334e-1 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = -0.617213399848367641e0 * wr_4_0;
 results[k++] = 0.741645600740016947e0 * wr_4_0 - 0.239978060151704777e0 * wr_6_0;
 results[k++] = -0.146254484825426131e0 * wr_4_0 - 0.121691087147225504e1 * wr_6_0;
 results[k++] = 0.146759877141068561e1 * wr_6_0;
 results[k++] = 0.314918328648886780e0 * wr_4_0 + 0.101899734239600903e1 * wr_6_0;
 results[k++] = -0.938210340209701971e-1 * wr_4_0 + 0.526207964923914663e-1 * wr_6_0 
             + 0.679614301417887869e0 * wr_8_0;
 results[k++] = 0.195671930411218583e0 * wr_4_0 - 0.684537243560938075e0 * wr_8_0;
 results[k++] = -0.115920416015935498e1 * wr_6_0 - 0.206682034855338043e0 * wr_4_0 
             - 0.259921700408847399e0 * wr_8_0;
 results[k++] = 0.429969707746757356e0 * wr_4_0;
 results[k++] = 0.337711188858943919e0 * wr_4_0 - 0.548635543712298352e0 * wr_6_0 
             + 0.295241763259710203e0 * wr_8_0;
 results[k++] = -0.246254378666166536e0 * wr_8_0 - 0.247240133282009624e0 * wr_4_0 
             + 0.748807061436702667e0 * wr_6_0;
 results[k++] = -0.574534151229195224e0 * wr_4_0 + 0.322235253162984833e0 * wr_6_0 
             + 0.289011850759005456e-1 * wr_8_0;
 results[k++] = wr_0_0 + 0.293706293706293706e0 * wr_4_0 - 0.537891099369919148e-1 * wr_6_0 
             - 0.151966377645142898e0 * wr_8_0;
 results[k++] = -0.232481036376607066e0 * wr_8_0 - 0.184862031865806711e0 * wr_4_0 
             - 0.103682372076674847e1 * wr_6_0;
 results[k++] = 0.302058070020347297e0 * wr_4_0 - 0.490714548245302573e0 * wr_6_0 
             + 0.264072260978244765e0 * wr_8_0;
 results[k++] = 0.102775793403489990e0 * wr_4_0 - 0.169538807251597224e0 * wr_6_0 
             - 0.476184317073802389e-1 * wr_8_0 - 0.923874822245111322e0 * wr_10_0;
 results[k++] = -0.232481036376607066e0 * wr_8_0 - 0.184862031865806711e0 * wr_4_0 
             - 0.103682372076674847e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.398190045248868778e0 * wr_4_0 + 0.253357875092492194e0 * wr_6_0 
             - 0.614569909594327896e-1 * wr_8_0 - 0.341528132708979292e0 * wr_10_0;
 results[k++] = -0.611876383513858154e-1 * wr_4_0 - 0.204393464007786932e0 * wr_6_0 
             - 0.637867476746028426e-1 * wr_8_0 - 0.802126357680826684e0 * wr_10_0;
 results[k++] = 0.449134769392292598e0 * wr_10_0 + 0.251565361602972531e0 * wr_4_0 
             + 0.125880612567559370e0 * wr_8_0 - 0.597573898609985976e0 * wr_6_0;
 results[k++] = 0.302058070020347297e0 * wr_4_0 - 0.490714548245302573e0 * wr_6_0 
             + 0.264072260978244765e0 * wr_8_0;
 results[k++] = -0.611876383513858154e-1 * wr_4_0 - 0.204393464007786932e0 * wr_6_0 
             - 0.637867476746028426e-1 * wr_8_0 - 0.802126357680826684e0 * wr_10_0;
 results[k++] = wr_0_0 - 0.398190045248868778e0 * wr_4_0 + 0.337810500123322925e-1 * wr_6_0 
             - 0.815113774830371735e-1 * wr_8_0 + 0.647105935659118659e0 * wr_10_0;
 results[k++] = 0.119062459992599217e0 * wr_4_0 + 0.189390796096851310e0 * wr_6_0 
             - 0.567405521596292145e0 * wr_8_0 + 0.490544700754864698e0 * wr_10_0;
 results[k++] = 0.102775793403489990e0 * wr_4_0 - 0.169538807251597224e0 * wr_6_0 
             - 0.476184317073802389e-1 * wr_8_0 - 0.923874822245111322e0 * wr_10_0;
 results[k++] = 0.449134769392292598e0 * wr_10_0 + 0.251565361602972531e0 * wr_4_0 
             + 0.125880612567559370e0 * wr_8_0 - 0.597573898609985976e0 * wr_6_0;
 results[k++] = 0.119062459992599217e0 * wr_4_0 + 0.189390796096851310e0 * wr_6_0 
             - 0.567405521596292145e0 * wr_8_0 + 0.490544700754864698e0 * wr_10_0;
 results[k++] = wr_0_0 - 0.447552447552447552e0 * wr_4_0 - 0.593262241952116707e-1 * wr_6_0 
             + 0.749834100222744562e-1 * wr_8_0 + 0.113500326810051765e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_T2g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,4,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,4,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,6,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,14,6,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_T2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 + 0.380952380952380952e0 * wr_4_0;
 results[k++] = -0.673435029701473833e0 * wr_4_0;
 results[k++] = -0.673435029701473833e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.952380952380952381e-1 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.583211843519804309e0 * wr_4_0;
 results[k++] = 0.749805544402111380e-1 * wr_4_0 + 0.131013944022344018e1 * wr_6_0;
 results[k++] = -0.123205623123443351e0 * wr_4_0 - 0.127572075535567886e1 * wr_6_0;
 results[k++] = -0.789311947385871995e0 * wr_6_0 + 0.522717189545405384e0 * wr_4_0;
 results[k++] = 0.730760865880454901e0 * wr_6_0 + 0.501865861339893977e0 * wr_4_0;
 results[k++] = -0.516725963689822825e0 * wr_6_0 - 0.354872753799466611e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.116883116883116883e0 * wr_4_0 - 0.378204679244474401e0 * wr_6_0;
 results[k++] = 0.452686365141126648e0 * wr_4_0 - 0.683564197946731387e0 * wr_6_0;
 results[k++] = 0.106383053042750338e0 * wr_4_0 + 0.596663748467175994e0 * wr_6_0 
             - 0.561903259060819587e0 * wr_8_0;
 results[k++] = 0.452686365141126648e0 * wr_4_0 - 0.683564197946731387e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.350649350649350649e0 * wr_4_0 - 0.252136452829649601e-1 * wr_6_0;
 results[k++] = 0.462173752219812755e0 * wr_6_0 - 0.435248392904445214e0 * wr_8_0 
             + 0.824039585506544655e-1 * wr_4_0;
 results[k++] = 0.106383053042750338e0 * wr_4_0 + 0.596663748467175994e0 * wr_6_0 
             - 0.561903259060819587e0 * wr_8_0;
 results[k++] = 0.462173752219812755e0 * wr_6_0 - 0.435248392904445214e0 * wr_8_0 
             + 0.824039585506544655e-1 * wr_4_0;
 results[k++] = wr_0_0 + 0.251748251748251748e0 * wr_4_0 - 0.806836649054878721e0 * wr_6_0 
             - 0.949789860282143113e-1 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.458138755162699669e0 * wr_4_0 + 0.667090350641220733e0 * wr_6_0;
 results[k++] = -0.558452438752633937e0 * wr_8_0 + 0.872181209038214775e-1 * wr_4_0 
             + 0.566044932723022720e0 * wr_6_0;
 results[k++] = 0.471168995160146335e0 * wr_4_0 - 0.305788314862575327e0 * wr_6_0 
             + 0.731361707129005037e-1 * wr_8_0;
 results[k++] = -0.323219264131930762e0 * wr_8_0 - 0.720749970156447168e0 * wr_6_0 
             + 0.237976279687565047e0 * wr_4_0;
 results[k++] = 0.603557936294437806e0 * wr_4_0 + 0.137441626548809901e0 * wr_6_0 
             + 0.542392358592982847e0 * wr_8_0;
 results[k++] = -0.383529314824863744e0 * wr_8_0 - 0.301633921065556324e0 * wr_4_0 
             - 0.583115436899835021e0 * wr_6_0;
 results[k++] = -0.605135624764448152e0 * wr_8_0;
 results[k++] = 0.654326589163349245e0 * wr_4_0 + 0.440385506050544242e0 * wr_6_0 
             - 0.204073240277899699e0 * wr_8_0;
 results[k++] = 0.859337848847319459e0 * wr_6_0 + 0.222657525719164264e0 * wr_8_0;
 results[k++] = -0.121109727937107048e0 * wr_8_0 - 0.437740305698434457e0 * wr_4_0 
             + 0.920672151894242381e0 * wr_6_0;
 results[k++] = -0.377665541865259920e0 * wr_4_0 - 0.653612388562121543e0 * wr_6_0 
             + 0.131900181481405717e0 * wr_8_0;
 results[k++] = 0.752241782098569426e-1 * wr_4_0 + 0.421904982629324646e0 * wr_6_0 
             - 0.397325604852726885e0 * wr_8_0;
 results[k++] = 0.430384771925125789e0 * wr_10_0 + 0.164280420431434680e0 * wr_8_0 
             - 0.510697023314840200e-1 * wr_4_0 + 0.454920357406566824e0 * wr_6_0;
 results[k++] = -0.624187783932359260e0 * wr_6_0 - 0.279916093730764466e0 * wr_8_0 
             + 0.206093503707542025e0 * wr_4_0;
 results[k++] = 0.134097046880302260e0 * wr_4_0 - 0.474013508250223705e-1 * wr_6_0 
             + 0.102705192886233326e0 * wr_8_0 - 0.107149212862047058e1 * wr_10_0;
 results[k++] = 0.697265660246228560e-1 * wr_8_0 - 0.372648635541050492e0 * wr_10_0 
             + 0.429181494970749005e0 * wr_4_0;
 results[k++] = -0.261222638285881910e0 * wr_4_0 - 0.504992781694118979e0 * wr_6_0 
             - 0.332146129734371713e0 * wr_8_0;
 results[k++] = -0.271224631690280131e0 * wr_4_0 - 0.396279004164344417e0 * wr_6_0 
             - 0.677050752088668300e-1 * wr_8_0 - 0.361199922873183882e0 * wr_10_0;
 results[k++] = 0.820119337440890437e0 * wr_6_0 + 0.526098372510995646e-1 * wr_4_0 
             + 0.319665560322077307e0 * wr_8_0 + 0.650267352263012175e0 * wr_10_0;
 results[k++] = 0.462221150408058091e0 * wr_10_0 - 0.503700843188519135e-1 * wr_4_0 
             + 0.279051489968316089e0 * wr_8_0 - 0.168258103984516291e0 * wr_6_0;
 results[k++] = -0.187542123769025411e0 * wr_10_0 - 0.627539094221605703e-1 * wr_8_0 
             + 0.273115496799567549e0 * wr_4_0 + 0.912325168435054369e0 * wr_6_0;
 results[k++] = -0.170414542270490852e0 * wr_8_0 - 0.234388903135727940e0 * wr_10_0 
             - 0.119197375004713120e0 * wr_4_0 - 0.398171346930187912e0 * wr_6_0;
 results[k++] = 0.336972644440186942e-1 * wr_4_0 - 0.351761237689984980e0 * wr_6_0 
             + 0.165606475324668382e0 * wr_8_0 - 0.100497473410106323e1 * wr_10_0;
 results[k++] = -0.316068776376191969e0 * wr_6_0 + 0.228390652007755534e0 * wr_4_0 
             + 0.407759566608181848e0 * wr_10_0 - 0.461801607088716113e0 * wr_8_0;
 results[k++] = -0.246407351119698603e0 * wr_10_0 + 0.348872483615285911e0 * wr_4_0 
             + 0.819419846335603224e-1 * wr_8_0 + 0.665935214968262024e-1 * wr_6_0;
 results[k++] = -0.889893362928175062e0 * wr_6_0 - 0.124972350037124094e0 * wr_8_0 
             - 0.785771493300358371e-1 * wr_10_0 + wr_0_0 + 0.261072261072261072e0 * wr_4_0;
 results[k++] = -0.340180106182257858e0 * wr_10_0 + 0.391787310098782055e0 * wr_4_0 
             + 0.636513551150987569e-1 * wr_8_0;
 results[k++] = 0.480259910151713525e-1 * wr_4_0 + 0.593610162072682990e0 * wr_10_0 
             + 0.291813397076550224e0 * wr_8_0 + 0.748663101604278075e0 * wr_6_0;
 results[k++] = 0.127536507874783213e0 * wr_6_0 - 0.706510570841336836e0 * wr_12_4 
             + 0.144015642100331981e-1 * wr_4_0 + 0.502356871863906090e0 * wr_10_0 
             - 0.435447936430230328e0 * wr_12_0 + 0.129638734622868732e0 * wr_8_0;
 results[k++] = 0.528115556908779555e0 * wr_10_0 + 0.400553843375241268e0 * wr_12_0 
             - 0.213302771388987750e-1 * wr_6_0 - 0.623353797090870579e-1 * wr_8_0 
             - 0.421511755078551970e-1 * wr_4_0 - 0.768057965807101596e0 * wr_12_4;
 results[k++] = -0.340180106182257858e0 * wr_10_0 + 0.391787310098782055e0 * wr_4_0 
             + 0.636513551150987569e-1 * wr_8_0;
 results[k++] = 0.446507897890277313e0 * wr_6_0 - 0.798900018021576570e-1 * wr_8_0 
             + 0.196384771321739966e-1 * wr_10_0 + wr_0_0 - 0.204881952781112445e0 * wr_4_0 
             - 0.301986973279014123e0 * wr_12_0 + 0.605757017641839937e0 * wr_12_4;
 results[k++] = 0.186422840827509207e0 * wr_10_0 + 0.451553345019564458e0 * wr_6_0 
             + 0.140509117114442230e-1 * wr_8_0 + 0.335616591891729085e0 * wr_12_0 
             + 0.172664230482783087e0 * wr_4_0 - 0.445528688705751488e0 * wr_12_4;
 results[k++] = 0.550129135048720287e-1 * wr_4_0 - 0.361478902412882696e0 * wr_12_0 
             - 0.152298905832355826e0 * wr_10_0 + 0.487180057256621141e0 * wr_6_0 
             + 0.353721720317435684e-1 * wr_8_0 - 0.630892587748734474e-1 * wr_12_4;
 results[k++] = -0.423696447528272289e0 * wr_6_0 + 0.708714303093544575e0 * wr_12_4 
             + 0.392264928856200015e0 * wr_10_0 - 0.782069859216227040e-1 * wr_4_0 
             - 0.327213228667266020e0 * wr_12_0 + 0.330405206980044368e0 * wr_8_0;
 results[k++] = 0.480259910151713525e-1 * wr_4_0 + 0.593610162072682990e0 * wr_10_0 
             + 0.291813397076550224e0 * wr_8_0 + 0.748663101604278075e0 * wr_6_0;
 results[k++] = 0.186422840827509207e0 * wr_10_0 + 0.451553345019564458e0 * wr_6_0 
             + 0.140509117114442230e-1 * wr_8_0 + 0.335616591891729085e0 * wr_12_0 
             + 0.172664230482783087e0 * wr_4_0 - 0.445528688705751488e0 * wr_12_4;
 results[k++] = -0.243549762485605806e0 * wr_6_0 + 0.694695667844849192e-2 * wr_8_0 
             - 0.471323451172175917e-1 * wr_10_0 + wr_0_0 + 0.367856233402451890e0 * wr_4_0 
             + 0.478653704044546881e0 * wr_12_0 + 0.550688197856218125e0 * wr_12_4;
 results[k++] = -0.813224818814574319e0 * wr_10_0 - 0.525530764155597408e0 * wr_6_0 
             - 0.255172674651455880e0 * wr_8_0 - 0.593435179498991281e-1 * wr_4_0 
             - 0.213609505114854299e0 * wr_12_0 + 0.359182498750943900e0 * wr_12_4;
 results[k++] = 0.701980475168181752e-1 * wr_8_0 + 0.318844112048702199e0 * wr_4_0 
             + 0.255439815936827944e0 * wr_12_0 - 0.158678976650402096e0 * wr_10_0 
             + 0.113031525642696826e0 * wr_12_4 - 0.258189155241097999e0 * wr_6_0;
 results[k++] = 0.127536507874783213e0 * wr_6_0 - 0.706510570841336836e0 * wr_12_4 
             + 0.144015642100331981e-1 * wr_4_0 + 0.502356871863906090e0 * wr_10_0 
             - 0.435447936430230328e0 * wr_12_0 + 0.129638734622868732e0 * wr_8_0;
 results[k++] = 0.550129135048720287e-1 * wr_4_0 - 0.361478902412882696e0 * wr_12_0 
             - 0.152298905832355826e0 * wr_10_0 + 0.487180057256621141e0 * wr_6_0 
             + 0.353721720317435684e-1 * wr_8_0 - 0.630892587748734474e-1 * wr_12_4;
 results[k++] = -0.813224818814574319e0 * wr_10_0 - 0.525530764155597408e0 * wr_6_0 
             - 0.255172674651455880e0 * wr_8_0 - 0.593435179498991281e-1 * wr_4_0 
             - 0.213609505114854299e0 * wr_12_0 + 0.359182498750943900e0 * wr_12_4;
 results[k++] = -0.389143977634463193e0 * wr_10_0 - 0.595343863853703080e0 * wr_6_0 
             - 0.729430451237091651e-1 * wr_8_0 + 0.139201738902544026e0 * wr_12_4 + wr_0_0 
             + 0.487394957983193277e0 * wr_4_0 - 0.100122428834233922e0 * wr_12_0;
 results[k++] = 0.778174774441560141e-2 * wr_10_0 - 0.983814129420106787e-1 * wr_4_0 
             + 0.984813273768607974e-1 * wr_12_0 - 0.109242874740262849e0 * wr_12_4 
             - 0.121996077340576946e0 * wr_8_0 - 0.871240211370214801e0 * wr_6_0;
 results[k++] = 0.528115556908779555e0 * wr_10_0 + 0.400553843375241268e0 * wr_12_0 
             - 0.213302771388987750e-1 * wr_6_0 - 0.623353797090870579e-1 * wr_8_0 
             - 0.421511755078551970e-1 * wr_4_0 - 0.768057965807101596e0 * wr_12_4;
 results[k++] = -0.423696447528272289e0 * wr_6_0 + 0.708714303093544575e0 * wr_12_4 
             + 0.392264928856200015e0 * wr_10_0 - 0.782069859216227040e-1 * wr_4_0 
             - 0.327213228667266020e0 * wr_12_0 + 0.330405206980044368e0 * wr_8_0;
 results[k++] = 0.701980475168181752e-1 * wr_8_0 + 0.318844112048702199e0 * wr_4_0 
             + 0.255439815936827944e0 * wr_12_0 - 0.158678976650402096e0 * wr_10_0 
             + 0.113031525642696826e0 * wr_12_4 - 0.258189155241097999e0 * wr_6_0;
 results[k++] = 0.778174774441560141e-2 * wr_10_0 - 0.983814129420106787e-1 * wr_4_0 
             + 0.984813273768607974e-1 * wr_12_0 - 0.109242874740262849e0 * wr_12_4 
             - 0.121996077340576946e0 * wr_8_0 - 0.871240211370214801e0 * wr_6_0;
 results[k++] = 0.308080041434783413e0 * wr_6_0 - 0.286161177023782109e0 * wr_8_0 
             + 0.806920622519622674e-1 * wr_10_0 + wr_0_0 - 0.248339895398718928e0 * wr_4_0 
             + 0.101137754873116295e0 * wr_12_0 + 0.535391303471323178e-1 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::setup___ar_2_T2u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,4,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,12,5,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=2)
void BoxMatrix::evaluate___ar_2_T2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = 0.466569474815843447e0 * wr_4_0;
 results[k++] = -0.690065559342354218e0 * wr_4_0;
 results[k++] = -0.260820265478650530e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.190476190476190476e0 * wr_4_0;
 results[k++] = -0.563436169819011052e0 * wr_4_0;
 results[k++] = 0.174239063181801795e0 * wr_4_0 - 0.150345132835404189e1 * wr_6_0;
 results[k++] = -0.563436169819011052e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.303030303030303030e-1 * wr_4_0 + 0.113461403773342320e1 * wr_6_0;
 results[k++] = 0.515406099558037127e0 * wr_4_0 - 0.778272075748090855e0 * wr_6_0;
 results[k++] = 0.174239063181801795e0 * wr_4_0 - 0.150345132835404189e1 * wr_6_0;
 results[k++] = 0.515406099558037127e0 * wr_4_0 - 0.778272075748090855e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.506493506493506494e0 * wr_4_0 + 0.210113710691374667e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.148453923805041097e0 * wr_4_0 - 0.148225357197110716e1 * wr_6_0;
 results[k++] = 0.526361355967815189e0 * wr_4_0 + 0.766428462031902497e0 * wr_6_0;
 results[k++] = 0.497364731301993823e0 * wr_4_0 - 0.869048189253481640e0 * wr_6_0;
 results[k++] = 0.637114143531956023e0 * wr_4_0 + 0.390608113112417935e0 * wr_6_0;
 results[k++] = -0.311688311688311688e0 * wr_4_0 + 0.470654711948679254e0 * wr_6_0;
 results[k++] = 0.460993229851918134e0 * wr_4_0 - 0.696107706545038659e0 * wr_6_0;
 results[k++] = 0.174239063181801795e0 * wr_4_0 - 0.263103982461957331e0 * wr_6_0;
 results[k++] = 0.429772247480202826e0 * wr_4_0 + 0.625786218774743878e0 * wr_6_0;
 results[k++] = -0.268925345684654243e0 * wr_4_0 - 0.498074004683101846e0 * wr_8_0;
 results[k++] = 0.831634580949746732e-1 * wr_4_0 - 0.439259983632502582e0 * wr_8_0 
             + 0.466433508187627491e0 * wr_6_0;
 results[k++] = -0.624764003972484789e-1 * wr_4_0 + 0.709574875186899142e0 * wr_6_0 
             + 0.848554157940544245e-1 * wr_8_0;
 results[k++] = -0.313757131166073273e0 * wr_8_0 + 0.231009605819374093e0 * wr_4_0 
             - 0.699650262281441238e0 * wr_6_0;
 results[k++] = 0.157164163062460272e0 * wr_4_0 - 0.881476475579908486e-1 * wr_6_0 
             - 0.213460287721329363e0 * wr_8_0;
 results[k++] = -0.800310030545443988e-1 * wr_4_0 - 0.318930188838919714e0 * wr_6_0 
             + 0.629304606233739849e0 * wr_8_0;
 results[k++] = -0.292803691605686389e0 * wr_4_0 - 0.566044932723022720e0 * wr_6_0 
             - 0.372301625835089292e0 * wr_8_0;
 results[k++] = -0.317880171362583802e0 * wr_4_0 - 0.736921235064691513e0 * wr_6_0 
             + 0.140716787809238021e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.545454545454545455e0 * wr_4_0 + 0.268945549684959574e0 * wr_6_0;
 results[k++] = 0.417190812516495919e0 * wr_6_0 + 0.743836582177274122e-1 * wr_4_0 
             - 0.392886073279088307e0 * wr_8_0;
 results[k++] = -0.281143801787618156e-1 * wr_4_0 + 0.463774428226731466e-1 * wr_6_0 
             + 0.351703368093778207e0 * wr_8_0 - 0.117939039865471721e1 * wr_10_0;
 results[k++] = 0.568641337492815465e-1 * wr_4_0 + 0.387719053098294555e0 * wr_6_0 
             - 0.231849065454535734e0 * wr_8_0 - 0.397572422281739302e0 * wr_10_0;
 results[k++] = 0.417190812516495919e0 * wr_6_0 + 0.743836582177274122e-1 * wr_4_0 
             - 0.392886073279088307e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.205128205128205128e0 * wr_4_0 - 0.391553079688397026e0 * wr_6_0 
             + 0.549878340163346011e-1 * wr_8_0 + 0.392885746650179185e0 * wr_10_0;
 results[k++] = 0.426421456728358923e0 * wr_4_0 + 0.692781590196758872e-1 * wr_8_0 
             - 0.370252156435776198e0 * wr_10_0;
 results[k++] = 0.522715068141154405e-1 * wr_4_0 + 0.646085525271272980e0 * wr_10_0 
             + 0.814845203394606014e0 * wr_6_0 + 0.317609811922850263e0 * wr_8_0;
 results[k++] = -0.281143801787618156e-1 * wr_4_0 + 0.463774428226731466e-1 * wr_6_0 
             + 0.351703368093778207e0 * wr_8_0 - 0.117939039865471721e1 * wr_10_0;
 results[k++] = 0.426421456728358923e0 * wr_4_0 + 0.692781590196758872e-1 * wr_8_0 
             - 0.370252156435776198e0 * wr_10_0;
 results[k++] = wr_0_0 - 0.234432234432234432e0 * wr_4_0 + 0.652588466147328378e0 * wr_6_0 
             - 0.301123852946594245e0 * wr_8_0 - 0.187088450785799612e-1 * wr_10_0;
 results[k++] = 0.197567725263953725e0 * wr_4_0 + 0.659962581182440362e0 * wr_6_0 
             + 0.529611287585205328e-1 * wr_8_0 - 0.177598090965851966e0 * wr_10_0;
 results[k++] = 0.568641337492815465e-1 * wr_4_0 + 0.387719053098294555e0 * wr_6_0 
             - 0.231849065454535734e0 * wr_8_0 - 0.397572422281739302e0 * wr_10_0;
 results[k++] = 0.522715068141154405e-1 * wr_4_0 + 0.646085525271272980e0 * wr_10_0 
             + 0.814845203394606014e0 * wr_6_0 + 0.317609811922850263e0 * wr_8_0;
 results[k++] = 0.197567725263953725e0 * wr_4_0 + 0.659962581182440362e0 * wr_6_0 
             + 0.529611287585205328e-1 * wr_8_0 - 0.177598090965851966e0 * wr_10_0;
 results[k++] = wr_0_0 + 0.420912420912420912e0 * wr_4_0 - 0.355957345171270024e0 * wr_6_0 
             + 0.261846828649212387e-1 * wr_8_0 + 0.449012281885919069e-1 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::setup___ar_3_G1g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,2,1,1,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,1,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,2,1,7,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,7,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,2,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,2,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,11,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,2,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,2,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,15,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::evaluate___ar_3_G1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0;
 results[k++] = 0.699854212223765171e0 * wr_4_0;
 results[k++] = 0.699854212223765171e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.285714285714285714e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.521640530957301061e0 * wr_4_0;
 results[k++] = -0.348478126363603589e0 * wr_4_0 - 0.112758849626553142e1 * wr_6_0;
 results[k++] = -0.416125189288239507e0 * wr_4_0;
 results[k++] = -0.277989377147795752e0 * wr_4_0 - 0.899504445305733909e0 * wr_6_0;
 results[k++] = -0.158665765604383528e1 * wr_6_0;
 results[k++] = -0.606622553892095820e0 * wr_4_0 + 0.412204720856279096e0 * wr_6_0;
 results[k++] = wr_0_0 + 0.779220779220779221e-1 * wr_4_0 - 0.672363874212398935e0 * wr_6_0;
 results[k++] = -0.239078132432806886e0 * wr_4_0 - 0.455906699440488863e0 * wr_6_0 
             + 0.606136159962323282e0 * wr_8_0;
 results[k++] = 0.281724078569660837e0 * wr_4_0 - 0.737374221184772301e0 * wr_6_0 
             + 0.231472069539767318e0 * wr_8_0;
 results[k++] = -0.239078132432806886e0 * wr_4_0 - 0.455906699440488863e0 * wr_6_0 
             + 0.606136159962323282e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.186904005085823268e0 * wr_4_0 - 0.464542313092202900e0 * wr_6_0 
             - 0.276302504809350724e0 * wr_8_0;
 results[k++] = 0.224738068774512179e0 * wr_4_0 - 0.588221139188852597e0 * wr_6_0 
             + 0.184650833353401000e0 * wr_8_0;
 results[k++] = 0.281724078569660837e0 * wr_4_0 - 0.737374221184772301e0 * wr_6_0 
             + 0.231472069539767318e0 * wr_8_0;
 results[k++] = 0.224738068774512179e0 * wr_4_0 - 0.588221139188852597e0 * wr_6_0 
             + 0.184650833353401000e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.480610298792116974e0 * wr_4_0 - 0.733487862777162473e-1 * wr_6_0 
             + 0.181323518781136412e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.882734829504749529e0 * wr_4_0;
 results[k++] = 0.352814670705953158e-1 * wr_4_0 + 0.508836554386502718e0 * wr_6_0 
             + 0.753017114798575855e0 * wr_8_0;
 results[k++] = 0.108389352559426925e1 * wr_6_0;
 results[k++] = 0.239078132432806886e0 * wr_4_0 - 0.724087110876070546e0 * wr_6_0 
             + 0.238124919985198432e0 * wr_8_0;
 results[k++] = 0.928190961784514221e0 * wr_6_0;
 results[k++] = 0.204734281038153814e0 * wr_4_0 - 0.620071156427787390e0 * wr_6_0 
             + 0.203917998665726533e0 * wr_8_0;
 results[k++] = 0.799286669497027599e0 * wr_8_0;
 results[k++] = 0.831634580949746732e0 * wr_4_0 + 0.559720209825152991e0 * wr_6_0 
             + 0.175703993453001033e0 * wr_8_0;
 results[k++] = -0.236675276147314494e0 * wr_4_0 - 0.910234500035991094e0 * wr_6_0 
             - 0.275530492948971021e0 * wr_8_0;
 results[k++] = -0.188801556324443713e0 * wr_4_0 - 0.726115938362863193e0 * wr_6_0 
             - 0.219797296660710627e0 * wr_8_0;
 results[k++] = 0.171267417323764469e0 * wr_6_0 - 0.164927818630657228e0 * wr_8_0 
             - 0.235427870253668522e-1 * wr_4_0 - 0.101847625925607036e1 * wr_10_0;
 results[k++] = -0.427675964842762695e0 * wr_4_0 - 0.899504445305733909e-1 * wr_6_0 
             + 0.161352578249576338e0 * wr_8_0;
 results[k++] = 0.221758807685929557e0 * wr_4_0 - 0.843378467424538511e0 * wr_10_0 
             - 0.489626662549524873e0 * wr_6_0 + 0.616476290161760328e-1 * wr_8_0;
 results[k++] = 0.156342541883681095e0 * wr_4_0 + 0.663177707409398280e-1 * wr_6_0 
             - 0.502920857953314240e0 * wr_8_0 + 0.536784120342888310e0 * wr_10_0;
 results[k++] = 0.189223904820021365e0 * wr_4_0 - 0.489360443526860564e0 * wr_6_0 
             + 0.719959747661488325e-1 * wr_8_0 - 0.832198142414860681e0 * wr_10_0;
 results[k++] = 0.320989409360188128e0 * wr_10_0 + 0.975936469215139810e-1 * wr_6_0 
             + 0.135750537023322187e0 * wr_8_0 - 0.506407726416575528e0 * wr_4_0;
 results[k++] = 0.133883754162371856e0 * wr_4_0 + 0.567911459510643566e-1 * wr_6_0 
             - 0.430675692604808647e0 * wr_8_0 + 0.459674458022571476e0 * wr_10_0;
 results[k++] = -0.991782109569698829e-1 * wr_4_0 - 0.331298586410158524e0 * wr_6_0 
             - 0.563400805770419541e0 * wr_10_0 - 0.372207858895978396e0 * wr_8_0;
 results[k++] = -0.449438364223950679e0 * wr_10_0 - 0.296919155138152953e0 * wr_8_0 
             - 0.264284845212953883e0 * wr_6_0 - 0.791168426502430798e-1 * wr_4_0;
 results[k++] = -0.370246123456577452e-1 * wr_8_0 - 0.121110530821804874e1 * wr_6_0 
             - 0.362558920190649524e0 * wr_4_0 + 0.565820144031150198e-1 * wr_10_0;
 results[k++] = 0.733487862777162473e0 * wr_6_0 + 0.863445327529221012e-1 * wr_8_0 + wr_0_0 
             + 0.498410680228862047e0 * wr_4_0;
 results[k++] = -0.537235344835613423e0 * wr_6_0 + 0.201191337791126049e0 * wr_8_0 
             + 0.298179316711304476e0 * wr_10_0 + 0.192993423633925249e0 * wr_4_0;
 results[k++] = 0.172289968449319538e0 * wr_8_0 - 0.460060863592854427e0 * wr_6_0 
             + 0.255345511553610386e0 * wr_10_0 + 0.165269694182041151e0 * wr_4_0;
 results[k++] = 0.497427519237096432e0 * wr_10_0 + 0.204422134052687032e0 * wr_12_4 
             + 0.493624023035787742e-2 * wr_4_0 + 0.746264638578543546e0 * wr_12_0 
             + 0.437140599333138628e-1 * wr_6_0 + 0.116640860034649154e0 * wr_8_0;
 results[k++] = -0.537235344835613423e0 * wr_6_0 + 0.201191337791126049e0 * wr_8_0 
             + 0.298179316711304476e0 * wr_10_0 + 0.192993423633925249e0 * wr_4_0;
 results[k++] = -0.215731724346224257e-1 * wr_6_0 - 0.211316882790046195e0 * wr_8_0 
             + 0.419078129760191131e0 * wr_10_0 + wr_0_0 - 0.358550540368722187e0 * wr_4_0;
 results[k++] = -0.115537393669888332e1 * wr_12_4 + 0.510470242546475660e-1 * wr_6_0 
             + 0.132578594357412797e0 * wr_4_0 + 0.292562828554438015e-1 * wr_10_0 
             + 0.602544979002991541e0 * wr_12_0 - 0.300211742735852009e0 * wr_8_0;
 results[k++] = 0.349077355789729282e0 * wr_12_4 + 0.451654023612731950e-1 * wr_8_0 
             + 0.876532798198778671e-1 * wr_12_0 - 0.194464771768242050e0 * wr_10_0 
             + 0.622061978230710280e0 * wr_6_0 + 0.702439299255830870e-1 * wr_4_0;
 results[k++] = 0.172289968449319538e0 * wr_8_0 - 0.460060863592854427e0 * wr_6_0 
             + 0.255345511553610386e0 * wr_10_0 + 0.165269694182041151e0 * wr_4_0;
 results[k++] = -0.115537393669888332e1 * wr_12_4 + 0.510470242546475660e-1 * wr_6_0 
             + 0.132578594357412797e0 * wr_4_0 + 0.292562828554438015e-1 * wr_10_0 
             + 0.602544979002991541e0 * wr_12_0 - 0.300211742735852009e0 * wr_8_0;
 results[k++] = -0.374691942285547393e-1 * wr_6_0 - 0.117831072892145574e0 * wr_8_0 
             + 0.409967735634969585e0 * wr_10_0 + wr_0_0 - 0.399835458658988071e0 * wr_4_0 
             - 0.187632251985462377e0 * wr_12_0 + 0.359782955932729175e0 * wr_12_4;
 results[k++] = 0.298931988204300597e0 * wr_12_4 + 0.532702052581199862e0 * wr_6_0 
             + 0.750617843712763923e-1 * wr_12_0 - 0.166529681448006773e0 * wr_10_0 
             + 0.601533078089046838e-1 * wr_4_0 + 0.386773398559696921e-1 * wr_8_0;
 results[k++] = 0.497427519237096432e0 * wr_10_0 + 0.204422134052687032e0 * wr_12_4 
             + 0.493624023035787742e-2 * wr_4_0 + 0.746264638578543546e0 * wr_12_0 
             + 0.437140599333138628e-1 * wr_6_0 + 0.116640860034649154e0 * wr_8_0;
 results[k++] = 0.349077355789729282e0 * wr_12_4 + 0.451654023612731950e-1 * wr_8_0 
             + 0.876532798198778671e-1 * wr_12_0 - 0.194464771768242050e0 * wr_10_0 
             + 0.622061978230710280e0 * wr_6_0 + 0.702439299255830870e-1 * wr_4_0;
 results[k++] = 0.298931988204300597e0 * wr_12_4 + 0.532702052581199862e0 * wr_6_0 
             + 0.750617843712763923e-1 * wr_12_0 - 0.166529681448006773e0 * wr_10_0 
             + 0.601533078089046838e-1 * wr_4_0 + 0.386773398559696921e-1 * wr_8_0;
 results[k++] = 0.355305370883640307e0 * wr_10_0 + 0.570135746606334842e0 * wr_4_0 
             + 0.987912235832548122e-1 * wr_12_0 + 0.196385121486909290e0 * wr_8_0 
             - 0.134918608474773441e0 * wr_12_4 + 0.137387045504700711e0 * wr_6_0 + wr_0_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::setup___ar_3_G1u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,1,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,9,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,9,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,9,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(1,1,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,13,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::evaluate___ar_3_G1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = 0.356348322549899180e0 * wr_4_0;
 results[k++] = -0.796819072889595762e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.606060606060606061e-1 * wr_4_0 - 0.112060645702066489e1 * wr_6_0;
 results[k++] = -0.877013274873191104e0 * wr_6_0 - 0.271038542727247236e0 * wr_4_0;
 results[k++] = -0.877013274873191104e0 * wr_6_0 - 0.271038542727247236e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.424242424242424242e0 * wr_4_0 + 0.448242582808265956e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = -0.796819072889595762e0 * wr_4_0;
 results[k++] = 0.563436169819011052e0 * wr_4_0;
 results[k++] = -0.842650088469486327e0 * wr_6_0;
 results[k++] = 0.172691879389566526e1 * wr_6_0;
 results[k++] = -0.877013274873191104e0 * wr_6_0 - 0.271038542727247236e0 * wr_4_0;
 results[k++] = 0.759831888225714491e0 * wr_8_0 + 0.549097163940125797e0 * wr_6_0 
             + 0.466200466200466200e-1 * wr_4_0;
 results[k++] = -0.250623404302389039e0 * wr_4_0 - 0.496113627082764000e0 * wr_6_0 
             + 0.600699851404933492e0 * wr_8_0;
 results[k++] = -0.887475035776832790e0 * wr_6_0 - 0.268641140363090767e0 * wr_8_0 
             - 0.230757457729875649e0 * wr_4_0;
 results[k++] = -0.340698437597685379e0 * wr_4_0 + 0.239937417307921703e0 * wr_8_0 
             - 0.334399325695651230e0 * wr_6_0;
 results[k++] = -0.598191699108454638e0 * wr_6_0 + 0.187780731406186631e0 * wr_8_0 
             + 0.228547459888918395e0 * wr_4_0;
 results[k++] = 0.193951117561268924e0 * wr_4_0 - 0.587412587412587413e0 * wr_6_0 
             + 0.193177828019453836e0 * wr_8_0;
 results[k++] = 0.656747238146791380e0 * wr_6_0 - 0.785379554904113357e-1 * wr_8_0 
             - 0.693900613086480875e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.424242424242424242e0 * wr_4_0 + 0.448242582808265956e0 * wr_6_0;
 results[k++] = -0.887475035776832790e0 * wr_6_0 - 0.268641140363090767e0 * wr_8_0 
             - 0.230757457729875649e0 * wr_4_0;
 results[k++] = -0.598191699108454638e0 * wr_6_0 + 0.187780731406186631e0 * wr_8_0 
             + 0.228547459888918395e0 * wr_4_0;
 results[k++] = -0.173475153271620219e-1 * wr_4_0 + 0.154528761916892089e0 * wr_6_0 
             - 0.159142699283201917e0 * wr_8_0 - 0.101361476964046979e1 * wr_10_0;
 results[k++] = -0.887475035776832790e0 * wr_6_0 - 0.268641140363090767e0 * wr_8_0 
             - 0.230757457729875649e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.261072261072261072e0 * wr_4_0 - 0.179297033123306383e0 * wr_6_0 
             - 0.189957972056428623e0 * wr_8_0;
 results[k++] = 0.215476611613886223e0 * wr_4_0 - 0.847423471290119332e0 * wr_10_0 
             + 0.559078014962039002e-1 * wr_8_0 - 0.472748395934866535e0 * wr_6_0;
 results[k++] = 0.196264731593181363e0 * wr_4_0 + 0.303233563398453113e0 * wr_10_0 
             + 0.204601603344515621e0 * wr_8_0 - 0.546341677198979566e0 * wr_6_0;
 results[k++] = -0.598191699108454638e0 * wr_6_0 + 0.187780731406186631e0 * wr_8_0 
             + 0.228547459888918395e0 * wr_4_0;
 results[k++] = 0.215476611613886223e0 * wr_4_0 - 0.847423471290119332e0 * wr_10_0 
             + 0.559078014962039002e-1 * wr_8_0 - 0.472748395934866535e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.316299085529854761e0 * wr_4_0 - 0.365084456585917973e-2 * wr_6_0 
             - 0.347230867949301713e0 * wr_8_0 + 0.564143636215641906e0 * wr_10_0;
 results[k++] = 0.454201947982443956e0 * wr_10_0 + 0.132289843132345542e0 * wr_4_0 
             + 0.561150367807952389e-1 * wr_6_0 - 0.425548418268188973e0 * wr_8_0;
 results[k++] = -0.173475153271620219e-1 * wr_4_0 + 0.154528761916892089e0 * wr_6_0 
             - 0.159142699283201917e0 * wr_8_0 - 0.101361476964046979e1 * wr_10_0;
 results[k++] = 0.196264731593181363e0 * wr_4_0 + 0.303233563398453113e0 * wr_10_0 
             + 0.204601603344515621e0 * wr_8_0 - 0.546341677198979566e0 * wr_6_0;
 results[k++] = 0.454201947982443956e0 * wr_10_0 + 0.132289843132345542e0 * wr_4_0 
             + 0.561150367807952389e-1 * wr_6_0 - 0.425548418268188973e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.522861753630984400e0 * wr_4_0 - 0.912711141464794933e-1 * wr_6_0 
             + 0.317237503940391930e0 * wr_8_0 - 0.145065506455450776e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::setup___ar_3_G2g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,5,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,5,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,7,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,7,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,11,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,15,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::evaluate___ar_3_G2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 + 0.653061224489795918e0 * wr_4_0;
 results[k++] = 0.499895865874117978e0 * wr_4_0;
 results[k++] = 0.499895865874117978e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.367346938775510204e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = 0.499895865874117978e0 * wr_4_0;
 results[k++] = -0.185528756957328386e0 * wr_4_0 + 0.151281871697789760e1 * wr_6_0;
 results[k++] = 0.386149483955404682e0 * wr_4_0 + 0.110480658227309086e1 * wr_6_0;
 results[k++] = 0.448043305324633187e0 * wr_4_0 - 0.676553097759318853e0 * wr_6_0;
 results[k++] = -0.569062397407964793e0 * wr_4_0 - 0.828604936704818143e0 * wr_6_0;
 results[k++] = -0.232318750909069060e0 * wr_4_0 - 0.338276548879659426e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.367346938775510204e0 * wr_4_0;
 results[k++] = 0.448043305324633187e0 * wr_4_0 - 0.676553097759318853e0 * wr_6_0;
 results[k++] = 0.804180291608315975e-1 * wr_4_0 + 0.451035398506212569e0 * wr_6_0 
             - 0.424758938386179918e0 * wr_8_0;
 results[k++] = 0.448043305324633187e0 * wr_4_0 - 0.676553097759318853e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.403418324527439361e0 * wr_6_0 - 0.100185528756957328e0 * wr_4_0;
 results[k++] = 0.107892107892107892e0 * wr_4_0 + 0.605127486791159041e0 * wr_6_0 
             - 0.569873916169285869e0 * wr_8_0;
 results[k++] = 0.804180291608315975e-1 * wr_4_0 + 0.451035398506212569e0 * wr_6_0 
             - 0.424758938386179918e0 * wr_8_0;
 results[k++] = 0.107892107892107892e0 * wr_4_0 + 0.605127486791159041e0 * wr_6_0 
             - 0.569873916169285869e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.251748251748251748e0 * wr_4_0 - 0.806836649054878721e0 * wr_6_0 
             - 0.949789860282143113e-1 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = -0.598067114769061560e0 * wr_4_0 - 0.619953973934739169e0 * wr_6_0 
             - 0.319115679287219393e0 * wr_8_0;
 results[k++] = 0.915599539451716283e-1 * wr_4_0 + 0.594223395711187828e0 * wr_6_0 
             - 0.586252937381497635e0 * wr_8_0;
 results[k++] = 0.455155034887693299e0 * wr_4_0 - 0.306335832426993437e-1 * wr_6_0 
             + 0.703364370090160989e0 * wr_8_0;
 results[k++] = 0.445959035733409723e0 * wr_4_0 + 0.112554971906530035e1 * wr_6_0 
             - 0.168250372067871145e0 * wr_8_0;
 results[k++] = 0.221485691937184049e0 * wr_8_0 + 0.493388535449130081e0 * wr_4_0 
             + 0.126279518633396058e0 * wr_6_0;
 results[k++] = 0.406895197930025387e0 * wr_8_0 - 0.255327497913265900e0 * wr_4_0 
             + 0.332233006772849067e0 * wr_6_0;
 results[k++] = 0.604743156814763562e0 * wr_6_0 + 0.352555033085438851e0 * wr_8_0;
 results[k++] = 0.700298987745130225e0 * wr_4_0 - 0.100998556338823796e1 * wr_6_0 
             - 0.166073064867185857e0 * wr_8_0;
 results[k++] = -0.457799769725858142e0 * wr_4_0 - 0.792297860948250437e0 * wr_6_0 
             + 0.159887164740408446e0 * wr_8_0;
 results[k++] = -0.163787424830523051e0 * wr_4_0 + 0.738179948128318321e-1 * wr_6_0 
             - 0.397242854543623116e0 * wr_8_0;
 results[k++] = -0.818937124152615257e-1 * wr_4_0 + 0.729495478150338107e0 * wr_6_0 
             + 0.263434735118402698e0 * wr_8_0 + 0.690151011869427829e0 * wr_10_0;
 results[k++] = -0.743265059555682872e-1 * wr_4_0 - 0.187591619844216724e0 * wr_6_0 
             + 0.538401190617187661e0 * wr_8_0;
 results[k++] = 0.325360311404125121e0 * wr_10_0 + 0.888284359018518580e0 * wr_6_0 
             + 0.412173817219800262e0 * wr_4_0 - 0.594030425026408013e-1 * wr_8_0;
 results[k++] = -0.690887834792181116e0 * wr_6_0 - 0.505470483788551529e0 * wr_10_0 
             - 0.930715071141484464e-1 * wr_4_0 - 0.277214198345657073e0 * wr_8_0;
 results[k++] = -0.805700104526305729e-1 * wr_4_0 + 0.773300964040252140e0 * wr_6_0 
             + 0.169539665804177245e0 * wr_8_0;
 results[k++] = -0.235984251968385944e0 * wr_4_0 + 0.262198442651731251e0 * wr_6_0 
             + 0.143659787729963444e0 * wr_8_0 + 0.968658157786347899e0 * wr_10_0;
 results[k++] = 0.351271639636807480e0 * wr_10_0 - 0.497343154686060700e0 * wr_4_0 
             - 0.949339188911440737e-1 * wr_6_0 - 0.116814271841030881e0 * wr_8_0;
 results[k++] = -0.108920011737947231e0 * wr_6_0 - 0.227257878239306962e0 * wr_8_0 
             + 0.122405612519683903e1 * wr_10_0;
 results[k++] = -0.835155275291948456e-1 * wr_4_0 - 0.401437329951551700e0 * wr_10_0 
             + 0.351805890576088099e0 * wr_8_0 + 0.597810805419579591e0 * wr_6_0;
 results[k++] = -0.250546582587584537e0 * wr_4_0 + 0.860222849896182215e-1 * wr_10_0 
             - 0.995006559205097651e-1 * wr_8_0 - 0.154987986590261376e0 * wr_6_0;
 results[k++] = -0.237304896780846683e0 * wr_6_0 + 0.110689795747167055e0 * wr_8_0 
             + 0.538814738263102882e0 * wr_10_0 + wr_0_0 + 0.187812187812187812e0 * wr_4_0;
 results[k++] = -0.621008212975079715e0 * wr_6_0 - 0.702078068496102183e0 * wr_12_4 
             - 0.193238111705639916e0 * wr_8_0 - 0.294246897293175632e0 * wr_12_0 
             - 0.921642036789233848e-1 * wr_4_0 - 0.321710010001681167e-1 * wr_10_0;
 results[k++] = 0.223569142660637791e-1 * wr_10_0 + 0.501652075890907930e0 * wr_12_4 
             - 0.261619143320931713e0 * wr_12_0 - 0.492494827128853500e0 * wr_4_0 
             - 0.853318590260662413e-1 * wr_6_0 - 0.814278974364941589e-1 * wr_8_0;
 results[k++] = -0.295647021300956634e0 * wr_10_0 - 0.597962821408269505e0 * wr_12_0 
             + 0.485421144268690805e-1 * wr_4_0 + 0.121378371714065475e0 * wr_8_0 
             + 0.440995267538240159e0 * wr_12_4 + 0.796067302208328202e-1 * wr_6_0;
 results[k++] = -0.621008212975079715e0 * wr_6_0 - 0.702078068496102183e0 * wr_12_4 
             - 0.193238111705639916e0 * wr_8_0 - 0.294246897293175632e0 * wr_12_0 
             - 0.921642036789233848e-1 * wr_4_0 - 0.321710010001681167e-1 * wr_10_0;
 results[k++] = 0.649482936023858626e0 * wr_10_0 - 0.293831003772956682e0 * wr_6_0 
             + 0.428246264919840905e-1 * wr_8_0 - 0.452630170366981865e0 * wr_12_4 + wr_0_0 
             + 0.296015180265654649e0 * wr_4_0 + 0.327026691388151924e0 * wr_12_0;
 results[k++] = 0.730064581457399157e-1 * wr_4_0 + 0.516569736255738700e0 * wr_12_0 
             - 0.206207967748904619e-1 * wr_8_0 + 0.129929536894440179e0 * wr_10_0 
             - 0.111632537083876870e0 * wr_12_4 + 0.290936794419689421e0 * wr_6_0;
 results[k++] = 0.418865869425138717e0 * wr_4_0 - 0.103703803482090372e0 * wr_10_0 
             + 0.277861622464640234e0 * wr_8_0 - 0.179456099878106091e0 * wr_12_0 
             + 0.126661319842452619e0 * wr_6_0 + 0.285090996334780852e0 * wr_12_4;
 results[k++] = 0.223569142660637791e-1 * wr_10_0 + 0.501652075890907930e0 * wr_12_4 
             - 0.261619143320931713e0 * wr_12_0 - 0.492494827128853500e0 * wr_4_0 
             - 0.853318590260662413e-1 * wr_6_0 - 0.814278974364941589e-1 * wr_8_0;
 results[k++] = 0.730064581457399157e-1 * wr_4_0 + 0.516569736255738700e0 * wr_12_0 
             - 0.206207967748904619e-1 * wr_8_0 + 0.129929536894440179e0 * wr_10_0 
             - 0.111632537083876870e0 * wr_12_4 + 0.290936794419689421e0 * wr_6_0;
 results[k++] = 0.271349487235823839e0 * wr_6_0 + 0.106428065838066970e0 * wr_8_0 
             + 0.216004505872188276e0 * wr_10_0 + wr_0_0 - 0.123246772203128939e0 * wr_4_0 
             - 0.423685730289753755e0 * wr_12_0 + 0.812413126299711040e0 * wr_12_4;
 results[k++] = -0.131021255680358047e0 * wr_4_0 + 0.427493782898925460e0 * wr_10_0 
             + 0.296444692649524062e-1 * wr_12_0 - 0.522130577166072449e0 * wr_6_0 
             + 0.183681948106155278e0 * wr_8_0 + 0.432881091754196147e0 * wr_12_4;
 results[k++] = -0.295647021300956634e0 * wr_10_0 - 0.597962821408269505e0 * wr_12_0 
             + 0.485421144268690805e-1 * wr_4_0 + 0.121378371714065475e0 * wr_8_0 
             + 0.440995267538240159e0 * wr_12_4 + 0.796067302208328202e-1 * wr_6_0;
 results[k++] = 0.418865869425138717e0 * wr_4_0 - 0.103703803482090372e0 * wr_10_0 
             + 0.277861622464640234e0 * wr_8_0 - 0.179456099878106091e0 * wr_12_0 
             + 0.126661319842452619e0 * wr_6_0 + 0.285090996334780852e0 * wr_12_4;
 results[k++] = -0.131021255680358047e0 * wr_4_0 + 0.427493782898925460e0 * wr_10_0 
             + 0.296444692649524062e-1 * wr_12_0 - 0.522130577166072449e0 * wr_6_0 
             + 0.183681948106155278e0 * wr_8_0 + 0.432881091754196147e0 * wr_12_4;
 results[k++] = -0.306360789519578493e0 * wr_8_0 + 0.107161895493666555e1 * wr_6_0 
             - 0.219950943880348762e0 * wr_10_0 - 0.134918608474773441e0 * wr_12_4 
             - 0.504201680672268908e-1 * wr_4_0 + 0.781801049939426572e-2 * wr_12_0 + wr_0_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::setup___ar_3_G2u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,5,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,7,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,13,5,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::evaluate___ar_3_G2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = 0.699854212223765171e0 * wr_4_0;
 results[k++] = 0.521640530957301062e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.285714285714285714e0 * wr_4_0;
 results[k++] = 0.348478126363603589e0 * wr_4_0 + 0.112758849626553142e1 * wr_6_0;
 results[k++] = 0.348478126363603589e0 * wr_4_0 + 0.112758849626553142e1 * wr_6_0;
 results[k++] = wr_0_0 + 0.779220779220779221e-1 * wr_4_0 - 0.672363874212398935e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.148225357197110716e1 * wr_6_0 - 0.148453923805041097e0 * wr_4_0;
 results[k++] = -0.901853927001594838e0 * wr_6_0 - 0.619367728911011003e0 * wr_4_0;
 results[k++] = 0.501359692919287570e0 * wr_4_0 + 0.194673024029224601e0 * wr_6_0;
 results[k++] = -0.802492335635490748e0 * wr_6_0 + 0.543474433241650744e0 * wr_4_0;
 results[k++] = 0.467532467532467532e0 * wr_4_0 - 0.705982067923018881e0 * wr_6_0;
 results[k++] = 0.348478126363603589e0 * wr_4_0 - 0.526207964923914663e0 * wr_6_0;
 results[k++] = -0.515436856704211390e0 * wr_4_0 - 0.490907098595363472e0 * wr_6_0 
             - 0.330219849604766385e0 * wr_8_0;
 results[k++] = -0.130477567890502062e0 * wr_4_0 + 0.274425410774106063e0 * wr_6_0 
             - 0.590715224988811761e0 * wr_8_0;
 results[k++] = 0.684295970784690738e0 * wr_8_0 - 0.238424787778084409e0 * wr_6_0 
             - 0.944673404039014512e-1 * wr_4_0;
 results[k++] = -0.159388782021226938e0 * wr_8_0 + 0.106626806598551556e1 * wr_6_0 
             + 0.422470789593472169e0 * wr_4_0;
 results[k++] = -0.102402696130024967e0 * wr_4_0 + 0.982848372400625026e0 * wr_6_0 
             + 0.215481154610726608e0 * wr_8_0;
 results[k++] = -0.241879636928863172e0 * wr_4_0 + 0.314734604422824424e0 * wr_6_0 
             + 0.385464407663781543e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.545454545454545455e0 * wr_4_0 + 0.268945549684959574e0 * wr_6_0;
 results[k++] = 0.875270134026019341e-1 * wr_4_0 + 0.490907098595363472e0 * wr_6_0 
             - 0.462307789446672940e0 * wr_8_0;
 results[k++] = -0.377869361615605805e-1 * wr_4_0 + 0.131306792639606227e0 * wr_8_0 
             - 0.280499750327158128e0 * wr_6_0 + 0.396287855362262452e0 * wr_10_0;
 results[k++] = 0.216343724218362606e-1 * wr_4_0 - 0.827962318071695735e-1 * wr_6_0 
             - 0.317551175215807633e0 * wr_8_0 + 0.117982264730351781e1 * wr_10_0;
 results[k++] = 0.875270134026019341e-1 * wr_4_0 + 0.490907098595363472e0 * wr_6_0 
             - 0.462307789446672940e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.165680473372781065e0 * wr_4_0 - 0.401592902244509773e-1 * wr_6_0 
             + 0.181882835592491373e0 * wr_8_0 + 0.725327532277253882e0 * wr_10_0;
 results[k++] = -0.682662686436610481e0 * wr_6_0 - 0.499452763531871229e0 * wr_10_0 
             - 0.919634734867786885e-1 * wr_4_0 - 0.273913911681397780e0 * wr_8_0;
 results[k++] = 0.347089685340295116e0 * wr_10_0 - 0.115423576177342652e0 * wr_8_0 
             - 0.938037129046828304e-1 * wr_6_0 - 0.491422191796113667e0 * wr_4_0;
 results[k++] = -0.377869361615605805e-1 * wr_4_0 + 0.131306792639606227e0 * wr_8_0 
             - 0.280499750327158128e0 * wr_6_0 + 0.396287855362262452e0 * wr_10_0;
 results[k++] = -0.682662686436610481e0 * wr_6_0 - 0.499452763531871229e0 * wr_10_0 
             - 0.919634734867786885e-1 * wr_4_0 - 0.273913911681397780e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.387096774193548387e0 * wr_4_0 - 0.715742188677714996e0 * wr_6_0 
             - 0.115297071324572551e0 * wr_8_0 - 0.229817038900749975e0 * wr_10_0;
 results[k++] = 0.954699837290445054e-1 * wr_4_0 + 0.555175297785512437e-1 * wr_8_0 
             - 0.459750669011096019e-1 * wr_10_0 + 0.708692191535140895e0 * wr_6_0;
 results[k++] = 0.216343724218362606e-1 * wr_4_0 - 0.827962318071695735e-1 * wr_6_0 
             - 0.317551175215807633e0 * wr_8_0 + 0.117982264730351781e1 * wr_10_0;
 results[k++] = 0.347089685340295116e0 * wr_10_0 - 0.115423576177342652e0 * wr_8_0 
             - 0.938037129046828304e-1 * wr_6_0 - 0.491422191796113667e0 * wr_4_0;
 results[k++] = 0.954699837290445054e-1 * wr_4_0 + 0.555175297785512437e-1 * wr_8_0 
             - 0.459750669011096019e-1 * wr_10_0 + 0.708692191535140895e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.161168855957937844e0 * wr_4_0 + 0.660979520189827300e0 * wr_6_0 
             - 0.286537100333257227e0 * wr_8_0 - 0.764323636163127747e-1 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::setup___ar_3_Hg(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=0)
 if (lmax>=0){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,3,0,1));
    }
#endif
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,3,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,3,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,3,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,5,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,5,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,5,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,7,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,7,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,7,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,11,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,11,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,11,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,11,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,5,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,7,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,9,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,9,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,11,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,11,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,11,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,11,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,11,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,11,4,2));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,0,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,2,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,2,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,2,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,4,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,4,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,4,2,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,4,2,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,2,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,2,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,3,9,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,2,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,2,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,3,9,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,2,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,3,11,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,2,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,2,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,3,11,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,2,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,3,13,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,2,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,2,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,3,13,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,2,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,2,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,3,15,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,2,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,2,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,3,15,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,6,2,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,6,2,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,6,2,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,1,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,2,15,6,3));
    quantnums.push_back(BoxMatrixQuantumNumbers(15,6,3,15,6,3));
    }
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::evaluate___ar_3_Hg(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=0)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=2)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0;
 results[k++] = -0.374087811833129796e0 * wr_4_0;
 results[k++] = 0.591484765150589331e0 * wr_4_0;
 results[k++] = -0.374087811833129796e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.326530612244897959e0 * wr_4_0;
 results[k++] = -0.387217672673679104e0 * wr_4_0;
 results[k++] = 0.591484765150589331e0 * wr_4_0;
 results[k++] = -0.387217672673679104e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.408163265306122449e-1 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.534522483824848769e0 * wr_4_0;
 results[k++] = 0.617213399848367641e0 * wr_4_0;
 results[k++] = -0.674199862463242087e0 * wr_4_0;
 results[k++] = -0.147122471584124921e0 * wr_4_0;
 results[k++] = 0.720749970156447168e0 * wr_4_0;
 results[k++] = 0.227921152919275897e0 * wr_4_0;
 results[k++] = 0.381801774160606263e0 * wr_4_0;
 results[k++] = -0.249947932937058989e0 * wr_4_0;
 results[k++] = 0.143709957187659254e0 * wr_4_0 + 0.976520282781044840e0 * wr_6_0;
 results[k++] = 0.176346685670962183e0 * wr_4_0;
 results[k++] = -0.299110104101174092e0 * wr_4_0 + 0.713149582320669206e0 * wr_6_0;
 results[k++] = -0.497825894805147985e-1 * wr_4_0 + 0.902070797012425136e0 * wr_6_0;
 results[k++] = -0.429036276112972237e0 * wr_4_0 - 0.203988434183663384e0 * wr_6_0;
 results[k++] = -0.573204434743343850e-2 * wr_4_0 + 0.124638992072287315e1 * wr_6_0;
 results[k++] = -0.435031578887596769e0 * wr_4_0 - 0.246339437635061194e0 * wr_6_0;
 results[k++] = -0.936233910080794957e-1 * wr_4_0 + 0.934792440542154866e0 * wr_6_0;
 results[k++] = -0.262675271089574839e-1 * wr_4_0 - 0.271984578911551179e0 * wr_6_0;
 results[k++] = 0.332260856658094184e0 * wr_4_0 - 0.698823740714370368e0 * wr_6_0;
 results[k++] = -0.381627415789877038e0 * wr_6_0 - 0.262090898238708061e0 * wr_4_0;
 results[k++] = 0.249833788589642438e0 * wr_6_0 + 0.171578768591121133e0 * wr_4_0;
 results[k++] = -0.395021904206128019e0 * wr_6_0 - 0.271289853437451176e0 * wr_4_0;
 results[k++] = -0.828804192433730537e-1 * wr_4_0 + 0.120681185146011757e1 * wr_6_0;
 results[k++] = -0.352676809468686528e0 * wr_4_0 + 0.790043808412256036e0 * wr_6_0;
 results[k++] = 0.257368152886681700e0 * wr_4_0 - 0.832779295298808125e-1 * wr_6_0;
 results[k++] = wr_0_0 + 0.183673469387755102e0 * wr_4_0;
 results[k++] = -0.347052851980405840e0 * wr_4_0 - 0.436713146741146727e0 * wr_6_0;
 results[k++] = 0.631826272539742649e-1 * wr_4_0 + 0.954068539474692597e0 * wr_6_0;
 results[k++] = 0.289539171997516913e0 * wr_4_0 - 0.208194823824702032e0 * wr_6_0;
 results[k++] = -0.135992289455775590e0 * wr_6_0 - 0.704383012488323085e0 * wr_8_0 
             - 0.242469481005761390e-1 * wr_4_0;
 results[k++] = 0.498391284987141276e-1 * wr_4_0 - 0.430045378901150996e0 * wr_6_0;
 results[k++] = -0.347052851980405840e0 * wr_4_0 - 0.436713146741146727e0 * wr_6_0;
 results[k++] = wr_0_0 + 0.111317254174397032e-1 * wr_4_0 + 0.537891099369919148e0 * wr_6_0;
 results[k++] = -0.374138531827587968e0 * wr_4_0 - 0.124855191700641822e0 * wr_6_0 
             - 0.387326855686078213e0 * wr_8_0;
 results[k++] = 0.285753023749927768e0 * wr_4_0 - 0.354193274733017774e0 * wr_6_0 
             - 0.253564947838670031e0 * wr_8_0;
 results[k++] = 0.706636664325049881e0 * wr_6_0 + 0.295764161361987535e0 * wr_8_0 
             + 0.125990838116050670e0 * wr_4_0;
 results[k++] = -0.119525403828083333e0 * wr_4_0 + 0.148972089163400481e0 * wr_6_0 
             + 0.327350940053707122e0 * wr_8_0;
 results[k++] = 0.631826272539742649e-1 * wr_4_0 + 0.954068539474692597e0 * wr_6_0;
 results[k++] = -0.374138531827587968e0 * wr_4_0 - 0.124855191700641822e0 * wr_6_0 
             - 0.387326855686078213e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.200254291163382072e-1 * wr_4_0 + 0.871016837047880438e-1 * wr_6_0 
             + 0.483529383416363768e0 * wr_8_0;
 results[k++] = 0.109247672320943420e0 * wr_4_0 + 0.266100039156861890e0 * wr_6_0 
             - 0.105514761916229143e0 * wr_8_0;
 results[k++] = -0.102917260495095040e1 * wr_6_0 - 0.807679146956288751e-1 * wr_8_0 
             - 0.183497864758689343e0 * wr_4_0;
 results[k++] = -0.362669499009376154e0 * wr_4_0 + 0.292907658338431851e0 * wr_6_0 
             - 0.143029920488208622e0 * wr_8_0;
 results[k++] = 0.289539171997516913e0 * wr_4_0 - 0.208194823824702032e0 * wr_6_0;
 results[k++] = 0.285753023749927768e0 * wr_4_0 - 0.354193274733017774e0 * wr_6_0 
             - 0.253564947838670031e0 * wr_8_0;
 results[k++] = 0.109247672320943420e0 * wr_4_0 + 0.266100039156861890e0 * wr_6_0 
             - 0.105514761916229143e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.113477431659249841e0 * wr_4_0 + 0.145169472841313406e0 * wr_6_0 
             - 0.345378131011688405e0 * wr_8_0;
 results[k++] = -0.229125051267329591e0 * wr_8_0;
 results[k++] = -0.332392086292435651e0 * wr_4_0 + 0.497137598506713736e-1 * wr_6_0 
             + 0.263069937411994141e0 * wr_8_0;
 results[k++] = -0.135992289455775590e0 * wr_6_0 - 0.704383012488323085e0 * wr_8_0 
             - 0.242469481005761390e-1 * wr_4_0;
 results[k++] = 0.706636664325049881e0 * wr_6_0 + 0.295764161361987535e0 * wr_8_0 
             + 0.125990838116050670e0 * wr_4_0;
 results[k++] = -0.102917260495095040e1 * wr_6_0 - 0.807679146956288751e-1 * wr_8_0 
             - 0.183497864758689343e0 * wr_4_0;
 results[k++] = -0.229125051267329591e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.434837889383343929e0 * wr_4_0 + 0.220046358833148742e0 * wr_6_0 
             + 0.604411729270454708e-1 * wr_8_0;
 results[k++] = 0.405911149431352364e0 * wr_6_0 - 0.273045387002242496e-1 * wr_8_0 
             + 0.723725338627219685e-1 * wr_4_0;
 results[k++] = 0.498391284987141276e-1 * wr_4_0 - 0.430045378901150996e0 * wr_6_0;
 results[k++] = -0.119525403828083333e0 * wr_4_0 + 0.148972089163400481e0 * wr_6_0 
             + 0.327350940053707122e0 * wr_8_0;
 results[k++] = -0.362669499009376154e0 * wr_4_0 + 0.292907658338431851e0 * wr_6_0 
             - 0.143029920488208622e0 * wr_8_0;
 results[k++] = -0.332392086292435651e0 * wr_4_0 + 0.497137598506713736e-1 * wr_6_0 
             + 0.263069937411994141e0 * wr_8_0;
 results[k++] = 0.405911149431352364e0 * wr_6_0 - 0.273045387002242496e-1 * wr_8_0 
             + 0.723725338627219685e-1 * wr_4_0;
 results[k++] = wr_0_0 - 0.320406865861411316e0 * wr_4_0 + 0.220046358833148742e0 * wr_6_0 
             - 0.103613439303506521e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = -0.264442942673972545e0 * wr_6_0;
 results[k++] = 0.121182980180034710e1 * wr_6_0;
 results[k++] = -0.409673245199351323e0 * wr_6_0;
 results[k++] = 0.129550055126259144e1 * wr_6_0;
 results[k++] = 0.146482709986908877e1 * wr_6_0;
 results[k++] = -0.901538758749090340e-1 * wr_6_0;
 results[k++] = -0.152764578926482939e1 * wr_6_0;
 results[k++] = 0.293470602893126049e0 * wr_6_0;
 results[k++] = -0.204234691757896803e0 * wr_6_0;
 results[k++] = -0.520070503224868537e0 * wr_4_0 + 0.168281872610709802e0 * wr_6_0;
 results[k++] = 0.567443439938508420e-1 * wr_4_0 + 0.991497110563920352e0 * wr_6_0;
 results[k++] = 0.552127296469736214e-1 * wr_4_0 + 0.139350629460345909e0 * wr_6_0 
             - 0.481185203289743438e0 * wr_8_0;
 results[k++] = -0.113488687987701684e0 * wr_4_0 - 0.771164419327493608e0 * wr_6_0;
 results[k++] = 0.260035251612434268e0 * wr_4_0 - 0.216362407642341174e0 * wr_6_0;
 results[k++] = -0.421694188220648422e-1 * wr_4_0 + 0.395314404730624727e0 * wr_6_0 
             - 0.315009659623994742e0 * wr_8_0;
 results[k++] = 0.671408132614542178e0 * wr_4_0 - 0.148972089163400481e0 * wr_6_0;
 results[k++] = 0.180324019921763423e0 * wr_4_0 + 0.186923156257391028e0 * wr_6_0 
             - 0.529193486457547513e0 * wr_8_0;
 results[k++] = 0.106918991210690674e0 * wr_4_0 + 0.693903429235851875e0 * wr_6_0 
             + 0.304264861842058236e0 * wr_8_0;
 results[k++] = 0.212317893862233537e0 * wr_4_0 + 0.471091109550033252e0 * wr_6_0;
 results[k++] = -0.370652502863727670e0 * wr_4_0 + 0.591102921200910857e0 * wr_6_0;
 results[k++] = -0.101432261205991926e0 * wr_4_0 + 0.146287687505784283e0 * wr_6_0 
             + 0.336759491382075692e0 * wr_8_0;
 results[k++] = 0.878896259921453259e0 * wr_6_0 - 0.310534336821234422e-1 * wr_8_0;
 results[k++] = 0.215881580707832636e0 * wr_4_0 + 0.494006831636088876e-1 * wr_6_0 
             - 0.289822047629164062e0 * wr_8_0;
 results[k++] = 0.327685199958823741e0 * wr_4_0 - 0.689200044552955431e0 * wr_6_0 
             + 0.370884895673455651e-1 * wr_8_0;
 results[k++] = -0.540923255249454204e-1 * wr_6_0 - 0.504558575658773450e0 * wr_8_0;
 results[k++] = 0.690902826751859077e0 * wr_4_0 - 0.504349016580517371e-1 * wr_6_0 
             - 0.220207415761469764e0 * wr_8_0;
 results[k++] = -0.198315027521062610e0 * wr_4_0 - 0.407206373121819988e0 * wr_6_0 
             - 0.284568962858663550e0 * wr_8_0;
 results[k++] = 0.611058315705931757e0 * wr_6_0 + 0.113348029428405094e0 * wr_8_0;
 results[k++] = -0.666719282322536978e-1 * wr_6_0 - 0.144873897373603317e0 * wr_8_0;
 results[k++] = 0.299020649925481517e0 * wr_4_0 - 0.431253714291556366e0 * wr_6_0 
             + 0.966975469712628966e-1 * wr_8_0;
 results[k++] = -0.117388241157250419e0 * wr_6_0 + 0.608105978427750089e0 * wr_8_0;
 results[k++] = -0.463548207148008608e0 * wr_6_0 - 0.283538002048647936e0 * wr_8_0;
 results[k++] = 0.718003711433388393e0 * wr_4_0 + 0.303476704112452644e0 * wr_6_0 
             - 0.516703601283101422e-1 * wr_8_0;
 results[k++] = 0.816938767031587215e-1 * wr_6_0 + 0.259778991936709992e-1 * wr_8_0;
 results[k++] = 0.101614272890366734e1 * wr_6_0 - 0.243760221256665443e0 * wr_8_0;
 results[k++] = 0.533024000685101689e-1 * wr_4_0 + 0.599615754043203050e0 * wr_6_0 
             - 0.126174653745555244e0 * wr_8_0;
 results[k++] = -0.115828907144914897e0 * wr_4_0 - 0.539702667183440347e0 * wr_6_0;
 results[k++] = -0.370378250141852951e0 * wr_4_0 - 0.249277984144574630e0 * wr_6_0 
             + 0.176066643980114471e0 * wr_8_0;
 results[k++] = -0.202287381776189692e-1 * wr_4_0 + 0.136146738443036849e0 * wr_6_0 
             + 0.384645269156243598e0 * wr_8_0;
 results[k++] = -0.110356814181407119e0 * wr_4_0 + 0.415935156357713710e0 * wr_6_0 
             - 0.839364791245309107e-1 * wr_8_0;
 results[k++] = 0.721408928634641470e-1 * wr_8_0 + 0.192226051117216644e-1 * wr_4_0 
             + 0.692985319532201439e-1 * wr_10_0 + 0.299655558576805035e0 * wr_6_0;
 results[k++] = 0.379920091968974457e-1 * wr_4_0 - 0.852834670769436985e-1 * wr_6_0 
             + 0.127752538976570558e0 * wr_8_0 - 0.876564797912530671e0 * wr_10_0;
 results[k++] = -0.530794734655583843e0 * wr_4_0 + 0.117772777387508313e0 * wr_6_0;
 results[k++] = 0.282881061173388288e0 * wr_4_0 - 0.707159905170033066e0 * wr_6_0 
             + 0.115262674770816505e0 * wr_8_0;
 results[k++] = -0.110356814181407119e0 * wr_4_0 + 0.415935156357713710e0 * wr_6_0 
             - 0.839364791245309107e-1 * wr_8_0;
 results[k++] = 0.114629516339840826e0 * wr_4_0 + 0.226911230738394748e0 * wr_6_0 
             - 0.274746620825888284e0 * wr_8_0;
 results[k++] = 0.771231151403443410e0 * wr_10_0 + 0.204651634725276769e0 * wr_8_0;
 results[k++] = 0.348202515896481954e-1 * wr_4_0 - 0.144747386447543989e-1 * wr_6_0 
             - 0.234970783162536876e0 * wr_8_0 + 0.573846362566834385e0 * wr_10_0;
 results[k++] = 0.138031824117434053e0 * wr_4_0 + 0.238886793360592986e0 * wr_6_0 
             + 0.265142867118838221e0 * wr_8_0;
 results[k++] = -0.191262505946245508e0 * wr_4_0 + 0.862008465328655411e-1 * wr_6_0 
             + 0.206168761891946695e0 * wr_8_0;
 results[k++] = -0.181065308266170616e0 * wr_4_0 - 0.856668205505872590e0 * wr_6_0 
             - 0.269652205253617530e-1 * wr_8_0 + 0.573846362566834385e-1 * wr_10_0;
 results[k++] = -0.764958159263053582e-1 * wr_8_0 + 0.638640067050558062e0 * wr_10_0;
 results[k++] = -0.306733783053079035e0 * wr_10_0 - 0.167640285984438081e0 * wr_8_0 
             - 0.141452775989997181e0 * wr_4_0 - 0.198953312222819484e0 * wr_6_0;
 results[k++] = 0.757321616161181149e-1 * wr_8_0 - 0.235427870253668522e-1 * wr_4_0 
             + 0.533487564372227330e0 * wr_10_0 - 0.367001608550923861e0 * wr_6_0;
 results[k++] = -0.283721719969254210e0 * wr_4_0 + 0.755426369953463126e0 * wr_6_0;
 results[k++] = 0.181447544934490196e0 * wr_4_0 + 0.181727340852322399e-1 * wr_6_0 
             + 0.228187004484416926e0 * wr_8_0;
 results[k++] = -0.357861737101007704e0 * wr_4_0 + 0.243812045560297959e0 * wr_6_0 
             - 0.477520481025645795e-1 * wr_8_0 - 0.725864613085593799e0 * wr_10_0;
 results[k++] = -0.327985699718750901e0 * wr_4_0 + 0.413810057082254572e-1 * wr_6_0 
             + 0.878286743274238108e-1 * wr_8_0 + 0.475189933393509560e0 * wr_10_0;
 results[k++] = 0.757321616161181149e-1 * wr_8_0 - 0.235427870253668522e-1 * wr_4_0 
             + 0.533487564372227330e0 * wr_10_0 - 0.367001608550923861e0 * wr_6_0;
 results[k++] = 0.104228361255787396e0 * wr_4_0 - 0.198953312222819484e0 * wr_6_0 
             + 0.287383347401893852e0 * wr_8_0 - 0.306733783053079035e0 * wr_10_0;
 results[k++] = -0.352533145066436577e-1 * wr_4_0 + 0.302516166739354028e0 * wr_6_0 
             - 0.221848791531267209e0 * wr_8_0;
 results[k++] = -0.543916994017514825e0 * wr_6_0 + 0.130945869245331234e-1 * wr_8_0 
             + 0.647483266426056647e0 * wr_10_0 + 0.302860238029130351e0 * wr_4_0;
 results[k++] = -0.323708435323099800e0 * wr_4_0 + 0.792181467324200066e-2 * wr_6_0 
             - 0.128096613600487510e0 * wr_8_0 - 0.286014656605741847e0 * wr_10_0;
 results[k++] = 0.246166502102989318e0 * wr_8_0 - 0.784239383390052307e0 * wr_10_0;
 results[k++] = 0.332748917084535995e0 * wr_4_0 + 0.157035646851038744e0 * wr_10_0 
             + 0.840448732719488669e-1 * wr_8_0 - 0.573053850183275822e0 * wr_6_0;
 results[k++] = -0.312440584225525942e0 * wr_6_0 + 0.348513946252261634e0 * wr_8_0 
             - 0.134687291768531014e0 * wr_4_0 + 0.394119299910421208e-1 * wr_10_0;
 results[k++] = -0.112823959159238797e0 * wr_4_0 - 0.308849435724190080e0 * wr_6_0 
             - 0.168561189435159665e0 * wr_8_0;
 results[k++] = -0.183290964765359543e0 * wr_4_0 - 0.321367458060540969e0 * wr_6_0 
             - 0.100470875563987039e0 * wr_8_0 + 0.382558467113048852e0 * wr_10_0;
 results[k++] = 0.199228769732536262e-1 * wr_4_0 - 0.487553989695656705e-3 * wr_6_0 
             + 0.183107649570822337e0 * wr_8_0 + 0.707180799212030052e0 * wr_10_0;
 results[k++] = -0.230418993568335916e0 * wr_4_0 - 0.118415412347377524e0 * wr_6_0 
             + 0.466169258046523104e-1 * wr_8_0 + 0.110228215728180101e0 * wr_10_0;
 results[k++] = 0.226127415175354904e0 * wr_10_0 + 0.229367937823885828e-1 * wr_4_0 
             + 0.357554957451188561e0 * wr_6_0 + 0.124142505122559080e0 * wr_8_0;
 results[k++] = -0.101545514803510958e0 * wr_4_0 - 0.796096691243817151e0 * wr_6_0 
             - 0.296281562736911075e-1 * wr_8_0 + 0.187841299270855994e0 * wr_10_0;
 results[k++] = 0.120082503188589427e-1 * wr_6_0 + 0.933860856878063500e-1 * wr_8_0 
             + 0.101212615486079678e1 * wr_10_0;
 results[k++] = -0.204842167849158386e0 * wr_8_0 - 0.259711692427885276e0 * wr_10_0 
             - 0.356602933285090184e-1 * wr_4_0 + 0.255259223127845100e0 * wr_6_0;
 results[k++] = 0.207748048359599436e0 * wr_4_0 - 0.669184693012354084e0 * wr_6_0 
             + 0.556901241020236497e-1 * wr_8_0 + 0.253700374911088772e0 * wr_10_0;
 results[k++] = 0.236975337076221716e0 * wr_8_0 - 0.249571010726729322e0 * wr_10_0;
 results[k++] = -0.162068172168540010e0 * wr_8_0 + 0.520349474943000874e0 * wr_6_0 
             - 0.624633765856525630e0 * wr_4_0 + 0.116978625326159871e-1 * wr_10_0;
 results[k++] = -0.210694976379193298e0 * wr_4_0 + 0.228087656250459065e0 * wr_6_0 
             + 0.154274331918882188e0 * wr_8_0 - 0.168518607078122408e0 * wr_10_0;
 results[k++] = 0.834894543157778647e-1 * wr_6_0 + 0.182769323080894438e0 * wr_8_0 
             + 0.359080105507466730e0 * wr_10_0;
 results[k++] = -0.856269390326506350e-1 * wr_4_0 - 0.179627966466097260e0 * wr_6_0 
             + 0.109457467265175380e0 * wr_8_0 + 0.675017625593421448e0 * wr_10_0;
 results[k++] = -0.204833547183346753e0 * wr_4_0 - 0.422362932360564794e0 * wr_6_0 
             - 0.284803001875882829e0 * wr_8_0 - 0.601911079763486755e-1 * wr_10_0;
 results[k++] = 0.503850556064511006e-1 * wr_4_0 + 0.763397519932151519e0 * wr_6_0 
             - 0.445597393902799283e-1 * wr_8_0 - 0.674488527777694038e-1 * wr_10_0;
 results[k++] = -0.118531576514953335e0 * wr_8_0 - 0.431250077782278645e0 * wr_6_0 
             - 0.155165234671393386e0 * wr_10_0 - 0.276642622248678903e-1 * wr_4_0;
 results[k++] = 0.302521652165648856e0 * wr_4_0 + 0.421793266042732628e0 * wr_6_0 
             - 0.856840234829487617e-1 * wr_8_0 + 0.128393172552357684e-1 * wr_10_0;
 results[k++] = -0.183016999386267706e0 * wr_6_0 + 0.157128463596515794e0 * wr_8_0 
             - 0.134024913303820935e0 * wr_10_0;
 results[k++] = -0.635668212891083653e-2 * wr_4_0 - 0.354912772875987278e0 * wr_6_0 
             + 0.267285886875056819e0 * wr_8_0 - 0.603558694237802728e0 * wr_10_0;
 results[k++] = -0.555486866369020144e-1 * wr_4_0 - 0.367800283669260081e0 * wr_6_0 
             + 0.261650819733425768e0 * wr_8_0 - 0.338094582923822756e0 * wr_10_0;
 results[k++] = 0.369712374700193127e0 * wr_4_0 - 0.455533146092058002e-1 * wr_6_0 
             - 0.175468490791561288e0 * wr_8_0 - 0.265601831709075762e0 * wr_10_0;
 results[k++] = -0.129978777751597782e0 * wr_10_0 - 0.344907869684102525e-1 * wr_8_0;
 results[k++] = -0.295767415791280628e0 * wr_4_0 + 0.182961570655112241e-1 * wr_6_0 
             + 0.220655877418549199e0 * wr_8_0 + 0.518731767392775138e-1 * wr_10_0;
 results[k++] = -0.137528974270717964e0 * wr_6_0 - 0.151102932317613677e0 * wr_8_0 + wr_0_0 
             + 0.534011443102352193e-1 * wr_4_0;
 results[k++] = 0.291327126189182454e0 * wr_4_0 - 0.420157956563466141e0 * wr_6_0 
             + 0.329733630988216072e-1 * wr_8_0;
 results[k++] = -0.157578470538636160e0 * wr_4_0 - 0.939966047596727652e0 * wr_6_0 
             - 0.880028782600337223e-1 * wr_8_0 - 0.202885327165121389e-1 * wr_10_0;
 results[k++] = -0.311441798192393909e0 * wr_4_0 + 0.267519027026870945e0 * wr_6_0 
             - 0.155842140133244418e0 * wr_8_0 + 0.256631895068086478e0 * wr_10_0;
 results[k++] = 0.105644506035808062e0 * wr_4_0 - 0.373437924983500856e-1 * wr_6_0 
             - 0.162575868940400908e0 * wr_8_0 - 0.227523266105244558e0 * wr_10_0;
 results[k++] = -0.650196988086136529e-2 * wr_4_0 + 0.229835154872236647e-2 * wr_6_0 
             + 0.232394006382207550e0 * wr_8_0 + 0.562558880978717327e0 * wr_10_0;
 results[k++] = -0.129617694505891387e-1 * wr_4_0 + 0.110686557729888570e0 * wr_6_0 
             - 0.218771468875896186e-1 * wr_8_0 - 0.280789443374400501e0 * wr_10_0 
             - 0.144517558208106608e0 * wr_12_4;
 results[k++] = 0.127799285495152174e-1 * wr_4_0 + 0.698609809576585871e-1 * wr_6_0 
             + 0.111881185515956535e0 * wr_8_0 + 0.666180635747600946e-1 * wr_10_0 
             - 0.570398927453634267e0 * wr_12_0 - 0.181281912627439317e-1 * wr_12_4;
 results[k++] = 0.346578114767293845e-2 * wr_4_0 + 0.608360408666361631e-1 * wr_6_0 
             - 0.102786149409180159e0 * wr_8_0 + 0.374194913114931000e0 * wr_10_0 
             - 0.983158044449799712e0 * wr_12_4 + 0.243266906254338392e0 * wr_12_0;
 results[k++] = 0.291327126189182454e0 * wr_4_0 - 0.420157956563466141e0 * wr_6_0 
             + 0.329733630988216072e-1 * wr_8_0;
 results[k++] = -0.229214957117863273e0 * wr_6_0 + 0.107930665941152626e0 * wr_8_0 + wr_0_0 
             - 0.302606484424666243e0 * wr_4_0;
 results[k++] = -0.249649431571792707e0 * wr_8_0 - 0.225793361074440498e0 * wr_10_0;
 results[k++] = -0.285441122957961200e0 * wr_4_0 + 0.454046737478360471e-1 * wr_6_0 
             + 0.286635005536367135e0 * wr_8_0 - 0.168005012127067229e0 * wr_10_0;
 results[k++] = 0.312426159119480464e0 * wr_8_0 - 0.623858609327245506e0 * wr_10_0;
 results[k++] = 0.751988459383152949e-1 * wr_4_0 + 0.558215607118879178e0 * wr_6_0 
             + 0.591646180722509271e-1 * wr_8_0 + 0.876860086719260287e-1 * wr_10_0;
 results[k++] = -0.930927043447579182e-1 * wr_8_0 + 0.276219162896010099e0 * wr_10_0 
             - 0.641419974481458015e0 * wr_12_0 + 0.113530739955228892e1 * wr_12_4;
 results[k++] = -0.314361304321613364e-2 * wr_4_0 - 0.126269839318132612e0 * wr_6_0 
             + 0.175047188282068065e-1 * wr_8_0 + 0.746507601116042836e-1 * wr_10_0 
             - 0.573604869416827054e0 * wr_12_4 - 0.804593166485700466e-1 * wr_12_0;
 results[k++] = -0.230670112269783820e-1 * wr_4_0 + 0.753475033115640804e-2 * wr_6_0 
             + 0.689305331796012537e-1 * wr_8_0 + 0.293961688117130589e0 * wr_10_0 
             - 0.188656602028777713e0 * wr_12_0 + 0.234900738206254719e-1 * wr_12_4;
 results[k++] = -0.157578470538636160e0 * wr_4_0 - 0.939966047596727652e0 * wr_6_0 
             - 0.880028782600337223e-1 * wr_8_0 - 0.202885327165121389e-1 * wr_10_0;
 results[k++] = -0.249649431571792707e0 * wr_8_0 - 0.225793361074440498e0 * wr_10_0;
 results[k++] = 0.647195173038672774e-1 * wr_6_0 - 0.704389609300153984e-1 * wr_8_0 
             - 0.239473217005823504e0 * wr_10_0 + wr_0_0 + 0.324402869857415312e0 * wr_4_0;
 results[k++] = 0.539922078023481352e-1 * wr_4_0 + 0.119385632185691872e0 * wr_6_0 
             + 0.318210789363515691e-1 * wr_8_0 + 0.416504442390393554e0 * wr_10_0;
 results[k++] = -0.515092507813299575e0 * wr_6_0 + 0.585852842550322326e-1 * wr_8_0 
             + 0.329505129110113863e0 * wr_4_0 + 0.999463690548579157e-2 * wr_10_0 
             - 0.179704721170108515e0 * wr_12_0 + 0.261046966160046017e0 * wr_12_4;
 results[k++] = 0.321390179397114758e0 * wr_6_0 + 0.865361998607993284e-1 * wr_8_0 
             - 0.575123173686201824e0 * wr_12_0 + 0.143920278890407891e-1 * wr_10_0 
             - 0.254490669419750132e0 * wr_12_4 + 0.227131954714008108e-1 * wr_4_0;
 results[k++] = 0.197702926302392039e0 * wr_8_0 - 0.267267942397687101e0 * wr_6_0 
             - 0.732958935466682931e-1 * wr_12_4 - 0.402039798614204454e-1 * wr_10_0 
             + 0.121019586154180218e0 * wr_4_0 + 0.113840752305180762e0 * wr_12_0;
 results[k++] = 0.535980881712889689e-2 * wr_4_0 + 0.219415055721830433e0 * wr_12_0 
             + 0.533282037853305001e0 * wr_10_0 + 0.221503674929887548e0 * wr_6_0 
             + 0.144593717709559502e0 * wr_8_0 - 0.152456397061934967e-1 * wr_12_4;
 results[k++] = 0.420744518981548534e-1 * wr_8_0 - 0.646405078735131474e0 * wr_12_4 
             + 0.753734941285162794e-1 * wr_12_0 + 0.446719573645790522e0 * wr_10_0;
 results[k++] = -0.311441798192393909e0 * wr_4_0 + 0.267519027026870945e0 * wr_6_0 
             - 0.155842140133244418e0 * wr_8_0 + 0.256631895068086478e0 * wr_10_0;
 results[k++] = -0.285441122957961200e0 * wr_4_0 + 0.454046737478360471e-1 * wr_6_0 
             + 0.286635005536367135e0 * wr_8_0 - 0.168005012127067229e0 * wr_10_0;
 results[k++] = 0.539922078023481352e-1 * wr_4_0 + 0.119385632185691872e0 * wr_6_0 
             + 0.318210789363515691e-1 * wr_8_0 + 0.416504442390393554e0 * wr_10_0;
 results[k++] = 0.647195173038672774e-1 * wr_6_0 + 0.120752504451454969e0 * wr_8_0 
             - 0.239473217005823504e0 * wr_10_0 + wr_0_0 - 0.239033693579148125e0 * wr_4_0;
 results[k++] = -0.133374298713063757e0 * wr_4_0 + 0.447732783477532310e0 * wr_12_0 
             + 0.250839817521524923e-2 * wr_10_0 - 0.280838884547948900e0 * wr_6_0 
             + 0.242939132550830929e0 * wr_8_0 - 0.858523108916350194e0 * wr_12_4;
 results[k++] = -0.206529427634469233e-1 * wr_8_0 + 0.119552828909462359e-1 * wr_10_0 
             - 0.139899935691770364e0 * wr_12_0 + 0.268256719542457324e0 * wr_12_4 
             - 0.715575754396380182e0 * wr_6_0 - 0.100555602882347739e0 * wr_4_0;
 results[k++] = -0.117153031775517348e0 * wr_6_0 + 0.408210702654065722e-1 * wr_4_0 
             + 0.579175782443422320e0 * wr_10_0 - 0.262854271749936706e0 * wr_12_0 
             - 0.188195414717154185e0 * wr_8_0 + 0.605161644082548859e0 * wr_12_4;
 results[k++] = -0.586120173916038416e-1 * wr_4_0 - 0.441270061880656400e-1 * wr_10_0 
             + 0.226505185917709985e0 * wr_12_0 + 0.343820166512716663e0 * wr_12_4 
             - 0.216646357421212019e0 * wr_6_0 + 0.104523805959416908e0 * wr_8_0;
 results[k++] = 0.573034187607041731e-1 * wr_4_0 - 0.939748474468959172e-2 * wr_6_0 
             - 0.269172608586605948e0 * wr_8_0 - 0.178281130177329545e0 * wr_10_0 
             - 0.323944093178808386e0 * wr_12_4 + 0.357527874977159309e0 * wr_12_0;
 results[k++] = 0.105644506035808062e0 * wr_4_0 - 0.373437924983500856e-1 * wr_6_0 
             - 0.162575868940400908e0 * wr_8_0 - 0.227523266105244558e0 * wr_10_0;
 results[k++] = 0.312426159119480464e0 * wr_8_0 - 0.623858609327245506e0 * wr_10_0;
 results[k++] = -0.515092507813299575e0 * wr_6_0 + 0.585852842550322326e-1 * wr_8_0 
             + 0.329505129110113863e0 * wr_4_0 + 0.999463690548579157e-2 * wr_10_0 
             - 0.179704721170108515e0 * wr_12_0 + 0.261046966160046017e0 * wr_12_4;
 results[k++] = -0.133374298713063757e0 * wr_4_0 + 0.447732783477532310e0 * wr_12_0 
             + 0.250839817521524923e-2 * wr_10_0 - 0.280838884547948900e0 * wr_6_0 
             + 0.242939132550830929e0 * wr_8_0 - 0.858523108916350194e0 * wr_12_4;
 results[k++] = -0.324450356818031485e0 * wr_10_0 + 0.855428773897193106e-2 * wr_6_0 
             + 0.223804930902062663e-1 * wr_8_0 - 0.631317262297053081e0 * wr_12_4 + wr_0_0 
             - 0.259199180397848544e0 * wr_4_0 + 0.283754892225013143e0 * wr_12_0;
 results[k++] = 0.140520328685162949e0 * wr_10_0 - 0.426150423435900222e0 * wr_12_4 
             - 0.115302258438551158e-1 * wr_8_0 + 0.161820812199194675e0 * wr_6_0 
             - 0.147291048577598959e0 * wr_12_0 + 0.794477650306288276e-1 * wr_4_0;
 results[k++] = 0.185374026460385010e0 * wr_4_0 + 0.334734183435597494e0 * wr_10_0 
             - 0.403468666959629849e-1 * wr_12_0 + 0.205321294687599031e0 * wr_6_0 
             - 0.443001493985899246e0 * wr_8_0 + 0.101903588631629438e0 * wr_12_4;
 results[k++] = 0.638817504555955700e-1 * wr_4_0 - 0.331619527702039545e-1 * wr_12_4 
             + 0.336820940488342105e-3 * wr_12_0 + 0.106749259676915684e0 * wr_8_0 
             - 0.201672035504751379e0 * wr_10_0 + 0.752407827657879961e0 * wr_6_0;
 results[k++] = 0.128949731261832415e0 * wr_8_0 + 0.325373868847275995e0 * wr_10_0 
             + 0.170364996764025415e0 * wr_12_4 - 0.284672331873549066e0 * wr_12_0;
 results[k++] = -0.650196988086136529e-2 * wr_4_0 + 0.229835154872236647e-2 * wr_6_0 
             + 0.232394006382207550e0 * wr_8_0 + 0.562558880978717327e0 * wr_10_0;
 results[k++] = 0.751988459383152949e-1 * wr_4_0 + 0.558215607118879178e0 * wr_6_0 
             + 0.591646180722509271e-1 * wr_8_0 + 0.876860086719260287e-1 * wr_10_0;
 results[k++] = 0.321390179397114758e0 * wr_6_0 + 0.865361998607993284e-1 * wr_8_0 
             - 0.575123173686201824e0 * wr_12_0 + 0.143920278890407891e-1 * wr_10_0 
             - 0.254490669419750132e0 * wr_12_4 + 0.227131954714008108e-1 * wr_4_0;
 results[k++] = -0.206529427634469233e-1 * wr_8_0 + 0.119552828909462359e-1 * wr_10_0 
             - 0.139899935691770364e0 * wr_12_0 + 0.268256719542457324e0 * wr_12_4 
             - 0.715575754396380182e0 * wr_6_0 - 0.100555602882347739e0 * wr_4_0;
 results[k++] = 0.140520328685162949e0 * wr_10_0 - 0.426150423435900222e0 * wr_12_4 
             - 0.115302258438551158e-1 * wr_8_0 + 0.161820812199194675e0 * wr_6_0 
             - 0.147291048577598959e0 * wr_12_0 + 0.794477650306288276e-1 * wr_4_0;
 results[k++] = 0.214210676438718605e-1 * wr_6_0 - 0.380913028091590095e-1 * wr_8_0 
             - 0.313277231947476758e0 * wr_10_0 + wr_0_0 + 0.372732705696079725e0 * wr_4_0 
             - 0.141609246781481039e0 * wr_12_0 + 0.271534306364323906e0 * wr_12_4;
 results[k++] = -0.201299503963860512e-1 * wr_8_0 - 0.895286799657705161e-1 * wr_12_0 
             - 0.150823222374491165e0 * wr_12_4 - 0.342412509774821800e-1 * wr_6_0 
             - 0.291272551782059434e-2 * wr_10_0 - 0.828548596120240536e-1 * wr_4_0;
 results[k++] = -0.936104924497568997e-1 * wr_6_0 - 0.193595730697203848e0 * wr_8_0 
             + 0.323517803490970486e0 * wr_12_4 - 0.160361480346627444e0 * wr_4_0 
             - 0.196959923219261472e0 * wr_12_0 - 0.521791160803252175e0 * wr_10_0;
 results[k++] = -0.176430217046712768e-1 * wr_8_0 + 0.268381540012032326e0 * wr_4_0 
             - 0.291940211523589316e0 * wr_10_0 - 0.660570166064752168e-1 * wr_12_4 
             + 0.213260252171125777e-1 * wr_12_0 - 0.673403187510312084e0 * wr_6_0;
 results[k++] = -0.129617694505891387e-1 * wr_4_0 + 0.110686557729888570e0 * wr_6_0 
             - 0.218771468875896186e-1 * wr_8_0 - 0.280789443374400501e0 * wr_10_0 
             - 0.144517558208106608e0 * wr_12_4;
 results[k++] = -0.930927043447579182e-1 * wr_8_0 + 0.276219162896010099e0 * wr_10_0 
             - 0.641419974481458015e0 * wr_12_0 + 0.113530739955228892e1 * wr_12_4;
 results[k++] = 0.197702926302392039e0 * wr_8_0 - 0.267267942397687101e0 * wr_6_0 
             - 0.732958935466682931e-1 * wr_12_4 - 0.402039798614204454e-1 * wr_10_0 
             + 0.121019586154180218e0 * wr_4_0 + 0.113840752305180762e0 * wr_12_0;
 results[k++] = -0.117153031775517348e0 * wr_6_0 + 0.408210702654065722e-1 * wr_4_0 
             + 0.579175782443422320e0 * wr_10_0 - 0.262854271749936706e0 * wr_12_0 
             - 0.188195414717154185e0 * wr_8_0 + 0.605161644082548859e0 * wr_12_4;
 results[k++] = 0.185374026460385010e0 * wr_4_0 + 0.334734183435597494e0 * wr_10_0 
             - 0.403468666959629849e-1 * wr_12_0 + 0.205321294687599031e0 * wr_6_0 
             - 0.443001493985899246e0 * wr_8_0 + 0.101903588631629438e0 * wr_12_4;
 results[k++] = -0.201299503963860512e-1 * wr_8_0 - 0.895286799657705161e-1 * wr_12_0 
             - 0.150823222374491165e0 * wr_12_4 - 0.342412509774821800e-1 * wr_6_0 
             - 0.291272551782059434e-2 * wr_10_0 - 0.828548596120240536e-1 * wr_4_0;
 results[k++] = 0.248812353919215682e0 * wr_8_0 - 0.451552996889363480e0 * wr_4_0 
             - 0.158817107374718464e0 * wr_10_0 + 0.347707096796264304e-1 * wr_12_0 
             + 0.769671072606444869e-1 * wr_6_0 + 0.819947344321827540e-2 * wr_12_4 + wr_0_0;
 results[k++] = -0.206557988774136265e-1 * wr_8_0 + 0.454285307017714009e0 * wr_6_0 
             - 0.334722852897267252e-1 * wr_10_0 + 0.110739343753586716e0 * wr_12_4 
             + 0.338092956900680866e-2 * wr_12_0 + 0.183208577676823618e0 * wr_4_0;
 results[k++] = -0.664985941293442965e-1 * wr_12_0 + 0.307507587770210301e-1 * wr_12_4 
             + 0.117669740514599103e0 * wr_8_0 - 0.280435895658513876e-2 * wr_10_0;
 results[k++] = 0.127799285495152174e-1 * wr_4_0 + 0.698609809576585871e-1 * wr_6_0 
             + 0.111881185515956535e0 * wr_8_0 + 0.666180635747600946e-1 * wr_10_0 
             - 0.570398927453634267e0 * wr_12_0 - 0.181281912627439317e-1 * wr_12_4;
 results[k++] = -0.314361304321613364e-2 * wr_4_0 - 0.126269839318132612e0 * wr_6_0 
             + 0.175047188282068065e-1 * wr_8_0 + 0.746507601116042836e-1 * wr_10_0 
             - 0.573604869416827054e0 * wr_12_4 - 0.804593166485700466e-1 * wr_12_0;
 results[k++] = 0.535980881712889689e-2 * wr_4_0 + 0.219415055721830433e0 * wr_12_0 
             + 0.533282037853305001e0 * wr_10_0 + 0.221503674929887548e0 * wr_6_0 
             + 0.144593717709559502e0 * wr_8_0 - 0.152456397061934967e-1 * wr_12_4;
 results[k++] = -0.586120173916038416e-1 * wr_4_0 - 0.441270061880656400e-1 * wr_10_0 
             + 0.226505185917709985e0 * wr_12_0 + 0.343820166512716663e0 * wr_12_4 
             - 0.216646357421212019e0 * wr_6_0 + 0.104523805959416908e0 * wr_8_0;
 results[k++] = 0.638817504555955700e-1 * wr_4_0 - 0.331619527702039545e-1 * wr_12_4 
             + 0.336820940488342105e-3 * wr_12_0 + 0.106749259676915684e0 * wr_8_0 
             - 0.201672035504751379e0 * wr_10_0 + 0.752407827657879961e0 * wr_6_0;
 results[k++] = -0.936104924497568997e-1 * wr_6_0 - 0.193595730697203848e0 * wr_8_0 
             + 0.323517803490970486e0 * wr_12_4 - 0.160361480346627444e0 * wr_4_0 
             - 0.196959923219261472e0 * wr_12_0 - 0.521791160803252175e0 * wr_10_0;
 results[k++] = -0.206557988774136265e-1 * wr_8_0 + 0.454285307017714009e0 * wr_6_0 
             - 0.334722852897267252e-1 * wr_10_0 + 0.110739343753586716e0 * wr_12_4 
             + 0.338092956900680866e-2 * wr_12_0 + 0.183208577676823618e0 * wr_4_0;
 results[k++] = -0.552464088692322968e-1 * wr_6_0 + 0.389333388735050711e-1 * wr_8_0 
             - 0.439762330826778481e-1 * wr_10_0 + wr_0_0 + 0.384990727344492444e0 * wr_4_0 
             - 0.789534802835975447e-1 * wr_12_0 + 0.625852894537579312e-1 * wr_12_4;
 results[k++] = -0.257624609406984663e-1 * wr_12_4 - 0.464490695084125747e0 * wr_6_0 
             - 0.717985688455950698e-2 * wr_8_0 + 0.262254027559885436e0 * wr_4_0 
             + 0.288461194514875467e-1 * wr_12_0 - 0.234949424163154198e0 * wr_10_0;
 results[k++] = 0.346578114767293845e-2 * wr_4_0 + 0.608360408666361631e-1 * wr_6_0 
             - 0.102786149409180159e0 * wr_8_0 + 0.374194913114931000e0 * wr_10_0 
             - 0.983158044449799712e0 * wr_12_4 + 0.243266906254338392e0 * wr_12_0;
 results[k++] = -0.230670112269783820e-1 * wr_4_0 + 0.753475033115640804e-2 * wr_6_0 
             + 0.689305331796012537e-1 * wr_8_0 + 0.293961688117130589e0 * wr_10_0 
             - 0.188656602028777713e0 * wr_12_0 + 0.234900738206254719e-1 * wr_12_4;
 results[k++] = 0.420744518981548534e-1 * wr_8_0 - 0.646405078735131474e0 * wr_12_4 
             + 0.753734941285162794e-1 * wr_12_0 + 0.446719573645790522e0 * wr_10_0;
 results[k++] = 0.573034187607041731e-1 * wr_4_0 - 0.939748474468959172e-2 * wr_6_0 
             - 0.269172608586605948e0 * wr_8_0 - 0.178281130177329545e0 * wr_10_0 
             - 0.323944093178808386e0 * wr_12_4 + 0.357527874977159309e0 * wr_12_0;
 results[k++] = 0.128949731261832415e0 * wr_8_0 + 0.325373868847275995e0 * wr_10_0 
             + 0.170364996764025415e0 * wr_12_4 - 0.284672331873549066e0 * wr_12_0;
 results[k++] = -0.176430217046712768e-1 * wr_8_0 + 0.268381540012032326e0 * wr_4_0 
             - 0.291940211523589316e0 * wr_10_0 - 0.660570166064752168e-1 * wr_12_4 
             + 0.213260252171125777e-1 * wr_12_0 - 0.673403187510312084e0 * wr_6_0;
 results[k++] = -0.664985941293442965e-1 * wr_12_0 + 0.307507587770210301e-1 * wr_12_4 
             + 0.117669740514599103e0 * wr_8_0 - 0.280435895658513876e-2 * wr_10_0;
 results[k++] = -0.257624609406984663e-1 * wr_12_4 - 0.464490695084125747e0 * wr_6_0 
             - 0.717985688455950698e-2 * wr_8_0 + 0.262254027559885436e0 * wr_4_0 
             + 0.288461194514875467e-1 * wr_12_0 - 0.234949424163154198e0 * wr_10_0;
 results[k++] = -0.626223698612095320e0 * wr_6_0 - 0.232757858776386152e0 * wr_8_0 
             + 0.135116126955750539e0 * wr_10_0 + wr_0_0 - 0.193295519724682939e0 * wr_4_0 
             - 0.912184643735342463e-2 * wr_12_0 + 0.641338455777972343e-1 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::setup___ar_3_Hu(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,3,1,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,5,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,3,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,9,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,9,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,9,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,9,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,3,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,3,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,3,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,3,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,3,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,5,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,7,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,9,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,9,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,9,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,9,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,9,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,9,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,9,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,9,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,9,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,9,3,2));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,1,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,1,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(3,3,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(5,3,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,3,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,3,2,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,7,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,9,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,9,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,11,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,11,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,13,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(7,5,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(9,5,2,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(11,5,2,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,1,13,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(13,5,2,13,5,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=3)
void BoxMatrix::evaluate___ar_3_Hu(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = -0.571428571428571429e0 * wr_4_0;
 results[k++] = -0.349927106111882585e0 * wr_4_0;
 results[k++] = -0.349927106111882585e0 * wr_4_0;
 results[k++] = 0.538748023761179066e0 * wr_4_0;
 results[k++] = -0.404061017820884300e0 * wr_4_0;
 results[k++] = -0.577350269189625763e0 * wr_4_0;
 results[k++] = -0.824786098842322518e-1 * wr_4_0;
 results[k++] = -0.125988157669742409e0 * wr_4_0;
 results[k++] = -0.377964473009227227e0 * wr_4_0;
 results[k++] = wr_0_0;
 results[k++] = 0.349927106111882585e0 * wr_4_0;
 results[k++] = 0.404061017820884300e0 * wr_4_0;
 results[k++] = 0.157459164324443390e0 * wr_4_0 - 0.291142097827431151e0 * wr_6_0;
 results[k++] = 0.343604066372024752e-1 * wr_4_0 + 0.133418070128244146e1 * wr_6_0;
 results[k++] = 0.349927106111882585e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.142857142857142857e0 * wr_4_0;
 results[k++] = -0.269929995984760097e0 * wr_4_0 + 0.727855244568577877e0 * wr_6_0;
 results[k++] = 0.826488445542717887e-1 * wr_4_0 + 0.124801176906117111e1 * wr_6_0;
 results[k++] = 0.378744586270589234e0 * wr_4_0 - 0.272338495234217310e0 * wr_6_0;
 results[k++] = 0.404061017820884300e0 * wr_4_0;
 results[k++] = -0.269929995984760097e0 * wr_4_0 + 0.727855244568577877e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.865800865800865801e-2 * wr_4_0 + 0.896485165616531913e0 * wr_6_0;
 results[k++] = -0.424154068014403134e0 * wr_4_0 - 0.240179976939762735e0 * wr_6_0;
 results[k++] = 0.323953020499908346e0 * wr_4_0 - 0.681350381981416237e0 * wr_6_0;
 results[k++] = 0.157459164324443390e0 * wr_4_0 - 0.291142097827431151e0 * wr_6_0;
 results[k++] = 0.826488445542717887e-1 * wr_4_0 + 0.124801176906117111e1 * wr_6_0;
 results[k++] = -0.424154068014403134e0 * wr_4_0 - 0.240179976939762735e0 * wr_6_0;
 results[k++] = wr_0_0 + 0.454545454545454545e-1 * wr_4_0 - 0.840454842765498668e-1 * wr_6_0;
 results[k++] = 0.247974875268173160e0 * wr_4_0 - 0.256763195677673753e0 * wr_6_0;
 results[k++] = 0.343604066372024752e-1 * wr_4_0 + 0.133418070128244146e1 * wr_6_0;
 results[k++] = 0.378744586270589234e0 * wr_4_0 - 0.272338495234217310e0 * wr_6_0;
 results[k++] = 0.323953020499908346e0 * wr_4_0 - 0.681350381981416237e0 * wr_6_0;
 results[k++] = 0.247974875268173160e0 * wr_4_0 - 0.256763195677673753e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.257575757575757576e0 * wr_4_0 - 0.140075807127583111e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.421637021355783911e0 * wr_4_0;
 results[k++] = 0.114991914915213794e0 * wr_4_0 + 0.956790566516759144e0 * wr_6_0;
 results[k++] = -0.593815695220164387e0 * wr_4_0 - 0.185281696496388395e0 * wr_6_0;
 results[k++] = 0.742269619025205484e-1 * wr_4_0 + 0.129697187547471877e1 * wr_6_0;
 results[k++] = -0.129581208199963338e0 * wr_4_0 + 0.849067399084534081e0 * wr_6_0;
 results[k++] = 0.340150671524903763e0 * wr_4_0 - 0.283022466361511360e0 * wr_6_0;
 results[k++] = 0.606925789379112862e0 * wr_4_0 - 0.362558920190649524e0 * wr_6_0;
 results[k++] = 0.186746396732034727e0 * wr_4_0 + 0.271919190142987142e0 * wr_6_0;
 results[k++] = 0.191926786513362764e0 * wr_4_0 + 0.114651197381366136e1 * wr_6_0;
 results[k++] = -0.383853573026725527e0 * wr_4_0 + 0.859883980360246020e0 * wr_6_0;
 results[k++] = 0.121880981960012525e1 * wr_6_0;
 results[k++] = 0.237796607121605320e0 * wr_4_0 - 0.313935862624274685e0 * wr_6_0;
 results[k++] = -0.750125589574154862e-1 * wr_6_0;
 results[k++] = 0.761039211931050287e0 * wr_4_0 + 0.320508206454411623e0 * wr_6_0;
 results[k++] = -0.361403161162100497e0 * wr_4_0;
 results[k++] = -0.362149092112901319e0 * wr_4_0 - 0.455709465297820924e0 * wr_6_0;
 results[k++] = -0.387197918181781766e-1 * wr_4_0 + 0.701610619898552884e0 * wr_6_0;
 results[k++] = 0.729567176164057427e-1 * wr_4_0 + 0.150376451476059589e0 * wr_6_0 
             - 0.485539909275129166e0 * wr_8_0;
 results[k++] = -0.557216134887829204e-1 * wr_4_0 + 0.426592815769650475e0 * wr_6_0 
             - 0.317860483882181508e0 * wr_8_0;
 results[k++] = -0.445361771415123290e0 * wr_4_0 + 0.144107986163857641e0 * wr_6_0;
 results[k++] = -0.389610389610389610e-1 * wr_4_0 + 0.705982067923018881e0 * wr_6_0;
 results[k++] = -0.392205977071873645e0 * wr_4_0 - 0.135866312319467870e0 * wr_6_0 
             - 0.383853002055230659e0 * wr_8_0;
 results[k++] = -0.247240133282009624e-1 * wr_4_0 + 0.166401569208156148e0 * wr_6_0 
             + 0.470121995635408841e0 * wr_8_0;
 results[k++] = -0.134880550666164257e0 * wr_4_0 + 0.508365191103872312e0 * wr_6_0 
             - 0.102589030041093335e0 * wr_8_0;
 results[k++] = -0.971859061499725035e-1 * wr_4_0 - 0.660385754843526506e0 * wr_6_0;
 results[k++] = -0.178541910193084675e0 * wr_4_0 - 0.154057917406604252e0 * wr_6_0;
 results[k++] = 0.299552262990995937e0 * wr_4_0 - 0.385429980370483090e0 * wr_6_0 
             - 0.251290776807733446e0 * wr_8_0;
 results[k++] = -0.134880550666164257e0 * wr_4_0 + 0.508365191103872312e0 * wr_6_0 
             - 0.102589030041093335e0 * wr_8_0;
 results[k++] = 0.140102742193138787e0 * wr_4_0 + 0.277335948680260247e0 * wr_6_0 
             - 0.335801425453863458e0 * wr_8_0;
 results[k++] = -0.186746396732034727e0 * wr_4_0 - 0.271919190142987142e0 * wr_6_0;
 results[k++] = 0.155410059709822852e0 * wr_4_0 + 0.148014059360256816e0 * wr_6_0 
             - 0.547607669733299991e0 * wr_8_0;
 results[k++] = 0.306580785969284296e0 * wr_8_0 + 0.320459838808100699e0 * wr_6_0 
             - 0.152364973259278930e0 * wr_4_0;
 results[k++] = -0.186608219579018479e0 * wr_4_0 - 0.104661745084585773e1 * wr_6_0 
             - 0.821369599056744905e-1 * wr_8_0;
 results[k++] = -0.233008803313189580e0 * wr_8_0;
 results[k++] = -0.590543958502654657e-1 * wr_4_0 + 0.859883980360246020e0 * wr_6_0;
 results[k++] = -0.319442343990774376e0 * wr_4_0 + 0.468061553305776532e0 * wr_6_0;
 results[k++] = 0.144546105338991079e0 * wr_4_0 + 0.675588659496011123e-1 * wr_6_0 
             + 0.339322749677635865e0 * wr_8_0;
 results[k++] = -0.368816877486578569e0 * wr_4_0 + 0.297872548519700948e0 * wr_6_0 
             - 0.145454329094961777e0 * wr_8_0;
 results[k++] = -0.338026251731900136e0 * wr_4_0 + 0.505564259644791014e-1 * wr_6_0 
             + 0.267529067489551804e0 * wr_8_0;
 results[k++] = -0.406269939866708418e0 * wr_6_0 - 0.430633643923525318e-1 * wr_8_0;
 results[k++] = -0.448061807702318052e-1 * wr_4_0 + 0.384491337694974868e0 * wr_6_0 
             - 0.281964893120451162e0 * wr_8_0;
 results[k++] = 0.351350734413920581e-1 * wr_8_0 - 0.652900521527273657e0 * wr_6_0 
             + 0.310426326348628395e0 * wr_4_0;
 results[k++] = -0.443558559663816723e0 * wr_4_0 + 0.533091043512948126e-1 * wr_6_0 
             + 0.741098072834813510e-1 * wr_8_0;
 results[k++] = -0.142418690999898646e0 * wr_8_0;
 results[k++] = 0.250041863191384954e-1 * wr_6_0 - 0.699696852312609366e0 * wr_8_0;
 results[k++] = -0.143396749498530840e0 * wr_4_0 - 0.392540782093957234e0 * wr_6_0 
             - 0.214237532849676608e0 * wr_8_0;
 results[k++] = -0.187869960134990491e0 * wr_4_0 - 0.385759193548685002e0 * wr_6_0 
             - 0.269580981210486591e0 * wr_8_0;
 results[k++] = 0.272991422228322578e-1 * wr_4_0 - 0.328094856868685639e-2 * wr_6_0 
             - 0.105936232351525919e0 * wr_8_0;
 results[k++] = -0.315729544719294002e0 * wr_4_0 - 0.796865343865020592e0 * wr_6_0 
             - 0.269700446438498461e-1 * wr_8_0;
 results[k++] = wr_0_0 + 0.606060606060606061e-1 * wr_4_0 - 0.358594066246612765e0 * wr_6_0;
 results[k++] = -0.361117328317707868e0 * wr_4_0 - 0.243045048158837826e0 * wr_6_0 
             + 0.171664281192572448e0 * wr_8_0;
 results[k++] = 0.275807915296019396e0 * wr_4_0 - 0.689478109339847815e0 * wr_6_0 
             + 0.112380651812163917e0 * wr_8_0;
 results[k++] = 0.102209531279305614e0 * wr_4_0 + 0.573255986906830680e0 * wr_6_0 
             + 0.239937417307921703e0 * wr_8_0;
 results[k++] = -0.969644752262488005e-1 * wr_4_0 + 0.120852973396883174e0 * wr_6_0 
             + 0.265562057106968526e0 * wr_8_0;
 results[k++] = -0.289447835929368842e-1 * wr_8_0 - 0.277653747088426868e-1 * wr_4_0 
             + 0.788632620640162004e0 * wr_10_0 + 0.171756464550593965e0 * wr_6_0;
 results[k++] = 0.168036000716805720e-1 * wr_4_0 + 0.101480444672983293e0 * wr_6_0 
             + 0.222084726104957416e0 * wr_8_0 + 0.465955032525772964e0 * wr_10_0;
 results[k++] = -0.361117328317707868e0 * wr_4_0 - 0.243045048158837826e0 * wr_6_0 
             + 0.171664281192572448e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.279720279720279720e-1 * wr_4_0 + 0.336181937106199468e-1 * wr_6_0 
             + 0.332426451098750089e0 * wr_8_0;
 results[k++] = 0.152599923241952714e0 * wr_4_0 + 0.102705278271069501e0 * wr_6_0 
             - 0.725413988174075357e-1 * wr_8_0;
 results[k++] = -0.175935916652629643e0 * wr_4_0 - 0.827137390542611621e0 * wr_6_0 
             - 0.244545689833052627e-1 * wr_8_0 + 0.576598639088572863e-1 * wr_10_0;
 results[k++] = -0.347723886782410424e0 * wr_4_0 + 0.235407428280258197e0 * wr_6_0 
             - 0.433059968235735621e-1 * wr_8_0 - 0.729345998109313609e0 * wr_10_0;
 results[k++] = 0.125457306156649054e0 * wr_4_0 - 0.443473284538609998e-1 * wr_6_0 
             - 0.193065700514760514e0 * wr_8_0 - 0.270193473609042144e0 * wr_10_0;
 results[k++] = -0.772136343453627604e-2 * wr_4_0 + 0.272938939016796854e-2 * wr_6_0 
             + 0.275977683096749403e0 * wr_8_0 + 0.668062395390128628e0 * wr_10_0;
 results[k++] = 0.275807915296019396e0 * wr_4_0 - 0.689478109339847815e0 * wr_6_0 
             + 0.112380651812163917e0 * wr_8_0;
 results[k++] = 0.152599923241952714e0 * wr_4_0 + 0.102705278271069501e0 * wr_6_0 
             - 0.725413988174075357e-1 * wr_8_0;
 results[k++] = wr_0_0 - 0.158508158508158508e0 * wr_4_0 + 0.560303228510332445e-1 * wr_6_0 
             - 0.237447465070535778e0 * wr_8_0;
 results[k++] = -0.693735178521763510e-1 * wr_8_0 + 0.641703106527749175e0 * wr_10_0;
 results[k++] = -0.318694206424930056e0 * wr_4_0 + 0.399545318240433802e-1 * wr_6_0 
             + 0.796512074890002580e-1 * wr_8_0 + 0.477469034878435514e0 * wr_10_0;
 results[k++] = 0.371019239587462632e0 * wr_8_0 - 0.740858407935580213e0 * wr_10_0;
 results[k++] = 0.893018008367816381e-1 * wr_4_0 + 0.662904574517065963e0 * wr_6_0 
             + 0.702604790505216100e-1 * wr_8_0 + 0.104130833191455165e0 * wr_10_0;
 results[k++] = 0.102209531279305614e0 * wr_4_0 + 0.573255986906830680e0 * wr_6_0 
             + 0.239937417307921703e0 * wr_8_0;
 results[k++] = -0.175935916652629643e0 * wr_4_0 - 0.827137390542611621e0 * wr_6_0 
             - 0.244545689833052627e-1 * wr_8_0 + 0.576598639088572863e-1 * wr_10_0;
 results[k++] = -0.693735178521763510e-1 * wr_8_0 + 0.641703106527749175e0 * wr_10_0;
 results[k++] = wr_0_0 + 0.286175363098440022e0 * wr_4_0 + 0.109525336975775392e-1 * wr_6_0 
             - 0.115743622649767238e0 * wr_8_0 - 0.322367792123223947e0 * wr_10_0;
 results[k++] = 0.476297872429879622e-1 * wr_4_0 + 0.202037223698863167e-1 * wr_6_0 
             + 0.522876388874739680e-1 * wr_8_0 + 0.560679057063991322e0 * wr_10_0;
 results[k++] = 0.328787479249986423e0 * wr_4_0 + 0.155166108226362687e0 * wr_10_0 
             - 0.566231537361823125e0 * wr_6_0 + 0.830443034017399791e-1 * wr_8_0;
 results[k++] = 0.353298199085787026e0 * wr_6_0 + 0.122664565476722967e0 * wr_8_0 
             + 0.226637269802816611e-1 * wr_4_0 + 0.223435326179984946e0 * wr_10_0;
 results[k++] = -0.969644752262488005e-1 * wr_4_0 + 0.120852973396883174e0 * wr_6_0 
             + 0.265562057106968526e0 * wr_8_0;
 results[k++] = -0.347723886782410424e0 * wr_4_0 + 0.235407428280258197e0 * wr_6_0 
             - 0.433059968235735621e-1 * wr_8_0 - 0.729345998109313609e0 * wr_10_0;
 results[k++] = -0.318694206424930056e0 * wr_4_0 + 0.399545318240433802e-1 * wr_6_0 
             + 0.796512074890002580e-1 * wr_8_0 + 0.477469034878435514e0 * wr_10_0;
 results[k++] = 0.476297872429879622e-1 * wr_4_0 + 0.202037223698863167e-1 * wr_6_0 
             + 0.522876388874739680e-1 * wr_8_0 + 0.560679057063991322e0 * wr_10_0;
 results[k++] = wr_0_0 - 0.210866057019903174e0 * wr_4_0 + 0.109525336975775392e-1 * wr_6_0 
             + 0.198417638828172408e0 * wr_8_0 - 0.322367792123223947e0 * wr_10_0;
 results[k++] = -0.133083814473639250e0 * wr_4_0 + 0.389427236237695011e-1 * wr_10_0 
             - 0.308720920876222464e0 * wr_6_0 + 0.344364822809130684e0 * wr_8_0;
 results[k++] = -0.100336596536260084e0 * wr_4_0 - 0.786619011856353415e0 * wr_6_0 
             - 0.292754275548152802e-1 * wr_8_0 + 0.185605013616368136e0 * wr_10_0;
 results[k++] = -0.289447835929368842e-1 * wr_8_0 - 0.277653747088426868e-1 * wr_4_0 
             + 0.788632620640162004e0 * wr_10_0 + 0.171756464550593965e0 * wr_6_0;
 results[k++] = 0.125457306156649054e0 * wr_4_0 - 0.443473284538609998e-1 * wr_6_0 
             - 0.193065700514760514e0 * wr_8_0 - 0.270193473609042144e0 * wr_10_0;
 results[k++] = 0.371019239587462632e0 * wr_8_0 - 0.740858407935580213e0 * wr_10_0;
 results[k++] = 0.328787479249986423e0 * wr_4_0 + 0.155166108226362687e0 * wr_10_0 
             - 0.566231537361823125e0 * wr_6_0 + 0.830443034017399791e-1 * wr_8_0;
 results[k++] = -0.133083814473639250e0 * wr_4_0 + 0.389427236237695011e-1 * wr_10_0 
             - 0.308720920876222464e0 * wr_6_0 + 0.344364822809130684e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.338952774366417327e0 * wr_4_0 + 0.208373675692906013e-1 * wr_6_0 
             - 0.602551737044014860e-1 * wr_8_0 + 0.114805510874072679e0 * wr_10_0;
 results[k++] = 0.394178901510858824e0 * wr_6_0 + 0.103893231193899236e0 * wr_4_0 
             - 0.497225778424422740e-1 * wr_10_0 + 0.310429157334560810e-1 * wr_8_0;
 results[k++] = 0.168036000716805720e-1 * wr_4_0 + 0.101480444672983293e0 * wr_6_0 
             + 0.222084726104957416e0 * wr_8_0 + 0.465955032525772964e0 * wr_10_0;
 results[k++] = -0.772136343453627604e-2 * wr_4_0 + 0.272938939016796854e-2 * wr_6_0 
             + 0.275977683096749403e0 * wr_8_0 + 0.668062395390128628e0 * wr_10_0;
 results[k++] = 0.893018008367816381e-1 * wr_4_0 + 0.662904574517065963e0 * wr_6_0 
             + 0.702604790505216100e-1 * wr_8_0 + 0.104130833191455165e0 * wr_10_0;
 results[k++] = 0.353298199085787026e0 * wr_6_0 + 0.122664565476722967e0 * wr_8_0 
             + 0.226637269802816611e-1 * wr_4_0 + 0.223435326179984946e0 * wr_10_0;
 results[k++] = -0.100336596536260084e0 * wr_4_0 - 0.786619011856353415e0 * wr_6_0 
             - 0.292754275548152802e-1 * wr_8_0 + 0.185605013616368136e0 * wr_10_0;
 results[k++] = 0.394178901510858824e0 * wr_6_0 + 0.103893231193899236e0 * wr_4_0 
             - 0.497225778424422740e-1 * wr_10_0 + 0.310429157334560810e-1 * wr_8_0;
 results[k++] = wr_0_0 + 0.487419692064104256e0 * wr_4_0 + 0.521795237478929935e-1 * wr_6_0 
             + 0.102553507563120410e0 * wr_8_0 + 0.110851943612184084e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif




#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_A1g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(0,2,1,0,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,0,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(0,2,1,8,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(0,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(0,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(0,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(0,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(0,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,16,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_A1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0;
 results[k++] = 0.699854212223765171e0 * wr_4_0;
 results[k++] = 0.699854212223765171e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.285714285714285714e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.667284809281305403e0 * wr_4_0;
 results[k++] = -0.144241605094894116e1 * wr_6_0 - 0.445774717049887318e0 * wr_4_0;
 results[k++] = -0.158665765604383528e1 * wr_6_0;
 results[k++] = -0.606622553892095820e0 * wr_4_0 + 0.412204720856279096e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.112796294614476433e0 * wr_4_0 - 0.103605160617274199e1 * wr_6_0 
             + 0.483529383416363768e0 * wr_8_0;
 results[k++] = 0.360382652194055811e0 * wr_4_0 - 0.943252273072522744e0 * wr_6_0 
             + 0.296100066253164394e0 * wr_8_0;
 results[k++] = 0.360382652194055811e0 * wr_4_0 - 0.943252273072522744e0 * wr_6_0 
             + 0.296100066253164394e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.480610298792116974e0 * wr_4_0 - 0.733487862777162473e-1 * wr_6_0 
             + 0.181323518781136412e0 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.882734829504749529e0 * wr_4_0;
 results[k++] = 0.352814670705953158e-1 * wr_4_0 + 0.508836554386502718e0 * wr_6_0 
             + 0.753017114798575855e0 * wr_8_0;
 results[k++] = 0.142701213602535153e1 * wr_6_0;
 results[k++] = 0.313506024978456201e0 * wr_8_0 + 0.314760987480609637e0 * wr_4_0 
             - 0.953304979096694144e0 * wr_6_0;
 results[k++] = 0.799286669497027599e0 * wr_8_0;
 results[k++] = 0.831634580949746732e0 * wr_4_0 + 0.559720209825152991e0 * wr_6_0 
             + 0.175703993453001033e0 * wr_8_0;
 results[k++] = -0.302756030509616215e0 * wr_4_0 - 0.116437588475558528e1 * wr_6_0 
             - 0.352459790847210547e0 * wr_8_0;
 results[k++] = 0.171267417323764469e0 * wr_6_0 - 0.164927818630657228e0 * wr_8_0 
             - 0.235427870253668522e-1 * wr_4_0 - 0.101847625925607036e1 * wr_10_0;
 results[k++] = -0.258097030460414915e0 * wr_4_0 - 0.494570638930576801e0 * wr_6_0 
             + 0.216678537547789027e0 * wr_8_0 - 0.692430709343691584e0 * wr_10_0;
 results[k++] = 0.205834520990190080e0 * wr_4_0 + 0.873114023165528375e-1 * wr_6_0 
             - 0.662126076789858285e0 * wr_8_0 + 0.706709133385605272e0 * wr_10_0;
 results[k++] = -0.476129892898863370e0 * wr_8_0 - 0.126869193737362985e0 * wr_4_0 
             - 0.423798575701481407e0 * wr_6_0 - 0.720704732313489499e0 * wr_10_0;
 results[k++] = -0.370246123456577452e-1 * wr_8_0 - 0.121110530821804874e1 * wr_6_0 
             - 0.362558920190649524e0 * wr_4_0 + 0.565820144031150198e-1 * wr_10_0;
 results[k++] = 0.733487862777162473e0 * wr_6_0 + 0.863445327529221012e-1 * wr_8_0 + wr_0_0 
             + 0.498410680228862047e0 * wr_4_0;
 results[k++] = 0.254087649013030823e0 * wr_4_0 - 0.707303198034932875e0 * wr_6_0 
             + 0.264880704526491523e0 * wr_8_0 + 0.392571312228740672e0 * wr_10_0;
 results[k++] = 0.497427519237096432e0 * wr_10_0 + 0.204422134052687032e0 * wr_12_4 
             + 0.493624023035787742e-2 * wr_4_0 + 0.746264638578543546e0 * wr_12_0 
             + 0.437140599333138628e-1 * wr_6_0 + 0.116640860034649154e0 * wr_8_0;
 results[k++] = 0.254087649013030823e0 * wr_4_0 - 0.707303198034932875e0 * wr_6_0 
             + 0.264880704526491523e0 * wr_8_0 + 0.392571312228740672e0 * wr_10_0;
 results[k++] = 0.221408874986914369e-1 * wr_6_0 + 0.444131713604550383e0 * wr_10_0 
             - 0.468402860009272903e0 * wr_8_0 + wr_0_0 - 0.245017015070491006e0 * wr_4_0 
             + 0.515988692960021537e0 * wr_12_0 - 0.989403128815005234e0 * wr_12_4;
 results[k++] = 0.818982650356238065e0 * wr_6_0 + 0.459581694475449437e0 * wr_12_4 
             + 0.115400905265867829e0 * wr_12_0 - 0.256024768844830873e0 * wr_10_0 
             + 0.594630153018654435e-1 * wr_8_0 + 0.924804310745957777e-1 * wr_4_0;
 results[k++] = 0.497427519237096432e0 * wr_10_0 + 0.204422134052687032e0 * wr_12_4 
             + 0.493624023035787742e-2 * wr_4_0 + 0.746264638578543546e0 * wr_12_0 
             + 0.437140599333138628e-1 * wr_6_0 + 0.116640860034649154e0 * wr_8_0;
 results[k++] = 0.818982650356238065e0 * wr_6_0 + 0.459581694475449437e0 * wr_12_4 
             + 0.115400905265867829e0 * wr_12_0 - 0.256024768844830873e0 * wr_10_0 
             + 0.594630153018654435e-1 * wr_8_0 + 0.924804310745957777e-1 * wr_4_0;
 results[k++] = 0.355305370883640307e0 * wr_10_0 + 0.570135746606334842e0 * wr_4_0 
             + 0.987912235832548122e-1 * wr_12_0 + 0.196385121486909290e0 * wr_8_0 
             - 0.134918608474773441e0 * wr_12_4 + 0.137387045504700711e0 * wr_6_0 + wr_0_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_A1u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_A1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=3)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = wr_0_0 - 0.181818181818181818e0 * wr_4_0 - 0.151281871697789760e1 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = -0.395584213251215398e0 * wr_4_0 - 0.998409415248936889e0 * wr_6_0 
             + 0.537282280726181533e0 * wr_8_0;
 results[k++] = -0.242244868191451369e0 * wr_4_0 - 0.611398405437605417e0 * wr_6_0 
             + 0.329016858904483421e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.979020979020979021e-1 * wr_4_0 - 0.806836649054878721e0 * wr_6_0 
             - 0.379915944112857245e0 * wr_8_0;
 results[k++] = 0.342585978011633300e0 * wr_4_0 - 0.813786274807666678e0 * wr_6_0 
             + 0.171426354146568860e0 * wr_8_0 - 0.769895685204259432e0 * wr_10_0;
 results[k++] = 0.342585978011633300e0 * wr_4_0 - 0.813786274807666678e0 * wr_6_0 
             + 0.171426354146568860e0 * wr_8_0 - 0.769895685204259432e0 * wr_10_0;
 results[k++] = wr_0_0 - 0.251748251748251748e0 * wr_4_0 + 0.237304896780846683e-1 * wr_6_0 
             - 0.554877234164830978e0 * wr_8_0 + 0.785771493300358371e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_A2g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_A2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 + 0.857142857142857143e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = 0.657096656658364538e0 * wr_4_0 + 0.956790566516759144e0 * wr_6_0;
 results[k++] = 0.894995622700763991e0 * wr_6_0 + 0.614657639802557511e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.233766233766233766e0 * wr_4_0 - 0.907691230186738562e0 * wr_6_0;
 results[k++] = -0.134565100823038851e0 * wr_4_0 - 0.754726576964030294e0 * wr_6_0 
             + 0.710757649321534101e0 * wr_8_0;
 results[k++] = -0.134565100823038851e0 * wr_4_0 - 0.754726576964030294e0 * wr_6_0 
             + 0.710757649321534101e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.251748251748251748e0 * wr_4_0 - 0.806836649054878721e0 * wr_6_0 
             - 0.949789860282143113e-1 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.683421833226256532e0 * wr_4_0 + 0.459967659660855178e0 * wr_6_0 
             + 0.680697007698427277e0 * wr_8_0;
 results[k++] = 0.591860669074870102e0 * wr_4_0 + 0.398343678185575355e0 * wr_6_0 
             + 0.589500900946889622e0 * wr_8_0;
 results[k++] = 0.533088500268402012e0 * wr_4_0 + 0.545454545454545455e0 * wr_6_0 
             + 0.293529946471118168e0 * wr_8_0;
 results[k++] = 0.908626028638635353e0 * wr_10_0 + 0.346827944985163865e0 * wr_8_0 
             - 0.107818082423432899e0 * wr_4_0 + 0.960425425482081214e0 * wr_6_0;
 results[k++] = -0.149730221739821735e0 * wr_4_0 + 0.926230378379078764e0 * wr_6_0 
             + 0.327046584160259940e0 * wr_8_0 + 0.915999728533728234e0 * wr_10_0;
 results[k++] = 0.222490230444076745e0 * wr_8_0 + 0.346563673711650279e0 * wr_6_0 
             + 0.560239190196104180e0 * wr_4_0 - 0.192351676816646134e0 * wr_10_0;
 results[k++] = 0.243549762485605806e0 * wr_6_0 + 0.571026488920136209e0 * wr_10_0 
             + 0.245353879052476282e0 * wr_8_0 + wr_0_0 + 0.128342245989304813e0 * wr_4_0 
             + 0.167528796415591408e0 * wr_12_0 + 0.706716520582146596e0 * wr_12_4;
 results[k++] = 0.754437806518934547e0 * wr_12_0 + 0.161178011911863219e0 * wr_10_0 
             + 0.918844074276752839e-1 * wr_8_0 - 0.556394963725715500e0 * wr_12_4 
             + 0.555738227027447259e0 * wr_4_0 + 0.281227041864267861e0 * wr_6_0;
 results[k++] = 0.754437806518934547e0 * wr_12_0 + 0.161178011911863219e0 * wr_10_0 
             + 0.918844074276752839e-1 * wr_8_0 - 0.556394963725715500e0 * wr_12_4 
             + 0.555738227027447259e0 * wr_4_0 + 0.281227041864267861e0 * wr_6_0;
 results[k++] = 0.162366508323737204e0 * wr_6_0 + 0.524498404637754738e0 * wr_10_0 
             + 0.218829135371127495e0 * wr_8_0 + wr_0_0 - 0.320855614973262032e-1 * wr_4_0 
             - 0.502586389246774225e-1 * wr_12_0 + 0.867333911623543547e0 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_A2u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,6,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,14,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_A2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = 0.872871560943969523e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.545454545454545455e0 * wr_4_0 + 0.840454842765498668e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = -0.148453923805041097e0 * wr_4_0 + 0.148225357197110716e1 * wr_6_0;
 results[k++] = 0.689168787606316851e0 * wr_4_0 + 0.100349041200850892e1 * wr_6_0;
 results[k++] = 0.674824989961900242e0 * wr_4_0 - 0.698741034785834762e0 * wr_6_0;
 results[k++] = 0.583115436899835021e0 * wr_4_0 - 0.880514339791368676e0 * wr_6_0;
 results[k++] = 0.546606023505038850e0 * wr_4_0 + 0.255476154010634166e0 * wr_6_0 
             + 0.687407433271062055e0 * wr_8_0;
 results[k++] = -0.158586492171703732e0 * wr_4_0 + 0.106734456102595317e1 * wr_6_0 
             + 0.526514008549536743e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.545454545454545455e0 * wr_4_0 + 0.268945549684959574e0 * wr_6_0;
 results[k++] = -0.973910697858456784e-1 * wr_4_0 - 0.546230993599135097e0 * wr_6_0 
             + 0.514408620084396907e0 * wr_8_0;
 results[k++] = 0.847680456966890140e-2 * wr_4_0 - 0.167799901722510401e0 * wr_6_0 
             - 0.259215135438070038e0 * wr_8_0 + 0.124459854708170957e1 * wr_10_0;
 results[k++] = -0.973910697858456784e-1 * wr_4_0 - 0.546230993599135097e0 * wr_6_0 
             + 0.514408620084396907e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.131868131868131868e0 * wr_4_0 + 0.261035386458931351e0 * wr_6_0 
             + 0.290649979800625750e0 * wr_8_0 + 0.101027763424331791e1 * wr_10_0;
 results[k++] = 0.218792074323303158e0 * wr_8_0 + 0.340803211471953584e0 * wr_6_0 
             - 0.189154473372968004e0 * wr_10_0 + 0.550927086980670080e0 * wr_4_0;
 results[k++] = 0.847680456966890140e-2 * wr_4_0 - 0.167799901722510401e0 * wr_6_0 
             - 0.259215135438070038e0 * wr_8_0 + 0.124459854708170957e1 * wr_10_0;
 results[k++] = 0.218792074323303158e0 * wr_8_0 + 0.340803211471953584e0 * wr_6_0 
             - 0.189154473372968004e0 * wr_10_0 + 0.550927086980670080e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.479520479520479520e-1 * wr_4_0 + 0.949219587123386734e0 * wr_6_0 
             - 0.235662145784291149e0 * wr_8_0 - 0.119736608502911752e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_Eg(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=0)
 if (lmax>=0){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,4,0,1));
    }
#endif
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,4,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,4,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,16,6,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_Eg(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=0)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=2)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 + 0.244897959183673469e0 * wr_4_0;
 results[k++] = 0.706959513293419302e0 * wr_4_0;
 results[k++] = 0.706959513293419302e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.408163265306122449e-1 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = 0.534522483824848769e0 * wr_4_0;
 results[k++] = 0.789542033951722785e0 * wr_4_0;
 results[k++] = -0.534522483824848769e0 * wr_4_0;
 results[k++] = 0.720749970156447168e0 * wr_4_0;
 results[k++] = -0.456340403571385652e0 * wr_4_0;
 results[k++] = -0.143709957187659254e0 * wr_4_0 - 0.976520282781044840e0 * wr_6_0;
 results[k++] = 0.398307855657959773e0 * wr_4_0 - 0.499667577179284877e0 * wr_6_0;
 results[k++] = -0.636821024356981882e-1 * wr_4_0 + 0.115393284075915293e1 * wr_6_0;
 results[k++] = -0.290398438636336324e0 * wr_4_0 - 0.135310619551863770e1 * wr_6_0;
 results[k++] = -0.603581820188168864e0 * wr_4_0 + 0.195304056556208968e0 * wr_6_0;
 results[k++] = -0.456132005458413146e0 * wr_6_0 - 0.313258539821053114e0 * wr_4_0;
 results[k++] = -0.395021904206128019e0 * wr_6_0 - 0.271289853437451176e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.183673469387755102e0 * wr_4_0;
 results[k++] = 0.443951499932880950e0 * wr_4_0 + 0.558645334362751805e0 * wr_6_0;
 results[k++] = 0.116883116883116883e0 * wr_4_0 - 0.100854581131859840e1 * wr_6_0;
 results[k++] = 0.135992289455775590e0 * wr_6_0 + 0.704383012488323085e0 * wr_8_0 
             + 0.242469481005761390e-1 * wr_4_0;
 results[k++] = 0.443951499932880950e0 * wr_4_0 + 0.558645334362751805e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.161137563734966332e-1 * wr_4_0 + 0.828841284938193598e0 * wr_6_0 
             + 0.338470568391454637e0 * wr_8_0;
 results[k++] = -0.478101615312333331e0 * wr_4_0 + 0.223458133745100722e-1 * wr_6_0 
             - 0.392821128064448548e0 * wr_8_0;
 results[k++] = 0.903932658223437975e0 * wr_6_0 + 0.378342786448152597e0 * wr_8_0 
             + 0.161168021643514505e0 * wr_4_0;
 results[k++] = 0.116883116883116883e0 * wr_4_0 - 0.100854581131859840e1 * wr_6_0;
 results[k++] = -0.478101615312333331e0 * wr_4_0 + 0.223458133745100722e-1 * wr_6_0 
             - 0.392821128064448548e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.629370629370629371e-1 * wr_4_0 - 0.242050994716463617e0 * wr_6_0 
             + 0.455899132935428694e0 * wr_8_0;
 results[k++] = -0.951946026190429127e0 * wr_6_0 + 0.640348193171202805e-1 * wr_8_0 
             - 0.169728636704032973e0 * wr_4_0;
 results[k++] = 0.135992289455775590e0 * wr_6_0 + 0.704383012488323085e0 * wr_8_0 
             + 0.242469481005761390e-1 * wr_4_0;
 results[k++] = 0.903932658223437975e0 * wr_6_0 + 0.378342786448152597e0 * wr_8_0 
             + 0.161168021643514505e0 * wr_4_0;
 results[k++] = -0.951946026190429127e0 * wr_6_0 + 0.640348193171202805e-1 * wr_8_0 
             - 0.169728636704032973e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.434837889383343929e0 * wr_4_0 + 0.220046358833148742e0 * wr_6_0 
             + 0.604411729270454708e-1 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = -0.869048189253481640e0 * wr_6_0;
 results[k++] = -0.156892908110547225e1 * wr_6_0;
 results[k++] = -0.539359889970593670e0 * wr_6_0;
 results[k++] = 0.159325501363138301e1 * wr_6_0;
 results[k++] = -0.138744369255116080e1 * wr_6_0;
 results[k++] = 0.169841555121689363e0 * wr_6_0;
 results[k++] = 0.453954751950806735e0 * wr_4_0 + 0.660998073709280234e0 * wr_6_0;
 results[k++] = 0.504020958151361656e-2 * wr_4_0 - 0.407069243509202175e0 * wr_6_0 
             + 0.527111980359003098e0 * wr_8_0;
 results[k++] = -0.460993229851918134e0 * wr_4_0 - 0.852376783524537134e-1 * wr_6_0;
 results[k++] = 0.122840568622892288e0 * wr_4_0 - 0.177163187550796397e0 * wr_6_0 
             - 0.407835997331453065e0 * wr_8_0;
 results[k++] = 0.609532031274101180e0 * wr_4_0 - 0.298887063020322875e0 * wr_6_0 
             + 0.381606850012849159e0 * wr_8_0;
 results[k++] = 0.140765392934320682e0 * wr_4_0 + 0.913566315663953214e0 * wr_6_0 
             + 0.400583304690042917e0 * wr_8_0;
 results[k++] = 0.761721589703075318e0 * wr_6_0 + 0.242220438905725297e0 * wr_8_0;
 results[k++] = 0.415817290474873366e0 * wr_4_0 - 0.599700224812663918e0 * wr_6_0 
             + 0.134467341928317117e0 * wr_8_0;
 results[k++] = 0.663324958071079970e0 * wr_6_0 + 0.210931217721857540e0 * wr_8_0;
 results[k++] = 0.362103412188950683e0 * wr_4_0 - 0.522232967867093514e0 * wr_6_0 
             + 0.117097303204048088e0 * wr_8_0;
 results[k++] = 0.662733495663611233e0 * wr_8_0 - 0.811997942941150153e-1 * wr_6_0;
 results[k++] = 0.664894081517189618e0 * wr_4_0 + 0.541259257538081080e0 * wr_6_0 
             - 0.103015597494483591e0 * wr_8_0;
 results[k++] = -0.507536842035529563e0 * wr_4_0 - 0.197071550108048955e0 * wr_6_0;
 results[k++] = -0.432508615013737449e-1 * wr_4_0 + 0.931500707804468223e0 * wr_6_0 
             - 0.246721853593047383e0 * wr_8_0;
 results[k++] = 0.117123886623583745e0 * wr_4_0 - 0.137950085075634269e0 * wr_6_0 
             - 0.296944861311538912e0 * wr_8_0;
 results[k++] = -0.210737036479374768e0 * wr_8_0 - 0.105286544337040695e-1 * wr_4_0 
             - 0.683214644749881815e0 * wr_10_0 - 0.164128108914326769e0 * wr_6_0;
 results[k++] = -0.343604066372024752e0 * wr_4_0 + 0.914866766593674148e0 * wr_6_0;
 results[k++] = -0.527057489806126855e0 * wr_4_0 + 0.109797006488770132e0 * wr_6_0 
             - 0.180287951510577196e0 * wr_8_0;
 results[k++] = 0.185017574200321020e0 * wr_4_0 - 0.301367876054386778e0 * wr_6_0 
             + 0.244866802062272591e0 * wr_8_0 + 0.791983222322515932e0 * wr_10_0;
 results[k++] = -0.917162023734433920e-1 * wr_8_0 + 0.285117309895175130e-1 * wr_4_0 
             - 0.646085525271272980e0 * wr_10_0 + 0.444461020033421462e0 * wr_6_0;
 results[k++] = -0.181727340852322399e0 * wr_4_0 - 0.314509077886449673e0 * wr_6_0 
             - 0.349076805262485223e0 * wr_8_0;
 results[k++] = -0.115424500980064319e0 * wr_4_0 + 0.473954386424688696e0 * wr_6_0 
             + 0.276861679555483915e0 * wr_8_0 - 0.464496640740267953e0 * wr_10_0;
 results[k++] = -0.167189153584136608e0 * wr_4_0 - 0.658880540161613052e0 * wr_10_0 
             - 0.647518689766219916e0 * wr_6_0 - 0.194859460672838642e-1 * wr_8_0;
 results[k++] = -0.403833790506060156e0 * wr_10_0 - 0.220708692263286096e0 * wr_8_0 
             - 0.186231233276838644e0 * wr_4_0 - 0.261934206949658513e0 * wr_6_0;
 results[k++] = -0.425815313626320065e0 * wr_6_0 + 0.180540455644345512e0 * wr_8_0;
 results[k++] = 0.108105709847023425e1 * wr_10_0 - 0.242923414744318047e-1 * wr_8_0 
             - 0.393527248865661306e0 * wr_6_0 + 0.380607581212088956e0 * wr_4_0;
 results[k++] = -0.257672550571884240e0 * wr_4_0 + 0.159396106705039596e-1 * wr_6_0 
             - 0.434905146187795868e0 * wr_8_0 + 0.321705105698772973e-1 * wr_10_0;
 results[k++] = 0.347445596312234292e0 * wr_4_0 + 0.921797536567300859e-1 * wr_10_0 
             - 0.730760865880454901e0 * wr_6_0 + 0.482939041931900511e-1 * wr_8_0;
 results[k++] = -0.654370454743734967e-1 * wr_6_0 - 0.744720854846655455e-1 * wr_8_0 
             - 0.105055621026873750e1 * wr_10_0;
 results[k++] = -0.552403291136545429e-1 * wr_4_0 + 0.395414680551857889e0 * wr_6_0 
             - 0.317315078260885562e0 * wr_8_0 - 0.310354872670983084e-1 * wr_10_0;
 results[k++] = 0.224387277602029723e0 * wr_4_0 - 0.624626343164474287e0 * wr_6_0 
             - 0.200501768612561084e0 * wr_8_0 + 0.406215067970578501e0 * wr_10_0;
 results[k++] = 0.236094950824362552e-1 * wr_10_0 - 0.162213917786670567e0 * wr_8_0 
             - 0.605127486791159041e0 * wr_4_0 + 0.449197860962566845e0 * wr_6_0;
 results[k++] = -0.233986917989983706e0 * wr_8_0 - 0.260061919504643963e0 * wr_10_0 
             + 0.801036440296944376e-2 * wr_6_0;
 results[k++] = -0.101432261205991926e0 * wr_4_0 - 0.409820653968410382e0 * wr_6_0 
             + 0.279155894171983797e0 * wr_8_0 + 0.422550604327814656e0 * wr_10_0;
 results[k++] = -0.320459838808100699e0 * wr_4_0 - 0.902258317752649165e0 * wr_6_0 
             - 0.539969810746116243e-1 * wr_8_0 - 0.817337461300309598e-1 * wr_10_0;
 results[k++] = -0.121349190713111478e0 * wr_8_0 - 0.246918833427901966e-1 * wr_4_0 
             - 0.197105918351959034e0 * wr_10_0 - 0.384914534340887298e0 * wr_6_0;
 results[k++] = -0.586790290221729981e0 * wr_6_0 + 0.604411729270454708e-1 * wr_8_0 + wr_0_0 
             + 0.712015257469802924e-1 * wr_4_0;
 results[k++] = 0.223458133745100722e0 * wr_6_0 + 0.187057680030689784e0 * wr_8_0 
             - 0.495809082546123454e0 * wr_4_0;
 results[k++] = 0.113631451087248854e0 * wr_4_0 + 0.677819156361045248e0 * wr_6_0 
             + 0.338452149285297880e0 * wr_8_0 + 0.263344842047927585e0 * wr_10_0;
 results[k++] = -0.124972350037124094e0 * wr_8_0 + 0.177978672585635012e0 * wr_6_0 
             - 0.419580419580419580e-1 * wr_4_0 + 0.817202353032372705e0 * wr_10_0;
 results[k++] = 0.214929666435427912e-2 * wr_4_0 - 0.407863122605950988e-1 * wr_6_0 
             + 0.777348874378982538e-1 * wr_8_0 + 0.214205689895096757e-1 * wr_10_0 
             - 0.903771358897105603e0 * wr_12_4 + 0.557026871894984520e0 * wr_12_0;
 results[k++] = 0.350029142178773637e0 * wr_12_0 + 0.394653732455881100e-2 * wr_4_0 
             + 0.422722624771255235e-1 * wr_6_0 - 0.683867660182346513e-1 * wr_8_0 
             - 0.291642734449943659e0 * wr_10_0 + 0.671177359452222714e0 * wr_12_4;
 results[k++] = 0.223458133745100722e0 * wr_6_0 + 0.187057680030689784e0 * wr_8_0 
             - 0.495809082546123454e0 * wr_4_0;
 results[k++] = -0.711914690342540050e-1 * wr_6_0 - 0.449012281885919069e0 * wr_10_0 
             + 0.317072705237046272e0 * wr_8_0 + wr_0_0 - 0.167832167832167832e0 * wr_4_0;
 results[k++] = -0.373550154207328579e0 * wr_10_0 - 0.713822259328250933e0 * wr_6_0 
             - 0.156605171245885040e0 * wr_4_0 + 0.122749922273452825e-1 * wr_8_0;
 results[k++] = 0.151815491136759440e0 * wr_4_0 + 0.887836754301999772e-1 * wr_6_0 
             - 0.435120073379659037e0 * wr_8_0 + 0.126879757293719446e-1 * wr_10_0 
             + 0.830366633900834989e0 * wr_12_4 - 0.433048755988133033e0 * wr_12_0;
 results[k++] = -0.224498168282187372e-1 * wr_4_0 + 0.165674783594274558e0 * wr_6_0 
             + 0.126304242185107778e0 * wr_8_0 - 0.720946318353998658e0 * wr_10_0 
             - 0.850241596828833752e0 * wr_12_4 + 0.377108974974090793e0 * wr_12_0;
 results[k++] = -0.440088720469378486e0 * wr_12_0 + 0.320618207900450341e-1 * wr_4_0 
             + 0.145060210720676897e0 * wr_10_0 + 0.239313396201804863e0 * wr_6_0 
             + 0.340149008265913312e-1 * wr_8_0 - 0.194738237304000425e0 * wr_12_4;
 results[k++] = 0.113631451087248854e0 * wr_4_0 + 0.677819156361045248e0 * wr_6_0 
             + 0.338452149285297880e0 * wr_8_0 + 0.263344842047927585e0 * wr_10_0;
 results[k++] = -0.373550154207328579e0 * wr_10_0 - 0.713822259328250933e0 * wr_6_0 
             - 0.156605171245885040e0 * wr_4_0 + 0.122749922273452825e-1 * wr_8_0;
 results[k++] = -0.664226624960743108e-1 * wr_6_0 - 0.253789550631171648e0 * wr_10_0 
             - 0.156134286669757634e0 * wr_8_0 + wr_0_0 + 0.221682061254253768e0 * wr_4_0 
             + 0.515988692960021537e0 * wr_12_0 + 0.141343304116429319e0 * wr_12_4;
 results[k++] = 0.717727937185910442e0 * wr_12_4 + 0.344654217452133473e0 * wr_4_0 
             - 0.772405506351754476e-1 * wr_10_0 + 0.199445016543121965e-1 * wr_8_0 
             - 0.592992665448025550e0 * wr_6_0;
 results[k++] = 0.154354086238191623e0 * wr_4_0 - 0.303759922617101976e0 * wr_6_0 
             + 0.260522070709960808e0 * wr_8_0 - 0.106829274015580792e0 * wr_10_0 
             + 0.155569138999425901e0 * wr_12_0 + 0.108175544574192286e0 * wr_12_4;
 results[k++] = 0.629833080478090182e-2 * wr_4_0 + 0.260289772785292122e0 * wr_6_0 
             + 0.194891676835854976e0 * wr_8_0 + 0.891873463968264374e0 * wr_10_0 
             - 0.401677789685735523e0 * wr_12_4 + 0.302583726324219035e0 * wr_12_0;
 results[k++] = -0.124972350037124094e0 * wr_8_0 + 0.177978672585635012e0 * wr_6_0 
             - 0.419580419580419580e-1 * wr_4_0 + 0.817202353032372705e0 * wr_10_0;
 results[k++] = 0.151815491136759440e0 * wr_4_0 + 0.887836754301999772e-1 * wr_6_0 
             - 0.435120073379659037e0 * wr_8_0 + 0.126879757293719446e-1 * wr_10_0 
             + 0.830366633900834989e0 * wr_12_4 - 0.433048755988133033e0 * wr_12_0;
 results[k++] = 0.717727937185910442e0 * wr_12_4 + 0.344654217452133473e0 * wr_4_0 
             - 0.772405506351754476e-1 * wr_10_0 + 0.199445016543121965e-1 * wr_8_0 
             - 0.592992665448025550e0 * wr_6_0;
 results[k++] = -0.343467613761751778e-1 * wr_6_0 - 0.625363482452707573e0 * wr_10_0 
             + 0.589155364460727869e-1 * wr_8_0 + wr_0_0 - 0.217194570135746606e0 * wr_4_0 
             + 0.463750168259523489e0 * wr_12_0 - 0.433666955811771774e0 * wr_12_4;
 results[k++] = -0.461745231381115629e0 * wr_8_0 + 0.269189660919927652e0 * wr_6_0 
             + 0.871493810365066117e-1 * wr_12_4 + 0.253309964013182896e0 * wr_4_0 
             + 0.233756209210919080e0 * wr_10_0 + 0.696283589868730647e-1 * wr_12_0;
 results[k++] = -0.359559299706547882e-1 * wr_12_4 + 0.224001549916870644e0 * wr_8_0 
             + 0.845778102002960278e0 * wr_6_0 + 0.682187166102308759e-1 * wr_4_0 
             + 0.163677044844356135e0 * wr_10_0 - 0.812567651486438801e-1 * wr_12_0;
 results[k++] = 0.214929666435427912e-2 * wr_4_0 - 0.407863122605950988e-1 * wr_6_0 
             + 0.777348874378982538e-1 * wr_8_0 + 0.214205689895096757e-1 * wr_10_0 
             - 0.903771358897105603e0 * wr_12_4 + 0.557026871894984520e0 * wr_12_0;
 results[k++] = -0.224498168282187372e-1 * wr_4_0 + 0.165674783594274558e0 * wr_6_0 
             + 0.126304242185107778e0 * wr_8_0 - 0.720946318353998658e0 * wr_10_0 
             - 0.850241596828833752e0 * wr_12_4 + 0.377108974974090793e0 * wr_12_0;
 results[k++] = 0.154354086238191623e0 * wr_4_0 - 0.303759922617101976e0 * wr_6_0 
             + 0.260522070709960808e0 * wr_8_0 - 0.106829274015580792e0 * wr_10_0 
             + 0.155569138999425901e0 * wr_12_0 + 0.108175544574192286e0 * wr_12_4;
 results[k++] = -0.461745231381115629e0 * wr_8_0 + 0.269189660919927652e0 * wr_6_0 
             + 0.871493810365066117e-1 * wr_12_4 + 0.253309964013182896e0 * wr_4_0 
             + 0.233756209210919080e0 * wr_10_0 + 0.696283589868730647e-1 * wr_12_0;
 results[k++] = 0.167440461708853992e0 * wr_6_0 - 0.133239514081365115e0 * wr_10_0 
             + 0.159562911208113798e0 * wr_8_0 + wr_0_0 - 0.397058823529411765e0 * wr_4_0 
             + 0.603674787993000404e-1 * wr_12_0 + 0.252972390890200202e-1 * wr_12_4;
 results[k++] = 0.178219357099160826e0 * wr_4_0 + 0.526088094983480756e0 * wr_6_0 
             + 0.638065646971932042e-1 * wr_8_0 - 0.119608779015215736e-1 * wr_10_0 
             + 0.112514102271972636e0 * wr_12_4 - 0.381016944376451536e-1 * wr_12_0;
 results[k++] = 0.350029142178773637e0 * wr_12_0 + 0.394653732455881100e-2 * wr_4_0 
             + 0.422722624771255235e-1 * wr_6_0 - 0.683867660182346513e-1 * wr_8_0 
             - 0.291642734449943659e0 * wr_10_0 + 0.671177359452222714e0 * wr_12_4;
 results[k++] = -0.440088720469378486e0 * wr_12_0 + 0.320618207900450341e-1 * wr_4_0 
             + 0.145060210720676897e0 * wr_10_0 + 0.239313396201804863e0 * wr_6_0 
             + 0.340149008265913312e-1 * wr_8_0 - 0.194738237304000425e0 * wr_12_4;
 results[k++] = 0.629833080478090182e-2 * wr_4_0 + 0.260289772785292122e0 * wr_6_0 
             + 0.194891676835854976e0 * wr_8_0 + 0.891873463968264374e0 * wr_10_0 
             - 0.401677789685735523e0 * wr_12_4 + 0.302583726324219035e0 * wr_12_0;
 results[k++] = -0.359559299706547882e-1 * wr_12_4 + 0.224001549916870644e0 * wr_8_0 
             + 0.845778102002960278e0 * wr_6_0 + 0.682187166102308759e-1 * wr_4_0 
             + 0.163677044844356135e0 * wr_10_0 - 0.812567651486438801e-1 * wr_12_0;
 results[k++] = 0.178219357099160826e0 * wr_4_0 + 0.526088094983480756e0 * wr_6_0 
             + 0.638065646971932042e-1 * wr_8_0 - 0.119608779015215736e-1 * wr_10_0 
             + 0.112514102271972636e0 * wr_12_4 - 0.381016944376451536e-1 * wr_12_0;
 results[k++] = -0.545254836846780948e0 * wr_6_0 - 0.196686901739158027e0 * wr_10_0 
             - 0.220933261672772951e-1 * wr_8_0 + wr_0_0 + 0.478506787330316742e0 * wr_4_0 
             - 0.415331807780320366e-1 * wr_12_0 + 0.421620651483667001e-1 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_Eu(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,4,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,10,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,14,5,1));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_Eu(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = 0.285714285714285714e0 * wr_4_0;
 results[k++] = 0.699854212223765171e0 * wr_4_0;
 results[k++] = -0.436435780471984762e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.428571428571428571e0 * wr_4_0;
 results[k++] = 0.508984881617283761e0 * wr_4_0 - 0.617605654987961318e0 * wr_6_0;
 results[k++] = 0.178541910193084675e0 * wr_4_0 - 0.154057917406604252e1 * wr_6_0;
 results[k++] = 0.508984881617283761e0 * wr_4_0 - 0.617605654987961318e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.259740259740259740e-1 * wr_4_0 + 0.121025497358231808e1 * wr_6_0;
 results[k++] = -0.583115436899835021e0 * wr_4_0 + 0.188681644241007573e0 * wr_6_0;
 results[k++] = 0.178541910193084675e0 * wr_4_0 - 0.154057917406604252e1 * wr_6_0;
 results[k++] = -0.583115436899835021e0 * wr_4_0 + 0.188681644241007573e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.272727272727272727e0 * wr_4_0 + 0.134472774842479787e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.629836657297773559e0 * wr_4_0 - 0.524055776089376072e0 * wr_6_0;
 results[k++] = -0.474455714591177738e0 * wr_4_0 - 0.127541405484509065e1 * wr_6_0;
 results[k++] = 0.574959574576068970e0 * wr_4_0 - 0.478395283258379572e0 * wr_6_0;
 results[k++] = 0.124985206225168621e1 * wr_6_0;
 results[k++] = 0.899766653282533658e-1 * wr_4_0 + 0.611398405437605417e0 * wr_6_0;
 results[k++] = -0.565120304644593426e-1 * wr_4_0 + 0.798727532199149510e0 * wr_6_0 
             + 0.376097596508327073e0 * wr_8_0;
 results[k++] = 0.158586492171703732e0 * wr_4_0 - 0.186785298179541805e0 * wr_6_0 
             - 0.402065242892373513e0 * wr_8_0;
 results[k++] = -0.328469340870815357e0 * wr_4_0 - 0.283425345521131256e0 * wr_6_0;
 results[k++] = -0.515757872616547153e0 * wr_4_0 + 0.347123738349394590e-1 * wr_6_0 
             - 0.392281167495726058e0 * wr_8_0;
 results[k++] = 0.192978925386251716e0 * wr_4_0 - 0.346351493258559239e0 * wr_6_0 
             + 0.419366208015054044e0 * wr_8_0;
 results[k++] = -0.265365957496647217e0 * wr_4_0 - 0.318930188838919714e0 * wr_6_0 
             + 0.471978454675304887e0 * wr_8_0;
 results[k++] = -0.108335198495312360e0 * wr_4_0 + 0.585912169668626903e0 * wr_6_0 
             + 0.420402321287932526e0 * wr_8_0;
 results[k++] = -0.173722798156117146e0 * wr_4_0 - 0.974347821173939868e0 * wr_6_0 
             + 0.655417271193293552e-1 * wr_8_0;
 results[k++] = -0.624926031125843104e0 * wr_6_0 + 0.264960950893566853e0 * wr_8_0;
 results[k++] = 0.385957850772503432e0 * wr_4_0 - 0.556636328451255918e0 * wr_6_0 
             + 0.124811371433051799e0 * wr_8_0;
 results[k++] = -0.412606298093237722e0 * wr_4_0 - 0.867809345873486476e-1 * wr_6_0 
             + 0.155667129958621452e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.139860139860139860e-1 * wr_4_0 + 0.645469319243902978e0 * wr_6_0 
             - 0.265941160879000072e0 * wr_8_0;
 results[k++] = -0.495986409281410961e0 * wr_4_0 + 0.981814197190726943e-1 * wr_6_0 
             - 0.184923115778669176e0 * wr_8_0;
 results[k++] = 0.153209106994452060e0 * wr_4_0 + 0.779863469839828841e0 * wr_6_0 
             + 0.219040560575246240e0 * wr_8_0 - 0.516461726310150947e0 * wr_10_0;
 results[k++] = -0.545826827066845495e-1 * wr_4_0 + 0.106308813903487461e1 * wr_10_0 
             + 0.231530189707450246e0 * wr_6_0 - 0.162574939412243965e0 * wr_8_0;
 results[k++] = -0.495986409281410961e0 * wr_4_0 + 0.981814197190726943e-1 * wr_6_0 
             - 0.184923115778669176e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.710059171597633136e-1 * wr_4_0 - 0.199457808114773186e0 * wr_6_0 
             + 0.294396403656683711e0 * wr_8_0 + 0.725327532277253882e0 * wr_10_0;
 results[k++] = -0.606300049551190597e0 * wr_6_0 - 0.222119653324817147e-1 * wr_8_0 
             - 0.658393022122119217e0 * wr_10_0 - 0.159801732105540277e0 * wr_4_0;
 results[k++] = 0.151817036825992550e0 * wr_4_0 + 0.939139405724472084e-1 * wr_6_0 
             - 0.527552911102353247e0 * wr_8_0 + 0.284316174368883002e-1 * wr_10_0;
 results[k++] = 0.153209106994452060e0 * wr_4_0 + 0.779863469839828841e0 * wr_6_0 
             + 0.219040560575246240e0 * wr_8_0 - 0.516461726310150947e0 * wr_10_0;
 results[k++] = -0.606300049551190597e0 * wr_6_0 - 0.222119653324817147e-1 * wr_8_0 
             - 0.658393022122119217e0 * wr_10_0 - 0.159801732105540277e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.227772227772227772e0 * wr_4_0 - 0.711914690342540050e-1 * wr_6_0 
             - 0.184959078054943659e0 * wr_8_0 - 0.449012281885919069e0 * wr_10_0;
 results[k++] = 0.341670475058265875e0 * wr_4_0 + 0.906475734818224852e-1 * wr_10_0 
             + 0.474911795205982356e-1 * wr_8_0 - 0.718614409995251973e0 * wr_6_0;
 results[k++] = -0.545826827066845495e-1 * wr_4_0 + 0.106308813903487461e1 * wr_10_0 
             + 0.231530189707450246e0 * wr_6_0 - 0.162574939412243965e0 * wr_8_0;
 results[k++] = 0.151817036825992550e0 * wr_4_0 + 0.939139405724472084e-1 * wr_6_0 
             - 0.527552911102353247e0 * wr_8_0 + 0.284316174368883002e-1 * wr_10_0;
 results[k++] = 0.341670475058265875e0 * wr_4_0 + 0.906475734818224852e-1 * wr_10_0 
             + 0.474911795205982356e-1 * wr_8_0 - 0.718614409995251973e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.324598478444632291e0 * wr_4_0 - 0.200796451122254886e0 * wr_6_0 
             - 0.634475007880783862e-1 * wr_8_0 + 0.142762879368856319e0 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_T1g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,2,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,2,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,2,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,6,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,6,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,8,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,8,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,10,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,4,1));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,2,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,2,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,10,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,2,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,16,6,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_T1g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=2)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0;
 results[k++] = 0.285714285714285714e0 * wr_4_0;
 results[k++] = 0.638876564999939914e0 * wr_4_0;
 results[k++] = 0.285714285714285714e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.428571428571428571e0 * wr_4_0;
 results[k++] = 0.319438282499969957e0 * wr_4_0;
 results[k++] = 0.638876564999939914e0 * wr_4_0;
 results[k++] = 0.319438282499969957e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.142857142857142857e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.451753951452625620e0 * wr_4_0;
 results[k++] = -0.328548328329182269e0 * wr_4_0 + 0.398662736048649643e0 * wr_6_0;
 results[k++] = -0.183664099009492863e0 * wr_4_0 - 0.124801176906117111e1 * wr_6_0;
 results[k++] = -0.182743471161951801e0 * wr_4_0;
 results[k++] = 0.199356513994856510e0 * wr_4_0 - 0.112886911961552136e1 * wr_6_0;
 results[k++] = -0.222887358524943659e0 * wr_4_0 + 0.721208025474470581e-1 * wr_6_0;
 results[k++] = -0.447229124558611505e0 * wr_4_0 + 0.144712215171007889e0 * wr_6_0;
 results[k++] = -0.651204968269535501e0 * wr_6_0 - 0.372690937132176256e-1 * wr_4_0;
 results[k++] = -0.808965875742374985e0 * wr_6_0 - 0.250008681007693989e0 * wr_4_0;
 results[k++] = 0.881947727404847175e-1 * wr_4_0 + 0.733824866177795418e0 * wr_6_0;
 results[k++] = 0.856129010540761320e0 * wr_6_0 - 0.818951461161643805e-1 * wr_4_0;
 results[k++] = -0.382872533015755260e0 * wr_6_0 + 0.408505407580586299e0 * wr_4_0;
 results[k++] = -0.139930052456288247e1 * wr_6_0;
 results[k++] = -0.327613622798385077e0 * wr_4_0 + 0.572441123684815558e0 * wr_6_0;
 results[k++] = -0.439539798559298345e0 * wr_4_0 + 0.142224140630623609e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.116883116883116883e0 * wr_4_0 - 0.378204679244474401e0 * wr_6_0;
 results[k++] = 0.236407743980617355e0 * wr_4_0 - 0.356979759821410922e0 * wr_6_0;
 results[k++] = -0.163184154180964462e0 * wr_4_0 - 0.411858184669882087e0 * wr_6_0 
             + 0.488421477061400274e0 * wr_8_0;
 results[k++] = -0.358581033746822544e0 * wr_4_0 + 0.541463528851021698e0 * wr_6_0;
 results[k++] = -0.482724740584047031e0 * wr_6_0 + 0.277812406649398171e0 * wr_8_0 
             + 0.717234397298420657e-1 * wr_4_0;
 results[k++] = 0.236407743980617355e0 * wr_4_0 - 0.356979759821410922e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.563981473072382163e-1 * wr_4_0 + 0.518025803086370997e-1 * wr_6_0 
             - 0.386823506733091013e0 * wr_8_0;
 results[k++] = 0.290553258228432014e0 * wr_8_0 - 0.198033721748976116e0 * wr_4_0 
             - 0.925582438195983543e-1 * wr_6_0;
 results[k++] = 0.323580148864015979e0 * wr_4_0 - 0.438065564016264649e-1 * wr_6_0 
             - 0.330035761328438168e0 * wr_8_0;
 results[k++] = 0.261122039286750831e0 * wr_4_0 - 0.325452953709368725e0 * wr_6_0 
             - 0.510821144600745079e-1 * wr_8_0;
 results[k++] = -0.163184154180964462e0 * wr_4_0 - 0.411858184669882087e0 * wr_6_0 
             + 0.488421477061400274e0 * wr_8_0;
 results[k++] = 0.290553258228432014e0 * wr_8_0 - 0.198033721748976116e0 * wr_4_0 
             - 0.925582438195983543e-1 * wr_6_0;
 results[k++] = wr_0_0 + 0.814479638009049774e-1 * wr_4_0 - 0.391553079688397026e0 * wr_6_0 
             - 0.212305968768949637e0 * wr_8_0;
 results[k++] = -0.125156532991470987e-1 * wr_4_0 + 0.315880808012034351e0 * wr_6_0 
             - 0.220354219239537093e0 * wr_8_0;
 results[k++] = -0.584087418688352865e0 * wr_6_0 + 0.325439804891970094e0 * wr_4_0 
             + 0.687574502767579517e-1 * wr_8_0;
 results[k++] = -0.358581033746822544e0 * wr_4_0 + 0.541463528851021698e0 * wr_6_0;
 results[k++] = 0.323580148864015979e0 * wr_4_0 - 0.438065564016264649e-1 * wr_6_0 
             - 0.330035761328438168e0 * wr_8_0;
 results[k++] = -0.125156532991470987e-1 * wr_4_0 + 0.315880808012034351e0 * wr_6_0 
             - 0.220354219239537093e0 * wr_8_0;
 results[k++] = wr_0_0 - 0.814479638009049774e-1 * wr_4_0 - 0.522070772917862704e-1 * wr_6_0 
             - 0.281584758577764782e0 * wr_8_0;
 results[k++] = -0.309923475443660815e0 * wr_8_0 + 0.154026228026981424e0 * wr_4_0 
             + 0.185116487639196709e0 * wr_6_0;
 results[k++] = -0.482724740584047031e0 * wr_6_0 + 0.277812406649398171e0 * wr_8_0 
             + 0.717234397298420657e-1 * wr_4_0;
 results[k++] = 0.261122039286750831e0 * wr_4_0 - 0.325452953709368725e0 * wr_6_0 
             - 0.510821144600745079e-1 * wr_8_0;
 results[k++] = -0.584087418688352865e0 * wr_6_0 + 0.325439804891970094e0 * wr_4_0 
             + 0.687574502767579517e-1 * wr_8_0;
 results[k++] = -0.309923475443660815e0 * wr_8_0 + 0.154026228026981424e0 * wr_4_0 
             + 0.185116487639196709e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.366179275270184361e0 * wr_4_0 - 0.366743931388581237e-1 * wr_6_0 
             + 0.259033598258766303e-1 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = -0.644658371220304240e0 * wr_4_0;
 results[k++] = -0.102559286330502947e0 * wr_4_0 - 0.853344843783741653e0 * wr_6_0;
 results[k++] = 0.176407335352976580e-1 * wr_4_0 - 0.254418277193251359e-1 * wr_6_0 
             - 0.602413691838860684e0 * wr_8_0;
 results[k++] = 0.591628521323607743e0 * wr_4_0 - 0.191436266507877630e0 * wr_6_0;
 results[k++] = -0.159284601894817470e0 * wr_4_0 - 0.492264685305971051e0 * wr_6_0 
             + 0.458680610769187630e0 * wr_8_0;
 results[k++] = 0.508815996579719523e-1 * wr_4_0 + 0.301659125188536953e0 * wr_8_0 
             + 0.733824866177795418e0 * wr_6_0;
 results[k++] = -0.116670717803590529e0 * wr_4_0 - 0.970759050890849983e0 * wr_6_0;
 results[k++] = -0.350012153410771585e0 * wr_4_0 + 0.647172700593899988e0 * wr_6_0;
 results[k++] = -0.831387475141008569e-1 * wr_4_0 + 0.347309316410418934e0 * wr_6_0 
             - 0.342650774767760567e0 * wr_8_0;
 results[k++] = 0.269679944985296835e0 * wr_6_0;
 results[k++] = -0.364265061042256044e0 * wr_4_0 + 0.266062664381112804e0 * wr_8_0 
             + 0.294196303620323820e0 * wr_6_0;
 results[k++] = 0.228066002729206574e0 * wr_4_0 - 0.328921466812105770e0 * wr_6_0 
             - 0.540849276209891129e-1 * wr_8_0;
 results[k++] = 0.399643334748513800e0 * wr_8_0;
 results[k++] = 0.679026791926730407e0 * wr_4_0 - 0.171378614099395059e0 * wr_6_0 
             - 0.322788847296876530e0 * wr_8_0;
 results[k++] = 0.383214231015951249e0 * wr_6_0 + 0.240592601644871719e0 * wr_8_0 
             + 0.151835006529177459e0 * wr_4_0;
 results[k++] = -0.992277876713667651e0 * wr_6_0;
 results[k++] = 0.893533657342573306e-1 * wr_4_0 + 0.101482964663897828e0 * wr_6_0 
             - 0.200243499524913390e0 * wr_8_0;
 results[k++] = -0.149252692330051061e0 * wr_8_0 + 0.680768422640053921e0 * wr_6_0 
             - 0.279720279720279720e0 * wr_4_0;
 results[k++] = 0.246394606670621563e0 * wr_8_0;
 results[k++] = 0.116227242631943056e1 * wr_6_0 - 0.123197303335310781e0 * wr_8_0;
 results[k++] = 0.280835360880946580e0 * wr_4_0 - 0.330771655915764310e0 * wr_6_0 
             + 0.114429134036388382e0 * wr_8_0;
 results[k++] = 0.646864810320029435e0 * wr_8_0;
 results[k++] = -0.544881717778978688e-1 * wr_6_0 + 0.334983562487158101e0 * wr_8_0;
 results[k++] = 0.737282828151573906e0 * wr_4_0 + 0.520585912278005888e0 * wr_6_0 
             + 0.596057838514324167e-2 * wr_8_0;
 results[k++] = 0.324320940005761710e0 * wr_4_0 + 0.719603556244587128e0 * wr_6_0;
 results[k++] = -0.151378015254808107e0 * wr_4_0 + 0.582187942377792639e-1 * wr_6_0 
             + 0.281967832677768438e0 * wr_8_0;
 results[k++] = 0.485137017548475824e-1 * wr_4_0 + 0.571400888182922901e0 * wr_6_0 
             + 0.219637618254846441e0 * wr_8_0;
 results[k++] = -0.792696854714301544e-1 * wr_4_0 + 0.270436259409932358e0 * wr_6_0 
             - 0.249483585209404455e0 * wr_8_0;
 results[k++] = -0.170583698219945813e-1 * wr_4_0 + 0.590928730663219675e-1 * wr_6_0 
             + 0.284527518536197074e-1 * wr_8_0 + 0.843378467424538511e0 * wr_10_0;
 results[k++] = 0.839503563634658644e-1 * wr_4_0 - 0.311335523446577944e0 * wr_6_0 
             - 0.356025791926093858e0 * wr_8_0;
 results[k++] = -0.218311657896814121e0 * wr_4_0 - 0.454788462023142718e0 * wr_6_0 
             + 0.133351411083299624e0 * wr_8_0;
 results[k++] = -0.239434507788650732e0 * wr_4_0 - 0.487506858323272729e0 * wr_6_0 
             - 0.114031108803509295e0 * wr_8_0 + 0.258171001394349556e0 * wr_10_0;
 results[k++] = 0.367925623611647832e-1 * wr_4_0 + 0.393290382088462170e0 * wr_6_0 
             - 0.118353883760855086e0 * wr_8_0 + 0.606350532135289125e0 * wr_10_0;
 results[k++] = -0.546687486009863136e-1 * wr_4_0 + 0.272708833018419185e0 * wr_6_0 
             - 0.536818725824473464e0 * wr_10_0 - 0.984803625826596529e-1 * wr_8_0;
 results[k++] = 0.184472602253051767e0 * wr_4_0 + 0.409307954671785836e0 * wr_6_0;
 results[k++] = 0.356713584621435695e0 * wr_4_0 - 0.215245186060966570e0 * wr_6_0 
             - 0.151472176734281276e0 * wr_8_0;
 results[k++] = 0.367925623611647832e-1 * wr_4_0 + 0.393290382088462170e0 * wr_6_0 
             - 0.118353883760855086e0 * wr_8_0 + 0.606350532135289125e0 * wr_10_0;
 results[k++] = 0.239434507788650732e0 * wr_4_0 - 0.650009144431030306e-1 * wr_6_0 
             - 0.151241260097286012e0 * wr_8_0 - 0.489166107905083370e0 * wr_10_0;
 results[k++] = -0.258739742692520440e-1 * wr_4_0 - 0.586313060499593209e0 * wr_10_0 
             + 0.443899186367689650e0 * wr_8_0 - 0.864303864478370775e-1 * wr_6_0;
 results[k++] = -0.284137125345403336e0 * wr_4_0 + 0.348873899490998893e0 * wr_6_0 
             + 0.114731457242355027e0 * wr_8_0;
 results[k++] = -0.187009065273730196e0 * wr_4_0 - 0.170643082293966994e0 * wr_6_0 
             - 0.373805990525995839e-1 * wr_8_0 + 0.573387101698893161e0 * wr_10_0;
 results[k++] = 0.320570568285146591e0 * wr_4_0 - 0.547449831648201042e0 * wr_10_0 
             - 0.209230537714447629e-1 * wr_8_0 - 0.397299331740010220e0 * wr_6_0;
 results[k++] = 0.151721684647080854e0 * wr_4_0 + 0.125917207732824753e0 * wr_6_0 
             - 0.597924347312346561e0 * wr_10_0 + 0.943104422232004088e-1 * wr_8_0;
 results[k++] = 0.156826301706811490e0 * wr_4_0 + 0.436557011582764186e-1 * wr_6_0 
             - 0.945894395414083264e-1 * wr_8_0 - 0.218743303190782584e0 * wr_10_0;
 results[k++] = -0.179078589606739476e0 * wr_8_0 - 0.398490266762598991e0 * wr_6_0 
             + 0.243959705154902838e0 * wr_10_0 - 0.171781700381256160e0 * wr_4_0;
 results[k++] = 0.251467709729450657e0 * wr_6_0 - 0.434645137738710460e-1 * wr_8_0 
             + 0.138978238524893717e0 * wr_4_0 - 0.690805918580436057e0 * wr_10_0;
 results[k++] = -0.459809636516310408e0 * wr_10_0 - 0.157867995684519497e0 * wr_8_0 
             - 0.433948829520884090e-1 * wr_6_0 + 0.584585073582575625e-1 * wr_4_0;
 results[k++] = 0.213015890587799997e0 * wr_10_0 + 0.184450769883929445e0 * wr_4_0 
             - 0.667114041191173731e-2 * wr_8_0 - 0.136921381185506358e0 * wr_6_0;
 results[k++] = -0.102775793403489990e0 * wr_4_0 + 0.962369606505324291e-1 * wr_10_0 
             - 0.762924632632187511e0 * wr_6_0 - 0.408157986063259190e-1 * wr_8_0;
 results[k++] = -0.226048121857837370e-1 * wr_4_0 + 0.235968611797280252e0 * wr_6_0 
             - 0.111092200902030016e0 * wr_8_0 + 0.674157546335926017e0 * wr_10_0;
 results[k++] = 0.428544529302910185e0 * wr_10_0 + 0.269634047647994984e-1 * wr_8_0 
             - 0.256034709279935280e0 * wr_4_0 + 0.446724735779186778e0 * wr_6_0;
 results[k++] = 0.373089877811481800e0 * wr_4_0 - 0.316938840643062756e-1 * wr_10_0 
             + 0.894621086115097042e-1 * wr_6_0 - 0.163594486661336481e0 * wr_8_0;
 results[k++] = -0.112257719430633264e0 * wr_4_0 - 0.139957606606599612e-1 * wr_6_0 
             - 0.202785112129535584e0 * wr_8_0 + 0.537510167380803618e0 * wr_10_0;
 results[k++] = -0.669290073555875806e-1 * wr_6_0 + 0.398794134531405424e0 * wr_8_0 
             - 0.182578070170785467e0 * wr_4_0 - 0.278604794062295377e0 * wr_10_0;
 results[k++] = -0.682630018347195826e0 * wr_10_0 - 0.324302481951144172e0 * wr_6_0 
             + 0.123026551620075995e0 * wr_8_0;
 results[k++] = -0.310084763940376492e0 * wr_8_0 - 0.428425616539628245e-1 * wr_4_0 
             + 0.585036946376643874e0 * wr_10_0 + 0.250447552542923914e0 * wr_6_0;
 results[k++] = -0.154585075013006056e0 * wr_8_0 + 0.802635564275771820e-1 * wr_6_0 
             + 0.136494854551875427e0 * wr_10_0 - 0.108125368357414403e0 * wr_4_0;
 results[k++] = 0.887378515946673425e-1 * wr_10_0 - 0.341161763082399086e0 * wr_4_0 
             + 0.253250988533794455e0 * wr_6_0 + 0.314281584796916452e0 * wr_8_0;
 results[k++] = 0.135887866888509496e0 * wr_8_0 - 0.282222419490661143e0 * wr_6_0 
             + 0.804299582096521965e-1 * wr_10_0 - 0.316825016071510392e0 * wr_4_0;
 results[k++] = -0.493593082504622564e0 * wr_10_0 + 0.152035348549997290e-1 * wr_6_0 
             - 0.334519274582134234e0 * wr_8_0;
 results[k++] = -0.112475455093714038e0 * wr_4_0 - 0.394167593524261459e0 * wr_6_0 
             - 0.161522199487894355e-1 * wr_8_0 - 0.399336466004909082e-1 * wr_10_0;
 results[k++] = -0.233717688100085974e0 * wr_8_0 - 0.371140693838940958e0 * wr_10_0 
             - 0.218243186677711179e0 * wr_6_0 - 0.591382802894849688e-1 * wr_4_0;
 results[k++] = 0.243907129715450660e0 * wr_4_0 - 0.800402210381542312e-1 * wr_10_0 
             - 0.166732944472900988e-1 * wr_8_0 + 0.749457210085215518e0 * wr_6_0;
 results[k++] = -0.668904753238480464e-1 * wr_8_0 - 0.284341428797907187e-1 * wr_10_0 
             - 0.740924301545004135e0 * wr_6_0 - 0.210912399036671317e0 * wr_4_0;
 results[k++] = -0.366743931388581237e-1 * wr_6_0 - 0.690756262023376809e-1 * wr_8_0 + wr_0_0 
             + 0.249205340114431024e0 * wr_4_0;
 results[k++] = -0.138358694394491435e0 * wr_8_0 - 0.925582438195983543e0 * wr_6_0 
             - 0.205368304035975232e0 * wr_4_0;
 results[k++] = 0.157159886346875318e0 * wr_8_0 - 0.438065564016264649e0 * wr_6_0 
             + 0.335564598821942498e0 * wr_4_0;
 results[k++] = -0.244042788488305946e0 * wr_6_0 - 0.325079930585865494e0 * wr_10_0 
             + 0.184103992420068937e0 * wr_4_0 - 0.456962628820175574e-1 * wr_8_0;
 results[k++] = -0.522200189935819291e0 * wr_10_0 - 0.223603905587230537e0 * wr_8_0 
             - 0.113730089351641706e0 * wr_6_0 - 0.153209106994452060e-1 * wr_4_0;
 results[k++] = 0.323949214357923566e0 * wr_10_0 + 0.282251736564762527e-1 * wr_4_0 
             - 0.202038043653464315e0 * wr_6_0 + 0.138713679041842921e0 * wr_8_0;
 results[k++] = 0.759636269200375170e-1 * wr_8_0 + 0.705183092317923656e0 * wr_12_4 
             - 0.403210744504735514e0 * wr_12_0 + 0.166692299507849555e-2 * wr_4_0 
             - 0.403790156842755680e0 * wr_10_0 - 0.258332140543219838e-1 * wr_6_0;
 results[k++] = -0.519827309693764094e0 * wr_12_0 + 0.437620709965853531e-2 * wr_4_0 
             + 0.275620429170883961e-1 * wr_10_0 + 0.406576774793758043e-1 * wr_6_0 
             + 0.395692195426974845e-2 * wr_8_0 - 0.453074380814656879e0 * wr_12_4;
 results[k++] = -0.138358694394491435e0 * wr_8_0 - 0.925582438195983543e0 * wr_6_0 
             - 0.205368304035975232e0 * wr_4_0;
 results[k++] = -0.115162670496587361e0 * wr_6_0 - 0.146369199732419697e0 * wr_10_0 
             - 0.147656406850585274e0 * wr_8_0 + wr_0_0 + 0.217194570135746606e0 * wr_4_0;
 results[k++] = -0.333750754643922631e-1 * wr_4_0 + 0.929061200035395147e-1 * wr_6_0 
             - 0.153253874283136700e0 * wr_8_0 - 0.343768439006068579e0 * wr_10_0;
 results[k++] = 0.300276708545101893e0 * wr_4_0 - 0.437981344931757396e0 * wr_6_0 
             + 0.131802849874464067e-1 * wr_8_0 - 0.310374880676853709e0 * wr_10_0;
 results[k++] = -0.344425783267118278e-1 * wr_4_0 - 0.181347868122210353e0 * wr_10_0 
             + 0.543629723868575390e0 * wr_12_0 - 0.241709617818910230e0 * wr_6_0 
             + 0.177621425522639385e0 * wr_12_4 - 0.157946012983912154e0 * wr_8_0;
 results[k++] = -0.190881652706858560e0 * wr_12_4 - 0.163675333953971725e0 * wr_8_0 
             - 0.124999953265889387e-1 * wr_10_0 - 0.219817062051793116e0 * wr_4_0 
             + 0.498304191893693895e0 * wr_6_0 + 0.995476683080881009e-1 * wr_12_0;
 results[k++] = -0.524961044983646522e-1 * wr_12_0 + 0.108178803185661285e-1 * wr_4_0 
             + 0.973794440206378232e-1 * wr_8_0 - 0.212889633733302331e-1 * wr_6_0 
             + 0.771165172117807312e0 * wr_12_4 - 0.242249661872627709e0 * wr_10_0;
 results[k++] = 0.147228304692806554e0 * wr_8_0 + 0.578864358178915835e-1 * wr_6_0 
             - 0.310368213332499333e0 * wr_12_4 + 0.591675060289954136e-2 * wr_4_0 
             + 0.283021363926766597e0 * wr_12_0 + 0.658696680434101768e0 * wr_10_0;
 results[k++] = 0.157159886346875318e0 * wr_8_0 - 0.438065564016264649e0 * wr_6_0 
             + 0.335564598821942498e0 * wr_4_0;
 results[k++] = -0.333750754643922631e-1 * wr_4_0 + 0.929061200035395147e-1 * wr_6_0 
             - 0.153253874283136700e0 * wr_8_0 - 0.343768439006068579e0 * wr_10_0;
 results[k++] = -0.153550227328783148e-1 * wr_6_0 + 0.277331115282479425e0 * wr_10_0 
             - 0.195839023822881521e0 * wr_8_0 + wr_0_0 - 0.217194570135746606e0 * wr_4_0;
 results[k++] = 0.142116877180749842e0 * wr_4_0 - 0.594099943235985247e-1 * wr_8_0 
             - 0.338991241246945828e0 * wr_10_0 + 0.138810673935297290e0 * wr_6_0;
 results[k++] = -0.762652471124901082e0 * wr_6_0 - 0.667443724453794401e-2 * wr_8_0 
             + 0.127372427221796487e0 * wr_12_4 - 0.108674688702125252e0 * wr_4_0 
             + 0.840129796472442072e-1 * wr_10_0 - 0.664266468613612189e-1 * wr_12_0;
 results[k++] = -0.967946645608875454e0 * wr_12_4 - 0.779564255100785533e-1 * wr_6_0 
             + 0.661399934584794242e-1 * wr_4_0 + 0.504798812513302608e0 * wr_12_0 
             + 0.211992779636021174e0 * wr_10_0 - 0.202885327165121389e0 * wr_8_0;
 results[k++] = -0.197978789290452143e0 * wr_8_0 - 0.671718431019238380e-1 * wr_6_0 
             - 0.462721272174070677e0 * wr_12_4 - 0.157491024952458315e0 * wr_10_0 
             + 0.221153956427736741e0 * wr_12_0 + 0.341330362926188302e-1 * wr_4_0;
 results[k++] = 0.105031882484961280e-1 * wr_8_0 - 0.262076395196727052e0 * wr_12_0 
             - 0.244027666974953474e-1 * wr_4_0 - 0.322133879335640003e0 * wr_12_4 
             - 0.198784701370402933e0 * wr_6_0 + 0.142054559832027254e0 * wr_10_0;
 results[k++] = -0.244042788488305946e0 * wr_6_0 - 0.325079930585865494e0 * wr_10_0 
             + 0.184103992420068937e0 * wr_4_0 - 0.456962628820175574e-1 * wr_8_0;
 results[k++] = 0.300276708545101893e0 * wr_4_0 - 0.437981344931757396e0 * wr_6_0 
             + 0.131802849874464067e-1 * wr_8_0 - 0.310374880676853709e0 * wr_10_0;
 results[k++] = 0.142116877180749842e0 * wr_4_0 - 0.594099943235985247e-1 * wr_8_0 
             - 0.338991241246945828e0 * wr_10_0 + 0.138810673935297290e0 * wr_6_0;
 results[k++] = 0.110704437493457185e-1 * wr_6_0 - 0.137469339925217976e0 * wr_10_0 
             - 0.669146942870389861e-1 * wr_8_0 + wr_0_0 - 0.186679630529897910e0 * wr_4_0 
             - 0.442276022537161318e0 * wr_12_0 + 0.848059824698575913e0 * wr_12_4;
 results[k++] = -0.619092691691191443e0 * wr_6_0 - 0.168561804315818904e-1 * wr_8_0 
             + 0.477690270632027538e0 * wr_12_4 - 0.101950092401429284e0 * wr_4_0 
             + 0.119947966444904096e0 * wr_12_0 - 0.806402223614547652e-1 * wr_10_0;
 results[k++] = -0.543110781113900138e-1 * wr_6_0 + 0.499383206906922875e0 * wr_12_4 
             + 0.233452432332468042e0 * wr_10_0 - 0.181111237461428749e0 * wr_4_0 
             + 0.164694704409778877e0 * wr_8_0 - 0.260435893837027082e0 * wr_12_0;
 results[k++] = 0.322183668181890971e0 * wr_12_0 + 0.808147653520749672e-1 * wr_4_0 
             - 0.363932986056642627e0 * wr_10_0 - 0.218241375026225074e0 * wr_8_0 
             - 0.254695713809472369e0 * wr_12_4 + 0.190846546155834233e0 * wr_6_0;
 results[k++] = 0.537988958363837488e-1 * wr_4_0 + 0.128660050987837114e0 * wr_10_0 
             - 0.169879859963250898e0 * wr_12_0 + 0.107428791437367000e0 * wr_8_0 
             - 0.907914839738446550e-1 * wr_12_4 + 0.501033348689957465e0 * wr_6_0;
 results[k++] = -0.522200189935819291e0 * wr_10_0 - 0.223603905587230537e0 * wr_8_0 
             - 0.113730089351641706e0 * wr_6_0 - 0.153209106994452060e-1 * wr_4_0;
 results[k++] = -0.344425783267118278e-1 * wr_4_0 - 0.181347868122210353e0 * wr_10_0 
             + 0.543629723868575390e0 * wr_12_0 - 0.241709617818910230e0 * wr_6_0 
             + 0.177621425522639385e0 * wr_12_4 - 0.157946012983912154e0 * wr_8_0;
 results[k++] = -0.762652471124901082e0 * wr_6_0 - 0.667443724453794401e-2 * wr_8_0 
             + 0.127372427221796487e0 * wr_12_4 - 0.108674688702125252e0 * wr_4_0 
             + 0.840129796472442072e-1 * wr_10_0 - 0.664266468613612189e-1 * wr_12_0;
 results[k++] = -0.619092691691191443e0 * wr_6_0 - 0.168561804315818904e-1 * wr_8_0 
             + 0.477690270632027538e0 * wr_12_4 - 0.101950092401429284e0 * wr_4_0 
             + 0.119947966444904096e0 * wr_12_0 - 0.806402223614547652e-1 * wr_10_0;
 results[k++] = 0.332579185520361991e0 * wr_4_0 - 0.458936104058035397e0 * wr_10_0 
             - 0.222280253062323328e0 * wr_12_0 + 0.171733806880875889e-1 * wr_6_0 
             + 0.303566869068240242e0 * wr_12_4 - 0.981925607434546450e-1 * wr_8_0 + wr_0_0;
 results[k++] = 0.114976234487609666e0 * wr_10_0 + 0.187560890418395683e-1 * wr_4_0 
             - 0.902749757005347109e-1 * wr_12_0 - 0.103369538837753692e-1 * wr_8_0 
             - 0.359518204866742084e0 * wr_12_4 + 0.355926530355372677e-1 * wr_6_0;
 results[k++] = -0.106580455776258194e0 * wr_10_0 + 0.605392740944607897e-1 * wr_8_0 
             - 0.132771611099110089e0 * wr_12_4 + 0.864329227841398891e-1 * wr_12_0 
             - 0.667044749033691518e0 * wr_6_0 + 0.338955454788104760e0 * wr_4_0;
 results[k++] = 0.165440240215776021e0 * wr_12_0 + 0.176560853523010858e-1 * wr_4_0 
             + 0.543648413401902217e0 * wr_10_0 - 0.220329792742601913e0 * wr_12_4 
             + 0.158934996927004215e0 * wr_8_0 + 0.328351171791875968e0 * wr_6_0;
 results[k++] = 0.323949214357923566e0 * wr_10_0 + 0.282251736564762527e-1 * wr_4_0 
             - 0.202038043653464315e0 * wr_6_0 + 0.138713679041842921e0 * wr_8_0;
 results[k++] = -0.190881652706858560e0 * wr_12_4 - 0.163675333953971725e0 * wr_8_0 
             - 0.124999953265889387e-1 * wr_10_0 - 0.219817062051793116e0 * wr_4_0 
             + 0.498304191893693895e0 * wr_6_0 + 0.995476683080881009e-1 * wr_12_0;
 results[k++] = -0.967946645608875454e0 * wr_12_4 - 0.779564255100785533e-1 * wr_6_0 
             + 0.661399934584794242e-1 * wr_4_0 + 0.504798812513302608e0 * wr_12_0 
             + 0.211992779636021174e0 * wr_10_0 - 0.202885327165121389e0 * wr_8_0;
 results[k++] = -0.543110781113900138e-1 * wr_6_0 + 0.499383206906922875e0 * wr_12_4 
             + 0.233452432332468042e0 * wr_10_0 - 0.181111237461428749e0 * wr_4_0 
             + 0.164694704409778877e0 * wr_8_0 - 0.260435893837027082e0 * wr_12_0;
 results[k++] = 0.114976234487609666e0 * wr_10_0 + 0.187560890418395683e-1 * wr_4_0 
             - 0.902749757005347109e-1 * wr_12_0 - 0.103369538837753692e-1 * wr_8_0 
             - 0.359518204866742084e0 * wr_12_4 + 0.355926530355372677e-1 * wr_6_0;
 results[k++] = -0.124897314095182465e-1 * wr_6_0 + 0.302595233444858503e0 * wr_10_0 
             - 0.193579619751382015e0 * wr_8_0 + wr_0_0 - 0.316536404771698889e0 * wr_4_0 
             - 0.678491625483145203e-1 * wr_12_0 + 0.130100086743531532e0 * wr_12_4;
 results[k++] = 0.309434314821306451e-1 * wr_12_4 - 0.241385772782402084e0 * wr_6_0 
             + 0.215405066148829895e0 * wr_10_0 - 0.545150994651249243e-1 * wr_4_0 
             + 0.892234963246693034e-1 * wr_8_0 - 0.169827633427557131e0 * wr_12_0;
 results[k++] = -0.633715016065973837e0 * wr_6_0 - 0.702819502676001386e-1 * wr_4_0 
             + 0.668934972579685567e-1 * wr_10_0 - 0.184543459913016671e0 * wr_12_4 
             + 0.213091013333088054e-1 * wr_12_0 - 0.786900918389524449e-1 * wr_8_0;
 results[k++] = 0.759636269200375170e-1 * wr_8_0 + 0.705183092317923656e0 * wr_12_4 
             - 0.403210744504735514e0 * wr_12_0 + 0.166692299507849555e-2 * wr_4_0 
             - 0.403790156842755680e0 * wr_10_0 - 0.258332140543219838e-1 * wr_6_0;
 results[k++] = -0.524961044983646522e-1 * wr_12_0 + 0.108178803185661285e-1 * wr_4_0 
             + 0.973794440206378232e-1 * wr_8_0 - 0.212889633733302331e-1 * wr_6_0 
             + 0.771165172117807312e0 * wr_12_4 - 0.242249661872627709e0 * wr_10_0;
 results[k++] = -0.197978789290452143e0 * wr_8_0 - 0.671718431019238380e-1 * wr_6_0 
             - 0.462721272174070677e0 * wr_12_4 - 0.157491024952458315e0 * wr_10_0 
             + 0.221153956427736741e0 * wr_12_0 + 0.341330362926188302e-1 * wr_4_0;
 results[k++] = 0.322183668181890971e0 * wr_12_0 + 0.808147653520749672e-1 * wr_4_0 
             - 0.363932986056642627e0 * wr_10_0 - 0.218241375026225074e0 * wr_8_0 
             - 0.254695713809472369e0 * wr_12_4 + 0.190846546155834233e0 * wr_6_0;
 results[k++] = -0.106580455776258194e0 * wr_10_0 + 0.605392740944607897e-1 * wr_8_0 
             - 0.132771611099110089e0 * wr_12_4 + 0.864329227841398891e-1 * wr_12_0 
             - 0.667044749033691518e0 * wr_6_0 + 0.338955454788104760e0 * wr_4_0;
 results[k++] = 0.309434314821306451e-1 * wr_12_4 - 0.241385772782402084e0 * wr_6_0 
             + 0.215405066148829895e0 * wr_10_0 - 0.545150994651249243e-1 * wr_4_0 
             + 0.892234963246693034e-1 * wr_8_0 - 0.169827633427557131e0 * wr_12_0;
 results[k++] = 0.680510525201708144e-1 * wr_12_4 - 0.223253948945138656e0 * wr_6_0 
             - 0.210511068821932590e0 * wr_8_0 + 0.243882853260042579e0 * wr_10_0 + wr_0_0 
             - 0.236842105263157895e0 * wr_4_0 - 0.194826816671507818e-2 * wr_12_0;
 results[k++] = -0.150273656759487451e-1 * wr_12_0 + 0.471606985569855479e-2 * wr_12_4 
             + 0.108288586814455945e0 * wr_10_0 + 0.979705513571159168e-1 * wr_4_0 
             + 0.117587026177734943e0 * wr_8_0 + 0.549481094405537094e0 * wr_6_0;
 results[k++] = -0.519827309693764094e0 * wr_12_0 + 0.437620709965853531e-2 * wr_4_0 
             + 0.275620429170883961e-1 * wr_10_0 + 0.406576774793758043e-1 * wr_6_0 
             + 0.395692195426974845e-2 * wr_8_0 - 0.453074380814656879e0 * wr_12_4;
 results[k++] = 0.147228304692806554e0 * wr_8_0 + 0.578864358178915835e-1 * wr_6_0 
             - 0.310368213332499333e0 * wr_12_4 + 0.591675060289954136e-2 * wr_4_0 
             + 0.283021363926766597e0 * wr_12_0 + 0.658696680434101768e0 * wr_10_0;
 results[k++] = 0.105031882484961280e-1 * wr_8_0 - 0.262076395196727052e0 * wr_12_0 
             - 0.244027666974953474e-1 * wr_4_0 - 0.322133879335640003e0 * wr_12_4 
             - 0.198784701370402933e0 * wr_6_0 + 0.142054559832027254e0 * wr_10_0;
 results[k++] = 0.537988958363837488e-1 * wr_4_0 + 0.128660050987837114e0 * wr_10_0 
             - 0.169879859963250898e0 * wr_12_0 + 0.107428791437367000e0 * wr_8_0 
             - 0.907914839738446550e-1 * wr_12_4 + 0.501033348689957465e0 * wr_6_0;
 results[k++] = 0.165440240215776021e0 * wr_12_0 + 0.176560853523010858e-1 * wr_4_0 
             + 0.543648413401902217e0 * wr_10_0 - 0.220329792742601913e0 * wr_12_4 
             + 0.158934996927004215e0 * wr_8_0 + 0.328351171791875968e0 * wr_6_0;
 results[k++] = -0.633715016065973837e0 * wr_6_0 - 0.702819502676001386e-1 * wr_4_0 
             + 0.668934972579685567e-1 * wr_10_0 - 0.184543459913016671e0 * wr_12_4 
             + 0.213091013333088054e-1 * wr_12_0 - 0.786900918389524449e-1 * wr_8_0;
 results[k++] = -0.150273656759487451e-1 * wr_12_0 + 0.471606985569855479e-2 * wr_12_4 
             + 0.108288586814455945e0 * wr_10_0 + 0.979705513571159168e-1 * wr_4_0 
             + 0.117587026177734943e0 * wr_8_0 + 0.549481094405537094e0 * wr_6_0;
 results[k++] = -0.274774091009401422e0 * wr_6_0 - 0.218169964577673873e-1 * wr_10_0 
             + 0.534029716324051580e-1 * wr_8_0 + wr_0_0 + 0.521909978566325316e0 * wr_4_0 
             + 0.230363228032390844e-2 * wr_12_0 - 0.591748282784094038e-3 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_T1u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,2,1,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,6,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,2,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,10,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,10,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,2,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,2,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,2,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,2,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,2,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,10,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,10,3,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,10,3,2));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,1,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(2,3,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,2,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,10,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,2,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,14,5,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_T1u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = 0.571428571428571429e0 * wr_4_0;
 results[k++] = 0.178174161274949590e0 * wr_4_0;
 results[k++] = -0.436435780471984762e0 * wr_4_0;
 results[k++] = 0.414039335605412531e0 * wr_4_0;
 results[k++] = 0.338061701891406632e0 * wr_4_0;
 results[k++] = -0.733358797622569035e0 * wr_4_0;
 results[k++] = 0.149696237713023949e0 * wr_4_0;
 results[k++] = 0.144620305212437449e0 * wr_4_0;
 results[k++] = 0.328942671772035394e0 * wr_4_0;
 results[k++] = wr_0_0;
 results[k++] = -0.436435780471984762e0 * wr_4_0;
 results[k++] = 0.338061701891406632e0 * wr_4_0;
 results[k++] = 0.264207148652341136e0 * wr_6_0 + 0.816524932980130631e-1 * wr_4_0;
 results[k++] = -0.161020888280017325e-1 * wr_4_0 + 0.133977477487929459e1 * wr_6_0;
 results[k++] = -0.436435780471984762e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.272727272727272727e0 * wr_4_0 + 0.350189517818957779e0 * wr_6_0;
 results[k++] = 0.164308384384557080e0 * wr_4_0 - 0.113927366324455231e1 * wr_6_0;
 results[k++] = -0.187089365610009641e0 * wr_4_0 - 0.605374628923901556e0 * wr_6_0;
 results[k++] = -0.411110370735372510e0 * wr_4_0 + 0.795876578528472460e0 * wr_6_0;
 results[k++] = 0.338061701891406632e0 * wr_4_0;
 results[k++] = 0.164308384384557080e0 * wr_4_0 - 0.113927366324455231e1 * wr_6_0;
 results[k++] = wr_0_0 - 0.909090909090909091e-1 * wr_4_0 + 0.756409358488948801e-1 * wr_6_0;
 results[k++] = -0.241531332420025989e0 * wr_4_0 - 0.781535285346255180e0 * wr_6_0;
 results[k++] = 0.394653717607063139e0 * wr_4_0 - 0.369890008113277591e0 * wr_6_0;
 results[k++] = 0.264207148652341136e0 * wr_6_0 + 0.816524932980130631e-1 * wr_4_0;
 results[k++] = -0.187089365610009641e0 * wr_4_0 - 0.605374628923901556e0 * wr_6_0;
 results[k++] = -0.241531332420025989e0 * wr_4_0 - 0.781535285346255180e0 * wr_6_0;
 results[k++] = wr_0_0 + 0.352941176470588235e0 * wr_4_0 + 0.217529488715776126e0 * wr_6_0;
 results[k++] = -0.175489337784463528e0 * wr_6_0 - 0.542344976296374275e-1 * wr_4_0;
 results[k++] = -0.161020888280017325e-1 * wr_4_0 + 0.133977477487929459e1 * wr_6_0;
 results[k++] = -0.411110370735372510e0 * wr_4_0 + 0.795876578528472460e0 * wr_6_0;
 results[k++] = 0.394653717607063139e0 * wr_4_0 - 0.369890008113277591e0 * wr_6_0;
 results[k++] = -0.175489337784463528e0 * wr_6_0 - 0.542344976296374275e-1 * wr_4_0;
 results[k++] = wr_0_0 - 0.352941176470588235e0 * wr_4_0 + 0.290039318287701501e-1 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = -0.666666666666666667e0 * wr_4_0;
 results[k++] = 0.742269619025205484e-1 * wr_4_0 + 0.617605654987961318e0 * wr_6_0;
 results[k++] = -0.585540043769119909e0 * wr_4_0;
 results[k++] = -0.126571494788797394e1 * wr_6_0 - 0.152120004824377373e0 * wr_4_0;
 results[k++] = 0.398622532737182282e0 * wr_4_0 + 0.892968449944494126e-1 * wr_6_0;
 results[k++] = -0.656195117630409645e0 * wr_6_0 - 0.175255195801893776e0 * wr_4_0;
 results[k++] = -0.786094235671469647e-1 * wr_4_0 + 0.452817650885350557e0 * wr_6_0;
 results[k++] = 0.862689482040431319e0 * wr_6_0 - 0.385105953427649434e0 * wr_4_0;
 results[k++] = -0.960768922830522798e0 * wr_6_0;
 results[k++] = 0.641834624088602286e0 * wr_6_0 - 0.367328198018985727e0 * wr_4_0;
 results[k++] = 0.774209661138763753e0 * wr_4_0 + 0.300617975667198279e0 * wr_6_0;
 results[k++] = -0.159881613006357904e1 * wr_6_0;
 results[k++] = -0.178012895963046929e0 * wr_6_0 + 0.101878511760095601e0 * wr_4_0;
 results[k++] = 0.233284737407921724e0 * wr_4_0;
 results[k++] = -0.291557718449917511e0 * wr_4_0 - 0.366880974913070281e0 * wr_6_0;
 results[k++] = -0.125466465334973494e0 * wr_4_0 - 0.852554343527197385e0 * wr_6_0;
 results[k++] = 0.690732277014531808e0 * wr_8_0 + 0.226510445207864996e0 * wr_6_0 
             + 0.192314370005918453e-1 * wr_4_0;
 results[k++] = 0.422591800945434102e-1 * wr_4_0 - 0.297789747901142981e0 * wr_6_0;
 results[k++] = -0.478091443733757458e0 * wr_4_0;
 results[k++] = 0.265562452123716903e0 * wr_4_0 - 0.322235253162984833e0 * wr_6_0;
 results[k++] = -0.197792106625607699e0 * wr_4_0 + 0.499204707624468445e-1 * wr_6_0 
             - 0.429825824580945227e0 * wr_8_0;
 results[k++] = 0.656878627012394570e-1 * wr_4_0 + 0.297390740967524126e0 * wr_8_0 
             + 0.773680460006860622e0 * wr_6_0;
 results[k++] = -0.107331661515551966e0 * wr_4_0 + 0.366172426242063931e0 * wr_6_0 
             - 0.337802371261244973e0 * wr_8_0;
 results[k++] = -0.300437478517532188e0 * wr_4_0 - 0.170124660126402500e0 * wr_6_0;
 results[k++] = -0.661912253321279002e-2 * wr_4_0 - 0.445490932918785729e0 * wr_6_0 
             + 0.424531976607546496e0 * wr_8_0;
 results[k++] = 0.290153872117684280e0 * wr_8_0 - 0.143781580340071886e0 * wr_6_0 
             - 0.213631261146994879e0 * wr_4_0;
 results[k++] = -0.195293087065833991e0 * wr_8_0 - 0.560274474388845827e0 * wr_6_0 
             - 0.249737432852796338e0 * wr_4_0;
 results[k++] = -0.202696400731455016e0 * wr_8_0 + 0.451994794216174692e0 * wr_6_0 
             + 0.383757552619123712e-1 * wr_4_0;
 results[k++] = 0.592470697580999131e-1 * wr_4_0 - 0.862689482040431319e0 * wr_6_0;
 results[k++] = -0.145448668859368844e-1 * wr_4_0 + 0.585679978176670110e0 * wr_6_0;
 results[k++] = 0.349065980649376340e0 * wr_4_0 - 0.680498640505610003e-1 * wr_6_0 
             - 0.329582103710112642e0 * wr_8_0;
 results[k++] = -0.202696400731455016e0 * wr_8_0 + 0.451994794216174692e0 * wr_6_0 
             + 0.383757552619123712e-1 * wr_4_0;
 results[k++] = 0.249737432852796338e0 * wr_4_0 - 0.747032632518461103e-1 * wr_6_0 
             - 0.259020304950474557e0 * wr_8_0;
 results[k++] = -0.784464540552736127e0 * wr_6_0;
 results[k++] = 0.163403097140530386e0 * wr_6_0 + 0.268685554869530165e0 * wr_8_0 
             - 0.291341989438914795e0 * wr_4_0;
 results[k++] = -0.175523082489666199e0 * wr_4_0 - 0.210952491314662323e0 * wr_6_0 
             - 0.567608006932466977e-1 * wr_8_0;
 results[k++] = 0.333098259875850929e0 * wr_4_0 + 0.703754940127593694e-1 * wr_8_0 
             - 0.597832532640104377e0 * wr_6_0;
 results[k++] = -0.317216790365359068e0 * wr_8_0 + 0.157650870482974697e0 * wr_4_0 
             + 0.189472765715965866e0 * wr_6_0;
 results[k++] = 0.701020783207575107e0 * wr_8_0;
 results[k++] = -0.288299559224379299e0 * wr_8_0 - 0.459201542919776321e0 * wr_6_0 
             - 0.181942275688948498e0 * wr_4_0;
 results[k++] = 0.140931880742875222e0 * wr_4_0 + 0.223315878318991978e0 * wr_8_0 
             + 0.355695985656208811e0 * wr_6_0;
 results[k++] = 0.236257244717996057e0 * wr_6_0 + 0.565062474333599796e-1 * wr_8_0 
             + 0.936085285747888496e-1 * wr_4_0;
 results[k++] = 0.238782477185232532e-2 * wr_8_0 + 0.745448911513042675e0 * wr_6_0 
             + 0.295357612494405879e0 * wr_4_0;
 results[k++] = 0.217571317288168469e0 * wr_6_0;
 results[k++] = -0.239418457348762471e-1 * wr_4_0 + 0.271919190142987142e0 * wr_6_0 
             - 0.178847916010815538e0 * wr_8_0;
 results[k++] = -0.259633835464199783e0 * wr_4_0 - 0.138535000042758284e0 * wr_8_0 
             + 0.631883096962798318e0 * wr_6_0;
 results[k++] = 0.585559505074875889e-1 * wr_8_0 - 0.487063677774022025e0 * wr_6_0 
             + 0.597421933373181229e0 * wr_4_0;
 results[k++] = -0.179756213627967617e0 * wr_4_0 + 0.761979207334377701e-1 * wr_6_0 
             + 0.725835890429108441e-1 * wr_8_0;
 results[k++] = wr_0_0 + 0.272727272727272727e0 * wr_4_0 + 0.112060645702066489e0 * wr_6_0;
 results[k++] = 0.310513659574533285e0 * wr_4_0 + 0.688967951586430433e0 * wr_6_0;
 results[k++] = -0.317690641239073686e0 * wr_8_0 - 0.123832443601787396e0 * wr_4_0 
             - 0.476249839970396868e0 * wr_6_0;
 results[k++] = -0.272109543117047186e0 * wr_4_0 + 0.626118233322953853e0 * wr_6_0;
 results[k++] = -0.349370517392917382e0 * wr_6_0 + 0.201065858219406536e0 * wr_8_0 
             + 0.519096146124538648e-1 * wr_4_0;
 results[k++] = 0.972522371140021489e-2 * wr_4_0 + 0.331475965684300118e0 * wr_10_0 
             + 0.721922203816710988e-1 * wr_6_0 + 0.141936602023101341e0 * wr_8_0;
 results[k++] = 0.880510034277622916e-1 * wr_8_0 - 0.427490943867267122e-1 * wr_6_0 
             + 0.127974548495574132e-2 * wr_4_0 + 0.915999728533728234e0 * wr_10_0;
 results[k++] = 0.310513659574533285e0 * wr_4_0 + 0.688967951586430433e0 * wr_6_0;
 results[k++] = wr_0_0 + 0.489510489510489510e-1 * wr_4_0 + 0.403418324527439361e-1 * wr_6_0 
             + 0.303932755290285796e0 * wr_8_0;
 results[k++] = -0.205441754265445047e0 * wr_4_0 - 0.406675721872732860e0 * wr_6_0 
             + 0.136779847041299248e0 * wr_8_0;
 results[k++] = -0.192474081315897375e0 * wr_6_0 + 0.335684613918240416e0 * wr_4_0 
             - 0.155366493660765755e0 * wr_8_0;
 results[k++] = 0.248227123766417456e0 * wr_4_0 + 0.637534195974890819e0 * wr_10_0 
             - 0.280782940455141645e0 * wr_6_0 - 0.295738557400431363e-1 * wr_8_0;
 results[k++] = -0.290883474563664192e0 * wr_8_0 - 0.199307777117321761e-1 * wr_4_0 
             - 0.679323580093187331e0 * wr_10_0 - 0.147950025587257759e0 * wr_6_0;
 results[k++] = 0.421421409465682357e0 * wr_10_0 + 0.367177691364415996e-1 * wr_4_0 
             + 0.180450859403524009e0 * wr_8_0 - 0.262828719282089072e0 * wr_6_0;
 results[k++] = -0.317690641239073686e0 * wr_8_0 - 0.123832443601787396e0 * wr_4_0 
             - 0.476249839970396868e0 * wr_6_0;
 results[k++] = -0.205441754265445047e0 * wr_4_0 - 0.406675721872732860e0 * wr_6_0 
             + 0.136779847041299248e0 * wr_8_0;
 results[k++] = wr_0_0 + 0.918900104420466411e-1 * wr_4_0 - 0.322652336656250743e0 * wr_6_0 
             - 0.137096364447965454e0 * wr_8_0 + 0.236442553413908741e0 * wr_10_0;
 results[k++] = -0.141202242349351882e-1 * wr_4_0 + 0.260295949890258571e0 * wr_6_0 
             - 0.142293514043344803e0 * wr_8_0 + 0.555318247625187705e0 * wr_10_0;
 results[k++] = -0.547044763274834157e0 * wr_10_0 + 0.306405834205290441e0 * wr_4_0 
             - 0.372008728593751229e0 * wr_6_0 - 0.238501196409070238e-1 * wr_8_0;
 results[k++] = -0.406370040376896169e0 * wr_10_0 - 0.344429289992425524e-1 * wr_4_0 
             - 0.191498586354504430e0 * wr_8_0 - 0.255676537084571254e0 * wr_6_0;
 results[k++] = 0.527098140933545386e0 * wr_6_0 - 0.219819300089976987e0 * wr_4_0 
             - 0.280103850030031864e-1 * wr_10_0 - 0.198444990672094758e0 * wr_8_0;
 results[k++] = -0.272109543117047186e0 * wr_4_0 + 0.626118233322953853e0 * wr_6_0;
 results[k++] = -0.192474081315897375e0 * wr_6_0 + 0.335684613918240416e0 * wr_4_0 
             - 0.155366493660765755e0 * wr_8_0;
 results[k++] = -0.141202242349351882e-1 * wr_4_0 + 0.260295949890258571e0 * wr_6_0 
             - 0.142293514043344803e0 * wr_8_0 + 0.555318247625187705e0 * wr_10_0;
 results[k++] = wr_0_0 - 0.918900104420466411e-1 * wr_4_0 - 0.430203115541667658e-1 * wr_6_0 
             - 0.181833072846775233e0 * wr_8_0 - 0.447996416994774456e0 * wr_10_0;
 results[k++] = 0.145017708893255327e0 * wr_4_0 + 0.107504160481582566e0 * wr_8_0 
             - 0.597481931900448302e0 * wr_10_0 + 0.117901784912683056e0 * wr_6_0;
 results[k++] = -0.809229225160028332e-2 * wr_8_0 - 0.108675795159015656e0 * wr_4_0 
             + 0.188258942798416539e0 * wr_10_0 - 0.806721489098107328e0 * wr_6_0;
 results[k++] = -0.824610501549883232e-1 * wr_6_0 + 0.475040127641564309e0 * wr_10_0 
             - 0.245984388020919782e0 * wr_8_0 + 0.661406668540268826e-1 * wr_4_0;
 results[k++] = -0.349370517392917382e0 * wr_6_0 + 0.201065858219406536e0 * wr_8_0 
             + 0.519096146124538648e-1 * wr_4_0;
 results[k++] = 0.248227123766417456e0 * wr_4_0 + 0.637534195974890819e0 * wr_10_0 
             - 0.280782940455141645e0 * wr_6_0 - 0.295738557400431363e-1 * wr_8_0;
 results[k++] = -0.547044763274834157e0 * wr_10_0 + 0.306405834205290441e0 * wr_4_0 
             - 0.372008728593751229e0 * wr_6_0 - 0.238501196409070238e-1 * wr_8_0;
 results[k++] = 0.145017708893255327e0 * wr_4_0 + 0.107504160481582566e0 * wr_8_0 
             - 0.597481931900448302e0 * wr_10_0 + 0.117901784912683056e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.191808191808191808e0 * wr_4_0 + 0.118652448390423341e-1 * wr_6_0 
             - 0.792681763092615683e-1 * wr_8_0 - 0.243214986021539496e0 * wr_10_0;
 results[k++] = -0.750243561673582737e0 * wr_6_0 - 0.101067489498712417e0 * wr_4_0 
             + 0.946373429757965071e-1 * wr_10_0 - 0.401373724339093911e-1 * wr_8_0;
 results[k++] = -0.179543320256717518e0 * wr_4_0 - 0.273973920956622919e0 * wr_10_0 
             + 0.392165515528214555e0 * wr_8_0 - 0.658165364047716989e-1 * wr_6_0;
 results[k++] = 0.972522371140021489e-2 * wr_4_0 + 0.331475965684300118e0 * wr_10_0 
             + 0.721922203816710988e-1 * wr_6_0 + 0.141936602023101341e0 * wr_8_0;
 results[k++] = -0.290883474563664192e0 * wr_8_0 - 0.199307777117321761e-1 * wr_4_0 
             - 0.679323580093187331e0 * wr_10_0 - 0.147950025587257759e0 * wr_6_0;
 results[k++] = -0.406370040376896169e0 * wr_10_0 - 0.344429289992425524e-1 * wr_4_0 
             - 0.191498586354504430e0 * wr_8_0 - 0.255676537084571254e0 * wr_6_0;
 results[k++] = -0.809229225160028332e-2 * wr_8_0 - 0.108675795159015656e0 * wr_4_0 
             + 0.188258942798416539e0 * wr_10_0 - 0.806721489098107328e0 * wr_6_0;
 results[k++] = -0.750243561673582737e0 * wr_6_0 - 0.101067489498712417e0 * wr_4_0 
             + 0.946373429757965071e-1 * wr_10_0 - 0.401373724339093911e-1 * wr_8_0;
 results[k++] = wr_0_0 + 0.497041420118343195e0 * wr_4_0 + 0.100398225561127443e0 * wr_6_0 
             + 0.105745834646797310e0 * wr_8_0 + 0.104769532440047783e0 * wr_10_0;
 results[k++] = -0.262476763594543158e-1 * wr_10_0 + 0.280310781284635307e-1 * wr_4_0 
             + 0.208080125438525565e0 * wr_6_0 + 0.111321041825273207e-1 * wr_8_0;
 results[k++] = 0.880510034277622916e-1 * wr_8_0 - 0.427490943867267122e-1 * wr_6_0 
             + 0.127974548495574132e-2 * wr_4_0 + 0.915999728533728234e0 * wr_10_0;
 results[k++] = 0.421421409465682357e0 * wr_10_0 + 0.367177691364415996e-1 * wr_4_0 
             + 0.180450859403524009e0 * wr_8_0 - 0.262828719282089072e0 * wr_6_0;
 results[k++] = 0.527098140933545386e0 * wr_6_0 - 0.219819300089976987e0 * wr_4_0 
             - 0.280103850030031864e-1 * wr_10_0 - 0.198444990672094758e0 * wr_8_0;
 results[k++] = -0.824610501549883232e-1 * wr_6_0 + 0.475040127641564309e0 * wr_10_0 
             - 0.245984388020919782e0 * wr_8_0 + 0.661406668540268826e-1 * wr_4_0;
 results[k++] = -0.179543320256717518e0 * wr_4_0 - 0.273973920956622919e0 * wr_10_0 
             + 0.392165515528214555e0 * wr_8_0 - 0.658165364047716989e-1 * wr_6_0;
 results[k++] = -0.262476763594543158e-1 * wr_10_0 + 0.280310781284635307e-1 * wr_4_0 
             + 0.208080125438525565e0 * wr_6_0 + 0.111321041825273207e-1 * wr_8_0;
 results[k++] = wr_0_0 - 0.473065396142319219e0 * wr_4_0 - 0.730168913171835949e-1 * wr_6_0 
             + 0.208470359732257555e0 * wr_8_0 - 0.690788125978337028e-1 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_T2g(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=0)
 if (lmax>=0){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,4,0,1));
    }
#endif
#if (AR_LMAX>=2)
 if (lmax>=2){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,4,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,4,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,4,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,6,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,6,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,8,2,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,2,1));
    }
#endif
#if (AR_LMAX>=4)
 if (lmax>=4){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,12,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,4,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,6,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,8,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,10,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,12,4,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,12,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,4,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,12,4,2));
    }
#endif
#if (AR_LMAX>=6)
 if (lmax>=6){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,0,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,2,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,2,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,2,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,4,2,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,8,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,10,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,12,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,12,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,14,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,14,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,16,6,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,6,2,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,6,2,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,1,16,6,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(16,6,2,16,6,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_T2g(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=0)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=2)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 results[k++] = wr_0_0 - 0.163265306122448980e0 * wr_4_0;
 results[k++] = 0.539949247156038895e0 * wr_4_0;
 results[k++] = 0.353479756646709650e0 * wr_4_0;
 results[k++] = 0.539949247156038895e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.142857142857142857e0 * wr_4_0;
 results[k++] = 0.467609764791412244e0 * wr_4_0;
 results[k++] = 0.353479756646709650e0 * wr_4_0;
 results[k++] = 0.467609764791412244e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.265306122448979592e0 * wr_4_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=4)
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 results[k++] = -0.356348322549899180e0 * wr_4_0;
 results[k++] = 0.666666666666666667e0 * wr_4_0;
 results[k++] = 0.394771016975861392e0 * wr_4_0;
 results[k++] = 0.712696645099798359e0 * wr_4_0;
 results[k++] = 0.425917709999959942e0 * wr_4_0;
 results[k++] = 0.545591956855000841e0 * wr_4_0;
 results[k++] = 0.304226935714257102e0 * wr_4_0;
 results[k++] = 0.402454407013579323e0 * wr_4_0;
 results[k++] = -0.718549785938296268e-1 * wr_4_0 + 0.130202704370805979e1 * wr_6_0;
 results[k++] = -0.569156480635425544e-1 * wr_4_0;
 results[k++] = 0.109516109443060756e0 * wr_4_0 - 0.717592924887569358e0 * wr_6_0;
 results[k++] = -0.268856711432086060e0 * wr_4_0 + 0.852554343527197385e0 * wr_6_0;
 results[k++] = 0.199153927828979888e0 * wr_4_0 + 0.666223436239046501e0 * wr_6_0;
 results[k++] = 0.291828054825518616e0 * wr_4_0 + 0.771164419327493608e0 * wr_6_0;
 results[k++] = 0.413933665832038223e0 * wr_4_0 - 0.360604012737235290e0 * wr_6_0;
 results[k++] = 0.387197918181781766e0 * wr_4_0 - 0.676553097759318853e0 * wr_6_0;
 results[k++] = 0.894995622700763991e0 * wr_6_0 + 0.512214699835464593e-1 * wr_4_0;
 results[k++] = 0.325506760927014946e0 * wr_6_0 + 0.100596970031361477e0 * wr_4_0;
 results[k++] = -0.185116011714233340e0 * wr_4_0 + 0.121295342726362012e1 * wr_6_0;
 results[k++] = 0.306106831682488106e0 * wr_4_0 - 0.534862186740501905e0 * wr_6_0;
 results[k++] = 0.120236376593837852e0 * wr_4_0 - 0.389054993191739014e-1 * wr_6_0;
 results[k++] = -0.237129860311212055e0 * wr_4_0 - 0.545182022556967198e0 * wr_6_0;
 results[k++] = -0.387989105580457481e0 * wr_4_0 - 0.432724815284682349e0 * wr_6_0;
 results[k++] = -0.243190045687932180e0 * wr_4_0 - 0.325253020396629957e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.122448979591836735e0 * wr_4_0;
 results[k++] = -0.458162128992727518e0 * wr_4_0;
 results[k++] = 0.221975749966440475e0 * wr_4_0 - 0.744860445817002406e0 * wr_6_0;
 results[k++] = -0.155844155844155844e0 * wr_4_0 - 0.504272905659299201e0 * wr_6_0;
 results[k++] = 0.143284148971156081e-1 * wr_4_0 - 0.361632842253706839e0 * wr_6_0 
             - 0.756810675909955972e-1 * wr_8_0;
 results[k++] = 0.183544091706080628e-1 * wr_4_0 + 0.162541875006426982e0 * wr_6_0 
             - 0.561265818970126154e0 * wr_8_0;
 results[k++] = -0.458162128992727518e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.389610389610389610e-1 * wr_4_0 + 0.680768422640053921e0 * wr_6_0;
 results[k++] = 0.346065501894423948e0 * wr_4_0 + 0.243863601555605340e0 * wr_6_0;
 results[k++] = 0.224275168038398085e0 * wr_4_0 + 0.566044932723022720e0 * wr_6_0 
             + 0.355378824660767050e0 * wr_8_0;
 results[k++] = 0.451035398506212569e0 * wr_6_0 + 0.353965781988483265e0 * wr_8_0 
             - 0.670150243006929979e-1 * wr_4_0;
 results[k++] = 0.849412579130163253e-1 * wr_4_0 + 0.364905604366730518e0 * wr_6_0 
             + 0.420012879498659656e0 * wr_8_0;
 results[k++] = 0.221975749966440475e0 * wr_4_0 - 0.744860445817002406e0 * wr_6_0;
 results[k++] = 0.346065501894423948e0 * wr_4_0 + 0.243863601555605340e0 * wr_6_0;
 results[k++] = wr_0_0 + 0.104739416427728116e0 * wr_4_0 - 0.259012901543185499e0 * wr_6_0;
 results[k++] = 0.491026410080560683e0 * wr_8_0 + 0.372430222908501201e-1 * wr_6_0 
             + 0.796836025520555551e-1 * wr_4_0;
 results[k++] = -0.714300910987859260e-1 * wr_4_0 + 0.890278514802052253e-1 * wr_6_0 
             + 0.377285665671673866e0 * wr_8_0;
 results[k++] = 0.144474472783614972e0 * wr_4_0 + 0.744279808769568593e0 * wr_6_0 
             - 0.248713367373968694e0 * wr_8_0;
 results[k++] = -0.155844155844155844e0 * wr_4_0 - 0.504272905659299201e0 * wr_6_0;
 results[k++] = 0.224275168038398085e0 * wr_4_0 + 0.566044932723022720e0 * wr_6_0 
             + 0.355378824660767050e0 * wr_8_0;
 results[k++] = 0.491026410080560683e0 * wr_8_0 + 0.372430222908501201e-1 * wr_6_0 
             + 0.796836025520555551e-1 * wr_4_0;
 results[k++] = wr_0_0 + 0.419580419580419580e-1 * wr_4_0 + 0.605127486791159041e0 * wr_6_0 
             + 0.189957972056428623e0 * wr_8_0;
 results[k++] = 0.378405337954977986e-1 * wr_8_0 + 0.551643973538950912e0 * wr_4_0;
 results[k++] = 0.796455187531492208e0 * wr_6_0 + 0.173482162227129902e0 * wr_8_0 
             + 0.676215074706612838e-1 * wr_4_0;
 results[k++] = 0.143284148971156081e-1 * wr_4_0 - 0.361632842253706839e0 * wr_6_0 
             - 0.756810675909955972e-1 * wr_8_0;
 results[k++] = 0.451035398506212569e0 * wr_6_0 + 0.353965781988483265e0 * wr_8_0 
             - 0.670150243006929979e-1 * wr_4_0;
 results[k++] = -0.714300910987859260e-1 * wr_4_0 + 0.890278514802052253e-1 * wr_6_0 
             + 0.377285665671673866e0 * wr_8_0;
 results[k++] = 0.378405337954977986e-1 * wr_8_0 + 0.551643973538950912e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.191808191808191808e0 * wr_4_0 + 0.403418324527439361e0 * wr_6_0 
             - 0.104024603745187103e0 * wr_8_0;
 results[k++] = 0.161646320670507593e0 * wr_4_0 + 0.407976868367326769e0 * wr_6_0 
             + 0.182956626620343659e-1 * wr_8_0;
 results[k++] = 0.183544091706080628e-1 * wr_4_0 + 0.162541875006426982e0 * wr_6_0 
             - 0.561265818970126154e0 * wr_8_0;
 results[k++] = 0.849412579130163253e-1 * wr_4_0 + 0.364905604366730518e0 * wr_6_0 
             + 0.420012879498659656e0 * wr_8_0;
 results[k++] = 0.144474472783614972e0 * wr_4_0 + 0.744279808769568593e0 * wr_6_0 
             - 0.248713367373968694e0 * wr_8_0;
 results[k++] = 0.796455187531492208e0 * wr_6_0 + 0.173482162227129902e0 * wr_8_0 
             + 0.676215074706612838e-1 * wr_4_0;
 results[k++] = 0.161646320670507593e0 * wr_4_0 + 0.407976868367326769e0 * wr_6_0 
             + 0.182956626620343659e-1 * wr_8_0;
 results[k++] = wr_0_0 + 0.344382889837435292e0 * wr_4_0 - 0.220046358833148742e0 * wr_6_0 
             + 0.904561771697279157e-2 * wr_8_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=6)
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 cmplx wr_12_0=wzeta.eval_wr_lm(12,0);
 cmplx wr_12_4=wzeta.eval_wr_lm(12,4);
 results[k++] = 0.115873091900464219e1 * wr_6_0;
 results[k++] = -0.784464540552736127e0 * wr_6_0;
 results[k++] = 0.143427433120127238e1 * wr_6_0;
 results[k++] = -0.644658371220304240e0 * wr_6_0;
 results[k++] = 0.117669681082910419e1 * wr_6_0;
 results[k++] = -0.147804444608928612e1 * wr_6_0;
 results[k++] = 0.226977375975403368e0 * wr_4_0 - 0.881330764945706980e0 * wr_6_0;
 results[k++] = -0.150131422517230992e0 * wr_4_0 + 0.582945506709165690e0 * wr_6_0;
 results[k++] = -0.327613622798385077e-1 * wr_4_0 + 0.127209138596625679e0 * wr_6_0;
 results[k++] = 0.614657639802557511e0 * wr_4_0 - 0.426188391762268567e-1 * wr_6_0;
 results[k++] = 0.218915746048930460e0 * wr_4_0 + 0.676553097759318853e0 * wr_6_0 
             + 0.333739165874855650e0 * wr_8_0;
 results[k++] = -0.204734281038153814e-1 * wr_4_0 - 0.295271979251327329e0 * wr_6_0 
             + 0.509794996664316331e0 * wr_8_0;
 results[k++] = 0.360194932613785144e0 * wr_4_0 + 0.794805194805194805e0 * wr_6_0 
             - 0.410010083959657122e-1 * wr_8_0;
 results[k++] = 0.338995224120614280e0 * wr_8_0 + 0.340352219714908537e0 * wr_4_0 
             - 0.274883253097619801e0 * wr_6_0;
 results[k++] = -0.623875923915923895e-1 * wr_4_0 + 0.899766653282533658e-1 * wr_6_0 
             + 0.399464042081460355e0 * wr_8_0;
 results[k++] = 0.461402410653524322e0 * wr_4_0 - 0.357238368681821781e0 * wr_6_0 
             - 0.304071616435557489e0 * wr_8_0;
 results[k++] = -0.431394989075198917e0 * wr_4_0 - 0.222391501718236601e0 * wr_6_0 
             + 0.402248938920952769e0 * wr_8_0;
 results[k++] = 0.126185118629473193e0 * wr_4_0 + 0.752211966826198817e0 * wr_6_0 
             - 0.263333744402990624e0 * wr_8_0;
 results[k++] = 0.594231387042316592e0 * wr_8_0;
 results[k++] = 0.534255422861975530e0 * wr_4_0 - 0.134839972492648417e0 * wr_6_0 
             + 0.374906481627931678e0 * wr_8_0;
 results[k++] = -0.395861136080545592e-1 * wr_8_0 + 0.102985730108887445e1 * wr_6_0 
             + 0.408044319284273946e0 * wr_4_0;
 results[k++] = 0.562568677126194508e0 * wr_6_0 - 0.218645349784210071e0 * wr_8_0;
 results[k++] = -0.357413462937029322e0 * wr_4_0 - 0.281897124066382855e0 * wr_6_0 
             + 0.222492777249903767e0 * wr_8_0;
 results[k++] = 0.341223801730256357e0 * wr_4_0 - 0.356786974928687189e0 * wr_6_0 
             - 0.291311426665323618e0 * wr_8_0;
 results[k++] = 0.323173737085556338e0 * wr_8_0;
 results[k++] = 0.256511201578726195e0 * wr_8_0 + 0.806662398622938590e0 * wr_6_0;
 results[k++] = 0.665746763475353301e0 * wr_4_0 - 0.784125470113630411e0 * wr_6_0 
             - 0.101903811778436877e0 * wr_8_0;
 results[k++] = 0.706640403133488638e0 * wr_6_0 - 0.812314318567325451e-1 * wr_8_0;
 results[k++] = -0.296238608404484957e0 * wr_6_0 + 0.153512976667574344e0 * wr_8_0;
 results[k++] = 0.141260176157364717e0 * wr_4_0 - 0.268372887459054695e0 * wr_6_0;
 results[k++] = -0.253768421017764782e0 * wr_4_0 + 0.262762066810731941e0 * wr_6_0;
 results[k++] = 0.474757243515539558e0 * wr_4_0 - 0.491582814123181535e0 * wr_6_0;
 results[k++] = 0.281130599758929343e0 * wr_4_0 - 0.291093971188896320e0 * wr_6_0;
 results[k++] = -0.195206477705972909e-1 * wr_4_0 - 0.229916808459390448e0 * wr_6_0 
             + 0.371181076639423639e0 * wr_8_0;
 results[k++] = 0.466632733763150632e-2 * wr_4_0 - 0.161648910139717293e-1 * wr_6_0 
             - 0.210148219915096406e0 * wr_8_0 + 0.107663120908033190e1 * wr_10_0;
 results[k++] = -0.943811174771888452e-2 * wr_4_0 - 0.135139754499577668e0 * wr_6_0 
             + 0.138533414275571967e0 * wr_8_0 + 0.362932306542796900e0 * wr_10_0;
 results[k++] = 0.458138755162699669e0 * wr_4_0 + 0.457433383296837074e0 * wr_6_0;
 results[k++] = -0.115378728864937825e0 * wr_4_0 + 0.427889749392401524e0 * wr_6_0 
             - 0.259046813921551811e0 * wr_8_0;
 results[k++] = 0.878429149676878090e-1 * wr_4_0 + 0.182995010814616887e0 * wr_6_0 
             + 0.225359939388221496e0 * wr_8_0;
 results[k++] = -0.123345049466880680e0 * wr_4_0 + 0.753419690135966946e0 * wr_6_0 
             + 0.102027834192613579e0 * wr_8_0 - 0.296993708370943474e0 * wr_10_0;
 results[k++] = -0.541984828335278339e-1 * wr_8_0 - 0.926674772210514091e-1 * wr_4_0 
             + 0.442535970039793151e0 * wr_10_0;
 results[k++] = -0.113593455267724507e-1 * wr_4_0 - 0.772219903881064842e0 * wr_10_0 
             - 0.371862768814524684e0 * wr_6_0 - 0.248476145770149797e0 * wr_8_0;
 results[k++] = -0.107389380596717278e0 * wr_4_0 + 0.836347503272648615e0 * wr_6_0 
             + 0.375058807852168420e-1 * wr_8_0;
 results[k++] = 0.265484427844983197e0 * wr_4_0 + 0.146181412382780656e0 * wr_8_0 
             - 0.325971438909380084e0 * wr_6_0;
 results[k++] = 0.511564424254982137e-1 * wr_4_0 + 0.466795179255256024e-1 * wr_6_0 
             + 0.276088105315000789e0 * wr_8_0 + 0.731968472539147439e0 * wr_10_0;
 results[k++] = -0.115149633989700830e-1 * wr_8_0 + 0.451299909339923453e0 * wr_10_0 
             + 0.543390265819389428e0 * wr_4_0;
 results[k++] = 0.821471104178536373e-1 * wr_4_0 - 0.480212712741040607e0 * wr_6_0 
             + 0.379859177840893756e0 * wr_8_0 + 0.360565884380410853e-1 * wr_10_0;
 results[k++] = -0.692294631818371046e-1 * wr_4_0 - 0.485639017324664937e0 * wr_6_0 
             - 0.668089579449732484e-1 * wr_8_0 + 0.342275605278760026e0 * wr_10_0;
 results[k++] = -0.137563620693807139e0 * wr_4_0 - 0.375910247785263736e0 * wr_6_0 
             + 0.278151056336515438e0 * wr_8_0;
 results[k++] = -0.336500381709733953e0 * wr_4_0 - 0.263723879135579007e0 * wr_6_0 
             + 0.173457659096749617e0 * wr_8_0;
 results[k++] = -0.103468999342138974e0 * wr_4_0 + 0.390244424608973579e0 * wr_6_0 
             - 0.182002150128197060e0 * wr_8_0 + 0.246746521756661297e0 * wr_10_0;
 results[k++] = -0.787512871734858860e0 * wr_10_0 + 0.541753004161115387e0 * wr_6_0 
             + 0.666097531780539833e-1 * wr_4_0 - 0.527910298310132968e-1 * wr_8_0;
 results[k++] = -0.692294631818371046e-1 * wr_4_0 - 0.485639017324664937e0 * wr_6_0 
             - 0.668089579449732484e-1 * wr_8_0 + 0.342275605278760026e0 * wr_10_0;
 results[k++] = -0.147491402795691757e0 * wr_4_0 + 0.261934206949658513e0 * wr_6_0 
             - 0.330312328557298918e-1 * wr_8_0 - 0.865358122512986047e-1 * wr_10_0;
 results[k++] = 0.442913925263535866e0 * wr_8_0;
 results[k++] = -0.135157119083218884e0 * wr_4_0 - 0.313530465228838874e0 * wr_6_0 
             - 0.310067373885171762e0 * wr_10_0 + 0.207992700263918470e0 * wr_8_0;
 results[k++] = 0.373492793464069453e0 * wr_4_0 + 0.675799163737718043e0 * wr_6_0 
             + 0.715147169284532397e-2 * wr_8_0 + 0.224410289619420490e0 * wr_10_0;
 results[k++] = 0.497213948526450176e0 * wr_10_0 + 0.170710144474042973e0 * wr_8_0 
             + 0.469249432480862142e-1 * wr_6_0 - 0.632139541241013967e-1 * wr_4_0;
 results[k++] = 0.300055365557329128e-1 * wr_8_0 - 0.707481352665395037e-1 * wr_10_0 
             + 0.560860346615054304e0 * wr_6_0 + 0.755551264782778703e-1 * wr_4_0;
 results[k++] = -0.605011149678329433e0 * wr_6_0 - 0.377771193884555698e0 * wr_10_0 
             - 0.815028094080764807e-1 * wr_4_0 - 0.216458096223416762e0 * wr_8_0;
 results[k++] = -0.314485451016575488e0 * wr_6_0 - 0.162968621693904230e0 * wr_8_0;
 results[k++] = 0.904192487431349483e-1 * wr_4_0 - 0.655468366103556254e0 * wr_6_0 
             + 0.123435778780033351e0 * wr_8_0 + 0.674157546335926017e0 * wr_10_0;
 results[k++] = -0.487919410309805675e0 * wr_10_0 + 0.312330364329556653e0 * wr_4_0 
             - 0.234125969718701017e0 * wr_6_0 + 0.526271773538173152e-1 * wr_8_0;
 results[k++] = -0.784812177224965568e-2 * wr_6_0 + 0.185017574200321020e0 * wr_4_0 
             + 0.522708926732860515e0 * wr_10_0 - 0.820841217475553695e-1 * wr_8_0;
 results[k++] = -0.487775582930112505e0 * wr_6_0 + 0.280276413541900882e0 * wr_8_0 
             - 0.107410030415309588e0 * wr_4_0 + 0.182220693545797180e0 * wr_10_0;
 results[k++] = -0.737118999159198258e-1 * wr_10_0 - 0.297237247181677893e0 * wr_6_0 
             + 0.595476602063539821e-1 * wr_8_0 + 0.437902770057077976e0 * wr_4_0;
 results[k++] = -0.114100807052518223e0 * wr_8_0 + 0.972906007548989412e0 * wr_10_0;
 results[k++] = -0.225078571982043419e0 * wr_6_0 + 0.709319449773780408e0 * wr_10_0 
             - 0.256155676526953819e0 * wr_8_0;
 results[k++] = 0.276143131607486907e0 * wr_8_0 - 0.101562341261613325e0 * wr_4_0 
             - 0.681555096428038320e-1 * wr_10_0 + 0.593709591992791261e0 * wr_6_0;
 results[k++] = 0.103137045109261261e0 * wr_4_0 - 0.130197715716114760e0 * wr_10_0 
             - 0.765606274055584578e-1 * wr_6_0 + 0.147453350652485087e0 * wr_8_0;
 results[k++] = 0.183014904447428603e0 * wr_6_0 - 0.881202316210332277e-1 * wr_8_0 
             + 0.205453911661334936e0 * wr_4_0 - 0.521570226171817630e-1 * wr_10_0;
 results[k++] = -0.851552621894191488e-1 * wr_8_0 - 0.221627198375371364e0 * wr_4_0 
             - 0.197421797451487611e0 * wr_6_0 + 0.288231618647509437e-1 * wr_10_0;
 results[k++] = -0.697101166347501177e-1 * wr_6_0 + 0.286798426644151468e-1 * wr_8_0 
             + 0.637517259380993559e0 * wr_10_0;
 results[k++] = 0.826578294209004252e-1 * wr_6_0 - 0.153300207366890530e0 * wr_8_0 
             - 0.655977069758662664e0 * wr_10_0;
 results[k++] = -0.215498069306063117e-1 * wr_4_0 + 0.203201609421197308e0 * wr_6_0 
             - 0.492025396388798380e0 * wr_10_0;
 results[k++] = -0.276915913699067782e0 * wr_4_0 + 0.801450268936106187e-1 * wr_10_0 
             - 0.303344489719775590e0 * wr_8_0 + 0.693530865879652260e0 * wr_6_0;
 results[k++] = -0.122042219689260656e0 * wr_10_0 + 0.250918725469868216e0 * wr_6_0 
             + 0.194047727072586178e0 * wr_8_0 - 0.504011820787182295e0 * wr_4_0;
 results[k++] = -0.400169207884619256e0 * wr_4_0 + 0.429972149261477754e0 * wr_6_0 
             - 0.135109735584243355e0 * wr_8_0 + 0.294969076765086392e-1 * wr_10_0;
 results[k++] = 0.183371965694290619e0 * wr_6_0 + wr_0_0 - 0.462809917355371901e0 * wr_4_0;
 results[k++] = 0.372430222908501201e0 * wr_6_0 - 0.233822100038362230e0 * wr_8_0 
             + 0.826348470910205756e-1 * wr_4_0;
 results[k++] = 0.667580517574715786e-1 * wr_6_0 - 0.414987116973941810e0 * wr_10_0 
             - 0.503617579968975421e-1 * wr_4_0 + 0.337506486220826055e0 * wr_8_0;
 results[k++] = 0.558102539483696554e0 * wr_6_0 - 0.139892128593924461e0 * wr_10_0 
             + 0.101861670944746215e0 * wr_4_0 - 0.222490230444076745e0 * wr_8_0;
 results[k++] = -0.305640431363319904e0 * wr_6_0 - 0.411737103325307545e-1 * wr_4_0 
             + 0.169638233707704642e0 * wr_10_0 + 0.367908636810299336e-1 * wr_8_0;
 results[k++] = -0.368832405577437224e0 * wr_10_0 + 0.105887024160260146e0 * wr_6_0 
             + 0.270741378991787845e0 * wr_8_0 - 0.344311862879252399e-1 * wr_4_0;
 results[k++] = 0.470406597374931091e-1 * wr_10_0 - 0.612400752985009993e-1 * wr_6_0 
             - 0.676487085640731731e-1 * wr_8_0 - 0.261833025698146002e0 * wr_12_4 
             + 0.395159849334857088e-2 * wr_4_0 + 0.136549882215922423e0 * wr_12_0;
 results[k++] = 0.838462204997653676e-3 * wr_4_0 - 0.209598800988915260e-1 * wr_6_0 
             + 0.339593957627670833e0 * wr_10_0 - 0.643547563164011476e0 * wr_12_0 
             + 0.123399597941398771e1 * wr_12_4;
 results[k++] = 0.372430222908501201e0 * wr_6_0 - 0.233822100038362230e0 * wr_8_0 
             + 0.826348470910205756e-1 * wr_4_0;
 results[k++] = 0.177978672585635012e0 * wr_6_0 + 0.168379605707219651e0 * wr_10_0 
             + 0.132113627182102614e0 * wr_8_0 + wr_0_0 + 0.111888111888111888e0 * wr_4_0;
 results[k++] = 0.508990707876080746e0 * wr_4_0 + 0.255862998604164288e0 * wr_10_0 
             + 0.725374512135377895e-2 * wr_8_0;
 results[k++] = -0.446477831329873628e0 * wr_10_0 + 0.623929936809312489e-1 * wr_4_0 
             + 0.332552229494888910e-1 * wr_8_0 + 0.597226550430188181e0 * wr_6_0;
 results[k++] = 0.318715254695662513e0 * wr_12_0 + 0.517112788217227829e0 * wr_12_4 
             + 0.196100043159273155e0 * wr_10_0 + 0.261372063411064441e0 * wr_6_0 
             + 0.170794508276807725e0 * wr_8_0 + 0.372443920423326141e-1 * wr_4_0;
 results[k++] = 0.562160868644889337e0 * wr_12_4 + 0.206155204205013277e0 * wr_10_0 
             - 0.109008638420403126e0 * wr_4_0 - 0.293175393727284964e0 * wr_12_0 
             - 0.821246871672529758e-1 * wr_8_0 - 0.437140599333138628e-1 * wr_6_0;
 results[k++] = 0.543112655226265862e0 * wr_12_0 - 0.103188014741781606e-1 * wr_4_0 
             - 0.928868799546855294e-1 * wr_8_0 - 0.349897254637031940e0 * wr_12_4 
             + 0.203068050460334753e-1 * wr_6_0 + 0.231073564731557463e0 * wr_10_0;
 results[k++] = 0.277052763677126825e-1 * wr_4_0 - 0.142240568184722571e0 * wr_10_0 
             - 0.387873212687597702e0 * wr_12_4 - 0.183950897009007588e0 * wr_6_0 
             + 0.191089066995313212e0 * wr_8_0 + 0.202281745650613405e0 * wr_12_0;
 results[k++] = 0.667580517574715786e-1 * wr_6_0 - 0.414987116973941810e0 * wr_10_0 
             - 0.503617579968975421e-1 * wr_4_0 + 0.337506486220826055e0 * wr_8_0;
 results[k++] = 0.508990707876080746e0 * wr_4_0 + 0.255862998604164288e0 * wr_10_0 
             + 0.725374512135377895e-2 * wr_8_0;
 results[k++] = -0.121774881242802903e0 * wr_6_0 + 0.226597813063546114e-1 * wr_10_0 
             + 0.268720915152712119e0 * wr_8_0 + wr_0_0 - 0.977845683728036669e-1 * wr_4_0 
             + 0.221457113737943690e0 * wr_12_0 - 0.444221812937349289e0 * wr_12_4;
 results[k++] = -0.246118834053934663e0 * wr_12_0 + 0.215103277877895238e0 * wr_10_0 
             - 0.472621575748578409e-1 * wr_8_0 + 0.326721038384217759e0 * wr_12_4 
             - 0.123150912278063034e0 * wr_6_0 + 0.824079281849646552e-1 * wr_4_0;
 results[k++] = 0.749481163878861096e-1 * wr_4_0 + 0.592822686937221114e-1 * wr_10_0 
             + 0.464328057377407375e0 * wr_12_0 + 0.123917393607354545e-1 * wr_8_0 
             + 0.810396202178839275e-1 * wr_12_4 + 0.455122992228995841e0 * wr_6_0;
 results[k++] = 0.420313002504696803e0 * wr_12_0 - 0.910360005506315140e0 * wr_12_4 
             - 0.106547097940567142e0 * wr_4_0 - 0.152688916473073318e0 * wr_10_0 
             - 0.395816684454897716e0 * wr_6_0 + 0.115749047150745301e0 * wr_8_0;
 results[k++] = -0.123759701556904654e0 * wr_6_0 + 0.400223298763014715e0 * wr_12_4 
             - 0.524065614118965527e-1 * wr_4_0 + 0.236002372839935945e0 * wr_10_0 
             + 0.915531035262621905e-1 * wr_12_0 + 0.141524633191735821e0 * wr_8_0;
 results[k++] = -0.169678129073416517e0 * wr_6_0 + 0.229115586162066367e0 * wr_12_4 
             + 0.552221963372390010e0 * wr_10_0 + 0.128561808460209126e0 * wr_4_0 
             - 0.139717887037193823e0 * wr_12_0 - 0.311648447699754463e0 * wr_8_0;
 results[k++] = 0.558102539483696554e0 * wr_6_0 - 0.139892128593924461e0 * wr_10_0 
             + 0.101861670944746215e0 * wr_4_0 - 0.222490230444076745e0 * wr_8_0;
 results[k++] = -0.446477831329873628e0 * wr_10_0 + 0.623929936809312489e-1 * wr_4_0 
             + 0.332552229494888910e-1 * wr_8_0 + 0.597226550430188181e0 * wr_6_0;
 results[k++] = -0.246118834053934663e0 * wr_12_0 + 0.215103277877895238e0 * wr_10_0 
             - 0.472621575748578409e-1 * wr_8_0 + 0.326721038384217759e0 * wr_12_4 
             - 0.123150912278063034e0 * wr_6_0 + 0.824079281849646552e-1 * wr_4_0;
 results[k++] = 0.664226624960743108e-1 * wr_6_0 - 0.543834751352510676e-1 * wr_10_0 
             - 0.233670361002358364e-1 * wr_8_0 + wr_0_0 + 0.175567747760261129e0 * wr_4_0 
             - 0.351012716299334379e0 * wr_12_0 - 0.403838011761226624e0 * wr_12_4;
 results[k++] = -0.490950174023437108e0 * wr_6_0 - 0.893932460077635985e-1 * wr_8_0 
             - 0.461378273464197161e0 * wr_12_4 - 0.808480156169470004e-1 * wr_4_0 
             + 0.316547331406545964e0 * wr_10_0 + 0.274386377421386193e0 * wr_12_0;
 results[k++] = 0.434384658018557727e0 * wr_4_0 + 0.617657078914844939e-1 * wr_10_0 
             + 0.245920976433195161e-1 * wr_8_0 - 0.328118384555996632e0 * wr_12_0 
             - 0.241199981698980404e0 * wr_6_0 - 0.145191623560179220e0 * wr_12_4;
 results[k++] = -0.130420301073511142e0 * wr_10_0 + 0.440613085312052110e0 * wr_12_4 
             - 0.284885029871487382e0 * wr_12_0 + 0.133502038029051209e0 * wr_6_0 
             + 0.136762773134008343e0 * wr_8_0 + 0.565319943937153694e-1 * wr_4_0;
 results[k++] = -0.308939393357300475e0 * wr_12_4 - 0.133468895534756420e0 * wr_10_0 
             + 0.110820917910742200e-1 * wr_12_0 + 0.102073949327984457e0 * wr_4_0 
             - 0.290758968680974036e0 * wr_6_0 + 0.216991664881511980e0 * wr_8_0;
 results[k++] = -0.305640431363319904e0 * wr_6_0 - 0.411737103325307545e-1 * wr_4_0 
             + 0.169638233707704642e0 * wr_10_0 + 0.367908636810299336e-1 * wr_8_0;
 results[k++] = 0.318715254695662513e0 * wr_12_0 + 0.517112788217227829e0 * wr_12_4 
             + 0.196100043159273155e0 * wr_10_0 + 0.261372063411064441e0 * wr_6_0 
             + 0.170794508276807725e0 * wr_8_0 + 0.372443920423326141e-1 * wr_4_0;
 results[k++] = 0.749481163878861096e-1 * wr_4_0 + 0.592822686937221114e-1 * wr_10_0 
             + 0.464328057377407375e0 * wr_12_0 + 0.123917393607354545e-1 * wr_8_0 
             + 0.810396202178839275e-1 * wr_12_4 + 0.455122992228995841e0 * wr_6_0;
 results[k++] = -0.490950174023437108e0 * wr_6_0 - 0.893932460077635985e-1 * wr_8_0 
             - 0.461378273464197161e0 * wr_12_4 - 0.808480156169470004e-1 * wr_4_0 
             + 0.316547331406545964e0 * wr_10_0 + 0.274386377421386193e0 * wr_12_0;
 results[k++] = -0.313203912530724059e0 * wr_12_4 - 0.744179829817128851e-1 * wr_6_0 
             + 0.502644304444514959e0 * wr_10_0 + 0.364715225618545825e-1 * wr_8_0 + wr_0_0 
             + 0.284313725490196078e0 * wr_4_0 + 0.225275464877026325e0 * wr_12_0;
 results[k++] = -0.100514241698701518e-1 * wr_10_0 - 0.108905026421276850e0 * wr_6_0 
             - 0.573891575495062293e-1 * wr_4_0 - 0.221582986597936794e0 * wr_12_0 
             + 0.245796468165591409e0 * wr_12_4 + 0.609980386702884732e-1 * wr_8_0;
 results[k++] = 0.422741850706231173e0 * wr_4_0 - 0.690923696178065894e-1 * wr_12_0 
             + 0.126521883603382936e-1 * wr_10_0 - 0.404723449332992474e-1 * wr_6_0 
             + 0.120836985439225028e0 * wr_12_4 + 0.262264083498498586e0 * wr_8_0;
 results[k++] = -0.146602294427863773e-1 * wr_12_0 - 0.596286489292800441e-1 * wr_10_0 
             + 0.102566027986398968e-1 * wr_4_0 + 0.190742595560591210e0 * wr_6_0 
             + 0.377701303848913554e-1 * wr_8_0 + 0.201100642503586404e0 * wr_12_4;
 results[k++] = -0.368832405577437224e0 * wr_10_0 + 0.105887024160260146e0 * wr_6_0 
             + 0.270741378991787845e0 * wr_8_0 - 0.344311862879252399e-1 * wr_4_0;
 results[k++] = 0.562160868644889337e0 * wr_12_4 + 0.206155204205013277e0 * wr_10_0 
             - 0.109008638420403126e0 * wr_4_0 - 0.293175393727284964e0 * wr_12_0 
             - 0.821246871672529758e-1 * wr_8_0 - 0.437140599333138628e-1 * wr_6_0;
 results[k++] = 0.420313002504696803e0 * wr_12_0 - 0.910360005506315140e0 * wr_12_4 
             - 0.106547097940567142e0 * wr_4_0 - 0.152688916473073318e0 * wr_10_0 
             - 0.395816684454897716e0 * wr_6_0 + 0.115749047150745301e0 * wr_8_0;
 results[k++] = 0.434384658018557727e0 * wr_4_0 + 0.617657078914844939e-1 * wr_10_0 
             + 0.245920976433195161e-1 * wr_8_0 - 0.328118384555996632e0 * wr_12_0 
             - 0.241199981698980404e0 * wr_6_0 - 0.145191623560179220e0 * wr_12_4;
 results[k++] = -0.100514241698701518e-1 * wr_10_0 - 0.108905026421276850e0 * wr_6_0 
             - 0.573891575495062293e-1 * wr_4_0 - 0.221582986597936794e0 * wr_12_0 
             + 0.245796468165591409e0 * wr_12_4 + 0.609980386702884732e-1 * wr_8_0;
 results[k++] = 0.385100051793479268e-1 * wr_6_0 - 0.104227247075451262e0 * wr_10_0 
             + 0.143080588511891054e0 * wr_8_0 + wr_0_0 - 0.144864938982586041e0 * wr_4_0 
             - 0.227559948464511663e0 * wr_12_0 - 0.120463043281047715e0 * wr_12_4;
 results[k++] = 0.651509995226907330e0 * wr_6_0 - 0.236430225645482263e0 * wr_12_4 
             - 0.129009555492618791e0 * wr_8_0 + 0.115555884090694865e-1 * wr_12_0 
             + 0.147138465465133031e0 * wr_4_0 - 0.419508555018601346e0 * wr_10_0;
 results[k++] = -0.128111772245388490e0 * wr_12_0 + 0.159103389700320075e0 * wr_4_0 
             + 0.333376331682943525e0 * wr_10_0 - 0.127605577204446706e-1 * wr_6_0 
             - 0.304700203190708521e0 * wr_8_0 + 0.387873212687597702e-1 * wr_12_4;
 results[k++] = 0.470406597374931091e-1 * wr_10_0 - 0.612400752985009993e-1 * wr_6_0 
             - 0.676487085640731731e-1 * wr_8_0 - 0.261833025698146002e0 * wr_12_4 
             + 0.395159849334857088e-2 * wr_4_0 + 0.136549882215922423e0 * wr_12_0;
 results[k++] = 0.543112655226265862e0 * wr_12_0 - 0.103188014741781606e-1 * wr_4_0 
             - 0.928868799546855294e-1 * wr_8_0 - 0.349897254637031940e0 * wr_12_4 
             + 0.203068050460334753e-1 * wr_6_0 + 0.231073564731557463e0 * wr_10_0;
 results[k++] = -0.123759701556904654e0 * wr_6_0 + 0.400223298763014715e0 * wr_12_4 
             - 0.524065614118965527e-1 * wr_4_0 + 0.236002372839935945e0 * wr_10_0 
             + 0.915531035262621905e-1 * wr_12_0 + 0.141524633191735821e0 * wr_8_0;
 results[k++] = -0.130420301073511142e0 * wr_10_0 + 0.440613085312052110e0 * wr_12_4 
             - 0.284885029871487382e0 * wr_12_0 + 0.133502038029051209e0 * wr_6_0 
             + 0.136762773134008343e0 * wr_8_0 + 0.565319943937153694e-1 * wr_4_0;
 results[k++] = 0.422741850706231173e0 * wr_4_0 - 0.690923696178065894e-1 * wr_12_0 
             + 0.126521883603382936e-1 * wr_10_0 - 0.404723449332992474e-1 * wr_6_0 
             + 0.120836985439225028e0 * wr_12_4 + 0.262264083498498586e0 * wr_8_0;
 results[k++] = 0.651509995226907330e0 * wr_6_0 - 0.236430225645482263e0 * wr_12_4 
             - 0.129009555492618791e0 * wr_8_0 + 0.115555884090694865e-1 * wr_12_0 
             + 0.147138465465133031e0 * wr_4_0 - 0.419508555018601346e0 * wr_10_0;
 results[k++] = -0.546325351218272736e-1 * wr_12_4 + 0.833271781274109068e0 * wr_6_0 
             - 0.233725954445687817e0 * wr_8_0 - 0.781922030993926734e-1 * wr_10_0 + wr_0_0 
             - 0.484672742336371168e-1 * wr_4_0 - 0.124502567972107785e-1 * wr_12_0;
 results[k++] = -0.133843908348716764e0 * wr_10_0 - 0.287578883142279230e-1 * wr_8_0 
             + 0.410915658321484957e-1 * wr_12_0 + 0.281568276188341813e0 * wr_6_0 
             - 0.115920977143713031e-1 * wr_12_4 + 0.502026358025805145e-1 * wr_4_0;
 results[k++] = 0.838462204997653676e-3 * wr_4_0 - 0.209598800988915260e-1 * wr_6_0 
             + 0.339593957627670833e0 * wr_10_0 - 0.643547563164011476e0 * wr_12_0 
             + 0.123399597941398771e1 * wr_12_4;
 results[k++] = 0.277052763677126825e-1 * wr_4_0 - 0.142240568184722571e0 * wr_10_0 
             - 0.387873212687597702e0 * wr_12_4 - 0.183950897009007588e0 * wr_6_0 
             + 0.191089066995313212e0 * wr_8_0 + 0.202281745650613405e0 * wr_12_0;
 results[k++] = -0.169678129073416517e0 * wr_6_0 + 0.229115586162066367e0 * wr_12_4 
             + 0.552221963372390010e0 * wr_10_0 + 0.128561808460209126e0 * wr_4_0 
             - 0.139717887037193823e0 * wr_12_0 - 0.311648447699754463e0 * wr_8_0;
 results[k++] = -0.308939393357300475e0 * wr_12_4 - 0.133468895534756420e0 * wr_10_0 
             + 0.110820917910742200e-1 * wr_12_0 + 0.102073949327984457e0 * wr_4_0 
             - 0.290758968680974036e0 * wr_6_0 + 0.216991664881511980e0 * wr_8_0;
 results[k++] = -0.146602294427863773e-1 * wr_12_0 - 0.596286489292800441e-1 * wr_10_0 
             + 0.102566027986398968e-1 * wr_4_0 + 0.190742595560591210e0 * wr_6_0 
             + 0.377701303848913554e-1 * wr_8_0 + 0.201100642503586404e0 * wr_12_4;
 results[k++] = -0.128111772245388490e0 * wr_12_0 + 0.159103389700320075e0 * wr_4_0 
             + 0.333376331682943525e0 * wr_10_0 - 0.127605577204446706e-1 * wr_6_0 
             - 0.304700203190708521e0 * wr_8_0 + 0.387873212687597702e-1 * wr_12_4;
 results[k++] = -0.133843908348716764e0 * wr_10_0 - 0.287578883142279230e-1 * wr_8_0 
             + 0.410915658321484957e-1 * wr_12_0 + 0.281568276188341813e0 * wr_6_0 
             - 0.115920977143713031e-1 * wr_12_4 + 0.502026358025805145e-1 * wr_4_0;
 results[k++] = -0.129163173062517922e0 * wr_6_0 - 0.423578334504138595e-1 * wr_10_0 
             + 0.233725954445687817e0 * wr_8_0 + wr_0_0 - 0.480944490472245236e0 * wr_4_0 
             - 0.333917138583283250e-1 * wr_12_0 - 0.128267691155594468e-1 * wr_12_4;
 if (k==n_elems) return;
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::setup___ar_4_T2u(uint lmax,
                    std::vector<BoxMatrixQuantumNumbers>& quantnums)
{
 quantnums.clear();
#if (AR_LMAX>=1)
 if (lmax>=1){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,4,1,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,6,1,1));
    }
#endif
#if (AR_LMAX>=3)
 if (lmax>=3){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,4,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,6,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,8,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,3,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,10,3,1));
    }
#endif
#if (AR_LMAX>=5)
 if (lmax>=5){
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,1,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,1,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(4,3,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,3,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,3,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,3,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,6,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,8,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,10,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,12,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,12,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,14,5,1));
    quantnums.push_back(BoxMatrixQuantumNumbers(6,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(8,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(10,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(12,5,2,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,1,14,5,2));
    quantnums.push_back(BoxMatrixQuantumNumbers(14,5,2,14,5,2));
    }
#endif
}
#endif


#if (AR_SX2MAX>=4)
void BoxMatrix::evaluate___ar_4_T2u(WZetaRGLCalculator& wzeta, uint n_elems,
                                    vector<cmplx>& results)
{
 results.resize(n_elems);
 uint k=0; if (k==n_elems) return;
#if (AR_LMAX>=1)
 cmplx wr_0_0=wzeta.eval_wr_lm(0,0);
 results[k++] = wr_0_0;
 results[k++] = wr_0_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=3)
 cmplx wr_4_0=wzeta.eval_wr_lm(4,0);
 cmplx wr_6_0=wzeta.eval_wr_lm(6,0);
 results[k++] = -0.190476190476190476e0 * wr_4_0;
 results[k++] = 0.673435029701473833e0 * wr_4_0;
 results[k++] = 0.514344499873639701e0 * wr_4_0;
 results[k++] = 0.145478593490661587e0 * wr_4_0;
 results[k++] = 0.349927106111882585e0 * wr_4_0;
 results[k++] = 0.494871659305393511e0 * wr_4_0;
 results[k++] = 0.581914373962646349e0 * wr_4_0;
 results[k++] = -0.205737799949455880e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.285714285714285714e0 * wr_4_0;
 results[k++] = 0.254492440808641880e0 * wr_4_0 + 0.823474206650615091e0 * wr_6_0;
 results[k++] = -0.770289587033021258e0 * wr_6_0 - 0.238055880257446234e0 * wr_4_0;
 results[k++] = wr_0_0 + 0.909090909090909091e-1 * wr_4_0 - 0.630341132074124001e0 * wr_6_0;
 results[k++] = 0.240522846460417326e0 * wr_4_0 + 0.778272075748090855e0 * wr_6_0;
 results[k++] = 0.257129738613290009e0 * wr_4_0 + 0.832007846040780741e0 * wr_6_0;
 results[k++] = 0.254492440808641880e0 * wr_4_0 + 0.823474206650615091e0 * wr_6_0;
 results[k++] = 0.240522846460417326e0 * wr_4_0 + 0.778272075748090855e0 * wr_6_0;
 results[k++] = wr_0_0 + 0.168831168831168831e0 * wr_4_0 - 0.378204679244474401e0 * wr_6_0;
 results[k++] = 0.971859061499725035e-1 * wr_4_0 + 0.314469407068345955e0 * wr_6_0;
 results[k++] = -0.770289587033021258e0 * wr_6_0 - 0.238055880257446234e0 * wr_4_0;
 results[k++] = 0.257129738613290009e0 * wr_4_0 + 0.832007846040780741e0 * wr_6_0;
 results[k++] = 0.971859061499725035e-1 * wr_4_0 + 0.314469407068345955e0 * wr_6_0;
 results[k++] = wr_0_0 + 0.181818181818181818e0 * wr_4_0 - 0.336181937106199468e0 * wr_6_0;
 if (k==n_elems) return;
#endif
#if (AR_LMAX>=5)
 cmplx wr_8_0=wzeta.eval_wr_lm(8,0);
 cmplx wr_10_0=wzeta.eval_wr_lm(10,0);
 results[k++] = 0.384900179459750509e0 * wr_4_0;
 results[k++] = -0.111169017897833037e1 * wr_6_0 - 0.247423206341735161e-1 * wr_4_0;
 results[k++] = 0.314918328648886780e0 * wr_4_0 + 0.698741034785834762e0 * wr_6_0;
 results[k++] = 0.864647916983145845e0 * wr_6_0 - 0.222680885707561645e0 * wr_4_0;
 results[k++] = 0.632607619454903650e0 * wr_4_0 - 0.637707027422545325e0 * wr_6_0;
 results[k++] = 0.901853927001594838e0 * wr_6_0 + 0.240865227909837612e0 * wr_4_0;
 results[k++] = 0.339764794291750363e0 * wr_4_0 + 0.127215628693239510e1 * wr_6_0;
 results[k++] = -0.599700224812663918e0 * wr_6_0 + 0.343214271503070080e0 * wr_4_0;
 results[k++] = 0.435231817404564685e0 * wr_4_0 - 0.571791729121046343e0 * wr_6_0;
 results[k++] = -0.485181370905448045e0 * wr_6_0 - 0.435022627528448350e0 * wr_4_0;
 results[k++] = 0.609144903873172670e0 * wr_4_0 + 0.236524958395633047e0 * wr_6_0;
 results[k++] = 0.923076923076923077e0 * wr_6_0;
 results[k++] = 0.494480266564019248e0 * wr_6_0 - 0.407514047040382404e0 * wr_4_0;
 results[k++] = -0.494871659305393511e0 * wr_4_0;
 results[k++] = 0.971859061499725035e-1 * wr_4_0 + 0.660385754843526506e0 * wr_6_0;
 results[k++] = -0.183664099009492863e0 * wr_4_0 + 0.582405492228546518e0 * wr_6_0;
 results[k++] = 0.502581553615466891e0 * wr_8_0 - 0.311308830299236342e0 * wr_6_0 
             - 0.264310820286172886e-1 * wr_4_0;
 results[k++] = 0.449883326641266828e-1 * wr_4_0 - 0.815197873916807222e0 * wr_6_0;
 results[k++] = 0.388743624599890014e0 * wr_4_0 + 0.220128584947842169e0 * wr_6_0;
 results[k++] = 0.367328198018985727e0 * wr_4_0 - 0.249602353812234222e0 * wr_6_0;
 results[k++] = 0.502581553615466891e0 * wr_8_0 - 0.311308830299236342e0 * wr_6_0 
             - 0.264310820286172886e-1 * wr_4_0;
 results[k++] = 0.437959121161087143e0 * wr_4_0 - 0.141712672760565628e0 * wr_6_0;
 results[k++] = 0.909711378444742491e-2 * wr_4_0 + 0.612268723893035093e0 * wr_6_0 
             + 0.308892384883263534e0 * wr_8_0;
 results[k++] = 0.490351459369657573e0 * wr_8_0 + 0.578539563915657650e-1 * wr_6_0 
             + 0.859596454360911919e-1 * wr_4_0;
 results[k++] = 0.174735920006272519e0 * wr_8_0 + 0.865878733146398095e0 * wr_6_0 
             - 0.128652616924167811e0 * wr_4_0;
 results[k++] = -0.156814520442346322e0 * wr_4_0 + 0.848104191288263402e0 * wr_6_0 
             - 0.507108103070097060e-1 * wr_8_0;
 results[k++] = -0.152676204138114823e0 * wr_6_0 + 0.342337096047790208e0 * wr_8_0 
             + 0.272216315553221029e0 * wr_4_0;
 results[k++] = 0.480144449178737893e-1 * wr_4_0 + 0.577061810381117665e-1 * wr_6_0 
             + 0.419227682721447628e0 * wr_8_0;
 results[k++] = 0.387310211307364628e-1 * wr_8_0 + 0.564625607853412263e0 * wr_4_0;
 results[k++] = -0.200876223417491394e0 * wr_4_0 - 0.381194486080697561e0 * wr_6_0 
             - 0.376081434678240531e0 * wr_8_0;
 results[k++] = -0.345033020711716395e0 * wr_4_0 - 0.123521130997592264e0 * wr_6_0 
             + 0.406214376605815099e0 * wr_8_0;
 results[k++] = -0.971139964796382651e-1 * wr_4_0 + 0.482428191557756377e0 * wr_6_0 
             - 0.276362285008659596e0 * wr_8_0;
 results[k++] = 0.692128194832718197e-1 * wr_4_0 + 0.177564654011943434e0 * wr_8_0 
             + 0.815197873916807222e0 * wr_6_0;
 results[k++] = 0.650019932557449469e0 * wr_8_0;
 results[k++] = 0.334848537391649368e0 * wr_8_0 - 0.361297841864756418e0 * wr_6_0 
             - 0.143151416984380133e0 * wr_4_0;
 results[k++] = 0.955904238798486420e0 * wr_6_0 - 0.367434728631712076e-1 * wr_8_0 
             + 0.378743049167177638e0 * wr_4_0;
 results[k++] = -0.611028829574277381e-1 * wr_8_0 - 0.255476154010634166e0 * wr_6_0 
             - 0.101223337686118306e0 * wr_4_0;
 results[k++] = -0.461538461538461538e0 * wr_6_0 - 0.239172548976466654e0 * wr_8_0;
 results[k++] = 0.957673829395049882e-1 * wr_4_0 - 0.755331083730519840e0 * wr_6_0 
             + 0.198719906678683931e0 * wr_8_0;
 results[k++] = -0.331166445411245524e0 * wr_6_0 + 0.316720848711775035e0 * wr_4_0 
             - 0.270392633295305710e0 * wr_8_0;
 results[k++] = 0.293806586553897450e-1 * wr_8_0 + 0.427279785077467599e-1 * wr_6_0 
             + 0.296265225781931253e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.909090909090909091e-1 * wr_4_0 - 0.201709162263719681e0 * wr_6_0;
 results[k++] = 0.454545454545454545e0 * wr_4_0 - 0.470654711948679254e0 * wr_6_0;
 results[k++] = -0.231153894723336469e0 * wr_8_0 + 0.170191414949503761e0 * wr_4_0 
             + 0.654542798127151296e0 * wr_6_0;
 results[k++] = 0.326435455427419159e0 * wr_6_0 + 0.256181624838790897e0 * wr_8_0 
             - 0.485019137090521720e-1 * wr_4_0;
 results[k++] = 0.264099286982750146e0 * wr_6_0 + 0.303983004568183958e0 * wr_8_0 
             + 0.614759690774723789e-1 * wr_4_0;
 results[k++] = -0.421298599785246918e0 * wr_10_0 + 0.765176509695375111e-2 * wr_4_0 
             + 0.568005352453255974e-1 * wr_6_0 - 0.164853750444988838e0 * wr_8_0;
 results[k++] = -0.978344482530692129e-1 * wr_8_0 + 0.118747484407574201e0 * wr_6_0 
             - 0.511898193982296529e-2 * wr_4_0 + 0.915999728533728234e0 * wr_10_0;
 results[k++] = 0.454545454545454545e0 * wr_4_0 - 0.470654711948679254e0 * wr_6_0;
 results[k++] = wr_0_0 - 0.909090909090909091e-1 * wr_4_0 - 0.201709162263719681e0 * wr_6_0;
 results[k++] = 0.231153894723336469e0 * wr_8_0 + 0.163635699531787824e0 * wr_6_0 
             + 0.826644015469018266e-1 * wr_4_0;
 results[k++] = -0.679026791926730407e-1 * wr_4_0 + 0.813856695130669565e0 * wr_10_0 
             + 0.768083424535103905e-1 * wr_6_0 + 0.218428543283600660e0 * wr_8_0;
 results[k++] = 0.137339930917757442e0 * wr_4_0 + 0.274351035960943082e0 * wr_10_0 
             + 0.642123756585510159e0 * wr_6_0 - 0.143991949532297665e0 * wr_8_0;
 results[k++] = 0.478607662582225659e-1 * wr_8_0 + 0.220680218935129338e0 * wr_10_0 
             - 0.535623556786762578e-1 * wr_4_0 - 0.397603746717279181e0 * wr_6_0;
 results[k++] = -0.447910919734509463e-1 * wr_4_0 - 0.479809381612905265e0 * wr_10_0 
             + 0.137747081912786073e0 * wr_6_0 + 0.352204013711049166e0 * wr_8_0;
 results[k++] = -0.231153894723336469e0 * wr_8_0 + 0.170191414949503761e0 * wr_4_0 
             + 0.654542798127151296e0 * wr_6_0;
 results[k++] = 0.231153894723336469e0 * wr_8_0 + 0.163635699531787824e0 * wr_6_0 
             + 0.826644015469018266e-1 * wr_4_0;
 results[k++] = wr_0_0 + 0.473372781065088757e-1 * wr_4_0 + 0.498644520286932966e0 * wr_6_0 
             + 0.122665168190284880e0 * wr_8_0 - 0.271997824603970205e0 * wr_10_0;
 results[k++] = -0.131258686101028985e-1 * wr_8_0 + 0.450965984093062804e0 * wr_10_0 
             + 0.519380018534094179e0 * wr_4_0;
 results[k++] = 0.636665340112440762e-1 * wr_4_0 - 0.786930176226489215e0 * wr_10_0 
             + 0.507267015545110442e0 * wr_6_0 - 0.601763199191653332e-1 * wr_8_0;
 results[k++] = 0.439427180929650430e0 * wr_10_0 + 0.207076495786270972e0 * wr_8_0 
             + 0.372447712411570718e-1 * wr_4_0 + 0.276475155050126093e0 * wr_6_0;
 results[k++] = -0.462400278752279034e-1 * wr_6_0 - 0.995704874103832577e-1 * wr_8_0 
             + 0.461959103926395959e0 * wr_10_0 - 0.109009748277358175e0 * wr_4_0;
 results[k++] = 0.326435455427419159e0 * wr_6_0 + 0.256181624838790897e0 * wr_8_0 
             - 0.485019137090521720e-1 * wr_4_0;
 results[k++] = -0.679026791926730407e-1 * wr_4_0 + 0.813856695130669565e0 * wr_10_0 
             + 0.768083424535103905e-1 * wr_6_0 + 0.218428543283600660e0 * wr_8_0;
 results[k++] = -0.131258686101028985e-1 * wr_8_0 + 0.450965984093062804e0 * wr_10_0 
             + 0.519380018534094179e0 * wr_4_0;
 results[k++] = wr_0_0 - 0.100470957613814757e0 * wr_4_0 - 0.130517693229465676e0 * wr_6_0 
             + 0.318330930257828202e0 * wr_8_0 + 0.400903823112427740e-1 * wr_10_0;
 results[k++] = 0.846718822559801676e-1 * wr_4_0 - 0.131992516236488072e0 * wr_6_0 
             - 0.559874789732931347e-1 * wr_8_0 + 0.380567337783968499e0 * wr_10_0;
 results[k++] = 0.742992751409684905e-1 * wr_4_0 - 0.695721840845614982e-1 * wr_10_0 
             + 0.551537918751171086e0 * wr_6_0 + 0.295067948426734238e-1 * wr_8_0;
 results[k++] = 0.275617755351922613e0 * wr_8_0 - 0.105624697816120717e0 * wr_4_0 
             + 0.179191883823127676e0 * wr_10_0 - 0.479667944882471101e0 * wr_6_0;
 results[k++] = 0.264099286982750146e0 * wr_6_0 + 0.303983004568183958e0 * wr_8_0 
             + 0.614759690774723789e-1 * wr_4_0;
 results[k++] = 0.137339930917757442e0 * wr_4_0 + 0.274351035960943082e0 * wr_10_0 
             + 0.642123756585510159e0 * wr_6_0 - 0.143991949532297665e0 * wr_8_0;
 results[k++] = 0.636665340112440762e-1 * wr_4_0 - 0.786930176226489215e0 * wr_10_0 
             + 0.507267015545110442e0 * wr_6_0 - 0.601763199191653332e-1 * wr_8_0;
 results[k++] = 0.846718822559801676e-1 * wr_4_0 - 0.131992516236488072e0 * wr_6_0 
             - 0.559874789732931347e-1 * wr_8_0 + 0.380567337783968499e0 * wr_10_0;
 results[k++] = wr_0_0 + 0.180391037533894677e0 * wr_4_0 + 0.711914690342540050e-1 * wr_6_0 
             - 0.276809504572024523e-1 * wr_8_0 - 0.962169175469826575e-1 * wr_10_0;
 results[k++] = -0.594954862344483736e0 * wr_6_0 - 0.212860204163878298e0 * wr_8_0 
             - 0.371492010973343478e0 * wr_10_0 - 0.801480977298552607e-1 * wr_4_0;
 results[k++] = -0.724866860568491599e-1 * wr_10_0 - 0.292296671845885309e0 * wr_6_0 
             + 0.585578794702275680e-1 * wr_8_0 + 0.430624100759293509e0 * wr_4_0;
 results[k++] = -0.421298599785246918e0 * wr_10_0 + 0.765176509695375111e-2 * wr_4_0 
             + 0.568005352453255974e-1 * wr_6_0 - 0.164853750444988838e0 * wr_8_0;
 results[k++] = 0.478607662582225659e-1 * wr_8_0 + 0.220680218935129338e0 * wr_10_0 
             - 0.535623556786762578e-1 * wr_4_0 - 0.397603746717279181e0 * wr_6_0;
 results[k++] = 0.439427180929650430e0 * wr_10_0 + 0.207076495786270972e0 * wr_8_0 
             + 0.372447712411570718e-1 * wr_4_0 + 0.276475155050126093e0 * wr_6_0;
 results[k++] = 0.742992751409684905e-1 * wr_4_0 - 0.695721840845614982e-1 * wr_10_0 
             + 0.551537918751171086e0 * wr_6_0 + 0.295067948426734238e-1 * wr_8_0;
 results[k++] = -0.594954862344483736e0 * wr_6_0 - 0.212860204163878298e0 * wr_8_0 
             - 0.371492010973343478e0 * wr_10_0 - 0.801480977298552607e-1 * wr_4_0;
 results[k++] = wr_0_0 + 0.424908424908424908e0 * wr_4_0 - 0.435058977431552251e0 * wr_6_0 
             - 0.392770242973818581e-1 * wr_8_0 - 0.114747583148623762e0 * wr_10_0;
 results[k++] = 0.229461792463536964e-2 * wr_10_0 - 0.636675539078233893e0 * wr_6_0 
             - 0.857684112827785404e-1 * wr_4_0 - 0.656901954910798939e-1 * wr_8_0;
 results[k++] = -0.978344482530692129e-1 * wr_8_0 + 0.118747484407574201e0 * wr_6_0 
             - 0.511898193982296529e-2 * wr_4_0 + 0.915999728533728234e0 * wr_10_0;
 results[k++] = -0.447910919734509463e-1 * wr_4_0 - 0.479809381612905265e0 * wr_10_0 
             + 0.137747081912786073e0 * wr_6_0 + 0.352204013711049166e0 * wr_8_0;
 results[k++] = -0.462400278752279034e-1 * wr_6_0 - 0.995704874103832577e-1 * wr_8_0 
             + 0.461959103926395959e0 * wr_10_0 - 0.109009748277358175e0 * wr_4_0;
 results[k++] = 0.275617755351922613e0 * wr_8_0 - 0.105624697816120717e0 * wr_4_0 
             + 0.179191883823127676e0 * wr_10_0 - 0.479667944882471101e0 * wr_6_0;
 results[k++] = -0.724866860568491599e-1 * wr_10_0 - 0.292296671845885309e0 * wr_6_0 
             + 0.585578794702275680e-1 * wr_8_0 + 0.430624100759293509e0 * wr_4_0;
 results[k++] = 0.229461792463536964e-2 * wr_10_0 - 0.636675539078233893e0 * wr_6_0 
             - 0.857684112827785404e-1 * wr_4_0 - 0.656901954910798939e-1 * wr_8_0;
 results[k++] = wr_0_0 - 0.216501447270678040e0 * wr_4_0 + 0.225135414894649417e0 * wr_6_0 
             - 0.154086787628190366e0 * wr_8_0 + 0.237938132281427199e-1 * wr_10_0;
 if (k==n_elems) return;
#endif
}
#endif
#endif

// **********************************************************************
