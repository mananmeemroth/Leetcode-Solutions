#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseByType(string s) {
        vector<char> letters,specials;
        for(char c:s){
            if(islower(c)){
                letters.push_back(c);
            }else{
                specials.push_back(c);
            }
        }
        reverse(letters.begin(),letters.end());
        reverse(specials.begin(),specials.end());
        string res;
        int letterIdx =0,specialsIdx = 0;
        for(char c:s){
            if (islower(c)) {
                res.push_back(letters[letterIdx++]);
            } else {
                res.push_back(specials[specialsIdx++]);
            }
        }
        return res;
    }
};