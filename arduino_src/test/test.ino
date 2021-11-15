int ledPin = 13;                 // Arduino Uno引脚13接有LED
void setup()
{
  pinMode(ledPin, OUTPUT);      // 将LED连接引脚设置为输出模式
}
 
void loop()
{
  digitalWrite(ledPin, HIGH);   // 点亮LED
  delayMicroseconds(1000000);                  // 等待10000微秒
  digitalWrite(ledPin, LOW);    // 熄灭LED
  delayMicroseconds(1000000);                   // 等待10000微秒
}
