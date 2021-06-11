#include "utils.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "/home/me/labiagi_2020_21/workspaces/srrg2_labiagi/devel/include/srrg2_core_ros/PlannerStatusMessage.h"

using namespace std;
int i=0;
int k=0;
float dist=0;
float dist_att=0;
int p=0;
bool sessione=false;
bool finito=true;

geometry_msgs::PoseStamped goal;
vector<float> v = {1,2,3,4,5,6,7,8};

void robot_status(const srrg2_core_ros::PlannerStatusMessage::ConstPtr& status){
	
			if(status->distance_to_global_goal>dist){
			dist=status->distance_to_global_goal;
		}
	if(k<4 and finito){
		cout << purple;
		cout << "PRIMA VOLTA" << endl;
		cout << fine;
		if(k==3) sessione=false;
	}
	else if(!sessione and finito){
		cout << purple;
		cout << "SECONDA VOLTA" << endl;
		cout << fine;
		dist_att=dist-status->distance_to_global_goal;
		p=(dist_att/dist)*100;
		
		cout << blue;
		cout << "dist: " << dist << "   dist_att: " << dist_att << "   p: " << p << endl;
		cout << fine;
	}
	if(v.at(0)==v.at(1) and v.at(1)==v.at(2) and v.at(2)==v.at(3) and v.at(3)==v.at(4) and v.at(4)==v.at(5) and v.at(5)==v.at(6)
		and v.at(6)==v.at(7) and finito){
			cout << purple;
			cout << "FINITO" << endl;
			cout << fine;
			finito=false;
	}
	v.insert(v.begin()+i,status->distance_to_global_goal);
	k++;
	i++;
	i=i%8;
	
}


int main(int argc, char** argv){
	ros::init(argc, argv, "ped_client");
	ros::NodeHandle n;
	
	ros::Subscriber pub_status = n.subscribe("/planner_status", 1000, robot_status);
	ros::Publisher pub_goal = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
	

	while(ros::ok()){
		sessione=true;
		i=0;
		dist=0;
		dist_att=0;
		p=0;
		goal.header.frame_id="map";
		cout << "x: "; cin >> goal.pose.position.x;
		cout << "y: "; cin >> goal.pose.position.y;
		goal.header.stamp = ros::Time::now();
		pub_goal.publish(goal);
		ros::spin();
		
		
	}
	cout << "fine" << endl;
	
}

/*
--devo prendere da /planner_status la distanza per calcolare la percentuale a cui si torva il robot

--devo prendere le coordinate del robot mentre si muove per assicurarmi che no si sia schiantato



*/
