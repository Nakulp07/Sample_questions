// Header Files
#include<bits/stdc++.h>
using namespace std;

/*
 * 
 */
int workingWeeks (vector<int> projC)
{
    int  answer;

    int sum = 0;
    for(int c : projC) sum += c;
    
    // Find the maximum number of modules in any single project
    int max1 = *max_element(projC.begin(), projC.end());
    
    // Calculate and return the maximum number of weeks
    if(max1 <= (sum - max1)) {
        answer = sum;
    } else {
        answer = ( 2 * (sum - max1) + 1);
    }

    return answer;
}

int main()
{
    
	//input for projC
	int projC_size;
	cin >> projC_size;
	vector<int> projC;
	for ( int idx = 0; idx < projC_size; idx++ )
	{
		int temp;
		cin >> temp;
		projC.push_back(temp);
	}
	
    int result = workingWeeks(projC);
	cout << result;
	
	
    return 0;
}