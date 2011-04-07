#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char grid[51][51];
int m,n,k,numcases;
		
bool searchdirection(string s,int posi, int posj,int diri,int dirj){
	int i = posi;
	int j = posj;
	for(int l = 1; l < s.length(); l++){
		i += diri;
		j += dirj;
		if( i < 0 || j < 0 || i >= m || j >= n || (s[l] != grid[i][j]))
			return false;
	}
	return true;
}

bool search(string s,int posi, int posj){
	if(s[0] != grid[posi][posj]) return false;
	return searchdirection(s,posi,posj,0,1) ||
			searchdirection(s,posi,posj,1,0) ||
			searchdirection(s,posi,posj,0,-1) ||
			searchdirection(s,posi,posj,-1,0) ||
			searchdirection(s,posi,posj,1,1) ||
			searchdirection(s,posi,posj,-1,-1) ||
			searchdirection(s,posi,posj,1,-1) ||
			searchdirection(s,posi,posj,-1,1) ;
}
	
void searchAll(string find){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(search(find,i,j)){
				cout << i+1 << " " << j+1 << endl;
				return;
			}
		}
	}
}

int main(){
	string find;
	cin >> numcases;
	cin.ignore(1000,'\n');
	while( numcases--){ // 
		cin.ignore(1000,'\n');
		cin >> m >> n;   
		// read in the grid
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cin >> grid[i][j];
				grid[i][j] = tolower(grid[i][j]);
			}
		}
		cin >> k;
		while(k--){
			cin >> find;
			for(int i = 0; i < find.length(); i++)
				find[i] = tolower(find[i]);
			searchAll(find);
		}
		cin.ignore(1000,'\n');
		if( numcases != 0){
			cout << endl;
		}

	}
	return 0;
}
