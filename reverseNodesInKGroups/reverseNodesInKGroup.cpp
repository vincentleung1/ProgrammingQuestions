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

        if (numNodes < k || k == 1) {
            return head;
        }

        for(int i = 0; i < (numNodes/k); i++) { // floor of numNodes
            if ( i == 0 ) {
                newStart = swapSection(head, k);
            } else {
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
        ListNode* endNext = newStart->next;

        for (int i = k; i > 1; i--) {
            getKthNode(start,i)->next = getKthNode(start,i-1);
        }
        start->next = endNext;

        return newStart;
    }

    ListNode* getKthNode(ListNode* start, int k) {
        for ( int i = 0; i < k-1; i++) {
            start = start->next;
        }
        return start;
    }
};
