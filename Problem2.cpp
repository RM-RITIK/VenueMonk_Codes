#include <iostream>

using namespace std;

long long countWays(int arr[], int m, int N)
{
    long long count[N + 1];
    memset(count, 0, sizeof(count));

    count[0] = 1;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < m; j++)
            if (i >= arr[j])
                count[i] += count[i - arr[j]];

    return count[N];

}

int main()
{
    int arr[] = {10, 20, 50, 100, 200, 500, 1000, 2000};
    int m = sizeof(arr) / sizeof(arr[0]);
    int N = 2000;
    cout << "Total number of ways = "
        << countWays(arr, m, N);
    return 0;
}