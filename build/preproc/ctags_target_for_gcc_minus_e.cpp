# 1 "d:\\arduino\\arduino_src\\testdelay1\\testdelay.ino"

//初始化引脚
int R_IN1 = 6; //1,2右轮，3，4左轮
int R_IN2 = 7;
int L_IN3 = 5;
int L_IN4 = 4;

int Sensor_LL_X2 = 12;
int Sensor_L_X1 = 8;
int Sensor_R_X3 = 11;
int Sensor_RR_X4 = 10;



// int Throw_Place_Count = 0;


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
void Go_Straight() //这个是正转的程序
{
    analogWrite(R_IN1,180);
    digitalWrite(R_IN2,0);
    analogWrite(L_IN3,180);
    digitalWrite(L_IN4,0);
}

void Slow_TurnLeft()
{
    analogWrite(R_IN1,160);
    digitalWrite(R_IN2,0);
    analogWrite(L_IN3,130);
    digitalWrite(L_IN4,0);
}

void Slow_TurnRight()
{
    analogWrite(R_IN1,130);
    digitalWrite(R_IN2,0);
    analogWrite(L_IN3,160);
    digitalWrite(L_IN4,0);
}

void Fast_TurnLeft()
{
    analogWrite(R_IN1,180);
    digitalWrite(R_IN2,0);
    analogWrite(L_IN3,130);
    digitalWrite(L_IN4,0);
}

void Fast_TurnRight()
{
    analogWrite(R_IN1,130);
    digitalWrite(R_IN2,0);
    analogWrite(L_IN3,180);
    digitalWrite(L_IN4,0);
}

void Stop()
{
    analogWrite(R_IN1, 0);
    digitalWrite(R_IN2, 0);
    analogWrite(L_IN3, 0);
    digitalWrite(L_IN4, 0);
}



//现在有两种算法，一种是单纯if判断，另一种是给每个传感器赋个特殊的值，然后用switch语句
//先把if的写了

void loop()
{
    int SensorVal_LL_X2 = digitalRead(Sensor_LL_X2);
    int SensorVal_L_X1 = digitalRead(Sensor_L_X1);
    int SensorVal_R_X3 = digitalRead(Sensor_R_X3);
    int SensorVal_RR_X4 = digitalRead(Sensor_RR_X4);

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 0 && SensorVal_R_X3 == 1 && SensorVal_RR_X4 == 1)
    {
        Slow_TurnLeft();
        delay(2);
        Stop();
        delay(2);
    }

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 1 && SensorVal_R_X3 == 0 && SensorVal_RR_X4 == 1)
    {
        Slow_TurnRight();
        delay(2);
        Stop();
        delay(2);
    }

    if(SensorVal_LL_X2 == 0 && SensorVal_L_X1 == 1 && SensorVal_R_X3 == 1 && SensorVal_RR_X4 == 1)
    {
        Fast_TurnLeft();
        delay(2);
        Stop();
        delay(2);
    }

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 1 && SensorVal_R_X3 == 1 && SensorVal_RR_X4 == 0)
    {
        Fast_TurnRight();
        delay(2);
        Stop();
        delay(2);
    }

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 0 && SensorVal_R_X3 == 0 && SensorVal_RR_X4 == 1)
    {
        Go_Straight();
        delay(2);
        Stop();
        delay(2);
    }

    if(SensorVal_LL_X2 == 1 && SensorVal_L_X1 == 1 && SensorVal_R_X3 == 1 && SensorVal_RR_X4 == 1)
    {
        // Throw_Place_Count++;
        Stop();
    }

    if(SensorVal_LL_X2 == 0 && SensorVal_L_X1 == 0 && SensorVal_R_X3 == 0 && SensorVal_RR_X4 == 0)
    {
        // Throw_Place_Count++;
        Stop();
    }


    //最终停止的条件
    // if (Throw_Place_Count == 4)
    // {
    //     Stop();
    // }

}
