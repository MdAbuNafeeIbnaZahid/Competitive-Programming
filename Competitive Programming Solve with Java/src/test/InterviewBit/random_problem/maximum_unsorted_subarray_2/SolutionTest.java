package InterviewBit.random_problem.maximum_unsorted_subarray_2;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.io.CharArrayReader;
import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by nafee on 6/2/18.
 */
public class SolutionTest {

    Solution solution = new Solution();

    ArrayList<Integer> A;
    ArrayList<Integer> expected;


    @Before
    public void setUp() throws Exception {
        solution = new Solution();
        A = new ArrayList<>();
        expected = new ArrayList<>();
    }

    @After
    public void tearDown() throws Exception {

    }

    @Test
    public void subUnsort1() throws Exception {
        A.add(1);
        A.add(3);
        A.add(2);
        A.add(4);
        A.add(5);

        expected.add(1);
        expected.add(2);
        assertEquals(expected, solution.subUnsort(A));
    }

    @Test
    public void subUnsort2() throws Exception {
        A.add(1);
        A.add(2);
        A.add(3);
        A.add(4);
        A.add(5);

        expected.add(-1);
        assertEquals(expected, solution.subUnsort(A));
    }


    @Test
    public void subUnsort3() throws Exception {
        A.add(1);

        expected.add(-1);
        assertEquals(expected, solution.subUnsort(A));
    }


}