class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int maxlen =0;
        int maxfreq =0;
        int left =0;
        vector<int>hash(26,0);

        for(int right =0; right<n; right++){
            hash[s[right] -'A']++;
            maxfreq= max(maxfreq , hash[s[right]- 'A']);
            int windowLen = right - left +1;
            
            if(windowLen - maxfreq > k){
                hash[s[left] - 'A']--;
                left++;
            }
            else{
                maxlen= max(maxlen , right- left +1);
            }

            
        }
    return maxlen;
    }
};