#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

#ifndef NULL
#define NULL 0
#endif
using namespace std;

typedef struct token{
	char a;
	bool star;
}token;

class Solution {
public:
	token getToken(string const & pass, int mark){
		token a = {0,false};
		if(!(pass.size()-mark)) return a;
		a.a = pass[mark];
		if(pass.size()-mark>=2 && pass[mark+1]=='*'){
			a.star = true;
		}
		//cout<< a.a<<' '<<a.star<<endl;
		return a;
	}
	bool checkChar(char a, char b){
		return a==b || b=='.';
	}
	bool checkEnd(string const &p, int j){
		token b = getToken(p, j);
		if (b.a == 0) return true;
		if (b.star) return checkEnd(p, j+2);
		else return false;
	}
	//bool checkEndToken(string const &p, int j){
	//	token b = getToken(p, j);
	//	if(!b.star) return checkEnd(p,j+1);
	//	else return checkEnd(p,j+2);
	//}
	bool match(string const &s, string const &p, int i, int j){
		//int static matchTable[s.size()][p.size()];
		token b = getToken(p, j);
		//cout<<i<<' '<<j<<' '<<b.a<<' '<< s.size()<<endl;
		if (b.a == 0) return (s.size()==i);
		if (s.size() == i) return b.star && checkEnd(p,j+2);
		//if (matchTable[i*s.size()+j]) return matchTable[i*s.size()+j]-1;
		if (!b.star) {
			bool ret = checkChar(s[i], b.a) && match(s,p,i+1,j+1);
			//matchTable[i*s.size()+j] = (int)ret + 1;
			return ret;
		}
		if (b.star){
			if(!checkChar(s[i],b.a)){
				bool ret = match(s,p,i,j+2);
				//matchTable[i*s.size()+j] = (int)ret + 1;
				return ret;
			}
			else{
				bool ret = match(s,p,i,j+2) || match(s,p,i+1,j);
				//matchTable[i*s.size()+j] = (int)ret + 1;
				return ret;
			}
		}
	}
    bool isMatch(string s, string p) {
		int i = 0;
		int j = 0;
		//matchTable = (int*)malloc(sizeof(int)*(s.size()*p.size()));
		return match(s, p, i, j);
    }
//private:
	//int *matchTable;
};
int main(){
	auto solution = new Solution();
	auto ret = solution->isMatch("a","ab*");
	cout<<ret<<endl;
	return 0;
}

