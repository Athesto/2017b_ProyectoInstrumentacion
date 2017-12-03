#include "max6675.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define cell 3
#define extractor 5
#define fan 6

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);
uint8_t x = 0;
String buff = "";
unsigned long time = 0;
double temperature;
int thermoCLK = 13;
int thermoDO = 12;
int thermoCS = 10;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  //Serial.begin(115200);
  delay(500);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  //trabaja parecido al lcd, solo que se incluye el tamaño y el color de fuente
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("proyect \nTempControl");
  display.display();
}

void loop() {

  if (millis() >= time) {
    time = millis() + 1e3;

    analogWrite(cell,255);
    analogWrite(extractor,255);
    analogWrite(fan,255);

    
    display.clearDisplay();
    display.setCursor(0, 0);
    temperature = thermocouple.readCelsius();
    
    buff += "Counter: " + String(x++) +"\n";
    buff += "Temp: "+ String(temperature)+char(167)+"C\n";
    //Serial.println(buff);
    display.print(buff);
    display.display();
    buff = "";
  }
}
