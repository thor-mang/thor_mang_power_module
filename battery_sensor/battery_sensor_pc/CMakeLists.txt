cmake_minimum_required(VERSION 2.8.3)
project(battery_sensor_pc)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  battery_sensor_msgs
)


catkin_package(
  CATKIN_DEPENDS roscpp std_msgs battery_sensor_msgs
)


set(HEADERS
)

set(SOURCES
  src/listener.cpp
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
#add_dependencies(listener battery_sensor_pc_generate_messages_cpp)




