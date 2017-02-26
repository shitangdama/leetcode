<<<<<<< HEAD
# Time:  O(n)
# Space: O(1)


class Solution:
    # @return a string
    def intToRoman(self, num):
        numeral_map = {1: "I", 4: "IV", 5: "V", 9: "IX", 10: "X", 40: "XL", 50: "L", 90: "XC", 100: "C", 400: "CD", 500: "D", 900: "CM", 1000: "M"}
        keyset, result = sorted(numeral_map.keys()), ""
        
        while num > 0:
            # reversed提供迭代器，倒序
            for key in reversed(keyset):
                while num / key > 0:
                    num -= key
                    result += numeral_map[key]
                    
        return result
=======
# Time:  O(n)
# Space: O(1)


class Solution:
    # @return a string
    def intToRoman(self, num):
        numeral_map = {1: "I", 4: "IV", 5: "V", 9: "IX", 10: "X", 40: "XL", 50: "L", 90: "XC", 100: "C", 400: "CD", 500: "D", 900: "CM", 1000: "M"}
        keyset, result = sorted(numeral_map.keys()), ""
        
        while num > 0:
            for key in reversed(keyset):
                while num / key > 0:
                    num -= key
                    result += numeral_map[key]
                    
        return result

if __name__ == "__main__":
    print Solution().intToRoman(999)
    print Solution().intToRoman(3999)
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
