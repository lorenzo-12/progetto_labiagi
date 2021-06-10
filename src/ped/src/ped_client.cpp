#include "utils.h"
using namespace std;

int main(int argc, char** argv){
	ros::init(argc, argv, "ped_client");
	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<"nome_package"::"tipo_dato">("map");
	
	ros::spin();
	
}
