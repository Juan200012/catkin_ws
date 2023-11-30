#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <geometry_msgs/Twist.h>

ros::Publisher cmdVelPub;

// Callback funtion of the sucriber

void turtleVel(const geometry_msgs::Twist::ConstPtr &msg)
{
    ROS_INFO_STREAM("Received cmd_vel: Linear X=" << msg->linear.x
                  << ", Linear Y=" << msg->linear.y
                  << ", Angular Z=" << msg->angular.z);

    geometry_msgs::Twist invertedMsg = *msg;
    if (msg->linear.x)
    {
        invertedMsg.linear.x = -invertedMsg.linear.x;
    }

    if (msg->linear.y)
    {
        invertedMsg.linear.y = -invertedMsg.linear.y;
    }

    if (msg->angular.z)
    {
        invertedMsg.angular.z = -invertedMsg.angular.z;
    }

    cmdVelPub.publish(invertedMsg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_second_turtle");
    ros::NodeHandle nh;

    // Spawning a new turtle

    ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("spawn");

    turtlesim::Spawn::Request req;
    turtlesim::Spawn::Response resp;

    req.y = 5; 
    req.x = 5;

    // Publisher of the opposite velocities for the second turtle

    cmdVelPub = nh.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 1);

    // Subscriber for the first-turtle-velocities topic

    ros::Subscriber cmdVelSub = nh.subscribe("turtle1/cmd_vel", 1, turtleVel);

    ros::service::waitForService("spawn", ros::Duration(5));

    bool success = spawnClient.call(req, resp);

    if (success)
    {
        ROS_INFO_STREAM("Spawned a turtle named " << resp.name);
    }
    else
    {
        ROS_ERROR_STREAM("Failed to spawn.");
    }

    ros::spin();

    return 0;
}
