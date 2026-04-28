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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = 0;
        ListNode* first = head;
        ListNode* second = head;
        while(counter != n){
            first = first->next;
            counter++;
        }
        if(first == nullptr){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        while(first->next != nullptr) {
            first = first->next;
            second = second->next;
        }
        ListNode* tmp = second->next;
        second->next = (second->next)->next;
        delete tmp;

        return head;
    }
};
