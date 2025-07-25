#include <iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int value){
        val = value;
        next = nullptr;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};