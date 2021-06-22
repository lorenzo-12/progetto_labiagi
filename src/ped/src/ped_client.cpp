#include "utils.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "ped/utenti.h"
#include "/home/me/labiagi_2020_21/workspaces/srrg2_labiagi/devel/include/srrg2_core_ros/PlannerStatusMessage.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
string s;
ped::utenti msg;
ped::utenti m;
stringstream ss;
bool password=false;
bool aspetta=false;
bool pacco=false;
bool arrivato=false;
string stanza;
string opzione;
ros::Publisher talk;


void stampa_opzioni(){
	
	cout << green;
	cout << "  3- PER VEDERE LE STANZE" << endl;
	cout << fine;
	cout << purple;
	cout << "  2- PER LOGGARSI IN UN'ALTRA STANZA" << endl;
	cout << fine;
	cout << blue;
	cout << "  1- PICK AND DELIVERY" << endl;
	cout << fine;
	cout << orange;
	cout << "  0- PER TERMINARE" << endl << flush;
	cout << fine;
}
				
void CB(const ped::utenti::ConstPtr& msg){
	if(msg->name==stanza){
		cout << msg->response << endl;
		if(msg->response=="finito"){
			aspetta=true;
			cout << red;
			cout << "pacco spedito correttamente" << endl;
			cout << fine;
		}
		else if(msg->response=="delivery-non-trovato"){
			aspetta=true;
			cout << red;
			cout << "stanza per la consegna non trovata" << endl;
			cout << fine;
		}
		else if(msg->response=="pick-non-trovato"){
			aspetta=true;
			cout << red;
			cout << "stanza per il ritiro non trovata" << endl;
			cout << fine;
		}
		else if(msg->response=="occupato"){
			aspetta=true;
			cout << red;
			cout << "robot già in uso riprova più tardi" << endl;
			cout << fine;
		}
		else if(msg->response=="nessuno-per-prendere-il-pacco"){
			aspetta=true;
			cout << red;
			cout << "nella stanza non c'è nessuno per ritirare il pacco'" << endl;
			cout << fine;
		}
		else if(msg->response=="nessuno-per-ritirare-il-pacco"){
			aspetta=true;
			cout << red;
			cout << "nella stanza non c'è nessuno per ritirare il pacco'" << endl;
			cout << fine;
		}
		else if(msg->option=="devi-ritirare"){
			cout << "TI ARRIVERÀ UN PACCO NON MUOVERTI" << endl;
			opzione="4";
			pacco=true;
		}
		else if(msg->option=="pacco-arrivato"){
			opzione="4";
			arrivato=true;
			pacco=true;
		}
	}
}

int main(int argc, char** argv){
	
	ros::init(argc, argv, "ped_test",ros::init_options::AnonymousName);
	ros::NodeHandle n;
	
	
	talk = n.advertise<ped::utenti>("/ped_cts",1000);
	ros::Subscriber listener = n.subscribe("/ped_stc",1000,CB);
	

	/*	NON SO PER QUALE MOTIVO MA NON INVIA QUESTI MESSAGGI, HO PROVATO ANCHE A METTERE ROS::SPINONCE() PRIMA MA NULLA.
		HO PROVATO ANCHE A FARE 10 PUBLISH DI FILA MA NULLA. PERÒ SE METTO UNA SLEEP E POI FACCIO UN PUBLISH ALLORA FUNZIONA
		NON SO PERCHÈ. QUINDI SONO COSTRETTO A METTERE IL WHILE
	
	msg.data="psw";
	talk.publish(msg);
	ros::spinOnce();
	
	*/
	
	
	//per ottenere la password dal server invio un messaggio "psw" e aspetto dal server che risponda con 2 messaggi: il primo
	// deve essere "psw" e il secondo deve contenere la password. ho dovuto fare un ciclo while per i motivi sopra descritti
	cout << "digita stanza dove loggarsi: "; cin >> stanza;
	msg.name=stanza;
	msg.option="IN";
	talk.publish(msg);
	ros::spinOnce();
	cout << "ho mandato: " << msg.name.c_str() << " " << msg.option.c_str() << endl << flush;
	
	while(ros::ok()){
		if(pacco==true){
			while(ros::ok()){
				ros::spinOnce();
				if(arrivato){
					cout << "PACCO ARRIVATO, DIGITA QUALCOSA PER RITIRARLO: "; cin >> s;
					m.name=stanza;
					m.option="pacco-ritirato";
					m.pick="";m.delivery="";
					talk.publish(m);
					ros::spinOnce();
					arrivato=false;
					pacco=false;
					break;
				}
			}
		}
		stampa_opzioni();
		cout << "scegli un'opzione: "; cin >> opzione;
		if(opzione=="0") {
			msg.name=stanza;
			msg.option="OUT";
			talk.publish(msg);
			ros::spinOnce();
			return 0;
		}
		else if(opzione=="1"){
			string delivery;
			cout << "digita stanza dove portare il pacco: "; cin >> delivery;
			msg.pick=stanza;
			msg.delivery=delivery;
			msg.name=stanza;
			msg.option="";
			talk.publish(msg);
			ros::spinOnce();
			
			while(ros::ok()){
				if(aspetta) break;
				ros::spinOnce();
			}
			aspetta=false;
		}
		else if(opzione=="2"){
			msg.name=stanza;
			msg.option="OUT";
			talk.publish(msg);
			ros::spinOnce();
			
			cout << "digita stanza dove loggarsi: "; cin >> stanza;
			msg.name=stanza;
			msg.option="IN";
			talk.publish(msg);
			ros::spinOnce();
		}
		else if(opzione=="3"){
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
				cout << s << " " << x << " " << y << "\n";
			}
		}
		if(opzione=="4"){
			string ritiro;
			cout << "IL PACCO È ARRIVATO DIGITA QUALCOSA PER RITIRARLO: "; cin >> ritiro;
			m.name=stanza;
			m.option="pacco-ritirato";
			m.pick="";m.delivery="";
			talk.publish(m);
			ros::spinOnce();
		}
		ros::spinOnce();

	}
	return 0;


}

