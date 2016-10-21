cmake_minimum_required(VERSION 2.8.3)
project(battery_sensor_arduino)

find_package(catkin REQUIRED COMPONENTS
  rosserial_arduino
  rosserial_client
  std_msgs
  battery_sensor_msgs
)


catkin_package(
  CATKIN_DEPENDS rosserial_arduino rosserial_client std_msgs battery_sensor_msgs
)

## Specify additional locations of header files
set(HEADERS
    lib/Sensor.h
)

set(SOURCES
  firmware/program.cpp
  lib/Sensor.cpp
)

add_custom_target(dummy SOURCES ${HEADERS} ${SOURCES})

rosserial_generate_ros_lib(
  PACKAGE rosserial_arduino
  SCRIPT make_libraries.py
)

rosserial_configure_client(
  DIRECTORY firmware
  TOOLCHAIN_FILE ${ROSSERIAL_ARDUINO_TOOLCHAIN}
)

rosserial_add_client_target(firmware sensor ALL)
rosserial_add_client_target(firmware sensor-upload)

