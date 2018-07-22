#include <Arduino.h>

int xAxisPin = A0;
int yAxisPin = A1;
int zAxisPin = A2;

//Variables to hold the returned
//ADC data from the analog input
//pins
int xAxisValADC = 0;
int yAxisValADC = 0;
int zAxisValADC = 0;

//Arduino Uno with a 10-bit resolution (max output value = 1023)
const int ADCMaxVal = 1023;

//The AD converter voltage, measured with a voltage meter in mV
const float VREF = 3300;

int run = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  //analogReference(EXTERNAL);
  pinMode(xAxisPin, INPUT);
  pinMode(yAxisPin, INPUT);
  pinMode(zAxisPin, INPUT);
}

void loop()
{
  //Read the x, y, and z values from
  //the analog input pins and hold them
  xAxisValADC = analogRead(xAxisPin);
  yAxisValADC = analogRead(yAxisPin);
  zAxisValADC = analogRead(zAxisPin);
  Serial.print("Gravitation run ");
  Serial.print(++run);
  if (run == 65535)
  {
    run = 0;
  }
  Serial.print("\tx: ");
  Serial.print(xAxisValADC);
  Serial.print("\t");
  Serial.print(float(xAxisValADC * 0.0144 - 4.86));
  Serial.print("g");

  Serial.print("\ty: ");
  Serial.print(yAxisValADC);
  Serial.print("\t");
  Serial.print(float(yAxisValADC * 0.0143 - 4.89));
  Serial.print("g");

  Serial.print("\tz: ");
  Serial.print(zAxisValADC);
  Serial.print("\t");
  Serial.print(float(zAxisValADC * 0.0145 - 5.25));
  Serial.print("g");
  Serial.println();
  delay(2000);
}
