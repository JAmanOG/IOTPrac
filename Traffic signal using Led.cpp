#Code
int led_red = 0;
int led_yellow = 1; 
int led_green = 2;
void setup() {
 pinMode(led_red, OUTPUT);
 pinMode(led_yellow, OUTPUT);
 pinMode(led_green, OUTPUT);
}
void loop() {
// turn the green LED on and the other LEDs off
digitalWrite(led_red, LOW);
digitalWrite(led_yellow, LOW);
digitalWrite(led_green, HIGH);
delay(2000); // wait 2 seconds

// turn the yellow LED on and the other LEDs off
digitalWrite(led_red, LOW);
digitalWrite(led_yellow, HIGH);
digitalWrite(led_green, LOW);
delay(1000); // wait 1 second

// turn the red LED on and the other LEDs off
digitalWrite(led_red, HIGH);
digitalWrite(led_yellow, LOW);
digitalWrite(led_green, LOW);
delay(3000);
}

Practical Link
https://www.tinkercad.com/things/lGxVTIGZqNq-traffic-signal-using-led?sharecode=WZQMZGZtzIOctYzIep72zUqgq7L6U7376nh8MggJFNc
