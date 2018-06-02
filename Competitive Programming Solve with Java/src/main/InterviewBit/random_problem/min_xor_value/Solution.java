package InterviewBit.random_problem.min_xor_value;

import java.util.ArrayList;

/**
 * Created by nafee on 6/2/18.
 */


class Util
{
    public static int getBit(int num, int bitPos)
    {
        return (num >> bitPos) & 1;
    }
}

class Node
{
    static final int SIZE = 2;
    private int cnt = 0;
    private Node[] children;

    Node()
    {
        cnt = 0;
        children = new Node[SIZE];
    }

    int getCnt()
    {
        return cnt;
    }

    void incCnt()
    {
        cnt++;
    }

    Node getChild(int childPos)
    {
        if ( !hasChild(childPos) )
        {
            children[childPos] = new Node();
        }

        return children[childPos];
    }

    boolean hasChild(int childPos)
    {
        return (children[childPos] != null);
    }
}


class Trie
{
    final static int INP_MAX_BIT_POS = 30;
    Node head = new Node();

    Trie(){}

    void addNum( int num )
    {
        head.incCnt();
        Node cur = head;

        for (int bitPos = INP_MAX_BIT_POS; bitPos >= 0; bitPos--)
        {
            int bit = Util.getBit(num, bitPos);
            cur = cur.getChild(bit);
            cur.incCnt();
        }
    }

    int getMinXorVal(int num)
    {
        Node cur = head;
        int ret = 0;

        for (int bitPos = INP_MAX_BIT_POS; bitPos >= 0; bitPos--)
        {
            int bit = Util.getBit(num, bitPos);

            if ( cur.hasChild(bit) )
            {
                cur = cur.getChild(bit);
            }
            else
            {
                cur = cur.getChild(bit ^ 1);
                ret = ret | (1 << bitPos);
            }
        }

        return ret;
    }
}

public class Solution {
    public int findMinXor(ArrayList<Integer> A) {

        Trie trie = new Trie();
        trie.addNum(A.get(0));

        int minXor = Integer.MAX_VALUE;

        for (int idx = 1; idx < A.size(); idx++)
        {
            int curNum = A.get(idx);

            int posMinXor = trie.getMinXorVal(curNum);
            minXor = Integer.min(minXor, posMinXor);

            trie.addNum(curNum);
        }


        return minXor;
    }


}
