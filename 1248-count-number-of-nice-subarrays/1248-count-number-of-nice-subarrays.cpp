class Solution {
public:
    int countAtMost(vector<int>& nums, int k){
        int n = nums.size();
        int count = 0;
        int start =0;
        int oddCount =0;
        for(int end =0; end <n ;end++){

            if(nums[end]% 2 != 0){
                k--;
            }

            while(k<0){
                if (nums[start] % 2 != 0)
                    k++;
                start++;
            }
            count += (end - start + 1);

        }
       return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
        
    }
};