#ifndef CHOL_H_
#define CHOL_H_

#include "../jagsversions.h"

#ifndef INCLUDERSCALARDIST
#include <function/ArrayFunction.h>  // from JAGS/src/modules/bugs/function
namespace jags {
#endif
namespace runjags {
    /**
     * Added by Meera Chotai, March 2023.
     * @short Decomposes a square symmetric positive-definite matrix using Cholesky Decomposition
     * <pre>
     * y[,] <- cholt(x[,])
     * </pre>
     */
    class Chol: public ArrayFunction
    {
    public:
	Chol ();
	void evaluate (double *value, std::vector <double const *> const &args,
		       std::vector<std::vector<unsigned int> > const &dims) 
	    const;
    	std::vector<unsigned int> 
	    dim(std::vector<std::vector<unsigned int> > const &args,
		std::vector<double const *> const &values) const;
	bool checkParameterDim(std::vector<std::vector<unsigned int> > const &dims) const;
	bool checkParameterValue(std::vector<double const *> const &args,
				 std::vector<std::vector<unsigned int> > const &dims) const;
    };

}
#ifndef INCLUDERSCALARDIST
}
#endif

#endif /* CHOL_H_ */
