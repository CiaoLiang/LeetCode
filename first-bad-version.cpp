// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0, end = n;
        n = start + (end - start) / 2;
        while (start != end) {
            if (isBadVersion(n))
                end = n;
            else
                start = n + 1;
            n = start + (end - start)/2;
        }
        return start;
    }
};