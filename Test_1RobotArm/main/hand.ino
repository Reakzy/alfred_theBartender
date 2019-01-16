#include "Main.h"

void initHand()
{
  openHand();
}

void closeHand()
{
  for (uint16_t pulselen = SERVOMIN_HAND; pulselen < SERVOMAX_HAND; pulselen++) {
    pwm.setPWM(HAND_PIN, 0, pulselen);
    handAnglePulse = pulselen;
  }

  delay(1000);
}

void openHand() 
{
  for (uint16_t pulselen = SERVOMAX_HAND; pulselen > SERVOMIN_HAND; pulselen--) {
    pwm.setPWM(HAND_PIN, 0, pulselen);
    handAnglePulse = pulselen;
  }

  delay(1000);
}

void takingCupHand()
{
  for (uint16_t pulselen = SERVOMIN_HAND; pulselen < SERVOMIN_HAND + 34; pulselen++) {
    pwm.setPWM(HAND_PIN, 0, pulselen);
    handAnglePulse = pulselen;
  }

  delay(1000);
}
