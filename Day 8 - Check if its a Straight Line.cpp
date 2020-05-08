class Solution {
public:
    
    // good lesson in typecasting broooo (in this case from int to double)
    // use (higher_datatype) <calculation>
    // other than that, simple solution
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size()==2)
            return true;
        else
        {
            // must be more than 2 points!
            int p1x = coordinates[0][0];
            int p1y = coordinates[0][1];
            
            int p2x = coordinates[1][0];
            int p2y = coordinates[1][1];
            
            double slope = (double)(p2y-p1y)/(p2x-p1x);
            
            // cout<<slope<<" expected\n";
            
            for(int i=1;i<coordinates.size()-1;i++)
            {
                int x1 = coordinates[i][0];
                int y1 = coordinates[i][1];
                
                int x2 = coordinates[i+1][0];
                int y2 = coordinates[i+1][1];
                
                double slope_expected = (double)(y2-y1)/(x2-x1);
                // cout<<slope_expected<<"\n";
                if(slope!=slope_expected)
                    return false;
            }
            return true;
        }
        
    }
};