#include <iostream>
using namespace std;
void TOH(int n, char source, char aux, char dest)
{
    if (n == 0)
        return;
    TOH(n - 1, source, dest, aux);
    cout << n << "moved from " << source << "to" << dest;
    TOH(n - 1, aux, source, dest);
}
void main()
{
    TOH(3, 'A', 'B', 'C');
}