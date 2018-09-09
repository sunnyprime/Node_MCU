int analog= A0;
int digital=2;
int A=0;
int D=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //pinMode(digital,INPUT_PULLUP);
//  pinMode(analog,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  D=analogRead(analog);
  A=digitalRead(digital);
  Serial.print("Analog input: ");
  Serial.print(A);
  Serial.print("\t Digital input: ");
  Serial.println(D);
  delay(2000);
}
