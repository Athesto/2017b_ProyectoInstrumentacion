#include <EEPROM.h>
unsigned int address = 257;
unsigned long int running_time = 0;
unsigned long int time = 0;
int wait = 1e3;
void setup() {
  EEPROM.get(address, running_time);
  Serial.begin(115200);
  Serial.println("hello");




}

void loop() {
  if (millis() > time) {
    Serial.println(running_time);
    time += wait;
    running_time += wait;

    if ((running_time + 1) % 60) {

      EEPROM.put(address, running_time);
    }

  }
}
