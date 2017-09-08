#include "pmodeladm.h"
#include "register.h"

#include "generat.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
        admin.registerAtomic(NewAtomicFunction<Generator>(), ATOMIC_MODEL_NAME);
}
