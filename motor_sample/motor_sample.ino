#include "ESC2nd.h"

Motor motorR('r');
Motor motorL('l');

void setup(){
  Serial.begin(9600);
  delay(1000);
}

void loop(){
  // 直進
  motorR.drive(20);
  motorL.drive(20);
  delay(3000);

  // 左折
  motorR.drive(40);
  motorL.drive(-20);
  delay(3000);

  // 右折
  motorR.drive(-20);
  motorL.drive(40);
  delay(3000);
}
