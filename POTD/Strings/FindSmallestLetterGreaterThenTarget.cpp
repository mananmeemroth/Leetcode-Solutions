#include <istream>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i=0;i<letters.size();i++){
            if(target==letters[i]) return letters[i+1];
            
        }
        return letters[0];
    }
};