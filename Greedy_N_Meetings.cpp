#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//!FINDING THE MAXIMUM NUMBER OF MEETINGS THAT CAN BE PERFORMED IN ONE ROOM


class Solution{
    public:
   static bool compare(pair<int,int> a, pair <int,int> b){
        return a.second < b.second;
    }

    int maxMeetings(int start[], int end[], int n){
        vector<pair<int, int> > v;
        for (int i = 0; i < n; i++){
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end(), compare);
        int count = 1;
        int ansEnd = v[0].second;

        for (int i = 1; i < n; i++){
            if(v[i].first>ansEnd){
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }
};
int main(){

    int n;
    cout << "Enter the number of schedules :" << endl;
    cin >> n;
    int start[n], end[n];
    cout << "Enter the  starting times of meeting :" << endl;
    for (int i = 0; i < n; i++){
        cin >> start[i];
    }
    cout << "Enter the  ending times of meeting :" << endl;
    for (int i = 0; i < n; i++){
        cin >> end[i];
    }

    Solution sol;
    int maximum_meetings=sol.maxMeetings(start, end, n);
    cout << "Total " << maximum_meetings << " can be performed in that room" << endl;

    return 0;
}