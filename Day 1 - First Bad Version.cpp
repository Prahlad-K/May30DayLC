// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // lt's do a binary search kind of solution!
        
        int start = 1;
        int end = n;
        
        while(true)
        {
            if(start==end)
                return end;
            
            if(end-start==1)
            {
                if(!isBadVersion(start) && isBadVersion(end))
                    return end;
                else if(isBadVersion(start) && isBadVersion(end))
                    return 1;
                
            }
            else
            {
                // very valuable insight here
                // I initially did a simple (start+end)/2
                // Integer Overflow!
                // Then I tried using unsigned int, and long too
                // The error persisted
                // Then I got round the problem by doing below
                // Now I understand why I had seen this step in common
                // binary search solutions!
                int middle = start + (end-start)/2;
                
                int nextmiddle = middle + 1;
                
                if(!isBadVersion(middle) && isBadVersion(nextmiddle))
                    return nextmiddle;
                
                else if(isBadVersion(middle) && isBadVersion(nextmiddle))
                {
                    // both true, so look to the left
                    end = middle;
                }
                else
                {
                    // both false, so look to the right
                    start = nextmiddle;
                }
            }
        }
    }
};