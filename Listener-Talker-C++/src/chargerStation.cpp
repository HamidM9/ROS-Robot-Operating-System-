#include "ros/ros.h"
#include "exercise1/message1.h"
#include <cstdio>
#include<string.h>
void messageCallback(const exercise1::message1::ConstPtr& msg)
{
ROS_INFO("I heard: [%d] [%d] [%s] " , msg->roomID, msg->battryLevel, msg->roomName.c_str());
}
int main(int argc, char **argv)
{
ros::init(argc, argv, "chargerstation");
ros::NodeHandle n;
ros::Subscriber sub = n.subscribe("message",
5000, messageCallback);
ros::spin();
return 0;
}
