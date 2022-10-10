/** -*- C++ -*-
	@file progresscallback.h
	@author Michael Vogt <mvo@debian.org>
*/

#ifndef EPT_PROGRESSCALLBACK_H
#define EPT_PROGRESSCALLBACK_H

#include <string>
#include <apt-pkg/acquire.h>

namespace ept {

class ProgressCallback : public pkgAcquireStatus
{
protected:
    virtual bool Pulse(pkgAcquire *Owner);
public:
    ProgressCallback() {};
    virtual ~ProgressCallback() {};
    virtual bool MediaChange(std::string, std::string ) { return false; } // bah

    // override this to get periodic updates
    virtual void UpdatePulse( double, double, unsigned long ) {}
};

}

#endif
