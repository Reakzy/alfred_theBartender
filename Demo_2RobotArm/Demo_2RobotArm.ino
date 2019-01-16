/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  
  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

// ======= DEFINED ARM FUNC =======
void setUpTo(int servoPin, int startPos, int endPos) {
    for (uint16_t pulselen = startPos; pulselen < endPos; pulselen++) {
      pwm.setPWM(servoPin, 0, pulselen);
    }
}

void setDownTo(int servoPin, int endPos, int startPos) {
    for (uint16_t pulselen = endPos; pulselen > startPos; pulselen--) {
      pwm.setPWM(servoPin, 0, pulselen);
    }
}
// ======= STOP ARM FUNC =======

void setTo0(int servoPin) {
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
      pwm.setPWM(servoPin, 0, pulselen);
    }
}

void setTo180(int servoPin) {
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
      pwm.setPWM(servoPin, 0, pulselen);
    }
}

void setTo100(int servoPin) {
    for (uint16_t pulselen = 100; pulselen < 300; pulselen++) {
      pwm.setPWM(servoPin, 0, pulselen);
    }
}


// ======= DEFINED HAND FUNC =======
void closeHand() {
     for (uint16_t pulselen = 120; pulselen < 250; pulselen++) {
      pwm.setPWM(5, 0, pulselen);
    }
}

void openHand() {
    for (uint16_t pulselen = 250; pulselen > 120; pulselen--) {
      pwm.setPWM(5, 0, pulselen);
    }
}
// ======= STOP HAND FUNC =======


void setupArm() {
  // Set all the servos to 0 degre
  for (int set = 0; set < 5; set++) {
      setTo0(set);
      delay(1000);
  }
  closeHand();
}

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  setupArm();
  delay(1000);
    setUpTo(2, 150, 250);
  delay(500);
  setUpTo(1, 150, 250);
  delay(500);
  setUpTo(2, 250, 350);
  delay(500);
  setUpTo(1, 250, 350);
  delay(500);
  setUpTo(2, 350, 550);
  delay(1000);
}

void loop() {

//  openHand();
//  delay(1000);
//  closeHand();
//  delay(1000);
//  setDownTo(2, 325, 425);
//  delay(1000);
//  setDownTo(1, 225, 400);
//  delay(1000);
//  setDownTo(2, 150, 325);
//  delay(1000);
//  setDownTo(1, 150, 225);
//  delay(1000);
//  openHand();
//  delay(1000);
//  closeHand();
//  delay(1000);
//  setTo0(0);
//  delay(1000);
}
