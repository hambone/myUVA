#include <iostream>
#include <bitset>
using namespace std;

int T,n,P,i,j,k,h,counter;
bitset<3651> checks;

int main(){
	cin >> T;
	for ( i = 0; i < T; i++){
		cin >> n;	
		for(j = 0; j <= n; j++){
			checks[j] = 0;
		}
		cin >> P;
		for (k = 0; k < P; k++){
		 	cin >> h;
			counter = h;
			while(counter <= n){
				if( (counter % 7 != 0) && 
				    (counter % 7 != 6) )
					checks[counter] = 1;
				counter+=h;		
			}
		}
		counter = 0;
		for(int mm = 0; mm <= n; mm++){
			if(checks[mm]) counter++;
		}
		cout << counter << endl;
	}
	return 0;
}  




