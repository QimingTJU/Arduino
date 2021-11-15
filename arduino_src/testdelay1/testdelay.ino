

//初始化
int In1 = 4;
int In2 = 7;
int Sensor_x1 = 11;
int Sensor_x2 = 10;
int Sensor_x3 = 9;
int Sensor_x4 = 8;



void setup() 
{
  // 初始化I/O口
    pinMode(In1,OUTPUT);
    pinMode(In2,OUTPUT);
    pinMode(Sensor_x1,INPUT);
    pinMode(Sensor_x2,INPUT);
    pinMode(Sensor_x3,INPUT);
    pinMode(Sensor_x4,INPUT);

    Serial.begin(115200);

}

void loop() 
{
    int SensorVal_x1 = digitalRead(Sensor_x1);
    int SensorVal_x2 = digitalRead(Sensor_x2);
    int SensorVal_x3 = digitalRead(Sensor_x3);
    int SensorVal_x4 = digitalRead(Sensor_x4);

    //控制正反转
    if (SensorVal_x1  && SensorVal_x3)
    {
        digitalWrite(In1, LOW);
        digitalWrite(In2, HIGH);
    }
    else
    {
        digitalWrite(In1, LOW);
        digitalWrite(In2, LOW);

    }

    delay(10);
    // else
    // {
    //     digitalWrite(In1,HIGH);
    //     digitalWrite(In2,LOW);
    // }








    // digitalWrite(4,LOW);
    // digitalWrite(5,HIGH);
}