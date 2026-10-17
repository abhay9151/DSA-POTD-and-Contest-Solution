class Solution {
    long long calsum(int num) {
        long long sum = 0;
        while(num > 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<long long, int>> arr;
        vector<int> original = nums;
        int count = 0;
        for(int i = 0; i < n; i++) {
            arr.push_back({calsum(nums[i]), i});
        }
        sort(arr.begin(), arr.end(), [&](const auto& a, const auto& b) {
            if(a.first == b.first) {
                return original[a.second] < original[b.second];
            }
            return a.first < b.first;
        });
        unordered_map<int, int> valToIdx;
        for(int i = 0; i < n; i++) {
            valToIdx[nums[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            int expectedVal = original[arr[i].second];
            int currVal = nums[i];
             if(expectedVal == currVal) continue;
             int idx = valToIdx[expectedVal];
             swap(nums[i], nums[idx]);
            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;
            count++;
        }

        return count;
    }
};