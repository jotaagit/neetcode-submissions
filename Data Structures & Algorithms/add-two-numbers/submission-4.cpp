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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // First Try
        /*int sum = 0;
        int idx = 0;
        while (l1) {
            sum = sum + (l1->val * std::pow(10, idx));
            idx++;
            l1 = l1->next;
        }
        idx = 0;
        while (l2) {
            sum = sum + (l2->val * std::pow(10, idx));
            idx++;
            l2 = l2->next;
        }
        ListNode* temp = new ListNode(0);
        ListNode* p = temp;
        if (sum == 0) {
            p->next = new ListNode(0);
        } else {
            while (sum > 0) {
                int alg = sum % 10;
                sum = sum / 10;
                p->next = new ListNode(alg);

                p = p->next;
            }
        }
        ListNode* l3 = temp->next;
        delete temp;

        return l3;
        */ 
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;


        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            

            int sum = carry + x + y;
            carry = sum / 10;
            

            current->next = new ListNode(sum % 10);
            current = current->next;


            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        
        return result;
    }
};

/*
1->2->3 = 321
4->5->6 = 654
     p.val = 975%10
     sum = sum/10 = 97

if p is the node
idx = 0
int sum = 0

sum = sum + (p.val * 10^idx)
p
.val = sum

*/