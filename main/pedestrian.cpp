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

    // Turn lEDs off
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(white, LOW);
}

void loop()
{
    // Car Cycle
    int pressed = 0;
    // Green light
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    // Check button every 0.1 second
    for (int i = 1; i < 10; i++)
    {
        int stateB = digitalRead(btnPed);

        if (stateB == 0)
        {
            delay(100);
        }
        else if (stateB == 1)
        {
            pressed = 1;
            delay(100);
        }
    }
    // Yellow light
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    // Check button every 0.1 second
    for (int i = 1; i < 10; i++)
    {
        int stateB = digitalRead(btnPed);

        if (stateB == 0)
        {
            delay(100);
        }
        else if (stateB == 1)
        {
            pressed = 1;
            delay(100);
        }
    }
    // Red light
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    // Check button every 0.1 second
    if (pressed == 1)
    {
        digitalWrite(white, HIGH);
        delay(5000);
        digitalWrite(white, LOW);
        digitalWrite(red, LOW);
    }
    else
    {
        for (int i = 1; i < 10; i++)
        {
            int stateB = digitalRead(btnPed);

            if (stateB == 0)
            {
                delay(100);
            }
            else if (stateB == 1)
            {
                digitalWrite(white, HIGH);
                delay(5000);
                digitalWrite(white, LOW);
                digitalWrite(red, LOW);
                return;
            }
        }
    }
}
