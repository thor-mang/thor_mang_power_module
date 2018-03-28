# battery_sensor

## ROS Packages

ROS packages related to read the sensor values (voltage and current) using the arduino and send them in a ROS message

The following ROS packages are part of this repo:

- battery_sensor_arduino contains the program that has to be flashed to the Arduino. 

- battery_sensor_msgs contains the custom message for sending the values of the measures.

- battery_sensor_pc contains a subscriber to store the measured voltage and current on the pc.


To flash the program on the Arduino:
- cd ~/thor/build/battery_sensor_arduino
- make battery_sensor_arduino_firmware_sensor-upload


To launch the communication with the Arduino:
- roscore
- rosrun rosserial_python serial_node.py /dev/ttyUSB0
- (rostopic echo measures)
- rqt_plot measures/voltage


To print the serial messages comming from the Arduino:
- screen /dev/ttyUSB0 9600


To launch the subscriber (i.e. the storage of the measures on the pc):
- rosrun battery_sensor_pc listener
- (rosrun rqt_graph rqt_graph)

## Arduino Code

'Power_Measure_Arduino.ino' contains a simple script for reading out the sensor values for quick debugging.
