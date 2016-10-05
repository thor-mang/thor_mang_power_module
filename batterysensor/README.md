batterysensor

ROS packages related to read the sensor values (voltage and current) using the arduino and send them in a ROS message

The following ROS packages are part of this repo:

- batterysensor_arduino contains the program that has to be flashed to the Arduino. 

- batterysensor_msgs contains the custom message for sending the values of the measures.


To flash the program on the Arduino :
-> cd ~thor/build/batterysensor_arduino
-> make batterysensor_arduino_firmware_sensor-upload


To launch the communication with the arduino :
-> roscore
-> rosrun rosserial_python serial_node.py /dev/ttyUSB0
(-> rostopic echo measures)
-> rqt_plot measures/voltage