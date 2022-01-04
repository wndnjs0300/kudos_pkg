#include "ros/ros.h"
#include "std_msgs/Int8.h"

void numberCallback(const std_msgs::Int8::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->data);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "kudos_publisher");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<std_msgs::Int8>("number", 1000);
  ros::Subscriber sub = nh.subscribe("number", 1000, numberCallback);

  ros::Rate loop_rate(50);
  while (ros::ok())
  {
    std_msgs::Int8 msg;
    msg.data = 1;

    chatter_pub.publish(msg);

    ros::spinOnce();


    loop_rate.sleep();
  }

  return 0;
}
