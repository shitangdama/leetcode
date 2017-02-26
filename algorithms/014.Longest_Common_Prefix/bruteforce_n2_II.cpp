<<<<<<< HEAD
class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }

        string prefix = "";
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return prefix;
                }
            }
            prefix += strs[0][i];
        }

        return prefix;
    }
};
=======
class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }

        string prefix = "";
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return prefix;
                }
            }
            prefix += strs[0][i];
        }

        return prefix;
    }
};
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
