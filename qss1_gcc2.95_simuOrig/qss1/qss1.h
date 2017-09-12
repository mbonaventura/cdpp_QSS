#ifndef _QSS_H_
#define _QSS_H_

#include <string> 
#include "atomic.h"

#define QSS_MODEL_NAME "QSS1"

Time minposroot(double *coeff);

double to_seconds(const Time &);

class QSS1 : public Atomic {
  public:
    
    QSS1(const string &name = QSS_MODEL_NAME );
    virtual string className() const {  return QSS_MODEL_NAME ;}
  
  protected:
  	Model &initFunction();
  	Model &externalFunction( const ExternalMessage & );
  	Model &internalFunction( const InternalMessage & );
  	Model &outputFunction( const InternalMessage & );

  private:
    const Port &in;
    Port &out;

    double dQ, dQMin, dQRel; // Time de cd++ usa floats (que tiene la mitad de la precision). Hay que castear al hacer Time((float) dQ) y se pierde precision.
    double x[2], q;
    Time sigma; // track last change
    double gain;

    double get_param(const string &);
};

#endif
