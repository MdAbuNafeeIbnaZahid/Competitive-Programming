package InterviewBit.random_problem.matrix_search;

import java.util.ArrayList;

/**
 * Created by nafee on 3/19/18.
 */
public class Main {

}



class Solution {

    public int searchMatrix(ArrayList<ArrayList<Integer>> a, int b) {
        int rowCount = a.size();

        if ( rowCount == 0 )
        {
            return 0;
        }

        int colCount = a.get(0).size();
//        int maxIdx = rowCount*colCount-1;

        int lowIdx = 0;
        int highIdx = rowCount*colCount-1;

        while (lowIdx <= highIdx)
        {
            int midIdx = (lowIdx + highIdx)/2;

            int midVal = getValFrom2DMatrix(a, midIdx);

            if (b == midVal)
            {
                return 1;
            }

            else if (b < midVal)
            {
                highIdx = midIdx-1;
            }

            else if (midVal < b)
            {
                lowIdx = midIdx + 1;
            }
        }

        return 0;
    }

    int getValFrom2DMatrix( ArrayList<ArrayList<Integer>> a, int oneDIdx )
    {
        int rowCount = a.size();
        int colCount = a.get(0).size();

        int rowIdx = oneDIdx / colCount;
        int colIdx = oneDIdx % colCount;

        return a.get(rowIdx).get(colIdx);
    }
}

