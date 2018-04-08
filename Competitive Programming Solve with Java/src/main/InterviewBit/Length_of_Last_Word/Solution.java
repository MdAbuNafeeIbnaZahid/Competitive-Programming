package InterviewBit.Length_of_Last_Word;

/**
 * Created by nafee on 4/8/18.
 */
public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int lengthOfLastWord(final String A) {

        int ret = 0;
        int len = A.length();

        for (int i = len-1; i >= 0; i--)
        {
            if ( A.charAt(i) == ' ' )
            {
                if (ret > 0)
                {
                    return ret;
                }
            }
            else
            {
                ret++;
            }
        }
        return ret;
    }
}
