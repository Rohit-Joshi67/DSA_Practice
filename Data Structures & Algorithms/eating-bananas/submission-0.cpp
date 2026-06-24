class Solution {
public:

    int calculateHours(vector<int>& piles, int speed)
    {
        int totalHours = 0;

        for(int i = 0; i < piles.size(); i++)
        {
            totalHours += ceil((double)piles[i] / speed);
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        int maxi = piles[0];

        for(int i = 1; i < piles.size(); i++)
        {
            maxi = max(maxi, piles[i]);
        }

        int left = 1;
        int right = maxi;

        while(left < right)
        {
            int mid = left + (right - left) / 2;

            int totalHours = calculateHours(piles, mid);

            if(totalHours > h)
            {
                // speed is too slow
                left = mid + 1;
            }
            else
            {
                // speed works, try smaller speed
                right = mid;
            }
        }

        return left;
    }
};