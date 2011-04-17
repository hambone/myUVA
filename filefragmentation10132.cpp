#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

list<string> words;
unsigned int corrsize,minlen,maxlen;
int T;
string line;

bool cmplen(const string& a, const string& b){
	return a.length() < b.length();
}

bool test(string cand){
	if(words.empty()) return true;	

	string half1 = *(words.begin());
	words.erase(words.begin());

	list<string>::iterator it = words.end();
	it--;

	while( (*it).length() + half1.length() == cand.length() ){
		if( ( (half1 + *it) == cand) || ( (*it + half1) == cand)){
			string half2 = *it;
			words.erase(it);
			if(test(cand)) return true;
			else{
				words.push_front(half1);
				words.push_back(half2);
				return false;	
			}
		}
		it--;
	}
	words.push_front(half1);
	return false;
}

int main(){
	string candidate;
	cin >> T;
	cin.ignore(1000,'\n');
	cin.ignore(1000,'\n');		

	while(T--){
		minlen =10000;
		maxlen =0;
		while(getline(cin,line)){
			if(line == "") break;
			words.push_back(line);	
			if(line.length() < minlen) minlen = line.length();
			if(line.length() > maxlen) maxlen = line.length();
		}
		words.sort(cmplen);
		corrsize = maxlen+minlen;
		bool foundanswer =false;
		string half1 = *(words.begin());
		list<string>::iterator it = words.end();
		while( !foundanswer){
			it--;
			string half2 = *it;
			if(test(half1+half2)){
				candidate = half1+half2;
				foundanswer = true;
			} else if ( test(half2+half1) ){
				candidate = half2+half1;
				foundanswer = true;
			}
		}
		cout << candidate << endl;
		if(T!=0) cout << endl;
	}

	return 0;
}
