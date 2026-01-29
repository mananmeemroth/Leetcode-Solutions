#include <iostream>
using namespace std;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dist[26][26];
        const long long INF = 1e14;
        // initialize dist
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j){
                    dist[i][j] = 0;
                }else{
                    dist[i][j] = INF;
                }
            }
        }
        // direct transformations
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            dist[u][v]=min(dist[u][v],(long long)cost[i]);
        }
        // floyd-warshall
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        // calculate total cost;
        long long ans = 0;
        for(int i=0;i<source.size();i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(dist[u][v]==INF) return -1;
            ans+=dist[u][v];
        }
        return ans;
    }
};