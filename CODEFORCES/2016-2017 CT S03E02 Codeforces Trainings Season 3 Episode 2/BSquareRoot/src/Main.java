import java.math.BigDecimal;
import java.util.Scanner;
import java.math.*;
///**
 //* Created by nafeedgbhs on 9/14/2016.
 //*/
public class Main {
    public static BigDecimal f( BigDecimal x0, BigDecimal sub )
    {
        return (x0.multiply(x0) ).subtract( sub );
    }

    public static BigDecimal fPrime( BigDecimal x )
    {
        return x.multiply( new BigDecimal(2) );
    }

    public static void main(String[] args) {
        Integer N, K;
        BigDecimal ans, dN, dK, eps, prev, cur;
        String str = "0.", ansStr, toPr = new String();
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextInt();
        dN = new BigDecimal(N).setScale(K+5);
        //dK = new BigDecimal(K);
        //dN = new BigDecimal()
        for (int i = 0; i < K-1; i++)
        {
            str = str + "0";
        }
        str = str + "1";
        eps = new BigDecimal(str); //.setScale(K+5, RoundingMode.HALF_UP);

        ans = new BigDecimal(1).setScale(K+5);
        //prev = new BigDecimal(10).setScale(K+5);
        cur = new BigDecimal(10).setScale(K+5);
        while ( ( ( (ans.multiply(ans) ).subtract( dN ) ).abs() ).compareTo(eps) > 0 )
        {
            //System.out.println(ans);
            //ans = (ans.add( dN.divide(ans, K+5, RoundingMode.HALF_UP) ) ).divide( new BigDecimal(2.0), K+5, RoundingMode.HALF_UP );
            ans = ans.subtract( f(ans, dN).divide( fPrime(ans), K+5, RoundingMode.HALF_UP ) );
        }
        ansStr = ans.toString();
        //System.out.println(ansStr);
        for (int i = 0; i < ansStr.length() ;i++)
        {
            toPr = toPr + ansStr.charAt(i);
            if ( ansStr.charAt(i) == '.' ) {
                for (int j = i + 1; j <= i + K; j++) {
                    toPr = toPr + ansStr.charAt(j);
                }
                break;
            }
            else if ( i == ansStr.length()-1 )
            {
                toPr = toPr + '.';
                for (int j =  1; j <=  K; j++) {
                    toPr = toPr + '0';
                }
                break;
            }
        }
        System.out.println( toPr );
    }
}
