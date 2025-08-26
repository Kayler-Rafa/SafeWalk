int triggerPin = 7;  // Trigger do sensor
int echoPin = 6;     // Echo do sensor
int buzzerPin = 13;  // Buzzer

long readUltrasonicDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  return pulseIn(echoPin, HIGH);
}

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration = readUltrasonicDistance(triggerPin, echoPin);
  int cm = duration * 0.034 / 2;

  if (cm > 0 && cm <= 20) {
    tone(buzzerPin, 2500);   // Bem agudo, forte
    delay(50);
    noTone(buzzerPin);
    delay(50);
  } else if (cm > 20 && cm <= 40) {
    tone(buzzerPin, 2000);
    delay(200);
    noTone(buzzerPin);
    delay(150);
  } else if (cm > 40 && cm <= 60) {
    tone(buzzerPin, 1500);
    delay(300);
    noTone(buzzerPin);
    delay(200);
  } else if (cm > 60 && cm <= 80) {
    tone(buzzerPin, 1200);
    delay(400);
    noTone(buzzerPin);
    delay(250);
  } else if (cm > 80 && cm <= 100) {
    tone(buzzerPin, 1000);
    delay(500);
    noTone(buzzerPin);
    delay(300);
  } else {
    noTone(buzzerPin);
  }
}
