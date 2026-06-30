class Solution {
public:
    vector<vector<int>>ans;
    vector<int>ds;
    void solve( int indx , vector<int>& candidates, int target ){
        if(target==0){
            ans.push_back(ds);
            return;
        }

       for(int i =indx;i<candidates.size(); i++){
        if(i>indx && candidates[i]==candidates[i-1]){
            continue;
        }
         if (candidates[i] > target)
                break;

            ds.push_back(candidates[i]);

            // Move to next index (cannot reuse same element)
            solve(i + 1, candidates, target - candidates[i]);

            ds.pop_back();
       }
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        solve(0, candidates , target);
       return ans; 
    }
};