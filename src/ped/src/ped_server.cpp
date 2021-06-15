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
bool loop=false;
string username;
float pos_x;
float pos_y;
vector<string> result;
ros::Publisher pub_goal;


void CB(const std_msgs::String::ConstPtr& msg){
	cout << "ho sentito: " << msg->data.c_str() << endl << flush;
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
		p=false;
		return;
	}
	if(msg->data=="opzioni"){
		m.data="opzioni";
		talk.publish(m);
		ros::spinOnce();
		cout << "ho mandato: " << m.data.c_str() << endl << flush;
	}
	else if(msg->data=="pick"){
		cout << "pick" << endl << flush;
		p=true;
	}
	else{
		m.data=msg->data;
		talk.publish(m);
		ros::spinOnce();
		cout << "ho mandato: " << m.data.c_str() << endl << flush; 
	}
}

void nulla(const std_msgs::String::ConstPtr& msg){
	//ROS_INFO("IL ROBOT HA SCRITTO: %s",msg->data.c_str());
}

int main(int argc, char** argv){
	//inizializzo il nodo e creo il nodehandle
	ros::init(argc, argv, "ped_client");
	ros::NodeHandle n;
	
	//publisher necessario per avvisare il robot che deve raggiungere un determinato goal
	pub_goal = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
	
	talk = n.advertise<std_msgs::String>("/ped_stc",1000);
	listener = n.subscribe("/ped_cts",1000,CB);
	
	/// il momentaneo problema è che non so come fare per aspettare che il robot sia arrivato al goal, poichè quando provo
	/// ad usare funzioni come waitForMessage su un topic quello che succede è che è come se non venissero chiamate le
	/// funzioni di callback. allo stesso modo anche usando un ciclo while che aspetta fino a quando una variabile non 
	/// viene modificata non va poichè anche qui non vengon visualizzate le print presneti nella funzione di callback
	/// e quindi non viene eseguita tale funzione. non so come risovere questo problema devo chiedere al prof
	
	ros::spin();
	return 0;
}


///l'idea che mi era venuta in mente era quella di:
/// 1. chiedere all'utente le posizioni da far raggiungere al robot
/// 2. aspettare che il robot arrivi al punto stabilito
/// 3. aspettare che si riceva un messaggio (per segnalare che il pacco è stato messo)
/// 4. chiedere all'utente le coordinate dove il robot deve andare per spedire il pacco
/// 5. aspettare fino a quando il robot non raggiunge le coordinate inserite precedentemente
/// 6. aspettare che il pacco venga preso
/// 7.ripetere l'azione


//pre ora il problema principale sta nella realizzazione del punto 2. poichè non so come far aspettare un nodo. so farlo con le 
//so farlo usanod le actionlib ma non so farlo usando solamente i publisher e subscriber. 

//finchè non risolvo il punto 2- non posso andare avanti e fare i punti seguenti, poichè il punto 5 è identico al punto 2 e 
//il punto 7 implicherà cambiare delle cose ma si vedrà in seguito

