#ifndef ISUBCRIBER_H_INCLUDED
#define ISUBCRIBER_H_INCLUDED

#include<iostream>
#include<string>

class iSubcriber
{
public:
    virtual void update( std::string &WCmessage ) = 0;
};
#endif // ISUBCRIBER_H_INCLUDED
