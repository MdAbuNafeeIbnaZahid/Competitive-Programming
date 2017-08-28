#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

//#define WIN
#ifdef WIN
typedef __int64 LL;
#define iform "%I64d"
#define oform "%I64d\n"
#define oform1 "%I64d"
#else
typedef long long LL;
#define iform "%lld"
#define oform "%lld\n"
#define oform1 "%lld"
#endif

#define S64I(a) scanf(iform, &(a))
#define P64I(a) printf(oform, (a))
#define P64I1(a) printf(oform1, (a))
#define REP(i, n) for(int (i)=0; (i)<n; (i)++)
#define REP1(i, n) for(int (i)=1; (i)<=(n); (i)++)
#define FOR(i, s, t) for(int (i)=(s); (i)<=(t); (i)++)

const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const double PI = (4.0*atan(1.0));

const int maxn = 100 + 20;
vector<int> prevv[maxn];
int son[maxn];

typedef double Matrix[maxn][maxn];


void gaussJordan(Matrix A, int n) {
    for(int i=0; i<n; i++) {
        int r = i;
        for(int j=i+1; j<n; j++) if(fabs(A[j][i]) > fabs(A[r][i]))
            r = j;
        if(fabs(A[r][i]) < eps) continue;
        if(r != i) for(int j=0; j<=n; j++) swap(A[r][j], A[i][j]);
        for(int k=0; k<n; k++) if(k != i) {
            for(int j=n; j>=i; j--) A[k][j] -= A[k][i] / A[i][i] * A[i][j];
        }
    }
}

Matrix A;
int inf[maxn];

void printGausAr( Matrix toPr, LL siz )
{
    LL a, b, c, d, e;
    for (a = 0; a < siz; a++)
    {
        for ( b = 0; b <= siz; b++ )
        {
            cout << toPr[a][b] << " ";
        }
        cout << endl;
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int kase = 1;

    while(scanf("%d", &n) != EOF && n) {
        int a, b;
        for(int i=0; i<n; i++) prevv[i].clear();
        memset(son, 0, sizeof(son));
        while(scanf("%d%d", &a, &b) == 2 && (a || b)) {
            a--, b--;
            prevv[b].push_back(a);
            son[a]++;
        }
        memset(A, 0, sizeof(A));
        for(int i=0; i<n; i++) {
            A[i][i] = 1;
            int sz = prevv[i].size();
            for(int j=0; j<sz; j++) {
                int v = prevv[i][j];
                A[i][v] -= 1.0 / son[v];
            }
        }
        A[0][n] = 1;
        printGausAr(A, n);
        cout << endl;
        gaussJordan(A, n);
        printGausAr( A, n );
        cout << endl;
        memset(inf, 0, sizeof(inf));
        for(int i=n-1; i>=0; i--) {
            if(fabs(A[i][i]) < eps && fabs(A[i][n]>eps)) inf[i] = 1;
            for(int j=i+1; j<n; j++)
                if(fabs(A[i][j]) > eps && inf[j]) inf[i] = 1;
        }
        int Q;
        scanf("%d", &Q);
        printf("Case #%d:\n", kase++);
        while(Q--) {
            int u;
            scanf("%d", &u); u--;
            if(inf[u]) puts("infinity");
            else printf("%.3lf\n", fabs(A[u][u]) < eps ? 0 : A[u][n] / A[u][u]);
        }
    }

    return 0;
}
