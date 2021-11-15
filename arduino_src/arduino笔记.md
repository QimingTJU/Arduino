# Arduino笔记
## 程序结构
1. 每个板子上都自带一个LED灯，比如我的板子上是13位置，但无论什么板子，都有一个共同的名字——LED_BUILTIN(也可以说13)
2. 当你给开发板通电后或者按下复位按钮后，setup函数运行一次
3. delay函数的单位是毫秒
4. 这里面int的范围是-32768~32767（16位？）
5. PinMode(引脚位置， 状态)
6. digitalWrite(引脚位置， 高低电平)，HIGH的时候为5V，LOW时为0V
7. LED在工作时，会产生2V左右的电压降，工作电流大概为20mA，长脚为正极
8. 开始串口通讯：  
为毛这个代码块要两次缩进了

        void setup()
        {
            Serial.begin(115200波特率)
        }

        void loop()
        {
            //将开关状态数值读取到变量中
            int SensorVal = digitalRead(pin)
            //digitalRead 读取数字引脚的高电平或低电平，返回值为HIGH或LOW

            //输出开关状态数值到串口监视器中
            Serial.println(SensorVal)
        }
9. 模拟输出

        analogWrite(pin, )