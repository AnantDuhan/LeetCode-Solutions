class Solution {
public:
    string thousandSeparator(int n) 
    {
        if(n<1000)
            return to_string(n);
        string answer = "";
        
        string temp=to_string(n);
        int n1=temp.length();
        
        int count=0;
        for(int i=n1-1; i>=0; i--)
        {
            count++;
            answer += temp[i];
            if(count==3)
            {
                answer+=".";
                count=0;
            }
        }
        reverse(answer.begin(),answer.end());
        if(answer[0]=='.')
            answer = answer.substr(1);
        return answer;
    }
};