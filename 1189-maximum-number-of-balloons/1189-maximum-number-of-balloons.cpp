class Solution {
public:
    int maxNumberOfBalloons(string text) {
       int hash[26] ={0};
        for(int i =0;i<text.size();i++){
           int indx = text[i] -'a';
           hash[indx]++;
        }
        int ans = min({  hash['b' - 'a'],
                        hash['a' - 'a'],
                         hash['l' - 'a']/2,
                        hash['o'- 'a']/2,
                        hash['n' -'a']
                        

        });
        return ans;
    }
};