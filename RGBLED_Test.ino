int greenpin = 11; //digital pin for red LED
int redpin = 10; //digital pin for blue LED
int bluepin = 9; //digital pin for green LED

void setup()
{
  Serial.begin(9600); //establish communication with the Serial Monitor
  
  pinMode(redpin,OUTPUT); //declares the pin as an output pin
  pinMode(bluepin,OUTPUT);
  pinMode(greenpin,OUTPUT);
}

void loop()
{
  analogWrite(redpin,255); //analogwrite sets a value from 0-255 which is equivalent to 0-5V
  analogWrite(bluepin,0);
  analogWrite(greenpin,0);
}

