#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef vector<char> TVecChar;
    typedef vector<TVecChar> TVVChar;
    bool exist(vector<vector<char> > &board, string word) {
        if (word.length() == 0)
        {
            return false;
        }

        int iRowNum = board.size();
        int iColNum = 0;
        for (TVVChar::iterator it = board.begin(); it != board.end(); ++it)
        {
            if (it->size() > iColNum)
            {
                iColNum = it->size();
            }
        }

        char **sz = new char*[iRowNum];
        int **mask = new int*[iRowNum];
        for (int i = 0; i < iRowNum; ++i)
        {
            mask[i] = new int[iColNum];
            sz[i] = new char[iColNum];
            for (int j = 0; j < iColNum; ++j)
            {
                sz[i][j] = '\0';
                mask[i][j] = 0;
            }
        }

        int i = 0;
        int j = 0;
        for (TVVChar::iterator itA = board.begin(); itA != board.end(); ++itA, ++i)
        {
            j = 0;
            for (TVecChar::iterator itB = itA->begin(); itB != itA->end(); ++itB, ++j)
            {
                sz[i][j] = *itB;
            }
        }

        for (i = 0; i < iRowNum; ++i)
        {
            for (j = 0; j < iColNum; ++j)
            {
                if (oneStepForward(sz, mask, iRowNum, iColNum, i, j, word.c_str(), 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool oneStepForward(char **sz, int **mask, int iRowNum, int iColNum, int i, int j, const char *word, int iPos)
    {
        if (i < 0 || i >= iRowNum || j < 0 || j > iColNum)
        {
            return false;
        }

        if (sz[i][j] != word[iPos])
        {
            return false;
        }

        mask[i][j] = 1;
        ++iPos;
        if (word[iPos] == '\0')
        {
            return true;
        }

        //up, right, down, left
        int iSz[] = {i-1, i, i+1, i};
        int jSz[] = {j, j+1, j, j-1};

        for(int k = 0; k < 4; ++k)
        {
            if (0 <= iSz[k] && iSz[k] < iRowNum 
                && 0<= jSz[k] && jSz[k] < iColNum 
                && mask[iSz[k]][jSz[k]] == 0)
            {
                if (oneStepForward(sz, mask, iRowNum, iColNum, iSz[k], jSz[k], word, iPos))
                {
                    return true;
                }

                mask[iSz[k]][jSz[k]] = 0;
            }
        }

        mask[i][j] = 0;
        return false;
    }
};
int main() {
    int n, m;
    string w;
    Solution s;
    cin >> n >> m;
    vector<vector<char> > b(n, vector<char>(m));
    for (auto &i : b)
        for (auto &j : i)
            cin >> j;
    while (cin >> w)
        cout << s.exist(b, w) << endl;
    return 0;
}

