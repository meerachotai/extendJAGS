// from Francisco Agosto, April 2023
#ifdef FORTRAN_TRAILING_UNDERSCORE
#define F77NAME(x) x##_
#else
#define F77NAME(x) x
#endif

// #define F77_DPOTRF F77NAME(dpotrf)

// FOR LAPACK AND BLAS on Mac
#ifdef __APPLE__
  #include <Accelerate/Accelerate.h>
  #include <clapack.h>
  typedef __CLPK_doublereal doublereal;
  typedef __CLPK_integer integer;
  #else
// everything else here is for Linux and other
  typedef double doublereal;
  typedef int integer;
  or typedef long int integer; on some systems
  extern "C" {
	void F77NAME(dpotrf)(const char *uplo, const int *n, double *a,
		 const int *lda, const int *info);
  }
  #endif
