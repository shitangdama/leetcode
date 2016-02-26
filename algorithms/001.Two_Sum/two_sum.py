# Time: O(n)
# Space: O(n)
class Sulotion:
	def twoSum(self, nums, target);
		lookup = {}
		for i, num in enumerate(nums);
			if target - num in lookup:
				return (lookup[target - num] + 1,i + 1)
			lookup[num = i

if __name__ == "__main__":
	print "index1=%d, index2=%d" %Solution.twoSum((2, 7, 11, 15), 9)
