#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <list>
using namespace std;

struct node{
	string s;
	node * prev;
	node(string in, node * last);
};

node::node(string in, node * last){
	this->s = in;
	this->prev = last;
}

map<string,bool> dict;
string tmp,beginning,goal;


void traceback(node * in){
	if(in == NULL) return;	
	traceback(in->prev);
	cout << in->s << endl;	
}

void bfs(string start,string finish){
		queue<node *> q;
		list<node *> lst;
		map<string,bool> seen;

		node * nd = new node(start,NULL);
		q.push(nd);
		lst.push_back(nd);

		while( !q.empty() ){
			nd = q.front();
			q.pop();
			//generate the neighbours
			string t = nd->s;
			for(int i = 0; i < t.length(); i++){ // for each char
				char orig = t[i];
				for(int j = (int)'a'; j <= (int)'z'; j++){
					if(orig == (char)j) continue;	
					t[i] = (char)j;
					if( dict.find(t) != dict.end() && seen.find(t) == seen.end()){
						node * tmpnode = new node(t,nd);
						seen[t] = true;
						lst.push_back(tmpnode);
						q.push(tmpnode);
						if(t == finish){
							traceback(tmpnode);
							for(list<node *>::iterator k = lst.begin();
								k != lst.end(); k++){
								delete (*k);	
							}
							return;
						}
					}
					t[i] = orig;
				}
			}
		}

		cout << "No solution." << endl;
		for(list<node *>::iterator k = lst.begin();
			k != lst.end(); k++){
			delete (*k);	
		}
		return;
}

int main(){
	bool first = true;
	while(true){
		getline(cin,tmp);
		if(tmp.length() == 0){
			break;
		}
		dict[tmp] = true;
	}

	while(cin >> beginning >> goal){
		if(!first) cout << endl;
		bfs(beginning,goal);
		first = false;
	}

	return 0;
}
