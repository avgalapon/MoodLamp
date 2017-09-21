int switchpin = 12; //digital pin for he switch
int switchstate; //variable to check for status of switch

void setup()
{
  Serial.begin(9600);
  pinMode(switchpin, INPUT); //sets the pin as an input
}

void loop()
{
  switchstate = digitalRead(switchpin); //reads whether the pin is on (5V) or Off (0V)
  Serial.println(switchstate); //prints the value of switchstate in the Serial Monitor
}

