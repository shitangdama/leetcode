public class MyStack {

    // 维持两个队列，其中总有一个队列为空，为pop和top操作准备
    private List<Integer> aList = new LinkedList<>();
    private List<Integer> bList = new LinkedList<>();


    // Push element x onto stack.
    public void push(int x) {
        // 如果aList非空，就将x添加到aList中
        if (!aList.isEmpty()) {
            aList.add(x);
        }
        // 否则总添加到bList中
        else {
            bList.add(x);
        }
    }

    // Removes the element on top of the stack.
    public void pop() {

        // 两个队列中至少有一个为空，将aList设置非空
        if (aList.isEmpty()) {
            List<Integer> tmp = bList;
            bList = aList;
            aList = tmp;
        }

        // 除最后一个元素外都转移到bList中
        while (aList.size() > 1) {
            bList.add(aList.remove(0));
        }

        // 删除最后一个元素（对应就是入栈的栈顶元素）
        aList.clear();
    }

    // Get the top element.
    public int top() {

        // 两个队列中至少有一个为空，将aList设置非空
        if (aList.isEmpty()) {
            List<Integer> tmp = bList;
            bList = aList;
            aList = tmp;
        }

        // 除最后一个元素外都转移到bList中
        while (aList.size() > 1) {
            bList.add(aList.remove(0));
        }

        bList.add(aList.get(0));
        return aList.remove(0);
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return aList.isEmpty() && bList.isEmpty();
    }
}