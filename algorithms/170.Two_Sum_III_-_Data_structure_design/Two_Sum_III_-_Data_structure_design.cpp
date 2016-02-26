#include <bits/stdc++.h>

using namespace std;
// https://leetcode.com/problems/two-sum-iii-data-structure-design/
class TwoSum {
 public:
  // O(1)
  void add(int number) {
    D[number] += 1;
  }
  // O(D.size())
  bool find(int value) {
    for(auto & kv : D) {
      int v = value - kv.first;
      if(D.count(v)) {
        if(kv.first == v) {
          if(D[v] > 1) {
            return true;
          }
        } else {
          return true;
        }
      }
    }
    return false;
  }
 private:
  unordered_map<int, int> D;
};
public class TwoSum {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    
	public void add(int number) {
	    if(map.containsKey(number)) {
	        map.put(number, map.get(number) + 1);
	    } else {
	        map.put(number, 1);
	    }
	}

	public boolean find(int value) {
	    for(int key : map.keySet()) {
	        int another = value - key;
	        if(another == key && map.get(key) > 1) {
	            return true;
	        } else if(another != key && map.containsKey(another)) {
	            return true;
	        }
	    }
	    return false;
	}
}
int main() {

    return 0;
}

