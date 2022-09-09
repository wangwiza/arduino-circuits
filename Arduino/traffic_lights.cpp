// declare LEDs
int green = 4;
int yellow = 5;
int red = 6;
int white = 7;

// declare button
int btnPed = 9;

void setup()
{
    // Inputs, outputs
    pinMode(green, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(red, OUTPUT);
    pinMode(white, OUTPUT);
    pinMode(btnPed, INPUT);

    // configure LEDs
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(white, LOW);
}

void loop()
{

}

