class Solution:
    # @param num, a list of integer
    # @return an integer
    def rob(self, num):
        if len(num) == 0:
            return 0
            
        if len(num) == 1:
            return num[0]
        
        num_i, num_i_1 = max(num[1], num[0]), num[0]
        for i in xrange(2, len(num)):
            num_i_1, num_i_2 = num_i, num_i_1
            num_i = max(num[i] + num_i_2, num_i_1);
        
        return num_i

if __name__ == '__main__':
        print Solution().rob([8,4,8,5,9,6,5,4,4,10])
