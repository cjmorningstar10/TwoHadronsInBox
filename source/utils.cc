#include "utils.h"
using namespace std;


// *************************************************************************
 
 
  // Prototypes of routines in LAPACK library--to call Fortran
  // routines from a C++ program, use extern "C" to tell the
  // compiler that the external routine is a C routine; then
  // add an underscore to the end of the routine name since
  // the routine is in Fortran.  All parameters must be passed
  // as pointers and two-dimensional arrays must follow
  // Fortran conventions.

extern "C"{
   void dsyev_(char *jobz, char *uplo, int *n, double *a, int *lda,
               double *w, double *work, int *lwork, int *info);
   void zheev_(char *jobz, char *uplo, int *n, double *a, int *lda,
               double *w, double *work, int *lwork, double *rwork, 
               int *info);
   void zgeev_(char *jobvl, char *jobvr, int *n, double *a, int *lda, 
               double *w, double *vl, int *ldvl, double *vr, int *ldvr,
               double *work, int *lwork, double *rwork, int *info );
   void zgetrf_(int *m, int *n, double *a, int *lda, int *ipiv, int *info);
   void zpotrf_(char *uplo, int *n, double *a, int *lda, int *info);
}

// ***************************************************************


   //  Takes a Hermitian matrix "H" and returns the eigenvalues in
   //  ascending order in "eigvals" and the associated eigenvectors
   //  in the columns of "eigvecs".  Throws an exception if fails.

void Diagonalizer::diagonalize(const RealSymmetricMatrix& H, RVector& eigvals,
                               RMatrix& eigvecs, bool calceigvecs)
{
 int n=H.size();
 if (n==0){
   eigvals.clear();
   eigvecs.clear();return;}
 int lwork=5*n;
 RVector work(lwork);
 eigvals.resize(n);
 int info;
 char jobz=(calceigvecs)?'V':'N';
 char uplo='U';

    // load H (upper triangle) into matf fortran format 
    //    (column major; row index changes fastest)
 vector<double> matf(n*n);
 for (int col=0;col<n;++col)
 for (int row=0;row<=col;++row)
    matf[row+n*col]=H(row,col);

 dsyev_(&jobz,&uplo,&n,&matf[0],&n,&eigvals[0],&work[0],&lwork,&info);
 if (info<0){
    throw(std::invalid_argument(" bad arguments in diagonalize"));}
 else if (info>0){
    throw(std::invalid_argument(" no convergence in diagonalize"));}

 if (calceigvecs){
    eigvecs.resize(n,n);
    for (int col=0;col<n;++col)
    for (int row=0;row<n;++row)
       eigvecs(row,col)=matf[row+n*col];}
}


void Diagonalizer::getEigenvectors(const RealSymmetricMatrix& H, 
                                   RVector& eigvals, RMatrix& eigvecs)
{
 diagonalize(H,eigvals,eigvecs,true);
}


void Diagonalizer::getEigenvalues(const RealSymmetricMatrix& H, 
                                  RVector& eigvals)
{
 RMatrix eigvecs;
 diagonalize(H,eigvals,eigvecs,false);
}




void Diagonalizer::diagonalize(const ComplexHermitianMatrix& H, 
                               RVector& eigvals, CMatrix& eigvecs, bool calceigvecs)
{
 int n=H.size();
 if (n==0){
   eigvals.clear();
   eigvecs.clear();return;}
 int lwork=4*n;
 RVector work(2*lwork);
 RVector rwork(3*n);
 eigvals.resize(n);
 int info;
 char jobz=(calceigvecs)?'V':'N';
 char uplo='U';

    // load H (upper triangle) into matf fortran format 
    //    (column major; row index changes fastest)
    //    complex stored as real,imag contiguous in fortran
 vector<double> matf(2*n*n);
 for (int col=0;col<n;col++)
 for (int row=0;row<=col;row++){
    int index=2*(row+n*col);
    const complex<double>& z=H(row,col);
    matf[index]=z.real();
    matf[index+1]=z.imag();}

 zheev_(&jobz,&uplo,&n,&matf[0],&n,&eigvals[0],&work[0],&lwork,&rwork[0],&info);
 if (info<0){
    throw(std::invalid_argument(" bad arguments in diagonalize"));}
 else if (info>0){
    throw(std::invalid_argument(" no convergence in diagonalize"));}

 if (calceigvecs){
    eigvecs.resize(n,n);
    for (int col=0;col<n;col++)
    for (int row=0;row<n;row++){
       int index=2*(row+n*col);
       eigvecs(row,col)=complex<double>(matf[index],matf[index+1]);}}
}


void Diagonalizer::getEigenvectors(const ComplexHermitianMatrix& H, 
                                   RVector& eigvals, CMatrix& eigvecs)
{
 diagonalize(H,eigvals,eigvecs,true);
}


