cmake_minimum_required(VERSION 3.0.2)
project(ped)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation
  geometry_msgs
  message_runtime
  roscpp
  std_msgs
  #actionlib_msgs
)


#find_package(HeaderProjectName REQUIRED)
#include_directories(${HeaderProjectName_INCLUDE_DIRS})


## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   utenti.msg

 )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   set_user.srv
# )

## Generate actions in the 'action' folder
#add_action_files(
  #DIRECTORY action
  #FILES msg.action
#)

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
   #actionlib_msgs
 )


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ped
  CATKIN_DEPENDS message_generation roscpp std_msgs #actionlib_msgs
  #DEPENDS system_lib
)

## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(ped_server src/ped_server.cpp)
target_link_libraries(ped_server ${catkin_LIBRARIES})
add_dependencies(ped_server ${ped_EXPORTED_TARGETS})

add_executable(ped_client src/ped_client.cpp)
target_link_libraries(ped_client ${catkin_LIBRARIES})
add_dependencies(ped_client ${ped_EXPORTED_TARGETS})

#add_executable(ped_status src/ped_status.cpp)
#target_link_libraries(ped_status ${catkin_LIBRARIES})
#add_dependencies(ped_status ${ped_EXPORTED_TARGETS})
