class Solution {
public:
    
    // couldn't get a valid solution in time
    // must revise this question's ideas thoroughly!
    
    int getSingle(vector<int> nums, int start, int end)
    {
        // this shouldn't happen
        if(start>end)
            return -1;
        
        if(start==end)
            return nums[start];
        
        int middle = start + (end-start)/2;
        
        if(middle%2==0)
        {
            // even middle index
            if(nums[middle]==nums[middle+1])
            {
                // single on the right side
                return getSingle(nums, middle+2, end);
            }
            else
            {
                // single on the right side
                return getSingle(nums, start, middle);
            }
        }
        else
        {
            // odd middle index
            if(nums[middle]==nums[middle-1])
            {
                // single on the right side
                return getSingle(nums, middle+1, end);
            }
            else
            {
                // single on the right side
                return getSingle(nums, start, middle-1);
            }
        }
        
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        return getSingle(nums, 0, nums.size()-1);
    }
};