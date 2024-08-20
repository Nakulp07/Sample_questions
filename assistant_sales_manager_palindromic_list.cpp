#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Function to get the palindromic sales list
vector<int> palindromicSalesList(vector<int> salesData) {
    int start = 0;
    int end = salesData.size() - 1;
    vector<int> result;

    while (start <= end) {
        // Both values are same, so add to result
        if (salesData[start] == salesData[end]) {
            if (start != end) {
                result.push_back(salesData[start]);
            }
            start++;
            end--;
        }
        // Start value is smaller, so combine with next element
        else if (salesData[start] < salesData[end]) {
            start++;
            salesData[start] += salesData[start - 1];
        }
        // End value is smaller, so combine with previous element
        else {
            end--;
            salesData[end] += salesData[end + 1];
        }
    }

    // Create the final palindromic list
    vector<int> finalResult = result;
    if (start - 1 == end + 1 && salesData[start - 1] != result.back()) {
        finalResult.push_back(salesData[start - 1]);
    }
    for (int i = result.size() - 1; i >= 0; i--) {
        finalResult.push_back(result[i]);
    }

    return finalResult;
}

int main() {
    int salesData_size;
    cin >> salesData_size;
    vector<int> salesData(salesData_size);
    
    for (int &data : salesData) {
        cin >> data;
    }

    vector<int> result = palindromicSalesList(salesData);

    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << " ";
    }
    cout << result[result.size() - 1];
    
    return 0;
}