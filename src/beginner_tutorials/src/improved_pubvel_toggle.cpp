#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <message_tests/Changerate.h>

bool forward = true;
double newfrequency;
bool ratechanged = false;
ros::Publisher pub;

bool toggleForward(
    std_srvs::Empty::Request &req,
    std_srvs::Empty::Response &resp){
        forward = !forward;
        ROS_INFO_STREAM("Now sending "<<(forward?
                "forward":"rotate")<< " commands.");
        return true;
}

bool changeRate(
        message_tests::Changerate::Request &req,
        message_tests::Changerate::Response &resp){

        ROS_INFO_STREAM("Changing rate to "<<req.newrate);

        newfrequency = req.newrate;
        ratechanged = true;
        return true;
}

bool startTurtle(
    std_srvs::Empty::Request &req,
    std_srvs::Empty::Response &resp){
        forward = true;
        ROS_INFO_STREAM("Starting turtle movement.");
        return true;
}

bool stopTurtle(
    std_srvs::Empty::Request &req,
    std_srvs::Empty::Response &resp){
        forward = false;
        ROS_INFO_STREAM("Stopping turtle movement.");
        return true;
}

int main(int argc, char **argv){
    ros::init(argc,argv,"pubvel_toggle_rate");
    ros::NodeHandle nh;

    ros::ServiceServer server_toggle_forward = 
        nh.advertiseService("toggle_forward", &toggleForward);
    
    ros::ServiceServer server_change_rate =
        nh.advertiseService("change_rate", &changeRate);
    
    ros::ServiceServer server_start_turtle =
        nh.advertiseService("start_turtle", &startTurtle);

    ros::ServiceServer server_stop_turtle =
        nh.advertiseService("stop_turtle", &stopTurtle);

    pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

    ros::Rate rate(2);
    while(ros::ok()){
        geometry_msgs::Twist msg;
        msg.linear.x = forward ? 1.0 : 0.0;
        msg.angular.z = forward ? 0.0 : 1.0;
        pub.publish(msg);
        ros::spinOnce();
        if(ratechanged) {
            rate = ros::Rate(newfrequency);
            ratechanged = false;
        }
        rate.sleep();
    }
}
