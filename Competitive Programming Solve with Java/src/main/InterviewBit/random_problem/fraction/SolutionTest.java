package main.InterviewBit.random_problem.fraction;

import static org.junit.Assert.*;

/**
 * Created by nafee on 3/14/18.
 */
public class SolutionTest {



    public static void main(String[] args) {

        Solution solution = new Solution();
        assertEquals( "0.(3)", solution.fractionToDecimal(1,3) );
        assertEquals("0.5", solution.fractionToDecimal(1, 2));
        assertEquals("0.(6)", solution.fractionToDecimal(2, 3));
        assertEquals("0.1(3)", solution.fractionToDecimal(4, 30));
        assertEquals("2", solution.fractionToDecimal(2, 1));
        assertEquals("0", solution.fractionToDecimal(0, 1));
        assertEquals("0.(142857)", solution.fractionToDecimal(1, 7));
        assertEquals("1.(428571)", solution.fractionToDecimal(10, 7));
        assertEquals("2147483648", solution.fractionToDecimal(-2147483648, -1));
        assertEquals("-5", solution.fractionToDecimal(10, -2));
        assertEquals("-0.5", solution.fractionToDecimal(-1, 2));
    }
}