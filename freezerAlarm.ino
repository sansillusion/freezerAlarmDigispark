const int leson = 0;
const int laide = 1;
const int aimant = 2;
unsigned long previousMillis = 0;
unsigned long previousMillison = 0;
const long interval = 300000; // interval pour les leds en ms
const long intervalson = 600000; // interval pour le son en ms


void setup() {
  pinMode(laide, OUTPUT);
  pinMode(leson, OUTPUT);
  pinMode(aimant, INPUT);
  digitalWrite(laide, LOW);
  digitalWrite(leson, LOW);
}

void loop() {
  unsigned long currentMillis = millis();
  while (digitalRead(aimant) == LOW) {
    currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      digitalWrite(laide, HIGH);
    }
    currentMillis = millis();
    if (currentMillis - previousMillison >= intervalson) {
      digitalWrite(leson, HIGH);
      delay(200);
      digitalWrite(leson, LOW);
      delay(300);
      digitalWrite(leson, HIGH);
      delay(200);
      digitalWrite(leson, LOW);
      delay(400);
      digitalWrite(leson, HIGH);
      delay(500);
      digitalWrite(leson, LOW);
      delay(500);
      digitalWrite(leson, HIGH);
      delay(100);
      digitalWrite(leson, LOW);
      delay(100);
      digitalWrite(leson, HIGH);
      delay(150);
      digitalWrite(leson, LOW);
      delay(150);
      digitalWrite(leson, HIGH);
      delay(120);
      digitalWrite(leson, LOW);
      delay(720);
    }
  }
  digitalWrite(laide, LOW);
  previousMillis = currentMillis;
  previousMillison = currentMillis;
}

