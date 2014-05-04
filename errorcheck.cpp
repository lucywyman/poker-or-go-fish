
using namespace std;

int errorCheck(int a){ 
	int valid = 1;
	if(cin.fail()){
		cin.clear();
		cin.ignore(1000, '\n');
		valid = 0;
	}   
	return valid;
}

