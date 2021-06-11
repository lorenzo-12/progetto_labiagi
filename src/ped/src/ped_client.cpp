#include "utils.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "/home/me/labiagi_2020_21/workspaces/srrg2_labiagi/devel/include/srrg2_core_ros/PlannerStatusMessage.h"

using namespace std;
geometry_msgs::PoseStamped goal;

//serve per inserire i valori della distanza allìinterno del vettore e fare in modo che tali valori 
//vengano inseriti in cerchio
int i=0;

//serve per tener traccia delle volte che è stata chiamata la funzione di callBack
int k=0;

//rappresenta la distanza massima tra il punto di partenza del robot e il punto di arrivo
float dist=0;

//rappresenta la distanza del robot istante per istante
float dist_att=0;

//rappresenta la percentuale di completamento del percorso
int p=0;

bool sessione=false; //serve per far si che la funzione di callback "robot_status" venga eseguita solamente quando il robot sta 
				     //eseguendo un'azione
				     
ros::Publisher pub_in;
string s;
std_msgs::String msg;
vector<float> v = {1,2,3,4,5,6}; //vettore ceh server per capire quando il robot è arrivato (dato che la distanza dal gol 
								 //non arriva mai a zero preciso)



void robot_status(const srrg2_core_ros::PlannerStatusMessage::ConstPtr& status){
	
	//la prima volta (per sessione) che viene chiamata la funzione si aspettano 2 secondi in modo da evitare che i precedenti
	//messaggi presenti sul topic vengano usati e mandino lo stato direttamente in FINITO
	if(k==0)  ros::Duration(2, 0).sleep();
	
	//siccome capita che tra i primi messaggi ci siano alcuni vecchi (con una distanza vicina allo zero) se nell/andare avanti
	//la distanza aumenta imposto la distanza totale del percorso al valore maggiore che ho ottenuto
	if(status->distance_to_global_goal>dist){
		dist=status->distance_to_global_goal;
	}
	
	//se non sono arrivato alla fine stampo dei valori tra cui la percentuale del cammino che si è fatto
	if(sessione){
		dist_att=dist-status->distance_to_global_goal;
		p=(dist_att/dist)*100;
		if(p<0) p=0;
		cout << "\rdist: " << setprecision(4) << dist << "  dist_att: "<< fixed << setprecision(4) << dist_att;
		cout << red;
		cout << "  p: " << p << "% " << flush;
		//s = to_string(p);
		//msg.data=s;
		//pub_in.publish(msg);
		cout << fine;
	}
	
	//mi accorgo che sono arrivato alla fine del percorso perchè i valori della distanza del robot dal goal
	//pubblicati sul topic "/planner_status" smettono di variare, quindi nel momento in cui per 6 volte mi ritrovo la distanza 
	//sempre uguale considero che sono arrivato
	if(v.at(0)==v.at(1) and v.at(1)==v.at(2) and v.at(2)==v.at(3) and v.at(3)==v.at(4) and v.at(4)==v.at(5) and sessione){
		cout << "\rdist: " << setprecision(4) << dist << "  dist_att: "<< fixed << setprecision(4) << dist_att;
		cout << red;
		cout << "  p: 100%" << " " << flush;
		cout << fine;
		//s="100";
		//msg.data=s;
		//pub_in.publish(msg);
		sessione=false;
	}
	
	//ad ogni chiamata della funzione incremento le variabili e aggiungo nella prossiam posizione del vettore v il valore della
	//distanza, in modo che quando tutte e 6 le posizioni del vettore avranno lo stesso valore allora potrò considerare 
	//il robot arrivato al goal
	if(sessione){
		v.insert(v.begin()+i,status->distance_to_global_goal);
		k++;
		i++;
		i=i%6;
	}
	
}


int main(int argc, char** argv){
	//inizializzo il nodo e creo il nodehandle
	ros::init(argc, argv, "ped_client");
	ros::NodeHandle n;
	
	//pub_in = n.advertise<std_msgs::String>("/stato_robot",1000);
	
	//subscriber al topic /planner_status dove è presente la distanza del robot dal goal
	ros::Subscriber pub_status = n.subscribe("/planner_status", 1000, robot_status);
	
	//publisher necessario per avvisare il robot che deve raggiungere un determinato goal
	ros::Publisher pub_goal = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
	
	//inizializzo le variabili
	sessione=true;
	i=0; dist=0; dist_att=0; p=0;
	
	//chiedo in input all'utente le posizioni x e y che il robot deve raggiungere
	//e le inserisco all'interno del goal
	goal.header.frame_id="map";
	cout << "x: "; cin >> goal.pose.position.x;
	cout << "y: "; cin >> goal.pose.position.y;
	goal.header.stamp = ros::Time::now();
	
	//pubblico il goal sul topic "/move_base_simple/goal" in modo da far muovere il robot
	pub_goal.publish(goal);
	
	
	ros::spin();
	return 0;
}

