#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif
#ifndef min
    #define min(a,b) ((a) < (b) ? (a) : (b))
#endif

#ifndef ROTORS_JOY_INTERFACE_FAKE_DRIVER_H
#define ROTORS_JOY_INTERFACE_FAKE_DRIVER_H

#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include <geometry_msgs/PoseStamped.h>
#include <mav_msgs/RollPitchYawrateThrust.h>
#include <mav_msgs/conversions.h>
#include <mav_msgs/default_topics.h>
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <trajectory_msgs/MultiDOFJointTrajectory.h>


//add direct import (no .h file this is bullshit)

struct Max {
  double v_xy;
  double roll;
  double pitch;
  double rate_yaw;
  double thrust;
};

struct Axes {
  int roll_direction;
  int pitch_direction;
  int thrust_direction;
};

class Test {

 private:

  ros::NodeHandle nh_;
  std::string namespace_;

  ros::Publisher ctrl_pub_;
  ros::Subscriber land_sub_;
  ros::Subscriber takeoff_sub_;
  ros::Subscriber stop_sub_;
  ros::Subscriber move_sub;
  ros::Subscriber odom_sub_;
  ros::Publisher trajectory_pub_;

  trajectory_msgs::MultiDOFJointTrajectory trajectory_msg;
  mav_msgs::RollPitchYawrateThrust control_msg_;
  geometry_msgs::PoseStamped pose_;

  Max max_;
  Axes axes_;

  float test;
  double current_yaw_vel_;
  double desired_yaw;
  double v_yaw_step_;
  float val_ref;
  int x;

  bool is_fixed_wing_;
  void StopMav();
  void MovePublish();
  void Publish();
  void StopCallback(const std_msgs::Empty& msg);
  void LandCallback(const std_msgs::Empty& msg);
  void TakeoffCallback(const std_msgs::Empty& msg);
  void MoveCallback(const geometry_msgs::Twist& msg);
  void OdomCallback(const nav_msgs::Odometry::ConstPtr& msg);
  //void JoyCallback(const sensor_msgs::JoyConstPtr& msg);


 

 public:
  Test();
  float pose_x;
  float pose_y;
  float pose_z;
  bool start;   
  bool move; 

};

#endif