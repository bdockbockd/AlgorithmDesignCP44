#include <iostream>
#include <vector>
using namespace std;
int times;

void sw(int *a, pair<int, int> pos)
{
    // cout << "times : " << times;
    times--;
    if (times <= 0)
    {
        return;
    }
    if (pos.second == pos.first + 1)
    {
        return;
    }
    int mid = (pos.first + pos.second) / 2;
    int med = a[mid];
    a[mid] = a[mid - 1];
    a[mid - 1] = med;

    sw(a, make_pair(pos.first, mid));
    sw(a, make_pair(mid, pos.second));
}

int main()
{
    int count;
    cin >> count;
    cin >> times;
    if ((times % 2 == 0) || times > 2 * count - 1)
    {
        cout << -1;
        return 0;
    }
    int a[count];
    for (int i = 0; i < count; i++)
    {
        a[i] = i + 1;
    }
    times -= 1;
    sw(a, make_pair(0, count));
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
    }
}