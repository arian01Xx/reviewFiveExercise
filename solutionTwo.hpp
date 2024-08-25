#ifndef SOLUTION_TWO_HPP
#define SOLUTION_TWO_HPP

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

class SolutionTwo{
public:
	void dfs(vector<vector<int>> graph, vector<vector<int>> paths, vector<int> path, int start, int destination){
		path.push_back(start);
		if(start==destination){
			paths.push_back(path);
		}
		for(auto x: graph[start]){
			dfs(graph,paths,path,x,destination);
		}
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
		vector<vector<int>> paths;
		vector<int> path;
		int node=graph.size()-1;
		if(node==0) return paths;
		dfs(graph, paths, path, 0, node);
		return paths;
	}
};

#endif