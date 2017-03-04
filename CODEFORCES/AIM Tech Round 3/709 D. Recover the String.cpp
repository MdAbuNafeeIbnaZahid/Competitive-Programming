#include <bits/stdc++.h>
using namespace std;
long long a00, a01, a10, a11;
long long c0, c1, b01, len;
string str0, str1, ansStr;
long long a, b, c, d, e, f, g;
int main()
{
    cin >> a00 >> a01 >> a10 >> a11;
    if (a00==0 && a11==0)
    {
        c0 = 1;
        c1 = 1;
        if ( a01+a10 == c0*c1 )
        {
            if (a01==1) cout << "01";
            else if (a10==1) cout << "10";
            return 0;
        }

        c0 = 1;
        c1 = 0;
        if (a01+a10 == 0)
        {
            cout << "0";
            return 0;
        }

        c0 = 0;
        c1 = 1;
        if(a01+a10 == c0*c1)
        {
            cout << "1";
            return 0;
        }

        cout << "Impossible";
        return 0;

//        c0=0;
//        c1=0;
//        if ( a01+a10 == c0*c1 )
//        {
//            cout << "Impossible";
//            return 0;
//        }
//
//
    }
    else if (a00==0)
    {
        for (a = 2; (a*(a-1) )/2 < a11; a++){}
        if ( (a*(a-1) )/2 !=  a11)
        {
            cout << "Impossible";
            return 0;
        }
        c1 = a;
        //cout << "c1 = " << c1 << endl;

        c0 = 0;
        if ( a01+a10 == c0*c1 )
        {
            for (b = 1; b <= c1; b++)
            {
                printf("1");
            }
            return 0;
        }

        c0 = 1;
        if ( a01+a10 == c0*c1 )
        {
            for (b = 1; b <= a10; b++) printf("1");
            cout << 0;
            for (b = 1; b <= a01; b++) printf("1");
            return 0;
        }

        cout << "Impossible";
        return 0;
    }
    else if (a11==0)
    {
        for (b = 2; (b*(b-1) )/2 < a00; b++ ){}
        if ( (b*(b-1) )/2 != a00 )
        {
            cout << "Impossible";
            return 0;
        }
        c0 = b;

        c1 = 0;
        if (a01+a10 == c0*c1)
        {
            for (b = 1; b <= c0; b++)
            {
                printf("0");
            }
            return 0;
        }

        c1 = 1;
        if(a01+a10==c0*c1)
        {
            for (b = 1; b <= a01; b++) printf("0");
            cout << 1;
            for (b = 1; b <= a10; b++) printf("0");
            return 0;
        }

        cout << "Impossible";
        return 0;
    }

    else
    {
        for (c0 = 2; (c0*(c0-1) )/2 < a00; c0++ ){}
        //cout << "c0 = " << c0 << endl;
        if ( (c0*(c0-1) )/2 != a00 )
        {
//            cout << "c0 not matching " << endl;
//            cout <<
            cout << "Impossible";
            return 0;
        }

        for (c1 = 2; (c1*(c1-1) )/2 < a11; c1++ ){}
        //cout << "c1 = " << c1 << endl;
        if ( (c1*(c1-1) )/2 != a11 )
        {
            cout << "Impossible";
            return 0;
        }

        if ( a01+a10 != c0*c1 )
        {
            cout << "Impossible";
            return 0;
        }
        else if ( a01+a10 == c0*c1 )
        {
            str0 = "";
            str1 = "";
            for (d = 1; d <= c0; d++) str0 += "0";
            for (d = 1; d <= c1; d++) str1 += "1";
            b01 = c0*c1;
            while(b01-a01 >= c1)
            {
                //cout << "b01 = " << b01 << endl;
                len = str0.size();
                str0.erase( len-1 );
                //cout << "erased" << endl;
                str1 += "0";
                b01 -= c1;
            }
            if ( b01-a01 > 0 )
            {
                len = str0.size();
                str0.erase( len-1 );
                cout << str0;
                for (d = 0; d < (b01-a01); d++) printf("%c", str1[d]);
                cout << 0;
                for (d = (b01-a01); d < str1.size(); d++) printf("%c", str1[d]);
            }
            else
            {
                cout << str0 << str1;
            }
//            cout << str0;
//            for (d = 0; d < (b01-a01); d++) printf("%c", str1[d]);
//            if ( (b01-a01) > 0) cout << 0;
//            for (d = b01; d < str1.size(); d++) printf("%c", str1[d]);
            return 0;
        }
    }

    cout << "Impossible";
    return 0;

    return 0;
}
