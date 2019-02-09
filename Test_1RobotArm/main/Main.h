#ifndef MAIN_H
#define MAIN_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN_BODY  149 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_BODY  600 // this is the 'maximum' pulse length count (out of 4096)
#define BODY_PIN 0
uint16_t bodyAnglePulse = SERVOMAX_BODY;

#define SERVOMIN_ELBOW  170 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_ELBOW  550 // this is the 'maximum' pulse length count (out of 4096)
#define ELBOW_PIN 2
uint16_t elbowAnglePulse = SERVOMAX_ELBOW;

#define SERVOMIN_FOREARM  100 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_FOREARM  400 // this is the 'maximum' pulse length count (out of 4096)
#define FOREARM_PIN 3
uint16_t forearmAnglePulse = SERVOMAX_FOREARM;

#define SERVOMIN_HAND  120 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_HAND  250 // this is the 'maximum' pulse length count (out of 4096)
#define HAND_PIN 5
uint16_t handAnglePulse = SERVOMAX_HAND;

#define SERVOMIN_SHOULDER  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_SHOULDER  400 // this is the 'maximum' pulse length count (out of 4096)
#define SHOULDER_PIN 1
uint16_t shoulderAnglePulse = SERVOMAX_SHOULDER;

#define SERVOMIN_WRIST  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_WRIST  550 // this is the 'maximum' pulse length count (out of 4096)
#define WRIST_PIN 4
uint16_t wristAnglePulse = SERVOMAX_WRIST;

/** main.ino **/
void    setupArm();
void    setup();
void    loop();

/** body.ino **/
void    initBody();
void    frontBody();
void    backBody();

/** elbow.ino **/
void    initElbow();
void    upElbow();
void    downElbow();
void    upDegresElbow(uint16_t);

/** forearm.ino **/
void    initForearm();
void    upForearm();
void    downForearm();

/** hand.ino **/
void    initHand();
void    closeHand();
void    openHand();

/** shoulder.ino **/
void    initShoulder();
void    upShoulder();
void    downShoulder();

/** wrist.ino **/
void    initWrist();
void    leftWrist();
void    rightWrist();

/** preset.ino **/
void    simpleMove();

#endif /** MAIN_H **/
