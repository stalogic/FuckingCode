#include<iostream>
#include<vector>
using namespace std;


int find_max_subarray_sum(vector<int>& nums)
{
    int max=0;
    int sum=0;
    for(int i=0;i<nums.size();i++) {
        sum+=nums[i];
        if(sum < 0) {
            sum=0;
        }
        if(sum > max) {
            max=sum;
        }
    }
    return max;
}

int main()
{
    int a[]={2,3,-4,11,-2,13,-4,3,2};
    vector<int> nums(a,a+sizeof(a)/sizeof(a[0]));
    int res=find_max_subarray_sum(nums);
    cout<<res<<endl;
    return 0;
}