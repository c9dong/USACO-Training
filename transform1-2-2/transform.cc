/*
ID: davidcd1
PROG: transform
LANG: C++
*/

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void debug(vector<vector<char> > &v){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			cout << v.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

void rotate90(vector<vector<char> > &v, int n){
	char temp;
	for(int i=0;i<n-2;i++){
		for(int j=i;j<n-1-i;j++){
			temp = v.at(i).at(j);
			v.at(i).at(j) = v.at(n-j-1).at(i);
			v.at(n-j-1).at(i) = v.at(n-i-1).at(n-j-1);
			v.at(n-i-1).at(n-j-1) = v.at(j).at(n-i-1);
			v.at(j).at(n-i-1) = temp;
		}
	}
}

void reflect(vector<vector<char> > &v, int n){
	char temp;
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n;j++){
			temp = v.at(j).at(i);
			v.at(j).at(i) = v.at(j).at(n-i-1);
			v.at(j).at(n-i-1) = temp;
		}
	}
}

bool checkSame(vector<vector<char> > &vi, vector<vector<char> > &vf, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(vi.at(i).at(j) != vf.at(i).at(j)){
				return false;
			}
		}
	}
	return true;
}

int findOp(vector<vector<char> > &init, vector<vector<char> > &end, int n){
	
	rotate90(init, n);
	if(checkSame(init, end, n)){
		return 1;
	}
	rotate90(init, n);
	if(checkSame(init, end, n)){
		return 2;
	}
	rotate90(init, n);
	if(checkSame(init, end, n)){
		return 3;
	}
	rotate90(init, n);
	reflect(init, n);
	if(checkSame(init, end, n)){
		return 4;
	}
	for(int i=0;i<3;i++){
		rotate90(init, n);
		if(checkSame(init, end, n)){
			return 5;
		}
	}
	if(checkSame(init, end, n)){
		return 6; 
	}
	return 7;
}

int main(){

	ofstream fout ("transform.out");
	ifstream fin("transform.in");

	int n;
	fin >> n;

	vector<vector<char> > init;
	vector<vector<char> > end;

	
	string temp;
	for(int i=0;i<n;i++){
		fin >> temp;
		vector<char> t;
		for(int j=0;j<n;j++){
			t.push_back(temp.at(j));
		}
		init.push_back(t);
	}
	for(int i=0;i<n;i++){
		fin >> temp;
		vector<char> t;
		for(int j=0;j<n;j++){
			t.push_back(temp.at(j));
		}
		end.push_back(t);
	}

	//debug(init);
	//debug(end);

	int num;

	num = findOp(init, end, n);

	fout << num << endl;

}