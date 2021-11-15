/*
Arduino制作流水灯
<a href="http://www.arduino.cn/" target="_blank">http://www.arduino.cn/</a>
*/

void setup() 
{
  // 初始化I/O口
  for (int i = 2; i < 6; i++)
    pinMode(i,OUTPUT);
}

void loop() 
{
    
  // 从引脚2到引脚4，逐个点亮LED，等待1秒再熄灭LED
  for (int i = 2; i < 5; i++)
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);   
  }
  // 从引脚5到引脚3，逐个点亮LED，等待1秒再熄灭LED
  for(int i = 5; i > 2; i--)
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  } 
}