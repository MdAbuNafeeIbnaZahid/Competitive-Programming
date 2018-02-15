package codeforces.constructive_algorithms.cf_848_B_rooster_song;

/**
 * Created by nafee on 2/14/18.
 */

import java.io.*;
import java.util.*;


public class Main {

    static void redirectIO() throws IOException
    {
        System.setIn(new FileInputStream("input.txt"));
        System.setOut(new PrintStream("output.txt"));
    }

    public static void main(String[] args) throws IOException {

        //redirectIO();
        Reader reader = new Reader();

        Problem problem = new Problem(reader);

        System.out.println( problem.solve() );
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



class Problem
{
    private static final int SIZE = 100009;
    
    int n, w, h;
    List<Dancer> dancerList = new ArrayList<Dancer>();



    class Point implements Comparable
    {
        int idx, x, y;


        public Point(int idx, int x, int y) {
            this.idx = idx;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Object o) {
            Point B = (Point)o;

            // x small, y big
            if ( x == B.x )
            {
                return B.y - y;
            }
            return x - B.x;

        }

        int getSum()
        {
            return x + y;
        }
    }


    class Dancer
    {
        int idx, g, p, t;

        public Dancer(int idx, int g, int p, int t) {
            this.idx = idx;
            this.g = g;
            this.p = p;
            this.t = t;
        }

        Point getStartingPoint()
        {
            if (g == 1) // vertical
            {
                return new Point(idx, p, -t);
            }
            else if (g == 2) // horizontal
            {
                return new Point(idx, -t, p );
            }

            assert false;
            return null;
        }

        Point getEndPoint()
        {
            if (g == 1) // vertical
            {
                return new Point(idx, p, h);
            }
            else if (g == 2) // horizontal
            {
                return new Point(idx, w, p );
            }

            assert false;
            return null;
        }


    }




    Point ansAr[] = new Point[ SIZE ];

    Map<Integer, SortedSet<Point> > sumStartingPoints = new HashMap<>();
    Map<Integer, SortedSet<Point> > sumEndPoints = new HashMap<>();


    Problem(){}

    Problem(Reader reader) throws IOException
    {
        n = reader.nextInt();
        w = reader.nextInt();
        h = reader.nextInt();

        for (int a = 0; a < n; a++)
        {
            int gi = reader.nextInt();
            int pi = reader.nextInt();
            int ti = reader.nextInt();

            dancerList.add( new Dancer(a, gi, pi, ti) );
        }
    }

    void makeSumPoints()
    {
        for (int a = 0; a < n; a++)
        {
            Dancer dancer = dancerList.get(a);
            Point startingPoint  = dancer.getStartingPoint();
            int sum =startingPoint.getSum();

            Point endPoint = dancer.getEndPoint();

            if ( ! sumEndPoints.containsKey(sum) )
            {
                sumStartingPoints.put(sum, new TreeSet<Point>());
                sumEndPoints.put(sum, new TreeSet<Point>());
            }

            sumStartingPoints.get(sum).add(startingPoint);
            sumEndPoints.get(sum).add(endPoint);
        }
    }

    void makeAnsAr()
    {
        for ( Integer sum : sumStartingPoints.keySet() )
        {
            SortedSet startPoints = sumStartingPoints.get(sum);
            SortedSet endPoints = sumEndPoints.get(sum);

            assert startPoints.size() == endPoints.size();

            Iterator<Point> itStart = startPoints.iterator();
            Iterator<Point> itEnd = endPoints.iterator();
            while (itStart.hasNext())
            {
                Point start = itStart.next();
                Point end = itEnd.next();
                ansAr[start.idx] = end;
            }
        }
    }

    String solve()
    {
        makeSumPoints();
        makeAnsAr();
        StringBuilder stringBuilder = new StringBuilder();
        for (int a = 0; a < n; a++)
        {
            String str = "" + ansAr[a].x + " " + ansAr[a].y + "\n";
            stringBuilder.append(str);
        }
        return stringBuilder.toString();
    }

}







