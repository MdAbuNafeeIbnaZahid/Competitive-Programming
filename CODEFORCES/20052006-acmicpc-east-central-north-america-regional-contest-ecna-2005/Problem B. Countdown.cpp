#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

class myClass
{
public:
    string name;
    int numChild;
    vector<string> nameChildVec;
    int prev, now;
    myClass(){};
    myClass(string name, int numChild, vector<string>nameChildVec)
    {
        this->name = name;
        this->numChild = numChild;
        this->nameChildVec = nameChildVec;
        prev = numChild;
        now = 0;
    }
};

bool operator<(myClass left, myClass right)
{
    if (left.prev > right.prev) return false;
    if (left.prev == right.prev)  return left.name > right.name;
    return true;
}

int main()
{
    int t, i, j, k, m, n, lines, dis, numChild;
    scanf("%d", &t);


    char str[100];
    string myName, childName;

    for (i = 1; i <= t; i++)
    {
        map<string, myClass> tree;
        scanf("%d %d", &lines, &dis);
        for (j = 1; j <= lines; j++)
        {
            scanf("%s %d", str, &numChild);
            myName = str;
            vector<string> nameChildVec;
            for (k = 1; k <= numChild; k++)
            {
                scanf("%s", str);
                childName = str;
                nameChildVec.push_back(childName);
            }
            tree.insert(make_pair(myName, myClass(myName, numChild, nameChildVec)));
        }

        for (j = 2; j <= dis; j++)
        {
            map<string, myClass>::iterator it1, it2;
            for (it1 = tree.begin(); it1 != tree.end(); it1++)
            {
                vector<string>::iterator vit1;
                for (vit1 = it1->second.nameChildVec.begin(); vit1 != it1->second.nameChildVec.end(); vit1++)
                {
                    if (tree.find(*vit1) != tree.end())
                    {
                        it1->second.now += tree[*vit1].prev;
                    }
                }
            }


            for (it1 = tree.begin(); it1 != tree.end(); it1++)
            {
                it1->second.prev = it1->second.now;
                it1->second.now = 0;
            }
        }

        priority_queue<myClass> pq;
        map<string, myClass>::iterator mit1;
        for (mit1=tree.begin(); mit1 != tree.end(); mit1++)
        {
            if (mit1->second.prev > 0)
            {
                pq.push(mit1->second);
            }
        }

        int past = 0;
        if (pq.size())
        {
            past = pq.top().prev;
        }
        printf("Tree %d:\n", i);
        for (n = 1; pq.size() && (n <= 3 || pq.top().prev == past ); n++)
        {
            printf("%s %d\n", pq.top().name.c_str(), pq.top().prev);
            past = pq.top().prev;
            pq.pop();
        }
        printf("\n");


    }




    return 0;
}
