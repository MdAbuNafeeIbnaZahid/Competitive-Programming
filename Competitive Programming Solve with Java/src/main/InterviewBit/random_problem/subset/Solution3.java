package main.InterviewBit.random_problem.subset;

import java.util.ArrayList;
import java.util.Collections;

/**
 * Created by nafee on 3/16/18.
 */
public class Solution3
{
    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> A) {
        Solver solver = new Solver(A);
        return solver.getSubsetList();
    }

}

class Solver
{
    ArrayList<Integer> input;
    ArrayList<ArrayList<Integer>> subsetList;

    public Solver(ArrayList<Integer> input) {
        Collections.sort(input);
        this.input = input;
        subsetList = new ArrayList<>();
    }

    private void generateSubsetRecursively(int idx, ArrayList<Integer> temp)
    {
        subsetList.add( new ArrayList<Integer>(temp) );
        for (int i = idx; i < input.size(); i++)
        {
            temp.add(input.get(i));
            generateSubsetRecursively(i+1, temp);
            temp.remove( temp.size()-1 );
        }
    }

    public ArrayList<ArrayList<Integer>> getSubsetList() {
        generateSubsetRecursively(0, new ArrayList<Integer>());
        return subsetList;
    }
}
