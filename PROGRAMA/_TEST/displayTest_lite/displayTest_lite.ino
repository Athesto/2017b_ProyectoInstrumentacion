#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Para definir las placas sin reset, se inicializa con -1
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

//Para la corroborar la librería
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int x = 0;
int size = 1;
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

  //trabaja parecido al lcd, solo que se incluye el tamaño y el color de fuente
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

}

void loop() {
  //example1();
  example2(1e3);
}




void example2(int wait) {
  char buff[32];
  int x = 0;
  unsigned long time = 0;
  display.clearDisplay();
  display.print("hello");
  display.display();

  while (1) {
    if (millis()>= time) {
      time = millis() + wait;
      display.clearDisplay();
      display.setCursor(0, 0);
      sprintf(buff, "Time:%u \n" , (x += 1) %= 999);
      display.print(buff);
      display.display();
    }

  }
}

void example1() {
  while (1) {
    display.print(char((x += 1) + 30));
    display.display();
    if (x == 128) {

      display.clearDisplay();
      (size += 1) %= 10;
      display.setTextSize(1);
      display.setTextColor(BLACK, WHITE);
      display.setCursor(display.width() - 8, display.height() - 8);
      display.print(size);
      display.setTextColor(WHITE);
      display.setTextSize(size);
      display.setCursor(0, 0);
      x = 0;
    }
    delay(100);
  }

}
