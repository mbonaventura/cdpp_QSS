/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "pmodeladm.h" 
#include "parsimu.h"
#include "register.h"

#ifdef DEVS_AIRPORT
#include "modulo.h"
#include "selector.h"
#include "control.h"
#include "cola.h"
#include "deposito.h"
#include "salida.h"
#endif

#ifdef DEVS_NET
#include "client.h"
#include "controla.h"
#include "disco.h"
#include "multicpu.h"
#include "router.h"
#include "stopq.h"
#include "transduc2.h"
#endif

//CONTROL LINE1 TO BE USED BY ADDING HEADER FILES//

using namespace std;

void ParallelMainSimulator::registerNewAtomics()
{
/*	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<ConstGenerator>() , "ConstGenerator" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;*/
	
#ifdef DEVS_AIRPORT
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<modulo>() , "modulo" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<selector>() , "selector" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<control>() , "control" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<cola>() , "cola" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<deposito>() , "deposito" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<salida>() , "salida" ) ;
#endif
	
#ifdef DEVS_NET
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Client>() , "Client" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Controladora>() , "Controladora" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Disco>() , "Disco" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<MultiCPU>() , "MultiCPU" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Router>() , "Router" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<StoppableQueue>() , "StoppableQueue" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer2>() , "Transducer2" ) ;
#endif	

//CONTROL LINE2 TO BE USED BY ADDING MODELS//

	register_atomics_on(SingleParallelModelAdm::Instance());
}


#ifndef REGISTER_ATOMICS
void register_atomics_on(ParallelModelAdmin &admin)
{
	// This function can be used to dynamically register ad-hoc atomic models
	// defined by the user. In order to do this, the user must:
	//   * Provide a custom implementation of this function in one of their
	//     source files.
	//   * Compile the CD++ kernel defining the flag REGISTER_ATOMICS like so:
	//     DEFINES_CPP = -DREGISTER_ATOMICS
	// Note that the default behavior is to do nothing, as the kernel does not
	// need to register any custom atomic model.
}
#endif
