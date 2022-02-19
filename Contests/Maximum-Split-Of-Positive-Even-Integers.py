class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        n=0
        i=2
        ans=[]
        while n < finalSum:
            n+=i
            ans.append(i)
            i+=2
        n=sum(ans)
        
        if n==finalSum:
            return ans
        elif n>finalSum:
            r=n-finalSum
            k=0
            for i in range(len(ans)):
                if ans[i]==r:
                    k=i
            ans.pop(k)
            
            
            if finalSum%2==0:
                return ans
            else:
                return []
            