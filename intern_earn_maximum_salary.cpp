/*An intern has an internship at a company for N days. Each day they may choose either an easy task or a difficult task.
They may also choose to perform no task at all. They only choose a difficult task on days when they did not perform
any work the previous day. The amount paid by the company for both the easy and difficult tasks can vary each day,
but the company always pays more for difficult tasks.
Write an algorithm to help the intern earn the maximum salary.*/

// Header Files
#include <bits/stdc++.h>
using namespace std;
/*
* tasksStipend is a grid where each row represents the stipends fo
r easy task and difficult task for a day.
*/
int solve(vector<vector<int>> t, int curr, int prev, map<pair<int, bool>, int> &dp)
{
    if (curr >= t.size())
        return 0;
    if (prev == curr - 1 && dp.find({curr, false}) != dp.end())
        return dp[{curr,false}];
    else if (prev != curr - 1 && dp.find({curr, true}) != dp.end())
        return dp[{curr, true}];

    int notPick = solve(t, curr + 1, prev, dp);
    int pick = t[curr][0] + solve(t, curr + 1, curr, dp);
    int noTask = 0;

    if (prev != curr - 1)
        noTask = t[curr][1] + solve(t, curr + 1, curr, dp);
    if (prev == curr - 1)
        dp[{curr, false}] = max({pick, notPick, noTask});
    else if (prev != curr - 1)
        dp[{curr, true}] = max({pick, notPick, noTask});
        
    return max({pick, notPick, noTask});
}
int maxSalary(vector<vector<int>> tasksStipend)
{
    int answer;
    // Write your code here
    map<pair<int, bool>, int> dp;
    answer = solve(tasksStipend, 0, -2, dp);
    return answer;
}
int main()
{
    // input for tasksStipend
    int tasksStipend_row;
    int tasksStipend_col;
    cin >> tasksStipend_row;
    cin >> tasksStipend_col;
    vector<vector<int>> tasksStipend;
    for (int idx = 0; idx < tasksStipend_row; idx++)
    {
        vector<int> temp_vector;
        for (int jdx = 0; jdx < tasksStipend_col; jdx++)
        {
            int temp;
            cin >> temp;
            temp_vector.push_back(temp);
        }
        tasksStipend.push_back(temp_vector);
    }
    int result = maxSalary(tasksStipend);
    cout << result;
    return 0;
}