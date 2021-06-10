#include <sstream> 
#include <ros/ros.h>
#include <ped/User.h>
#include <ped/set_user.h>
#include "std_msgs/String.h"
#include <list>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

#define red     "\x1b[31m"
#define green   "\x1b[32m"
#define yellow  "\x1b[33m"
#define blue    "\x1b[34m"
#define purple "\x1b[35m"
#define lightblue    "\x1b[36m"
#define fine   "\x1b[0m"


class utente{
    public:
        string name;
        float x;
        float y;
        utente(string s,float a, float b){name=s;x=a;y=b;};
        void print(){
            cout << purple;
            cout << "name: " << name << endl << "    x: " << x << endl << "    y: " << y << endl << endl; 
        }
};
list<utente> list_user;

bool user_f(ped::set_user::Request& req,
            ped::set_user::Response& res){
    
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


