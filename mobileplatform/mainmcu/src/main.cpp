// #include "mbed.h"
// #include <Defs.h>
// #include <Drive.h>
// #include <Uart.h>

// StepperPins stepper_pins(PA_0, PA_1, PA_2, PA_3);
// DCPins front_left(PA_0, PA_4, PA_5);
// DCPins front_right(PA_2, PB_6, PB_7);
// DCPins back_left(PA_6, PB_15, PB_14);
// DCPins back_right(PB_0, PB_3, PA_8);
// DrivePins drive_pins(front_left, front_right, back_left, back_right);

// Drive drive(drive_pins, stepper_pins, 360, 100, 1);
// // Uart uart(PA_10, PA_9, 9600);

// #define WAIT_TIME_MS 1000
// DigitalOut onboard_led(PC_13);
// static Serial serial_mon(PA_9, PA_10, 9600);

// int main()
// {
//     serial_mon.printf("Program Start");
//     drive.init(50, 0.01);
//     while (1)
//     {
//         serial_mon.printf("This is the bare metal blinky example running on Mbed OS\n");
//         // Data data = uart.ReceiveData();
//         drive.drive(1.0, 90);
//         // ThisThread::sleep_for(1000);
//         onboard_led = !onboard_led;
//         thread_sleep_for(WAIT_TIME_MS);
//     }
// }

#include "mbed.h"
#include <Drive.h>

StepperPins stepper_pins(PB_1, PB_2, PB_3, PB_4);
DCPins front_left(PA_0, PA_4, PA_5);
DCPins front_right(PA_1, PB_8, PB_9);
DCPins back_left(PA_2, PB_6, PB_7);
DCPins back_right(PA_3, PB_4, PB_5);
DrivePins drive_pins(front_left, front_right, back_left, back_right);

Drive drive(drive_pins, stepper_pins, 360, 100, 1);
DigitalOut onboard_led(PC_13);
Serial serial_mon(PA_9, PA_10, 9600);

int main()
{
    serial_mon.printf("Program Start\n");
    drive.init(50, 0.1f);
    float counter = 0.0;
    while (1)
    {
        onboard_led = !onboard_led;
        drive.drive(counter, 90);
        wait(1);
        counter = counter + 0.1;
        if (counter >= 1.0)
        {
            counter = 0.0;
        }
    }
}

// #include "mbed.h"
// #include <SoftPWM.h>

// SoftPWM m1(PA_4);

// DigitalOut onboard_led(PC_13);
// Serial serial_mon(PA_9, PA_10, 9600);

// int main()
// {
//     serial_mon.printf("Program Start\n");
//     m1.period(0.1f);
//     m1.write(0.9f);
//     while (1)
//     {
//         serial_mon.printf("This is the bare metal blinky example running on Mbed OS\n");
//         onboard_led = !onboard_led;
//         wait(5);
//     }
// }

// #include "mbed.h"
 
// DigitalOut myled(PA_0);
 
// int main() {
//     while(1) {
//         myled = 1;
//         wait(0.2);
//         myled = 0;
//         wait(0.2);
//     }
// }