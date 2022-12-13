#include <iostream>
using namespace std;
 
int main(){
	int people, min_skill, person_skill;
	cin >> people >> min_skill;

    while(people > 0){
	people -= 1;
		cin >> person_skill;
		if(person_skill >= min_skill){
			cout << "YES" << "\n";
        }
		else{
			cout << "NO\n";
		}
		
		
	}
	return 0;
}