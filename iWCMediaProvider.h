#ifndef IWCMEDIAPROVIDER_H_INCLUDED
#define IWCMEDIAPROVIDER_H_INCLUDED

#include<iostream>
#include"iSubcriber.h"

class iWCMediaProvider
{
public:
    virtual void attach(iSubcriber *tv) = 0;
    virtual void detach(iSubcriber *tv) = 0;
    virtual void Notify() = 0;
};

#endif // IWCMEDIAPROVIDER_H_INCLUDED
