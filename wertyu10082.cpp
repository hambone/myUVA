#include <iostream>
using namespace std;


int main(){
		
		char L[1000];
		char bad[]="1234567890-=WERTYUIOP[]\\SDFGHJKL;\'XCVBNM,./ \n";
		char good[]="`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. \n";
 
		for(int i = 0; i < sizeof(bad); i++){
				L[bad[i]] = good[i];
		}

		int in,index;

		string a;	
		while(getline(cin,a)){
			for (int i = 0; i < a.size(); i++)
					cout << L[a[i]]; 
			cout << endl;
		}


		return 0;
}
