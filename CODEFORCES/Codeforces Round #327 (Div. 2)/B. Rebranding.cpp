#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m, i, j, k;
    map<char, char> Map, Map2;
    int ar1[300] = {0}, ar2[300] = {0};
    char ar[200009], x, y;
//    for (i = 0; i < 26; i++)
//    {
//        Map.insert(pair<char, char>('a'+i, 'a'+i));
//    }

    for (i = 'a'; i <= 'z'; i++)
    {
        ar1[i] = i;
    }

    map<char, char>::iterator it;


    scanf("%d %d", &n, &m);
    scanf("%s", ar);

//    printf("\n %s \n", ar);
    for (i = 1; i <= m; i++)
    {
        getchar();
        scanf("%c %c", &x, &y);

        int temp = ar1[(int)x];
        ar1[(int)x] = ar1[(int)y];
        ar1[(int)y] = temp;
//        char temp = Map[x];
//        Map[x] = Map[y];
//        Map[y] = temp;
//        printf("\n %c %c \n", x, y);
//        for (it = Map.begin(); it != Map.end(); it++)
//        {
//            if (it->second == x) it->second = y;
//            else if (it->second == y) it->second = x;
//        }
    }

//    cout << "\n";
//    for (i = 'a'; i <= 'z'; i++)
//    {
//        cout << "\n " << (char)i << " " << (char)ar1[i] << "\n";
//    }
//    cout << "\n";

//    cout << "\n pos 1\n";



//    for (it = Map.begin(); it != Map.end(); it++)
//    {
//        Map2.insert(pair<char, char>(it->second, it->first));
//    }

    for (i = 'a'; i <= 'z'; i++)
    {
        ar2[ (int)ar1[(int)i] ] = i;
    }

//    cout << "\n";
//    for (i = 'a'; i <= 'z'; i++)
//    {
//        cout << "\n " << (char)i << " " << (char)ar2[i] << "\n";
//    }
//    cout << "\n";

    for (i = 0; i < n; i++)
    {
//        cout << "\n " << i << " " << *(ar+i) << " later " ;
//        int idx = *(ar+i);
        *(ar+i) = (char)ar2[ (int)(*(ar+i) )];
//        cout << *(ar+i) << " \n";
    }

    printf("%s", ar);

    return 0;
}
