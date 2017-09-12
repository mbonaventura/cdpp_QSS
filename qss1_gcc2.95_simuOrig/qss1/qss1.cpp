#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>
#include "mainsimu.h"

#include "message.h"
// #include "parsimu.h"
#include "real.h"
// #include "tuple_value.h"
#include "value.h"


#include "qss1.h"

using namespace std;

QSS1::QSS1(const string &name) :
	Atomic(name),
	in(addInputPort("in")),
	out(addOutputPort("out"))
{
	this->dQRel = str2float(MainSimulator::Instance().getParameter( description(), "dQRel" ));
	this->dQMin = str2float( MainSimulator::Instance().getParameter( description(), "dQMin" ) );
	this->x[0] = str2float( MainSimulator::Instance().getParameter( description(), "X0" ) );
	this->gain = str2float (MainSimulator::Instance().getParameter( description(), "gain" )) ;

    this->x[1] = 0;

    this->q = this->x[0];

    this->dQ = max(fabs(this->x[0]) * this->dQRel, this->dQMin);

    this->sigma = Time::Zero;
    this->logFileName = description() + ".csv";
    // delete file from previous run
    ofstream outf(this->logFileName.data(), std::ofstream::out);
    outf.close();
}


Model &QSS1::initFunction()
{
	this->sigma = Time::Zero;
	holdIn(active, this->sigma);

	return *this;
}

Model &QSS1::externalFunction(const ExternalMessage &msg)
{
    double diffxq[2];

    //Real derx = Tuple<Real>::from_value(msg.value())[0];
    double derx = msg.value ();
    derx = derx * gain;

//    Time sigma = this->nextChange();
    Time e = msg.time() - lastChange();

    if(msg.port() == in)
    {
	    x[0] = x[0] + x[1] * to_seconds(e);
	    x[1] = derx;
	    if(this->sigma.asMsecs() > 0)
        {
	       	// inferior delta crossing
	    	diffxq[1] = -x[1];
       		diffxq[0] = q - x[0] -dQ;
       		this->sigma = minposroot(diffxq);

       		// superior delta difference
       		diffxq[0] = q - x[0] + dQ;
       		Time sigma_up = minposroot(diffxq);

       		// keep the smallest one
       		if(sigma_up < this->sigma){
       			this->sigma = sigma_up;
       		}

       		if(fabs(x[0] - q) > dQ)
                sigma = Time::Zero;
	    }
    }
    else
    {
	    x[0] = derx;
        sigma = Time::Zero;
    }

    holdIn(active, this->sigma);

	return *this;
}

Model &QSS1::internalFunction(const InternalMessage &msg)
{
    x[0] = x[0] + x[1] * to_seconds(this->sigma); // advance time
    q = x[0];    

    dQ = max(dQRel * fabs(x[0]), dQMin);

    if(x[1] == 0){
    	this->sigma = Time::Inf;
        passivate();
    } else {
    	this->sigma = Time((float) fabs(dQ/x[1]));
    	holdIn(active, this->sigma);
    }

	return *this ;
}


Model &QSS1::outputFunction(const InternalMessage &msg )
{
    double y[2] = {x[0], x[1]};
    //this->sigma = this->nextChange();

    y[0] = y[0] + y[1] * to_seconds(sigma); // time_advance
    y[1] = 0;	 

    // send output to file
    ofstream outf(this->logFileName.data(), std::ofstream::out | std::ofstream::app);
    outf << to_seconds(msg.time()) << "," << y[0] << endl;
    outf.close();

	//Tuple<Real> out_value{y[0], y[1]};
    sendOutput(msg.time(), out, y[0]);

	return *this ;
}

Time minposroot(double *coeff){
	float mpr;
	Time ret;

	if(coeff[1] == 0){
		ret = Time::Inf;
	} else{
		mpr = -coeff[0]/coeff[1];
		ret = Time(mpr);

		// check for negative values and overflows in Time.asMsecs() (Time.asMsecs() is used to advance time)
		if(mpr < 0 || ret.asMsecs() < 0 || ret.asMsecs() >= Time::Inf.asMsecs()){
			ret = Time::Inf;
		}
	}

	return ret;
}

double to_seconds(const Time &vt)
{
    return vt.asMsecs() / 1000.;
}
