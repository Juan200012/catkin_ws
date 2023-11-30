#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <message_tests/Changerate.h>
#include <message_tests/Changespeed.h>
bool forward = true;
bool inicio = true;
double newfrequency;
double newspeed = 1.0;
bool ratechanged = false;
bool speedchanged = false;

bool toggleForward(
	std_srvs::Empty::Request &req,
	std_srvs::Empty::Response &resp){
        forward = !forward;
        ROS_INFO_STREAM("Now sending "<<(forward?
                "forward":"rotate")<< " commands.");
	return true;
}
bool onoff(
	std_srvs::Empty::Request &req,
	std_srvs::Empty::Response &resp){
        inicio = !inicio;
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

bool changeSpeed(
        message_tests::Changespeed::Request &req,
        message_tests::Changespeed::Response &resp){

        ROS_INFO_STREAM("Changing speed to "<<req.newspeed);

        newspeed = req.newspeed;
        speedchanged = true;
        return true;
}

int main(int argc, char **argv){
        ros::init(argc,argv,"pubvel_toggle_rate");
	ros::NodeHandle nh;
        
	ros::ServiceServer server = 
		nh.advertiseService("toggle_forward",&toggleForward);
                
        ros::ServiceServer server0 =
                nh.advertiseService("change_rate",&changeRate);

        ros::ServiceServer server1 =
                nh.advertiseService("inicio",&onoff);

        ros::ServiceServer server2 =
                nh.advertiseService("cambiarvel",&changeSpeed);

        ros::Publisher pub=nh.advertise<geometry_msgs::Twist>(
		"turtle1/cmd_vel",1000);
        ros::Publisher pub2 =nh.advertise<geometry_msgs::Twist>(
		"Leo/cmd_vel",1000);
    
        ros::Rate rate(2);
	while(ros::ok()){
		geometry_msgs::Twist msg;
                geometry_msgs::Twist msg2;
                if(inicio == true)
                {
                        msg.linear.x = forward?newspeed:0.0;
                        msg.angular.z=forward?0.0:newspeed;
                        msg2.linear.x = forward?newspeed:0.0;
                        msg2.angular.z=forward?0.0:newspeed;
                }
                else
                {
                        msg.linear.x = 0.0;
                        msg.angular.z= 0.0;
                        msg2.linear.x = 0.0;
                        msg2.angular.z= 0.0;
                }
		pub.publish(msg);
                pub2.publish(msg2);
		ros::spinOnce();
                if(ratechanged) {
                    rate = ros::Rate(newfrequency);
                    ratechanged = false;
                }
                if(speedchanged)
                {
                        msg.linear.x = newspeed;
                        msg.angular.z= newspeed;
                        msg2.linear.x = 0.0;
                        msg2.angular.z= 0.0;
                        speedchanged = false;
                }
		rate.sleep();
	}
}
