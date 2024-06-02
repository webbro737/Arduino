  
  
// Toggling LED nightlight 

const int BLED=11;      // Blue LED on pin 11
const int GLED=10;      // Green LED on pin 10
const int RLED=9;       // Red LED on pin 9
const int BUTTON=2;     // Button on pin 2

boolean lastButton = LOW;     // Last button state
boolean currentButton = LOW;  // Current button state
int ledMode = 0;        // Cycle between LED states

void setup()
{
  pinMode (BLED, OUTPUT);   // Set blue LED as output
  pinMode (GLED, OUTPUT);   // Set green LED as output
  pinMode (RLED, OUTPUT);   // Set red LED as output
  pinMode (BUTTON, INPUT);  // Set button as input
}

// Debouncing function, pass it the previous button state, get back the current button state

boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);  //Read the button state
  if (last != current)    // If it is different
  {
    delay(5);   // Wait 5ms
    current = digitalRead(BUTTON);  // Read it again
  }
  return current;   // Return the current value
}

// LED mode selection, pass a number for the LED state, and set it accordingly

void setMode(int mode)
{
  // RED
  if (mode == 1)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }

  // GREEN
  if (mode == 2)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  
  // BLUE
  if (mode == 3)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  
  // PURPLE (RED+BLUE)
  if (mode == 4)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 0);
    analogWrite(BLED, 127);
  }

  // TEAL (BLUE+GREEN)
  if (mode == 5)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  }
  
  // ORANGE (GREEN+RED)
  if (mode == 6)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 0);
  }
  
  // WHITE (BLUE+GREEN+RED)
  if (mode == 7)
  {
    analogWrite(RLED, 85);
    analogWrite(GLED, 85);
    analogWrite(BLED, 85);
  }
  
  // OFF (MODE=0)
  else
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
}

void loop()
{
  currentButton = debounce(lastButton);     // Read debounced state
  if (lastButton == LOW && currentButton == HIGH)  // If it was pressed
  {
    ledMode++;    // Increment LED value
  }
  lastButton = currentButton;   // Reset button value
  // If you've cycled through the different modes, reset the counter to 0
  if (ledMode == 8) ledMode = 0;
  setMode(ledMode);     // change the led status
}
