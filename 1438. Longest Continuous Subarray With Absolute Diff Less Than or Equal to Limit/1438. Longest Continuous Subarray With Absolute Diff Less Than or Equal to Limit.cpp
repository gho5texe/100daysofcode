class Solution {
public:
    void solve(int &mini,int &maxi,int &max_ind,int &min_ind,int j,vector<int>&nums){
        if(mini>=nums[j]){
            min_ind=j;
            mini=nums[j];
          }
          if(maxi<=nums[j]){
            max_ind=j;
            maxi=nums[j];
          }
    }

    int longestSubarray(vector<int>& nums, int limit) {
      int i=0;int j=0;
      int mini=INT_MAX;int maxi=0;
      int min_ind=0,max_ind=0;int ans=0;
      while(j<nums.size()){
          solve(mini,maxi,max_ind,min_ind,j,nums);
  
          if(maxi-mini<=limit){
            ans=max(ans,j-i+1);
            j++;
          }else{
            int t=min(max_ind,min_ind);
            i=t+1;
            mini=INT_MAX;maxi=0;
            for(int k=i;k<=j;k++){
              solve(mini,maxi,max_ind,min_ind,k,nums);
          }
            j++;
          }

      }
      return ans;
      
    }
};