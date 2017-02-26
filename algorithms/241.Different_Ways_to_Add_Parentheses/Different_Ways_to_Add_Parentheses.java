public class Solution {
    public List<Integer> diffWaysToCompute(String input) {
    List<Integer> output = new ArrayList<>();
    for (int i = 0; i < input.length(); i++) {
        char c = input.charAt(i);
        if (c == '+' || c == '-' || c == '*') {
            for (int a : diffWaysToCompute(input.substring(0, i))) {
                for (int b : diffWaysToCompute(input.substring(i + 1))) {
                    output.add(c == '+' ? a + b : c == '-' ? a - b : a * b);
                }
            }
        }
    }

    if (output.size() == 0)
        output.add(Integer.parseInt(input));
    return output;
}
}