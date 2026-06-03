class MedianFinder {
private:

    // Left half store karega
    // Largest element top pe rahega
    priority_queue<int> maxHeap;

    // Right half store karega
    // Smallest element top pe rahega
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:

    MedianFinder() {
        // Kuch initialize karne ki zarurat nahi
    }

    void addNum(int num) {

        // -------------------------------------------------
        // STEP 1:
        // Decide karo number kis heap me jana chahiye
        // -------------------------------------------------

        // Agar left side empty hai
        // ya num left side ke largest element se chota hai,
        // toh left half me bhej do.
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        // -------------------------------------------------
        // STEP 2:
        // Heaps ko balance karo
        //
        // Rule:
        // Size difference 1 se zyada nahi hona chahiye.
        // -------------------------------------------------

        // Left side bahut bada ho gaya
        if (maxHeap.size() > minHeap.size() + 1) {

            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Right side bada ho gaya
        else if (minHeap.size() > maxHeap.size()) {

            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {

        // -------------------------------------------------
        // Case 1:
        // Total elements odd hain
        //
        // Median = left heap ka top
        // -------------------------------------------------
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        // -------------------------------------------------
        // Case 2:
        // Total elements even hain
        //
        // Median = middle 2 values ka average
        // -------------------------------------------------
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};