package InterviewBit.random_problem.Zigzag_String;

/**
 * Created by nafee on 4/8/18.
 */
public class Solution {


    public String convert(String A, int B) {
        if (B <= 1)
        {
            return A;
        }

        StringBuilder[] stringBuilderAr = new StringBuilder[B];
        for (int i = 0; i < B; i++)
        {
            stringBuilderAr[i] = new StringBuilder();
        }

        for (int i = 0; i < A.length(); i++)
        {
            int stringBuildArIdx = getStringBuilderArIdx(i, B-1);
            stringBuilderAr[stringBuildArIdx].append( A.charAt(i) );
        }

        String ret = getStringFromStrBuildAr(stringBuilderAr);

        return ret;
    }

    public static int getStringBuilderArIdx(int strIdx, int rowCnt)
    {
        int colNum = strIdx/rowCnt;

        int ret = strIdx%rowCnt;
        if ( (colNum & 1) == 1 ) // odd column
        {
            ret = rowCnt - ret;
        }

        return ret;
    }

    String getStringFromStrBuildAr( StringBuilder[] stringBuilders )
    {
        StringBuilder bigStringBuilder = new StringBuilder();
        for (int i = 0; i < stringBuilders.length; i++)
        {
            bigStringBuilder.append( stringBuilders[i] );
        }

        return bigStringBuilder.toString();
    }
}
