/*
ID: davidcd1
PROG: palsquare
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
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int n;
	fin >> n;

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
	baseNum.push_back("A");
	baseNum.push_back("B");
	baseNum.push_back("C");
	baseNum.push_back("D");
	baseNum.push_back("E");
	baseNum.push_back("F");
	baseNum.push_back("G");
	baseNum.push_back("H");
	baseNum.push_back("I");
	baseNum.push_back("J");

	string bn;
	string bn2;
	for(int i=1;i<=300;i++){
		bn2 = convertBase(i*i,n);
		if(isPalid(bn2)){
			bn = convertBase(i, n);
			fout << bn << " " << bn2 << endl;
		}
	}
}