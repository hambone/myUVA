#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

string suits[] = {"Clubs","Diamonds","Hearts","Spades"};
string values[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
int shuffles[100][52];

int main(){
	int numTests,numShuffles,tmp,t,i,j;
	int card[52], swap[52];
	cin >> numTests;
	string input;
	for( t = 0; t < numTests; t++){
		cin >> numShuffles;
		for( i = 0; i < numShuffles; i++){
			for ( j = 0; j < 52; j++){
				cin >> shuffles[i][j];
			}
		}
		
		for(i = 0; i <52; i++) card[i] = i;

		getline(cin,input);
		while(true){
			getline(cin,input);
			if(input == "") break;
			tmp = atoi(input.c_str());
			for(i = 0; i < 52; i++)
				swap[i] = card[shuffles[tmp-1][i]-1];
			for(i = 0; i < 52; i++)
				card[i] = swap[i];
		}
		for(i = 0; i < 52; i++)
			cout << values[card[i]%13] << " of " << suits[card[i]/13] << endl;
		if (t != numTests - 1) cout << endl;
	}
	return 0;
}
