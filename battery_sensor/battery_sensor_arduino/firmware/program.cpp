/*
* read the sensor values (voltage and current) and send them in a ros message 
*/

#include <ros.h>
#include <battery_sensor_msgs/Measures.h>
#include <Sensor.h>

#include <Arduino.h>


Sensor S1 = Sensor(0,1); //TODO sensor 2 & 3

ros::NodeHandle nh;

battery_sensor_msgs::Measures measures_msg_1;
ros::Publisher pub("measures", &measures_msg_1);

/*
int freeRam()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
*/

void setup()
{
  nh.initNode();
  nh.advertise(pub);

  //Serial.begin(9600);
}


long msg_delay = 2000;
long new_millis;
long last_millis = millis();


void loop()
{  
  new_millis = millis();
  
  if( (new_millis - last_millis) > msg_delay)
  {
    S1.updateMeasures();
    measures_msg_1.name = "battery1";
    measures_msg_1.voltage = S1.getVoltage();
    measures_msg_1.current = S1.getCurrent();
    measures_msg_1.SOC = S1.getSOC();

    //measures_msg_1.header.stamp = ros::Time::now();

    pub.publish(&measures_msg_1);
    nh.spinOnce();

    /*
    Serial.print("freeRam()=");
    Serial.println(freeRam());
    */

    last_millis = new_millis;
  }
  
}
