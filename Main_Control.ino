// [MCU 논리 판단(Arduino) 알고리즘] - 보고서 6페이지 발췌
#define SWITCH1_PIN 7      // 속도 감지 센서
#define SWITCH2_PIN 8      // 가속 레버(Throttle)
#define MOTOR_PWM_PIN 6    // 모터 출력 제어
#define BOOSTER_LED_PIN 5  // 부스터 상태 표시 LED

unsigned long boosterStartTime = 0;
bool boosterActive = false;

void setup() {
  pinMode(SWITCH1_PIN, INPUT);
  pinMode(SWITCH2_PIN, INPUT);
  pinMode(MOTOR_PWM_PIN, OUTPUT);
  pinMode(BOOSTER_LED_PIN, OUTPUT);
}

void loop() {
  bool speedOK = digitalRead(SWITCH1_PIN) == HIGH;
  bool throttlePressed = digitalRead(SWITCH2_PIN) == HIGH;

  // 속도가 10km/h 이상이고 가속 레버가 눌렸을 때 부스터 작동
  if (speedOK && throttlePressed && !boosterActive) {
    boosterActive = true;
    boosterStartTime = millis();
    digitalWrite(BOOSTER_LED_PIN, HIGH); // 부스터 준비 표시
    analogWrite(MOTOR_PWM_PIN, 255);     // 모터 최대 출력
  }

  // 3초 경과 시 또는 스로틀에서 손을 뗐을 때 가속 중지
  if (boosterActive) {
    if (millis() - boosterStartTime > 3000 || !throttlePressed) {
      boosterActive = false;
      digitalWrite(BOOSTER_LED_PIN, LOW);
      analogWrite(MOTOR_PWM_PIN, 0);     // 모터 OFF
      // 이후 회생제동 로직으로 전환 가능
    }
  }
}