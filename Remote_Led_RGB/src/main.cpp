#include <Arduino.h>
#include <TCS3200.h>

// TCS3200::TCS3200(uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t OUT)
TCS3200 sensor;

// Declare pin rgb
int green = 9;
int blue = 10;
int red = 11; 
void setup() {
  // put your setup code here, to run once:
  // Set pin mode
  sensor.begin();

  // set Frequency-scaling to 20% 
  // 0: 100% prescaler
  // 1: 20% prescaler
  // 2: 2% prescaler
  // 3: Power dowm
  digitalWrite(sensor._S0,HIGH);
  digitalWrite(sensor._S1,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.setred();
  // Printing the value on the Serial monitor
  Serial.print("Red ");//printing name
  Serial.print(sensor.redfrequency);//printing RED color frequency
  analogWrite(red, sensor.redfrequency);
  delay(100);

  sensor.setgreen();
  // Printing the value on the Serial monitor
  Serial.print(" Green ");//printing name
  Serial.print(sensor.greenfrequency);//printing GREEN color frequency
  analogWrite(green, sensor.greenfrequency);
  delay(100);

  sensor.setblue();
  // Printing the value on the Serial monitor
  Serial.print(" Blue ");//printing name
  Serial.print(sensor.bluefrequency);//printing BLUE color frequency
  analogWrite(blue, sensor.bluefrequency);
  Serial.println("  ");
  delay(1000);
}