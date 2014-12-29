/*
ID: davidcd1
PROG: dualpal
LANG: C++
*/

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<string> baseNum;

string convertBase(int num, int base){
	if(num == 0){
		return "";
	}
	return convertBase(num/base, base)+baseNum.at(num%base);
}

bool isPalid(string s){
	int n = s.size();
	for(int i=0;i<n/2;i++){
		if(s.at(i) != s.at(n-i-1)){
			return false;
		}
	}
	return true;
}

int main(){
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int n;
	int s;

	fin >> n;
	fin >> s;
	s++;



	baseNum.push_back("0");
	baseNum.push_back("1");
	baseNum.push_back("2");
	baseNum.push_back("3");
	baseNum.push_back("4");
	baseNum.push_back("5");
	baseNum.push_back("6");
	baseNum.push_back("7");
	baseNum.push_back("8");
	baseNum.push_back("9");

	int c = 0;
	int c2 = 0;
	while(c<n){
		//cout << s << endl;
		c2 = 0;
		for(int i=2;i<=10;i++){
			//cout << convertBase(s,i) << endl;
			
			if(isPalid(convertBase(s, i))){
				c2++;
			}
			if(c2==2){
				fout << s << endl;
				c++;
				break;
			}
		}
		s++;
	}
}