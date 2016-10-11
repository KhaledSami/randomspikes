class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int a1 = a ^ b;
            int b1 = (a & b) << 1;
            a = a1;
            b = b1;
        }
        return a;
    }
};
