package InterviewBit.random_problem.min_xor_value;


import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by nafee on 6/2/18.
 */
public class SolutionTest {

    Solution solution = new Solution();


    @Test
    public void findMinXor1() throws Exception {

        ArrayList<Integer> A = new ArrayList<>();

        A.add(0);
        A.add(2);
        A.add(5);
        A.add(7);

        assertEquals(2, solution.findMinXor(A));
    }

    @Test
    public void findMinXor2() throws Exception {

        ArrayList<Integer> A = new ArrayList<>();

        A.add(0);
        A.add(4);
        A.add(7);
        A.add(9);

        assertEquals(3, solution.findMinXor(A));
    }


    @Test
    public void findMinXor3() throws Exception {

        ArrayList<Integer> A = new ArrayList<>();

        A.add(0);
        A.add(4);
        A.add(4);
        A.add(9);

        assertEquals(0, solution.findMinXor(A));
    }

}