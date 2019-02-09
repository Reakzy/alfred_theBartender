#include "Main.h"

// Init the shoulder at 0°
void initShoulder()
{
  upShoulder();
  Serial.print(shoulderAnglePulse);
}

// Turn at 0°
void upShoulder()
{
  for (uint16_t pulselen = shoulderAnglePulse; pulselen > SERVOMIN_SHOULDER; pulselen--) {
    pwm.setPWM(SHOULDER_PIN, 0, pulselen);
    shoulderAnglePulse = pulselen;
  }
  
  delay(500);
}

// Turn at 100° because with more he can't stand up
void downShoulder()
{
  for (uint16_t pulselen = shoulderAnglePulse; pulselen < SERVOMAX_SHOULDER; pulselen++) {
    pwm.setPWM(SHOULDER_PIN, 0, pulselen);
    shoulderAnglePulse = pulselen;
  }
    
  delay(1000);
}
