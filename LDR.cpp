//Code
const int ledPin = 10;
const int ldrPin = A0;
void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(ldrPin, INPUT);
}
void loop() {
int ldrStatus = analogRead(ldrPin);
Serial.println(ldrStatus);
if (ldrStatus <=400) {
digitalWrite(ledPin, HIGH);
  }
else {
digitalWrite(ledPin, LOW);
} }

//Practical Link
https://www.tinkercad.com/things/l4genASUki3-ldr?sharecode=qLI7ig5tpc4CgVOrgg4RU1bMwEDOsh74M_m2bs3j_Uw
