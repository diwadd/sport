#include <iostream>
#include <string>

using namespace std;

ListNode* res;

class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* c1 = l1;
        ListNode* c2 = l2;

        int c1_size = 0;
        int c2_size = 0;
        
        while(c1 != nullptr) {
            c1_size++;
            c1 = c1->next;
        }
        
        while(c2 != nullptr) {
            c2_size++;
            c2 = c2->next;
        }
        
        ListNode* first;
        ListNode* second;
        if(c1_size <= c2_size) {
            first = l1;
            second = l2;
        } else {
            first = l2;
            second = l1;
        }
        
        ListNode *start = new ListNode(0, nullptr);
        ListNode *res = start;
        
        int carry = 0;
        while(first != nullptr) {
            
            int sum = first->val + second->val;
            
            start->val = ( sum + carry ) % 10;
            carry = (sum + carry ) / 10;
            
            
            first = first->next;
            second = second->next;

            if(first != nullptr) {
                start->next = new ListNode(0, nullptr);
                start = start->next;                
            }   
        }
        
        if(second != nullptr) {
            start->next = new ListNode(0, nullptr);
            start = start->next; 
        }
        
        while(second != nullptr) {
            
            int sum = second->val + carry;
            start->val = ( sum ) % 10;
            carry = sum / 10;
            
            second = second->next;

            if(second != nullptr) {
                start->next = new ListNode(0, nullptr);
                start = start->next;                
            }
        }
        
        if(carry != 0) {
            start->next = new ListNode(carry, nullptr);
        }
                
        return res;
    }
};