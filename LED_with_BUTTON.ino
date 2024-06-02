//Led control with button

const int LED=9;    //The LED is connected to pin 9
const int BUTTON=2; //The button is connected to pin 2

void setup()
{
  pinMode (LED, OUTPUT);    //The LED is set as output
  pinMode (BUTTON, INPUT);  //Set Button as input
}

void loop()
{
  if (digitalRead(BUTTON) == LOW)
  {
    digitalWrite(LED, LOW);
  }
  else
  {
    digitalWrite(LED, HIGH);
    }
}
