<<<<<<< HEAD

public class Solution {
    public  int maxPoints(Point[] points) {
        if (points == null || points.length == 0) {
            return 0;
        }  

        HashMap<Double, Integer> map=new HashMap<Double, Integer>();
        int max = 1;

        for(int i = 0 ; i < points.length; i++) {
            // shared point changed, map should be cleared and server the new point
            map.clear();

            // maybe all points contained in the list are same points,and same points' k is 
            // represented by Integer.MIN_VALUE
            map.put((double)Integer.MIN_VALUE, 1);

            int dup = 0;
            for(int j = i + 1; j < points.length; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    dup++;
                    continue;
                }

                // look 0.0+(double)(points[j].y-points[i].y)/(double)(points[j].x-points[i].x)
                // because (double)0/-1 is -0.0, so we should use 0.0+-0.0=0.0 to solve 0.0 !=-0.0
                // problem

                // if the line through two points are parallel to y coordinator, then K(slop) is 
                // Integer.MAX_VALUE
                double key=points[j].x - points[i].x == 0 ? 
                    Integer.MAX_VALUE :
                    0.0 + (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);

                if (map.containsKey(key)) {
                    map.put(key, map.get(key) + 1);
                } else {
                    map.put(key, 2);
                }
            }

            for (int temp: map.values()) {
                // duplicate may exist
                if (temp + dup > max) {
                    max = temp + dup;
                }
            }

        }
        return max;
    }
}


// version 2:
/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
class Line {
    public double a, b, c;
    public Line(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    
    public Line(int x1, int y1, int x2, int y2) {
        if (x1 == x2) {
            if (x1 == 0) {
                a = 1;
                b = 0;
                c = 0;
            } else {
                a = 1.0 / x1;
                b = 0;
                c = 1;
            }
        } else if (y1 == y2) {
            if (y1 == 0) {
                a = 0;
                b = 1;
                c = 0;
            } else {
                a = 0;
                b = 1.0 / y1;
                c = 1;
            }
        } else {
            if (x1 * y2 == x2 * y1) {
                a = 1;
                b = - 1.0 * (y1 - y2) / (x1 - x2);
                c = 0;
           } else {
                a = 1.0 * (y1 - y2) / (x2 * y1 - x1 * y2);
                b = 1.0 * (x1 - x2) / (x1 * y2 - x2 * y1);
                c = 1;
            }
        }
    }
    
    public String toString() {
        return Double.toString(a) + " " + Double.toString(b) + " " + Double.toString(c);
    }
}

public class Solution {
    
    public int maxPoints(Point[] points) {
        if (points.length < 2) {
            return points.length;
        }
        
        HashMap<String, Integer> hash = new HashMap<String, Integer>();
        for (int i = 0; i < points.length; i++) {
            for (int j = i + 1; j < points.length; j++) {
                Line line = new Line(points[i].x, points[i].y,
                                     points[j].x, points[j].y);
                String key = line.toString();
                if (hash.containsKey(key)) {
                    hash.put(key, hash.get(key) + 1);
                } else {
                    hash.put(key, 1);
                }
            }
        }
        
        int max = 0;
        String maxKey = "";
        for (String key: hash.keySet()) {
            if (hash.get(key) > max) {
                max = hash.get(key);
                maxKey = key;
                
            }
        }
        String[] params = maxKey.split(" ");
        double a = Double.parseDouble(params[0]);
        double b = Double.parseDouble(params[1]);
        double c = Double.parseDouble(params[2]);
        
        int count = 0;
        for (int i = 0; i < points.length; i++) {
            if (Math.abs(a * points[i].x + b * points[i].y - c) < 1e-6) {
                count++;
            }
        }
        return count;
    }
=======

public class Solution {
    public  int maxPoints(Point[] points) {
        if (points == null || points.length == 0) {
            return 0;
        }  

        HashMap<Double, Integer> map=new HashMap<Double, Integer>();
        int max = 1;

        for(int i = 0 ; i < points.length; i++) {
            // shared point changed, map should be cleared and server the new point
            map.clear();

            // maybe all points contained in the list are same points,and same points' k is 
            // represented by Integer.MIN_VALUE
            map.put((double)Integer.MIN_VALUE, 1);

            int dup = 0;
            for(int j = i + 1; j < points.length; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    dup++;
                    continue;
                }

                // look 0.0+(double)(points[j].y-points[i].y)/(double)(points[j].x-points[i].x)
                // because (double)0/-1 is -0.0, so we should use 0.0+-0.0=0.0 to solve 0.0 !=-0.0
                // problem

                // if the line through two points are parallel to y coordinator, then K(slop) is 
                // Integer.MAX_VALUE
                double key=points[j].x - points[i].x == 0 ? 
                    Integer.MAX_VALUE :
                    0.0 + (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);

                if (map.containsKey(key)) {
                    map.put(key, map.get(key) + 1);
                } else {
                    map.put(key, 2);
                }
            }

            for (int temp: map.values()) {
                // duplicate may exist
                if (temp + dup > max) {
                    max = temp + dup;
                }
            }

        }
        return max;
    }
}


// version 2:
/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
class Line {
    public double a, b, c;
    public Line(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    
    public Line(int x1, int y1, int x2, int y2) {
        if (x1 == x2) {
            if (x1 == 0) {
                a = 1;
                b = 0;
                c = 0;
            } else {
                a = 1.0 / x1;
                b = 0;
                c = 1;
            }
        } else if (y1 == y2) {
            if (y1 == 0) {
                a = 0;
                b = 1;
                c = 0;
            } else {
                a = 0;
                b = 1.0 / y1;
                c = 1;
            }
        } else {
            if (x1 * y2 == x2 * y1) {
                a = 1;
                b = - 1.0 * (y1 - y2) / (x1 - x2);
                c = 0;
           } else {
                a = 1.0 * (y1 - y2) / (x2 * y1 - x1 * y2);
                b = 1.0 * (x1 - x2) / (x1 * y2 - x2 * y1);
                c = 1;
            }
        }
    }
    
    public String toString() {
        return Double.toString(a) + " " + Double.toString(b) + " " + Double.toString(c);
    }
}

public class Solution {
    
    public int maxPoints(Point[] points) {
        if (points.length < 2) {
            return points.length;
        }
        
        HashMap<String, Integer> hash = new HashMap<String, Integer>();
        for (int i = 0; i < points.length; i++) {
            for (int j = i + 1; j < points.length; j++) {
                Line line = new Line(points[i].x, points[i].y,
                                     points[j].x, points[j].y);
                String key = line.toString();
                if (hash.containsKey(key)) {
                    hash.put(key, hash.get(key) + 1);
                } else {
                    hash.put(key, 1);
                }
            }
        }
        
        int max = 0;
        String maxKey = "";
        for (String key: hash.keySet()) {
            if (hash.get(key) > max) {
                max = hash.get(key);
                maxKey = key;
                
            }
        }
        String[] params = maxKey.split(" ");
        double a = Double.parseDouble(params[0]);
        double b = Double.parseDouble(params[1]);
        double c = Double.parseDouble(params[2]);
        
        int count = 0;
        for (int i = 0; i < points.length; i++) {
            if (Math.abs(a * points[i].x + b * points[i].y - c) < 1e-6) {
                count++;
            }
        }
        return count;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}