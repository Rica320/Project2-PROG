#include "Fail_Procedure.h"

//------------------------------------------------------------------------
void isInvalid() {

    isExit();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//------------------------------------------------------------------------
void isExit() {
    if (std::cin.eof())
        std::exit(0);
}