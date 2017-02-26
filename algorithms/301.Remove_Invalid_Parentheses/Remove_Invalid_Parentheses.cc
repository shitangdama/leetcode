void DFS(int ind, int l, int r, const string &s, vector<string> &ret, string &path) {
    // l is the number of '('s and r is the number of ')'s in path
    if(r>l) return;

    if(ind==s.size()) {
        // if !ret.empty(), we find one longest valid string
        if(l==r && (ret.empty() || path.size()==ret[0].size())) 
            ret.push_back(path);
        return;
    }

    if(!ret.empty())
        if(path.size() + s.size() - ind < ret[0].size()) return;

    char c = s[ind++];
    path.push_back(c);
    if(c!='(' && c!=')')
        DFS(ind,l,r,s,ret,path);
    else if(c=='(')
        DFS(ind,l+1,r,s,ret,path);
    else 
        DFS(ind,l,r+1,s,ret,path);

    path.pop_back();
    if(c!='(' && c!=')')
        DFS(ind,l,r,s,ret,path);
    else {
        //once decide to give up current '(' or ')', we do not need to try the continuous '('s or ')'s
        while(c==s[ind]) ++ind;
        DFS(ind,l,r,s,ret,path);
    }
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> ret;
    string path;
    DFS(0,0,0,s,ret,path);
    if(ret.empty()) return {""};
    return ret;
}
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        maxAnsLen = 0;
        strLen = s.size();
        cnt = 0;
        str = s;
        tmp = "";

        numAntiP = new int [strLen + 1];
        jump = new int [strLen + 1];
        numAntiP[strLen] = 0;
        jump[strLen] = strLen;
        str.push_back('@');
        for (int i = strLen - 1; i >= 0; i--) {
            numAntiP[i] = numAntiP[i + 1] + (str[i] == ')');
            if (str[i] == ')')
                jump[i] = (str[i + 1] == ')') ? jump[i + 1] : (i + 1);
            if (str[i] == '(')
                jump[i] = (str[i + 1] == '(') ? jump[i + 1] : (i + 1);
        }

        dfs(0);
        return ans;
    }
private:
    int cnt, *numAntiP, *jump, strLen, maxAnsLen;
    vector<string> ans;
    string str, tmp;
    void dfs(int i) {
        if (strLen - i + tmp.size() < maxAnsLen)
            return;
        else if (i == strLen) {
            maxAnsLen = tmp.size();
            ans.push_back(tmp);
        }
        else if (str[i] == ')') {
            if (cnt > 0) {
                cnt--;
                tmp.push_back(str[i]);
                dfs(i + 1);
                tmp.pop_back();
                cnt++;
            }
            if (numAntiP[i + 1] >= cnt)
                dfs(jump[i]); 
        }
        else if (str[i] == '(') {
            if (numAntiP[i + 1] > cnt) {
                cnt++;
                tmp.push_back(str[i]);
                dfs(i + 1);
                tmp.pop_back();
                cnt--;
            }
            dfs(jump[i]); 
        }
        else {
            tmp.push_back(str[i]);
            dfs(i + 1);
            tmp.pop_back();
        }
    }
};
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        queue<string> q;
        vector<string> output;

        q.push(s);

        while(!q.empty())
        {
            unordered_set<string> foundStrings;
            bool found = false;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string t = q.front();
                if(isValidParen(t))
                {
                    output.push_back(t);
                    found = true;
                }

                q.pop();
                if(!found)
                {
                    for(int k = 0; k < t.size(); k++)
                    {
                        if(t[k] == ')' || t[k] == '(')
                        {
                            string toadd = t.substr(0, k) + t.substr(k + 1);

                            if(foundStrings.find(toadd) == foundStrings.end())
                            {
                                q.push(toadd);
                                foundStrings.insert(toadd);
                            }

                        }
                    }
                }
            }

            if(found)
                return output;
        }

    }

    bool isValidParen(string s)
    {
        if(s.size() == 0)
            return true;

        stack<char> stk;
        int index = 0;

        while(index < s.size())
        {
            char c = s[index];
            if(c == ')')
                return false;
            if(c == '(')
            {
                stk.push(c);
                index++;
                break;
            }

            index++;
        }

        while(index < s.size())
        {
            char c = s[index];

            if(c == '(')
            {
                stk.push(c);
            }

            if(c == ')')
            {
                if(stk.empty())
                    return false;
                stk.pop();
            }
            index++;
        }


        return (stk.empty()) ? true : false;
    }
};