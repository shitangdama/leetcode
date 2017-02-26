<<<<<<< HEAD
public class Solution {
    private void dfs(HashMap<Integer, Integer> depthToValue, TreeNode node, int depth) {
        if (node == null) {
            return;
        }
        
        depthToValue.put(depth, node.val);
        dfs(depthToValue, node.left, depth + 1);
        dfs(depthToValue, node.right, depth + 1);
    }
    
    public List<Integer> rightSideView(TreeNode root) {
        HashMap<Integer, Integer> depthToValue = new HashMap<Integer, Integer>();
        dfs(depthToValue, root, 1);
        
        int depth = 1;
        List<Integer> result = new ArrayList<Integer>();
        while (depthToValue.containsKey(depth)) {
            result.add(depthToValue.get(depth));
            depth++;
        }
        return result;
    }
}
=======
public class Solution {
    private void dfs(HashMap<Integer, Integer> depthToValue, TreeNode node, int depth) {
        if (node == null) {
            return;
        }
        
        depthToValue.put(depth, node.val);
        dfs(depthToValue, node.left, depth + 1);
        dfs(depthToValue, node.right, depth + 1);
    }
    
    public List<Integer> rightSideView(TreeNode root) {
        HashMap<Integer, Integer> depthToValue = new HashMap<Integer, Integer>();
        dfs(depthToValue, root, 1);
        
        int depth = 1;
        List<Integer> result = new ArrayList<Integer>();
        while (depthToValue.containsKey(depth)) {
            result.add(depthToValue.get(depth));
            depth++;
        }
        return result;
    }
}
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
