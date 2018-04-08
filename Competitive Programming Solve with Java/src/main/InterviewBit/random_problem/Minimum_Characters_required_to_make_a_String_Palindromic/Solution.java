package InterviewBit.random_problem.Minimum_Characters_required_to_make_a_String_Palindromic;

/**
 * Created by nafee on 4/8/18.
 */
public class Solution {

    public static int[] getAuxAr(String str)
    {
        int len = str.length();
        int[] ret = new int[len];
        ret[0] = 0;
        int idx = 1;
        int prefixLen = 0;
        while (idx < len)
        {
            if ( str.charAt(idx) == str.charAt(prefixLen) ) // match
            {
                ret[idx] = ++prefixLen;
                idx++;
            }
            else
            {
                if ( prefixLen == 0 ) // no chance to recalc prefixLen
                {
                    ret[idx] = 0;
                    idx++;
                }
                else // chance to recalc prefixLen
                {
                    prefixLen = ret[prefixLen-1];
                }
            }
        }

        return ret;
    }

    public int solve(String A) {
        int aLen = A.length();
        String revA = new StringBuilder(A).reverse().toString();
        String newA = A + "#" + revA;
        int[] auxAr = getAuxAr(newA);
        return aLen-auxAr[ auxAr.length-1 ];
    }
}
