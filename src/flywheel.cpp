#include "main.h"
#include "headers.hpp"

bool toggle = false;

void toggle_flywheel(){
    
    if(master.get_digital_new_press(DIGITAL_UP)){
        toggle = !toggle;
    }
    if(toggle){
        flywheel.move_voltage(11000);
    }
    else{
        flywheel.move_voltage(0);
    }
}

// void hold_flywheel(){
//     if(master.get_digital(DIGITAL_UP)){
//         flywheel.move_voltage(11000);
//     }
//     else if(master.get_digital(DIGITAL_DOWN)){
//         flywheel.move_voltage(-11000);
//     }
//     else{
//         flywheel.move_voltage(0);
//     }
// }