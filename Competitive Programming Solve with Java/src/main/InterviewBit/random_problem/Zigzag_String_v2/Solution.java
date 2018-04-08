package InterviewBit.random_problem.Zigzag_String_v2;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by nafee on 4/9/18.
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

        List<Integer> strBuilderArIdxList = getRowIdxList(A.length(), B);
        assert strBuilderArIdxList.size() == A.length();

        for (int i = 0; i < A.length(); i++)
        {
            int stringBuildArIdx = strBuilderArIdxList.get(i);
            stringBuilderAr[stringBuildArIdx].append( A.charAt(i) );
        }

        String ret = getStringFromStrBuildAr(stringBuilderAr);

        return ret;
    }



    List<Integer> getRowIdxList(int strLen, int rowCnt)
    {
        if ( rowCnt <= 1 )
        {
            return getSeqList(strLen);
        }

        return getOnePlusRowIdxList(strLen, rowCnt);
    }

    List<Integer> getSeqList(int upto)
    {
        ArrayList<Integer> ret = new ArrayList<>();
        for (int i = 0; i < upto; i++)
        {
            ret.add( i );
        }
        return ret;
    }

    List<Integer> getOnePlusRowIdxList(int strLen, int rowCnt)
    {
        assert rowCnt > 1;
        int rowIdx = 0;
        int direction = 1;
        List<Integer> ret = new ArrayList<>();
        for (int i = 0; i < strLen; i++)
        {
            ret.add( rowIdx );
            if ( (rowIdx==0 && direction == -1) || ( rowIdx==rowCnt-1 && direction == 1 ) )
            {
                direction *= -1;
            }
            rowIdx += direction;
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
