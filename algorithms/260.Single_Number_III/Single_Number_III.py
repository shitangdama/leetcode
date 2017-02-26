class Solution(object):
    def singleNumber(self, nums):
        # https://leetcode.com/discuss/48119/single-number-iii
        xor = 0
        for num in nums: xor ^= num
        xor = xor & (xor - 1) ^ xor
        a = b = 0
        for num in nums:
            if xor & num:
                a ^= num
            else:
                b ^= num
        return [a, b]
def singleNumber1(self, nums):
    count = collections.Counter(nums)
    return [k for k, v in count.iteritems() if v < 2]

def singleNumber2(self, nums):
    dic = collections.defaultdict(int)
    for num in nums:
        dic[num] += 1
    return [k for k, v in dic.items() if v < 2]

def singleNumber3(self, nums):
    dic = {}
    for num in nums:
        dic[num] = dic.get(num, 0) + 1
    return [k for k, v in dic.items() if v < 2]

def singleNumber4(self, nums):
    dic = collections.OrderedDict()
    for num in nums:
        dic[num] = dic.get(num, 0) + 1
    return [k for k, v in dic.iteritems() if v < 2]

def singleNumber(self, nums):
    tmp = reduce(operator.xor, nums)
    bit = tmp & (-tmp)
    n1, n2 = 0, 0
    for num in nums:
        if num & bit:
            n1 ^= num
        else:
            n2 ^= num
    return [n1, n2]
# O(n) space, O(n) time
def singleNumber1(self, nums):
    dic, res = {}, []
    for num in nums:
        dic[num] = dic.get(num, 0) + 1
    for k, v in dic.items():
        if v == 1:
            res.append(k)
    return res

# Bit manipulation, O(1) space, O(n) time
def singleNumber(self, nums):
    # "xor" all the nums 
    tmp = 0
    for num in nums:
        tmp ^= num
    # find the rightmost "1" bit
    i = 0
    while tmp & 1 == 0:
        tmp >>= 1
        i += 1
    tmp = 1 << i
    # compute in two seperate groups
    first, second = 0, 0
    for num in nums:
        if num & tmp:
            first ^= num
        else:
            second ^= num
    return [first, second]
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        workingset = set()
        for n in nums:
            if n not in workingset:
                workingset.add(n)
            else:
                workingset.remove(n)
        return list(workingset)
