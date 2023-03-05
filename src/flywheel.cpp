#include "main.h"
#include "headers.hpp"

int rpms[4] = {0, 3240, 2916, 2700};
int mode = 0;

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
        ez::print_to_screen("sui");
        mode++;
        if (mode == 4) {
            mode = 0;
        }
    }

    if (master.get_digital_new_press(DIGITAL_Y)) {
        mode = 0;
    }

    set_flywheel_speed(rpms[mode]);
    ez::print_to_screen("PDLAE fdhsouif\n");
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

void flywheelPID(double target){
    if (target == 0) { flywheel.brake(); }

    //Constants
    double kP = 0.3;
    double kV = 0.0354;
    double threshold = 150;

    double error = 0;
    double prevError = 0;

    double output = 0;

    while (true){
        //Proportional
        error = target - flywheel.get_actual_velocity()*6;

        //Set Speed of Flywheel
        if (error > threshold){
            output = 127;
        }

        else if (error < - threshold){
            output = 0;
        }

        else{
            output = (kV * target) + (kP * error);
        }

        flywheel.move(output);

        prevError = error;
        pros::delay(10);
    }
}


void set_flywheel_speed(int speed){
    static std::unique_ptr<pros::Task> pidTask {};
    if (pidTask != nullptr) {pidTask -> remove();}

    pidTask = (speed == -1) ? nullptr : std::make_unique<pros::Task>([=]{flywheelPID(speed);});
}