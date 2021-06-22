
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
	

	/*	NON SO PER QUALE MOTIVO MA NON INVIA QUESTI MESSAGGI, HO PROVATO ANCHE A METTERE ROS::SPINONCE() PRIMA MA NULLA.
		HO PROVATO ANCHE A FARE 10 PUBLISH DI FILA MA NULLA. PERÒ SE METTO UNA SLEEP E POI FACCIO UN PUBLISH ALLORA FUNZIONA
		NON SO PERCHÈ. QUINDI SONO COSTRETTO A METTERE IL WHILE
	
	msg.data="psw";
	talk.publish(msg);
	ros::spinOnce();
	
	*/
	
	
	//per ottenere la password dal server invio un messaggio "psw" e aspetto dal server che risponda con 2 messaggi: il primo
	// deve essere "psw" e il secondo deve contenere la password. ho dovuto fare un ciclo while per i motivi sopra descritti
	while(ros::ok()){
		msg.data="psw";
		talk.publish(msg);
		ros::spinOnce();
		
		//una volta ottenuta la password si pone la variabile "psw_exit"=true in modo da uscire dal ciclo.
		if(psw_exit) break;
		ros::Duration(1,0).sleep();
	}
	
	//per procedere oltre si chiede di inserire la password
	cout << "PER CONTINUARE DIGITA LA PASSWORD: "; cin >> psw_tmp;
	while(psw_tmp!=password){
		cout << "PASSWORD ERRATA. DIGITA LA PASSWORD: "; cin >> psw_tmp;
	}
	
	stampa_opzioni();
	
	//ciclo while principale
	
	while(ros::ok()){
	cout << "scegli un'opzione: " << flush; cin >> s;
	esegui=true;
	
	//funzione per fare una clear del terminale in modo da rimuove vecchi messaggi
	if(s=="clear"){
		system("clear");
		stampa_opzioni();
	}
	
	//0 per terminare
	if(s=="0") return 0;
	
	//1 per inserire gli utenti
	if(s=="1" and esegui){
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
		
		system("clear");
		stampa_opzioni();
		esegui=false;
	}
	
	//2 per eliminare un utente (se esiste, altriemnti non fa nulla)
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
	
	//3 per effettuare il pick and delivery
	if(s=="3" and esegui){ 
		
		//si chiede in input il nome di un utente finchè non ne viene inserito uno valido.
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
		
		//si inviano al server 2 messaggi: il primo è "pick" per far capire al server che si intede prendere il pacco
		//il secondo contiene i dati necessari per impostare il prossimo goal (messaggio che verrà mandato dal server)
		
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
		
		//si aspetta fino a quando il robot non è arrivato a destinazine
		//ho dovuto usare un while poichè metodi come "ros::topic::waitForMessage<std_msgs::String>("/stato_robot",ros::Duration(120));"
		//per qualche motivo non funzionano, (infatti anche all'inizio del file si è dovuto optare per un ciclo while)
		//poichè ros non invia i messaggi
		
		while(ros::ok()){
			if(aspetta) break;
			ros::spinOnce();
		}
		
		cout << lightblue;
		cout << "\rIL ROBOT È ARRIVATO A DESTINAZIONE" << endl << flush;
		cout << fine;
		
		//si chiede in input il nome di un utente finchè non ne viene inserito uno valido.
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
		
		//vengono mandati al server 2 messaggi: il primo è "delivery" per far capire al server che si intede spedire il pacco
		//il secondo contiene i dati necessari per impostare il prossimo goal (messaggio che verrà mandato dal server)
		
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
		
		//come prima si aspetta che il robot arrivi a destinazione
		
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
	
	//4 per stampare la lista di utenti registrati
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

