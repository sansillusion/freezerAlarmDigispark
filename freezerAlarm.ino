const int leson = 5;
const int aimant = 2;
int rouge = 0;
int vert = 0;
int bleu = 0;
const int pinrouge = 0;
const int pinverte = 1;
const int pinbleu = 4;
long r = 0;
long g = 0;
long b = 0;
unsigned long previousMillisr = 0;
unsigned long previousMillisg = 0;
unsigned long previousMillisb = 0;
int attendR = 70;
int attendG = 70;
int attendB = 70;
unsigned long previousMillisf = 0;
int attendF = 700;
unsigned long flashfois = 0;
unsigned long flashrendu = 0;
int faitdubruit = 0;
int bruit = 0;

unsigned long previousMillis = 0;
unsigned long previousMillison = 0;
const long interval = 1000; // interval pour les leds en ms
const long intervalson = 600000; // interval pour le son en ms

void flashfunk() {
  if (flashrendu <= flashfois) {
    flashrendu++;
    if (bruit == 1) {
      digitalWrite(leson, LOW);
      digitalWrite(pinrouge, LOW);
      digitalWrite(pinverte, LOW);
      digitalWrite(pinbleu, LOW);
      bruit = 0;
    } else {
      digitalWrite(leson, HIGH);
      digitalWrite(pinrouge, HIGH);
      digitalWrite(pinverte, HIGH);
      digitalWrite(pinbleu, HIGH);
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
  pinMode(pinrouge, OUTPUT);
  pinMode(pinverte, OUTPUT);
  pinMode(pinbleu, OUTPUT);
  pinMode(leson, OUTPUT);
  pinMode(aimant, INPUT);
  digitalWrite(pinrouge, LOW);
  digitalWrite(pinverte, LOW);
  digitalWrite(pinbleu, LOW);
  digitalWrite(leson, LOW);
}

void loop() {
  unsigned long currentMillis = millis();
  int ouvert = digitalRead(aimant);
  if (ouvert == LOW) {
    currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      r = 255;
      int lintvert = interval + 1000;
      if (currentMillis - previousMillis >= lintvert) {
        g = 255;
      }
      int lintbleu = interval + 2000;
      if (currentMillis - previousMillis >= lintbleu) {
        b = 255;
      }
    }
    currentMillis = millis();
    if (currentMillis - previousMillison >= intervalson) {
      faitdubruit = 1;
      flashrendu = 0;
      flashfois = 0;
      digitalWrite(pinrouge, HIGH);
      digitalWrite(pinverte, HIGH);
      digitalWrite(pinbleu, HIGH);
      delay(500);
      digitalWrite(pinrouge, LOW);
      digitalWrite(pinverte, LOW);
      digitalWrite(pinbleu, LOW);
      int lintson = interval + 5000;
      if (currentMillis - previousMillis >= lintson) {
        flashrendu = 0;
        flashfois = 10000;
      }
    }
  } else {
//    digitalWrite(pinrouge, LOW);
//    digitalWrite(pinverte, LOW);
//    digitalWrite(pinbleu, LOW);
    digitalWrite(leson, LOW);
    previousMillis = currentMillis;
    previousMillison = currentMillis;
    r = 0;
    g = 0;
    b = 0;
    flashrendu = 0;
    flashfois = 0;
    faitdubruit = 0;
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
        attendR = fadecomment(rouge);
      }
    }
    if (g != vert) {
      currentMillis = millis();
      if (currentMillis - previousMillisg >= attendG) {
        fadeG();
        previousMillisg = currentMillis;
        attendG = fadecomment(vert);
      }
    }
    if (b != bleu) {
      currentMillis = millis();
      if (currentMillis - previousMillisb >= attendB) {
        fadeB();
        previousMillisb = currentMillis;
        attendB = fadecomment(bleu);
      }
    }
  }
}

int fadecomment(int claire) {
  int combien = 70;
  if (claire > 0)
    combien = 90;
  if (claire > 40)
    combien = 80;
  if (claire > 80)
    combien = 60;
  if (claire > 100)
    combien = 40;
  if (claire > 120)
    combien = 30;
  if (claire > 140)
    combien = 20;
  if (claire > 180)
    combien = 9;
  return combien;
}
