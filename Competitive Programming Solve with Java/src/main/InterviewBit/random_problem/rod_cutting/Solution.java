package InterviewBit.random_problem.rod_cutting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/**
 * Created by nafee on 6/5/18.
 */
public class Solution {

    private int A;
    private ArrayList<Integer> B;

    private long[][] cutIdx, cost;
    int weakPointCnt;
    private ArrayList<Integer> cutSeq = new ArrayList<>();

    private void saveInput(int A, ArrayList<Integer> B)
    {
        this.A = A;

        B = new ArrayList<>(B);
        Collections.sort(B);
        B.add(0, 0);
        B.add(A);

        weakPointCnt = B.size();

        this.B = B;
    }

    private void init2dAr()
    {
        cutIdx = new long[weakPointCnt][weakPointCnt];
        cost = new long[weakPointCnt][weakPointCnt];


        for (int i = 0; i < weakPointCnt; i++)
        {
            for (int j = 0; j < weakPointCnt; j++)
            {
                cost[i][j] = -1;
            }
        }
    }


    private long getDp(int startIdx, int endIdx)
    {
        if ( cost[startIdx][endIdx] == -1 )
        {
            cost[startIdx][endIdx] = getDpNew(startIdx, endIdx);
        }
        return cost[startIdx][endIdx];
    }

    private long getDpNew(int startIdx, int endIdx)
    {
        if (startIdx == endIdx-1)
        {
            return 0;
        }

        int curLen = B.get(endIdx) - B.get(startIdx);
        long minCost = Long.MAX_VALUE;

        for (int idx = startIdx+1; idx < endIdx; idx++)
        {
            long curCost = getDp(startIdx, idx) + curLen + getDp(idx, endIdx);
            if ( curCost < minCost )
            {
                minCost = curCost;
                cutIdx[startIdx][endIdx] = idx;
            }
        }

        return minCost;
    }

    private void generateCutSeq(int startIdx, int endIdx)
    {
        if (startIdx == endIdx-1)
        {
            return;
        }

        int curCutIdx = (int)cutIdx[startIdx][endIdx];
        int curCutPoint = B.get(curCutIdx);

        cutSeq.add(curCutPoint);

        generateCutSeq(startIdx, curCutIdx);
        generateCutSeq(curCutIdx, endIdx);
    }

    private void generateCutSeq()
    {
        generateCutSeq(0, weakPointCnt-1);
    }

    public ArrayList<Integer> rodCut(int A, ArrayList<Integer> B) {
        saveInput(A, B);
        init2dAr();
        getDp(0, weakPointCnt-1);
        generateCutSeq();

        return cutSeq;
    }
}