void Diagonalizer::getEigenvalues(const ComplexHermitianMatrix& H, RVector& eigvals)
{
 CMatrix eigvecs;
 diagonalize(H,eigvals,eigvecs,false);
}


void Diagonalizer::getEigenvalues(const CMatrix& M, CVector& eigvals)
{
 int n=M.size(0);
 if (int(M.size(1))!=n)
    throw(std::invalid_argument("Must be square matrix to get eigenvalues"));
 if (n==0){
   eigvals.clear();return;}

 int lwork=4*n;
 RVector work(2*lwork);
 RVector rwork(2*n);
 RVector lambda(2*n);
 int info;
 char jobvl='N';
 char jobvr='N';
 double *null=0;

    // load M (entire matrix) into matf fortran format 
    //    (column major; row index changes fastest)
    //    complex stored as real,imag contiguous in fortran
 vector<double> matf(2*n*n);
 for (int col=0;col<n;col++)
 for (int row=0;row<n;row++){
    int index=2*(row+n*col);
    const complex<double>& z=M(row,col);
    matf[index]=z.real();
    matf[index+1]=z.imag();}

 zgeev_(&jobvl,&jobvr,&n,&matf[0],&n,&lambda[0],null,&n,null,&n,
        &work[0],&lwork,&rwork[0],&info);

 if (info<0){
    throw(std::invalid_argument(" bad arguments in diagonalize"));}
 else if (info>0){
    throw(std::invalid_argument(" no convergence in diagonalize"));}
 eigvals.resize(n);
 for (int k=0;k<n;k++)
    eigvals[k]=complex<double>(lambda[2*k],lambda[2*k+1]);
}


// *********************************************************************


     //   returns  [det(M)]^(1/Ndet)   Ndet must be odd

double RealDeterminantRoot::getDeterminantOddRoot(
                    const ComplexHermitianMatrix& M, uint Ndet)
{
 int n=M.size();
 if (n==0){
   return 0.0;}

    // load M (entire matrix) into matf fortran format 
    //    (column major; row index changes fastest)
    //    complex stored as real,imag contiguous in fortran
 vector<double> matf(2*n*n);
 for (int col=0;col<n;col++)
 for (int row=0;row<n;row++){
    int index=2*(row+n*col);
    const complex<double>& z=M(row,col);
    matf[index]=z.real();
    matf[index+1]=z.imag();}

 return get_det_odd_root(matf,n,Ndet);
}

   //    returns [det(1-A*B)]^(1/Ndet) where A real symmetric
   //          and B is Hermitian.

double RealDeterminantRoot::getDeterminantOddRoot(
                         const RealSymmetricMatrix& A,
                         const ComplexHermitianMatrix& B, uint Ndet)
{
 int n=B.size();
 if (A.size()!=B.size())
    throw(std::invalid_argument("Matrices not same size in RealDetRoot"));
 if (n==0){
   return 0.0;}

    // load M (entire matrix) into matf fortran format 
    //    (column major; row index changes fastest)
    //    complex stored as real,imag contiguous in fortran
 vector<double> matf(2*n*n);
 for (int col=0;col<n;col++)
 for (int row=0;row<n;row++){
    int index=2*(row+n*col);
    complex<double> z(0.0,0.0);
    for (int k=0;k<n;k++)
       z+=A(row,k)*B(k,col);
    matf[index]=-z.real()+((row==col)?1.0:0.0);
    matf[index+1]=-z.imag();}

 return get_det_odd_root(matf,n,Ndet);
}


      //  compute determinant using LU decomposition: M = PLU
      //  where P = permutation matrix, L = lower triangular with unit diagonals,
      //  U = upper triangular.  Determinant is product of diagonal elements
      //  of U times (-1)^S  S from P

double RealDeterminantRoot::get_det_odd_root(std::vector<double>& matf, 
                                             int n, uint Ndet)
{
 if ((Ndet%2)==0)
    throw(std::invalid_argument("Must use odd root in RealDetRoot"));
 vector<int> ipiv(n);
 int info;
 zgetrf_(&n,&n,&matf[0],&n,&ipiv[0],&info);

 if (info<0){
    throw(std::invalid_argument(" bad arguments in diagonalize"));}
 else if (info>0){
    return 0.0;}

 double root=1.0/double(Ndet);
 double r,res=1.0;
 complex<double> phase(1.0,0.0);
 for (int k=0;k<n;k++){
    int index=2*(k+n*k);
    complex<double> z(matf[index],matf[index+1]);
    r=std::abs(z);
    if (Ndet>1) res*=std::pow(r,root);
    else res*=r;
    phase*=z/r;}
 if (phase.real()<0.0) res=-res;
 for (int i=1;i<=n;i++){
    if (ipiv[i-1]!=i) res=-res;}
 return res;
}


     //   returns  Omega(mu,M)   M = Hermitian

