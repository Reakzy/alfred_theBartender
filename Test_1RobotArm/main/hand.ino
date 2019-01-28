#include "Main.h"

void initHand()
{
  openHand();
}

void closeHand()
{
  for (uint16_t pulselen = handAnglePulse; pulselen < SERVOMAX_HAND; pulselen++) {
    pwm.setPWM(HAND_PIN, 0, pulselen);
    handAnglePulse = pulselen;
  }

  delay(1000);
}

void openHand() 
{
  for (uint16_t pulselen = handAnglePulse; pulselen > SERVOMIN_HAND; pulselen--) {
    pwm.setPWM(HAND_PIN, 0, pulselen);
    handAnglePulse = pulselen;
  }

  delay(1000);
}

void takingCupHand()
{
  openHand();
  for (uint16_t pulselen = handAnglePulse; pulselen < SERVOMIN_HAND + 60; pulselen++) {
    pwm.setPWM(HAND_PIN, 0, pulselen);
    handAnglePulse = pulselen;
  }

  delay(1000);
}
