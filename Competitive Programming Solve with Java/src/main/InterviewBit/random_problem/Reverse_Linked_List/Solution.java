package main.InterviewBit.random_problem.Reverse_Linked_List;

/**
 * Created by nafee on 3/14/18.
 */

class ListNode {
      public int val;
      public ListNode next;
      ListNode(int x) { val = x; next = null; }
  }

public class Solution
{
    public ListNode reverseList(ListNode A) {
        if (A == null)
        {
            return null;
        }

        if (A.next == null)
        {
            return A;
        }

        ListNode first = A;
        ListNode second = A.next;

        while (second != null)
        {
            ListNode third = second.next;

            second.next = first;

            first = second;
            second = third;
        }

        A.next = null;

        return first;
    }

    ListNode recursiveReverse(ListNode parent, ListNode current)
    {
        if (current == null)
        {
            return parent;
        }

        ListNode child = current.next;

        current.next = parent;

        return recursiveReverse(current,  child);
    }

}
