class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int current_sum = 0;
            while (num > 0) {
                current_sum += num % 10;
                num /= 10;
            }
            num = current_sum;
        }
        return num;
    }
};