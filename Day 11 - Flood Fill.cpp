class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int pixel = image[sr][sc];
            
        // this case to avoid permanent recursion
        if(pixel==newColor)
            return image;
       
        // first, change the color of this pixel
        image[sr][sc] = newColor;
        
        // recur for 4 connected pixels, only if it's feasible
        if(sr>0 && image[sr-1][sc]==pixel)
            floodFill(image, sr-1, sc, newColor);
        
        if(sr<image.size()-1 && image[sr+1][sc]==pixel)
            floodFill(image, sr+1, sc, newColor);
        
        if(sc>0 && image[sr][sc-1]==pixel)
            floodFill(image, sr, sc-1, newColor);
        
        if(sc<image[0].size()-1 && image[sr][sc+1]==pixel)
            floodFill(image, sr, sc+1, newColor);
        
        return image;
    }
};