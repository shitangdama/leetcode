<<<<<<< HEAD
﻿public class Solution {
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
=======
﻿public class Solution {
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
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}