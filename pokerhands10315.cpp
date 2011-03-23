#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;


enum Suit {CLUBS, HEARTS,SPADES,DIAMONDS}; 
enum CardVal {TWO = 2, THREE=3, FOUR=4, FIVE=5,SIX=6,SEVEN=7,
EIGHT=8,NINE=9,TEN=10,JACK=11,QUEEN=12,KING=13,ACE=14};
char suitChars[] = {'C','H','S','D'}; 
char valueChars[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'}; 

class Card{
public:
	Suit suit;
	CardVal value;
Card(CardVal v, Suit s);
Card();
friend ostream& operator<<(ostream& s, Card &c);
friend istream& operator>>(istream& s, Card &c);
bool operator<(const Card & rhs) const;
};

Card::Card(CardVal v, Suit s){
suit = s;
value = v;	
}

Card::Card(){
suit = CLUBS; 
value = TWO;	
}

bool Card::operator<(const Card & rhs) const{
		return this->value < rhs.value;
}

istream& operator>>(istream& s, Card &c){
char a,b;
int i,j;
s >> a >> b;
for(i = 0; i < 13; i++){
if(a == valueChars[i]) break;		
}

for(j = 0; j < 4; j++){
if (b == suitChars[j]) break; 	
}

c = Card(static_cast<CardVal>(i+2),(Suit)j);
return s;
}

ostream& operator<<(ostream& s, Card &c){
//s  << valueChars[(int)c.value];
s  << valueChars[(int)c.value-2] << suitChars[(int)c.suit];
return s;
}

unsigned int handType(Card * in){
sort(in, in+5);

bool flush = 1,straight = 1;
Suit chk = in[0].suit;
for(int i = 1; i < 5; i++){
if(in[i].suit != chk){
	flush = false;
} 
if(in[i].value != in[i-1].value+1){
	straight = false;
}
}

//		if(!flush && in[0].value == TWO && in[1].value == THREE
//				&& in[2].value == FOUR && in[3].value == FIVE
//				&& in[4].value == ACE){
//			return 6000000;		
//		}
//
//		if(flush && in[0].value == TWO && in[1].value == THREE
//				&& in[2].value == FOUR && in[3].value == FIVE
//				&& in[4].value == ACE){
//			return 100000000;		
//		}
 
int counters[5]; //num pairs..threes..etc.
for (int i = 0; i <= 4; i++){
	counters[i] = 0;
}
	vector<int> cardValues[5];

	int count = 1;
	for ( int i = 1; i < 5; i++){
		if(in[i].value == in[i-1].value){
				count++;
		} else {
				counters[count]++;
				cardValues[count].push_back((unsigned int)in[i-1].value);
				count = 1;
		}
	}
	counters[count]++;
    cardValues[count].push_back((unsigned int)in[4].value);

	if(straight && flush){
			return 100000000 + in[4].value; //+ in[3].value * 16*16*16 + in[2].value * 16*16+ in[1].value *16 + in[0].value ;
	} if(counters[4] == 1){
			return 9000000+cardValues[4][0] ;//+ cardValues[1][0];
	} if(counters[3] == 1 && counters[2] ==1){
			return 8000000+cardValues[3][0] ;// + cardValues[2][0];
	} if(flush){
			return 7000000+in[4].value*16*16*16*16+in[3].value*16*16*16+in[2].value*16*16+in[1].value*16+in[0].value;
	} if (straight){
			return 6000000+in[4].value;		
	} if ( counters[3] == 1){
			return 5000000+16*16*16*cardValues[3][0];//+cardValues[1][1]*16+cardValues[1][0];
	} if (counters[2] == 2){
			return 4000000+16*16*16*16*cardValues[2][1] + 16*16*cardValues[2][0] + 16*cardValues[1][0];
	} if (counters[2] == 1){ 
			return 3000000+16*16*16*16*cardValues[2][0] + 16*16*16*cardValues[1][2] +
			      16*cardValues[1][1] + cardValues[1][0];
	}
	return 16*16*16*16*in[4].value+16*16*16*in[3].value+16*16*in[2].value+16*in[1].value+in[0].value;
}

int main(){
	Card black[5];
	Card white[5];
	int i;
	unsigned int whiteval, blackval;
	string line;
	while (getline(cin,line)){
			stringstream ss(line);
			 ss >> black[0] >> black[1] >> black[2] >> black[3] >> black[4] >>
		            white[0] >> white[1] >> white[2]>> white[3]>> white[4];


		
		blackval = handType(black);
		whiteval = handType(white);
		if(blackval > whiteval){
				cout << "Black wins.";
		} else if ( whiteval > blackval){
				cout << "White wins.";
		} else {
				cout << "Tie.";
		} 
		cout << endl;
		//for (i = 0; i < 5; i++){
			//cout << black[i] << " ";
		//}
  		//for (i = 0; i < 5; i++){
  			//cout << white[i] << " ";
  		//}
	 }
}
