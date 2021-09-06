class Solution {
public:
    string FB(int i) {
        if(i%15==0)
            return "FizzBuzz";
        else if(i%3==0)
            return "Fizz";
        else if(i%5==0)
            return "Buzz";
        else
            return to_string(i);
    }
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1;i<n+1;i++){
            ans.push_back(FB(i));
        }
        return ans;
    }
};