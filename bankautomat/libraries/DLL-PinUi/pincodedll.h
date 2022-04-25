#ifndef PINCODEDLL_H
#define PINCODEDLL_H
#include "pinui.h"

#include "PinCodeDLL_global.h"

class PinCodeDLL
{
public:
    //PinCodeDLL();
    void PINCODEDLL_EXPORT pinui();
private:
    class PinUi * objectDialog;
};



#endif // PINCODEDLL_H
