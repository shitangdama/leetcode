// Flatten 2D Vector
class Vector2D {
  vector<int>::iterator i;
  vector<vector<int>>::iterator j, jj;
public:
  Vector2D(vector<vector<int>>& vec2d) {
    j = vec2d.begin();
    jj = vec2d.end();
    if (j != jj)
      i = j->begin();
  }

  int next() {
    while (i == j->end())
      i = (++j)->begin();
    return *i++;
  }

  bool hasNext() {
    if (j == jj)
      return false;
    for(;;) {
      if (i != j->end())
        return true;
      if (++j == jj)
        return false;
      i = j->begin();
    }
  }
};
class Vector2D {
private:
    vector<vector<int>> data;
    int row, col, r, c;
    void skipEmptyVector(void) {
        while (!col) {
            r++;
            col = data[r].size();
        }
    }

public:
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        r = c = 0;
        row = vec2d.size();
        col = (row == 0 ? -1 : data[r].size());
        skipEmptyVector();
    }

    int next() {
        int elem = data[r][c];
        if (c == col - 1) {
            r++;
            c = 0;
            col = data[r].size();
        }
        else c++;
        skipEmptyVector();
        return elem;
    }

    bool hasNext() {
        return col != -1 && (r < row && c < col);
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
class Vector2D {

 public:
  Vector2D(vector<vector<int>>& vec2d) {
    for(auto & vec : vec2d) {
      if(vec.size() > 0) data.push_back(vec);
    }
    if(data.size() > 0) {
      x = 0; y = 0;
    } else {
      x = -1; y = -1;
    }
  }

  int next() {
    int v = data[x][y];
    if(y + 1 == data[x].size()) {
      x ++; y = 0;
      if(x == data.size()) x = -1;
    } else {
      y ++;
    }
    return v;
  }

  bool hasNext() {
    return x != -1;
  }

 private:
  vector<vector<int>> data;
  int x, y;
};
