#include <Servo.h>
// declare joystick
const int VRX = A0; // horizontal and vertical => range of values => analog
const int VRY = A1;
const int SW = 2; // joystick button => not range of value => digital
// joystick values (will be read)
int x_joy; // to store joystick input
int y_joy;
int sw_state = 1; // unpressed switch = HIGH state
// declare LEDs
const int white = 4;
const int red = 5;
const int yellow = 6;
const int green = 7;
// servo
Servo servox;
const int servoxPin = 9; // if I had enough servos and wires, I'd have a servoy too...
int pos = 90;            // doesn't really matter but...oh well

void setup()
{
    // LED
    pinMode(green, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(red, OUTPUT);
    pinMode(white, OUTPUT);
    // Joystick
    pinMode(VRX, INPUT);
    pinMode(VRY, INPUT);
    pinMode(SW, INPUT);
    digitalWrite(SW, HIGH); // joystick button will be HIGH, and LOW when pressed.
    // Servo
    pinMode(servoxPin, OUTPUT);
    servox.attach(9, 500, 2500); // attach(pin, min, max)
}

void loop()
{
    // read joystick input from analog pins/digital pin -> variables
    x_joy = analogRead(VRX); // values from 0 to 1023
    y_joy = analogRead(VRY);
    sw_state = digitalRead(SW); // HIGH or LOW
    if (!sw_state)              // if button ISN'T HIGH = if button is LOW = if button is pressed
    {
        for (int i = 0; i < 4; i++) // for loop, for 4 flashes
        {
            digitalWrite(white, HIGH);
            digitalWrite(red, HIGH);
            digitalWrite(yellow, HIGH);
            digitalWrite(green, HIGH);
            delay(200);
            digitalWrite(white, LOW);
            digitalWrite(red, LOW);
            digitalWrite(yellow, LOW);
            digitalWrite(green, LOW);
            delay(200);
        }
    }
    else // if button isn't isn't high = if button is HIGH = if button isn't pressed
    {
        // directional LED joystick controls
        if (x_joy < 300) // if joystick tilts toward left, light left/green LED
        {
            digitalWrite(green, HIGH);
            digitalWrite(red, LOW);
        }
        else if (x_joy > 700) // if joystick tilts right, light right/red LED
        {
            digitalWrite(red, HIGH);
            digitalWrite(green, LOW);
        }
        else // horizontal deadzone -> turn "horizontal" LEDs off
        {
            digitalWrite(red, LOW);
            digitalWrite(green, LOW);
        }

        if (y_joy < 300) // if joystick tilts upward, light up/white LED
        {
            digitalWrite(white, HIGH);
            digitalWrite(yellow, LOW);
        }
        else if (y_joy > 700) // if joystick tilts downward, light down/yellow LED
        {
            digitalWrite(yellow, HIGH);
            digitalWrite(white, LOW);
        }
        else // vertical deadzone -> turn "vertical" LEDs off
        {
            digitalWrite(white, LOW);
            digitalWrite(yellow, LOW);
        }
    }
    // horizontal servo indicator
    x_joy = map(x_joy, 0, 1023, 0, 180); // convert joystick analog values to degrees
    servox.write(x_joy);                 // make servo indicate which direction joystick is moving in.
}