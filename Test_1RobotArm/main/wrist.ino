
#include "Main.h"

// Init the body at 0°
void initWrist()
{
  leftWrist();
}

// Turn at 0°
void leftWrist()
{
  for (uint16_t pulselen = SERVOMAX_WRIST; pulselen > SERVOMIN_WRIST; pulselen--) {
    pwm.setPWM(WRIST_PIN, 0, pulselen);
    wristAnglePulse = pulselen;
  }
  
  delay(1000);
}

// Turn at 180°
void rightWrist()
{
  for (uint16_t pulselen = SERVOMIN_WRIST; pulselen < SERVOMAX_WRIST; pulselen++) {
    pwm.setPWM(WRIST_PIN, 0, pulselen);
    wristAnglePulse = pulselen;
  }
    
  delay(1000);
}
