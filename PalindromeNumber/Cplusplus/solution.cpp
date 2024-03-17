class Solution {
public:
    bool isPalindrome(int x) {
        std::string num = std::to_string(x);
        int size = num.size();

        for (int i = 0; i < size/2; i++) {
            if (num[i] != num[size-i-1]) {
                return false;
            }
        }
        return true;
    }
};