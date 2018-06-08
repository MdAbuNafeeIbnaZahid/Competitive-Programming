package codeforces._981_d_bookshelves;

/**
 * Created by nafee on 6/8/18.
 */
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;

public class Main {

    static void redirectIO() throws IOException
    {
//        System.setIn(new FileInputStream("input.txt"));
//        System.setOut(new PrintStream("output.txt"));
    }

    public static void main(String[] args) throws IOException {

        redirectIO();

        Reader reader = new Reader();
        Solution solution = new Solution(reader);

        System.out.println( solution.getAns() );
    }
}


class Reader
{
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException
    {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String next() throws IOException
    {
        byte[] buf = new byte[64]; // String length
        int cnt = 0, c;
        while ((c = read()) != -1)
        {
            if (c=='\n' || c==' ')
                break;
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public String readLine() throws IOException
    {
        byte[] buf = new byte[64]; // line length
        int cnt = 0, c;
        while ((c = read()) != -1)
        {
            if (c == '\n')
                break;
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException
    {
        int ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do
        {
            ret = ret * 10 + c - '0';
        }  while ((c = read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    public long nextLong() throws IOException
    {
        long ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }

    public double nextDouble() throws IOException
    {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();

        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');

        if (c == '.')
        {
            while ((c = read()) >= '0' && c <= '9')
            {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }

    private void fillBuffer() throws IOException
    {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private byte read() throws IOException
    {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException
    {
        if (din == null)
            return;
        din.close();
    }
}




class DpQuery
{
    long book, shelf, beauty;

    public DpQuery(long book, long shelf, long beauty) {
        this.book = book;
        this.shelf = shelf;
        this.beauty = beauty;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof DpQuery)) return false;

        DpQuery dpQuery = (DpQuery) o;

        if (book != dpQuery.book) return false;
        if (shelf != dpQuery.shelf) return false;
        return beauty == dpQuery.beauty;
    }

    @Override
    public int hashCode() {
        int result = (int) (book ^ (book >>> 32));
        result = 31 * result + (int) (shelf ^ (shelf >>> 32));
        result = 31 * result + (int) (beauty ^ (beauty >>> 32));
        return result;
    }
}





class Solution
{
    Reader reader;
    long n, k;
    long aAr[];

    long cumSumA[];

    Map<DpQuery, Boolean> map = new HashMap<>();

    Solution(Reader reader) throws IOException
    {
        this.reader = reader;

        n = reader.nextLong();
        k = reader.nextLong();

        aAr = new long[(int)n+9];
        cumSumA = new long[(int)n+9];
        cumSumA[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            aAr[i] = reader.nextLong();
            cumSumA[i] = cumSumA[i-1] + aAr[i];
        }
    }


    private boolean getDp(long book, long shelf, long beauty)
    {
        if ( shelf == 0 )
        {
            return (book==0);
        }

        if (shelf > book)
        {
            return false;
        }

        DpQuery dpQuery = new DpQuery(book, shelf, beauty);
        if ( ! map.containsKey(dpQuery) )
        {
            boolean ret = calculateDp(book, shelf, beauty);
            map.put(dpQuery, ret);
        }

        boolean ret = map.get(dpQuery);
        return ret;
    }

    private boolean calculateDp(long book, long shelf, long beauty) {
        DpQuery dpQuery = new DpQuery(book, shelf, beauty);

        for (int bookInThisShelf = 1; book-bookInThisShelf >= shelf-1; bookInThisShelf++)
        {
            long bookRemaining = book - bookInThisShelf;

            long shelfValue = cumSumA[(int)book] - cumSumA[ (int) bookRemaining ];
            if ( (shelfValue & beauty) != beauty )
            {
                continue;
            }

            boolean posRet = getDp(bookRemaining, shelf-1, beauty );
            if (posRet)
            {
                return true;
            }
        }

        return false;
    }

    long getAns()
    {
        long ans = 0;

        for (int pos = 59; pos >= 0; pos--)
        {
            long posAns = ans | ( ( (long)1 ) << pos) ;

            boolean isPos = getDp(n, k, posAns);
            if (isPos)
            {
                ans = posAns;
            }
        }

        return ans;
    }
}
