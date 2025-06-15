class Solution {
public:
    typedef long long ll;  // Define 'll' as alias for 'long long' to handle large integer differences

    int numberOfArithmeticSlices(vector<int>& nums) {
        // 'v[i]' stores a map where key is 'difference' and value is 'count of subsequences ending at i with that difference'
        vector<unordered_map<ll, int>> v(nums.size());

        ll ans = 0; // To store the total count of valid arithmetic subsequences of length >= 3

        // Iterate through each pair of indices (j, i) where j < i
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {

                // Calculate the difference between nums[i] and nums[j]
                ll diff = ll(nums[i]) - ll(nums[j]);

                // Add the number of subsequences ending at index 'j' with difference 'diff' to the answer
                ans += v[j][diff];  // Only subsequences of length >= 2 can be extended to form valid sequences

                // Add one to count the new pair (nums[j], nums[i]) as a subsequence of length 2
                v[i][diff]++;

                // Also include all subsequences from 'j' ending with the same diff to 'i'
                v[i][diff] += v[j][diff];
            }
        }

        // Return total number of arithmetic subsequences of length >= 3
        return ans;
    }
};
