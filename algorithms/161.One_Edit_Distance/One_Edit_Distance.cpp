    bool isOneEditDistance2(string s, string t){
        if (s.length() > t.length()) {
            swap(s,t);
        }
        if (t.length() - s.length() > 1) {
            return false;
        }
        bool have = false;
        for (int i = 0, j = 0; i < s.length(); ++i,++j){
            if (s[i] != t[j]) {
                if (have) {
                    return false;
                }
                have = true;
                if (s.length() < t.length()) {
                    --i;
                }
            }
        }
        return (have) || (s.length() < t.length());
    }