# Time:  O(n)
# Space: O(1)

class Solution:
    # @return an integer
    def atoi(self, str):
        INT_MAX =  2147483647
        INT_MIN = -2147483648
        result = 0
        
        if not str:
            return result
        
        i = 0
        while i < len(str) and str[i] == " ":
            i += 1
        
        sign = 1
        if str[i] == "+":
            i += 1
        elif str[i] == "-":
            sign = -1
            i += 1

        while i < len(str) and str[i] >= '0' and str[i] <= '9':
            if result > INT_MAX / 10 or (result == INT_MAX / 10 and ord(str[i]) - ord('0') > INT_MAX % 10):
                if sign > 0:
                    return INT_MAX
                else:
                    return INT_MIN
            
            result = result * 10 + ord(str[i]) - ord('0')
            i += 1
        
        return sign * result

if __name__ == "__main__":
    print Solution().atoi("") 
    print Solution().atoi("-1")
    print Solution().atoi("2147483647") 
    print Solution().atoi("2147483648") 
    print Solution().atoi("-2147483648")  
    print Solution().atoi("-2147483649")  
