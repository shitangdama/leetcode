public class Solution {
  public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int areaA = (C - A) * (D - B);
    int areaB = (G - E) * (H - F);
    long l = Math.max(0L, (long)Math.min(C, G) - Math.max(E, A));
    long h = Math.max(0L, (long)Math.min(D, H) - Math.max(B, F));
    return areaA + areaB - (int)l * (int)h;
  }
}