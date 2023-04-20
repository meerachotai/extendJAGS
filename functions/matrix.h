#ifndef MATRIX_H_
#define MATRIX_H_

#include "../jagsversions.h"

#ifndef INCLUDERSCALARDIST
namespace jags {
#endif

namespace runjags {
/**
 * Checks the symmetry of a square matrix
 *
 * @param A pointer to array containing the values of the matrix
 *
 * @param n number or rows or columns in the matrix
 *
 * @param tol tolerance for symmetry test
 */
bool check_symmetry(double const *X, unsigned int n, double tol=1e-7);

/** 
 * ADDED FUNCTION by Meera Chotai, March 2023.
 * Cholesky decomposes a symmetrix positive definite matrix
 * using the LAPACK routines DPOTRF and DPOTRI.
 * 
 * @param X Pointer to an array of length n squared, which will contain
 * the decomposed matrix on exit.
 *
 * @param A pointer to array containing the values of the matrix. Only
 * the lower triangle of the matrix (in column-major order) is used.
 *
 * @param n number or rows or columns in the matrix
 */
bool cholesky (double *X, double const *A, int n);

}}

#endif /* MATRIX_H_ */
