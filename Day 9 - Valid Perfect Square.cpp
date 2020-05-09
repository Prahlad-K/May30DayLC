class Solution {
public:
    
    // ALWAYS REMEMBER ABOUT INT MAX!!!!!!!!!!
    
    bool isPerfectSquare(int num) {
        
        if(num==INT_MAX)
            return false;
        
        int numSqrt=1;
        while(numSqrt*numSqrt<num)
        {
            numSqrt++;
        }
        
        return (numSqrt*numSqrt==num);
    }
};