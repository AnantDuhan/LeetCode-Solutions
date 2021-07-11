class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int count=0;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto &it:mp){
            count+=it.second/2*2;
            if(count%2 == 0 && it.second % 2 ==1) count+=1;
        }
        return count;
    }
};