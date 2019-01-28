#include "Main.h"

// Init the body at 0°
void initElbow()
{
  upElbow();
}

// Turn at 0°
void upElbow()
{
  for (uint16_t pulselen = elbowAnglePulse; pulselen > SERVOMIN_ELBOW; pulselen--) {
    pwm.setPWM(ELBOW_PIN, 0, pulselen);
    elbowAnglePulse = pulselen;
  }
  
  delay(1000);
}

/* 
 * Turn at 180° 
 * @Security can't turn if shoulder is down too (~= 50 first pulse length)
 */
void downElbow()
{
  if (SERVOMIN_SHOULDER + 50 <= shoulderAnglePulse) {
    for (uint16_t pulselen = elbowAnglePulse; pulselen < SERVOMAX_ELBOW; pulselen++) {
      pwm.setPWM(ELBOW_PIN, 0, pulselen);
      elbowAnglePulse = pulselen;
    }
  }
    
  delay(1000);
}
