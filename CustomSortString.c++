class Solution {
public:
    static bool compare(char a, char b) {
        return m_order.find(a) < m_order.find(b);
    }
    
    string customSortString(string order, string str) {
        m_order = order;
        sort(str.begin(), str.end(), compare);
        return str;
    }
    
private:
    static string m_order;
};

// Static members have to be declared outside the class
string Solution::m_order;