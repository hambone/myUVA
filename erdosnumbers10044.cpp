#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cctype>
#include <cstring>
using namespace std;

struct node {
	int color;
	int depth;
	set<node *> nbrs;
};

map<string,node *> nodes;
typedef pair<string,node *> mypair;

void insertin(string &a, string &b){
	map<string,node *>::iterator it,itb;
	it = nodes.find(a);
	if( it == nodes.end()){
		node *nd = new node;
		nd->color = 0;
		nd->depth = -1;
		nodes.insert(mypair(a,nd));
		it = nodes.find(a);
	}
	itb = nodes.find(b);
	if( itb == nodes.end()){
		node * nd = new node;
		nd->color = 0;		
		nd->depth = -1;		
		nodes.insert(mypair(b,nd));
		itb = nodes.find(b);
	}
	node * tmp =  (itb->second);
	it->second->nbrs.insert( tmp );
}

int main(){
	int numScenarios, scenario, P, paper, n, name;	

	cin >> numScenarios;
	cin.ignore(10000,'\n');
	for(scenario = 0; scenario < numScenarios; scenario++){
		cout << "Scenario " << scenario + 1 << endl;
		cin >> P >> n;
		cin.ignore(10000,'\n');

		string line,ignore;
		vector<string> authorvec;

		for (paper = 0;  paper < P; paper++){
			getline(cin, line, ':'); // the authors
			getline(cin,ignore);	
			stringstream ss(line);
			string first,last;
				
			top:
			while(isspace(ss.peek())) ss.get();
			getline(ss,last,',');
			while(isspace(ss.peek())) ss.get();
			getline(ss,first,',');
			authorvec.push_back(last+first);
			if (!ss.eof()) goto top;
				
			//for (int i = 0 ; i < authorvec.size(); i++){
				//cout << authorvec[i] << endl;
			//}
				
			for(int i = 0; i < authorvec.size(); i++){
				for(int j = 0; j < authorvec.size(); j++){
					if ( i == j) continue;
					insertin(authorvec[i],authorvec[j]);
				}
			}
			authorvec.clear();
		}
		
		
		queue<node *> q;
		node * tmp;
		int depth = 0;
		node * erdos = NULL;
		if(nodes.find("ErdosP.") == nodes.end()){
			goto skipover;
		}
		erdos = nodes["ErdosP."];
		erdos->color = 1;
		q.push(erdos);
		while(!q.empty()){
			int sz = q.size();
			for( int qiter = 0; qiter < sz; qiter++ ){
				tmp = q.front();
				q.pop();	
				tmp->depth = depth;
				set<node *>::iterator sit = tmp->nbrs.begin();
				while( sit != tmp->nbrs.end() ){
					if( (*sit)->color == 0){
						(*sit)->color = 1;
						q.push(*sit);		
					}
					sit++;
				}
			}
			depth++;
		}
		
		skipover:
		for (name = 0; name < n; name++){
			getline(cin,line);
			stringstream ss(line);
			string first,last;
				
			top2:
			while(isspace(ss.peek())) ss.get();
			getline(ss,last,',');
			while(isspace(ss.peek())) ss.get();
			getline(ss,first,',');
			if ( nodes.find(last+first) != nodes.end()){
				int where = nodes[last+first]->depth; 
				if (where != -1)
					cout << line << " " << where << endl;
				else 
					cout << line << " infinity" << endl;
			} else {
				cout << line << " infinity" << endl;
			}
			if (!ss.eof()) goto top2 ;
		}
		nodes.clear();
	}
	
	return 0;
}
