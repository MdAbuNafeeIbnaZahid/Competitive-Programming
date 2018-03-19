package main.InterviewBit.random_problem.subset;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * Created by nafee on 3/16/18.
 */
public class Solution2
{
    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> A) {

        Collections.sort(A);

        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();

        for (int i = 0; i < (1 << A.size() ); i++ )
        {
            System.out.println(i);
            ArrayList<Integer> currentSubset = new ArrayList<>();
            for (int j = 0; j < A.size(); j++)
            {
                if ( ((i>>j)&1) != 0 )
                {
                    currentSubset.add( A.get(j) );
                }
            }
            System.out.println(currentSubset);
            ret.add( currentSubset );
        }

        System.out.println( ret );

        Collections.sort(ret, new LexicographicalComparator());

        return ret;
    }


    public static void main(String[] args) {
        Solution2 solution2 = new Solution2();

        ArrayList arrayList = new ArrayList();
        arrayList.add(0);
        arrayList.add(1);
        arrayList.add(2);
        System.out.println( solution2.subsets(arrayList) );
    }


}

class LexicographicalComparator implements Comparator<ArrayList<Integer>>
{

    @Override
    public int compare(ArrayList<Integer> P, ArrayList<Integer> Q) {
        for (int i = 0; i < Math.max(P.size(), Q.size()); i++)
        {
            if ( P.size() <= i )
            {
                return -1;
            }

            if (Q.size() <= i)
            {
                return 1;
            }

            if ( P.get(i) < Q.get(i) )
            {
                return -1;
            }

            if ( Q.get(i) < P.get(i) )
            {
                return 1;
            }
        }

        return 0;
    }
}


