class Solution {
public:
    int maxArea(vector<int> &h) {

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);

        int n = (int)h.size();
        int ans = 0, ptr1 = 0, ptr2 = n - 1;
        while(ptr1 < ptr2) {
            ans = max(ans, min(h[ptr1], h[ptr2]) * (ptr2 - ptr1));
            if(h[ptr1] < h[ptr2]) {
                ptr1++;
            } else if(h[ptr2] < h[ptr1]) {
                ptr2--;
            } else {
                ptr1++; ptr2--;
            }
        }

        return ans;

    }
};w