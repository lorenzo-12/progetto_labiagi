
#include "utils.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "/home/me/labiagi_2020_21/workspaces/srrg2_labiagi/devel/include/srrg2_core_ros/PlannerStatusMessage.h"

using namespace std;
list<utente> list_user;
string s;
string r;
std_msgs::String msg;
bool loop=false;
bool aspetta=false;
string username;
float pos_x;
float pos_y;
bool esegui=true;
bool esiste=false;
stringstream ss;
string password="";
string psw_tmp="";
bool psw_exit=false;
bool psw_wait=false;

void stampa_opzioni(){
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
	cout << orange;
	cout << "  4- VISUALIZZAZIONE LISTA UTENTI" << endl << flush;
	cout << fine;
}

void CB(const std_msgs::String::ConstPtr& msg){
	//cout << "ho sentito: " << msg->data.c_str() << endl << flush;
	r=msg->data;
	if(psw_wait==true){
		password=msg->data;
		psw_wait=false;
		psw_exit=true;
	}
	if(msg->data=="psw") psw_wait=true;
	if(msg->data=="opzioni") stampa_opzioni();
	if(msg->data=="pick") aspetta=true;
	if(msg->data=="delivery") aspetta=true;
	loop=true;
}

int main(int argc, char** argv){
	
	ros::init(argc, argv, "ped_test");
	ros::NodeHandle n;
	
	ros::Publisher talk = n.advertise<std_msgs::String>("/ped_cts",1000);
	ros::Subscriber listener = n.subscribe("/ped_stc",1000,CB);
	
	int count=0;
	while(ros::ok()){
		//cout << count << endl << flush;
		msg.data="psw";
		talk.publish(msg);
		ros::spinOnce();
		if(psw_exit) break;
		ros::Duration(1,0).sleep();
		count++;
	}
	//cout << "---" << password << "---" << endl << flush;
	
	cout << "PER CONTINUARE DIGITA LA PASSWORD: "; cin >> psw_tmp;
	while(psw_tmp!=password){
		cout << "PASSWORD ERRATA. DIGITA LA PASSWORD: "; cin >> psw_tmp;
	}
	
	stampa_opzioni();
	
	while(ros::ok()){
	cout << "scegli un'opzione: " << flush; cin >> s;
	esegui=true;
	
	if(s=="clear"){
		system("clear");
		stampa_opzioni();
	}
	
	if(s=="0") return 0;
	
	if(s=="1" and esegui){
		///if(wrong_psw){
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
		///}
		system("clear");
		stampa_opzioni();
		esegui=false;
	}
	if(s=="2" and esegui){
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
		system("clear");
		stampa_opzioni();
		esegui=false;
	}
	if(s=="3" and esegui){ 
		while(!esiste){	
			cout << "INSERIRE L'UTENTE DA CUI PRENDERE IL PACCO: "; cin >> username;
			if(username=="utenti?"){
				cout << orange;
				cout << "LISTA UTENTI:" << endl << flush;
				cout << fine;
				for(auto k : list_user){
					cout << k.name << " " << k.x << " " << k.y << endl << flush;
				}
				cout << orange;
				cout << "---" << endl << flush;
				cout << fine;
				esegui=false;
			}
			for( auto k : list_user){
				if(k.name==username){
					pos_x=k.x;
					pos_y=k.y;
					esiste=true;
					break;
				}
			}
			if(esiste==false){
				cout << "L'UTENTE INSERITO NON ESISTE NEL DATABASE, SI PREGA DI RIPROVARE." << endl << flush;
			}
		}
		esiste=false;
		
		//cout << username << pos_x << pos_y << endl << flush;
		msg.data="pick";
		talk.publish(msg);
		ros::spinOnce();
		
		ss.str("");
		ss << username << " " << pos_x << " " << pos_y << " ";
		msg.data=ss.str();
		talk.publish(msg);
		ros::spinOnce();
		
		cout << lightblue;
		cout << "IL ROBOT È IN MOVIMENTO" << flush;
		cout << fine;
		
		while(ros::ok()){
			if(aspetta) break;
			ros::spinOnce();
		}
		
		cout << lightblue;
		cout << "\rIL ROBOT È ARRIVATO A DESTINAZIONE" << endl << flush;
		cout << fine;
		
		while(!esiste){	
			cout << "INSERIRE L'UTENTE A CUI SI INTENDE SPEDIRE IL PACCO: "; cin >> username;
			if(username=="utenti?"){
				cout << orange;
				cout << "LISTA UTENTI:" << endl << flush;
				cout << fine;
				for(auto k : list_user){
					cout << k.name << " " << k.x << " " << k.y << endl << flush;
				}
				cout << orange;
				cout << "---" << endl << flush;
				cout << fine;
			}
			for( auto k : list_user){
				if(k.name==username){
					pos_x=k.x;
					pos_y=k.y;
					esiste=true;
					break;
				}
			}
			if(esiste==false){
				cout << "L'UTENTE INSERITO NON ESISTE NEL DATABASE, SI PREGA DI RIPROVARE." << endl << flush;
			}
		}
		esiste=false;
		//cout << username << pos_x << pos_y << endl << flush;
		msg.data="delivery";
		talk.publish(msg);
		ros::spinOnce();
		
		ss.str("");
		ss << username << " " << pos_x << " " << pos_y << " ";
		msg.data=ss.str();
		talk.publish(msg);
		ros::spinOnce();
		
		aspetta=false;
		esegui=false;
		
		cout << lightblue;
		cout << "IL ROBOT È IN MOVIMENTO" << flush;
		cout << fine;
		
		while(ros::ok()){
			if(aspetta) break;
			ros::spinOnce();
		}
		
		cout << lightblue;
		cout << "\rIL ROBOT È ARRIVATO A DESTINAZIONE" << endl << flush;
		cout << fine;
		
		aspetta=false;
		stampa_opzioni();
		
	}
	if(s=="4" and esegui){
		system("clear");
		cout << orange;
		cout << "LISTA UTENTI:" << endl << flush;
		cout << fine;
		for(auto k : list_user){
			cout << k.name << " " << k.x << " " << k.y << endl << flush;
		}
		cout << orange;
		cout << "---" << endl << flush;
		cout << fine;
		stampa_opzioni();
	}
	if(esegui){
		msg.data=s;
		talk.publish(msg);
		ros::spinOnce();
	}
	
	while(ros::ok() and esegui){
		ros::spinOnce();
		if(loop) break;
	}
	loop=false;
	}
	
	return 0;


}

