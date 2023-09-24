// ESC2ndライブラリを読み込む
#include "ESC2nd.h"

#define LPF(obs, x_prev, alpha) ((1 - alpha) * x_prev + obs * alpha)

// SensorクラスのインスタンスをDEVICE_ADDR1に対応するADCで作成
Sensor sensor(DEVICE_ADDR1);


// プログラムがスタートすると一度だけ実行される
void setup(){
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

  // val[0]からval[7]までの値を出力
  for(int i=0;i<8;i++){
   Serial.print(value[i]);
   Serial.print(" ");
  }

  // 改行
  Serial.println();
  // 100ms待つ
  delay(100);
}
