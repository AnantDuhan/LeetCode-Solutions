class Solution {
public:
    int minSwaps(string s) {
        int n =s.length();
        int open=0;
        int close=0;
        int swap=0;
        for(int i=0;i<n;i++){
            if(s[i]==']')close++;
            else open++;
            if(close>open){
                swap++;
                open++;
                close--;
            }
        }
        return swap;
    }
};