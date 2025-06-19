class Solution {
public:
int atmostsum(vector<int>&nums , int goal){

    int n = nums.size();
    int i=0,j=0;

    int sum=0,cnt=0;

    while(j<n){
        sum+=nums[j];

        while(i<n&&sum>goal){
           sum-=nums[i];
            i++;
        }
        if(i<=j)
        cnt+=(j-i+1);
        j++;
    }
    return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
         int x= atmostsum(nums,goal);

         int y= atmostsum(nums,goal-1);
        

         cout<<x<<" "<<y<<endl;
         return x-y;
    }
};