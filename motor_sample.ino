#include "ESC2nd.h"

Motor motorR('r');
Motor motorL('l');

void setup(){
  Serial.begin(9600);
  delay(1000);
}

void loop(){
  // 直進
  motorR.drive(80);
  motorL.drive(80);
  delay(3000);

  // 左折
  motorR.drive(170);
  motorL.drive(-10);
  delay(3000);

  // 右折
  motorR.drive(-10);
  motorL.drive(170);
  delay(3000);
}
