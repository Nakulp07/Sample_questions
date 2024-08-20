#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

float waitingTime(vector<int> req, vector<int> dur) {
    int n = req.size();
    vector<pair<int, int>> tasks;
    for (int i = 0; i < n; i++) {
        tasks.push_back({req[i], dur[i]});
    }
    
    // Sort tasks by their request time
    sort(tasks.begin(), tasks.end());
    
    // Min-heap to prioritize by duration, with tie-breaking by request time
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    int currentTime = 0;
    int totalWaitingTime = 0;
    int taskIndex = 0;
    
    while (taskIndex < n || !pq.empty()) {
        // Push all tasks that have arrived by currentTime into the min-heap
        while (taskIndex < n && tasks[taskIndex].first <= currentTime) {
            pq.push({tasks[taskIndex].second, tasks[taskIndex].first});
            taskIndex++;
        }
        
        if (!pq.empty()) {
            pair<int, int> currentTask = pq.top();
            pq.pop();
            int duration = currentTask.first;
            int requestTime = currentTask.second;
            currentTime += duration;
            totalWaitingTime += (currentTime - requestTime - duration);
        } else if (taskIndex < n) {
            // If no tasks in the queue, jump to the next task's request time
            currentTime = tasks[taskIndex].first;
        }
    }
    
    return (float)totalWaitingTime / n;
}

int main() {
    int req_size;
    cin >> req_size;
    vector<int> req(req_size);
    for (int i = 0; i < req_size; i++) {
        cin >> req[i];
    }

    int dur_size;
    cin >> dur_size;
    vector<int> dur(dur_size);
    for (int i = 0; i < dur_size; i++) {
        cin >> dur[i];
    }

    float result = waitingTime(req, dur);
    cout << result;

    return 0;
}
