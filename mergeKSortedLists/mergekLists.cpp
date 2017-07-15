/**
 * https://leetcode.com/problems/merge-k-sorted-lists/#/description
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // The function assumes no empty lists, so remove all empty lists.
        for (int i = lists.size() - 1; i >= 0 ; i--) {
            if(lists[i] == NULL) {
                lists.erase(lists.begin() + i);
            }
        }

        ListNode* start = NULL;
        ListNode* current = NULL;

        while(!lists.empty()){
            int min = INT_MAX;
            int minIndex;
            for(int i = 0; i < lists.size(); i++) {
                if (lists[i]->val < min) {
                    min = lists[i]->val;
                    minIndex = i;
                }
            }
            ListNode* newHead;
            if (current == NULL) {
                start = lists[minIndex];
                current = start;
                newHead = lists[minIndex]->next;
            } else {
                newHead = addHeadToNode(lists[minIndex], current);
                current = current->next;
            }

            if (newHead != NULL) {
                lists[minIndex] = newHead;
            } else {
                lists.erase(lists.begin()+minIndex);
            }
        }
        return start;
    }

    /*
    Takes the head of a list, removes it from the list and returns the new head.
    */
    ListNode* addHeadToNode ( ListNode* head, ListNode* node){
        node->next = head;
        ListNode* next = head->next;
        head->next = NULL;
        return next;
    }
};
