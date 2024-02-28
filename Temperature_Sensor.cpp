//Code
const int sensorPin = A0;      // Analog pin for temperature sensor
const float supplyVoltage = 5.0;  // Supply voltage in volts

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int reading = analogRead(sensorPin); // Read analog input

  // Convert analog reading to voltage
  float voltage = reading * (supplyVoltage / 1024.0);

  // Convert voltage to temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100.0;

  // Convert temperature to Fahrenheit
  float fahrenheit = temperatureC * 9.0 / 5.0 + 32.0;

  // Print temperature in Celsius and Fahrenheit
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" degrees Celsius, ");
  Serial.print(fahrenheit);
  Serial.println(" degrees Fahrenheit");

  delay(1000); // Delay for readability
}

Practical link
https://www.tinkercad.com/things/19a8rr02poO-temperature-sensor?sharecode=1RSJY9N_ID5dOVTO0v_nzSJoBfTtkKmLwgQlDtCnBqU
