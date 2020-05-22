class Solution {
    static bool compare(const pair<char, int> one, const pair<char, int> two)
    {
        return one.second>two.second;
    }
    
public:
    
    
    string frequencySort(string s) {
        map<char, int> freq;
        string answer;
        
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]]++;
        }
        
        vector<pair<char, int>> freqV;
        
        for(map<char,int>::iterator it = freq.begin();it!=freq.end();it++)
        {
            freqV.push_back(make_pair(it->first, it->second));
        }
        
        sort(freqV.begin(), freqV.end(), this->compare);
        
        for(vector<pair<char,int> >::iterator it = freqV.begin();it!=freqV.end();it++)
        {
            for(int i=0;i<it->second;i++)
                answer.push_back(it->first);
        }
        
        return answer;
        
    }
};