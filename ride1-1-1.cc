/*
ID: davidcd1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int computeInt(string t){
	int r = 1;
	for(int i=0; i<t.size(); i++){
		r = r*(t.at(i)-64);
	}
	return r;
}

int main(){
	cout << "Running" << endl;
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	string t1, t2;
	fin >> t1 >> t2;
	int n1, n2;
	n1 = computeInt(t1);
	n2 = computeInt(t2);
	if(n1%47 == n2%47){
		fout << "GO" << endl;
	}else{
		fout << "STAY" << endl;
	}
}