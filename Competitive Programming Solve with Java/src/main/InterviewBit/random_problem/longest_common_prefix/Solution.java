package InterviewBit.random_problem.longest_common_prefix;

import java.util.ArrayList;

/**
 * Created by nafee on 4/1/18.
 */
public class Solution {
    public String longestCommonPrefix(ArrayList<String> A) {
        if (A.isEmpty())
        {
            return "";
        }

        String ret = A.get(0);
        for (String str : A)
        {
            ret = getCommonPrefix(ret, str);
        }

        return ret;
    }

    public static String getCommonPrefix(String a, String b)
    {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < Math.min(a.length(), b.length()); i++)
        {
            if ( a.charAt(i) != b.charAt(i) )
            {
                break;
            }

            stringBuilder.append( a.charAt(i) );
        }

        return stringBuilder.toString();
    }
}
