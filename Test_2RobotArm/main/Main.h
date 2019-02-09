#ifndef MAIN_H
#define MAIN_H

#include <VarSpeedServo.h> 
 
VarSpeedServo myservo;

void servo_park();
void set_arm( uint16_t x, uint16_t y, uint16_t z, uint16_t grip_angle );
void set_arm( float x, float y, float z, float grip_angle_d, int servoSpeed );
void zero_x();
void line();
void circle();

#endif /** MAIN_H **/
