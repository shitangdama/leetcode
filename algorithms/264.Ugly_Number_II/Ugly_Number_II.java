<<<<<<< HEAD
public class Solution {
    public int nthUglyNumber(int n) {
        if(n<=0) return 0;
        int a=0,b=0,c=0;
        List<Integer> table = new ArrayList<Integer>();
        table.add(1);
        while(table.size()<n)
        {
            int next_val = Math.min(table.get(a)*2,Math.min(table.get(b)*3,table.get(c)*5));
            table.add(next_val);
            if(table.get(a)*2==next_val) a++;
            if(table.get(b)*3==next_val) b++;
            if(table.get(c)*5==next_val) c++;
        }
        return table.get(table.size()-1);
    }
=======
public class Solution {
    public int nthUglyNumber(int n) {
        if(n<=0) return 0;
        int a=0,b=0,c=0;
        List<Integer> table = new ArrayList<Integer>();
        table.add(1);
        while(table.size()<n)
        {
            int next_val = Math.min(table.get(a)*2,Math.min(table.get(b)*3,table.get(c)*5));
            table.add(next_val);
            if(table.get(a)*2==next_val) a++;
            if(table.get(b)*3==next_val) b++;
            if(table.get(c)*5==next_val) c++;
        }
        return table.get(table.size()-1);
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}