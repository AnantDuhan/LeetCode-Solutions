class Solution {
public:
    string addStrings(string num1, string num2) {
        string output="";
        int i=num1.length()-1;
        int j=num2.length()-1;
        int carry=0;
        while (i >= 0 || j >= 0||carry) {
            int add = 0;
            (i>=0)?add+=int(num1[i--]) - 48:add+=0;
            (j>=0)?add+=int(num2[j--]) - 48:add+=0;
            add+=carry;
            carry = add / 10;
            output+='0'+(add%10);
        }
        reverse(output.begin(),output.end());
        return output;
    }
};