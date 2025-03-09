#include <bits/stdc++.h>
using namespace std;
#define int long long
int rnd(int l, int r){
	int m = rand();
	return min(r,l + (m % r));
}
vector<pair<int,int>> gentree(int n){
	vector<pair<int,int>>edges;
	vector<int>incmp(1,1),outcmp(n-1);
	iota(outcmp.begin(),outcmp.end(),2);
	for(int i = 0;i<n-1;i++){
		int u = rnd(1,incmp.size())-1;
		int v = rnd(1,outcmp.size())-1;
		edges.push_back({incmp[u],outcmp[v]});
		incmp.push_back(outcmp[v]);
		swap(outcmp[v],outcmp.back());
		outcmp.pop_back();
	}
	return edges;
}

int32_t main()
{
    	int n = 1000000;
	vector<pair<int,int>>edges = gentree(n);
	cout<<"Done\n";
}
