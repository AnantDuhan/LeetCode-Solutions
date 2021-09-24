class Solution {
public:
    int tribonacci(int n) {
        vector<int> F(3);
        F[0] = 0;
        F[1] = 1;
        F[2] = 1;
        
        for(int i=3;i<=n;i++) {
            F.push_back(F[i-1]+F[i-2]+F[i-3]);
        }
        return F[n];
    }
};