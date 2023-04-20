# Adding custom functions to JAGS via runjags


### Step 1
Copy `Makevars.in` and `runjags.cc` from this repository into `runjags/src`

**OR**

Open `runjags/src/Makevars.in` > Add `functions/MAbs.o` to `OBJECTS`

Open `runjags/src/runjags.cc` > Add `#include "functions/MAbs.h"` > Add `insert(new Mabs);` in `runjagsModule::runjagsModule() : Module("runjags")`

### Step 2

Copy custom function files from this repository into `runjags/src`: `functions/MAbs.cc` and `functions/MAbs.h` (adapted from `JAGS-4.3.2/src/modules/bugs/functions/Abs.h` and `Abs.cc` for testing)

### Step 3

In `R`, run:
```
remove.packages("runjags")
install.packages("path/runjags", repos = NULL, type = "source")

library(runjags)
load.runjagsmodule()

m <- "model{
 L <- mabs(-3)
}"
run.jags(m, monitor="L", method="rjags", modules="runjags")
```
