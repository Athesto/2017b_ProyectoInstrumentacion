#define cell 3
#define extractor 5
#define fan 6
double val;
void setup() {
  //Serial.begin(115200);
  //Serial.println("Arduino");

}

void loop() {
  //val= analogRead(A1);
  val += 0.01;
  if (val>1) val = 0;
  //Serial.println(val*100);
  analogWrite(cell,val*255);
  analogWrite(extractor,val*255);
  analogWrite(fan,val*255);
  delay(50);

}
