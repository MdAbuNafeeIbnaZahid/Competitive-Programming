package InterviewBit.random_problem.pascal_triangle;

import java.util.ArrayList;

/**
 * Created by nafee on 3/19/18.
 */
public class Solution
{
    public ArrayList<ArrayList<Integer>> generate(int A) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();

        if (A == 0)
        {
            return ret;
        }

        ArrayList<Integer> firstRow = new ArrayList<Integer>();
        firstRow.add(1);
        ret.add(firstRow);

        for (int i = 2; i <= A; i++)
        {
            ArrayList<Integer> currentRow = new ArrayList<>();

            ArrayList<Integer> prevRow = ret.get( ret.size()-1 );

            currentRow.add(1);

            for (int j = 2; j < i; j++)
            {
                int curVal = prevRow.get(j-2) + prevRow.get(j-1);
                currentRow.add(curVal);
            }

            currentRow.add(1);

            ret.add(currentRow);
        }

        return ret;
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        for (int i = 0; i <= 5; i++)
        {
            System.out.println( solution.generate(i) );
        }
    }
}
