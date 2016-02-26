#using binary search
def lengthOfLIS(self, nums):
    def search(temp, left, right, target):
        if left == right:
            return left
        mid = left+(right-left)/2
        return search(temp, mid+1, right, target) if temp[mid]<target else search(temp, left, mid, target)
    temp = []
    for num in nums:
        pos = search(temp, 0, len(temp), num)
        if pos >=len(temp):
            temp.append(num)
        else:
            temp[pos]=num
    return len(temp)
