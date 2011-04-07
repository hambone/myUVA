#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int n,m;
vector<char> corr, incorr, corrnums, incorrnums;

void judge(){
	bool accepted = true;
	if( n != m || (corr.size() != incorr.size()) ){
		accepted = false;
	} 

	if(accepted){
		for(int i = 0; i < corr.size(); i++){
			if( corr[i] != incorr[i] )	{
				accepted = false;
				break;	
			}
		}
	}

	if(accepted){
		cout << "Accepted" << endl;
		return;
	}

	bool presErr = true;
	if(corrnums.size() != incorrnums.size()){
		presErr = false;
	}

	if(presErr){
		for(int i = 0; i < corrnums.size(); i++){
			if( corrnums[i] != incorrnums[i] ){
				presErr = false;
				break;
			}
		}
	}

	if(presErr){
		cout << "Presentation Error" << endl;
	} else {
		cout << "Wrong Answer" << endl;
	}
}

int main(){
	string line;
	char c;
	int count = 1;
	while ( cin >> n){
		if(n == 0) break;
		cin.ignore(1000,'\n');
		while(n--){
			getline(cin,line);
			for(int i = 0; i < line.length(); i++){
				corr.push_back(line[i]);
				if( isdigit(line[i])) corrnums.push_back( line[i] );
			}	
			corr.push_back('\n');
		}
		cin >> m; cin.ignore(1000,'\n');
		while(m--){
			getline(cin,line);
			for(int i = 0; i < line.length(); i++){
				incorr.push_back(line[i]);
				if( isdigit(line[i]) ) incorrnums.push_back( line[i] );
			}
			incorr.push_back('\n');
		}

		cout << "Run #" << count << ": ";
		judge();

		corr.clear();
		incorr.clear();
		incorrnums.clear();
		corrnums.clear();
		count++;
	}
	return 0;
}
