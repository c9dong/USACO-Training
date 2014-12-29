/*
ID: davidcd1
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool checkLeap(int year){
	if(year%400==0){
		return true;
	}
	if(year%100==0){
		return false;
	}
	if(year%4==0){
		return true;
	}
	return false;
}

int main(){
	ifstream fin ("friday.in");
	ofstream fout ("friday.out");
	vector<int> thirteen;
	for(int i=0;i<7;i++){
		thirteen.push_back(0);
	}
	vector<int> numOfMonth;
	numOfMonth.push_back(31);
	numOfMonth.push_back(28);
	numOfMonth.push_back(31);
	numOfMonth.push_back(30);
	numOfMonth.push_back(31);
	numOfMonth.push_back(30);
	numOfMonth.push_back(31);
	numOfMonth.push_back(31);
	numOfMonth.push_back(30);
	numOfMonth.push_back(31);
	numOfMonth.push_back(30);
	numOfMonth.push_back(31);
	int n;
	fin >> n;
	int weekDay = 0;
	for(int year=1900;year<1900+n;year++){
		for(int month = 1; month <= 12; month++){
			if(checkLeap(year)){
				numOfMonth[1] = 29;
			}else{
				numOfMonth[1] = 28;
			}
			for(int day = 1; day <= numOfMonth[month-1]; day++){
				weekDay = (weekDay+1)%7;
				if(day == 13){
					thirteen[weekDay]++;
				}
			}
		}
	}
	fout << thirteen[6] << " " << thirteen[0] << " " << thirteen[1] << " " << thirteen[2] << " " << thirteen[3] << " " << thirteen[4] << " " << thirteen[5] << endl;
}