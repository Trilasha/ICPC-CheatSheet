class Solution {
public:
    // to find all the bridges in the graph - tarjan's algorithm
    int timer=0; 
    void dfs(int node,int par,vector<vector<int>> &adj,vector<int> &vis,vector<int> &tin,vector<int> &lowestTime,vector<vector<int>> &allBridges){
        vis[node]=1;
        timer++;
        for(auto &adjNode:adj[node]){
            if(!vis[adjNode]){
                tin[adjNode]=timer;
                lowestTime[adjNode]=timer;
                dfs(adjNode,node,adj,vis,tin,lowestTime,allBridges);
            }
            if(adjNode!=par && lowestTime[adjNode]>tin[node]){
                allBridges.push_back({node,adjNode});
            }else if(adjNode!=par){
                lowestTime[node]=min(lowestTime[node],lowestTime[adjNode]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1);
        vector<int> tin(n+1),lowestTime(n+1);
        vector<vector<int>> allBridges;
        int len=connections.size();
        for(int x=0;x<len;++x){
            int node1=connections[x][0];
            int node2=connections[x][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        for(int x=0;x<n;++x){
            if(!vis[x]){
                tin[x]=timer;
                lowestTime[x]=timer;
                dfs(x,-1,adj,vis,tin,lowestTime,allBridges);
            }
        }
        // for(int x=1;x<=n;++x){
        //     cout<<tin[x]<<" "<<lowestTime[x]<<endl;
        // }
        return allBridges;
    }
};