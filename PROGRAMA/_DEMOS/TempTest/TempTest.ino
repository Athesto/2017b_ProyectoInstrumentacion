// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"

int thermoCLK = 13;
int thermoDO = 12;
int thermoCS = 10;





MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(115200);
  // use Arduino pins 

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
  
   Serial.print("C = "); 
   Serial.print(thermocouple.readCelsius());
   Serial.print(",F = ");
   Serial.println(thermocouple.readFahrenheit());
 
   delay(500);
}
