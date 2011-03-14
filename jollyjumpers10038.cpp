#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

int main(){
	bitset<3005> chk;
	int n;
	int temp;
	int inputArr[3005];

	top:
	while (cin >> n){
		if( n == 1){
			cin >> n;
			cout << "Jolly" << endl;
		} else {
			for( int i = 1; i <= n; i++){
				chk[i] = 0;
				cin >> inputArr[i];
			}
			
			for ( int i = 2; i <= n; i++){
				int diff = (inputArr[i]-inputArr[i-1]);
				diff = (diff < 0)?-1*diff:diff;	
				if(diff >= n || (chk[diff] == 1)){
					cout << "Not jolly" << endl;
					goto top;	
				} else {
					chk[diff] = 1;				
				}
			}
			cout << "Jolly" << endl;
		}
	}
	return 0;
}
