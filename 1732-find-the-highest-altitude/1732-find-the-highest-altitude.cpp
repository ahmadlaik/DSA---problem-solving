class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       ;
        int altitude =0;
        int highestAltitude = 0;


        for(int i =0;i<gain.size();i++){
            altitude += gain[i];
            highestAltitude= max(altitude , highestAltitude);
        }
        return highestAltitude;
    }
};