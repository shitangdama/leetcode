
public class Solution {
  private class Line {
    int pos, height;
    boolean end;
    Line (int pos, int height, boolean end) {
      this.pos = pos;
      this.height = height;
      this.end = end;
    }
  }

  public List<int[]> getSkyline(int[][] buildings) {
    List<int[]> ans = new ArrayList<>();
    if (buildings == null || buildings.length == 0 || buildings[0].length == 0) {
      return ans;
    }
    Queue<Line> lines = new PriorityQueue<>(buildings.length * 2, lineCmp);
    Queue<Integer> heights = new PriorityQueue<>(buildings.length * 2, maxCmp);
    for (int[] building : buildings) {
      lines.offer(new Line(building[0], building[2], false));
      lines.offer(new Line(building[1], building[2], true));
    }

    while (!lines.isEmpty()) {
      Line cur = lines.poll();
      if (!cur.end) {
        if (heights.isEmpty() || cur.height > heights.peek()) {
          ans.add(new int[]{cur.pos, cur.height});
        }

        heights.offer(cur.height);
      } else {
        if (cur.height == heights.peek()) {
          heights.poll();
          if (heights.isEmpty()) {
            ans.add(new int[]{cur.pos, 0});
          } else {
            if (cur.height > heights.peek()) {
              ans.add(new int[]{cur.pos, heights.peek()});
            }
          }
        }else{
          heights.remove(cur.height);
        }
      }
    }

    return ans;
  }

  private Comparator<Line> lineCmp = new Comparator<Line>() {
    @Override
    public int compare(Line l1, Line l2) {
      if (l1.pos != l2.pos) {
        return l1.pos - l2.pos;
      }
      if (l1.end && l2.end) {
        return compareHeight(l1.height, l2.height);
      }
      if (!l1.end && !l2.end) {
        return compareHeight(l2.height, l1.height);
      }
      return l1.end? 1: -1;
    }
  };

  private Comparator<Integer> maxCmp = new Comparator<Integer>(){
    @Override
    public int compare(Integer a, Integer b) {
      return b - a;
    }
  };

  private int compareHeight(int a, int b) {
    return a - b;
  }
}