/*
 * subscribe to the topic "measures" and store the data in a text file (Time, Voltage, Current)
 */


#include "ros/ros.h"
#include "battery_sensor_msgs/Measures.h"
#include "battery_sensor_msgs/ListMeasures.h"

#include <iostream>
#include <vector>
#include <fstream>


std::vector<ros::Time> time_vector;
std::vector<float> voltage_vector;
std::vector<float> current_vector;


void storeMeasures(const battery_sensor_msgs::ListMeasures::ConstPtr& msg)
{
  battery_sensor_msgs::Measures measures_msg_1 = msg->listMeasuresMsgs[0];
  ROS_INFO("Voltage: %f", measures_msg_1.voltage);
  ROS_INFO("Current: %f", measures_msg_1.current);
  //ROS_INFO_STREAM("Time: " << ros::Time::now());
  //ROS_INFO("Reading data...");
  time_vector.push_back(ros::Time::now());
  voltage_vector.push_back(measures_msg_1.voltage);
  current_vector.push_back(measures_msg_1.current);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("listMeasures", 1000, storeMeasures);

  /*
  ros::Rate rate(10);

  while (ros::ok())
  {
    ros::spinOnce();
    rate.sleep();
  }
  */

  ros::spin();

  std::ofstream measures_file;
  measures_file.open("./thor_doc/SOC_experiment/measures.txt");
  //measures_file.open("measures.txt");

  for (unsigned int i = 0; i < voltage_vector.size(); i++) {
    measures_file << time_vector[i] << ", ";
    measures_file << voltage_vector[i] << ", ";
    measures_file << current_vector[i] << "\n";
  }

  measures_file.close();

  printf("Measures stored. \n");

  return 0;
}
