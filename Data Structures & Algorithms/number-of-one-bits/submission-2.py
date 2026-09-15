class Solution:
    def hammingWeight(self, n: int) -> int:
        a = bin(n)
        count = 0
        for i in str(a):
            if i=="1":
                count+=1
        return count