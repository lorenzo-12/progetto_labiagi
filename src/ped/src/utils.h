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
        bool operator==(const utente& a){
            if(a.name==this->name) return true;
            return false;
        }   
        void print(){
            cout << purple;
            cout << "name: " << name << endl << "    x: " << x << endl << "    y: " << y << endl << endl; 
        }
};
