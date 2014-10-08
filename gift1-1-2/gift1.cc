/*
ID: davidcd1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int findPerson(vector<pair<string,int> > persons, string p){
	for(int i=0;i<persons.size();i++){
		if(persons[i].first==p){
			return i;
		}
	}
	return -1;
}

int main(){
	ofstream fout ("gift1.out");
	ifstream fin("gift1.in");
	int n;
	fin >> n;
	vector<pair<string,int> > persons;
	for(int i=0;i<n;i++){
		string name;
		fin >> name;
		pair<string, int> p (name, 0);
		persons.push_back(p); 
		//cout << name << endl;
	}
	string giver;
	int amount;
	int numP;
	int index;
	string receiver;
	while (fin>>giver){
		//cout << giver << endl;
		fin>>amount;
		fin>>numP;
		//cout << amount << " " << numP << endl;
		if(numP!=0){
			int money = amount/numP;
			int left = amount%numP;
			index = findPerson(persons,giver);
			persons[index].second -= (amount-left);
			for(int i=0;i<numP;i++){
				fin>>receiver;
				index = findPerson(persons,receiver);
				persons[index].second+=money;
			}
		}
	}
	for(int i=0;i<n;i++){
		fout << persons[i].first <<" " << persons[i].second << endl;
	}
}