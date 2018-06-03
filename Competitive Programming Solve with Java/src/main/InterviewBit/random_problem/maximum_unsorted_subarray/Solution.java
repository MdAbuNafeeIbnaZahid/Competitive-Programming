package InterviewBit.random_problem.maximum_unsorted_subarray;

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
        ArrayList<Integer> sortedA = Util.getSortedCopy(A);

        int firstMismatch = Util.getFirstMismatch(A, sortedA);
        int lastMismatch = Util.getlastMismatchIdx(A, sortedA);

        assert firstMismatch < lastMismatch;
        return getAns(firstMismatch, lastMismatch);
    }

    private ArrayList<Integer> getAns( int firstMismatch, int lastMismatch )
    {
        ArrayList<Integer> ret = new ArrayList<>();
        ret.add(firstMismatch);
        ret.add(lastMismatch);
        return ret;
    }
}
