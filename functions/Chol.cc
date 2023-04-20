#include <util/nainf.h>
#include <util/dim.h>
#include <rng/RNG.h>

#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#include "Chol.h"

#include "matrix.h"  // from runjags/src/matrix
using std::vector;

#ifndef INCLUDERSCALARDIST
namespace jags {
#endif

namespace runjags {

    Chol::Chol (): ArrayFunction ("cholt", 1)
    {
    }
    /**
     * Evaluates the function. 
     *
     * @param value array of doubles which contains the result of
     * the evaluation on exit 
     * @param args Vector of arguments. 
     * @param dims Respective dimensions of each element of args.
     */
    void Chol::evaluate (double *value, vector<double const *> const &args,
			    vector<vector<unsigned int> > const &dims) const
    {
	//FIXME: RETURN VALUE IGNORED
	cholesky (value, args[0], dims[0][0]);
    }
    
    bool 
    Chol::checkParameterDim (vector<vector<unsigned int> > const &dims) const
    {
	return isSquareMatrix(dims[0]) || isScalar(dims[0]);
    }

    bool 
    Chol::checkParameterValue(vector<double const *> const &args,
				 vector<vector<unsigned int> > const &dims) const
    {
	return check_symmetry(args[0], dims[0][0]);
    }

    vector<unsigned int> 
    Chol::dim (vector<vector<unsigned int> > const &dims,
		  vector<double const *> const &values) const
    {
	return dims[0];
    }

}
#ifndef INCLUDERSCALARDIST
}
#endif
