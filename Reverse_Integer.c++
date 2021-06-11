class Solution {
public:
    int reverse(int x) {
        int num=abs(x);
        long long rev=0;
        while(num>0){
            rev=(10*rev)+(num%10);
            num=num/10;
        }
        if(rev>INT_MAX) return 0;
        if(x<0) return -rev;
        return rev;
    }
}; 