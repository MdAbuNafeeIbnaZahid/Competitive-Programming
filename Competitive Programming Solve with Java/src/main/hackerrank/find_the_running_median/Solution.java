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



class MinHeap<E>
{
    public final int INIT_SIZE = 10;

    private int size = 0;
    private int capacity = INIT_SIZE;
    private Comparator<E> comparator;
    private E[] items = (E[]) new Object[capacity];;

    public MinHeap(Comparator<E> comparator)
    {
        this.comparator = comparator;
    }

    private boolean isFull( )
    {
        return size >= capacity;
    }

    private void increaseCapacity()
    {
        items = Arrays.copyOf(items, capacity*2);
        capacity *= 2;
    }

    private void ensureExtraCapacity()
    {
        if ( isFull() )
        {
            increaseCapacity();
        }
    }

    public boolean isEmpty()
    {
        return size == 0;
    }

    public int getSize() {
        return size;
    }

    private void assertIdxOk(int idx)
    {
        assert idx <= 0 && idx < size;
    }

    private int getParentIdx(int childIdx) { return (childIdx-1)/2;  }
    private int getLeftChildIdx(int parentIdx) { return 2*parentIdx + 1; }
    private int getRightChildIdx(int parentIdx) {return 2*parentIdx + 2; }

    private boolean hasParent(int childIdx){ return getParentIdx(childIdx) >= 0; }
    private boolean hasLeftChild(int parentIdx){ return getLeftChildIdx(parentIdx) < size; };
    private boolean hasRightChild(int parentIdx) { return getRightChildIdx(parentIdx) < size; }

    private E getParent(int childIdx)
    {
        assert hasParent(childIdx);
        return items[getParentIdx(childIdx)];
    }

    private E getLeftChild(int parentIdx)
    {
        assert( hasLeftChild(parentIdx) );
        return items[getLeftChildIdx(parentIdx)];
    }

    private E getRightChild(int parentIdx)
    {
        assert( hasRightChild(parentIdx) );
        return items[getRightChildIdx(parentIdx)];
    }

    private boolean hasBiggerParent(int idx)
    {
        assertIdxOk(idx);
        if ( ! hasParent(idx) )
        {
            return false;
        }

        return comparator.compare(getParent(idx), items[idx]) > 0;
    }

    private boolean hasSmallerLeftChild(int idx)
    {
        assertIdxOk(idx);
        if ( ! hasLeftChild(idx) )
        {
            return false;
        }

        return comparator.compare(getLeftChild(idx), items[idx]) < 0;
    }

    private boolean hasSmallerRightChild(int idx)
    {
        assertIdxOk(idx);
        if ( !hasRightChild(idx) )
        {
            return false;
        }

        return comparator.compare(getRightChild(idx), items[idx]) < 0;
    }

    private void swap(int idx1, int idx2)
    {
        assertIdxOk(idx1);
        assertIdxOk(idx2);

        E temp = items[idx1];
        items[idx1] = items[idx2];
        items[idx2] = temp;
    }

    private void bubbleUp(int idx)
    {
        if ( hasBiggerParent(idx) )
        {
            int parentIdx = getParentIdx(idx);
            swap(idx, parentIdx);
            bubbleUp( parentIdx );
        }
    }

    private void bubbleDown( int idx )
    {
        if (  hasSmallerLeftChild(idx) && hasSmallerRightChild(idx)  )
        {
            E leftChild = getLeftChild(idx);
            E rightChild = getRightChild(idx);

            if ( comparator.compare(leftChild, rightChild) < 0 )
            {
                swapAndBubbleDown(idx, getLeftChildIdx(idx));
            }
            else
            {
                swapAndBubbleDown(idx, getRightChildIdx(idx));
            }
        }
        else if ( hasSmallerLeftChild(idx)   )
        {
            swapAndBubbleDown(idx, getLeftChildIdx(idx));
        }
        else if ( hasSmallerRightChild(idx) )
        {
            swapAndBubbleDown(idx, getRightChildIdx(idx));
        }
    }

    private void swapAndBubbleDown(int parentIdx, int childIdx)
    {
        assertIdxOk(parentIdx);
        assertIdxOk(childIdx);

        swap(parentIdx, childIdx);
        bubbleDown(childIdx);
    }

    void add(E e)
    {
        ensureExtraCapacity();
        items[size++] = e;
        bubbleUp(size-1);
    }

    E peek()
    {
        if (size <= 0)
        {
            throw new IllegalStateException("Heap is empty");
        }

        return items[0];
    }

    E poll()
    {
        if (size <= 0)
        {
            throw new IllegalStateException("Heap is empty");
        }

        E ret = items[0];

        swap(0, size-1);
        size--;
        bubbleDown(0);

        return ret;
    }

    @Override
    public String toString() {
        return "MinHeap{" +
                "size=" + size +
                ", capacity=" + capacity +
                ", items=" + Arrays.toString(items) +
                '}';
    }
}


public class Solution {

    /*
     * Complete the runningMedian function below.
     */
    static double[] runningMedian(int[] a) {
        int len = a.length;
        double[] ret = new double[len];

        MinHeap<Integer> smallerHalf = new MinHeap<>( new IntRevComp() );
        MinHeap<Integer> biggerHalf = new MinHeap<>( Comparator.<Integer>naturalOrder() );


        for (int idx = 0; idx < len; idx++)
        {
            int curInt = a[idx];
//            System.out.println( curInt );

            if ( smallerHalf.isEmpty() || curInt <= smallerHalf.peek() )
            {
                smallerHalf.add(curInt);
//                System.out.println("smallerHalf = " + smallerHalf);
                if ( smallerHalf.getSize() > biggerHalf.getSize()+1 )
                {
                    biggerHalf.add( smallerHalf.poll() );
                }
//                System.out.println("smallerHalf = " + smallerHalf);
            }
            else
            {
                biggerHalf.add(curInt);
//                System.out.println("biggerHalf = " + biggerHalf);
                if ( biggerHalf.getSize() > smallerHalf.getSize() )
                {
                    smallerHalf.add( biggerHalf.poll() );
                }

//                System.out.println("smallerHalf = " + smallerHalf);
//                System.out.println("biggerHalf = " + biggerHalf);
            }



            if ( smallerHalf.getSize() > biggerHalf.getSize() )
            {
                ret[idx] = smallerHalf.peek();
            }
            else
            {
                int smallMedian = smallerHalf.peek();
                int bigMedian = biggerHalf.peek();
                ret[idx] = ( smallMedian + bigMedian ) / 2.0;
            }

//            System.out.println( smallerHalf );
//            System.out.println( biggerHalf );
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
