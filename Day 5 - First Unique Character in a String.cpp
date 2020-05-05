class Solution {
public:
    
    // very simple question, submission accepted at the first attempt
    
    int firstUniqChar(string s) {
     
        unordered_map<char, int> freq;
        
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]]++;
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(freq[s[i]]==1)
                return i;
        }
        
        return -1;
        
    }
};