#ifndef SOLUTION_THREE_HPP
#define SOLUTION_THREE_HPP

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

class SolutionThree{
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges){
		set<int> start; set<int> finish;
		for(int i=0; i<edges.size(); i++){
			for(int j=0; j<edges[i].size(); j++){
				start.insert(edges[i][0]);
				finish.insert(edges[i][1]);
			}
		}
		vector<int> alone;
		for(auto it=start.begin(); it!=start.end(); it++){
			if(finish.find(*it)==finish.end()){
				alone.push_back(*it);
			}
		}
		return alone;
	}
};

#endif