const int leson = 5;
const int aimant = 7;
int rouge = 0;
int vert = 0;
int bleu = 0;
const int pinrouge = 6;
const int pinverte = 9;
const int pinbleu = 10;
long r = 0;
long g = 0;
long b = 0;
unsigned long previousMillisr = 0;
unsigned long previousMillisg = 0;
unsigned long previousMillisb = 0;
int attendR = 40;
int attendG = 45;
int attendB = 50;
unsigned long previousMillisf = 0;
int attendF = 700;
unsigned long flashfois = 0;
unsigned long flashrendu = 0;
int faitdubruit = 0;
int bruit = 0;

int lerouge = 255;
int levert = 255;
int lebleu = 255;
unsigned long previousMillis = 0;
unsigned long previousMillison = 0;
long interval = 500; // interval pour les leds en ms
const long intervalson = 300000; // interval pour le son en ms

void flashfunk() {
  if (flashrendu < flashfois) {
    flashrendu++;
    if (bruit == 1) {
      digitalWrite(leson, LOW);
      bruit = 0;
    } else {
      digitalWrite(leson, HIGH);
      bruit = 1;
    }
  } else {
    bruit = 0;
    digitalWrite(leson, LOW);
    faitdubruit = 0;
    flashrendu = 0;
  }
}

void fadeR() {
  if (rouge < r) {
    rouge++;
    analogWrite(pinrouge, rouge);
  } else if (rouge > r) {
    rouge--;
    analogWrite(pinrouge, rouge);
  }
}

void fadeG() {
  if (vert < g) {
    vert++;
    analogWrite(pinverte, vert);
  } else if (vert > g) {
    vert--;
    analogWrite(pinverte, vert);
  }
}

void fadeB() {
  if (bleu < b) {
    bleu++;
    analogWrite(pinbleu, bleu);
  } else if (bleu > b) {
    bleu--;
    analogWrite(pinbleu, bleu);
  }
}

void setup() {
  bitSet(TCCR1B, WGM12); //fix pwm on nano
  pinMode(pinrouge, OUTPUT);
  pinMode(pinverte, OUTPUT);
  pinMode(pinbleu, OUTPUT);
  pinMode(leson, OUTPUT);
  pinMode(aimant, INPUT);
  digitalWrite(pinrouge, LOW);
  digitalWrite(pinverte, LOW);
  digitalWrite(pinbleu, LOW);
  digitalWrite(leson, LOW);
  lerouge = random(1, 255);
  levert = random(1, 255);
  lebleu = random(1, 255);
}

void loop() {
  unsigned long currentMillis = millis();
  int ouvert = digitalRead(aimant);
  if (ouvert == LOW) {
    currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      r = lerouge;
      int lintvert = interval + 4000;
      if (currentMillis - previousMillis >= lintvert) {
        g = levert;
      }
      int lintbleu = interval + 8000;
      if (currentMillis - previousMillis >= lintbleu) {
        b = lebleu;
        previousMillis = currentMillis;
        lerouge = random(1, 255);
        levert = random(1, 255);
        lebleu = random(1, 255);
        interval = 16000;
      }
    }
    currentMillis = millis();
    if (currentMillis - previousMillison >= intervalson) {
      analogWrite(pinrouge, 255);
      analogWrite(pinverte, 255);
      analogWrite(pinbleu, 255);
      delay(500);
      analogWrite(pinrouge, 0);
      analogWrite(pinverte, 0);
      analogWrite(pinbleu, 0);
      delay(500);
      int lintson = intervalson + 15000;
      if (currentMillis - previousMillison >= lintson) {
        faitdubruit = 1;
        flashrendu = 0;
        flashfois = 10000;
      }
    }
  } else {
    analogWrite(pinrouge, 0);
    analogWrite(pinverte, 0);
    analogWrite(pinbleu, 0);
    digitalWrite(leson, LOW);
    previousMillis = currentMillis;
    previousMillison = currentMillis;
    rouge = 0;
    vert = 0;
    bleu = 0;
    r = 0;
    g = 0;
    b = 0;
    flashrendu = 0;
    flashfois = 0;
    faitdubruit = 0;
    interval = 500;
  }
  if (faitdubruit == 1) {
    currentMillis = millis();
    if (currentMillis - previousMillisf >= attendF) {
      flashfunk();
      previousMillisf = currentMillis;
    }
  } else {
    if (r != rouge) {
      currentMillis = millis();
      if (currentMillis - previousMillisr >= attendR) {
        fadeR();
        previousMillisr = currentMillis;
      }
    }
    if (g != vert) {
      currentMillis = millis();
      if (currentMillis - previousMillisg >= attendG) {
        fadeG();
        previousMillisg = currentMillis;
      }
    }
    if (b != bleu) {
      currentMillis = millis();
      if (currentMillis - previousMillisb >= attendB) {
        fadeB();
        previousMillisb = currentMillis;
      }
    }
  }
}
