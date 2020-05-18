class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

// THE FOLLOWING CODE GAVE TLE
//         vector<int>anaStarts;
        
//         if(s.length()<p.length())
//             return anaStarts;   
        
        
//         int 
            
//         for(int i=0;i<s.length()-p.length()+1;i++)
//         {
//              std::sort(candidate.begin(), candidate.end());
//              if(candidate==p)
//                  anaStarts.push_back(i);
//         }
//         return anaStarts;

// THIS IS THE OPTIMIZED CODE, REVISE AND UNDERSTAND WELL!!!!!!!!!
        int bit_cnt = 0, cnt[26] = {}, n = s.size(), m = p.size();
        vector<int> res;
        if (n < m) return res;
        for (int i = 0; i < m; ++i) {
            --cnt[p[i] - 'a'];
            ++cnt[s[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i])
                bit_cnt |= 1<<i;
        }
        if (!bit_cnt) res.push_back(0);
        
        for (int i = m; i < n; ++i) {
            if (++cnt[s[i] - 'a']) bit_cnt |= 1<<(s[i] - 'a');
            else bit_cnt &= ~(1<<(s[i] - 'a'));
            if (--cnt[s[i-m] - 'a']) bit_cnt |= 1<<(s[i-m] - 'a');
            else bit_cnt &= ~(1<<(s[i-m] - 'a'));
            if (!bit_cnt) res.push_back(i-m +1);
        }
        
        return res;
            
        
    }
};