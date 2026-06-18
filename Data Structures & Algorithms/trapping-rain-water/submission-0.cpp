class Solution {
public:
    int trap(vector<int>& height) {
    int n=height.size();
      vector<int>lmax(n,0);
      vector<int>rmax(n,0);
      lmax[0]=height[0];
      rmax[n-1]=height[n-1];  
        int ans=0;
      for(int i=1;i<n;i++)
      {
        lmax[i]=max(lmax[i-1],height[i]);
      }
      for(int j=n-2;j>=0;j--)
      {
        rmax[j]=max(rmax[j+1],height[j]);
      }

      for(int i=0;i<n;i++)
      {
        ans+=(min(lmax[i],rmax[i])-height[i]);
      }
      return ans;
    }
};
