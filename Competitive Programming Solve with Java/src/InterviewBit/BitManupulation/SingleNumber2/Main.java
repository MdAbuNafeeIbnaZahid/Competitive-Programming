package InterviewBit.BitManupulation.SingleNumber2;

import java.util.List;

/**
 * Created by nafee on 11/26/17.
 */

class PrimitiveSizes
{
    public static int sizeof(int i)
    {
        return 4;
    }
}

class Solver
{
    int getBit( int num, int bitPos )
    {
        return (num>>bitPos) & 1;
    }


    int getBitFromList( final List<Integer> ints, int bitPos, int genMul )
    {
        int[] bitCnt = new int[5];
        for( Integer i : ints )
        {
            bitCnt[ getBit(i, bitPos) ]++;
        }

        int ret = (bitCnt[0]%genMul)==1 ? 0 : 1;
        return ret;
    }

}


class Solution {
    // DO NOT MODIFY THE LIST
    public int singleNumber(final List<Integer> a)
    {
        Solver solver = new Solver();
        int ret = 0;
        for (int b = 0; b < 32; b++)
        {
            int bit = solver.getBitFromList(a, b, 3);
            ret |= (bit<<b);
        }

        return ret;
    }
}



public class Main
{
    int add(int a, int b)
    {
        return a+b;
    }
}
