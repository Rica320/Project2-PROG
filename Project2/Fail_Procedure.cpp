// T04_G07

#include "Fail_Procedure.h"

//------------------------------------------------------------------------
void isInvalid() {

    isEOF();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//------------------------------------------------------------------------
void isEOF() {
    if (std::cin.eof())
        std::exit(0);
}