int ledLight1 = 13;
int ledLight2 = 12;
void setup()
{
 pinMode(ledLight1, OUTPUT);
 pinMode(ledLight2, OUTPUT);
}
void loop()
{
 digitalWrite(ledLight1, HIGH);
 digitalWrite(ledLight2, HIGH);
 delay(1000); // Wait for 1000 millisecond(s)
 digitalWrite(ledLight1, LOW);
 digitalWrite(ledLight2, LOW);
 delay(1000); // Wait for 1000 millisecond(s)
}


Practical Link
https://www.tinkercad.com/things/fv9T614VlUH-light-two-led-using-breadboard?sharecode=at06qRULsRWFm6x1jcUDeSfRnNhZl2rimGTrlANHidc
