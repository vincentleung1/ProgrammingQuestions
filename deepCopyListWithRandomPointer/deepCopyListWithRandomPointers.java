/**
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) {
            return null;
        }
        
        Map<Integer, RandomListNode> nodeHolder = new HashMap<Integer, RandomListNode>();
        
        // This is the start node
        RandomListNode startNode = new RandomListNode(head.label);
        nodeHolder.put(head.label, startNode);
        RandomListNode currentNode = startNode;
        
        while (head != null) {
            // Handle the random node
            if (head.random == null) {
                currentNode.random = null;
            } else {
                // Create/get the random node
                RandomListNode randomNode = nodeHolder.get(head.random.label);
                if (randomNode == null) {
                    randomNode = new RandomListNode(head.random.label);
                    nodeHolder.put(randomNode.label, randomNode);
                } 
                
                // Assign the random node
                currentNode.random = randomNode;
            }

            // Now deal with the next node.
            if (head.next == null) {
                currentNode.next = null;
            } else {
                // Create/get the next node
                RandomListNode nextNode = nodeHolder.get(head.next.label);
                if (nextNode == null) {
                    nextNode = new RandomListNode(head.next.label);
                    nodeHolder.put(nextNode.label, nextNode);
                } 
                currentNode.next = nextNode;
            }
            head = head.next;
            currentNode = currentNode.next;
        }
        return startNode;
    }
}