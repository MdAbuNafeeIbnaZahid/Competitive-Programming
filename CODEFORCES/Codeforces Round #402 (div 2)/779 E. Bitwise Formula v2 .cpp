#include <bits/stdc++.h>
using namespace std;
#define SIZE 5009
long long n, m;
long long bitAr[SIZE][SIZE], globalBit;
long long ansMin[SIZE], ansMax[SIZE];
struct myStr
{
    char *str;
    myStr(char *str)
    {
        long long len = strlen( str );
        this->str = new char[len+9];
        strcpy(this->str, str);
    }
    bool operator < ( const  myStr B ) const
    {
        return strcmp( str, B.str ) < 0;
    }
};
map< string, long long > myMap;
struct variable
{
    long long idx = 0, firIdx = 0 , secIdx = 0;
    string firNum, op, secNum;
    variable(){}
    variable(long long idx, string cons)
    {
        this->idx = idx;
        long long a, b, c,d;
        reverse( cons.begin(), cons.end() );
        firNum = cons;
        op = "";
        for ( a = 0; a < firNum.size(); a++ )
        {
            bitAr[idx][a] = firNum[a] - '0';
        }
    }
    variable( long long idx, string fir, string op, string sec )
    {
        this->idx = idx;
        if ( myMap[fir] )
        {
            firIdx = myMap[fir];
        }
        else
        {
            reverse( fir.begin(), fir.end() );
            firNum = fir;
        }

        this->op = op;

        if ( myMap[sec] )
        {
            secIdx = myMap[sec];
        }
        else
        {
            reverse( sec.begin(), sec.end() );
            secNum = sec;
        }
    }
    long long getBit(long long bitIdx)
    {
        long long ret;
        if ( op == "" )
        {
            ret = bitAr[ idx ][ bitIdx ];
        }
        else
        {
            long long firBit, secBit;
            firBit = firNum.size() ? (firNum=="?"?globalBit:firNum[bitIdx]-'0') : bitAr[firIdx][bitIdx];
            secBit = secNum.size() ? (secNum=="?"?globalBit:secNum[bitIdx]-'0') : bitAr[secIdx][bitIdx];
            //long long ret;
            if ( op == "AND" )
            {
                ret = firBit & secBit;
            }
            else if ( op == "XOR" )
            {
                ret = firBit ^ secBit;
            }
            else // or
            {
                ret = firBit | secBit;
            }
        }
        return bitAr[idx][bitIdx] = ret;
    }

};
ostream &operator << (ostream &stream, variable var)
    {
        stream << "idx = " << var.idx << ", firIdx = " << var.firIdx ;
        stream << ", secIdx = " << var.secIdx << endl;
        stream << "firNum = " << var.firNum << endl;
        stream << "op = " << var.op << endl;
        stream << "secNum = " << var.secNum << endl;
        return stream ;
    }
vector<variable> vecVar;
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> n >> m;
//    cout << "n = " << n << ", m = " << m << endl;
    vecVar.push_back( variable() );
    for ( a = 1;  a <= n; a++ )
    {
//        cout << "a = " << a << endl;
        char varStr[SIZE], eqStr[SIZE], firOp[SIZE], op[SIZE], secOp[SIZE];
        char ch;
        scanf( "%s", varStr );
//        cout << "varStr = " << varStr << endl;
        myMap[ string(varStr) ] = a;
        scanf( "%s", eqStr ); // :=
//        cout << "eqStr = " << eqStr << endl;
        scanf( "%s", firOp );
//        cout << "firOp = " << firOp << endl;
        scanf("%c", &ch);
//        cout << "ch = " << ch << endl;
        if ( ch == ' ' )
        {
//            cout << "ch is a space " << endl;
            scanf("%s", op);
            scanf("%s", secOp);
            vecVar.push_back( variable(a, firOp, op, secOp) );
        }
        else
        {
//            cout <<
            vecVar.push_back( variable(a, firOp) );
        }
    }
//    cout << "input taken " << endl;
    for ( a = 0; a < vecVar.size(); a++ )
    {
//        cout << "a = " << a << endl;
//        cout << vecVar[a] << endl;
    }
    for ( a = m-1; a >=0; a-- )
    {
//        cout << "a = " << a << endl;
        long long bitCntZero = 0, bitCntOne = 0;
        globalBit = 0;
//        cout << "globalBit = " << globalBit << endl;
        long long receivedBit;
        for ( b = 1; b <= n; b++ )
        {
//            cout << "b = " << b << endl;;
            receivedBit = vecVar[b].getBit(a);
//            cout << "receivedBit = " << receivedBit << endl;
            bitCntZero += receivedBit;
        }
        globalBit = 1;
        for ( b = 1; b <= n; b++ )
        {
            bitCntOne += vecVar[b].getBit(a);
        }
        if ( bitCntZero > bitCntOne )
        {
            ansMax[a] = 0;
            ansMin[a] = 1;
        }
        else if ( bitCntZero == bitCntOne )
        {
            ansMax[a] = 0;
            ansMin[a] = 0;
        }
        else
        {
            ansMax[a] = 1;
            ansMin[a] = 0;
        }
    }
    for ( a = m-1; a >= 0; a-- )
    {
        printf("%lld", ansMin[a]);
    }
    cout << endl;
    for ( a = m-1; a >= 0; a-- )
    {
        printf("%lld", ansMax[a]);
    }
    return 0;
}
