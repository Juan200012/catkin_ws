#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <stdlib.h>
#include <time.h>

void turtlePose(const turtlesim::Pose& msg) {
  ROS_INFO_STREAM(std::setprecision(2) << std::fixed
    << "position=(" <<  msg.x << "," << msg.y << ")"
    << " direction=" << msg.theta);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "publish_and_subscribe");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
  ros::Subscriber sub = nh.subscribe("turtle1/pose", 1000, turtlePose);

  srand(time(0));

  ros::Rate rate(2);
  while (ros::ok()) {
    // Obtener la posición actual del robot
    turtlesim::Pose::ConstPtr poseturtle = ros::topic::waitForMessage<turtlesim::Pose>("turtle1/pose");

    // Verificar si se encuentra dentro de la zona segura 
    if(poseturtle->x>=3 && poseturtle->x<=8 && poseturtle->y>=3 && poseturtle->y<=8)
    {
      geometry_msgs::Twist msg;
      msg.linear.x = 1,0;
      msg.angular.z = 2 * double(rand()) / double(RAND_MAX) - 1;

      pub.publish(msg);

      ROS_INFO_STREAM("Sending random velocity command:"
      << " linear=" << msg.linear.x
      << " angular=" << msg.angular.z);
    } 
    else
    {
      geometry_msgs::Twist msg;
      msg.linear.x = double(rand()) / double(RAND_MAX);
      msg.angular.z = 2 * double(rand()) / double(RAND_MAX) - 1;

      pub.publish(msg);

      ROS_INFO_STREAM("Sending random velocity command:"
        << " linear=" << msg.linear.x
        << " angular=" << msg.angular.z);
    }

    rate.sleep();
    ros::spinOnce();
  }
}
