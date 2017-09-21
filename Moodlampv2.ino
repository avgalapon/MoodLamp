// Arduino Project Series: MoodLamp
// Makerspace Pilipinas - The Mind Museum
// Author: Art Galapon
// Date: September 19, 2017

// Pins for RGB LED
int bluepin = 9;
int redpin = 10;
int greenpin = 11;

// Pins for Potentiometer
int potred = A0;
int potgreen = A1;
int potblue = A2;

// Pin for Switch
int switchpin = 12;

// Pin for Light-dependent Resistor (LDR)
int ldrpin = A4;

// Pin for Thermistor
int thermistorpin = A5;

// Variables for Value of Potentiometers
int redval;
int greenval;
int blueval;

// Variables to send to RGB LED
int redwrite;
int greenwrite;
int bluewrite;

// Variable for Status of Switch
int switchstate;

// Variable for Value of LDR
int ldrval;

void setup()
{
  Serial.begin(9600);

  pinMode(switchpin,INPUT);

  pinMode(potred,INPUT);
  pinMode(potgreen,INPUT);
  pinMode(potblue,INPUT);

  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(bluepin,OUTPUT);
}

void loop()
{
  ldrval = analogRead(ldrpin);
  switchstate = digitalRead(switchpin);
  float temp = getTemp();

  switch(switchstate)
  {
    case 0:
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

      break;
    }
    case 1:
    {
      if (ldrval > 80)
      {
        analogWrite(redpin,0);
        analogWrite(greenpin,0);
        analogWrite(bluepin,0);
      }
      else if (temp > 29)
      {
        analogWrite(redpin,200);
        analogWrite(greenpin,0);
        analogWrite(bluepin,0);
      }
      else if ((temp > 24) && (temp < 29))
      {
        analogWrite(redpin,0);
        analogWrite(greenpin,200);
        analogWrite(bluepin,0);
      }
      else if (temp < 25)
      {
        analogWrite(redpin,0);
        analogWrite(greenpin,0);
        analogWrite(bluepin,200);
      }
      delay(500);
      break;
    }
  }
}

float getTemp()
{
  int Vo = analogRead(thermistorpin);;
  float R1 = 10000;
  float logR2, R2, T;
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
  
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  //T = (T * 9.0)/ 5.0 + 32.0;
  return T;
}

