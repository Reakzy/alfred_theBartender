#ifndef MAIN_H
#define MAIN_H

#define SERVOMIN_BODY  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_BODY  600 // this is the 'maximum' pulse length count (out of 4096)
#define BODY_PIN 0
int bodyAnglePulse = 0;

#define SERVOMIN_ELBOW  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_ELBOW  600 // this is the 'maximum' pulse length count (out of 4096)
#define ELBOW_PIN 2
int elbowAnglePulse = 0;

#define SERVOMIN_FOREARM  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_FOREARM  200 // this is the 'maximum' pulse length count (out of 4096)
#define FOREARM_PIN 3
int forearmAnglePulse = 0;

#define SERVOMIN_HAND  120 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_HAND  250 // this is the 'maximum' pulse length count (out of 4096)
#define HAND_PIN 5
int handAnglePulse = 0;

#define SERVOMIN_SHOULDER  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_SHOULDER  400 // this is the 'maximum' pulse length count (out of 4096)
#define SHOULDER_PIN 1
int shoulderAnglePulse = 0;

#define SERVOMIN_WRIST  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX_WRIST  600 // this is the 'maximum' pulse length count (out of 4096)
#define WRIST_PIN 4
int wristAnglePulse = 0;

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
