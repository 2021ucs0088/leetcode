class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        if (n == 0) return days; // Check for empty meetings list

        // Sort meetings based on end time
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> event;
        event.push_back(meetings[0]);

        for (int i = 1; i < n; i++) {
            if (meetings[i][0] > event.back()[1]) {
                event.push_back(meetings[i]);
            } else if(event.back()[0]>meetings[i][0]) {
                event.back()[0]=min(meetings[i][1],event.back()[1]);
                event.back()[1] = max(meetings[i][1], event.back()[1]);
            }
            else{
                event.back()[1] = max(meetings[i][1], event.back()[1]);

            }
        }

        int total = 0;
        for (const auto& ele : event) {
            total += ele[1] - ele[0] + 1;
        }

        return days - total;
    }
};
