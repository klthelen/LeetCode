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
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Initialize new list, new head node, new pointer for next node
        ListNode *head = nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = nullptr;
        int carryOver = 0;
        
        // While there are numbers in both lists
        while ((l1 != nullptr) && (l2 != nullptr)) {
            // Create a new node, adding each digit and any carry over value from the previous addition
            ListNode temp = ListNode(l1->val + l2->val + carryOver);
            carryOver = 0;
            
            // If the addition results in a number > 9, carry over the 1 for the next addition
            if (temp.val > 9) {
                temp.val = temp.val % 10;
                carryOver = 1;
            }
            
            curr = new ListNode(temp.val);
            
            if (head == nullptr) {
                head = curr;
                prev = head;
            }
            else {
                prev->next = curr;
                prev = curr; 
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        // At this point, at least one list is empty
        // We fill in the number with whatever is left from the remaining list, accounting for carryover
        while (l1 != nullptr) {
            ListNode temp = ListNode(l1->val + carryOver);
            carryOver = 0;
            
            // If the addition results in a number > 9, carry over the 1 for the next addition
            if (temp.val > 9) {
                temp.val = temp.val % 10;
                carryOver = 1;
            }
            
            // Don't need to account for head being nullptr at this point because our problem states that both lists start as non-empty
            curr = new ListNode(temp.val);
            prev->next = curr;
            prev = curr; 
            
            l1 = l1->next;
        }
        
        
        while (l2 != nullptr) {
            ListNode temp = ListNode(l2->val + carryOver);
            carryOver = 0;
            
            // If the addition results in a number > 9, carry over the 1 for the next addition
            if (temp.val > 9) {
                temp.val = temp.val % 10;
                carryOver = 1;
            }
            
            
            // Don't need to account for head being nullptr at this point because our problem states that both lists start as non-empty
            curr = new ListNode(temp.val);
            prev->next = curr;
            prev = curr; 
            
            l2 = l2->next;
        }
        
        // If both lists are empty but there is still a carry over value
        if (carryOver > 0) {
            ListNode temp = ListNode(carryOver);
            carryOver = 0;
            curr = new ListNode(temp.val);
            
            // Don't need to account for head being nullptr at this point because our problem states that both lists start as non-empty
            prev->next = curr;
            prev = curr; 
        }
        
        return head;
    }
};