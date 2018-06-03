package InterviewBit.random_problem.maximum_unsorted_subarray_2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by nafee on 6/2/18.
 */

class Util
{
    public static boolean isSorted(List<Integer> integerList)
    {
        for (int idx = 0; idx < integerList.size()-1; idx++)
        {
            if ( integerList.get(idx) > integerList.get(idx+1) )
            {
                return false;
            }
        }

        return true;
    }

    public static int getlastMismatchIdx(List<Integer> A, List<Integer> B )
    {
        int lastMismatch = -1;
        for (int idx = 0; idx < A.size(); idx++)
        {
            if ( A.get(idx) != B.get(idx) )
            {
                lastMismatch = idx;
            }
        }

        return lastMismatch;
    }

    public static ArrayList<Integer> getSortedCopy(ArrayList<Integer> integerArrayList)
    {
        ArrayList<Integer> ret = new ArrayList<>(integerArrayList);
        Collections.sort(ret);

        return ret;
    }

    public static ArrayList<Integer> getReversedCopy(ArrayList<Integer> integerArrayList)
    {
        ArrayList<Integer> ret = new ArrayList<>(integerArrayList);
        Collections.reverse(ret);

        return ret;
    }

    public static int getFirstMismatch(ArrayList<Integer> A, ArrayList<Integer> B)
    {
        int len = A.size();

        ArrayList<Integer> reversedA = Util.getReversedCopy(A);
        ArrayList<Integer> reversedB = Util.getReversedCopy(B);

        int lastMismatch = getlastMismatchIdx(reversedA, reversedB);
        int firstMismatch = len-1-lastMismatch;

        return firstMismatch;
    }

    public static int getFirstDescentIdx(ArrayList<Integer> integerArrayList)
    {
        for (int idx = 0; idx <= integerArrayList.size()-2; idx++)
        {
            if ( integerArrayList.get(idx) > integerArrayList.get(idx+1) )
            {
                return idx;
            }
        }

        return -1;
    }

    public static int getLastAscentIdx(ArrayList<Integer> integerArrayList)
    {
        for (int idx = integerArrayList.size()-1; idx >= 1; idx--)
        {
            if ( integerArrayList.get(idx-1) > integerArrayList.get(idx) )
            {
                return idx;
            }
        }

        return -1;
    }

    public static int getMin( ArrayList<Integer> integerArrayList, int idxStart, int idxEnd )
    {
        int ret = Integer.MAX_VALUE;

        for (int idx = idxStart; idx <= idxEnd; idx++)
        {
            int curVal = integerArrayList.get(idx);
            ret = Math.min(ret, curVal);
        }

        return ret;
    }

    public static int getMax( ArrayList<Integer> integerArrayList, int idxStart, int idxEnd )
    {
        int ret = Integer.MIN_VALUE;

        for (int idx = idxStart; idx <= idxEnd; idx++)
        {
            int curVal = integerArrayList.get(idx);
            ret = Math.max(ret, curVal);
        }

        return ret;
    }

    public static int getFirstIdxGreaterThan(ArrayList<Integer> integerArrayList, int val)
    {
        for (int idx = 0; idx < integerArrayList.size(); idx++)
        {
            int curVal = integerArrayList.get(idx);
            if ( curVal > val )
            {
                return idx;
            }
        }

        return -1;
    }

    public static int getLastIdxSmallerThan(ArrayList<Integer> integerArrayList, int val)
    {
        for (int idx = integerArrayList.size()-1; idx >= 0; idx--)
        {
            int curVal = integerArrayList.get(idx);
            if ( curVal < val )
            {
                return idx;
            }
        }

        return -1;
    }
}

public class Solution {
    public ArrayList<Integer> subUnsort(ArrayList<Integer> A) {

        if ( Util.isSorted(A) )
        {
            ArrayList<Integer> ret = new ArrayList<>();
            ret.add(-1);
            return ret;
        }

        return subUnsortForUnsortedAr(A);
    }

    private ArrayList<Integer> subUnsortForUnsortedAr( ArrayList<Integer> A )
    {
        int firstDescentIdx = Util.getFirstDescentIdx(A);
        int lastAscentIdx = Util.getLastAscentIdx(A);

        int minWithinMiddlePart = Util.getMin(A, firstDescentIdx, lastAscentIdx);
        int maxWithinMiddlePart = Util.getMax(A, firstDescentIdx, lastAscentIdx);

        int ansStart = Util.getFirstIdxGreaterThan(A, minWithinMiddlePart);
        int ansEnd = Util.getLastIdxSmallerThan(A, maxWithinMiddlePart);

        assert ansStart < ansEnd;
        return getAns(ansStart, ansEnd);
    }

    private ArrayList<Integer> getAns( int firstMismatch, int lastMismatch )
    {
        ArrayList<Integer> ret = new ArrayList<>();
        ret.add(firstMismatch);
        ret.add(lastMismatch);
        return ret;
    }


}
