<<<<<<< HEAD
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans=1
        q2,q3,q5=[[i] for i in [2,3,5]]
        while n>1:
            n-=1
            minval=min(q2[0],q3[0],q5[0])
            if minval==q2[0]:
                ans=q2.pop(0)
                q2.append(ans*2)
                q3.append(ans*3)
                q5.append(ans*5)
            elif minval==q3[0]:
                ans=q3.pop(0)
                q3.append(ans*3)
                q5.append(ans*5)
            else:
                ans=q5.pop(0)
                q5.append(ans*5)
        return ans

=======
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans=1
        q2,q3,q5=[[i] for i in [2,3,5]]
        while n>1:
            n-=1
            minval=min(q2[0],q3[0],q5[0])
            if minval==q2[0]:
                ans=q2.pop(0)
                q2.append(ans*2)
                q3.append(ans*3)
                q5.append(ans*5)
            elif minval==q3[0]:
                ans=q3.pop(0)
                q3.append(ans*3)
                q5.append(ans*5)
            else:
                ans=q5.pop(0)
                q5.append(ans*5)
        return ans

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
