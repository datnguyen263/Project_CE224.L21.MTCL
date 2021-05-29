#include <Arduino.h>

#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 2

int green = 9;
int blue = 10;
int red  = 11;
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);
}
 
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  redfrequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  redfrequency = map(redfrequency, 25,72,255,0);
  if (redfrequency > 255)
  {
      redfrequency = 255;  
  }  
   else if (redfrequency < 0)
  {
      redfrequency = 0;  
  }
  // Printing the value on the Serial monitor
  Serial.print("R ");//printing name
  Serial.print(redfrequency);//printing RED color frequency
  analogWrite(red, redfrequency);
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  greenfrequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  greenfrequency = map(greenfrequency, 30,90,255,0);
  if (greenfrequency > 255)
  {
      greenfrequency = 255;  
  }  
  else if (greenfrequency < 0)
  {
      greenfrequency = 0;  
  }  
  // Printing the value on the Serial monitor
  Serial.print(" G ");//printing name
  Serial.print(greenfrequency);//printing GREEN color frequency
  analogWrite(green, greenfrequency);
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  bluefrequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  bluefrequency = map(bluefrequency, 25,70,255,0);
  if (bluefrequency > 255)
  {
      bluefrequency = 255;  
  }  
   else if (bluefrequency < 0)
  {
      bluefrequency = 0;  
  }  
  // Printing the value on the Serial monitor
  Serial.print(" B ");//printing name
  Serial.print(bluefrequency);//printing BLUE color frequency
  analogWrite(blue, bluefrequency);
  Serial.println("  ");
  delay(100);
}