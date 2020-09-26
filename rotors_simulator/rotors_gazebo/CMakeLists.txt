cmake_minimum_required(VERSION 2.8.3)
project(rotors_gazebo)

add_definitions(-std=c++11)

#--------------------------#
# Generation of SDF models #
#--------------------------#

# We need Gazebo version >= 3.0.0 to generate iris.sdf file
# (gz sdf ... command needs to be available)
find_package(gazebo REQUIRED)


if(NO_ROS)
  message(STATUS "NO_ROS = true, not building waypoint publisher or hovering example, returning now.")
  return()
endif()

find_package(catkin REQUIRED COMPONENTS gazebo_msgs geometry_msgs mav_msgs roscpp sensor_msgs eigen_conversions)

catkin_package(
  CATKIN_DEPENDS
    gazebo_msgs
    geometry_msgs
    mav_msgs
    roscpp
    sensor_msgs
    nav_msgs
    eigen_conversions
    std_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(waypoint_publisher src/waypoint_publisher.cpp)
target_link_libraries(waypoint_publisher ${catkin_LIBRARIES})
add_dependencies(waypoint_publisher ${catkin_EXPORTED_TARGETS})

add_executable(waypoint_publisher_file src/waypoint_publisher_file.cpp)
target_link_libraries(waypoint_publisher_file ${catkin_LIBRARIES})
add_dependencies(waypoint_publisher_file ${catkin_EXPORTED_TARGETS})

add_executable(hovering_example src/hovering_example.cpp)
target_link_libraries(hovering_example ${catkin_LIBRARIES})
add_dependencies(hovering_example ${catkin_EXPORTED_TARGETS})

add_executable(velocity_control_with_joy src/velocity_control_with_joy.cpp)
target_link_libraries(velocity_control_with_joy ${catkin_LIBRARIES})
add_dependencies(velocity_control_with_joy ${catkin_EXPORTED_TARGETS})

add_executable(fake_driver src/fake_driver.cpp)
target_link_libraries(fake_driver ${catkin_LIBRARIES})
add_dependencies(fake_driver ${catkin_EXPORTED_TARGETS})

add_executable(velocity_control_by_dronet src/velocity_control_by_dronet.cpp)
target_link_libraries(velocity_control_by_dronet ${catkin_LIBRARIES})
add_dependencies(velocity_control_by_dronet ${catkin_EXPORTED_TARGETS})

foreach(dir launch models resource worlds)
   install(DIRECTORY ${dir}/
      DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)

install(TARGETS waypoint_publisher waypoint_publisher_file hovering_example velocity_control_with_joy velocity_control_by_dronet fake_driver
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
