class Solution {
public:
    
    // easy, got the solution in the first attempt/submission
    
    bool canConstruct(string ransomNote, string magazine) {
        
        // no way we can contruct from magazine
        // it doesn't have enough letters!
        if(ransomNote.length()>magazine.length())
            return false;
        
        // maintains frequency counts of all characters in magazine
        unordered_map<char,int> charCounts;
        
        for(int i=0;i<magazine.length();i++)
        {
            if(charCounts.find(magazine[i])==charCounts.end())
            {
                charCounts[magazine[i]] = 1;
            }
            else
            {
                charCounts[magazine[i]]++;
            }
        }
        
        // maintains frequency counts of all characters in ransom note
        unordered_map<char,int> ransomCounts;
        for(int i=0;i<ransomNote.length();i++)
        {
            // couldn't find this letter in the magazine
            if(charCounts.find(ransomNote[i])==charCounts.end())
                return false;
            
            if(ransomCounts.find(ransomNote[i])==ransomCounts.end())
            {
                ransomCounts[ransomNote[i]] = 1;
            }
            else
            {
                ransomCounts[ransomNote[i]]++;
            }
            
            // this letter occurs too many times in the note
            if(ransomCounts[ransomNote[i]]>charCounts[ransomNote[i]])
                return false;
        }
        return true;
    }
};