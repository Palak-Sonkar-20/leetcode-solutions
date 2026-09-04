/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInData;
    unordered_map<string, pair<int, int>> trips;

    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        string startStation = checkInData[id].first;
        int startTime = checkInData[id].second;

        int travelTime = t - startTime;

        string route = startStation + "-" + stationName;

        trips[route].first += travelTime;
        trips[route].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "-" + endStation;

        int totalTime = trips[route].first;
        int totalTrips = trips[route].second;

        return (double)totalTime / totalTrips;
    }
};


/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

