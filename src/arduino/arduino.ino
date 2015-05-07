int sensorValue[] = {0, 0, 0, 0, 0, 0};
int pin[] = {A0, A1, A2, A3, A4, A5};

void setup() {
	pinMode(12, OUTPUT);
	Serial.begin(9600);
	while(!Serial);
}

void loop() {
	for (int i=0; i<3; i++) {
		sensorValue[i] = analogRead(pin[i]);
		Serial.print(i);
		Serial.print(": ");
		Serial.println(sensorValue[i]);
	}
	digitalWrite(12, HIGH);
	Serial.println("HIGH");
	delay(10000);
	digitalWrite(12, LOW);
	Serial.println("LOW");
	delay(1000);
}
