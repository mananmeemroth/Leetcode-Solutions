#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyprice=prices[0];
        int profit =0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<buyprice) buyprice = prices[i];
            profit = max(profit,prices[i]-buyprice); 
        }
        return profit;
    }
};