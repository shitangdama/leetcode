<<<<<<< HEAD
class Solution {

 public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<tuple<int, int, char>> height;
    vector<pair<int, int>> skyline;
    if(buildings.size() == 0) return skyline;
    for(auto & building : buildings) {
      height.push_back(make_tuple(building[0], building[2], 'l'));
      height.push_back(make_tuple(building[1], building[2], 'r'));
    }
    sort(height.begin(), height.end(), [](tuple<int, int, char> a, tuple<int, int, char> b) {
          int v1 = get<0>(a), v2 = get<0>(b), h1 = get<1>(a), h2 = get<1>(b);
          char ch1 = get<2>(a), ch2 = get<2>(b);
          if(v1 != v2) return v1 < v2;
          else if(ch1 == 'l' && ch2 == 'l') return h1 > h2;
          else if(ch1 == 'r' && ch2 == 'r') return h1 < h2;
          else return ch1 == 'l';
         });
    priority_queue<int> H;
    H.push(0);
    unordered_map<int, int> M;
    int prev = 0, curr = 0;
    for(auto & tpl : height) {
      int v = get<0>(tpl), h = get<1>(tpl);
      char ch = get<2>(tpl);
      if(ch == 'l') {
        H.push(h);
      } else {
        M[h] ++;
        while(!H.empty() && M[H.top()] > 0) {
            M[H.top()] -= 1;
            H.pop();
          }
      }
      curr = H.top();
      if(curr != prev) {
        // inflection point
        skyline.push_back(make_pair(v, curr));
        prev = curr;
      }
    }
    return skyline;
  }
=======
class Solution {

 public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<tuple<int, int, char>> height;
    vector<pair<int, int>> skyline;
    if(buildings.size() == 0) return skyline;
    for(auto & building : buildings) {
      height.push_back(make_tuple(building[0], building[2], 'l'));
      height.push_back(make_tuple(building[1], building[2], 'r'));
    }
    sort(height.begin(), height.end(), [](tuple<int, int, char> a, tuple<int, int, char> b) {
          int v1 = get<0>(a), v2 = get<0>(b), h1 = get<1>(a), h2 = get<1>(b);
          char ch1 = get<2>(a), ch2 = get<2>(b);
          if(v1 != v2) return v1 < v2;
          else if(ch1 == 'l' && ch2 == 'l') return h1 > h2;
          else if(ch1 == 'r' && ch2 == 'r') return h1 < h2;
          else return ch1 == 'l';
         });
    priority_queue<int> H;
    H.push(0);
    unordered_map<int, int> M;
    int prev = 0, curr = 0;
    for(auto & tpl : height) {
      int v = get<0>(tpl), h = get<1>(tpl);
      char ch = get<2>(tpl);
      if(ch == 'l') {
        H.push(h);
      } else {
        M[h] ++;
        while(!H.empty() && M[H.top()] > 0) {
            M[H.top()] -= 1;
            H.pop();
          }
      }
      curr = H.top();
      if(curr != prev) {
        // inflection point
        skyline.push_back(make_pair(v, curr));
        prev = curr;
      }
    }
    return skyline;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};