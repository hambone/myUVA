#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const string codeString = "the quick brown fox jumps over the lazy dog";

int main(){
	string line,word;
	vector< vector<string> > lines;
	vector<string> linewords,linecode;
	char codex[1000];
	int codeLen, numCases;
	bool decoded = false;

	for(int i = 0; i < 1000;i++){
		codex[i] = '#';
	}
	
	//count the words in the code line
	stringstream c(codeString);
	codeLen = 0;
	while( c >> word){
		linecode.push_back(word);	
		codeLen++;
	}

	cin >> numCases;
	cin.ignore(1000,'\n');
	cin.ignore(1000,'\n');
	while(numCases--){
		decoded = false;
		lines.clear();
		linewords.clear();
		
		// read the input into the linewords vector
		// each line is a vector of words. 
		while ( getline(cin,line)){
			if(line == "") break;
			stringstream s(line);
			int count = 0;
			while( s >> word){
				linewords.push_back(word);
				count++;
			}
			
			////////////////////
			////////////////////
			if( !decoded && (count == codeLen)){ // same number of words
				decoded = true;
				for (int n = 0; n < linewords.size(); n++){ //foreach word
					if( linewords[n].length() == linecode[n].length() ){ //same number of chars
						for(int m = 0; m < linewords[n].length(); m++){ //foreach char
							if(codex[linewords[n][m]] == '#'){
								codex[linewords[n][m]] = linecode[n][m];	
							} else if(codex[linewords[n][m]] == linecode[n][m] ){
								continue;
							} else {
								decoded = false;				
								goto out;
							}
						}
					} else {
						decoded = false;
						goto out;
					}
				}
			} 
			out:
			if(!decoded){
				for(int i = 0; i <1000; i++){
					codex[i] = '#';
				}
			}

			lines.push_back(linewords);
			linewords.clear();
		}

		if(!decoded){
			cout << "No solution." << endl;
		} else {
			// output the words.
			for( int linei=0; linei < lines.size(); linei++){
				if (linei != 0)
					cout << endl;
				linewords = lines[linei];
				for(int i =0; i < linewords.size(); i++){
					if(i != 0) cout << " ";
					for(int j = 0; j < linewords[i].length(); j++){
						cout << codex[linewords[i][j]];
					}
				}
			}
			cout << endl;
		}
		if(numCases != 0) cout << endl;
	}
	return 0;
}
