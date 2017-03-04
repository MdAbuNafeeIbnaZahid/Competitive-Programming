#include <bits/stdc++.h>
using namespace std;

int w, h, i, j, ans = 1, a, b, c, d, row, column, cr, cc;
string room[15][15];
char input[15][15];


class coOrd
{
public:
    int x, y;
    char c;
};

bool ifOk(coOrd ob)
{
    if (ob.x < 0 || ob.x >= h) return false;
    if (ob.y < 0 || ob.y >= w) return false;
    if ( count(room[ob.y][ob.x].begin(), room[ob.y][ob.x].end(), '*') > 0) return false;

    return true;
}

bool ifFatal(coOrd ob)
{
	if ( count(room[ob.y][ob.x].begin(), room[ob.y][ob.x].end(), ob.c) > 0) return true;
	return false;
}

coOrd operator+(coOrd ob, char c)
{
    ob.c = c;
    if (c == 'U')
    {
        ob.y++;
//        room[ob.y][ob.x] += "U";
    }

    else if (c == 'D')
    {
        ob.y--;
//        room[ob.y][ob.x] += "D";
    }

    else if (c == 'R')
    {
        ob.x++;
//        room[ob.y][ob.x] += "R";
    }

    else if (c == 'L')
    {
        ob.x--;
//        room[ob.y][ob.x] += "L";
    }

    return ob;
}

char transChar(char c)
{
    if (c == 'U')
    {
        return 'R';
    }

    else if (c == 'R')
    {
        return 'D';
    }

    else if (c == 'D')
    {
        return 'L';
    }

    else if (c == 'L')
    {
        return 'U';
    }

    return 'Z';
}



int main()
{
    int x, y, z, a,b, c, i, j, k;
    char str[10], ch;
    coOrd current;
    scanf("%d %d", &w, &h);
//    cout << "\n w = " << w << ", h = " << h << "\n";
    for (y = w-1; y >= 0; y--)
    {
    	scanf("%s", input[y]);
        //getchar();
        //for (x = 0; x < h; x++)
        {

            //room[y][x].push_back(ch);
            /*
            if ( (room[y][x] != "*") && (room[y][x] != ".") )
            {
                current.y = y;
                current.x = x;
                current.c = ch;
            } */
        }
    }

    for (y = w-1; y >= 0; y--)
    {
        for (x = 0; x < h; x++)
        {
       		room[y][x].push_back(input[y][x]);

            if ( (room[y][x] != "*") && (room[y][x] != ".") )
            {
                current.y = y;
                current.x = x;
                current.c = input[y][x];
            }
        }
    }

	/*
    cout << "\n";
    for (y = w-1; y >= 0; y--)
    {
        for (x = 0; x < h; x++)
        {
            cout << room[y][x];
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "\n x = " << current.x << ", y = " << current.y << "\n";

    */
    k = 0;

    while(1)
    {

      //  cout << "\n " << (current+current.c).x << ", " << (current+current.c).y << "\n";
        while( ifOk(current+current.c) )
        {
            current = current + current.c;
            if( ifFatal(current) )
            {
            	printf("%d", ans);
            	return 0;
            }
            if (room[current.y][current.x] == ".") ans++;
        //    cout << "\n x= " << current.x << ", y= " << current.y << "\n";
            room[current.y][current.x].push_back(current.c);
//            cout << "\n pos 2 \n";
        }

            for (k = 1; k <= 6; k++)
            {
                current.c = transChar(current.c);
                if( ifOk(current+current.c) ) break;
            }

            if (k > 6) break;
    }


    printf("%d", ans);

    return 0;
}

