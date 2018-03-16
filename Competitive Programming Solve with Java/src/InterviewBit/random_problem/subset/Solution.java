package InterviewBit.random_problem.subset;

import java.util.ArrayList;
import java.util.Collections;

/**
 * Created by nafee on 3/15/18.
 */
public class Solution {

    int findIdxOfEmptyList(ArrayList<ArrayList<Integer>> listArrayList)
    {
        for (int i = 0; i < listArrayList.size(); i++)
        {
            if ( listArrayList.get(i).size() == 0 )
            {
                return i;
            }
        }

        throw new Error(" no empty list found ");
    }

    void bringEmptyListAtBeginning(ArrayList<ArrayList<Integer>> listArrayList)
    {
        int idxOfEmptyList = findIdxOfEmptyList(listArrayList);
        ArrayList<Integer> emptyList = listArrayList.get(idxOfEmptyList);

        listArrayList.remove(idxOfEmptyList);
        listArrayList.add(0, emptyList);
    }

    ArrayList<ArrayList<Integer>> getCopyAddingElementAtBeginning(ArrayList<ArrayList<Integer>> inputListArrayList,
                                                                  int addee)
    {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        for (ArrayList<Integer> al : inputListArrayList)
        {
            ArrayList<Integer> newAL = new ArrayList<>( al );
            newAL.add(0, addee);
            ret.add(newAL);
        }

        return ret;
    }

    // idx will visit from left to right
    ArrayList<ArrayList<Integer>> getSubsetRecursively(ArrayList<Integer> A, int idx)
    {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        if (idx == A.size() )
        {
            ret.add( new ArrayList<>() );
            return ret;
        }

        ArrayList<ArrayList<Integer>> lowerRet = getSubsetRecursively(A, idx+1);

        ArrayList<ArrayList<Integer>> lowerRetAddingCurrent = getCopyAddingElementAtBeginning(lowerRet, A.get(idx));

        ret.addAll(lowerRetAddingCurrent);
        ret.addAll(lowerRet);

        bringEmptyListAtBeginning(ret);

        return ret;
    }



    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> A) {

        Collections.sort( A );

        return getSubsetRecursively(A, 0);

    }






//    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> A) {
//
//        Collections.sort( A );
//
//        ArrayList<ArrayList<Integer>> posRet = getSubsetsRecursive(A, A.size()-1);
//
//
//
//        return posRet;
//    }
//
//
//    ArrayList<ArrayList<Integer>> getSubsetsRecursive(ArrayList<Integer> A, int idx)
//    {
//        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
//
//        if (idx < 0)
//        {
//            ret.add( new ArrayList<>() );
//            return ret;
//        }
//
//        ArrayList<ArrayList<Integer>> lowerRet = getSubsetsRecursive(A, idx-1);
//
//        for ( ArrayList<Integer> al : lowerRet )
//        {
//            ArrayList<Integer> newAL = new ArrayList<>( al );
//            newAL.add( A.get(idx) );
//            ret.add(newAL);
//        }
//
//
//
//        ret.addAll(lowerRet);
//
//        if (ret.size() == 2)
//        {
//            Collections.reverse( ret );
//        }
//
//        return ret;
//
//    }
//
    public static void main(String[] args) {
        Solution solution = new Solution();

        ArrayList arrayList = new ArrayList();
        arrayList.add(0);
        arrayList.add(1);
        arrayList.add(2);
        System.out.println( solution.subsets(arrayList) );
    }
}








