//Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int maxlen=0;
        unordered_map<char,int> m;
        while(j<s.size()){
            m[s[j]]++;

            if(m[s[j]]==1){
                if(j-i+1>maxlen){
                    maxlen=j-i+1;
                }
                j++;
            }
            else if(m[s[j]]>1){
                while(m[s[j]]>1){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(m[s[i]]);
                    }
                    i++;
                }
                if(m[s[j]]==1){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                    }
                }
                j++;
            }

        }
        return maxlen;
        
    }
};
