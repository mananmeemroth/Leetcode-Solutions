// brute force approach
#include <iostream>
using namespace std;
class ListNode{
public:
    int data;
    ListNode* next;

    ListNode(int val){
        data = val;
        next = nullptr;
    }
};
class Solution{
    ListNode* head;
    ListNode* tail;
public:
    int length(ListNode* head){
        int idx = 0;
        ListNode* temp = head;
        while(temp!=tail){
            temp = temp->next;
            idx++;
        }
        return idx;
    }

    ListNode* middleNode(ListNode* head) {
        int len = length(head);
        int mid = len / 2; 
        ListNode* temp = head;
        
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        return temp;
    }
};

// optimal approach (2 pointer approach)
// 
// one is fast and take 2 steps at a time and other is 
// slow takes 1 step at a time and we will travers them
//  till the fast reaches the end;and will return slow part

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};