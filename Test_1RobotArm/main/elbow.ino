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
  
  delay(500);
}

/* 
 * Turn at 180° 
 * @Security can't turn if shoulder is down too (~= 50 first pulse length)
 */
void downElbow()
{
  for (uint16_t pulselen = elbowAnglePulse; pulselen < SERVOMAX_ELBOW; pulselen++) {
    pwm.setPWM(ELBOW_PIN, 0, pulselen);
    elbowAnglePulse = pulselen;
  }
    
  delay(1000);
}

void upDegresElbow(uint16_t degres)
{
  uint16_t difference = SERVOMAX_ELBOW - SERVOMIN_ELBOW;
  uint16_t pulselenDegres = elbowAnglePulse - (degres * difference / 180);

  if (pulselenDegres < SERVOMIN_ELBOW) {    
    pulselenDegres = SERVOMIN_ELBOW;
  }

  for (uint16_t pulselen = elbowAnglePulse; pulselen > pulselenDegres; pulselen--) {
    pwm.setPWM(ELBOW_PIN, 0, pulselen);
    elbowAnglePulse = pulselen;
    delay(10);
  }
  
  delay(500);
}

void downDegresElbow(uint16_t degres)
{
  uint16_t difference = SERVOMAX_ELBOW - SERVOMIN_ELBOW;
  uint16_t pulselenDegres = (degres * difference / 180) + elbowAnglePulse;

  if (pulselenDegres > SERVOMAX_ELBOW) {    
    pulselenDegres = SERVOMAX_ELBOW;
  }

  for (uint16_t pulselen = elbowAnglePulse; pulselen < pulselenDegres; pulselen++) {
    pwm.setPWM(ELBOW_PIN, 0, pulselen);
    elbowAnglePulse = pulselen;
    delay(10);
  }
  
  delay(500);
}
