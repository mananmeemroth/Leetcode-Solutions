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
