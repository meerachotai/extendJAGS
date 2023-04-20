#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#include "matrix.h"
#include "lapack.h" // from runjags/src/functions

using std::log;
using std::fabs;
using std::copy;
using std::vector;

#include "../jagsversions.h"

#ifndef INCLUDERSCALARDIST
#include <module/ModuleError.h>
namespace jags {
#endif

namespace runjags {

bool check_symmetry(double const *x, unsigned int n, double tol)
{
    for (unsigned int i = 1; i < n; ++i) {
	double const *xp = x + i;
	double const *yp = x + n*i;
	for (unsigned int j = 0; j < i; ++j) {
	    if (fabs(*xp - *yp) > tol) return false;
	    xp += n;
	    yp++;
	}
    }
    return true;
}


// ADDED FUNCTION by Meera Chotai, March 2023. 
bool cholesky (double *X, double const *A, int n)
{
    /* cholesky decompose n x n symmetric positive definite matrix A. Put result in X*/

    int N = n*n;
    double *Acopy = new double[N];
    for (int i = 0; i < N; i++) {
	Acopy[i] = A[i];
    }

    int info = 0;
    
//	https://netlib.org/lapack/explore-html/d1/d7a/group__double_p_ocomputational_ga2f55f604a6003d03b5cd4a0adcfb74d6.html
//	F77_DPOTRF ("L", &n, Acopy, &n, &info);
	char uplo = 'U';
	F77NAME(dpotrf)(&uplo, &n, Acopy, &n, &info);

    for (int i = 0; i < n; ++i) {
	X[i*n + i] = Acopy[i*n + i]; // diagonals
	for (int j = 0; j < i; ++j) {
	    X[j*n + i] = 0; // upper triangle
	    X[i*n + j] = Acopy[i*n + j]; // lower triangle
	}
    }
    delete [] Acopy;

    if (info != 0) {
	throwRuntimeError("Unable to invert symmetric positive definite matrix");
    }
    return true;
}

}}
