def detect(node,parent,path_vis,vis,adj):
    vis[node]=1
    path_vis[node]=1

    for i in adj[node]:
        if not vis[i]:
            if detect(i,node,path_vis,vis,adj):
                return True
        elif path_vis[i] :
            return True
    
    path_vis[node]=0
    return False




class Solution:
    def canFinish(self, n: int, p: List[List[int]]) -> bool:

        adj=[[] for _ in range(n)]
        vis=[0]*n
        path_vis=[0]*n
        for v,u in p:
            adj[u].append(v)
        
        for i in range(n):
            if not vis[i]:
                if detect(i,-1,path_vis,vis,adj):
                    return False
        
        return True


        