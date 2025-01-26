class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return (104 - purchaseAmount) / 10 * 10;
    }
};