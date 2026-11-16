class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        map<int, int> cardFreq;
        for (int card : hand) {
            cardFreq[card]++;
        }
        for (auto [card, freq] : cardFreq) {
            if (freq == 0) continue;
            for (int i = 0; i < groupSize; i++) {
                if (!cardFreq.count(card + i)) return false;
                cardFreq[card + i] -= freq;
                if (cardFreq[card + i] < 0) return false;
                // if (cardFreq[card + i] == 0) cardFreq.erase(card + i);
            }
        }
        return true;
    }
};
