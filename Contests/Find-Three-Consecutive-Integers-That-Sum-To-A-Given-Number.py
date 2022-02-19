class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        a=[]
        if num%3!=0:
            return a
        else:
            n=num//3
            a.append(n-1)
            a.append(n)
            a.append(n+1)
        return a
            
        