#include "main.h"
#include "headers.hpp"

void set_indexer(){
    if(master.get_digital(DIGITAL_L1)){
        indexer.set_value(true);
    }
    else{
        indexer.set_value(false);
    }
}