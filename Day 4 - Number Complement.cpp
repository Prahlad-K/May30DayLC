class Solution {
public:
    // very interesting problem, understood the importance of overflow cases, similar to Day 1!
    // got the solution in 3 submission attempts
    int numBits(int n)
    {
        int bitCount =0;
        while(n>0)
        {
            n>>=1;
            bitCount++;
        }
        return bitCount;
    }
    
    int findComplement(int num) {
        // get the simple complement
        int directComplement = ~num;
        // get the number of bits we need to take from the simple complement
        int bitCount = numBits(num);
        
        // get a number so that the last "bitCount" number of bits are 1s
        // then AND it with the simple complement
        int power2 = 1;
        power2 = power2<<bitCount;
        
        // here's the interesting part - what if the bit count was 32?
        // then, the value becomes INT_MIN!
        int setRequiredBits;
        if(power2!=INT_MIN)
            // in this case, obviously can't just subtract one from INT_MIN!!
            setRequiredBits = power2-1;
        else
            // so set it to the correct value, which is INT_MAX
            setRequiredBits = INT_MAX;
        
        // returning the AND
        return directComplement & setRequiredBits; 
        
    }
};