class Solution {
private:
    string help(string &s,int& i)   //要使用引用，改变i值
    {
        string res;
        
        while(i<s.size() && s[i]!=']')
        {
           if(!isdigit(s[i]))
            {
                res+=s[i];
                i++;
            }
            else
            {
                int tmp=0;
                while(i<s.size() && isdigit(s[i]))
                {
                    tmp=tmp*10+s[i]-'0';
                    i++;
                }
                
                i++;
                string str=help(s,i);
                i++;
                
                while(tmp>0)
                {
                    res+=str;
                    tmp--;
                }
            }             
        }
        
        return res;
    }
public:
    string decodeString(string s) {
        int n=s.size();
        if(n==0)
            return "";       

        int i=0;
        return help(s,i);
    }
};
