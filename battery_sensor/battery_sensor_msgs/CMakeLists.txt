cmake_minimum_required(VERSION 2.8.3)
project(battery_sensor_msgs)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
   std_msgs
   message_generation
)


add_message_files(
 # DIRECTORY msg
  FILES
  Measures.msg
  ListMeasures.msg
)


generate_messages(
  DEPENDENCIES
  std_msgs
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES battery_sensor_msgs
  CATKIN_DEPENDS std_msgs message_runtime
#  DEPENDS system_lib
)


install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

