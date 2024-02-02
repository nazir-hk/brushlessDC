// MKS ESP32 FOC AS5600测试例程 测试硬件：MKS ESP32 FOC V1.0
// 手动转动电机，可以收到串口监视器显示的电机位置
// 第一列和第二列分别是M0和M1电机的位置坐标

#include <SimpleFOC.h>


MagneticSensorI2C sensor0 = MagneticSensorI2C(AS5600_I2C);
TwoWire I2Cone = TwoWire(0);


void setup() {

  
  Serial.begin(115200);
  _delay(750);
  // I2Cone.begin(19,18, 400000);   //SDA0,SCL0
  
  //针对最新版本ESP-Arduino 2.0.2,采用下面两句
  I2Cone.begin(19,18, 400000UL);   //SDA0,SCL0
  //I2Ctwo.begin(23,5, 400000UL);
  
  sensor0.init(&I2Cone);
}

void loop() {
  sensor0.update(); // 如果simplefoc库版本为2.20及以上，取消这两行的注释
  _delay(200);
  Serial.print(sensor0.getAngle()); 
  Serial.println();
}
