/**
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Init new list and carry
        int carry = 0;
        ListNode startOfList = null;
        ListNode currentNode = null;
        
        // Use this node if there is no more next nodes for 1 number.
        ListNode zeroNode = new ListNode(0);
        
        // When we reach the end of the "number" list, it is set to the zero node.
        // If both are zero nodes and the carry is 0, we are done.
        while( l1 != zeroNode || l2 != zeroNode || carry > 0 ) {
            int sum = l1.val + l2.val + carry;
            if (sum > 9){
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            
            // Create the new node for the new list with the sum
            ListNode node = new ListNode(sum);
            
            // If we haven't set the start node yet, set it as 
            // the node that we just created.
            if ( startOfList == null ) {
                startOfList = node;
            }
            if ( currentNode != null ) {
                currentNode.next = node;
            }
            currentNode = node;
            
            if ( l1.next != null ) {
                l1 = l1.next;
            } else {
                l1 = zeroNode;
            }
            
            if ( l2.next != null ) {
                l2 = l2.next;
            } else { 
                l2 = zeroNode;
            }
        }
        return startOfList;
    }
}