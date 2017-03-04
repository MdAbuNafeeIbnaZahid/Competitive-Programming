import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static BigInteger ans, cur;
    static BigInteger term = new BigInteger("-999999");
    static final int SIZE = 109;
    static String string;
    static int i, j, n, a, b, c;
    static BigInteger ar[] = new BigInteger[SIZE], cumulativeMul[] = new BigInteger[SIZE];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext())
        {
            cur = new BigInteger("1");
            ans = new BigInteger("-99999999999999");
            i = 0;
            while (scanner.hasNext()) {
                n = scanner.nextInt();
                if (n == -999999) {
                    break;
                }
                i++;
                ar[i] = new BigInteger( String.valueOf(n) );
                //cumulativeMul[i] = new BigInteger( String.valueOf(n) );
            }

            //for (a = 1; a < i; a++)
            //{
                //cumulativeMul[a] = cumulativeMul[a-1].multiply(cumulativeMul[a]);
            //}
            for (a = 1; a <= i; a++)
            {
                for (b = a; b <= i; b++)
                {
                    cur = new BigInteger("1");
                    for (c = a; c <= b; c++)
                    {
                        cur = cur.multiply( ar[c] );
                    }
                    ans = cur.max( ans );
                }
            }
            System.out.println(ans);
        }
    }
}
