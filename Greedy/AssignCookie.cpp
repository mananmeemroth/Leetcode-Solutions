// problem: 455
#include <iostream>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while (i < s.size() && j < g.size()) {
            if (g[j] <= s[i]) j++;
            i++;
        }

        return j;
    }
};

// similar question to assign cookies

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i=0,j=0;
        while(i<players.size()&&j<trainers.size()){
            if(players[i]<=trainers[j]) i++;
            j++;
        }
        return i;
    }
};