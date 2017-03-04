#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846
#define M_PI 3.14159265358979323846


int n, x, y, i, j, k, m, minAng, i1, i2;

double ang(double x, double y)
{
    double sin, cos, ang;

    if (x == 0)
    {
        if (y > 0) ang = M_PI/2;
        else ang = -M_PI/2;
    }
    else if (y == 0)
    {
        if (x > 0) ang = 0;
        else ang = M_PI;
    }
    else
    {
        ang = atan(abs(y/x));

        if (x > 0 && y > 0) ang = ang;
        if (x < 0 && y > 0) ang = M_PI - ang;
        if (x < 0 && y < 0) ang = -(M_PI - ang);
        if (x > 0 && y < 0) ang = -ang;

    }

//    return to_deg(ang);
}

double difAng(double a1, double a2)
{
    double ret = abs(a1-a2);

    if (ret > M_PI) ret = 360 - ret;

    return ret;
}

class cl
{
public:

    int x, y, idx;
    double angl;

    cl(int x, int y, int idx)
    {
        this->idx = idx;
        this->x = x;
        this->y = y;
        angl = ang(x, y);
    }

    cl(){};

    //int operator<(cl &ob);

    /*
    bool operator>(cl ob)
    {
        return this->angl > ob.angl;
    }
    */

};
;


vector<cl> ar;

bool cmpfunc(cl a, cl b)
{
    return a.angl < b.angl;
}



int main()
{


    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);

        ar.push_back(cl(x, y, i+1) );
    }


    sort(ar.begin(), ar.end(), cmpfunc);

    /*
    for (i = 0; i < n; i++)
    {
        printf("\n %d %d %d %lf\n", ar[i].idx, ar[i].x, ar[i].y, ar[i].angl);
    }
    */


    i1 = ar[0].idx;
    i2 = ar[n-1].idx;
    minAng = difAng(ar[0].angl, ar[n-1].angl);
    //printf("\n difference between %d & %d = %lf \n", i1, i2, difAng(ar[0].angl, ar[n-1].angl));

    for (i = 0; i < n-1; i++)
    {
        //printf("\n difference between %d & %d = %lf \n", ar[i].idx, ar[i+1].idx, difAng(ar[i].angl, ar[i+1].angl));

        if (difAng(ar[i].angl, ar[i+1].angl) < minAng)
        {
            i1 = ar[i].idx;
            i2 = ar[i+1].idx;
            minAng = difAng(ar[i].angl, ar[i+1].angl);
        }
    }

    printf("%d %d", i1, i2);

    return 0;
}
