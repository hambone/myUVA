#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int T,numRel;
	vector<int> locations;
	cin >> T;

	while( T--){
		locations.clear();	
		cin >> numRel;	
		for(int i = 0; i < numRel; i++){
			int r;
			cin >> r;
			locations.push_back(r);
		}
		sort(locations.begin(), locations.end());
		int good = locations[numRel/2];
		
		int sum = 0;
		for (int i = 0; i < locations.size(); i++){
			if(i < numRel/2){
				sum += good - locations[i];
			} else {
				sum += locations[i] - good;
			}
		}
		cout << sum << endl;
	}

	return 0;
}
