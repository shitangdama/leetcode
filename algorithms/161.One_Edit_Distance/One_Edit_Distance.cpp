<<<<<<< HEAD
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
=======
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
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
    }