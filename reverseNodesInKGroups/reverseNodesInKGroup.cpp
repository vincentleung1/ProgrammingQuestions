/**
 * https://leetcode.com/problems/reverse-nodes-in-k-group/#/description
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL; // handle empty list

        ListNode* newStart = NULL;

        // Count the number of nodes in the list. O(n) computation
        int numNodes = 1;
        ListNode* temp = head;
        while(temp->next != NULL) {
            numNodes++;
            temp = temp->next;
        }

        // Check if we can reverse any part or need to reverse any.
        if (numNodes < k || k < 2) {
            return head;
        }

        // For each section...
        for(int i = 0; i < (numNodes/k); i++) { // floor of numNodes/k
            if ( i == 0 ) {
                // For the first section, reverse the section and set the
                // new starting point as the previous end.
                newStart = swapSection(head, k);
            } else {
                // Get the k*i'th node and set it to the new start of the
                // next section
                ListNode* kthNode = getKthNode(newStart, k*i);
                kthNode->next = swapSection(kthNode->next, k);
            }
        }
        return newStart;
    }

    // returns the new start node after swapping
    ListNode* swapSection(ListNode* start, int k) {
        // Get the k'th node
        ListNode* newStart = getKthNode(start,k);
        // Save the original end's next nodes.
        ListNode* endNext = newStart->next;

        // o -- o -- o
        // c -- n -- t, where c = current, n = next, t = temp.
        ListNode* current = start;
        ListNode* next = current->next;
        ListNode* temp = next->next;
        // Start reversing the pointers. O(k)
        for (int i = 0; i < k - 1; i++) {
            next->next = current;
            current = next;
            next = temp;
            if (temp != NULL)
                temp = temp->next;
        }
        start->next = endNext;

        return newStart;
    }

    // O(k)
    ListNode* getKthNode(ListNode* start, int k) {
        for ( int i = 0; i < k-1; i++) {
            start = start->next;
        }
        return start;
    }
};
