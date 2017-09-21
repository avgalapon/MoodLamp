int greenpin = 11; //digital pin for red LED
int redpin = 10; //digital pin for blue LED
int bluepin = 9; //digital pin for green LED

int potred = A0; //analog pin for potentiometer
int potgreen = A1;
int potblue = A2;

int redval; //variable to store the value of potentiometer
int greenval;
int blueval;

int redwrite; //variable to send to the RGB LED
int greenwrite;
int bluewrite;

void setup()
{
  Serial.begin(9600);
  
  pinMode(redpin,OUTPUT); //declares the pins as OUTPUT pins
  pinMode(bluepin,OUTPUT);
  pinMode(greenpin,OUTPUT);

  pinMode(potred,INPUT); //declares the pins as INPUT pins
  pinMode(potgreen,INPUT);
  pinMode(potblue,INPUT);
}

void loop()
{
  redval = analogRead(potred); //reads the value of each potentiometer; value range from 0-1024
  greenval = analogRead(potgreen);
  blueval = analogRead(potblue);

  redwrite = (255./1023.)*redval; //converts the value to a 255 range since RGB value range from 0-255 only
  bluewrite = (255./1023.)*blueval;
  greenwrite = (255./1023.)*greenval;

  analogWrite(redpin,redwrite); //writes a value from 0-255
  analogWrite(greenpin,greenwrite);
  analogWrite(bluepin,bluewrite);
}

