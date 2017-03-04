import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

//
 // Created by nafeedgbhs on 11/2/2016.
 //
public class Main {

    public static void main(String[] args) {
        int N;
        BigInteger ans, biggestFactor, diff, extraVal;
        String lineInput;
        StringTokenizer stringTokenizer;
        int a, b, c, d, e, f, g;
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        BigInteger[] input = new BigInteger[N];
        lineInput = scanner.nextLine();
        lineInput = scanner.nextLine();
        stringTokenizer = new StringTokenizer( lineInput );
        a = 0;
        while ( stringTokenizer.hasMoreTokens() )
        {
            input[a] = new BigInteger( stringTokenizer.nextToken() );
            a++;
        }
        Arrays.sort( input );
        biggestFactor = input[1].subtract(input[0]);
        for (a = 1; a <= N-2; a++)
        {
            diff = input[a+1].subtract( input[a] );
            biggestFactor = biggestFactor.gcd( diff );
        }
        extraVal = input[0].mod(biggestFactor);
        ans = biggestFactor.subtract(input[0].mod(biggestFactor));
        if ( extraVal.equals( new BigInteger("0") ) ) System.out.println( 0 );
        else System.out.println(ans);
    }
}
