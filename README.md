# Adding custom functions to JAGS via runjags

## Tutorial
The following steps have only been tested on MacOS with `JAGS-4.3.2`, `rjags-4-13` and `runjags-2.2.1-7`.

### Step 1
Copy `Makevars.in` and `runjags.cc` from this repository into `runjags/src`

**OR**

Open `runjags/src/Makevars.in` > Add `functions/Chol.o` and `functions/matrix.o` to `OBJECTS`

Add appropriate flags to `PKG_CPPFLAGS` to direct to where LAPACK is stored. In this repo, I have added in flags for MacOS default LAPACK directory. For Linux and other systems, you may need to add `-llapack -lblas -lg2c -lm` (but this remains untested).

For Windows, you may have to change `Makevars.win` instead.

### Step 2

Open `runjags/src/runjags.cc` > Add `#include "functions/Chol.h"` and `#include "functions/matrix.h"` > Add `insert(new Chol);` in `runjagsModule::runjagsModule() : Module("runjags")`


### Step 3
Copy custom function files from this repository into `runjags/src`: 
* `functions/Chol.h`
* `functions/Chol.cc` (adapted from `JAGS-4.3.2/src/modules/bugs/functions/Inverse.cc`)
* `functions/lapack.h`
 * For Linux and other systems, you may have to locate 
* `functions/matrix.h`
* `functions/matrix.cc` (adapted from `JAGS-4.3.2/src/modules/bugs/matrix/matrix.cc`)

### Step 4

In `R`, run:
```
A <- matrix(c(5,1,2,1,3,4,2,4,6),3,3)
m <- "model{
 L <- cholt(A)
}
"
results <- run.jags(m, data = list("A" = A), monitor=c("L"), 
                    method="rjags", modules="runjags")
results
```
**Outputs** a Cholesky decomposition of matrix A, as a lower triangular matrix. 

## References:
* Solikhah, A., Kuswanto, H., Iriawan, N., Fithriasari, K., & Choir, A. S. (2021, February). Extending Runjags: A tutorial on adding Fisher’sz distribution to Runjags. In AIP Conference Proceedings (Vol. 2329, No. 1, p. 060005). AIP Publishing LLC.
* Wabersich, D., & Vandekerckhove, J. (2014). Extending JAGS: A tutorial on adding custom distributions to JAGS (with a diffusion model example). Behavior research methods, 46, 15-28.
