const int buttonPin = 0;        // D2 WEMOS
int buttonState = false;         // True = on / False = off

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  LIGHTOFF();
}

void LIGHTON()
{
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED ON, BUTTON ON");
}
void LIGHTOFF()
{
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED OFF, BUTTON OFF");
}

void loop() {
  if (digitalRead(buttonPin) == LOW) //Pressed  
  {
    delay(200); //elimates button spam on press
    
    //Toggle Button State
    if (buttonState == true)
    {
      buttonState = false;
    } else {
      buttonState = true;
    }
    
    //REPORT BUTTON STATE
    if (buttonState == true) // Buttom is ON
    {
      LIGHTON();
    }
    else
    {
      LIGHTOFF();
    }
  }
}
