#include <iostream>
#include <string>
#include "Subcriber.h"
#include "WCMediaProvider.h"

using namespace std;

int main()
{

    WCMediaProvider *WC ;
    WC = WCMediaProvider :: getInstance("World Cup Quatar 2022 ");
    cout << "Copyright by " << WC->getName() <<std::endl;
    cout << &WC << endl;
    WC = WCMediaProvider :: getInstance("Quatar 2022 ");
    cout << "Copyright by " << WC->getName() <<std::endl;
    cout << &WC <<endl ;

    Subcriber vtv;
    Subcriber vtc;
    Subcriber kplus;
    vtv.Register(WC);
    vtc.Register(WC);
    kplus.Register(WC);
    WC->broadCast("Portugal 1-0 Spain");

    kplus.Unregister(WC);
    WC->broadCast("Argentina 2-0 Japan");
    return 0;
}
