int buttonState = 1;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    delay(200);
    buttonState = (buttonState == 1) ? 2 : 1;

    if (buttonState == 1) {
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
    }
  } else if (buttonState == 2) {
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    delay(500);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    delay(500);
  }
}