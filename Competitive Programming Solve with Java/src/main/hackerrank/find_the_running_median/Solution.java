package hackerrank.find_the_running_median;

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

class IntRevComp implements Comparator<Integer>
{
    public int compare(Integer a, Integer b)
    {
        return b-a;
    }
}


public class Solution {

    /*
     * Complete the runningMedian function below.
     */
    static double[] runningMedian(int[] a) {
        int len = a.length;
        double[] ret = new double[len];

        PriorityQueue<Integer> smallerHalf = new PriorityQueue<>( new IntRevComp() );
        PriorityQueue<Integer> biggerHalf = new PriorityQueue<>(  );


        for (int idx = 0; idx < len; idx++)
        {
            int curInt = a[idx];
            if ( smallerHalf.isEmpty() || curInt <= smallerHalf.peek() )
            {
                smallerHalf.add(curInt);
                if ( smallerHalf.size() > biggerHalf.size()+1 )
                {
                    biggerHalf.add( smallerHalf.poll() );
                }
            }
            else
            {
                biggerHalf.add(curInt);
                if ( biggerHalf.size() > smallerHalf.size() )
                {
                    smallerHalf.add( biggerHalf.poll() );
                }
            }



            if ( smallerHalf.size() > biggerHalf.size() )
            {
                ret[idx] = smallerHalf.peek();
            }
            else
            {
                int smallMedian = smallerHalf.peek();
                int bigMedian = biggerHalf.peek();
                ret[idx] = ( smallMedian + bigMedian ) / 2.0;
            }
        }

        /*
         * Write your code here.
         */


        return ret;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
//        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

            BufferedWriter  bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        int aCount = Integer.parseInt(scanner.nextLine().trim());

        int[] a = new int[aCount];

        for (int aItr = 0; aItr < aCount; aItr++) {
            int aItem = Integer.parseInt(scanner.nextLine().trim());
            a[aItr] = aItem;
        }

        double[] result = runningMedian(a);

        for (int resultItr = 0; resultItr < result.length; resultItr++) {
            bufferedWriter.write(String.valueOf(result[resultItr]));

            if (resultItr != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
