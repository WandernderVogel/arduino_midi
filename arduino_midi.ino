//create values for button
int button1 = 2;//change Number to your used
int button1_val = 0;
int button1_val_p = 0;

int button2 = 3;//change Number to your used
int button2_val = 0;
int button2_val_p = 0;

void setup()
{
  Serial.begin(115200); // Initialize serial communication at 115200 bps
  // Serial.write("");
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop()
{
  button1_val = digitalRead(button1);
  button2_val = digitalRead(button2);
  if (button1_val == 1 && button_changed(button1_val, button1_val_p))
  {
    writeMidiNote(0x90, 0x0B, 127);
  }
  else if (button1_val == 0 && button_changed(button1_val, button1_val_p))
  {
    writeMidiNote(0x90, 11, 0);//byte1:Command+Channel, byte2:Note, byte3: Value(If nothing there defaults to 0)
  }
  if (button2_val == 1 && button_changed(button2_val, button2_val_p))
  {
    writeMidiNote(0x91, 0x00, 0);
  }
  button1_val_p = button1_val;
  button2_val_p = button2_val;
  delay(10);
}

// code for sending midi data to ttymidi midi bridge
void writeMidiNote(uint8_t satus, uint8_t param1, uint8_t param2 = 0)
{
  Serial.write(satus);
  Serial.write(param1);
  Serial.write(param2);
}

// func for only once firing function on btn press
bool button_changed(int val, int prev_val)
{
  return (!val == prev_val);
}
