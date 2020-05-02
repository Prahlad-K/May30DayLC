class Solution {
public:
    
    // this problem is too easy
    // got no compilation errors and passed all cases in my first attempt
    
    int numJewelsInStones(string J, string S) {
        
        unordered_map<char,int> stoneCount;
        
        for(int i=0;i<S.length();i++)
        {
            if(stoneCount.find(S[i])==stoneCount.end())
            {
                stoneCount[S[i]]=1;
            }
            else
            {
                stoneCount[S[i]]++;
            }
        }
        
        int numJewels = 0;
        for(int i=0;i<J.length();i++)
        {
            numJewels += stoneCount[J[i]];
        }
        
        return numJewels;
        
    }
};