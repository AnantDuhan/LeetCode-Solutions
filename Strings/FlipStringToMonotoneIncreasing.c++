class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int onetozero=0;
        int zerotoone=0;
        for(auto x:s){
            if(x-'0'==0){
                zerotoone++;
                zerotoone=min(zerotoone,onetozero);
            } else if(x-'0'==1) {
                onetozero++;
            }
       }
       return min(onetozero,zerotoone);
    }
};