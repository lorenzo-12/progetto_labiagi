#include "utils.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "/home/me/labiagi_2020_21/workspaces/srrg2_labiagi/devel/include/srrg2_core_ros/PlannerStatusMessage.h"

using namespace std;
geometry_msgs::PoseStamped goal;
ros::Publisher pub_out;
std_msgs::String msg;
vector<float> v = {1,2,3,4};



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
				    
				    
void stato_robot(const srrg2_core_ros::PlannerStatusMessage::ConstPtr& status){
	
	//la prima volta (per sessione) che viene chiamata la funzione si aspettano 2 secondi in modo da evitare che i precedenti
	//messaggi presenti sul topic vengano usati e mandino lo stato direttamente in FINITO
	if(k==0){
		ros::Duration(2, 0).sleep();
		sessione=true;
	}

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
		cout << "  completamento: " << p << "% " << flush;
		cout << fine;
	}
	
	//mi accorgo che sono arrivato alla fine del percorso perchè i valori della distanza del robot dal goal
	//pubblicati sul topic "/planner_status" smettono di variare, quindi nel momento in cui per 6 volte mi ritrovo la distanza 
	//sempre uguale considero che sono arrivato
	if(v.at(0)==v.at(1) and v.at(1)==v.at(2) and v.at(2)==v.at(3) and sessione){
		cout << "\rdist: " << setprecision(4) << dist << "  dist_att: "<< fixed << setprecision(4) << dist_att;
		cout << red;
		cout << "  completamento: 100%" << " " << flush;
		cout << fine;
		string s="robot arrivato";
		msg.data=s;
		cout << endl << flush;
		///cout << "invio la risposta" << endl << flush;
		pub_out.publish(msg);
		sessione=false;
		p=0; dist=0; dist_att=0; i=0;
		v = {1,2,3,4};
	}
	
	//ad ogni chiamata della funzione incremento le variabili e aggiungo nella prossiam posizione del vettore v il valore della
	//distanza, in modo che quando tutte e 6 le posizioni del vettore avranno lo stesso valore allora potrò considerare 
	//il robot arrivato al goal
	if(sessione){
		v.insert(v.begin()+i,status->distance_to_global_goal);
		k++;
		i++;
		i=i%4;
	}

	return;
}

void reset_sessione(const geometry_msgs::PoseStamped::ConstPtr& status){
	//cout << "HO RESETTATO LA SESSIONE" << endl << flush;
	k=0;
}

int main(int argc, char** argv){
	
	ros::init(argc, argv, "ped_status");
	ros::NodeHandle n;
	
	ros::Subscriber sub = n.subscribe("/move_base_simple/goal", 1000, reset_sessione);
	pub_out = n.advertise<std_msgs::String>("/stato_robot", 1000);
	
	//subscriber al topic /planner_status dove è presente la distanza del robot dal goal
	ros::Subscriber pub_status = n.subscribe("/planner_status", 1000, stato_robot);
	sessione=true;
	
	ros::spin();
	return 0;


}


