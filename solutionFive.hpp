#ifndef SOLUTION_FIVE_HPP
#define SOLUTION_FIVE_HPP

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

class SolutionFive{
public:
	int n, distanceThreshold;
	int dist[100][100];
	void FW(vector<vector<int>>& edges){
		fill(&dist[0][0], &dist[0][0]+100*100, 1e9);
		for(int i=0; i<n; i++){
			dist[i][i]=0;
		}
		for(auto& edge: edges){
			int u=edge[0], v=edge[1], w=edge[2];
			if(w!=distanceThreshold){
				dist[u][v]=dist[v][u]=w;
			}
		}
		for(int k=0; k<n; k++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}
	}
	int findCity(int n, vector<vector<int>>& edges, int distanceThreshold){
		this->n=n;
		this->distanceThreshold=distanceThreshold;
		FW(edges);
		int min_cnt=n, city=-1;
		for(int i=0; i<n; i++){
			int cnt=-1;
			for(int j=0; j<n; j++){
				if(dist[i][j]<=distanceThreshold){
					cnt++;
				}
			}
			if(cnt<=min_cnt){
				min_cnt=cnt;
				city=i;
			}
		}
		return city;
	}
};

#endif