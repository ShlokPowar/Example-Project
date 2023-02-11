#include "main.h"
#include "headers.hpp"

int trigger = 0;

void expand(){
    if(master.get_digital_new_press(DIGITAL_RIGHT)){
        trigger++;
    }
    if(trigger >= 1000){
        expansion.set_value(true);
        // expansion2.set_value(true); // this is if you decide to use a second solenoid for the other piston
    }
    else{
        expansion.set_value(false);
        // expansion2.set_value(false); // this is if you decide to use a second solenoid for the other piston
    }
}
