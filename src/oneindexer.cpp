#include "main.h"
#include "headers.hpp"

void single_index(){
    if(master.get_digital(DIGITAL_L2)){
        indexerSingle.set_value(true);
    }
    else{
        indexerSingle.set_value(false);
    }
}