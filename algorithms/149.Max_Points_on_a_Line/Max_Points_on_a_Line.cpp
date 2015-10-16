#include <bits/stdc++.h>


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		unordered_map<float,int> mp;
		int maxNum = 0;
		for(int i = 0; i < points.size(); i++)
		{
			mp.clear();
			mp[INT_MIN] = 0;
			int duplicate = 1;
			for(int j = 0; j < points.size(); j++)
			{
				if(j == i) continue;
				if(points[i].x == points[j].x && points[i].y == points[j].y)
				{
					duplicate++;
					continue;
				}
				float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
				mp[k]++;
			}
			unordered_map<float, int>::iterator it = mp.begin();
			for(; it != mp.end(); it++)
				if(it->second + duplicate > maxNum)
					maxNum = it->second + duplicate;
		}
		return maxNum;
    }
};
// LeetCode, Max Points on a Line
// 暴力枚举，以点为中心，时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 3) return points.size();
        int result = 0;

        unordered_map<double, int> slope_count;
        for (int i = 0; i < points.size()-1; i++) {
            slope_count.clear();
            int samePointNum = 0; // 与i重合的点
            int point_max = 1;    // 和i共线的最大点数

            for (int j = i + 1; j < points.size(); j++) {
                double slope; // 斜率
                if (points[i].x == points[j].x) {
                    slope = std::numeric_limits<double>::infinity();
                    if (points[i].y == points[j].y) {
                        ++ samePointNum;
                        continue;
                    }
                } else {
                    slope = 1.0 * (points[i].y - points[j].y) / 
                        (points[i].x - points[j].x);
                }

                int count = 0;
                if (slope_count.find(slope) != slope_count.end())
                    count = ++slope_count[slope];
                else {
                    count = 2;
                    slope_count[slope] = 2;
                }

                if (point_max < count) point_max = count;
            }
            result = max(result, point_max + samePointNum);
        }
        return result;
    }
};
int main() {
    return 0;
}

