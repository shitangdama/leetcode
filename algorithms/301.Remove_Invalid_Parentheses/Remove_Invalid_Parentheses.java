/*So what we'll try to do is to generate unique combinations using either Iterative(BFS) or recursive(DFS). Two observations can help

    continuous (((+ or )))+ are guaranteed to be duplicate
    if if we define an extra element to identify the position of last removed index, then next BFS, we'll only need to start from there, instead of loop from 0 to str.length. According to combination C(n,k) = C(n-1,k-1) + C(n-1,k)*/

//BFS

public List<String> removeInvalidParentheses(String s) {
    Queue<String> queue = new LinkedList<>();
    Queue<Integer> ends = new LinkedList<>(); //here consider ends is index of last removed element!

    List<String> res = new ArrayList<>();
    int size = 1;
    queue.offer(s);
    ends.add(s.length());

    while (!queue.isEmpty()) {
        String str = queue.poll();
        int end = ends.poll();

        if (isValid(str)) res.add(str);

        //only when not found, we need to consider next level
        if (res.size() > 0) continue;
        for (int i = end - 1; i >= 0; i--) {
            if (str.charAt(i) != '(' && str.charAt(i) != ')') continue;
            String next = (new StringBuilder()).append(str.substring(0, i)).append(str.substring(i + 1)).toString();
            queue.offer(next);
            ends.add(i);

            //skip continuous ')' and '('
            while (i > 0 && str.charAt(i) == str.charAt(i - 1)) i--;
        }

        //check level finish, if not found, go on to next level
        if (--size == 0) {
            if (res.size() > 0) break;
            size = queue.size();
        }
    }

    return res;
}


private boolean isValid(String s) {
    int open = 0;
    for (char c : s.toCharArray()) {
        if (c == '(') open++;
        else if (c == ')') open--;
        if (open < 0) return false;
    }
    return open == 0;
}

//DFS

public List<String> removeInvalidParentheses(String s) {
    List<String> res = new ArrayList<>();
    dfs(res, s, 0, new StringBuilder(), 0);

    return res;
}


private void dfs(List<String> res, String s, int start, StringBuilder path, int open) {
    if (open < 0) return;
    if (!res.isEmpty() && path.length() + s.length() - start < res.get(0).length()) return;
    if (start == s.length()) {
        if (open == 0 && (res.size() == 0 || path.length() == res.get(0).length())) res.add(path.toString());
        return;
    }

    path.append(s.charAt(start));
    if (s.charAt(start) != '(' && s.charAt(start) != ')') dfs(res, s, start + 1, path, open);
    else {
        dfs(res, s, start + 1, path, open + (s.charAt(start) == '(' ? 1 : -1));
        while (start < s.length() - 1 && s.charAt(start) == s.charAt(start + 1)) start++;
    }

    path.deleteCharAt(path.length() - 1);
    dfs(res, s, start + 1, path, open);
}
// Optimized DFS Solution
public class Solution {
    public List<String> removeInvalidParentheses(String s) {
        if (s.length() == 0) return new ArrayList<String>(Arrays.asList(""));
        Map<Integer, List<String>> dics = new HashMap<Integer, List<String>>();
        Set<String> visited = new HashSet<String>();
        int[] min = new int[]{Integer.MAX_VALUE};
        char[] str = s.toCharArray();
        helper(dics, str, 0, "", 0, 0, min, 0, visited);
        return dics.get(min[0]);
    }
    private void helper(Map<Integer, List<String>> dics, char[] str, int start, String cur, 
                        int left, int right, int[] min, int delete, Set<String> visited) {
        // Base Cases
        if (visited.contains(cur + delete)) return;
        visited.add(cur + delete);
        if (start == str.length) {
            if (left != right) return;
            if (!dics.containsKey(delete)) dics.put(delete, new ArrayList<String>());
            dics.get(delete).add(cur);
            min[0] = Math.min(min[0], delete);
            return;
        }
        if (left < right) return;
        if (str[start] == '(') {
            helper(dics, str, start + 1, cur + "(", left + 1, right, min, delete, visited);
            helper(dics, str, start + 1, cur, left, right, min, delete + 1, visited);
        } else if (str[start] == ')') {
            helper(dics, str, start + 1, cur + ")", left, right + 1, min, delete, visited);
            helper(dics, str, start + 1, cur, left, right, min, delete + 1, visited);
        } else {
            helper(dics, str, start + 1, cur + str[start], left, right, min, delete, visited);
        }
    }
}

// DFS 
public class Solution {
    public List<String> removeInvalidParentheses(String s) {
        if (s.length() == 0) return new ArrayList<String>(Arrays.asList(""));
        Map<Integer, Set<String>> dics = new HashMap<Integer, Set<String>>();
        int[] min = new int[]{Integer.MAX_VALUE};
        char[] str = s.toCharArray();
        helper(dics, str, 0, "", 0, 0, min, 0);
        return new ArrayList<String>(dics.get(min[0]));
    }
    private void helper(Map<Integer, Set<String>> dics, char[] str, int start, String cur, 
                        int left, int right, int[] min, int delete) {
        // Base Cases
        if (start == str.length) {
            if (left != right) return;
            if (!dics.containsKey(delete)) dics.put(delete, new HashSet<String>());
            dics.get(delete).add(cur);
            min[0] = Math.min(min[0], delete);
            return;
        }
        if (left < right) return;
        if (str[start] == '(') {
            helper(dics, str, start + 1, cur + "(", left + 1, right, min, delete);
            helper(dics, str, start + 1, cur, left, right, min, delete + 1);
        } else if (str[start] == ')') {
            helper(dics, str, start + 1, cur + ")", left, right + 1, min, delete);
            helper(dics, str, start + 1, cur, left, right, min, delete + 1);
        } else {
            helper(dics, str, start + 1, cur + str[start], left, right, min, delete);
        }
    }
}

