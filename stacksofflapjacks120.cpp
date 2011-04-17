#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// selection sort

int main(){
	vector<int> pancakes;
	string line;
	int n;

	while( true ){
		pancakes.clear();
		getline(cin,line);
		if( !cin.good() ) break;

		stringstream s(line);
		while(s >> n){
			pancakes.push_back(n);
		}
		for(int i = 0; i < pancakes.size(); i++){
			if( i != 0 ) cout << " ";
			cout << pancakes[i];
		}
		cout << endl;
		reverse(pancakes.begin(),pancakes.end());
		for(int i = 0; i < pancakes.size(); i++){
			int max = pancakes[i];
			int maxind = i;
			for(int j = i+1; j < pancakes.size(); j++){
				if(pancakes[j] > max){
					 max = pancakes[j];	
					 maxind = j;
				}
			}
			if(maxind != i ){
					cout << maxind+1 << " ";
					reverse(pancakes.begin()+maxind,pancakes.end());
				cout << i+1 << " ";
					reverse(pancakes.begin()+i,pancakes.end());
			}
		}
		cout << "0" << endl;
	}
	return 0;
}
