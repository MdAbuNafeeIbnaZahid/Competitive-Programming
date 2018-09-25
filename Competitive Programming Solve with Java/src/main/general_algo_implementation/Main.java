package general_algo_implementation;

import java.util.*;

class PermutationGenerator
{
    private List< List<Integer> > permutations;


    private void makePerm( int upto, ArrayList<Integer> integerArrayList )
    {
        if ( upto == integerArrayList.size()-1 ) // upto = last index
        {
            permutations.add( new ArrayList<>(integerArrayList) );
            return;
        }

        Set<Integer> alreadyTaken = new HashSet<>();
        for (int i = upto+1; i < integerArrayList.size(); i++)
        {
            int nextPick = integerArrayList.get(i);

            if ( alreadyTaken.contains(nextPick) )
            {
                continue;
            }

            alreadyTaken.add(nextPick);

            Collections.swap(integerArrayList, i, upto+1);
            makePerm(upto+1, integerArrayList);
            Collections.swap(integerArrayList, i, upto+1);
        }
    }

    public List<List<Integer> > getAllPermutations(ArrayList<Integer> integerList)
    {
        this.permutations = new ArrayList<>();

        makePerm( -1, integerList );

        return permutations;
    }
}

public class Main {
    public static void main(String[] args) {
        PermutationGenerator permutationGenerator = new PermutationGenerator();

        ArrayList<Integer> integerList = new ArrayList<>();
        integerList.add(1);
        integerList.add(1);
        integerList.add(2);
        integerList.add(3);
        integerList.add(4);


        List list = permutationGenerator.getAllPermutations(integerList);
        System.out.println( list.size() );
        System.out.println( list );

    }
}
