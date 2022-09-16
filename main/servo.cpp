// C++ code
//include servo library
#include <Servo.h>

int Position = 0;
Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);

}

void loop()
{
  Position = 0;
  for (Position = 1; Position <= 179; Position += 1) {
    servo_9.write(Position);
    delay(20); // Wait for 20 millisecond(s)
  }
  for (Position = 179; Position >= 1; Position -= 1) {
    servo_9.write(Position);
    delay(20); // Wait for 20 millisecond(s)
  }
}