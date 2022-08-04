#ifndef WCMEDIAPROVIDER_H_INCLUDED
#define WCMEDIAPROVIDER_H_INCLUDED

#include"iWCMediaProvider.h"
#include<vector>
#include<algorithm>

class WCMediaProvider : public iWCMediaProvider
{
private:
    std::vector<iSubcriber*> station;
    std::vector<iSubcriber*>:: iterator iterator;
    WCMediaProvider(std::string name);
    std::string WCmessage;
    std::string mName;

    static WCMediaProvider* WCMediaProviderPtr;
public:
    void attach(iSubcriber *tv) override ;
    void detach(iSubcriber *tv) override;
    void Notify() override;

    void numberOfSubcribers();

    void broadCast(std::string content );
    std::string getName();

    static WCMediaProvider *getInstance(std::string name);

};

WCMediaProvider :: WCMediaProvider(string name)
{
    mName = name;
}

void WCMediaProvider :: attach(iSubcriber *tv)
{
    station.push_back(tv);
}

void WCMediaProvider :: detach(iSubcriber *tv)
{
    iterator = find(station.begin(), station.end(), tv);
    if(iterator != station.end())
    {
        station.erase(iterator);
    }
}

void WCMediaProvider :: Notify()
{
    numberOfSubcribers();
    for(iSubcriber *tv : station)
    {
        tv->update(WCmessage);
    }
}

void WCMediaProvider :: broadCast(std::string content)
{
    this->WCmessage = content;
    Notify();
}

void WCMediaProvider :: numberOfSubcribers()
{
    std::cout << "There are " << station.size() << " TV Stations subcribe to WC media right!" << std::endl;
}

WCMediaProvider* WCMediaProvider :: getInstance(std::string name)
{
     if(WCMediaProviderPtr == nullptr)
     {
         WCMediaProviderPtr = new WCMediaProvider(name);
     }
     return WCMediaProviderPtr;
}

std::string WCMediaProvider ::getName()
{
    return mName;
}

WCMediaProvider* WCMediaProvider::WCMediaProviderPtr = nullptr;




#endif // WCMEDIAPROVIDER_H_INCLUDED
