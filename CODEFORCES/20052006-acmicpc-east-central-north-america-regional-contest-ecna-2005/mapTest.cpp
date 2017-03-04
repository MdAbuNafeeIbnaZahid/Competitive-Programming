#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;


int main()
{
    string str;

    map<string, int> m;

    m.insert(make_pair("a", 1));
    m.insert(make_pair("b", 2));
    m.insert(make_pair("c", 3));
    m.insert(make_pair("d", 4));
    m.insert(make_pair("e", 5));



    while(1)
    {
        cin >> str;
        cout << m[str] << "\n\n\n\n";
    }

    return 0;
}
