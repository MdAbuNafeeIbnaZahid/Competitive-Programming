#include <bits/stdc++.h>
using namespace std;
int testCases, digitCount;
string Y, X, s1, s2;
string digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
int diff(int i1, int i2)
{
    int ret = i1-i2;
    if (ret < 0) ret = (-ret);
    return ret;
}
string addition(string s1, string s2)
{
    int i, j, k, m, found;
    string ret, addee;
    int s1Len = s1.size(), s2Len = s2.size(), sum = 0, inHand = 0;
    addee.assign(diff(s1Len, s2Len), '0');
    if ( s1Len > s2Len )
    {
        s2 = addee + s2;
    }
    else
    {
        s1 = addee + s1;
    }
    for (i = max(s1Len, s2Len)-1; i >= 0; i--)
    {
        sum = (s1[i]-'0') + (s2[i]-'0') + inHand;
        ret = digits[sum%10] + ret;
        inHand = sum/10;
    }
    if (inHand) ret = digits[inHand] + ret;
    found = ret.find_first_not_of('0');
    ret.replace(0, found, "");
    return ret;
}
int isSmaller(string s1, string s2)
{
    int i, j, k, m, found;
    string addee;
    found = s1.find_first_not_of('0');
    s1.replace(0, found, "");
    found = s2.find_first_not_of('0');
    s2.replace(0, found, "");
    int s1Len = s1.size(), s2Len = s2.size();
    if (s1Len < s2Len) return 1;
    else if (s1Len > s2Len) return 0;
    //addee.assign(diff(s1Len, s2Len), '0');
    //if ( s1Len > s2Len )
    //{
        //s2 = addee + s2;
    //}
    //else
    //{
        //s1 = addee + s1;
    //}
    for (i = 0; i < s1Len; i++ )
    {
        if ( s1[i] < s2[i] ) return 1;
        else if ( s1[i] > s2[i] ) return 0;
    }
    return 0;
}
string getTensComplement(string s1)
{
    string ret;
    int i, j, k, len = s1.size();
    for (i = 0; i < len; i++)
    {
        s1[i] = '9' - s1[i] + '0';
    }
    ret = addition(s1, "1");
    return ret;
}
string subtract(string s1, string s2) // consider s1 > s2
{
    string ret, addee, tensComplement;
    //s1 = addition(s1, "0");
    //s2 = addition(s2, "0");
    int s1Len = s1.size(), s2Len = s2.size(), i, j, k;
    addee.assign(diff(s1Len, s2Len), '0');
    if ( s1Len > s2Len )
    {
        s2 = addee + s2;
    }
    else
    {
        s1 = addee + s1;
    }
    tensComplement = getTensComplement(s2);
    ret = addition(s1, tensComplement);
    ret.erase(0, 1);
    //ret = addition(ret, "0");
    return ret;
}
string multiply(string s1, char ch)
{
    int i, j, k, inHand = 0, multiplier = ch-'0', len = s1.size(), mulAns = 0;
    string ret = "";
    /*
    for (i = '1'; i <= ch; i++)
    {
        ret = addition(ret, s1);
        //cout << ret << endl;
    }
    */
    for (i = len-1; i >= 0; i--)
    {
        mulAns = inHand + multiplier * ( s1[i]-'0' );
        inHand = mulAns / 10;
        ret = digits[mulAns%10] + ret;
    }
    if (inHand) ret = digits[inHand] + ret;
    return ret;
}
string getSquare(string s1)
{
    int i, j, k, len = s1.size();
    string ret = "", x0, x1, z0, z1, z2;
    if (len == 1)
    {
        int sq = (s1[0]-'0')*(s1[0]-'0');
        if (sq == 0) return "0";
        while(sq)
        {
            ret =  digits[sq%10] + ret;
            sq /= 10;
        }
        return ret;
    }
    else if (len == 0)
    {
        return "0";
    }
    x1.assign(s1.begin(), s1.begin()+len/2);
    //cout << "x1 = " << x1 << endl;
    x0.assign(s1.begin()+len/2, s1.end());
    //cout << "x0 = " << x0 << endl;
    z2 = getSquare(x1);
    //cout << "z2 = " << z2 << endl;
    z0 = getSquare(x0);
    //cout << "z0 = " << z0 << endl;
    z1 = subtract(getSquare( addition(x1, x0) ) , addition(z2, z0));
    ret = addition( z2 + string(2*ceil( (double)len/2 ), '0') , z1 + string(ceil( (double)len/2 ), '0') );
    ret = addition(ret, z0);
    //ret.replace(0, ret.find_first_not_of('0'), "");
    return ret;
}
string getSquareRoot(string s1)
{
    string ret = "", dividee = "", divisor = "", subtr;
    int len, i, j = 0, k;
    if (s1.size()%2) s1 = "0" + s1;
    len = s1.size();
    //cout << "s1 = " << s1 << endl;
    for (i = 0; i <= len-2; i+=2)
    {
        //cout << "i = " << i << endl;
        dividee = dividee + s1[i] + s1[i+1];
        divisor = addition(divisor, digits[j]);
        //cout << "dividee = " << dividee << endl;
        //cout << "divisor = " << divisor << endl;
        for (j = 9; j >= 0; j--)
        {
            subtr = multiply( divisor + digits[j], '0' + j );
            if ( !isSmaller(dividee, subtr) )
            {
                break;
            }
        }
        ret = ret + digits[j];
        divisor = divisor + digits[j];
        dividee = subtract(dividee, subtr);
        //cout << "ret = " << ret << endl;
        //cout << "divisor = " << divisor << endl;
        //cout << "dividee = " << dividee << endl;
        }
    return ret;
}
string divByTwo(string s)
{
    string ret = "";
    int i, j, k, len = s.size(), buf = 0, found;
    for (i = 0; i < len; i++)
    {
        buf = buf*10 + s[i] - '0';
        ret = ret + digits[ buf/2 ];
        buf = buf % 2;
    }
    found = ret.find_first_not_of('0');
    ret.replace(0, found, "");
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string low, high, mid;

    cin >> testCases;
    while(testCases--)
    {
        cin >> Y;
        Y.replace(0, Y.find_first_not_of('0'), "");
        low = "1";
        high = Y;
        mid = divByTwo( addition(low, high) );
        while( isSmaller(low, high) )
        {
            //cout << "low = " << low << endl;
            //cout << "high = " << high << endl;
            mid = divByTwo( addition(low, high) );
            //cout << "mid = " << mid << endl;
            X = getSquare(mid);
            //cout << "X = " << X << endl;
            if (X == Y) break;
            if ( isSmaller(X, Y) )
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        cout << mid << endl;
    }
}
