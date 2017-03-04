#include <bits/stdc++.h>
using namespace std;
long long T, parent[1000009], N, k, ci, cj, suc, unsuc, a, b;
char ch;

int getParent(int i)
{
    if ( parent[i] == i ) return i;
    parent[i] = getParent( parent[i] );
    return parent[i];
}

void makeUnion(int i, int j)
{
    parent[ getParent(i) ] = getParent(j);
}

string s;
char line[90009];
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d/n", &T);
    while(T--)
    {
        scanf("%d\n\n", &N);
        for (a = 1; a <= N; a++) parent[a] = a;
        suc = unsuc = 0;
        while(1)
        {
            gets(line);
			if (strcmp(line, "") == 0 || feof(stdin)) break;
			sscanf(line, "%c %d %d", &ch, &ci, &cj);
            //if( !getline(cin,s) || s.empty() )
            //{
                //cout << "broken " << endl;
                //break;
            //}
            //else
            //{
                //cout << "Not broken" << endl;
            //}
            sscanf(s.c_str(),"%c %d %d",&ch,&ci,&cj);
            if (ch == 'c') makeUnion(ci, cj);
            else
            {
                if ( getParent(ci) == getParent(cj) ) suc++;
                else unsuc++;
            }
        }
        cout << suc << "," << unsuc << endl;
        if (T) cout << endl;
    }
    return 0;
}
