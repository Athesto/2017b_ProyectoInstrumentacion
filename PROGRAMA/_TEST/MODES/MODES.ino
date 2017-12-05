// #include LCDPeltier2017
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
//-------------------------------------------



//include INPUTPeltier2017
#define cell 3
#define extractor 5
#define fan 6

#define MODE 9
#define UP 8
#define DOWN 7
//-------------------------------------------


//include MAXPeltier2017

#include "max6675.h"

#define thermoCLK  13
#define thermoDO 12
#define thermoCS 10
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

//-------------------------------------------


//include Timer
unsigned long time;
//----------------------------------------

char page[128];
char mode[8] = "set";
int T;
int setPoint;
int tolerance = 1;



void setup() {
  //Begin display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  //SET inputs
  pinMode(MODE, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);

  //SET OUTPUT
  pinMode(cell, OUTPUT);
  pinMode(extractor, OUTPUT);
  pinMode(fan, OUTPUT);

  //SET Temperature
  delay(500);
  T = (int)thermocouple.readCelsius();
  setPoint = T;

  //Print Page
  sprintf(page, "MODE: %s \nT: %d \nset: %d " , mode, T, setPoint);
  display.print(page);
  display.display();

  //Timer
  time = millis() + 500;
}

void loop() {
  //read Temperature
  if (millis() > time) {
    time += 500;
    T = (int)thermocouple.readCelsius();
  }





  if (!digitalRead(DOWN)) {
    delay(100);
    setPoint--;
    display.clearDisplay();
    display.setCursor(0, 0);
    sprintf(page, "MODE: %s \nT: %d \nset: %d " , mode, T, setPoint);
    display.print(page);
    display.display();
    digitalWrite(fan, HIGH);
  }

  if (!digitalRead(UP)) {
    delay(100);
    setPoint++;
    display.clearDisplay();
    display.setCursor(0, 0);
    sprintf(page, "MODE: %s \nT: %d \nset: %d " , mode, T, setPoint);
    display.print(page);
    display.display();
    digitalWrite(fan, HIGH);
  }

  if (T > setPoint - tolerance) {
    //Se enfria
    //se prende la celda y los dos disipadores CELL, fan, Extractor
    digitalWrite(cell, HIGH);
    digitalWrite(extractor, HIGH);
    digitalWrite(fan, HIGH);

  } else {
    //Se apagan
    digitalWrite(cell, LOW);
    digitalWrite(extractor, LOW);
    digitalWrite(fan, LOW);
  }



}
