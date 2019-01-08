int IN1 = 7;
int IN2 = 8;
int IN3 = 9;
int IN4 =10;
int ENA_PWM = 3;
int ENB_PWM = 2;

void setup() {
	// The parameter 9600 is the baud rate of the serial communication channel.
	Serial.begin(9600);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(ENA_PWM, OUTPUT);
}

void loop() {
	digitalWrite(ENA_PWM, HIGH); //Enables the motor
  digitalWrite(ENB_PWM, HIGH); //Enables the motor
	motdrive(HIGH,LOW);
 Serial.println("Turning one way!");
  delay(500);
  motdrive(LOW,HIGH);
  Serial.println("Turning other way!");
  delay(500);
  digitalWrite(ENA_PWM, LOW); //Turns it off
  digitalWrite(ENB_PWM, LOW); //Enables the motor
  Serial.println("Turning off.");
  delay(500);
}

void motdrive(bool x, bool y) {
  digitalWrite(IN1, x); //Turns the motor one way
  digitalWrite(IN2, y);
  digitalWrite(IN3, x); //Turns the motor one way
  digitalWrite(IN4, y);
  
}

