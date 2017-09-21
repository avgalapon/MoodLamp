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

int switchpin = 12; //digital pin for he switch
int switchstate; //variable to check for status of switch

int ldrpin = A4; //analog pin for the light-dependent resistor
int ldrval; //variable for the LDR value. Ranges from 0-1024

void setup()
{
  Serial.begin(9600); //establish communication with the Serial Monitor
  
  pinMode(redpin,OUTPUT); //declares the pin as an output pin
  pinMode(bluepin,OUTPUT);
  pinMode(greenpin,OUTPUT);

  pinMode(switchpin, INPUT); //sets the pin as an input

  pinMode(potred,INPUT); //declares the pins as INPUT pins
  pinMode(potgreen,INPUT);
  pinMode(potblue,INPUT);
}

void loop()
{
  ldrval = analogRead(ldrpin);
  Serial.println(ldrval);
  Serial.println(getTemp());
  
   if (ldrval > 80)
   {
    analogWrite(redpin,0);
    analogWrite(greenpin,0);
    analogWrite(bluepin,0);
   }
   else if (getTemp() > 36)
   {
    analogWrite(redpin,200);
    analogWrite(greenpin,0);
    analogWrite(bluepin,0);
   }
   else if ((getTemp() > 29) && (getTemp() < 36))
   {
    analogWrite(redpin,0);
    analogWrite(greenpin,200);
    analogWrite(bluepin,0);
   }
   else if (getTemp() < 30)
   {
    analogWrite(redpin,0);
    analogWrite(greenpin,0);
    analogWrite(bluepin,200);
   }

   delay(500);
}

float getTemp()
{
  int ThermistorPin = A5;
  int Vo;
  float R1 = 10000;
  float logR2, R2, T;
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  //T = (T * 9.0)/ 5.0 + 32.0;
  return T;
}

