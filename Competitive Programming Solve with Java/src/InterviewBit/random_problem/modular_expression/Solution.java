package InterviewBit.random_problem.modular_expression;

/**
 * Created by nafee on 3/14/18.
 */
public class Solution {
    public int Mod(int A, int B, int C) {


        long ret = 1;

        if (B == 0)
        {
            return 1%C;
        }

        long half = Mod(A, B/2, C);
        ret = (half * half) % C;


        if (B % 2 != 0)
        {
            ret = (ret * A) % C;
        }

        return (int) (  (ret+C)%C );
    }


    public static void main(String[] args) {
        Solution solution = new Solution();

//        System.out.println( solution.Mod(5, 2, 1 ) );
        System.out.println( solution.Mod(-5, 3, 10000000) );
    }
}