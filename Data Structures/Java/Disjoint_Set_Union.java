// By : Mohamed Bakr

public class Disjoint_Set_Union 
{
	public int[] parent;
	public int[] sz;
	public Disjoint_Set_Union(int n)
	{
		parent = new int[n+1];
		sz = new int[n+1];
		for(int i = 0;i<=n;i++)
		{
			parent[i] = i;
			sz[i] = 1;
		}
	}
	public int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	public boolean add(int u, int v)
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
	public boolean same(int u, int v)
	{ 
		return find(u) == find(v); 
	}
}
