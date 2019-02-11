const int buttonPin = 0;        // D2 WEMOS
int buttonState = false;         // True = on / False = off
int oldButtonState = false;

void ToggleButtonState()
{
 if (buttonState == true) {
     buttonState = false;
     digitalWrite(LED_BUILTIN, HIGH);
 } else {
    buttonState = true;
    digitalWrite(LED_BUILTIN, LOW);
 }
}

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(buttonPin), ToggleButtonState, RISING);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

int maxLoop = 75;
int loopCount;
void loop() {

  Serial.print(".");
  if (++loopCount > maxLoop) {
     loopCount=0;
     Serial.println();
  }

  if (oldButtonState != buttonState) {
     oldButtonState = buttonState;
     Serial.println();
     Serial.println(buttonState);
     delay(1000); 
  }
}
