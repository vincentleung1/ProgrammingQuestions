/**
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 *
 *  Runtime of solution: O(n*lg(n)), where n is the number of nodes.
 *  It runs n for the number of nodes, and for each node, there is a lg(n) 
 *  lookup time in the hash table for insertions.
 */
 class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if (head == NULL){
            return NULL;
        }
        
        // Assign the newly created head to have the same value as head.
        RandomListNode *newHead = new RandomListNode(head->label);
        RandomListNode *startHolder = newHead;
        
        // Storage for node pointers
        unordered_map<int, RandomListNode*> newListHolder;
        
        // Store the address
        newListHolder[newHead->label] = newHead;
        
        while (head != NULL) {
            // Deal with the next node
            if ( head->next == NULL) {
                newHead->next = NULL;
            } else if (newListHolder.count(head->next->label) > 0) { 
                newHead->next = newListHolder[head->next->label];
            } else {
                RandomListNode *newNextNode = new RandomListNode(head->next->label);
                newListHolder[newNextNode->label] = newNextNode;
                newHead->next = newNextNode;
            }
            
            // Deal with the random node
            if (head->random == NULL){
                newHead->random = NULL;
            }
            
            else if (newListHolder.count(head->random->label) > 0) { 
                newHead->random = newListHolder[head->random->label];
            } else {
                RandomListNode *newRandomNode = new RandomListNode(head->random->label);
                newListHolder[newRandomNode->label] = newRandomNode;
                newHead->random = newRandomNode;
            }
            
            // Now set heads to next.
            newHead = newHead->next;
            head = head->next;
        }
        return startHolder;
    }
};