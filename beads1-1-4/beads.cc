/*
ID: davidcd1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int bound(int i, int n){
	if(i<0){
		return n+i;
	}
	if(i>=n){
		return i-n;
	}
	return i;
}

int main(){
	ifstream fin ("beads.in");
	ofstream fout("beads.out");

	int n;
	string bead;
	fin >> n;
	fin >> bead;

	vector<string> beads;
	for(int i=0;i<bead.size();i++){
		beads.push_back(bead.substr(i,1));
	}
	for(int i=0;i<bead.size();i++){
		beads.push_back(bead.substr(i,1));
	}
	//cout << n << " " << beads.size();
	int total = 0;
	int max = -1;

	for(int i=0;i<beads.size()-n;i++){
		total = 0;
		string color = beads[i];
		bool stopNext = false;
		//cout << color << endl;
		for(int j=0;j<n;j++){
			if(color=="w"){
				color = beads[i+j];
			}
			//cout << total << endl;
			if(beads[i+j]=="w" || beads[i+j]==color){
				//cout << beads[i+j];
				total++;
			}else{
				if(!stopNext){
					color = beads[i+j];
					stopNext = true;
					total++;
					//cout << beads[i+j];
				}else{
					break;
				}
			}
		}
		//cout << endl;
		if(total > max){
			max = total;
			//cout << i << endl;
		}
	}
	if(max==-1){
		max = n;
	}
	
	fout << max << endl;
} 	