#include "utils.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"

using namespace std;

int main(int argc, char** argv){
	ros::init(argc, argv, "ped_client");
	ros::NodeHandle n;
	
	ros::Publisher pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
	
	geometry_msgs::PoseStamped goal;
	goal.header.frame_id="map";
	cout << "x: "; cin >> goal.pose.position.x;
	cout << "y: "; cin >> goal.pose.position.y;
	//cout << "time: "; cin >> goal.header.stamp.sec;
	goal.header.stamp = ros::Time::now();
	cout << goal.pose.position.x << " " << goal.pose.position.y << endl;
	pub.publish(goal);
	
	ros::spin();
	cout << "fine" << endl;
	
}
