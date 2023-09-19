#include <bits/stdc++.h>
using namespace std;

// By : Mhmd_Bakr

struct dsu
{
	vector<int>parent, sz;
	dsu(int n)
	{
        parent = sz = vector<int>(n+1);
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
	}
	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	bool add(int u, int v)
	{
		u = find(u); v = find(v);
		if (u == v) return false;
		if (sz[u] < sz[v]) 
        {
			parent[u] = v;
			sz[v] += sz[u];
		}
		else 
        {
			parent[v] = u;
			sz[u] += sz[v];
		}
		return true;
	}
	bool same(int u, int v)
	{ 
		return find(u) == find(v); 
	}
};

int main()
{
    return 0;
}