// BFS
//idea from @jeantimex, modified and rewrite
public class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> res = new ArrayList<String>();
        if (s == null) return res;
        Queue<String> queue = new LinkedList<String>();
        Set<String> visited = new HashSet<String>();
        queue.add(s);
        boolean reached = false;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String cur = queue.remove();
                // Valid
                if (isValid(cur)) {
                    reached = true;
                    res.add(cur);
                }
                // Not Valid Then Delete 
                if (!reached) {
                    for (int j = 0; j < cur.length(); j++) {
                        if (cur.charAt(j) != '(' && cur.charAt(j) != ')') continue;
                        String newStr = cur.substring(0, j) + cur.substring(j + 1);
                        if (!visited.contains(newStr)) {
                            queue.add(newStr);
                            visited.add(newStr);
                        }
                    }
                }
            }
            if (reached) break;
        }
        return res;
    }
    private boolean isValid(String str) {
        char[] s = str.toCharArray();
        int left = 0;
        for (int i = 0; i < s.length; i++) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') {
                if (left == 0) return false;
                left--;
            }
        }
        return left == 0;
    }
}
// Optimized DFS Solution
public class Solution {
    public List<String> removeInvalidParentheses(String s) {
        if (s.length() == 0) return new ArrayList<String>(Arrays.asList(""));
        Map<Integer, List<String>> dics = new HashMap<Integer, List<String>>();
        Set<String> visited = new HashSet<String>();
        int[] min = new int[]{Integer.MAX_VALUE};
        char[] str = s.toCharArray();
        helper(dics, str, 0, "", 0, 0, min, 0, visited);
        return dics.get(min[0]);
    }
    private void helper(Map<Integer, List<String>> dics, char[] str, int start, String cur, 
                        int left, int right, int[] min, int delete, Set<String> visited) {
        // Base Cases
        if (visited.contains(cur + delete)) return;
        visited.add(cur + delete);
        if (start == str.length) {
            if (left != right) return;
            if (!dics.containsKey(delete)) dics.put(delete, new ArrayList<String>());
            dics.get(delete).add(cur);
            min[0] = Math.min(min[0], delete);
            return;
        }
        if (left < right) return;
        if (str[start] == '(') {
            helper(dics, str, start + 1, cur + "(", left + 1, right, min, delete, visited);
            helper(dics, str, start + 1, cur, left, right, min, delete + 1, visited);
        } else if (str[start] == ')') {
            helper(dics, str, start + 1, cur + ")", left, right + 1, min, delete, visited);
            helper(dics, str, start + 1, cur, left, right, min, delete + 1, visited);
        } else {
            helper(dics, str, start + 1, cur + str[start], left, right, min, delete, visited);
        }
    }
}

// DFS 
public class Solution {
    public List<String> removeInvalidParentheses(String s) {
        if (s.length() == 0) return new ArrayList<String>(Arrays.asList(""));
        Map<Integer, Set<String>> dics = new HashMap<Integer, Set<String>>();
        int[] min = new int[]{Integer.MAX_VALUE};
        char[] str = s.toCharArray();
        helper(dics, str, 0, "", 0, 0, min, 0);
        return new ArrayList<String>(dics.get(min[0]));
    }
    private void helper(Map<Integer, Set<String>> dics, char[] str, int start, String cur, 
                        int left, int right, int[] min, int delete) {
        // Base Cases
        if (start == str.length) {
            if (left != right) return;
            if (!dics.containsKey(delete)) dics.put(delete, new HashSet<String>());
            dics.get(delete).add(cur);
            min[0] = Math.min(min[0], delete);
            return;
        }
        if (left < right) return;
        if (str[start] == '(') {
            helper(dics, str, start + 1, cur + "(", left + 1, right, min, delete);
            helper(dics, str, start + 1, cur, left, right, min, delete + 1);
        } else if (str[start] == ')') {
            helper(dics, str, start + 1, cur + ")", left, right + 1, min, delete);
            helper(dics, str, start + 1, cur, left, right, min, delete + 1);
        } else {
            helper(dics, str, start + 1, cur + str[start], left, right, min, delete);
        }
    }
}

// BFS
//idea from @jeantimex, modified and rewrite
public class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> res = new ArrayList<String>();
        if (s == null) return res;
        Queue<String> queue = new LinkedList<String>();
        Set<String> visited = new HashSet<String>();
        queue.add(s);
        boolean reached = false;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String cur = queue.remove();
                // Valid
                if (isValid(cur)) {
                    reached = true;
                    res.add(cur);
                }
                // Not Valid Then Delete 
                if (!reached) {
                    for (int j = 0; j < cur.length(); j++) {
                        if (cur.charAt(j) != '(' && cur.charAt(j) != ')') continue;
                        String newStr = cur.substring(0, j) + cur.substring(j + 1);
                        if (!visited.contains(newStr)) {
                            queue.add(newStr);
                            visited.add(newStr);
                        }
                    }
                }
            }
            if (reached) break;
        }
        return res;
    }
    private boolean isValid(String str) {
        char[] s = str.toCharArray();
        int left = 0;
        for (int i = 0; i < s.length; i++) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') {
                if (left == 0) return false;
                left--;
            }
        }
        return left == 0;
    }
}
