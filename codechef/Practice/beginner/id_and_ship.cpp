#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	char id;
	while(t--){
		cin>>id;
		id = tolower(id);
		if(id == 'b'){
			cout<<"BattleShip"<<endl;
		}
		else if(id =='c'){
			cout<<"Cruiser"<<endl;
		}
		else if(id == 'd'){
			cout<<"Destroyer"<<endl;
		}
		else{
			cout<<"Frigate"<<endl;
		}
	}
	return 0;
}
