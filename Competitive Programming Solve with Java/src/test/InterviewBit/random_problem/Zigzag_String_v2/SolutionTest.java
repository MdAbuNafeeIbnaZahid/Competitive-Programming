package InterviewBit.random_problem.Zigzag_String_v2;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by nafee on 4/9/18.
 */
public class SolutionTest {
    @Test
    public void convert() throws Exception {
        Solution solution = new Solution();

        assertEquals("ACBD", solution.convert("ABCD", 2));
        assertEquals("0481357926", solution.convert("0123456789", 3));
        assertEquals("ABCD", solution.convert("ABCD", 299));

    }

}