package leecode.twosumIII;

import java.util.HashMap;
import java.util.Map;

public class Solution {
	 private Map<Integer,Integer> elements=new HashMap<>();  
     public void add(int number) {  
       if(elements.containsKey(number))  
       {  
         elements.put(number,elements.get(number)+1);  
       }  
       else  
       {  
         elements.put(number,1);  
       }  
     }  
     public boolean find(int value) {  
       for(Integer i:elements.keySet())  
       {  
         int needed=value-i;  
         if(elements.containsKey(needed))  
         {  
           if(i==needed&&elements.get(needed)<2)  
           {  
             continue;  
           }  
           return true;  
         }  
       }  
       return false;  
     }  
}
public class TwoSumIIIDataStructureDesign {
  // special case: [add(3),add(2),add(1),find(2),find(3),find(4),find(5),find(6)]
  // 2-1 = 1
  Map<Integer,Integer> hm = new HashMap<Integer,Integer>();

  public void add(int number) {  
    hm.put(number, hm.containsKey(number) ? (hm.get(number)+1) : 1);
  }

  public boolean find(int value) {
    for (Map.Entry<Integer,Integer> entry : hm.entrySet()) {
      int a = entry.getKey();
      int b = value - a;
      if ( (a!=b && hm.containsKey(b)) || (a==b && entry.getValue()>1) ) { // 1) 5-4=1, 4!=1 2) 2-1=1, 1=1, hm.get(1)=2 
        return true;
      }
    }
    return false;
  }
}