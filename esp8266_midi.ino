// Code for Wemos D1 mini

// Variables
int button1 = D1; // change Number to your used
int button1_val = 0;
int button1_val_p = 0;

int button2 = D2; // change Number to your used
int button2_val = 0;
int button2_val_p = 0;

void setup()
{
    Serial.begin(115200);
    Serial.println("");
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
}

// status:Command+Channel, param1:Note, param2: Value(If nothing there defaults to 0)
void sendMidi(uint8_t status, uint8_t param1, uint8_t param2 = 0)
{
    Serial.write(status);
    Serial.write(param1);
    Serial.write(param2);
}

bool buttonPressed(int now, int previous)
{
    return (!now == previous);
}

void loop()
{
    button1_val = digitalRead(button1);
    button2_val = digitalRead(button2);
    if (button1_val == 1 && buttonPressed(button1_val, button1_val_p))
    {
        sendMidi(0x90, 0x0B, 127);
    }
    else if (button1_val == 0 && buttonPressed(button1_val, button1_val_p))
    {
        sendMidi(0x90, 0x0B, 0);
    }
    if (button2_val == 1 && buttonPressed(button2_val, button2_val_p))
    {
        sendMidi(0x90, 0x0C, 127);
    }
    else if (button2_val == 0 && buttonPressed(button2_val, button2_val_p))
    {
        sendMidi(0x90, 0x0C, 0);
    }
    delay(100);
    button1_val_p = button1_val;
    button2_val_p = button2_val;
}
