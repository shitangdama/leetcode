public class solution {
    public int[] twoSum_hashmap(int[] numbers, int target) {
	if (numbers == null || numbers.length < 2)
	    {
		return null;
	    }
	HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
	for (int i = 0; i < numbers.length; ++i)
	    {
		map.put(numbers[i], i + 1)
	    }

	int[] a = new int[2];
	for (int i = 0; i < numbers.length; ++i)
	    {
		if (map.containsKey(target - numbers[i]) )
		    {
			int index1 = i + 1;
			int index2 = map.get(target - numbers[i]);
			if (index1 == index2)
			    {
				continue;
			    }
			a[0] = index1;
			a[1] = index2;
			return a;
		    }
	    }
	return a;
    }
}
