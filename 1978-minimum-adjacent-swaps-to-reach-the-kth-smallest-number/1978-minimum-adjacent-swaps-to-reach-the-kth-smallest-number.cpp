class Solution {
public:
    int getMinSwaps(string num, int k) {
        string original = num;

        // Generate the k-th permutation
        while (k > 0) {
            func(num);
            k--;
        }

        // Count the minimum number of adjacent swaps needed
        return countMinSwaps(original, num);
    }

    void func(string &num) {
        int n = num.size();
        int i = n - 2;

        // Find the rightmost `i` such that num[i] < num[i+1]
        while (i >= 0 && num[i] >= num[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            // Find the smallest number greater than num[i] to the right of `i`
            while (num[j] <= num[i]) {
                j--;
            }
            // Swap num[i] and num[j]
            swap(num[i], num[j]);
        }
        reverse(num.begin() + i + 1, num.end());
    }

    int countMinSwaps(string original, string target) {
        int swaps = 0;
        int n = original.size();

        for (int i = 0; i < n; i++) {
            if (original[i] != target[i]) {
                int j = i;
                while (original[j] != target[i]) {
                    j++;
                }
                while (j > i) {
                    swap(original[j], original[j - 1]);
                    j--;
                    swaps++;
                }
            }
        }

        return swaps;
    }
};
