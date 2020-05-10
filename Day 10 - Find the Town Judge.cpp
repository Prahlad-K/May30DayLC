class Solution {
public:
    
    // missed a silly base case, when there's only the Town Judge
    
    int findJudge(int N, vector<vector<int>>& trust) {
        
        if(trust.size()==0 && N==1)
            return 1;
        
        map<int, vector<int> > followers;
        map<int, bool> isFollower;
        
        for(int i=0;i<trust.size();i++)
        {
            isFollower[trust[i][0]] = true;

            vector<int> trusters;
            if(followers.find(trust[i][1])!=followers.end())
            {
                followers[trust[i][1]].push_back(trust[i][0]);
            }
            else
            {
                trusters.push_back(trust[i][0]);
                followers[trust[i][1]] = trusters;
            }
        }
        
        int townJudge = -1;
        
        for(map<int, vector<int> >::iterator it = followers.begin();it!=followers.end();it++)
        {
            if(!isFollower[it->first] && (it->second).size()==N-1)
            {
                townJudge = it->first;
                break;
            }
        }
        return townJudge;
    }
};