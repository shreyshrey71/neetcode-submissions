class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> spaceTime;
        for(int i=0;i<position.size();i++){
            spaceTime.push_back({position[i], (float) (target-position[i])/speed[i]});
        }
        std::sort(spaceTime.rbegin(), spaceTime.rend());
        int fleetCount = 0;
        float lastFleetTime = -1.0;
        for(int i=0; i<spaceTime.size();i++){
            if(spaceTime[i].second > lastFleetTime){
                lastFleetTime = spaceTime[i].second;
                fleetCount++;
            }
        }
        return fleetCount;
    }
};
