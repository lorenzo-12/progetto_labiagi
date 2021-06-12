#include "utils.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "/home/me/labiagi_2020_21/workspaces/srrg2_labiagi/devel/include/srrg2_core_ros/PlannerStatusMessage.h"

using namespace std;
geometry_msgs::PoseStamped goal;
string pacco;
int scelta=0;
list<utente> list_user;
string username;
string username_goal;
float pos_x;
float pos_y;
bool esiste=false;

void nulla(const std_msgs::String::ConstPtr& msg){
	//ROS_INFO("IL ROBOT HA SCRITTO: %s",msg->data.c_str());
}

int main(int argc, char** argv){
	//inizializzo il nodo e creo il nodehandle
	ros::init(argc, argv, "ped_client");
	ros::NodeHandle n;

	
	//publisher necessario per avvisare il robot che deve raggiungere un determinato goal
	ros::Publisher pub_goal = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
	
	ros::Subscriber sub_out = n.subscribe("/stato_robot", 1000, nulla);
	
	while(ros::ok()){
		
		cout << "COMANDI DISPONIBILI (0 PER TERMINARE):" << endl;
		cout << red;
		cout << "  1- INSERIMENTO/MODIFICA UTENTE NEL DATABASE" << endl;
		cout << fine;
		cout << blue;
		cout << "  2- RIMOZIONE UTENTE DAL DATABESE" << endl;
		cout << fine;
		cout << green;
		cout << "  3- PICK AND DELIVERY" << endl;
		cout << fine;
		cout << purple;
		cout << "  4- VISUALIZZAZIONE LISTA UTENTI" << endl << flush;
		cout << fine;
		cout << "DIGITARE LA FUNZIONE CHE SI DESIDERA ESEGUIRE: "; cin >> scelta;
		while(ros::ok() and (scelta>4 or scelta<0)){
			cout << "IL NUMERO INSERITO NON È VALIDO." << endl << "DIGITARE LA FUNZIONE CHE SI DESIDERA ESEGUIRE: "; 
			cin >> scelta;
		}
		if(scelta==0) return 0;
		
		else if(scelta==1){
			cout << "USERNAME: "; cin >> username;
			cout << "POSITION X: "; cin >> pos_x;
			cout << "POSITION Y: "; cin >> pos_y;
			int trovato=0;
			for(auto& k : list_user){
				if(k.name==username){
					trovato=1;
					k.x=pos_x;
					k.y=pos_y;
				}
			}
			if(trovato==1){
				cout << red;
				cout << "UTENTE GIÀ PRESENTE" << endl << flush;
				cout << fine;
			}
			else{
				utente tmp = utente(username,pos_x,pos_y);
				list_user.push_back(tmp);
				cout << red;
				cout << "UTENTE AGGIUNTO CORRETTAMENTE" << endl << flush;
				cout << fine;  
			}
		}
		
		else if(scelta==2){
			cout << "USERNAME: "; cin >> username;
			for(auto k : list_user){
				if(k.name==username){
					pos_x=k.x;
					pos_y=k.y;
					break;
				}
			}
			utente k = utente(username,pos_x,pos_y);
			list_user.remove(k);
		}
		
		else if(scelta==3){
			//chiedo in input all'utente le posizioni x e y che il robot deve raggiungere
			//e le inserisco all'interno del goal
			goal.header.frame_id="map";
			while(!esiste){	
				cout << "INSERIRE L'UTENTE A CUI SI INTENDE SPEDIRE IL PACCO: "; cin >> username_goal;
				for( auto k : list_user){
					if(k.name==username_goal){
						goal.pose.position.x=k.x;
						goal.pose.position.y=k.y;
						esiste=true;
						break;
					}
				}
				if(esiste==false){
					cout << "L'UTENTE INSERITO NON ESISTE NEL DATABASE, SI PREGA DI RIPROVARE." << endl << flush;
					cout << "INSERIRE L'UTENTE A CUI SI INTENDE SPEDIRE IL PACCO: "; cin >> username_goal;
				}
				
			}
			///cout << "x: "; cin >> goal.pose.position.x;
			///cout << "y: "; cin >> goal.pose.position.y;
			goal.header.stamp = ros::Time::now();
	
			//pubblico il goal sul topic "/move_base_simple/goal" in modo da far muovere il robot
			pub_goal.publish(goal);
	
			cout << lightblue;
			cout << "IL ROBOT È IN MOVIMENTO..." << endl << flush;
			cout << fine;
			ros::topic::waitForMessage<std_msgs::String>("/stato_robot",ros::Duration(120));
	
			cout << lightblue;
			cout << "IL ROBOT È ARRIVATO A DESTINAZIONE, INSERIRE IL PACCO" << endl << flush;
			cout << fine;
	
			while(ros::ok()){
				cout << "digita 'pacco' per inserirlo: "; cin >> pacco;
				if(pacco=="pacco") break; 
				cout << "messaggio non valido" << endl << flush;
			}
			cout << lightblue;
			cout << "PACCO INSERITO, DIGITARE ORA LA DESTINAZIONE" << endl << flush;
			cout << fine;
	
			esiste=false;
			while(!esiste){	
				cout << "INSERIRE L'UTENTE A CUI SI INTENDE SPEDIRE IL PACCO: "; cin >> username_goal;
				for( auto k : list_user){
					if(k.name==username_goal){
						goal.pose.position.x=k.x;
						goal.pose.position.y=k.y;
						esiste=true;
						break;
					}
				}
				if(esiste==false){
					cout << "L'UTENTE INSERITO NON ESISTE NEL DATABASE, SI PREGA DI RIPROVARE." << endl << flush;
					cout << "INSERIRE L'UTENTE A CUI SI INTENDE SPEDIRE IL PACCO: "; cin >> username_goal;
				}
				
			}
			
			goal.header.stamp = ros::Time::now();
			pub_goal.publish(goal);
	
			cout << lightblue;
			cout << "IL ROBOT È IN MOVIMENTO..." << endl << flush;
			cout << fine;
	
			ros::topic::waitForMessage<std_msgs::String>("/stato_robot",ros::Duration(120));
	
			cout << lightblue;
			cout << "IL PACCO È ARRIVATO A DESTINAZIONE." << endl << flush;
			cout << fine;
		}
		
		else if(scelta==4){
			cout << purple;
			cout << "LISTA UTENTI:" << endl << flush;
			cout << fine;
			for(auto k : list_user){
				cout << k.name << " " << k.x << " " << k.y << endl << flush;
			}
			cout << purple;
			cout << "---" << endl << flush;
			cout << fine;
		}
		
		cout << endl << "--------------------" << endl << endl << flush;
	}
	
	
	
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
