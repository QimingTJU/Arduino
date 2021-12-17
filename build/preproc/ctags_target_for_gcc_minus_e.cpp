# 1 "d:\\arduino\\arduino_src\\testdelay1\\testdelay.ino"
// digitalWrite(R_IN1, LOW);       //这个是向前跑的代码,放在前面示例
// digitalWrite(R_IN2, HIGH);
// digitalWrite(L_IN3, LOW);
// digitalWrite(L_IN4, HIGH);

//初始化引脚
int R_IN1 = 6;
int R_IN2 = 7;
int L_IN3 = 4;
int L_IN4 = 5;

int Sensor_L_X1 = 11;
int Sensor_LL_X2 = 10;
int Sensor_R_X3 = 9;
int Sensor_RR_X4 = 8;


void setup()
{
  // 初始化I/O口
    pinMode(R_IN1,0x1);
    pinMode(R_IN2,0x1);
    pinMode(L_IN3,0x1);
    pinMode(L_IN4,0x1);

    pinMode(Sensor_L_X1,0x0);
    pinMode(Sensor_LL_X2,0x0);
    pinMode(Sensor_R_X3,0x0);
    pinMode(Sensor_RR_X4,0x0);

    Serial.begin(115200);

}

//几个转向函数
void Go_Straight()
{
    digitalWrite(R_IN1, 0x0);
    digitalWrite(R_IN2, 0x1);
    digitalWrite(L_IN3, 0x0);
    digitalWrite(L_IN4, 0x1);
}

void Slow_TurnLeft()
{
    digitalWrite(R_IN1,0x0);
    analogWrite(R_IN2,220);
    digitalWrite(L_IN3,0x0);
    analogWrite(L_IN4,200);
}

void Slow_TurnRight()
{
    digitalWrite(R_IN1,0x0);
    analogWrite(R_IN2,200);
    digitalWrite(L_IN3,0x0);
    analogWrite(L_IN4,220);
}

void Fast_TurnLeft()
{
    digitalWrite(R_IN1,0x0);
    analogWrite(R_IN2,220);
    digitalWrite(L_IN3,0x0);
    analogWrite(L_IN4,150);
}

void Fast_TurnRight()
{
    digitalWrite(R_IN1,0x0);
    analogWrite(R_IN2,150);
    digitalWrite(L_IN3,0x0);
    analogWrite(L_IN4,220);
}

void Stop()
{
    digitalWrite(R_IN1, 0x0);
    digitalWrite(R_IN2, 0x0);
    digitalWrite(L_IN3, 0x0);
    digitalWrite(L_IN4, 0x0);
}



//现在有两种算法，一种是单纯if判断，另一种是给每个传感器赋个特殊的值，然后用switch语句
//先把if的写了

void loop()
{
    int SensorVal_L_X1 = digitalRead(Sensor_L_X1);
    int SensorVal_LL_X2 = digitalRead(Sensor_LL_X2);
    int SensorVal_R_X3 = digitalRead(Sensor_R_X3);
    int SensorVal_RR_X4 = digitalRead(Sensor_RR_X4);

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 0 && SensorVal_R_X3 == 1 && SensorVal_RR_X4 == 1)
    {
        Slow_TurnLeft();
    }

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 1 && SensorVal_R_X3 == 0 && SensorVal_RR_X4 == 1)
    {
        Slow_TurnRight();
    }

    if(SensorVal_LL_X2 == 0 && SensorVal_L_X1 == 1 && SensorVal_R_X3 == 1 && SensorVal_RR_X4 == 1)
    {
        Fast_TurnLeft();
    }

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 1 && SensorVal_R_X3 == 1 && SensorVal_RR_X4 == 0)
    {
        Fast_TurnRight();
    }

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 0 && SensorVal_R_X3 == 0 && SensorVal_RR_X4 == 1)
    {
        Go_Straight();
    }

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 1 && SensorVal_R_X3 == 1 && SensorVal_RR_X4 == 1)
    {
        Stop();
    }

    delay(1);

}
