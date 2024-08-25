#ifndef SOLUTION_ONE_HPP
#define SOLUTION_ONE_HPP

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cmath>

using namespace std;

class SolutionOne{
public:
	int findJugde(int n, vector<vector<int>>& trust){
		vector<int> trustCoun(n+1,0);
		vector<bool> trustSomeone(n+1,false);
		for(const auto& edge: trust){
			trustSomeone[edge[0]]=true;
			trustCoun[edge[1]]++;
		}
		for(int i=0; i<n; i++){
			if(!trustSomeone[i] && trustCoun[i]==n-1){
				return i;
			}
		}
		return -1;
	}
};

#endif