class Solution:
    def findNthDigit(self, n: int) -> int:
        # 个数
        num = 9
        # 位数
        digit = 1

        while n - num * digit  > 0:
            # 个数 * 位数 == 总数字个数
            n -= num * digit
            num *= 10
            digit += 1
        a, b = divmod(n - 1, digit)
        return int(str(10 ** (digit - 1) + a)[b])