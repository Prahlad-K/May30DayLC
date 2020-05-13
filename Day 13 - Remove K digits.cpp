class Solution {
public:
    
    void removeKdigitsHelper(string num, int k, string& ans)
    {
        if(num.length()<=k)
            return;
        
        if(k==0)
        {
            ans.append(num);
            return;
        }
        int minIndex=0;
        for(int i=1;i<=k;i++)
        {
            if(num[i]<num[minIndex])
                minIndex = i;
        }
        
        ans.push_back(num[minIndex]);
        removeKdigitsHelper(num.substr(minIndex+1, num.length()-minIndex), k-minIndex, ans);
    }
    
    string removeKdigits(string num, int k) 
    {
        string ans;
        removeKdigitsHelper(num, k, ans);
        
        int index;
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]!='0')
            {
                index = i;
                break;
            }
        }
        ans = ans.substr(index, ans.length()-index+1);
        
        if(ans.length()==0)
            ans.push_back('0');
        return ans;
    }
    
};
//     int removeKdigitsHelper(string num, int k, int i, int ans)
//     {
//         if(i==num.size())
//         {
//             if(k==0)
//                 return ans;
//             else
//                 return INT_MAX;
//         }
//         else
//         {
//             if(k>=0)
//             {
//              return std::min(removeKdigitsHelper(num, k, i+1, ans * 10 + (num[i]-'0')), 
//                 removeKdigitsHelper(num, k-1, i+1, ans));   
//             }
//             else
//             {
//                 return INT_MAX;
//             }
//         }
//     }
    
//     string removeKdigits(string num, int k) {
        
//         return std::to_string(removeKdigitsHelper(num, k, 0, 0));
        
//     }

    
