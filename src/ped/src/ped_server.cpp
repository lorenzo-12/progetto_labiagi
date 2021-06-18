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
	//cout << "ho sentito: " << msg->data.c_str() << endl << flush;
	//cout << "p: " << p << "   d: " << d << endl << flush;
	
	//se la condizione è vera vuol dire che si è ricevuti un messaggio "pcik" e quindi ora il messaggio conterrà i dati per 
	//far muovere il robot
	if(p){
		s=msg->data;
		
		//funzione che divide una stringa ogni volta che trova una determinata occorrenza di caratteri (nel nostro caso " ")
		//e li salva all'interno di un array dato in input
		boost::split(result, s, boost::is_any_of(" "));
		username=result[0]; pos_x=stof(result[1]); pos_y=stof(result[2]);
		
		//si impostano i campi del messaggio che verrà inviato sul topic /move_base_simple/goal che è il topic
		//dove si inviano i messaggi per far muover il robot
		cout << "username: " << username << "   x: " << pos_x << "   y: " << pos_y << endl << flush;
		goal.header.frame_id="map";
		goal.header.stamp = ros::Time::now();
		goal.pose.position.x=pos_x;
		goal.pose.position.y=pos_y;
		pub_goal.publish(goal);
		ok=true;
		
		//aspetto finchè il robot non è arrivato a destinazione
		while(ros::ok()){
			if(aspetta) break;
			ros::spinOnce();
		}
		
		//cout << red;
		//cout << "fine ciclo while" << endl << flush;
		//cout << fine;
		
		//invio il messaggio "pick" per far sapere al client che il robot ha preso il pacco
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
		
		//come sopra
		boost::split(result, s, boost::is_any_of(" "));
		username=result[0]; pos_x=stof(result[1]); pos_y=stof(result[2]);
		
		//come sopra
		cout << "username: " << username << "   x: " << pos_x << "   y: " << pos_y << endl << flush;
		goal.header.frame_id="map";
		goal.header.stamp = ros::Time::now();
		goal.pose.position.x=pos_x;
		goal.pose.position.y=pos_y;
		pub_goal.publish(goal);
		ok=true;
		
		//aspetto che il robot sia arrivato a destinazione
		while(ros::ok()){
			if(aspetta) break;
			ros::spinOnce();
		}
		//cout << red;
		//cout << "fine ciclo while" << endl << flush;
		//cout << fine;
		
		//invio al client il messaggio "delivery" per far sapere che il pacco è stato consegnato
		m.data="delivery";
		talk.publish(m);
		ros::spinOnce();
		
		aspetta=false;
		ok=false;
		d=false;
		return;
	}
	
	//se il messaggio ricevuto è "psw" allora mando 2 messaggi al client. il primo è "psw" per far capire che nel prossimo
	//sarà presente la password. e nel secondo si manda la password.
	if(msg->data=="psw"){
		
		m.data="psw";
		talk.publish(m);
		ros::spinOnce();
		
		m.data=password;
		talk.publish(m);
		ros::spinOnce();
	}
	
	//se il messaggio che si riceve è opzioni allora si reinvia "opzioni" in modo da far capire al client
	//che si devono stampare le opzini
	if(msg->data=="opzioni"){
		m.data="opzioni";
		talk.publish(m);
		ros::spinOnce();
		//cout << "ho mandato: " << m.data.c_str() << endl << flush;
	}
	
	//se il messaggio è "pick" allora vuol dire che mi arriverà un ulteriore messaggio contentente i dati per 
	//far muover il robot. quindi metto la variabile p=true in modo che alla prossima chiamata callBack si entri nell'if 
	//che si trova sopra
	else if(msg->data=="pick"){
		//cout << "pick" << endl << flush;
		p=true;
	}
	
	//stessa logica del "pick" ma qui si imposta la variabile d=true
	else if(msg->data=="delivery"){
		//cout << "delivery" << endl << flush;
		d=true;
	}
	
	//se ricevo un messaggio che non consco lo rimando al client
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
		
		//imposto la distanza massima in modo da poter dare una stima della percentuale del cammino percorso
		if(status->distance_to_global_goal>dist_max){
			dist_max=status->distance_to_global_goal;
		}
		
		//mi calcolo a che percentuale del cammino totale si trova il robot
		completamento=(dist_max-status->distance_to_global_goal)*100/dist_max;
		
		//stampo la distanza a cui si trova dal goal e la percuntale del completamento del cammino
		cout << "\rstatus distance: ";
		cout << lightblue;
		cout << fixed << setprecision(4) << status->distance_to_global_goal << flush;
		cout << fine;
		cout << " completamento: " << flush;
		
		//cambio il colore alla percentuale e al [###]
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
	
	//siccome il robot non si ferma esattamente sopra il punto (cioè a distanza 0) quello che faccio è salvarmi 
	//ogni volta la distanza a cui si trova il robot all'interno di un array di 4 elementi. se tutti e 4 gli elementi
	//sono uguali vuol dire che sono arrivato a destinazine
	
	//dato che la distanza del robot non va mai a zero preciso non si può nemmeno scrivere una funzione per capire se il 
	//robot si è bloccato a metà strada poichè potrebbe benissimo incastrarsi a 0.5 dal goal (ovviamente se il robot si ferma
	//a 10 dal goal si è ovviamente incastrato, ma dai vari test fatti la distanza a cui si ferma il robot varia sempre)
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
		
		//quando il robot è arrivato al goal imposto la variabile aspetta (usata sopra) a true
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
	
	//condizione per impostare la password. count mi assicura si entri nell'if una sola volta
	if(psw_count==0){
		psw_count++;
		cout << "DIGITARE LA PASSWORD: "; cin >> password;
		cout << endl << flush;
	}
	
	ros::spin();
	return 0;
}




