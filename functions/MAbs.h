#ifndef MABS_H_
#define MABS_H_


#include "../jagsversions.h"

#ifndef INCLUDERSCALARDIST
#include <function/ScalarFunction.h>
namespace jags {
#endif
namespace runjags {
	
    /**
     * @short Absolute value
     * <pre>
     * y <- abs(x)
     * y = x; x >= 0
     * y = -1; x < 0
     * </pre>
     */
    class MAbs: public ScalarFunction
    {
    public:
	MAbs ();
	double evaluate(std::vector<double const *> const &args) const;
	bool isDiscreteValued(std::vector<bool> const &mask) const;
    };
}
#ifndef INCLUDERSCALARDIST
}
#endif

#endif
