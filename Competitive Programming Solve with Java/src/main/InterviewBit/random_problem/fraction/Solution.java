package main.InterviewBit.random_problem.fraction;

import java.util.*;

/**
 * Created by nafee on 3/14/18.
 */




public class Solution {


    class DivisionTask
    {
        long numerator;
        long denominator;

        public DivisionTask(long numerator, long denominator) {
            this.numerator = numerator;
            this.denominator = denominator;
        }
    }

    class DivisionResult
    {
        long divisionVal;
        long remainder;

        public DivisionResult(DivisionTask divisionTask)
        {
            this.divisionVal = divisionTask.numerator / divisionTask.denominator;
            this.remainder = divisionTask.numerator % divisionTask.denominator;
        }
    }


    class Division
    {
        DivisionTask divisionTask;
        DivisionResult divisionResult;

        public Division()
        {
        }

        public Division(DivisionTask divisionTask, DivisionResult divisionResult) {
            this.divisionTask = divisionTask;
            this.divisionResult = divisionResult;
        }
    }


    public String fractionToDecimal(int A, int B)
    {
        long a = A;
        long b = B;

        if (A == 0)
        {
            return "0";
        }

        boolean isMinus = (a<0) ^ (b<0);
        a = Math.abs(a);
        b = Math.abs(b);


        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append( isMinus ? "-" : "" );

        stringBuilder.append(a/b);




        if (a%b == 0)
        {
            return stringBuilder.toString();
        }

        stringBuilder.append(".");

        Map<Long, Long> numeratorPositions = new HashMap<>();

        long currentNumerator = (a%b)*10;

        while (currentNumerator != 0)
        {
            if ( numeratorPositions.containsKey(currentNumerator) )
            {
                long prevPosition = numeratorPositions.get(currentNumerator);
                stringBuilder.insert((int)prevPosition, "(");
                stringBuilder.append(")");
                return stringBuilder.toString();
            }

            numeratorPositions.put( currentNumerator, (long)stringBuilder.length() );
            stringBuilder.append( currentNumerator/b );
            currentNumerator = (currentNumerator % b) * 10;
        }


        return stringBuilder.toString();
    }



}
