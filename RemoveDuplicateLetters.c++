class Solution {
public:
    string removeDuplicateLetters(string s) {
    int cnt[26] = { 0 };
 
    int vis[26] = { 0 };
 
    int n = s.size();
 
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
        
    string res = "";
 
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']--;

        if (!vis[s[i] - 'a']) {
            while (res.size() > 0
                   && res.back() > s[i]
                   && cnt[res.back() - 'a'] > 0) {
                vis[res.back() - 'a'] = 0;
                res.pop_back();
            }
 
            res += s[i];
            vis[s[i] - 'a'] = 1;
        }
    }
    return res;
    }
};


// more efficient
/*
Lets deep dive into the solution:
Here in the solution visited is the map which helps to track of each character whether i have visited or not

Here lastIdx is where we keep track of the last Index of every char eg abddcabbe if we make this array of last index then it will look something like this [a => 5 , b => 7 , c => 4 , e => 8 ]

Apart from this we have taken stack stc in which we will store our final variable

Lets take a example to understand :

string s= "bcabc"

In the first loop it will mark all the numbers from 1-26 as false as in starting all the characters are not visited the next loop lastIdx will keep the track of the last visited number of individual character.

Here comes the main logic

If the value in visited is already visited we just continue with our solution.
Now we check of the. stack is empty or not and also followed by a condition where the stack top value > the current val.
eg 1st iteration -->b will enter in the loop and will not go in any condition so its pushed into the stack
2nd value will be c now the stack is not empty (1st condition satisfied) we check with stc.top() that is b will check if b >c this condition doesnt satisfied so the value will be pushed into the stack.
 */

 stack<int> stc;
        unordered_map<int,bool> visited;
        int lastIdx[26] ;
        string ans = "";
        for(int i=1 ; i<=26;i++)
            visited[i] = false;
        
        for(int i=0 ; i<s.size();i++)
            lastIdx[s[i] - 'a'] = i;
        
        for(int i=0 ; i<s.size();i++){
            char val = s[i] - 'a';
            if(visited[val]) continue;
            while(!stc.empty()  && stc.top() > val && lastIdx[stc.top()] > i){
                visited[stc.top()] = false;
                 stc.pop();
            }
            stc.push(val);
            visited[val] = true;
        }
        while(!stc.empty()){
            ans+= stc.top() + 'a';
            stc.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;