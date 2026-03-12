class Solution {
public:
    int crossMax(vector<int>& nums,int l,int m,int r){
        int sum=0;
        int leftSum=INT_MIN;
        for(int i=m;i>=0;--i){
            sum+=nums[i];
            if(sum>=leftSum) leftSum=sum;
        }
        int rightSum=INT_MIN;
        sum=0;
        for(int i=m+1;i<=r;++i){
            sum+=nums[i];
            if(sum>=rightSum) rightSum=sum;
        }
        return (leftSum+rightSum);
    }

    int maxSum(vector<int>& nums, int l, int r){
        if(l>r) return INT_MIN;
        if(l==r) return nums[l];
        int m=(r+l)/2;
        int leftSum=maxSum(nums,l,m);
        int rightSum=maxSum(nums,m+1,r);
        int crossSum=crossMax(nums,l,m,r);
        return max(leftSum,max(rightSum,crossSum));
        
    }

    int maxSubArray(vector<int>& nums) {
        return maxSum(nums,0,nums.size()-1);
    }
};
// O(nlogn)
