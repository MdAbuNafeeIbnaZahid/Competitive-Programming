package InterviewBit.BitManupulation.SingleNumber2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

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

}