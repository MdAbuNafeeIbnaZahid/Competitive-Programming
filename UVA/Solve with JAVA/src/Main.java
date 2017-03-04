import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.Scanner;

///**
 //* Created by nafeedgbhs on 2/24/2016.
 //*/
public class Main {
    static final int SIZE = 2009;
    public static void main(String[] args) throws Exception{
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int startIdx[] =  new int[SIZE], endIdx[] = new int[SIZE];
        boolean taken[] = new boolean[6000];
        String str, numbersOnly;
        BigInteger ans = new BigInteger("0");
        int n;
        int i, j, k, x;
        for (i = 0; i < SIZE; i++)
        {
            startIdx[i] = -1;
            endIdx[i] = 6000;
        }
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        //System.out.println("n = " + n);
        str = scanner.nextLine();
        BigInteger bigInteger = new BigInteger("0");
        for (i = 1; i <= n; i++)
        {
            str = scanner.nextLine();
            //System.out.println("str = " + str);
            numbersOnly = str.replaceAll("[^0-9]", "");
            //System.out.println("numbersOnly = " + numbersOnly);
            x = Integer.parseInt(numbersOnly);
            if ( str.charAt(0)=='w' )
            {
                if ( i < endIdx[x] )
                {
                    startIdx[x] = i;
                }
            }
            else if (str.charAt(0)=='s')
            {
                endIdx[x] = i;
            }
        }
        //System.out.println();
        //System.out.println();
        //for (i = 1; i <= 12; i++)
        //{
            //System.out.println("x = " + i + ", start = " + startIdx[i] + ", end = " + endIdx[i]);
        //}
        for (i = 2000; i >= 0; i--)
        {
            bigInteger = new BigInteger("2");
            if (startIdx[i] >= 1 && endIdx[i] <= 5000)
            {
                for (j = startIdx[i]; j <= endIdx[i]; j++)
                {
                    if ( taken[j] ) break;
                }
                if (j > endIdx[i])
                {
                    //System.out.println("i = " + i);
                    for (k = startIdx[i]; k <= endIdx[i]; k++)
                    {
                        taken[k] = true;
                    }
                    BigInteger adde = bigInteger.pow(i);
                    //System.out.println("adde = " + adde);
                    ans = ans.add( adde );
                }
            }
        }
        System.out.println(ans);
    }
}
