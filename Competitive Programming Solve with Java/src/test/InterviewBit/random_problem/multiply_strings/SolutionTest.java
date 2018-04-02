package InterviewBit.random_problem.multiply_strings;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by nafee on 4/2/18.
 */
public class SolutionTest {

    @Test
    public void multiplyTest() throws Exception {
        Solution solution = new Solution();
        String A, B;

        A = "0";
        B = "1";

        assertEquals("0", solution.multiply("0", "1") );
        assertEquals("120", solution.multiply("12", "10"));
        assertEquals("1", solution.multiply("0001", "01"));
    }

}