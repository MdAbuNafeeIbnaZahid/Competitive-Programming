package InterviewBit.random_problem.multiply_strings;

import java.util.Arrays;

/**
 * Created by nafee on 4/2/18.
 */
public class Solution {



    private static final int SAFETY = 9;

//    private static int[] getNumAsArray(String str)
//    {
//        int len = str.length();
//        int[] ret = new int[len];
//        for (int a = len-1; a >= 0; a-- )
//        {
//            char ch = str.charAt(a);
//            ret[ len-1-a ] = Character.getNumericValue(ch);
//        }
//
//        return ret;
//    }
//
//    private int[] getMulAr( int[] A, int[] B )
//    {
//
//        int retLen = A.length + B.length + SAFETY;
//        int[] ret = new int[retLen];
//        for (int a = 0; a < A.length; a++)
//        {
//            for (int b = 0; b < B.length; b++)
//            {
//                int retIdx = a+b;
//                int addee = A[a] * B[b];
//                ret[retIdx] += addee;
//            }
//        }
//        return ret;
//    }

    private static int getVal(String A, int idx)
    {
        char ch = A.charAt(idx);
        return Character.getNumericValue(ch);
    }

    private static int[] getMulAr( String A, String B )
    {

        int aLen = A.length();
        int bLen = B.length();

        int retLen = aLen + bLen + SAFETY;
        int[] ret = new int[retLen];

        for (int a = 0; a < aLen; a++)
        {
            for (int b = 0; b < bLen; b++)
            {
                int aVal = getVal(A, a);
                int bVal = getVal(B, b);

                int retIdx = aLen + bLen - 2 - a - b;

                int addee = aVal * bVal;
                ret[retIdx] += addee;
            }
        }
        return ret;
    }


    private static void makeDigitAr(int[] ar)
    {
        for (int a = 0; a < ar.length-1; a++) // skipping last element
        {
            ar[a+1] += ar[a] / 10;
            ar[a] %= 10;
        }
    }

    private static int[] removeLeadingZero(int[] ar)
    {
        int len = ar.length;
        int firstNonZeroIdx = len-1;
        while( firstNonZeroIdx >= 0 && ar[firstNonZeroIdx]==0 )
        {
            firstNonZeroIdx--;
        }

        if (firstNonZeroIdx == -1)
        {
            ar = new int[1];
        }
        else
        {
            ar = Arrays.copyOfRange(ar, 0, firstNonZeroIdx+1);
        }
        return ar;
    }

    private static String getStrFromNumArray(int[] ar)
    {
        int len = ar.length;
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = len-1; i >= 0; i--)
        {
            stringBuilder.append( ar[i] );
        }
        return stringBuilder.toString();
    }


    public String multiply(String A, String B) {
        int[] mulAr = getMulAr(A, B);
        makeDigitAr(mulAr);
        mulAr = removeLeadingZero(mulAr);
        return getStrFromNumArray(mulAr);
    }
}