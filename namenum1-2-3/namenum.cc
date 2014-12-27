/*
ID: davidcd1
PROG: namenum
LANG: C++
*/

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<vector<string> > letters;
vector<string> dict;
vector<string> names;
int total = 1;

void debug1(vector<string> &v){
	for(int i=0;i<v.size();i++){
		cout << v.at(i) << endl;
	}
}

void debug2(vector<vector<string> > &v){
	for(int i=0;i<v.size();i++){
		cout << v.at(i).at(0) << " " << v.at(i).at(1) << " " << v.at(i).at(2) << endl;
	}
}

bool inVector(vector<string> &v, string c){
	for(int i=0;i<v.size();i++){
		if(v.at(i) == c){
			return true;
		}
	}
	return false;
}

bool checkName(string s){
	for(int i=0;i<dict.size();i++){
		if(s == dict.at(i)){
			return true;
		}
	}
	return false;
}

void makenames(int n, string s){
	if(n == total){
		if(checkName(s)){
			names.push_back(s);
		}
		return;
	}
	makenames(n+1, s+letters.at(n).at(0));
	makenames(n+1, s+letters.at(n).at(1));
	makenames(n+1, s+letters.at(n).at(2));
}


int main(){
	ifstream fin("namenum.in");
	ifstream dictIn("dict.txt");
	ofstream fout("namenum.out");

	string n;

	fin >> n;

	total = n.size();
	
	for(int i=0;i<n.size();i++){
		//total = total*3;
		if(n.at(i)=='2'){
			vector<string> t;
			t.push_back("A");
			t.push_back("B");
			t.push_back("C");
			letters.push_back(t);
		}else if(n.at(i) == '3'){	
			vector<string> t;
			t.push_back("D");
			t.push_back("E");
			t.push_back("F");
			letters.push_back(t);
		}else if(n.at(i) == '4'){
			vector<string> t;
			t.push_back("G");
			t.push_back("H");
			t.push_back("I");
			letters.push_back(t);
		}
		else if(n.at(i) == '5'){
			vector<string> t;
			t.push_back("J");
			t.push_back("K");
			t.push_back("L");
			letters.push_back(t);
		}
		else if(n.at(i) == '6'){
			vector<string> t;
			t.push_back("M");
			t.push_back("N");
			t.push_back("O");
			letters.push_back(t);
		}
		else if(n.at(i) == '7'){
			vector<string> t;
			t.push_back("P");
			t.push_back("R");
			t.push_back("S");
			letters.push_back(t);
		}
		else if(n.at(i) == '8'){
			vector<string> t;
			t.push_back("T");
			t.push_back("U");
			t.push_back("V");
			letters.push_back(t);
		}
		else if(n.at(i) == '9'){
			vector<string> t;
			t.push_back("W");
			t.push_back("X");
			t.push_back("Y");
			letters.push_back(t);
		}
	}

	string d;
	
	while(dictIn >> d){
		if(d.size() == n.size() && inVector(letters.at(0), d.substr(0,1))){
			dict.push_back(d);
		}
	}

	//cout << total << endl;
	//debug1(dict);
	//debug2(letters);
	makenames(0, "");
	//debug1(names);
	//cout << names.size() << endl;
	if(names.size() == 0){
		fout << "NONE" << endl;
	}else{
		for(int i = 0;i<names.size();i++){
			fout << names.at(i) << endl;
		}
	}
}