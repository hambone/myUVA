#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	string first,second;
	getline(cin,first);
	getline(cin,second);
	while( true){
		sort(first.begin(),first.end());	
		sort(second.begin(),second.end());	
		string::iterator i = first.begin(), j = second.begin();
		vector<char> v;
		while ( i != first.end() && j != second.end() ){
			if( *i == *j){
				v.push_back(*i);
				i++;
				j++;
			} else if (*i < *j){
				i++;
			} else {
				j++;
			}
		}
		for ( vector<char>::iterator it = v.begin(); it != v.end(); it++){
			cout << *it;	
		}
		cout << endl;
		getline(cin,first);	
		getline(cin,second);	
		if(!cin.good()) break;
	}
	return 0;
}
