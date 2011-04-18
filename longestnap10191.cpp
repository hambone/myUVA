#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
	vector<int> times;
	int n,hr,min;
	char c;
	
	int testCase = 0;
	while(cin>>n){
		testCase++;
		times.clear();
		while(n--){
			for(int i = 0; i < 2; i++){
				cin >> hr;
				cin >> c;
				cin >> min;
				times.push_back(60*hr + min);
			}
			cin.ignore(1000,'\n');
		}
		times.push_back(60*10);		
		times.push_back(60*18);		
		sort(times.begin(),times.end());
		//for(int i = 0; i < times.size(); i++){
			//cout << times[i] << " ";
		//}
		//cout << endl;
					
		int bestStart = 600;
		int bestNap = 0;

		for(int i = 0; i < times.size(); i+=2){
			int diff = times[i+1]-times[i];
			if(diff > bestNap){
				bestNap = diff;	
				bestStart = times[i];
			}
		}
		cout << setfill('0');
		cout << "Day #" << testCase << ": the longest nap starts at ";
		cout << setw(2) << bestStart /60 << ":" << setw(2) << bestStart % 60;
		cout << " and will last for ";
		if( bestNap < 60){
			cout << bestNap << " minutes." << endl;
		} else {
			cout << bestNap / 60 << " hours and " << bestNap % 60 << " minutes." << endl; 
		}
	}
	return 0;
}
