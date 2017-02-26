public class KthLargestElement {
    public int findKthLargest(int[] nums, int k) {
        return findKthLargest(nums, k, 0, nums.length);
    }

    private int findKthLargest(int[] nums, int k, int start, int end) {
    	if (end - start < 2) return nums[start];
    	int mid = nums[end - 1];
    	int index = start - 1;
    	for (int i = start; i < end - 1; i++) {
    		if (nums[i] >= mid) {
    			exchange(nums, i, index + 1);
    			index++;
    		}
    	}
    	exchange(nums, index + 1, end - 1);
    	if (index + 1 == k - 1) {
    		return mid;
    	} else if (index + 1 < k - 1) {
    		 return findKthLargest(nums, k, index + 2, end);
    	} else {
    		return findKthLargest(nums, k, start, index + 1);
    	}
    }

    private void exchange(int[] nums, int i, int j) {
    	int temp = nums[i];
    	nums[i] = nums[j];
    	nums[j] = temp;
    }
}
public class Solution {

  public int findKthLargest(int[] a, int k) {
    int n = a.length;
    int p = quickSelect(a, 0, n - 1, n - k + 1);
    return a[p];
  }

  // return the index of the kth smallest number
  int quickSelect(int[] a, int lo, int hi, int k) {
    // use quick sort's idea
    // put nums that are <= pivot to the left
    // put nums that are  > pivot to the right
    int i = lo, j = hi, pivot = a[hi];
    while (i < j) {
      if (a[i++] > pivot) swap(a, --i, --j);
    }
    swap(a, i, hi);

    // count the nums that are <= pivot from lo
    int m = i - lo + 1;

    // pivot is the one!
    if (m == k)     return i;
    // pivot is too big, so it must be on the left
    else if (m > k) return quickSelect(a, lo, i - 1, k);
    // pivot is too small, so it must be on the right
    else            return quickSelect(a, i + 1, hi, k - m);
  }

  void swap(int[] a, int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }

}