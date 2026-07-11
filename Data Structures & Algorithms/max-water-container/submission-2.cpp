class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int n= heights.size();
        int r=n-1;
        int area=0;
        int maxarea=0;
        while(l<r) {
            if(heights[l]>heights[r])
            {
                area=heights[r]*(r-l);
                r--;
            }
            else{
                area=heights[l]*(r-l);
                l++;
            }
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};
