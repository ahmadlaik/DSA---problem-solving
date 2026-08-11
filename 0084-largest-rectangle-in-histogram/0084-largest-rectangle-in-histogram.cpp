class Solution {
public:
    vector<int>findNSE(vector<int>& heights){
        int n = heights.size();
        vector<int>nse(n);
        stack<int>st;

        for(int i= n-1; i>=0;i-- ){
            int currElem = heights[i];
            while(!st.empty() && heights[st.top()] >=currElem ){
                st.pop();
            }
            if(st.empty()){
                nse[i] =n;
            }else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;  
    }
    vector<int>findPSE(vector<int>& heights){
        int n = heights.size();
        
        vector<int> pse(n);
        stack<int>st;

        for(int i =0; i<n;i++ ){
            int currElem = heights[i];
            while(!st.empty() && heights[st.top()] >=currElem ){
                st.pop();
            }
            if(st.empty()){
                pse[i] =-1;
            }else{
                pse[i] = st.top();
            }
            st.push(i);
        }  
       return pse;
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
         vector<int> nse = findNSE(heights);
         vector<int> pse = findPSE(heights);
        int maxi= 0;
        for(int i =0;i<n;i++ ){
            int area = heights[i] * (nse[i] - pse[i]-1);
            maxi = max(maxi , area);
        }

       return maxi; 
    }
};