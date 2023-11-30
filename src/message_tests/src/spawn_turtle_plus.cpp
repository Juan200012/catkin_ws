//This program spawns a new turtlesim turtle by calling
// the appropriate service.
#include <ros/ros.h>
//The srv class for the service.
#include <turtlesim/Spawn.h>
#include <cstdlib>
#include <std_srvs/Empty.h>
#include <message_tests/Changespeed.h>

int main(int argc, char **argv){

    ros::init(argc, argv, "spawn_turtle");
    ros::NodeHandle nh;

//Create a client object for the spawn service. This
//needs to know the data type of the service and its name.
    ros::ServiceClient spawnClient
		= nh.serviceClient<turtlesim::Spawn>("spawn");

    ros::ServiceClient Client0 = nh.serviceClient<std_srvs::Empty>("toggle_forward");
    ros::ServiceClient Client1 = nh.serviceClient<message_tests::Changespeed>("cambiarvel");
//Create the request and response objects.
    turtlesim::Spawn::Request req;
    turtlesim::Spawn::Response resp;
    message_tests::Changespeed srv1;
    std_srvs::Empty srv;

    req.x = 2;
    req.y = 3;
    srv1.request.newspeed = 5.0;
    req.theta = M_PI/2;
    req.name = "Leo";



    ros::service::waitForService("spawn", ros::Duration(5));
    ros::service::waitForService("toggle_forward", ros::Duration(5));
    ros::service::waitForService("cambiarvel", ros::Duration(5));
    bool success = spawnClient.call(req,resp);
    bool success2 = Client0.call(srv);
    bool success3 = Client1.call(srv1);

    if(success){
	ROS_INFO_STREAM("Spawned a turtle named "
			<< resp.name);
    }else{
	ROS_ERROR_STREAM("Failed to spawn.");
    }
}
