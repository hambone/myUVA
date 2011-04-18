#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct job {
	int id;
	int time;
	int penalty;
};

bool cmp(const job& l, const job& r){
	double lval = (double)l.penalty/(double)l.time;
	double rval = (double)r.penalty/(double)r.time;
	return lval > rval;
}

int main(){
	int testCases,njobs;
	string line;
	cin >> testCases;
	cin.ignore(1000,'\n');
	vector<job> joblist;

	while(testCases--){
		joblist.clear();
		getline(cin,line);
		cin >> njobs;
		cin.ignore(1000,'\n');
		for(int i = 0; i < njobs; i++){
			getline(cin,line);
			stringstream s(line);
			job j;
			j.id = i+1;
			s >> j.time;
			s >> j.penalty;
			joblist.push_back(j);
		}
		stable_sort(joblist.begin(),joblist.end(),cmp);
		for(vector<job>::iterator k = joblist.begin(); k != joblist.end(); k++){
			if(k != joblist.begin()){
				cout << " ";
			} 
			cout << k->id;
		}
		cout << endl;
		if(testCases != 0) cout << endl;
	}
				
	return 0;
}
