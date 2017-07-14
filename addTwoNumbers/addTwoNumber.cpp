/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* startOfList = NULL;
        ListNode* currentNode = NULL;
        ListNode* zeroNode = new ListNode(0);
        
        // Guaranteed that they are non empty lists.
        // While (there is a next digit in the solution || our list is not done)
        while ( (l1->next != NULL || l2->next != NULL || carry == true)||(l1 != zeroNode || l2 != zeroNode)) {
            int sum = l1->val + l2->val + carry;
            if (sum > 9) {
                carry = true;
                sum-=10;
            } else {
                carry = false;
            }
            // Create the new summed node
            ListNode* node = new ListNode(sum);
            
            // Set the start of list if it has not been set yet.
            if (startOfList == NULL) {
                startOfList = node;
            }
            if (currentNode != NULL) {
                currentNode->next = node;
            }
            currentNode = node;
            
            // Change the current nodes we're adding on the list            
            if (l1->next != NULL) {
                l1=l1->next;    
            } else {
                l1=zeroNode;    
            }
            if (l2->next != NULL) {
                l2=l2->next;
            } else {
                l2 = zeroNode;
            }
        }
        
        return startOfList;
    }
    
};