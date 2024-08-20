/* A prime number is divisible only by 1 and itself. The teacher writes a positive integer on the board. Write an algorithm
to find all the prime numbers from 2 to the given positive number.*/

// Header Files
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * num, representing the number written on the board.
 */
bool checkPrime(int num)
{
    if (num == 1 || num == 0)
        return false;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
vector<int> calculatePrimeNumbers(int num)
{
    vector<int> answer;
    // Write your code here
    for (int i = 2; i <= num; i++)
    {
        bool flag = checkPrime(i);
        if (flag)
            answer.push_back(i);
    }
    return answer;
}
int main()
{
    // input for num
    int num;
    cin >> num;
    // output
    vector<int> result = calculatePrimeNumbers(num);
    for (int idx = 0; idx < result.size() - 1; idx++)
    {
        cout << result[idx] << " ";
    }
    cout << result[result.size() - 1];
    return 0;
}