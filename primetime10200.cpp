#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

const unsigned int LARGEST = 100002;
bitset<LARGEST+1> primes;
vector<unsigned int> primenums;

unsigned int myFormula(unsigned int n){
	return (n*n+n+41);
}

void sievePrimes(){
	unsigned int k;
	for (int i = 0; i<=LARGEST;i++) primes[i] = 1;
	primes[0] = primes[1] = 0;
	for (unsigned int i = 2; i*i <= LARGEST; i++){
		if(!primes[i]) continue;
		k = i*i;
		while(k <= LARGEST){
			primes[k] = 0;
			k+=i;
		}
	}

	for (unsigned int i = 1; i <= LARGEST; i++){
		if(primes[i]){
			primenums.push_back(i);
		}			
	}
}

bool isPrime(unsigned int n){
	if( n <= LARGEST ) return primes[n];
	int i = 1;
	while( primenums[i]*primenums[i] < n){
		if( (n % primenums[i]) == 0) return false;
		i++;
	}
	return true;
}

int main(){
	sievePrimes();
	unsigned int cumulative[10001];
	unsigned int counter = 0;
	unsigned int i = 0;

	for(i = 0; i <= 10000; i++){
		if( isPrime(myFormula(i)) ) counter++;
		cumulative[i] = counter;  	
	}

	cout.setf(ios::fixed);
	cout << setprecision(2);
	unsigned int a,b;
	while (cin >> a){
		cin >> b;	
		if (a > b){
			unsigned int temp = a;
			a = b;
			b = temp;
		}	
		if ( a == 0 && b == 0){
			cout << 100.00;			

		} else if ( a == 0 ){
			cout << 100.0 * (float)cumulative[b] / (float) (b+1) ;
		} else { 
			cout << 100.0 * (float)(cumulative[b] - cumulative[a-1]) / (float)(b-a+1) + 1e-9 ;
		}
		cout << endl;
	}
	return 0;
}
