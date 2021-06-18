#include "utils.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "/home/me/labiagi_2020_21/workspaces/srrg2_labiagi/devel/include/srrg2_core_ros/PlannerStatusMessage.h"
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>

using namespace std;
geometry_msgs::PoseStamped goal;
string s;
std_msgs::String m;
ros::Publisher talk;
ros::Subscriber listener;
bool p=false;
bool d=false;
bool loop=false;
bool aspetta=false;
bool ok=false;
string username;
float pos_x;
float pos_y;
int k=0;
vector<string> result;
ros::Publisher pub_goal;
ros::Subscriber pub_status;
vector<float> v = {1,2,3,4};
float dist_max=0;
int completamento=0;
string password="";
int psw_count=0;



void CB(const std_msgs::String::ConstPtr& msg){
	cout << "ho sentito: " << msg->data.c_str() << endl << flush;
	//cout << "p: " << p << "   d: " << d << endl << flush;
	if(p){
		s=msg->data;
		boost::split(result, s, boost::is_any_of(" "));
		
		username=result[0]; pos_x=stof(result[1]); pos_y=stof(result[2]);
		
		cout << "username: " << username << "   x: " << pos_x << "   y: " << pos_y << endl << flush;
		goal.header.frame_id="map";
		goal.header.stamp = ros::Time::now();
		goal.pose.position.x=pos_x;
		goal.pose.position.y=pos_y;
		pub_goal.publish(goal);
		ok=true;
		
		while(ros::ok()){
			if(aspetta) break;
			ros::spinOnce();
		}
		
		//cout << red;
		//cout << "fine ciclo while" << endl << flush;
		//cout << fine;
		
		m.data="pick";
		talk.publish(m);
		ros::spinOnce();
		
		aspetta=false;
		ok=false;
		p=false;
		return;
	}
	if(d){
		s=msg->data;
		boost::split(result, s, boost::is_any_of(" "));
		
		username=result[0]; pos_x=stof(result[1]); pos_y=stof(result[2]);
		
		cout << "username: " << username << "   x: " << pos_x << "   y: " << pos_y << endl << flush;
		goal.header.frame_id="map";
		goal.header.stamp = ros::Time::now();
		goal.pose.position.x=pos_x;
		goal.pose.position.y=pos_y;
		pub_goal.publish(goal);
		ok=true;
		
		while(ros::ok()){
			if(aspetta) break;
			ros::spinOnce();
		}
		//cout << red;
		//cout << "fine ciclo while" << endl << flush;
		//cout << fine;
		
		m.data="delivery";
		talk.publish(m);
		ros::spinOnce();
		
		aspetta=false;
		ok=false;
		d=false;
		return;
	}
	if(msg->data=="psw"){
		
		m.data="psw";
		talk.publish(m);
		ros::spinOnce();
		
		m.data=password;
		talk.publish(m);
		ros::spinOnce();
	}
	if(msg->data=="opzioni"){
		m.data="opzioni";
		talk.publish(m);
		ros::spinOnce();
		//cout << "ho mandato: " << m.data.c_str() << endl << flush;
	}
	else if(msg->data=="pick"){
		//cout << "pick" << endl << flush;
		p=true;
	}
	else if(msg->data=="delivery"){
		//cout << "delivery" << endl << flush;
		d=true;
	}
	else{
		m.data=msg->data;
		talk.publish(m);
		ros::spinOnce();
		//cout << "ho mandato: " << m.data.c_str() << endl << flush; 
	}
}

void stato_robot(const srrg2_core_ros::PlannerStatusMessage::ConstPtr& status){
	k++;
	if(ok){
		if(status->distance_to_global_goal>dist_max){
			dist_max=status->distance_to_global_goal;
		}
		completamento=(dist_max-status->distance_to_global_goal)*100/dist_max;
		cout << "\rstatus distance: ";
		cout << lightblue;
		cout << fixed << setprecision(4) << status->distance_to_global_goal << flush;
		cout << fine;
		cout << " completamento: " << flush;
		if(completamento<33) cout << red;
		else if(completamento<70) cout << yellow;
		else if(completamento>=70) cout << green;
		cout << fixed << setprecision(4) << completamento << "% " << flush;
		cout << fine;
		for(int aux=0; aux<30; aux++){
			if(completamento<33) cout << red;
			else if(completamento<70) cout << yellow;
			else if(completamento>=70) cout << green;
			if(aux==0) cout << "  [" << flush;
			if(aux<0.3*completamento) cout << "#" << flush;
			else cout << "." << flush;
			cout << fine;
		}
		cout << "]  " << flush;
		v.insert(v.begin()+k%4,status->distance_to_global_goal);
	}
	if(v.at(0)==v.at(1) and v.at(1)==v.at(2) and v.at(2)==v.at(3) and ok){
		cout << "\rstatus distance: ";
		cout << lightblue;
		cout << fixed << setprecision(4) << status->distance_to_global_goal << flush;
		cout << fine;
		cout << " completamento: " << flush;
		cout << green;
		cout << "100%" << flush;
		cout << fine;
		cout << green;
		cout << "   [#############################]  " << flush;
		cout << fine;
		cout << endl << flush;
		aspetta=true;
		dist_max=0;
		v = {1,2,3,4};
	}
	return;
}

int main(int argc, char** argv){
	//inizializzo il nodo e creo il nodehandle
	ros::init(argc, argv, "ped_client");
	ros::NodeHandle n;
	
	//publisher necessario per avvisare il robot che deve raggiungere un determinato goal
	pub_goal = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
	
	pub_status = n.subscribe("/planner_status", 1000, stato_robot);
	
	talk = n.advertise<std_msgs::String>("/ped_stc",1000);
	listener = n.subscribe("/ped_cts",1000,CB);
	
	if(psw_count==0){
		psw_count++;
		cout << "DIGITARE LA PASSWORD: "; cin >> password;
		cout << endl << flush;
	}
	
	ros::spin();
	return 0;
}




