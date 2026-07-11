class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        sort(hand.begin(),hand.end());
        unordered_map<int,int> cards;
        for(int i : hand ){
            cards[i]++;
        }
        for(auto& card: hand){
            if(cards[card]==0) continue;

            for(int i = card ; i<card+groupSize ; i++){
                if(cards[i]==0){
                    return false;
                }
                
                cards[i]--;
            }
        }
        return true;
    }
};
