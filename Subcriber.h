#ifndef SUBCRIBER_H_INCLUDED
#define SUBCRIBER_H_INCLUDED
#include<iostream>
#include<string>
#include"iSubcriber.h"
#include"iWCMediaProvider.h"

using namespace std;
class Subcriber : public iSubcriber
{
private:
    std::string Message;
    std::string sName;
public:
    Subcriber(std::string name);
    void update(std::string &WCmessage) override;
    void Register(iWCMediaProvider *Station);
    void Unregister(iWCMediaProvider *Station);
    std::string getName();
};

Subcriber::Subcriber(std::string name)
{
    sName = name;
}
void Subcriber :: update(std::string &WCmessage)
{
    Message = WCmessage;
    cout <<getName()<< ": " << this->Message << endl;
}

void Subcriber :: Register(iWCMediaProvider * Station)
{
    Station->attach(this);
}

void Subcriber :: Unregister(iWCMediaProvider * Station)
{
    Station->detach(this);
}

std::string Subcriber ::getName()
{
    return sName;
}

#endif // SUBCRIBER_H_INCLUDED
