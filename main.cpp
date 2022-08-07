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

    Subcriber vtv("vtc3");
    Subcriber vtc("vtc1");
    Subcriber kplus("kplus1");

    vtv.Register(WC);
    vtc.Register(WC);
    kplus.Register(WC);

    cout << "Test register: \n";
    WC->broadCast("Portugal 1-0 Spain");

    cout << "Test unregister: \n";
    kplus.Unregister(WC);
    WC->broadCast("Argentina 2-0 Japan");
    return 0;
}
