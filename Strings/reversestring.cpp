#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int end=s.size()-1;
        while(start!=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
        for(char c:s){
            cout<<c;
        }
        cout << endl;
        
    }
};
int main() {
    Solution s2;
    vector<char> input = {'h', 'e', 'l', 'l', 'o'};
    s2.reverseString(input);
    return 0;
}