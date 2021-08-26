#include "utils.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "ped/utenti.h"
#include "/home/me/labiagi_2020_21/workspaces/srrg2_labiagi/devel/include/srrg2_core_ros/PlannerStatusMessage.h"
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
geometry_msgs::PoseStamped goal;
string s;
ped::utenti m;
ros::Publisher talk;
ros::Subscriber listener;
ros::Publisher pub_goal;
ros::Subscriber pub_status;
int prima_volta=0;
list<utente> l;
string opzioni="";
stringstream ss;
bool movimento=false;
bool libero=true;
bool aspetta=false;
bool inizia=false;
bool ritirato=false;
float distanza=0;


void CB(const ped::utenti::ConstPtr& msg){
	cout << "name: "<< msg->name << "  option: " << msg->option << "   pick: " << msg->pick << "   delivery: " << msg->delivery << endl;
	if(msg->option=="IN"){
		for(auto& k : l){
			if(k.name==msg->name) {
				k.n++;
				cout << k.name << " " << k.n << endl;
			}
		}
	}
	else if(msg->option=="OUT"){
		for(auto& k : l){
			if(k.name==msg->name){
				k.n--;
				cout << k.name << " " << k.n << endl;
			}
		}
	}
	else if(msg->option=="pacco-ritirato"){
		cout << "pacco ritirato correttamente" << endl;
		ritirato=true;
	}
	else if(msg->pick!="" && msg->delivery!=""){
		if(libero==false){
			m.response="occupato";
			m.option="";m.name=msg->name;
			m.pick="";m.delivery="";
			talk.publish(m);
			m.name=""; m.option="";m.pick="";m.delivery="";m.response="";
			ros::spinOnce();
			return;
		}
		else{
			libero=false;
			bool pick_trovato=false;
			bool delivery_trovato=false;
			float pick_x; float delivery_x; float pick_n;
			float pick_y; float delivery_y; float delivery_n;
			for(auto& k : l){
				if(k.name==msg->pick){
					pick_x=k.x;
					pick_y=k.y;
					pick_n=k.n;
					pick_trovato=true;
				}
				else if(k.name==msg->delivery){
					delivery_trovato=true;
					delivery_x=k.x;
					delivery_y=k.y;
					delivery_n=k.n;
				}
			}
			
			if(delivery_trovato==false){
				m.response="delivery-non-trovato";
				m.name=msg->name;
				talk.publish(m);
				ros::spinOnce();
				m.name=""; m.option="";m.pick="";m.delivery="";m.response="";
				libero=true;
				return;
			}
			else if(pick_trovato==false){
				m.response="pick-non-trovato";
				m.name=msg->name;
				talk.publish(m);
				ros::spinOnce();
				m.name=""; m.option="";m.pick="";m.delivery="";m.response="";
				libero=true;
				return;
			}
			else if(pick_n==0){
				m.response="nessuno-per-prendere-il-pacco";
				m.name=msg->pick;
				talk.publish(m);
				ros::spinOnce();
				m.name=""; m.option="";m.pick="";m.delivery="";m.response="";
				libero=true;
				cout << m.name << endl;
				return;
			}
			else if(delivery_n==0){
				m.response="nessuno-per-ritirare-il-pacco";
				m.name=msg->pick;
				talk.publish(m);
				ros::spinOnce();
				m.name=""; m.option="";m.pick="";m.delivery="";m.response="";
				cout << m.name << endl;
				libero=true;
				return;
			}
			
			m.name=msg->delivery;
			m.option="devi-ritirare";
			talk.publish(m);
			ros::spinOnce();
			m.name=""; m.option="";m.pick="";m.delivery="";m.response="";
			
			goal.header.stamp=ros::Time::now();
			goal.header.frame_id="map";
			goal.pose.position.x=pick_x;
			goal.pose.position.y=pick_y;
			pub_goal.publish(goal);
			cout << pick_x << " " << pick_y << endl;
			ros::spinOnce();
			
			cout << red;
			cout << "inizio ad aspettare" << endl;
			cout << fine;
			movimento=true;
			
			
			while(ros::ok()){
				if(aspetta) break;
				ros::spinOnce();
			}
			
			
			aspetta=false;
			movimento=false;
			
			cout << red;
			cout << "finito di aspettare" << endl;
			cout << fine;
			
			
			goal.header.stamp=ros::Time::now();
			goal.header.frame_id="map";
			goal.pose.position.x=delivery_x;
			goal.pose.position.y=delivery_y;
			pub_goal.publish(goal);
			cout << delivery_x << " " << delivery_y << endl;
			
			
			cout << red;
			cout << "inizio ad aspettare" << endl;
			cout << fine;
			movimento=true;
			
			while(ros::ok()){
				if(aspetta) break;
				ros::spinOnce();
			}
			aspetta=false;
			
			cout << red;
			cout << "finito di aspettare" << endl;
			cout << fine;
			
			m.name=msg->delivery;
			m.option="pacco-arrivato";
			talk.publish(m);
			m.name=""; m.option="";m.pick="";m.delivery="";m.response="";
			
			cout << "apetto che l'utente prenda il pacco per un massimo di 20 secondi" << endl;
			int start =ros::Time::now().toSec();
			int end;
			
			while(ros::ok()){
				if(ritirato) break;
				end=ros::Time::now().toSec();
				if(end>start+20) break;
				ros::spinOnce();
			}
			
			m.name=msg->name;
			m.pick="";m.delivery="";m.option="";
			m.response="finito";
			talk.publish(m);
			ros::spinOnce();
			m.name=""; m.option="";m.pick="";m.delivery="";m.response="";
			
			cout << blue;
			cout << "PACCO SPEDITO, PRONTO PER UN PROSSIMO INCARICO" << endl;
			cout << fine;
			
			movimento=false;
			libero=true;
			
		}
	}
	return;
}

void stato_robot(const srrg2_core_ros::PlannerStatusMessage::ConstPtr& status){
	//cout << movimento << "  " << status->distance_to_global_goal << endl;
	if(movimento){
		if(status->distance_to_global_goal>distanza){
			movimento=false;
			inizia=true;
		}
		else distanza=status->distance_to_global_goal;
	}
	else if(inizia && status->distance_to_global_goal<0.8){
		aspetta=true;
		movimento=false;
		inizia=false;
	}
	else distanza=status->distance_to_global_goal;
	return;
}

int main(int argc, char** argv){
	//inizializzo il nodo e creo il nodehandle
	ros::init(argc, argv, "ped_server");
	ros::NodeHandle n;
	
	//publisher necessario per avvisare il robot che deve raggiungere un determinato goal
	pub_goal = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
	
	pub_status = n.subscribe("/planner_status", 1000, stato_robot);
	
	talk = n.advertise<ped::utenti>("/ped_stc",1000);
	listener = n.subscribe("/ped_cts",1000,CB);
	
	if(prima_volta==0){
		
		//ADESSO È IL CLIENT CHE GESTISCE GLI UTENTI
		string s;
		float x;
		float y;
		ifstream inFile;
		
		inFile.open("/home/me/progetto_labiagi/src/ped/src/stanze.txt");
		if (!inFile) {
			cout << "Unable to open file" << endl;
			exit(1); // terminate with error
		}
    
		while (inFile >> s >> x >> y ) {
			ss << s << " " << x << " " << y << "\n";
			utente tmp=utente(s,x,y);
			l.push_back(tmp);
			cout << tmp.name << " " << tmp.x << " " << tmp.y << " " << tmp.n << endl << flush;
		}
		opzioni=ss.str();
	}
	
	ros::spin();
	return 0;
}




