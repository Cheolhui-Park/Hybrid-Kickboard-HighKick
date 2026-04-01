// [MCU MOSFET(Arduino) 알고리즘] - 보고서 7페이지 발췌
#define MOSFET_PIN 5
float V_batt, I_regen;
const float V_max = 42.0; // 36V 리튬이온 배터리 최대 충전 전압
const float I_max = 3.0;  // 최대 회생 전류 (A)

void setup() {
  pinMode(MOSFET_PIN, OUTPUT);
  digitalWrite(MOSFET_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  // 전압 및 전류 센서값 변환 (10배 스케일링 가정)
  V_batt = analogRead(A0) * (5.0 / 1023.0) * 10.0;
  I_regen = analogRead(A1) * (5.0 / 1023.0);

  // 전압이나 전류가 임계치를 넘으면 회생제동 중단(보호 회로 작동)
  if (V_batt > V_max || I_regen > I_max) {
    digitalWrite(MOSFET_PIN, LOW);  // MOSFET OFF
  } else {
    digitalWrite(MOSFET_PIN, HIGH); // MOSFET ON (에너지 회수)
  }
  delay(10);
}