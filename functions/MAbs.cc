#include "MAbs.h"
#include <util/nainf.h>
#include <rng/RNG.h>

#include <cmath>

using std::vector;
using std::fabs;

#ifndef INCLUDERSCALARDIST
namespace jags {
#endif

namespace runjags {


    MAbs::MAbs ():ScalarFunction ("mabs", 1)
    {
    }

    double MAbs::evaluate(vector<double const *> const &args) const
    {
	return fabs(*args[0]);
    }


    bool MAbs::isDiscreteValued(vector<bool> const &mask) const
    {
	return mask[0];
    }

}
#ifndef INCLUDERSCALARDIST
}
#endif

