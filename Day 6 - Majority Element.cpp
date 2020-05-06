class Solution {
public:
    
    // accepted in first attempt
    // but not the most optimal solution
    // used hashmap
    // time complexity is same - O(n)
    // space complexity is O(n) tho

//     int majorityElement(vector<int>& nums) {
//         unordered_map <int, int> freq;
//         for(int i=0;i<nums.size();i++)
//         {
//             freq[nums[i]]++;
//             if(freq[nums[i]]>(nums.size()/2))
//             {
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
    
    // Boyer-Moore's voting algo works best!
    // space complexity is O(1)
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                candidate = nums[i];    
            }
            count += (candidate==nums[i]) ? 1 : -1;
        }
        return candidate;
    }
};