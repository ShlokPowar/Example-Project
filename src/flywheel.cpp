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

    set_flywheel_speed(volatesgsdsfa[indexjidsofjd]);
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

void flywheel_auto(int speed){
    flywheel.move_velocity(speed);
}

void flywheelPID(double target){
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
