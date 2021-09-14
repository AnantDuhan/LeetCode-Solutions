class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>p;
        for(int i=0;i<piles.size();i++){
            p.push(piles[i]);
        }
        while(k--){
            int a=p.top()/2;
            int b= p.top()-a;
            p.pop();
            p.push(b);
        }
        int ans=0;
        while(!p.empty()){
           ans+=p.top();
            p.pop();
        }
        return ans;
    }
};