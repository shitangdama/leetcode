<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        const int size = 32;
        bitset<size> bits(n);
        for (int i = 0; i < size / 2; ++i) {
            // swap(bits[i], bits[size - i - 1]);
            int tmp = bits[i];
            bits[i] = bits[size - i - 1];
            bits[size - i - 1] = tmp;
        }
        return (uint32_t) bits.to_ulong();
    }
};
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for(int i=0; i<32; i++) {
            ret = (ret*2) + (n & 0x1);
            n /=2 ;
        }
        return ret;
    }
};
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = n & 1;
    for(int i = 1; i <= 31; ++i) {
      n >>= 1;
      result <<= 1;
      result = result | (n & 1);
    }
    return result;
  }
};
int main() {

    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        const int size = 32;
        bitset<size> bits(n);
        for (int i = 0; i < size / 2; ++i) {
            // swap(bits[i], bits[size - i - 1]);
            int tmp = bits[i];
            bits[i] = bits[size - i - 1];
            bits[size - i - 1] = tmp;
        }
        return (uint32_t) bits.to_ulong();
    }
};
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for(int i=0; i<32; i++) {
            ret = (ret*2) + (n & 0x1);
            n /=2 ;
        }
        return ret;
    }
};
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = n & 1;
    for(int i = 1; i <= 31; ++i) {
      n >>= 1;
      result <<= 1;
      result = result | (n & 1);
    }
    return result;
  }
};
int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
