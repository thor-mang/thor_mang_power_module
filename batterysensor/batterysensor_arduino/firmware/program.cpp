/*
* read the sensor values (voltage and current) and send them in a ros message 
*/

#include <ros.h>
#include <std_msgs/String.h>
#include <batterysensor_msgs/Measures.h>

#include <Arduino.h>

int pinVoltage = 0;
int pinCurrent = 1;

ros::NodeHandle nh;

batterysensor_msgs::Measures measures_msg;
ros::Publisher pub("measures", &measures_msg);


int averageAnalog(int pin){
  int v=0;
  for(int i=0; i<4; i++) v+= analogRead(pin);
  return v/4;
}


void setup()
{
  nh.initNode();
  nh.advertise(pub);
}


long msg_delay = 100;
long new_millis;
long last_millis = millis();


void loop()
{  
  new_millis = millis();
  
  if( (new_millis - last_millis) > msg_delay)
  {
    measures_msg.voltage = averageAnalog(pinVoltage); //TODO send the real value of the battery voltage using the calculated sensor law
    measures_msg.current = averageAnalog(pinCurrent); //TODO send the real value of the battery current...
    pub.publish(&measures_msg);
    nh.spinOnce();
    
    last_millis = new_millis;
  }
  
}
