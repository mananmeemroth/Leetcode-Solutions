#include <iostream>
using namespace std;
class Solution {
private:
    void dfs(int node, vector<vector<int>>&AdjLs,vector<int>&vis){
        vis[node]=1;
        for(auto it:AdjLs[node]){
            if(!vis[it]){
                dfs(it,AdjLs,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> AdjLs(V);

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1&&i!=j){
                    AdjLs[i].push_back(j);
                    AdjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(V, 0); 
        int count=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i, AdjLs, vis);
            }
        }
        return count;
    }
};



