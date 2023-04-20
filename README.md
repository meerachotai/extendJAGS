# Adding custom functions to JAGS via runjags


### Step 1
Copy `Makevars.in` and `runjags.cc` from this repository into `runjags/src`

**OR**

Open `runjags/src/Makevars.in` > Add `functions/Chol.o` and `functions/matrix.o` to `OBJECTS`

Open `runjags/src/runjags.cc` > Add `#include "functions/Chol.h"` and `#include "functions/matrix.h"` > Add `insert(new Chol);` in `runjagsModule::runjagsModule() : Module("runjags")`

### Step 2

Copy custom function files from this repository into `runjags/src`: 
* `functions/Chol.h`
* `functions/Chol.cc` (adapted from `JAGS-4.3.2/src/modules/bugs/functions/Inverse.cc`)
* `functions/lapack.h`
* `functions/matrix.h`
* `functions/matrix.cc` (adapted from `JAGS-4.3.2/src/modules/bugs/matrix/matrix.cc`)

### Step 3

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
Outputs an lower triangular matrix
