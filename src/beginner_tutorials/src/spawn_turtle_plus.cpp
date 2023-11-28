#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <std_srvs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <beginner_tutorials/ChangeSpeed.h>

bool forward = true;
double turtle_speed = 5;

bool toggleForward(
    std_srvs::Empty::Request &req,
    std_srvs::Empty::Response &resp){
        forward = !forward;
        ROS_INFO_STREAM("Now sending "<<(forward?
                "stop":"rotate")<< " commands.");
        return true;
}

bool changeSpeed(
    beginner_tutorials::ChangeSpeed::Request &req,
    beginner_tutorials::ChangeSpeed::Response &res) {
    turtle_speed = req.new_speed;
    ROS_INFO_STREAM("Changed turtle speed to: " << turtle_speed);
    res.success = true;
    return true;
}

void turtleVel(const geometry_msgs::Twist& msg) {
    ROS_INFO_STREAM("cmd_vel Linear: " << msg.linear.x << ", Angular: " << msg.angular.z);
}   

int main(int argc, char **argv){

    ros::init(argc, argv, "spawn_turtle");
    ros::NodeHandle nh;

    ros::ServiceClient spawnClient
		= nh.serviceClient<turtlesim::Spawn>("spawn");

    turtlesim::Spawn::Request req;
    turtlesim::Spawn::Response resp;

    req.x = 2;
    req.y = 3;
    req.theta = M_PI/2;
    req.name = "Leo";

    ros::service::waitForService("spawn", ros::Duration(5));
    bool success = spawnClient.call(req,resp);

    if(success){
	ROS_INFO_STREAM("Spawned a turtle named "
			<< resp.name);
    }else{
	ROS_ERROR_STREAM("Failed to spawn.");
    }

    ros::ServiceServer server_toggle_forward = 
        nh.advertiseService("toggle_forward", &toggleForward);

    ros::ServiceServer server_change_speed =
        nh.advertiseService("change_speed", &changeSpeed);

    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>(
		"turtle1//cmd_vel",1000);
    ros::Publisher pu=nh.advertise<geometry_msgs::Twist>(
		"Leo//cmd_vel",1000);

    ros::Subscriber sub = nh.subscribe(
        "turtle1/cmd_vel", 1000, turtleVel);

    /*ros::Subscriber cmdVelSub = nh.subscribe(
        "turtle1/cmd_vel", 10, cmdVelCallback);*/


    ros::Rate rate(10);
    while(ros::ok()){

        geometry_msgs::Twist msg;
            msg.angular.z=forward?0.0:turtle_speed;
		pub.publish(msg);
        pu.publish(msg);
        ros::spinOnce();
        rate.sleep();
    }

}
