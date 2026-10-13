class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(int i =0;i<stones.size(); i++){
            pq.push(stones[i]);
        }
        while(pq.size()>=2){
            int firstMax = pq.top();
            pq.pop();
            int secondMax = pq.top();
            pq.pop();

            if(firstMax != secondMax){
                pq.push((firstMax - secondMax));
            }
                
            
        }



        if(pq.empty()){
            return 0;
        }
        else{
            return pq.top();
        }
        
        
    }
};