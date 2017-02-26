<<<<<<< HEAD
public boolean isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int divide = 1;
    while (x / divide >= 10) {
        divide *= 10;
    }
    int head = 0, tail = 0;
    while (divide > 0) {
        head = x / divide;
        tail = x % 10;
        if (head != tail) {
            return false;
        }
        x = x % divide / 10;
        divide /= 100;
    }
    return true;
=======
public boolean isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int divide = 1;
    while (x / divide >= 10) {
        divide *= 10;
    }
    int head = 0, tail = 0;
    while (divide > 0) {
        head = x / divide;
        tail = x % 10;
        if (head != tail) {
            return false;
        }
        x = x % divide / 10;
        divide /= 100;
    }
    return true;
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}