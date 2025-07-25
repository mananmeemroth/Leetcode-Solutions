#include <iostream>
using namespace std;
class ListNode{
public: 
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(){
        next = prev = nullptr;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while(curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        return prev;
        
    }

};