class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0) return false;
        // store to vector
        vector<int> l2h; // digit from low to high
        while(x!=0) {
            l2h.push_back(char('0'+x%10)); 
            x /= 10;
        }
        // use two pointers 
        int l = 0;
        int r = l2h.size()-1;
        while(l<=r) {
            if(l2h[l++]!=l2h[r--]) return false;
        }
        return true; 
    }
};