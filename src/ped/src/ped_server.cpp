#include <list>
#include "utils.h"
using namespace std;


list<utente> list_user;

bool user_f(ped::set_user::Request& req,
            ped::set_user::Response& res){
	
	if(req.azione=="rimuovi"){
		cout << purple;
		cout << "RIMUOVO" << endl;
		cout << fine;
		utente k = utente(req.name,req.x,req.y);
		cout << list_user.size();
		list_user.remove(k);
		return true;
	}
	
	if(req.azione=="print"){
		cout << purple;
		cout << "PRINT" << endl;
		cout << fine;
		for(auto k : list_user){
			cout << k.name << " " << k.x << " " << k.y << endl;
		}
		return true;
	}

	if(req.azione=="delete"){
		cout << purple;
		cout << "CANCELLO TUTTO" << endl;
		cout << fine;
		list_user.clear();
		return true;
	}
	
    int trovato=0;
    for(auto tmp : list_user){
        if(tmp.name==req.name){
            trovato=1;
            tmp.x=req.x;
            tmp.y=req.y;
        }
    }
    if(trovato==0){
        utente tmp = utente(req.name,req.x,req.y);
        list_user.push_back(tmp);
        cout << purple;
        //ROS_INFO("UTENTE AGGIUNTO CORRETTAMETNE. %d", list_user.size());
        cout << "UTENTE AGGIUNTO CORRETTAMENTE" << endl;
        cout << fine;
        string a,b,c;
        a = req.name;
        b=to_string(req.x);
        c=to_string(req.y);
        res.ret=a+" "+b+" "+c;
        cout << res.ret << endl;
        return true;    
    }
    cout << purple;
    //ROS_INFO("UTENTE GIÀ PRESENTE");
    cout << "UTENTE GIÀ PRESENTE" << endl;
    cout << fine;
    string a,b,c;
    a = req.name;
    b=to_string(req.x);
    c=to_string(req.y);
    res.ret=a+" "+b+" "+c;
    cout << res.ret << endl;
    return true;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "ped_client");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("user_topic", user_f);

    ros::spin();

}               


