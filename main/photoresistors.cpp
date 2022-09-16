//includes servo library
#include <Servo.h>
//declare variables
int pos = 0;
//Analog pins for range of values from 0 to 1023
const int LPR = A0; //output of left photores in analog 0 pin
const int RPR = A1; // output of right photores in analog 1 pin
Servo servo_9; //name of servo to call it in future functions
// store photores value
int left = 0; 
int right = 0;
//setup servo
void setup()
{
    servo_9.attach(9, 500, 2500); //which pin, min and max angle.
}

void loop()
{
    // read photores values -> variables
    left = analogRead(LPR);
    right = analogRead(RPR);

    // checks if left greater than right, if so move left

    if (left > (right + 20)) //+20 is the deadzone, so it won't jiggle back and forth.
    {
        if (pos < 179)
            pos = pos + 6; //increase in deg per tick
        servo_9.write(pos);
    }
    // checks if right greater than left, if so move right
    else if (right > (left + 20))
    {
        if (pos > 1)
            pos = pos - 6; //decrease in deg per tick
        servo_9.write(pos);
    }
    // control deg/ms speed
    delay(1000);
}
