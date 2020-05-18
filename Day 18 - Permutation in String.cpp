class Solution {
public:

    // similar to yesterday's, pretty easy
    bool checkInclusion(string s1, string s2) {
        
        // base case
        if(s2.length()<s1.length())
            return false;
        
        int count1[26];
        
        for(int j=0;j<26;j++)
        {
            count1[j] = 0;
        }
        
        for(int i=0;i<s1.length();i++)
        {
            count1[s1[i]-'a']++;
        }
        
        for(int i=0;i<s2.length()-s1.length()+1;i++)
        {
            int count2[26];
            
            for(int j=0;j<26;j++)
            {
                count2[j] = 0;
            }
            for(int j=i;j<i+s1.length();j++)
            {
                count2[s2[j]-'a']++;
            }
            
            bool permutationPresent = true;
            for(int j=0;j<26;j++)
            {
                if(count1[j]!=count2[j])
                {
                    permutationPresent = false;
                    break;
                }
            }
            if(permutationPresent)
                return true;
            
        }
        return false;
        
    }
};