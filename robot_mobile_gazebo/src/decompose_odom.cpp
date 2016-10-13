#include <ros/ros.h>
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/Float64.h"

ros::Publisher pub, pub2, pub3;

void callback(nav_msgs::Odometry odom){
	std_msgs::Float64 f;
	f.data = odom.twist.twist.angular.z;
	pub3.publish(f);
	f.data = odom.twist.twist.linear.x;
	pub.publish(f);
	f.data = odom.twist.twist.linear.y;
	pub2.publish(f);
}


int main(int argc, char **argv){
	ros::init (argc, argv, "teleop");
	ros::NodeHandle n;
	
	ros::Subscriber sub = n.subscribe("/base_pose_ground_truth",1,callback);
	pub = n.advertise<std_msgs::Float64>("/Robot_mobile/x",1);
	pub2 = n.advertise<std_msgs::Float64>("/Robot_mobile/y",1);
	pub3 = n.advertise<std_msgs::Float64>("/Robot_mobile/theta",1);
	ros::spin();
	return 0;
}
	
	