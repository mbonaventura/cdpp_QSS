#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
}
