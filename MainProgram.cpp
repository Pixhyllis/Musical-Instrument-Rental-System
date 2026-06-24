#include "CoreClasses.h"
#include <iostream>
using namespace std;

int main(){
    SystemManager S;

    S.addInstrument();
    S.displayAvailableInstruments();

    return 0;
}

