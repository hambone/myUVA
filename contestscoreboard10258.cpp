#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct problemScore{
	bool solved;		
	int time;
};

struct contScore{
		int contnum;
		int numSolved;
		int time;
		bool exists;
};

bool tcompare(const contScore & l, const contScore & r){
	return l.time < r.time;
}

bool solvedCompare(const contScore & l, const contScore & r){
	return l.numSolved > r.numSolved;	
}

problemScore contestantProbs[101][10];
contScore contestantScores[101];

int main(){

		int numCases;
		cin >> numCases;
		cin.ignore(1000,'\n');
		cin.ignore(1000,'\n');
		string line;

		while( numCases--){
				for ( int i = 0; i < 101; i++){
						contestantScores[i].exists = false;
						for (int j = 0 ; j < 10; j++){
								contestantProbs[i][j].solved = false;
								contestantProbs[i][j].time = 0;
						}
				}



			int maxContestant = 0,contestant,problem,time;
			char result;
				while(true){ 
					getline(cin,line);
					if(line == "") break;
					stringstream ss(line);
					ss >> contestant >> problem >> time >> result;
					maxContestant = (contestant > maxContestant)?contestant:maxContestant;
					switch (result){
						case 'C':
								if (!contestantProbs[contestant][problem].solved)
										contestantProbs[contestant][problem].time += time;
										contestantProbs[contestant][problem].solved = true;
								contestantScores[contestant].exists = true;
								break;
						case 'I':
								if (!contestantProbs[contestant][problem].solved)
										contestantProbs[contestant][problem].time += 20;
								contestantScores[contestant].exists = true;
								break;
						case 'R':
						case 'U':
						case 'E':
								contestantScores[contestant].exists = true;
								continue;
								break;
					}

				}

				
				for (int i = 1; i <= maxContestant; i++){
					contestantScores[i].numSolved = 0;
					contestantScores[i].time = 0;
					contestantScores[i].contnum = i;
					for( int j = 1; j <= 9; j++){	
							if(contestantProbs[i][j].solved){
									contestantScores[i].numSolved++;
									contestantScores[i].time += contestantProbs[i][j].time;
							}
					}
				}

				stable_sort(contestantScores+1,contestantScores+maxContestant+1,tcompare);
				stable_sort(contestantScores+1,contestantScores+maxContestant+1,solvedCompare);
				for ( int i = 1; i <= maxContestant; i++){
						if(contestantScores[i].exists){
							cout << contestantScores[i].contnum << " " << contestantScores[i].numSolved << " "
							<< contestantScores[i].time << endl;
						}
				}
				if(numCases != 0) cout << endl;
		}
		return 0;
}


