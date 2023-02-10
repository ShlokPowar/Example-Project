#include "main.h"
#include "headers.hpp"

int volatesgsdsfa[4] = {0, 11250, 9975, 8500};
int indexjidsofjd = 0;

void toggle_flywheel(){
    
    // if(master.get_digital_new_press(DIGITAL_X)){
    //     toggle = !toggle;
    // }
    // if(toggle){
    //     flywheel.move_voltage(11000);
    // }
    // else{
    //     flywheel.move_voltage(0);
    // }

    if (master.get_digital_new_press(DIGITAL_X)) {
        indexjidsofjd++;
        if (indexjidsofjd == 4) {
            indexjidsofjd = 0;
        }
    }

    if (master.get_digital_new_press(DIGITAL_Y)) {
        indexjidsofjd = 0;
    }

    flywheel.move_voltage(volatesgsdsfa[indexjidsofjd]);
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