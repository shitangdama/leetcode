public class Solution {
    public TreeNode invertTree(TreeNode root) {

        if (root != null) {
            invertTreeNode(root);
        }
        return root;
    }

    public void invertTreeNode(TreeNode root) {

        if (root != null) {
            TreeNode tmp = root.left;
            root.left = root.right;
            root.right = tmp;

            invertTree(root.left);
            invertTree(root.right);
        }
    }
}