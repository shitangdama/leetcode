<<<<<<< HEAD
import java.util.Stack;

public class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) {val = x;}
}

public class BSTIterator {

	Stack<TreeNode> st;
	
    public BSTIterator(TreeNode root) {
    	st = new Stack<TreeNode>();
    	pushAllNodes(root);
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return (!st.isEmpty());
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode smallest = st.pop();
        pushAllNodes(smallest.right);
        return smallest.val;
    }
    
    public void pushAllNodes(TreeNode node) {
    	while (node!=null) {
    		st.push(node);
    		node = node.left;
    	}
    }
=======
import java.util.Stack;

public class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) {val = x;}
}

public class BSTIterator {

	Stack<TreeNode> st;
	
    public BSTIterator(TreeNode root) {
    	st = new Stack<TreeNode>();
    	pushAllNodes(root);
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return (!st.isEmpty());
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode smallest = st.pop();
        pushAllNodes(smallest.right);
        return smallest.val;
    }
    
    public void pushAllNodes(TreeNode node) {
    	while (node!=null) {
    		st.push(node);
    		node = node.left;
    	}
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}