double RealDeterminantRoot::getOmega(double mu,
                    const ComplexHermitianMatrix& M)
{
 int n=M.size();
 if (n==0){
   return 0.0;}
 double musq=mu*mu;

    // load M (entire matrix) into nummatf fortran format
    // and mu^2+M*Mdag (lower triangle) into denmatf fortran format 
    //    (column major; row index changes fastest)
    //    complex stored as real,imag contiguous in fortran
 vector<double> nummatf(2*n*n),denmatf(2*n*n);
 for (int col=0;col<n;col++)
 for (int row=col;row<n;row++){
    int index=2*(row+n*col);
    const complex<double>& z=M(row,col);
    nummatf[index]=z.real();
    nummatf[index+1]=z.imag();
    complex<double> zz(0.0,0.0);
    for (int k=0;k<n;k++)
       zz+=M(row,k)*conj(M(col,k));
    denmatf[index]=zz.real();
    denmatf[index+1]=zz.imag();
    if (row==col){
       denmatf[index]+=musq;}
    else{
       index=2*(col+n*row);
       nummatf[index]=z.real();
       nummatf[index+1]=-z.imag();}}

 return get_omega(nummatf,denmatf,n);
}

   //    returns Omega(mu,1-A*B) where A real symmetric
   //          and B is Hermitian.

double RealDeterminantRoot::getOmega(double mu,
                         const RealSymmetricMatrix& A,
                         const ComplexHermitianMatrix& B)
{
 int n=B.size();
 if (A.size()!=B.size())
    throw(std::invalid_argument("Matrices not same size in RealDetRoot"));
 if (n==0){
   return 0.0;}
 double musq=mu*mu;

    // load M (entire matrix) into nummatf fortran format 
    //    (column major; row index changes fastest)
    //    complex stored as real,imag contiguous in fortran
 vector<double> nummatf(2*n*n);
 for (int col=0;col<n;col++)
 for (int row=0;row<n;row++){
    int index=2*(row+n*col);
    complex<double> z(0.0,0.0);
    for (int k=0;k<n;k++)
       z+=A(row,k)*B(k,col);
    nummatf[index]=-z.real()+((row==col)?1.0:0.0);
    nummatf[index+1]=-z.imag();}

 vector<double> denmatf(2*n*n);  // put mu^2+Q*Q^dag  Q=1-A*B (lower triangle)
 for (int col=0;col<n;col++)
 for (int row=col;row<n;row++){
    int index=2*(row+n*col);
    double& zre=denmatf[index];
    double& zim=denmatf[index+1];
    for (int k=0;k<n;k++){
       int index1=2*(row+n*k);
       double ar=nummatf[index1];
       double ai=nummatf[index1+1];
       int index2=2*(col+n*k);
       double br=nummatf[index2];
       double bi=nummatf[index2+1];
       zre+=ar*br+ai*bi;
       zim+=ai*br-ar*bi;}
    if (row==col) zre+=musq;}

return get_omega(nummatf,denmatf,n);
}


    //   nummatf is numerator matrix "A", denmatf is Hermitian, pos def 
    //   denominator matrix mu^2 + A * Adagger.  Method is to compute
    //   determinant of numerator as above using LU decomposition,
    //   then compute determinant of numerator using Cholesky.
    //   Avoid large determinants by multiplying one diagonal of 
    //   numerator U and denominator L at a time.

double RealDeterminantRoot::get_omega(std::vector<double>& nummatf, 
                   std::vector<double>& denmatf, int n)
{
 int info;
 char uplo='L';
 zpotrf_(&uplo,&n,&denmatf[0],&n,&info);  // Cholesky of Hermitian posdef denmatf
 if (info<0){
    throw(std::invalid_argument(" bad arguments in diagonalize"));}
 else if (info>0){
    return 0.0;}

 vector<int> ipiv(n);
 zgetrf_(&n,&n,&nummatf[0],&n,&ipiv[0],&info);
 if (info<0){
    throw(std::invalid_argument(" bad arguments in diagonalize"));}
 else if (info>0){
    return 0.0;}

 double r,res=1.0;
 complex<double> phase(1.0,0.0);
 for (int k=0;k<n;k++){
    int index=2*(k+n*k);
    complex<double> z(nummatf[index],nummatf[index+1]);
    r=std::abs(z);
    res*=r/denmatf[index];    // Cholesky has real pos diagonals
    phase*=z/r;}
 if (phase.real()<0.0) res=-res;

 for (int i=1;i<=n;i++){
    if (ipiv[i-1]!=i) res=-res;}
 return res;
}




// ********************************************************************
