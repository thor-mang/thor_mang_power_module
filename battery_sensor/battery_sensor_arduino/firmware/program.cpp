/*
* read the sensor values (voltage and current) and send them in a ros message 
*/

#include <ros.h>
#include <battery_sensor_msgs/Measures.h>
#include <battery_sensor_msgs/ListMeasures.h>
#include <Sensor.h>

#include <Arduino.h>

Sensor S1 = Sensor(0,1);
Sensor S2 = Sensor(2,3);
Sensor S3 = Sensor(4,5);

ros::NodeHandle nh;

battery_sensor_msgs::Measures measures_msg_1;
battery_sensor_msgs::Measures measures_msg_2;
battery_sensor_msgs::Measures measures_msg_3;

battery_sensor_msgs::ListMeasures list_measures_msg;

ros::Publisher pub("listMeasures", &list_measures_msg);


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

  measures_msg_1.name = "battery1";
  measures_msg_2.name = "battery2";
  measures_msg_3.name = "battery3";

  /*
  Serial.begin(9600);
  */
}


long msg_delay = 1000; //TODO 4000 for the experiment, 100 for the normal utilisation (10 Hz)
long new_millis;
long last_millis = millis();


void loop()
{  
  new_millis = millis();
  
  if( (new_millis - last_millis) > msg_delay)
  {

    S1.updateMeasures();
    measures_msg_1.voltage = S1.getVoltage();
    measures_msg_1.current = S1.getCurrent();
    measures_msg_1.SOC = S1.getSOC();

    S2.updateMeasures();
    measures_msg_2.voltage = S2.getVoltage();
    measures_msg_2.current = S2.getCurrent();
    measures_msg_2.SOC = S2.getSOC();

    S3.updateMeasures();
    measures_msg_3.voltage = S3.getVoltage();
    measures_msg_3.current = S3.getCurrent();
    measures_msg_3.SOC = S3.getSOC();

    list_measures_msg.listMeasuresMsgs[0] = measures_msg_1;
    list_measures_msg.listMeasuresMsgs[1] = measures_msg_2;
    list_measures_msg.listMeasuresMsgs[2] = measures_msg_3;

    pub.publish(&list_measures_msg);
    nh.spinOnce();

    /*
    Serial.print("freeRam()=");
    Serial.println(freeRam());
    */

    last_millis = new_millis;
  }
  
}
