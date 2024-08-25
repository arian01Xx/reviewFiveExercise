#ifndef SOLUTION_FOUR_HPP
#define SOLUTION_FOUR_HPP

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

class SolutionFour{
public:
	long long maximumImportance(int n, vector<vector<int>>& roads){
		vector<int> deg(n,0);
		for(auto it: roads){
			deg[it[0]]++;
			deg[it[1]]++;
		}
		sort(deg.begin(),deg.end());
		int ans=0;
		for(int i=0; i<n; i++){
			ans+=(i+1LL)*deg[i];
		}
		return ans;
	}
};

#endif