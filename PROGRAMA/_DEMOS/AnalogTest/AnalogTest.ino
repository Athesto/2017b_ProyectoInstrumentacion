int val;
void setup() {
  //Serial.begin(115200);
  //Serial.println("Arduino");

}

void loop() {
  val= analogRead(A1);
  //Serial.println(val);
  analogWrite(3,val/4);
  

}
