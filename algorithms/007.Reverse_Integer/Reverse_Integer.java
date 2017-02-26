<<<<<<< HEAD
public class Solution {
    public int reverse(int x) {
        int rst = 0;
        
        while(x != 0) {
            int next_rst = rst * 10 + x % 10;
            x = x / 10;
            if(next_rst/10 != rst) {
                rst  = 0;
                break;
            }
            rst = next_rst;
        }
        return rst;
    }
=======
public class Solution {
    public int reverse(int x) {
        int rst = 0;
        
        while(x != 0) {
            int next_rst = rst * 10 + x % 10;
            x = x / 10;
            if(next_rst/10 != rst) {
                rst  = 0;
                break;
            }
            rst = next_rst;
        }
        return rst;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}