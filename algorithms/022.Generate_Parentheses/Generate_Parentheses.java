public class Solution {
    public ArrayList<String> generateParenthesis(int n) {
        ArrayList<String> rst = new ArrayList<String>();
        if(n <= 0) {
            return rst;
        }
        getPair(rst, "", n, n);
        return rst;
    }
    
	public void getPair( ArrayList<String> rst , String s, int left, int right) {
		if(left > right || left < 0 || right < 0) {
			return; 	
		}
		if(left == 0 && right == 0) {
			rst.add(s);
			return;
		}

		getPair(rst, s + "(", left - 1, right);
		getPair(rst, s + ")", left, right - 1);
	}
}