<<<<<<< HEAD
// Meeting Rooms II

/// answer = maximum clique = maximum number of intersecting intervals

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    int n = intervals.size(), r = 0;
    vector<int> a, b;
    for (auto &i: intervals) {
      a.push_back(i.start);
      b.push_back(i.end);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int c = 0, i = 0, j = 0; i < n; ) {
      if (a[i] < b[j])
        i++, c++;
      else
        j++, c--;
      r = max(r, c);
    }
    return r;
  }
};

/// answer = chromatic number. graph coloring with greedy algorithm

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y) { return x.start < y.start; });
    priority_queue<int, vector<int>, greater<int>> h;
    for (auto &i: intervals) {
      if (! h.empty() && h.top() <= i.start)
        h.pop();
      h.push(i.end);
    }
    return h.size();
  }
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int n = intervals.size();
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[intervals[i].start]++;
            m[intervals[i].end]--;
        }
        
        int res = 0;
        int cur = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            cur += it->second;
            res = max(res, cur);
        }
        
        return res;
    }
};
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int n = intervals.size();
        vector<pair<int, int>> m;
        for(int i = 0; i < n; i++) {
            m.push_back(make_pair(intervals[i].start, 1));
            m.push_back(make_pair(intervals[i].end, -1));
        }
        sort(m.begin(), m.end());

        int res = 0;
        int cur = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            cur += it->second;
            res = max(res, cur);
        }
        
        return res;
    }
=======
// Meeting Rooms II

/// answer = maximum clique = maximum number of intersecting intervals

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    int n = intervals.size(), r = 0;
    vector<int> a, b;
    for (auto &i: intervals) {
      a.push_back(i.start);
      b.push_back(i.end);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int c = 0, i = 0, j = 0; i < n; ) {
      if (a[i] < b[j])
        i++, c++;
      else
        j++, c--;
      r = max(r, c);
    }
    return r;
  }
};

/// answer = chromatic number. graph coloring with greedy algorithm

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y) { return x.start < y.start; });
    priority_queue<int, vector<int>, greater<int>> h;
    for (auto &i: intervals) {
      if (! h.empty() && h.top() <= i.start)
        h.pop();
      h.push(i.end);
    }
    return h.size();
  }
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int n = intervals.size();
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[intervals[i].start]++;
            m[intervals[i].end]--;
        }
        
        int res = 0;
        int cur = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            cur += it->second;
            res = max(res, cur);
        }
        
        return res;
    }
};
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int n = intervals.size();
        vector<pair<int, int>> m;
        for(int i = 0; i < n; i++) {
            m.push_back(make_pair(intervals[i].start, 1));
            m.push_back(make_pair(intervals[i].end, -1));
        }
        sort(m.begin(), m.end());

        int res = 0;
        int cur = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            cur += it->second;
            res = max(res, cur);
        }
        
        return res;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};