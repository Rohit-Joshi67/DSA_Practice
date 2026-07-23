/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())
        return 0;
         sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

             //sorted the intervals

             priority_queue<int,vector<int>,greater<int>> minHeap;
                minHeap.push(intervals[0].end);  //pushing first into the heap

                for(int i=1;i<intervals.size();i++) {   // traversing the array
                    if(intervals[i].start>=minHeap.top()) {  //compare current start time with min end time
                        minHeap.pop();
                    }

                    minHeap.push(intervals[i].end);
                }
        return minHeap.size();
    }
};
