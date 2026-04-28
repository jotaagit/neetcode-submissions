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
        // Edge case: If the list has 0, 1, or 2 nodes, it is already perfectly ordered.
        if (!head || !head->next || !head->next->next) return;

        // --- STEP 1: Count the Nodes ---
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }

        // --- STEP 2: Find the Middle ---
        // (count - 1) / 2 ensures we land on the exact end of the first half
        int targetSteps = (count - 1) / 2;
        curr = head;
        for (int i = 0; i < targetSteps; i++) {
            curr = curr->next;
        }

        // --- STEP 3: Sever the Tie ---
        ListNode* secondHalf = curr->next; // Save the start of the back half
        curr->next = nullptr;              // Cut the connection!

        // --- STEP 4: Reverse the Second Half ---
        // (This is your exact logic from the Reverse Linked List problem!)
        ListNode* prev = nullptr;
        ListNode* p = secondHalf;
        ListNode* nextNode = nullptr;
        
        while (p) {
            nextNode = p->next;
            p->next = prev;
            prev = p;
            p = nextNode;
        }
        // 'prev' is now the head of our completely detached, reversed second half.

        // --- STEP 5: Weave Them Together ---
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            // Save the next nodes so we don't lose our path
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            // Link the front node to the back node
            first->next = second;
            // Link the back node to the NEXT front node
            second->next = temp1;

            // Move both pointers forward for the next iteration
            first = temp1;
            second = temp2;
        }
    }
};


/*
0    1    2    3    
     6    5    4   



*/