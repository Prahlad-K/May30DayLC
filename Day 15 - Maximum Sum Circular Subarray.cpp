class Solution {
public:
    
    int kadane(vector<int> nums, int start, int end, int sign)
    {
        int maxSumSubarray = sign * nums[start];
        int sumSubarray = sign * nums[start];
        
        for(int i=start+1;i<=end;i++)
        {
            if(sumSubarray<0)
            {
                //restart summing for this subarray, because the previous one is lossy
                sumSubarray = 0;
            }

            if(sign * nums[i] + sumSubarray > maxSumSubarray)
            { 
                // update the maximum
                maxSumSubarray = sign * nums[i] + sumSubarray;
            }

            // summing starts for this subarray
            sumSubarray = sign * nums[i] + sumSubarray;
        }
        return maxSumSubarray;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        // let's first implement Kadane's algorithm
        
        if(A.size()==1)
        {
            return A[0];
        }
        
        int maxKadane = kadane(A, 0, A.size()-1, 1);
        
        int arraySum = 0;
        for(int i=0;i<A.size();i++)
        {
            arraySum+=A[i];
        }
        
       int maxWrap = arraySum + kadane(A, 1, A.size()-1, -1);
       int maxWrap2 = arraySum + kadane(A, 0, A.size()-2, -1);
        
        return std::max(maxKadane, maxWrap);
    }
};