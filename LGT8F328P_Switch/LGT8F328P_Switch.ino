void setup() {
  pinMode(3, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

boolean SW = false;

void loop() {
  if (digitalRead(3) == LOW && SW == false) {
    SW = true;
    digitalWrite(13, HIGH);
    delay(75);
    digitalWrite(13, LOW);
  }
  if (digitalRead(3) == HIGH && SW == true) {
    SW = false;
    delay(50);
  }
}
