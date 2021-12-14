class Solution {
public:
    string longestPalindrome(string s)
    {
        int l=0,h=0;
        int len=0;
        int st=0;
        int maxlen=INT_MIN;
        for(int i=1;i<s.length();i++)
         {
            l=i-1;
            h=i+1;
            while(l>=0 && h<s.length() && s[l]==s[h])
            {
                l--;
                h++;
            }
            l++;
            h--;
            len=h-l+1;
            if(len>maxlen)
            {  st=l;
                maxlen=len;
            }
                l=i-1;
            h=i;
            while(l>=0 && h<s.length() && s[l]==s[h])
            {
                l--;
                h++;
            }
            l++;
            h--;
            len=h-l+1;
            if(len>maxlen)
            {
                st=l;
                maxlen=len;
            }
         }
        return s.substr(st,maxlen);

    }
};
