<<<<<<< HEAD
//把左子树继续颠倒，颠倒完后，原来的那个左孩子的左右孩子指针分别指向原来的根节点以及原来的右兄弟节点即可。
=======
//把左子树继续颠倒，颠倒完后，原来的那个左孩子的左右孩子指针分别指向原来的根节点以及原来的右兄弟节点即可。
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
public TreeNode UpsideDownBinaryTree(TreeNode root) {
		if (root == null)
			return null;
		TreeNode parent = root, left = root.left, right = root.right;
		if (left != null) {
			TreeNode ret = UpsideDownBinaryTree(left);
			left.left = right;
			left.right = parent;
			return ret;
		}
		return root;
<<<<<<< HEAD
	}
//直接用迭代代替递归，做起来也不麻烦，并且效率会更高，因为省去了递归所用的栈空间。
=======
	}
//直接用迭代代替递归，做起来也不麻烦，并且效率会更高，因为省去了递归所用的栈空间。
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
public TreeNode UpsideDownBinaryTree(TreeNode root) {
		TreeNode node = root, parent = null, right = null;
		while (node != null) {
			TreeNode left = node.left;
			node.left = right;
			right = node.right;
			node.right = parent;
			parent = node;
			node = left;
		}
		return parent;
<<<<<<< HEAD
	}

//把后续遍历转换成层次遍历。注意由于Java不支持对TreeNode地址传引用，所以这里弄了一个全局变量。另外，类似于对链表的处理，这里我弄了一个dummy node简化对根节点的处理。
=======
	}

//把后续遍历转换成层次遍历。注意由于Java不支持对TreeNode地址传引用，所以这里弄了一个全局变量。另外，类似于对链表的处理，这里我弄了一个dummy node简化对根节点的处理。
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
private TreeNode out = null;
	public TreeNode UpsideDownBinaryTree(TreeNode root) {	
		TreeNode dummy = new TreeNode(0);
		dummy.left = new TreeNode(0);
		out = dummy;
		
		postorder(root);
		return dummy.right;
	}
		
	private void postorder(TreeNode root) {
		if (root == null)
			return;
		
		postorder(root.left);
		postorder(root.right);
		
		if (out.left == null) {
			out.left = root;
			out.left.left = null;
			out.left.right = null;
		} else if (out.right == null) {
			out.right = root;
			out.right.left = null;
			out.right.right = null;
		}
		
		if (out.left != null && out.right != null)
			out = out.right;
	}