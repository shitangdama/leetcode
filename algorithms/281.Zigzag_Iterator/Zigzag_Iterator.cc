<<<<<<< HEAD
// Zigzag Iterator
class ZigzagIterator {
  vector<int>::iterator i, ii, j, jj;
public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    i = v1.begin();
    ii = v1.end();
    j = v2.begin();
    jj = v2.end();
  }

  int next() {
    if (i == ii)
      return *j++;
    swap(i, j);
    swap(ii, jj);
    return *j++;
  }

  bool hasNext() {
    return i != ii || j != jj;
  }
=======
// Zigzag Iterator
class ZigzagIterator {
  vector<int>::iterator i, ii, j, jj;
public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    i = v1.begin();
    ii = v1.end();
    j = v2.begin();
    jj = v2.end();
  }

  int next() {
    if (i == ii)
      return *j++;
    swap(i, j);
    swap(ii, jj);
    return *j++;
  }

  bool hasNext() {
    return i != ii || j != jj;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};