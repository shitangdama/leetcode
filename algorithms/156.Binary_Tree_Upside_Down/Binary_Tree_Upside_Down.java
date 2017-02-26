//�������������ߵ����ߵ����ԭ�����Ǹ����ӵ����Һ���ָ��ֱ�ָ��ԭ���ĸ��ڵ��Լ�ԭ�������ֵܽڵ㼴�ɡ�
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
	}
//ֱ���õ�������ݹ飬������Ҳ���鷳������Ч�ʻ���ߣ���Ϊʡȥ�˵ݹ����õ�ջ�ռ䡣
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
	}

//�Ѻ�������ת���ɲ�α�����ע������Java��֧�ֶ�TreeNode��ַ�����ã���������Ū��һ��ȫ�ֱ��������⣬�����ڶ�����Ĵ���������Ū��һ��dummy node�򻯶Ը��ڵ�Ĵ���
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