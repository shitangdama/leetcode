public class Solution {
       public String fractionToDecimal(int numerator, int denominator) {
        StringBuilder result = new StringBuilder();
        long n = Math.abs(numerator);
        long d = Math.abs(denominator);
        if (n * d < 0) {
            result.append("-");
        }

        result.append(n / d);
        n %= d;
        if (n != 0) {
            result.append(".");
        }

        int pos = result.length();
        Map<Long, Integer> usedMod = new HashMap<>();
        while (n != 0) {
            if (usedMod.containsKey(n)) {
                break;
            }
            usedMod.put(n, pos);
            n *= 10;
            result.append(n / d);
            n %= d;
            pos++;
        }

        if (n != 0) {
            int insertPos = usedMod.get(n);  
            result.insert(insertPos, '(');  
            result.append(')');  
        }

        return result.toString();
    }
}