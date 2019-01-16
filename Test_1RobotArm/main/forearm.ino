#include "Main.h"

// Init the body at 0°
void initForearm()
{
  upForearm();
}

// Turn at 0°
void upForearm()
{
  for (uint16_t pulselen = SERVOMAX_FOREARM; pulselen > SERVOMIN_FOREARM; pulselen--) {
    pwm.setPWM(FOREARM_PIN, 0, pulselen);
    forearmAnglePulse = pulselen;
  }
  
  delay(1000);
}

// Turn at 180°
void downForearm()
{
  for (uint16_t pulselen = SERVOMIN_FOREARM; pulselen < SERVOMAX_FOREARM; pulselen++) {
    pwm.setPWM(FOREARM_PIN, 0, pulselen);
    forearmAnglePulse = pulselen;
  }
    
  delay(1000);
}
