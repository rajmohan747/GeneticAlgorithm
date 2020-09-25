cmake_minimum_required(VERSION 2.8.3)
project(genetic_algorithm)

add_compile_options(-std=c++11)


find_package(catkin REQUIRED COMPONENTS
  
  geometry_msgs
  roscpp
  rospy
  std_msgs
  roslib
  message_generation

  

)









catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS
    
    geometry_msgs
    roscpp
    rospy
    std_msgs

)


###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/include/genetic_algorithm
)


add_executable(genetic_algorithm
  src/genetic_algorithm.cpp
  src/individual_chromosome.cpp



)

target_link_libraries(genetic_algorithm
  ${catkin_LIBRARIES}
)



add_executable(graph
  src/graph.cpp
)

target_link_libraries(graph
  ${catkin_LIBRARIES}
)
