#define MAXLEN 25
#include <iostream>
#include <string>
using namespace std;

enum move { INSERT,DELETE , MATCH, NONE };

struct cell{
	int cost;
	move action;
};	

cell M[MAXLEN][MAXLEN];

int twoDig(int i){
	if(i < 10) cout << "0";
	cout << i;	
}

void traceback(int i, int j,const string& a,const string&b){
	if(M[i][j].action == NONE ) return;
	if(M[i][j].action == MATCH){
		traceback(i-1,j-1,a,b);
		if(a[i-1] != b[j-1]){
			cout << "C" << b[j-1]; twoDig(j); 
		}
		return;
	} else if (M[i][j].action == INSERT){
		traceback(i,j-1,a,b);
		cout << "I" << b[j-1]; twoDig(j);
		return;
	} else { // DELETE
		cout << "D" << a[i-1]; twoDig(i);	
		traceback(i-1,j,a,b);
		return;
	}
}

int editd(const string& a, const string& b){
	int opt[3];
	//set up base cases	
	M[0][0].cost = 0;
	M[0][0].action = NONE;
	for(int i = 1; i <= a.length(); i++){
		M[i][0].cost = i;
		M[i][0].action = DELETE;
	}
	for(int j = 1; j <= b.length(); j++){
		M[0][j].cost = j;		
		M[0][j].action = INSERT;
	}
	for (int j = 0; j < b.length(); j++){
		for (int i = 0; i < a.length(); i++){
			if(a[i] == b[j])
				opt[MATCH] = M[i][j].cost; 	
			else
				opt[MATCH] = 1 + M[i][j].cost;
			opt[DELETE] = 1 + M[i][j+1].cost;
			opt[INSERT] = 1 + M[i+1][j].cost;	
			
			M[i+1][j+1].cost = opt[MATCH];
			M[i+1][j+1].action = MATCH;
			for (int k = INSERT; k <= DELETE; k++){
				if(opt[k] < M[i+1][j+1].cost){
					M[i+1][j+1].cost = opt[k];
					M[i+1][j+1].action = (move)k;
				}
			}
		}
	}
	traceback(a.length(),b.length(),a,b);
	return M[a.length()][b.length()].cost;
}

int main(){
	string a,b;	
	while (getline(cin,a)){
		if(a == "#"){
			cout << endl;
			 break;
		}
		b = a.substr(a.find_first_of(" ")+1);
		if (b.length() == 0) b = "";
		a = a.substr(0,a.find_first_of(" "));
		editd(a,b);
		cout << "E" << endl;
	}
	return 0;
}
