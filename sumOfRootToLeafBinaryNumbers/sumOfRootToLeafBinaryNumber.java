/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode node, int value) {
        int nextVal = node.val + value*2;
        if (isLeafNode(node)) {
            return nextVal;
        }
        if (node.left == null) {
            return dfs(node.right, nextVal);
        } else if (node.right == null) {
            return dfs(node.left, nextVal);
        } else {
            return dfs(node.right, nextVal) + dfs(node.left, nextVal);
        }
    }

    private boolean isLeafNode(TreeNode node) {
        if (node.left == null && node.right == null) {
            return true;
        }
        return false;
    }
}
