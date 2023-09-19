# By : Mohamed Bakr

class Disjoint_Set_Union:
    def __init__(self, n):
        self.parent = [0] * (n+1)
        self.sz = [1] * (n+1)
        for i in range(0,n+1):
            self.parent[i] = i
            
    def find(self, u):
        if u == self.parent[u]:
            return u
        else:
            self.parent[u] = self.find(self.parent[u])
            return self.parent[u]

    def add(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if u == v:
            return False
        if self.sz[u] < self.sz[v]:
            self.parent[u] = v
            self.sz[v] += self.sz[u]
        else:
            self.parent[v] = u
            self.sz[u] += self.sz[v]
        return True

    def same(self, u, v):
        return self.find(u) == self.find(v)
