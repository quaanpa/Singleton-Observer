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
public:
    Subcriber();
    void update(std::string &WCmessage) override;
    void Register(iWCMediaProvider *Station);
    void Unregister(iWCMediaProvider *Station);
};

Subcriber::Subcriber(){}
void Subcriber :: update(std::string &WCmessage)
{
    Message = WCmessage;
    cout << this->Message << endl;
}

void Subcriber :: Register(iWCMediaProvider * Station)
{
    Station->attach(this);
}

void Subcriber :: Unregister(iWCMediaProvider * Station)
{
    Station->detach(this);
}

#endif // SUBCRIBER_H_INCLUDED
