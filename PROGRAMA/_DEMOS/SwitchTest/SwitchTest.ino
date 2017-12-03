#define MODE 9
#define UP 8
#define DOWN 7
void setup() {
  Serial.begin(115200);
pinMode(MODE,INPUT_PULLUP);
pinMode(UP,INPUT_PULLUP);
pinMode(DOWN,INPUT_PULLUP);
}

void loop() {
  Serial.print(digitalRead(MODE));Serial.print(',');
  Serial.print(digitalRead(UP));Serial.print(',');
  Serial.print(digitalRead(DOWN));Serial.print(',');
  Serial.println();
  delay(100);

}
