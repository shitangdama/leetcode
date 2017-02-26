<<<<<<< HEAD
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || (root.val >= Math.min(p.val,q.val) && root.val <= Math.max(p.val,q.val))) {
            return root;
        }
        if (root.val > Math.max(p.val,q.val)) {
            return lowestCommonAncestor(root.left,p,q);
        } else {
            return lowestCommonAncestor(root.right,p,q);
        }
    }

=======
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || (root.val >= Math.min(p.val,q.val) && root.val <= Math.max(p.val,q.val))) {
            return root;
        }
        if (root.val > Math.max(p.val,q.val)) {
            return lowestCommonAncestor(root.left,p,q);
        } else {
            return lowestCommonAncestor(root.right,p,q);
        }
    }

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
