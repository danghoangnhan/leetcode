// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int lo = 1, hi = n;
        long long int mid;
        while (hi - lo > 1) {
            mid = (hi + lo) / 2;
            if (isBadVersion(mid)==false) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        if (isBadVersion(lo)) {
            return lo;
        }
        else return hi;
    }
};
