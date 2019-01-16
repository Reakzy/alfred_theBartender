#include "Main.h"

// Init the body at 0°
void initBody()
{
  frontBody();
}

// Turn at 0°
void frontBody()
{
  for (uint16_t pulselen = SERVOMAX_BODY; pulselen > SERVOMIN_BODY; pulselen--) {
    pwm.setPWM(BODY_PIN, 0, pulselen);
    bodyAnglePulse = pulselen;
  }
  
  delay(1000);
}

// Turn at 180°
void backBody()
{
  for (uint16_t pulselen = SERVOMIN_BODY; pulselen < SERVOMAX_BODY; pulselen++) {
    pwm.setPWM(BODY_PIN, 0, pulselen);
    bodyAnglePulse = pulselen;
  }
    
  delay(1000);
}
