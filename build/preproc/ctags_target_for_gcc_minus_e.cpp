# 1 "d:\\arduino\\arduino_src\\testdelay1\\testdelay.ino"


//初始化
int In1 = 6;
int In2 = 7;
int In3 = 4;
int In4 = 5;

int Sensor_x1 = 11;
int Sensor_x2 = 10;
int Sensor_x3 = 9;
int Sensor_x4 = 8;



void setup()
{
  // 初始化I/O口
    pinMode(In1,0x1);
    pinMode(In2,0x1);
    pinMode(In3,0x1);
    pinMode(In4,0x1);

    pinMode(Sensor_x1,0x0);
    pinMode(Sensor_x2,0x0);
    pinMode(Sensor_x3,0x0);
    pinMode(Sensor_x4,0x0);

    Serial.begin(115200);

}

void loop()
{
    int SensorVal_x1 = digitalRead(Sensor_x1);
    int SensorVal_x2 = digitalRead(Sensor_x2);
    int SensorVal_x3 = digitalRead(Sensor_x3);
    int SensorVal_x4 = digitalRead(Sensor_x4);

    //控制正反转
    if (SensorVal_x1 && SensorVal_x3)
    {
        digitalWrite(In1, 0x0);
        digitalWrite(In2, 0x1);
        digitalWrite(In3, 0x0);
        digitalWrite(In4, 0x1);
    }
    else
    {
        digitalWrite(In1, 0x0);
        digitalWrite(In2, 0x0);
        digitalWrite(In3, 0x0);
        digitalWrite(In4, 0x0);

    }

    delay(10);
    // else
    // {
    //     digitalWrite(In1,HIGH);
    //     digitalWrite(In2,LOW);
    // }
# 71 "d:\\arduino\\arduino_src\\testdelay1\\testdelay.ino"
    // digitalWrite(4,LOW);
    // digitalWrite(5,HIGH);
}
