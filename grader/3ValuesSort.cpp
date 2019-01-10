#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int timesSwap;

int swapData(int val, int Da, pair<int, int> Pair, int *arr, int si)
{
    cout << "---------------------------------" << endl;
    cout << "Find value " << val;
    cout << " for putting in range of " << Pair.first << " , " << Pair.second << endl;
    for (int i = 0; i <= si; i++)
    {
        if (i >= Pair.first && i <= Pair.second)
        {
            continue;
        }
        if (arr[i] == val)
        {
            cout << "index " << i << " not appropiate val " << arr[i] << endl;
            arr[i] = Da;
            cout << "index " << i << " now appropiage had been changed to" << arr[i] << endl;
            timesSwap++;
            // cout << "change return" << change << endl;
            return val;
        }
    }
    return 0;
}

int main()
{
    int number;
    cin >> number;
    int data[number];
    map<int, int> numberOfEachType;
    pair<int, int> pairBound[4];
    pair<int, int> putData[3];
    putData[0] = make_pair(2, 3);
    putData[1] = make_pair(1, 3);
    putData[2] = make_pair(1, 2);
    for (int round = 0; round < number; round++)
    {
        int dataa;
        cin >> dataa;
        data[round] = dataa;
        numberOfEachType[dataa]++;
    }
    pairBound[1] = make_pair(numberOfEachType[0],
                             numberOfEachType[1] - 1);
    pairBound[2] = make_pair(numberOfEachType[1],
                             numberOfEachType[1] + numberOfEachType[2] - 1);
    pairBound[3] = make_pair(numberOfEachType[1] + numberOfEachType[2],
                             numberOfEachType[1] + numberOfEachType[2] + numberOfEachType[3] - 1);

    for (int val = 1; val <= 3; val++)
    {
        for (int i = pairBound[val].first; i <= pairBound[val].second; i++)
        {
            if (data[i] == putData[val - 1].first)
            {
                cout << "changing data index " << i << " val " << data[i] << endl;
                data[i] = swapData(val, data[i], pairBound[val], data, number);
                cout << "changed Data index " << i << " val " << data[i] << endl;
            }
            else if (data[i] == putData[val - 1].second)
            {
                cout << "changing data index " << i << " val " << data[i] << endl;
                data[i] = swapData(val, data[i], pairBound[val], data, number);
                cout << "changed Data index " << i << " val " << data[i] << endl;
            }
        }
    }
    cout << "timesSwap is " << timesSwap << endl;

    return 0;
}