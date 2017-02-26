<<<<<<< HEAD

# Definition for a point
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        max_points = 0
        for i, start in enumerate(points):
            slope_count, same = {}, 1
            for j in xrange(i + 1, len(points)):
                end = points[j]
                if start.x == end.x and start.y == end.y:
                    same += 1
                else:
                    slope = float("inf")
                    if start.x - end.x != 0:
                        slope = (start.y - end.y) * 1.0 / (start.x - end.x)
                    if slope not in slope_count:
                        slope_count[slope] = 1
                    else:
                        slope_count[slope] += 1
            
            current_max = same            
            for slope in slope_count:
                current_max = max(current_max, slope_count[slope] + same)
                
            max_points = max(max_points, current_max)
            
        return max_points

if __name__ == "__main__":
    print Solution().maxPoints([Point(), Point(), Point()])
=======

# Definition for a point
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        max_points = 0
        for i, start in enumerate(points):
            slope_count, same = {}, 1
            for j in xrange(i + 1, len(points)):
                end = points[j]
                if start.x == end.x and start.y == end.y:
                    same += 1
                else:
                    slope = float("inf")
                    if start.x - end.x != 0:
                        slope = (start.y - end.y) * 1.0 / (start.x - end.x)
                    if slope not in slope_count:
                        slope_count[slope] = 1
                    else:
                        slope_count[slope] += 1
            
            current_max = same            
            for slope in slope_count:
                current_max = max(current_max, slope_count[slope] + same)
                
            max_points = max(max_points, current_max)
            
        return max_points

if __name__ == "__main__":
    print Solution().maxPoints([Point(), Point(), Point()])
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
