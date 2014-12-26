/*
ID: davidcd1
PROG: milk2
LANG: C++
*/

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

void debug(vector<pair<int, int > > &v){
	for(int i=0;i<v.size();i++){
		cout << v.at(i).first << " " << v.at(i).second << endl;
	}
	cout << "-----------------------------------------" << endl;
}

int partition(vector<pair<int, int> > &v, int low, int high){
	int pivot = v.at(high).first;
	int pivIdx = high;
	//cout << v.at(high).first << endl;
	//debug(v);
	pair<int, int> temp;
	int start = low;
	for(int i=low;i<high;i++){
		if(v.at(start).first > pivot){
			temp = v.at(start);
			v.at(start) = v.at(pivIdx-1);
			v.at(pivIdx-1) = v.at(pivIdx);
			v.at(pivIdx) = temp;
			pivIdx--;
			//debug(v);
		}else{
			start ++;
		}
	}

	return pivIdx;
}

void quickSort(vector<pair<int,int> > &v, int low, int high){
	if(low < high){
		int p = partition(v, low, high);
		//debug(v);
		quickSort(v, low, p-1);
		quickSort(v, p+1, high);
	}
}

int checkInInterval(vector<pair<int,int> > &intervals, int num){
	for(int i=0;i<intervals.size();i++){
		if(intervals.at(i).first < num && num <= intervals.at(i).second){
			return i;
		}
	}
	return -1;
}

int main(){

	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");

	int n;
	int start;
	int end;

	fin >> n;

	vector<pair<int, int> > inputs;
	vector<pair<int,int> > intervals;

	for(int i=0;i<n;i++){
		fin >> start;
		fin >> end;
		pair<int,int> temp;
		temp.first = start;
		temp.second = end;
		inputs.push_back(temp);
	}

	quickSort(inputs, 0, n-1);

	//debug(inputs);

	int index;
	for(int i=0;i<n;i++){
		start = inputs.at(i).first;
		end = inputs.at(i).second;
		//cout << start << " " << end << endl;
		index = checkInInterval(intervals, start);
		if(index != -1){
			if(intervals.at(index).second < end){
				intervals.at(index).second = end;
			}
		}else{
			index = checkInInterval(intervals, end);
			if(index != -1){
				if(start < intervals.at(index).first){
					intervals.at(index).first = start;
				}
			}else{
				pair<int,int> temp;
				temp.first = start;
				temp.second = end;
				intervals.push_back(temp);
			}
		}
	}

	//debug(intervals);

	int longestMilking=0;
	int longestIdle=0;
	for(int i=0;i<intervals.size();i++){
		if(intervals.at(i).second - intervals.at(i).first > longestMilking){
			longestMilking = intervals.at(i).second - intervals.at(i).first;
		}
		if(i<intervals.size()-1){
			int delay=0;
			if(intervals.at(i).second < intervals.at(i+1).first){
				delay = intervals.at(i+1).first - intervals.at(i).second;
			}else{
				delay = intervals.at(i).first - intervals.at(i+1).second;
			}
			if(delay>longestIdle){
				longestIdle = delay;
			}
		}
	}
	fout << longestMilking << " " << longestIdle << endl;
}