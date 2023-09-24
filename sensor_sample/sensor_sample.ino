// ESC2ndライブラリを読み込む
#include "ESC2nd.h"

#define LPF(obs, x_prev, alpha) ((1 - alpha) * x_prev + obs * alpha)
#define GREEN_THRESHOLD (20)
#define GREEN_CH (3)
#define BUZZER_PIN (8)

// SensorクラスのインスタンスをDEVICE_ADDR1に対応するADCで作成
Sensor sensor(DEVICE_ADDR2);
Motor motorR('r');
Motor motorL('l');
float filterd_value[8] = {0,0,0,0,0,0,0,0};


// プログラムがスタートすると一度だけ実行される
void setup(){
  pinMode(BUZZER_PIN, OUTPUT);
  // PCとarduinoのデータ通信速度を設定(9600bps)
  Serial.begin(9600);
  // 初期化が終わる前に動き出さないように1000ms待つ
  delay(1000);
}

// 電源が入っているうちは永遠に繰り返し実行される
void loop(){
  // センサーの値を入れる配列を定義
  int value[8];
  // センサーから読み出してvalに格納
  sensor.read(value);
  motorR.drive(100);
  motorL.drive(100);

  // val[0]からval[7]までの値を出力
  for(int i=0;i<8;i++){
  filterd_value[i] = LPF(value[i], filterd_value[i], 0.9);
   Serial.print(filterd_value[i]);
   Serial.print(" ");
  }

  if(filterd_value[GREEN_CH] > GREEN_THRESHOLD){
    digitalWrite(BUZZER_PIN, HIGH);
  }else{
    digitalWrite(BUZZER_PIN, LOW);

  }
  // 改行
  Serial.println();
  // 100ms待つ
  delay(100);
}
