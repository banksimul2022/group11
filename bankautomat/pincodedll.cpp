#include "pincodedll.h"

/*PinCodeDLL::PinCodeDLL()
{
}
*/
void PinCodeDLL::pinui()
{
    objectDialog = new PinUi();
    objectDialog->exec();
}
