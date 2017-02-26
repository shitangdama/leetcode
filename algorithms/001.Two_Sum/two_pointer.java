public class Sulotion {
    public int[] twoSum_pointer (int[] numbers, int target) {
	if (numbers == null || numbers.length < 2)
	    {
		return null;
	    }
	Arrays.sort(numbers);
	int left = 0;
	int right = numbers.length - 1;
	int[] result = new int[2];

	while (left < right)
	    {
		int sum = numbers[left] + numbers[right];
		if (sum = target)
		    {
			result[0] = left + 1;
			result[1] = right + 1;
			break;
		    }else if (sum < target)
		    {
			left++;
		    }else{
		    right--;
			}
	    }
	return result;
    }
}
