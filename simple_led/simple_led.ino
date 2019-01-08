// LED connected to digital pin 13
int ledPin = 13;

void setup() {
	// Sets digital pin as output
	pinMode(ledPin, OUTPUT);
}

void loop() {
	// Turns the LED on
	digitalWrite(ledPin, HIGH);
	// Waits for a second
	delay(1000);
	// Turns the LED off
	digitalWrite(ledPin, LOW);
	// Waits for a second
	delay(1000);
}