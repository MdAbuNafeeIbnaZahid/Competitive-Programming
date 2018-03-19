package main.InterviewBit.BitManupulation.SingleNumber2;

import java.util.*;

import static org.junit.Assert.*;

/**
 * Created by nafee on 11/26/17.
 */
public class SolutionTest {

    Solution solution = new Solution();

    @org.junit.Test
    public void singleNumber() throws Exception {

        List<Integer> ints;
        ints = new ArrayList<>(Arrays.asList(1, 2, 4, 3, 3, 2, 2, 3, 1, 1));
        assertEquals( 4, solution.singleNumber(ints) );

        ints = new ArrayList<>(Arrays.asList(1));
        assertEquals( 1, solution.singleNumber(ints) );


        ints = new ArrayList<>(Arrays.asList(-99, -9, -9, -9));
        assertEquals( -99, solution.singleNumber(ints) );

    }



    Vector getItems()
    {
        return null;
    }

    public void f()
    {

        class Item{}


        Vector itemsVector = getItems();

        Random rand = new Random(System.currentTimeMillis()); // would make this static to the class

        List subsetList = new ArrayList(5);
        for (int i = 0; i < 5; i++) {
            // be sure to use Vector.remove() or you may get the same item twice
            int randomIndex = rand.nextInt(itemsVector.size());
            Object itemSelected = itemsVector.get(randomIndex);
            itemsVector.remove(randomIndex);
            subsetList.add(itemSelected);
        }


    }


}






