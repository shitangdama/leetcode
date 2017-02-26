private char[][] image;
public int minArea(char[][] iImage, int x, int y) {
    image = iImage;
    int m = image.length, n = image[0].length;
    int left = searchColumns(0, y, 0, m, true);
    int right = searchColumns(y + 1, n, 0, m, false);
    int top = searchRows(0, x, left, right, true);
    int bottom = searchRows(x + 1, m, left, right, false);
    return (right - left) * (bottom - top);
}
private int searchColumns(int i, int j, int top, int bottom, boolean opt) {
    while (i != j) {
        int k = top, mid = (i + j) / 2;
        while (k < bottom && image[k][mid] == '0') ++k;
        if (k < bottom == opt)
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}
private int searchRows(int i, int j, int left, int right, boolean opt) {
    while (i != j) {
        int k = left, mid = (i + j) / 2;
        while (k < right && image[mid][k] == '0') ++k;
        if (k < right == opt)
            j = mid;
        else
            i = mid + 1;
    }
    return i;
}
//  Runtime: 1 ms
Java (DRY)

private char[][] image;
public int minArea(char[][] iImage, int x, int y) {
    image = iImage;
    int m = image.length, n = image[0].length;
    int top = search(0, x, 0, n, true, true);
    int bottom = search(x + 1, m, 0, n, false, true);
    int left = search(0, y, top, bottom, true, false);
    int right = search(y + 1, n, top, bottom, false, false);
    return (right - left) * (bottom - top);
}
private boolean isWhite(int mid, int k, boolean isRow) {
    return ((isRow) ? image[mid][k] : image[k][mid]) == '0';
}
private int search(int i, int j, int low, int high, boolean opt, boolean isRow) {
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
//  Runtime: 2 ms