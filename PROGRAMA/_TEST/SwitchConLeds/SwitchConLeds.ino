#define cell 3
#define extractor 5
#define fan 6

#define MODE 9
#define UP 8
#define DOWN 7

int var;
bool led = false;
unsigned long timer;
int wait = 1e3;

void setup() {
  pinMode(cell, OUTPUT);
  pinMode(extractor, OUTPUT);
  pinMode(fan, OUTPUT);

  pinMode(MODE, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  timer = millis() + wait;

}

void loop() {


  if (!digitalRead(MODE)) {
    digitalWrite(cell, HIGH);
  } else {
    digitalWrite(cell, led);
  }
  if (!digitalRead(UP)) {
    digitalWrite(extractor, HIGH);
  } else {
    digitalWrite(extractor, led);
  }
  if (!digitalRead(DOWN)) {
    digitalWrite(fan, HIGH);
  } else {
    digitalWrite(fan, led);
  }

  if (millis() > timer) {
    timer += wait;
    led = !led;
    digitalWrite(extractor, led);

  }

}
