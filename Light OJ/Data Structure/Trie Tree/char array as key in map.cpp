#include <bits/stdc++.h>
using namespace std;
#define SIZE 500
char strAr[SIZE][SIZE];
long long a, b, c, d, e, f, g, h;
struct myString
{
    char str[109];
    myString(){}
    myString(char *str)
    {
        strcpy(this->str, str);
    }
    const bool operator<(myString b) const
    {
        return strcmp( this->str, b.str ) < 0;
    }
};
map<myString, long long> myMap;
int main()
{
    freopen("input.txt", "r", stdin);
    for (a = 1; a <= 7; a++)
    {
        scanf("%s", strAr[1]);
        cout << "strAr[1] = " << strAr[1] << endl;
        myMap[ myString(strAr[1]) ]++;
        cout << "myMap[ myString(strAr[a]) ] = " << myMap[ myString(strAr[1]) ] << endl;
        cout << "myMap.size() = " << myMap.size() << endl;
        getchar();
    }
    return 0;
}
