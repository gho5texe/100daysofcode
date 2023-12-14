class Solution {
public:
    int pivotInteger(int n) {
        int ans;
        if(n==1) return 1;
        ans = n*(n+1)/2;
        if (ceil((double)sqrt(ans)) == floor((double)sqrt(ans))) return sqrt(ans);
        else return -1;
    }
};