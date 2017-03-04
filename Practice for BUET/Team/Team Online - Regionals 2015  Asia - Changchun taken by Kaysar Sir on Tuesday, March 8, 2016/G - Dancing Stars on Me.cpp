#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long int a,b,c,d,e,i,j,sum=0,s;
double p,q;
long long int x[100002];
struct node
{
    long long int x;
    long long int y;
    long long int z;
    double r;
    node(){}
    node(long long int x, long long int y, long long int z, double r = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
    }
}cam[100002];
vector<node> vec;
bool compAngle(node a,node b)
{
    if(a.r!=b.r)
        return a.r<b.r;
        return (a.x-d)*(a.x-d)+(a.y-e)*(a.y-e)<(b.x-d)*(b.x-d)+(b.y-e)*(b.y-e);
        //return a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;
}
bool compLeftDown(node a, node b)
{
    if (a.y<b.y) return true;
    if (a.y==b.y) return a.x<b.x;
}
int main()
{
    cin>>a;
    for(i=0;i<a;i++)
    {
        cin >> b >> c;
        vec.push_back( node(b, c, i+1) );
    }
    sort(vec.begin(), vec.end(), compLeftDown );
    d = vec[0].x;
    e = vec[0].y;
    vec[0].r = 0;
    s = vec.size();
    for (i = 1; i < s; i++)
    {
        vec[i].r = (double)atan( (double)(vec[i].x-d)/(vec[i].y-e) );
    }
    sort(vec.begin(), vec.end(), compAngle )
    for (i = 0; i < s; i++)
    {
        cout << vec[i].x << " " << vec[i].y << endl;
    }
    return 0;
}
