// include servo library
#include <Servo.h>
// declare variables
Servo greg; //Everyone say hi to greg
// joystick analog pins for range of values
int VRX = A0;
int VRY = A1;
// servo pin
int greg_pin = 9;
// joystick values (will be read)
int x_joy;
int y_joy;
// initial servo pos
int pos = 90;

void setup()
{
    // inputs, outputs. They're OPTIONAL, but good practice/habit to have.
    // Joystick X and Y values are input
    pinMode(VRX, INPUT);
    pinMode(VRY, INPUT);
    // Servo takes values
    pinMode(greg_pin, OUTPUT);
    greg.attach(9, 500, 2500); // attach(pin, min, max)
}

void loop()
{
    // read joystick value -> variables
    x_joy = analogRead(VRX);
    // if joystick value is bigger than 700, rotate servo left
    if (x_joy > 700) // Check condition. Deadzone = 300 < x_joy < 700 = no motion
    {
        if (pos > 1)
            pos--; // CCW rotation
        greg.write(pos);
    }
    // if joystick value is smaller than 300, rotate servo right
    else if (x_joy < 300) // Check condition. Deadzone = 300 < x_joy < 700 = no motion
    {
        if (pos < 179)
            pos++; // CW rotation
        greg.write(pos);
    }
    // control deg/ms speed
    delay(10);
}
