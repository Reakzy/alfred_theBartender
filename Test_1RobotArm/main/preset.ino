#include "Main.h"

/*
 * Move forward, standup, turn 180°, move forward, stand up
 */
void  simpleMove()
{
  upShoulder();
  downElbow(); 
}

void turningAndUsingHand()
{
  rightWrist();
  closeHand();
  leftWrist();
  openHand(); 
}

/**
 * Move the arm in front.
 */
void moveForward()
{
  uint16_t pulselenShoulder = SERVOMIN_SHOULDER;
  uint16_t pulselenElbow = SERVOMIN_ELBOW;

    for (pulselenShoulder; pulselenShoulder < (SERVOMAX_SHOULDER / 1.5); pulselenShoulder++) {
      pwm.setPWM(SHOULDER_PIN, 0, pulselenShoulder);
      shoulderAnglePulse = pulselenShoulder;
      delay(5);
      pwm.setPWM(ELBOW_PIN, 0, pulselenElbow);
      elbowAnglePulse = pulselenElbow;
      delay(5);
      pulselenElbow++;
    }

  delay(1000);
}

/**
 * Go back and stabilise the hand. The hand need to be stable for the cup.
 */
void moveBackward()
{
  uint16_t pulselenShoulder = shoulderAnglePulse;
  uint16_t pulselenElbow = elbowAnglePulse;
  uint16_t pulselenForearm = forearmAnglePulse;

  for (pulselenShoulder; pulselenShoulder > SERVOMIN_SHOULDER; pulselenShoulder--) {
      pwm.setPWM(SHOULDER_PIN, 0, pulselenShoulder);
      shoulderAnglePulse = pulselenShoulder;
      delay(5);
      
      pwm.setPWM(ELBOW_PIN, 0, pulselenElbow);
      elbowAnglePulse = pulselenElbow;
      delay(5);
      pulselenElbow--;
      if (pulselenElbow < SERVOMIN_ELBOW) {
        pulselenElbow = SERVOMIN_ELBOW;
      }
      
      if (pulselenShoulder % 2 == 0) {
        pwm.setPWM(FOREARM_PIN, 0, pulselenForearm);
        forearmAnglePulse = pulselenForearm;
        delay(5);
        pulselenForearm--;
        if (pulselenForearm < SERVOMIN_FOREARM) {
          pulselenForearm = SERVOMIN_FOREARM;
        }
      }
  }
  
  delay(1000);
}

/**
 * Move forward, take a cup and go back to initial position.
 */
void takeCup()
{
  moveForward();
  upDegresForearm(50);
  takingCupHand();
  moveBackward();
}



void takeCupAndRotate()
{
  takeCup();
  backBody();
}
