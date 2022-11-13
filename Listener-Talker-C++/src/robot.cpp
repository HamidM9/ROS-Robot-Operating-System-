#include "ros/ros.h"
#include "exercise1/message1.h"
#include <sstream>
#include <cstdio>
#include<string.h>
#include<iostream>
#include <string>
int main(int argc, char **argv)
{
ros::init(argc, argv, "robot");
ros::NodeHandle n;
ros::Publisher pub = n.advertise<exercise1::message1>("message", 5000);
ros::Rate loop_rate(10);



std::string rooms[5] = {"Robot Vision Lab", "SSL Lab", "Neurorobotics Lab", "IAS-Lab", "Autonomous Robotics Lab"};





while (ros::ok())
{
std::stringstream ss;
exercise1::message1 msg;


	   

ROS_INFO(" I publishing " );

msg.roomID =  1+ (rand() % 5); ;
msg.battryLevel =  1+ (rand() % 100);
msg.roomName = rooms[rand()%4] ;
pub.publish(msg);
ros::spinOnce();
loop_rate.sleep();
}
return 0;
}






