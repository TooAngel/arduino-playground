int sensorValue[] = {0, 0, 0, 0, 0, 0};
int pin[] = {A0, A1, A2, A3, A4, A5};

void setup() {
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
	delay(10000);
}
