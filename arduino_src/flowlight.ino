#include <Servo.h>

Servo myservo;  // 定义Servo对象来控制
int pos = 0;    // 角度存储变量
int count = 0;

void toufang() {
  for (pos = 0; pos <= 180; pos ++) { // 0°到180°
    myservo.write(pos);              // 舵机角度写入
    delay(5);                       // 等待转动到指定角度
  }
  delay(10);
  for (pos = 180; pos >= 0; pos --) { // 从180°到0°
    myservo.write(pos);              // 舵机角度写入
    delay(5);                       // 等待转动到指定角度
  }
  count += 1;
}
void setup() {
  myservo.attach(9);
}

void loop() {
    toufang();
}
