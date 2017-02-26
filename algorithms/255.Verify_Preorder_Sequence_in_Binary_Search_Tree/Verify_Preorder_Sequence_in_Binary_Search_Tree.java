<<<<<<< HEAD
public class Solution {
    public boolean verifyPreorder(int[] preorder) {
        if (preorder == null || preorder.length < 3) {
            return true;
        }

        Stack<Integer> stack = new Stack<>();
        List<Integer> list = new ArrayList<>();

        for (int i : preorder) {
            if (!list.isEmpty() && i < list.get(list.size() - 1)) {
                return false;
            }

            while (!stack.isEmpty() && i > stack.peek()) {
                list.add(stack.pop());
            }
            stack.add(i);
        }

        return true;
    }
=======
public class Solution {
    public boolean verifyPreorder(int[] preorder) {
        if (preorder == null || preorder.length < 3) {
            return true;
        }

        Stack<Integer> stack = new Stack<>();
        List<Integer> list = new ArrayList<>();

        for (int i : preorder) {
            if (!list.isEmpty() && i < list.get(list.size() - 1)) {
                return false;
            }

            while (!stack.isEmpty() && i > stack.peek()) {
                list.add(stack.pop());
            }
            stack.add(i);
        }

        return true;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}