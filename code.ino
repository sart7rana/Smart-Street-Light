#define irSensorOne 2
#define irSensorTwo 3
#define ledOne 9
#define ledTwo 10

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(irSensorOne, INPUT);
  pinMode(irSensorTwo, INPUT);

  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
}

void loop() {
  if (analogRead(A0) >= 150) {
    digitalWrite(ledOne, LOW);
    digitalWrite(ledTwo, LOW);
    Serial.println("It's Bright Outside; Lights status: OFF");
  } else {
    if (digitalRead(irSensorOne) == HIGH) {
      analogWrite(ledOne, 40);
    } else {
      analogWrite(ledOne, 255);
      Serial.println("IR sensor 1 is detecting an object; LED1 Lights status: ON");
    }
    if (digitalRead(irSensorTwo) == HIGH) {
      analogWrite(ledTwo, 40);

    } else {
      analogWrite(ledTwo, 255);
      Serial.println("IR sensor 2 is detecting an object; LED2 Lights status: ON");
    }
  }
  delay(50);
}
