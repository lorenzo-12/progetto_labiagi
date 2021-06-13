#include <sstream> 
#include <ros/ros.h>
#include <ped/User.h>
#include "std_msgs/String.h"
#include <ped/set_user.h>
#include "std_msgs/String.h"
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

// per altri colori http://bashrcgenerator.com/


#define red     		"\x1b[38;5;196m"
#define green   		"\x1b[38;5;46m"
#define yellow  		"\x1b[38;5;11m"
#define yellow2  		"\x1b[33m"
#define blue2   		"\x1b[34m"
#define blue   			"\x1b[38;5;21m"
#define purple 			"\x1b[38;5;129m"
#define purple2 		"\x1b[38;5;93m"
#define purple3 		"\x1b[38;5;201m"
#define lightblue   	"\x1b[38;5;27m"
#define lightblue2    	"\x1b[38;5;14m"
#define lightblue3    	"\x1b[36m"
#define pink    		"\x1b[38;5;13m"
#define orange 			"\x1b[38;5;202m"
#define orange2 		"\x1b[38;5;208m"
#define fine   			"\x1b[0m"


class utente{
    public:
        string name;
        float x;
        float y;
        utente(string s,float a, float b){name=s;x=a;y=b;};
        bool operator==(const utente& a){
            if(a.name==this->name) return true;
            return false;
        }   
        void print(){
            cout << purple;
            cout << "name: " << name << endl << "    x: " << x << endl << "    y: " << y << endl << endl; 
        }
};
