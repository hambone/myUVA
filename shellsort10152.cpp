#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int testCases,n;
	vector<string> orig,corr;
	string line;

	cin >> testCases;
	cin.ignore(1000,'\n');
	while(testCases--){
		orig.clear();
		corr.clear();
		cin >> n;
		cin.ignore(1000,'\n');
		for (int i = 0; i < n; i++){
			getline(cin,line);
			orig.push_back(line);
		}
		for (int i = 0; i < n; i++){
			getline(cin,line);
			corr.push_back(line);
		}
				
		vector<string>::reverse_iterator origit = orig.rbegin();			
		vector<string>::reverse_iterator corrit = corr.rbegin();
		while((origit != orig.rend()) && (corrit != corr.rend())){
			if(*origit != *corrit){
				origit++;
			} else {
				origit++;
				corrit++;
			}
		}

		while(corrit != corr.rend()){
			cout << *corrit << endl;
			corrit++;
		}	
		cout << endl;				
	}


	return 0;
}
