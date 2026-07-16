#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> getOrder(vector<vector<int>>& tasks) {

    int n = tasks.size();

    vector<vector<int>> arr;

    // Store {enqueueTime, processingTime, originalIndex}
    for (int i = 0; i < n; i++) {
        arr.push_back({tasks[i][0], tasks[i][1], i});
    }

    sort(arr.begin(), arr.end());

    // Min Heap -> {processingTime, index}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> ans;

    long long currentTime = 0;
    int i = 0;

    while (i < n || !pq.empty()) {

        if (pq.empty()) {
            currentTime = max(currentTime, (long long)arr[i][0]);
        }

        while (i < n && arr[i][0] <= currentTime) {
            pq.push({arr[i][1], arr[i][2]});
            i++;
        }

        auto task = pq.top();
        pq.pop();

        int processingTime = task.first;
        int index = task.second;

        ans.push_back(index);

        currentTime += processingTime;
    }

    return ans;
}

int main() {

    vector<vector<int>> tasks = {
        {1, 2},
        {2, 4},
        {3, 2},
        {4, 1}
    };

    vector<int> order = getOrder(tasks);

    cout << "Order of execution: ";

    for (int x : order) {
        cout << x << " ";
    }

    return 0;
}