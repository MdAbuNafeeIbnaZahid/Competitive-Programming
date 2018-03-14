package InterviewBit.random_problem.fraction;

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

        boolean isMinus = false;

        if ( (a<0 && b>=0) && (a>=0 && b<0) )
        {
            isMinus = true;
        }

        if (a < 0)
        {
            a *= -1;
        }

        if (b < 0)
        {
            b *= -1;
        }

        StringBuilder stringBuilder = new StringBuilder();

//        DivisionTask divisionTask = new DivisionTask(A, B);
//        DivisionResult resultBeforeDecimal = new DivisionResult(divisionTask);
//
//        stringBuilder.append( resultBeforeDecimal.divisionVal );
//
//        if ( resultBeforeDecimal.remainder != 0 )
//        {
//            return stringBuilder.toString();
//        }

        stringBuilder.append(a/b);

        if (a%b == 0)
        {
            return stringBuilder.toString();
        }

        stringBuilder.append(".");

        List<Long> numeratorsAfterDecimal = new ArrayList<>();
        Map<Long, Long> numeratorCount = new HashMap<>();

        long currentNumerator = (a%b)*10;

        while (currentNumerator != 0)
        {
            numeratorCount.merge( currentNumerator, (long)1, Long::sum);
            if ( numeratorCount.get(currentNumerator) == 2 )
            {
                break;
            }

            numeratorsAfterDecimal.add(currentNumerator);

            currentNumerator = (currentNumerator % b) * 10;
        }


        for (Long numerator : numeratorsAfterDecimal)
        {
            if ( numeratorCount.get(numerator) > 1 )
            {
                stringBuilder.append("(");
            }
            stringBuilder.append( numerator/b );
        }

        if (numeratorCount.containsValue((long)2))
        {
            stringBuilder.append(")");
        }


        String ret = stringBuilder.toString();
        if (isMinus)
        {
            ret = "-" + ret;
        }

        return ret;
    }



}
