<<<<<<< HEAD
vector<vector<char>> *image;
int minArea(vector<vector<char>> &iImage, int x, int y) {
    image = &iImage;
    int m = int(image->size()), n = int((*image)[0].size());
    int top = searchRows(0, x, 0, n, true);
    int bottom = searchRows(x + 1, m, 0, n, false);
    int left = searchColumns(0, y, top, bottom, true);
    int right = searchColumns(y + 1, n, top, bottom, false);
    return (right - left) * (bottom - top);
}
int searchRows(int i, int j, int low, int high, bool opt) {
    while (i != j) {
        int k = low, mid = (i + j) / 2;
        while (k < high && (*image)[mid][k] == '0') ++k;
        if (k < high == opt)
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}
int searchColumns(int i, int j, int low, int high, bool opt) {
    while (i != j) {
        int k = low, mid = (i + j) / 2;
        while (k < high && (*image)[k][mid] == '0') ++k;
        if (k < high == opt)
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}
// Runtime: 20 ms
C++ (DRY)

vector<vector<char>> *image;
int minArea(vector<vector<char>> &iImage, int x, int y) {
    image = &iImage;
    int m = int(image->size()), n = int((*image)[0].size());
    int top = search(0, x, 0, n, true, true);
    int bottom = search(x + 1, m, 0, n, false, true);
    int left = search(0, y, top, bottom, true, false);
    int right = search(y + 1, n, top, bottom, false, false);
    return (right - left) * (bottom - top);
}
bool isWhite(int mid, int k, bool isRow) {
    return ((isRow) ? (*image)[mid][k]:(*image)[k][mid]) == '0';
}
int search(int i, int j, int low, int high, bool opt, bool isRow) {
    while (i != j) {
        int k = low, mid = (i + j) / 2;
        while (k < high && isWhite(mid, k, isRow)) ++k;
        if (k < high == opt)
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}
// Runtime: 24 ms

=======
vector<vector<char>> *image;
int minArea(vector<vector<char>> &iImage, int x, int y) {
    image = &iImage;
    int m = int(image->size()), n = int((*image)[0].size());
    int top = searchRows(0, x, 0, n, true);
    int bottom = searchRows(x + 1, m, 0, n, false);
    int left = searchColumns(0, y, top, bottom, true);
    int right = searchColumns(y + 1, n, top, bottom, false);
    return (right - left) * (bottom - top);
}
int searchRows(int i, int j, int low, int high, bool opt) {
    while (i != j) {
        int k = low, mid = (i + j) / 2;
        while (k < high && (*image)[mid][k] == '0') ++k;
        if (k < high == opt)
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}
int searchColumns(int i, int j, int low, int high, bool opt) {
    while (i != j) {
        int k = low, mid = (i + j) / 2;
        while (k < high && (*image)[k][mid] == '0') ++k;
        if (k < high == opt)
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}
// Runtime: 20 ms
C++ (DRY)

vector<vector<char>> *image;
int minArea(vector<vector<char>> &iImage, int x, int y) {
    image = &iImage;
    int m = int(image->size()), n = int((*image)[0].size());
    int top = search(0, x, 0, n, true, true);
    int bottom = search(x + 1, m, 0, n, false, true);
    int left = search(0, y, top, bottom, true, false);
    int right = search(y + 1, n, top, bottom, false, false);
    return (right - left) * (bottom - top);
}
bool isWhite(int mid, int k, bool isRow) {
    return ((isRow) ? (*image)[mid][k]:(*image)[k][mid]) == '0';
}
int search(int i, int j, int low, int high, bool opt, bool isRow) {
    while (i != j) {
        int k = low, mid = (i + j) / 2;
        while (k < high && isWhite(mid, k, isRow)) ++k;
        if (k < high == opt)
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}
// Runtime: 24 ms

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
