cmake_minimum_required(VERSION 2.8.3)
project(fake_laser_scan)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(fakeLaserScan src/fakeLaserScan.cpp)
target_link_libraries(fakeLaserScan ${catkin_LIBRARIES})
add_dependencies(fakeLaserScan fake_laser_scan_generate_messages_cpp)


include_directories(
  ${catkin_INCLUDE_DIRS}
)


