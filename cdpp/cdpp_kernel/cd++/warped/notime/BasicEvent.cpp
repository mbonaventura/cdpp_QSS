#ifndef BASICEVENT_CC
#define BASICEVENT_CC

// Copyright (c) 1994-1996 Ohio Board of Regents and the University of
// Cincinnati.  All Rights Reserved.

// BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY 
// FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.  EXCEPT 
// PARTIES PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY OF ANY KIND, 
// EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE 
// PROGRAM IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME 
// THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION. 

// IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING 
// WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR 
// REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR 
// DAMAGES, INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL 
// DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM 
// (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED 
// INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A FAILURE OF 
// THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH HOLDER 
// OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
//
// $Id:
//
//---------------------------------------------------------------------------

#include "BasicEvent.h"
#include <string>
#include <cstring>

using namespace std;

ostream&
operator<<(ostream& os, const BasicEvent& e) {
  os << "sTime: "   << e.sendTime
     << " rTime: "  << e.recvTime
     << " sendID: " << e.sender
     << " dest: "   << e.dest
     << endl;
  
  return os;
}

BasicEvent::BasicEvent(VTime sTime, VTime rTime, unsigned send, 
		       unsigned recv, SequenceCounter evId, unsigned sz) {
  sendTime = sTime;
  recvTime = rTime;
  sender   = send;
  dest     = recv;
  eventId  = evId;
  size     = sz;
}

BasicEvent::BasicEvent(const BasicEvent *be) {
  memcpy(this, be, sizeof(BasicEvent));
}

#endif






