int analog= 17;
int A=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  A=analogRead(analog);
  Serial.print("Analog input:");
  Serial.println(A);
  delay(2000);
}
