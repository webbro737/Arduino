//Led control with button

const int LED=9;    //The LED is connected to pin 9
const int BUTTON=2; //The button is connected to pin 2
boolean lastButton = LOW; //Variable containing the previous button state
boolean currentButton = LOW;  //Variable containing the current button state
boolean ledOn = false;  //The present state of the LED

void setup()
{
  pinMode (LED, OUTPUT);    //The LED is set as output
  pinMode (BUTTON, INPUT);  //Set Button as input
}
/*
 * Debouncing function, Pass it the previous button state,
 * and get it back the current debounced button state.
 */
boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);
  if (last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
    return current;
  }
}
void loop()
{
  currentButton = debounce(lastButton);
  if (lastButton ==LOW && currentButton == HIGH)
  {
    ledOn = !ledOn;
  }
  lastButton = currentButton;

  digitalWrite(LED, ledOn);
}
