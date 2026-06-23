class Solution {
public:
    

    

    void solve( int indx ,vector<int>& candidates, int target , vector<vector<int>>& ans, vector<int>& ds){

        if(target == 0){
    ans.push_back(ds);
    return;
}

    if(indx == candidates.size()){
    return;
}

        // pick 
        if(candidates[indx] <= target){
            ds.push_back(candidates[indx]);
            solve(indx, candidates, target - candidates[indx], ans , ds);
            ds.pop_back();
        }
         
        // not pick

        solve(indx+1, candidates , target , ans ,ds);




        
    }

    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;

        solve(0, candidates, target , ans , ds);



        return ans;
    }
};