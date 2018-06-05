package InterviewBit.random_problem.rod_cutting;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by nafee on 6/5/18.
 */
public class SolutionTest {

    Solution solution = new Solution();
    int A;
    ArrayList<Integer> B;
    ArrayList<Integer> expected;


    @Before
    public void setUp() throws Exception {
        B = new ArrayList<>();
        expected = new ArrayList<>();
    }

    @After
    public void tearDown() throws Exception {

    }

    @Test
    public void rodCut1() throws Exception {
        A = 6;

        B.add(1);
        B.add(2);
        B.add(5);

        expected.add(2);
        expected.add(1);
        expected.add(5);

        assertEquals(expected, solution.rodCut(A, B));
    }

}