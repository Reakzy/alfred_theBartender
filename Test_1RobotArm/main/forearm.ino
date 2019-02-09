#include "Main.h"

// Init the body at 0°
void initForearm()
{
  downForearm();
}

// Turn at 0°
void upForearm()
{
  
  for (uint16_t pulselen = forearmAnglePulse; pulselen < SERVOMAX_FOREARM; pulselen++) {
    pwm.setPWM(FOREARM_PIN, 0, pulselen);
    forearmAnglePulse = pulselen;
  }
    
  delay(1000);
}

// Turn at 180°
void downForearm()
{
  for (uint16_t pulselen = forearmAnglePulse; pulselen > SERVOMIN_FOREARM; pulselen--) {
    pwm.setPWM(FOREARM_PIN, 0, pulselen);
    forearmAnglePulse = pulselen;
  }
  
  delay(500);
}

void upDegresForearm(uint16_t degres)
{
  uint16_t difference = SERVOMAX_FOREARM - SERVOMIN_FOREARM;
  uint16_t pulselenDegres = (degres * difference / 180) + forearmAnglePulse;

  if (pulselenDegres > SERVOMAX_FOREARM) {    
    pulselenDegres = SERVOMAX_FOREARM;
  }

  for (uint16_t pulselen = forearmAnglePulse; pulselen < pulselenDegres; pulselen++) {
    pwm.setPWM(FOREARM_PIN, 0, pulselen);
    forearmAnglePulse = pulselen;
    delay(10);
  }
  
  delay(500);
}

void downDegresForearm(uint16_t degres)
{
  uint16_t difference = SERVOMAX_FOREARM - SERVOMIN_FOREARM;
  uint16_t pulselenDegres = forearmAnglePulse - (degres * difference / 180);

  if (pulselenDegres < SERVOMIN_FOREARM) {    
    pulselenDegres = SERVOMIN_FOREARM;
  }

  for (uint16_t pulselen = forearmAnglePulse; pulselen > pulselenDegres; pulselen--) {
    pwm.setPWM(FOREARM_PIN, 0, pulselen);
    forearmAnglePulse = pulselen;
    delay(10);
  }
  
  delay(500);
}
