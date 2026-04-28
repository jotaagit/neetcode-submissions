/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next || !head->next->next) return;

        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }


        int targetSteps = (count - 1) / 2;
        curr = head;
        for (int i = 0; i < targetSteps; i++) {
            curr = curr->next;
        }


        ListNode* secondHalf = curr->next; 
        curr->next = nullptr;              

        
        
        ListNode* prev = nullptr;
        ListNode* p = secondHalf;
        ListNode* nextNode = nullptr;
        
        while (p) {
            nextNode = p->next;
            p->next = prev;
            prev = p;
            p = nextNode;
        }
        

        
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
        
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

        
            first->next = second;
            
            second->next = temp1;

            
            first = temp1;
            second = temp2;
        }
    }
};


/*
0    1    2    3    
     6    5    4   



*/