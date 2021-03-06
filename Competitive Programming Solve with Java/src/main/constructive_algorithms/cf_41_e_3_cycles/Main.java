package main.constructive_algorithms.cf_41_e_3_cycles;

/**
 * Created by nafee on 2/14/18.
 */

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;


public class Main {

    static void redirectIO() throws IOException
    {
//        System.setIn(new FileInputStream("input.txt"));
//        System.setOut(new PrintStream("output.txt"));
    }

    public static void main(String[] args) throws Exception {

        redirectIO();
        Reader reader = new Reader();


        Solver solver = new Solver(reader);
        System.out.println( solver.solve() );
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


class Solver
{
    int numCity;

    public Solver(int numCity) {
        this.numCity = numCity;
    }

    public Solver(Reader reader) throws Exception {
        this.numCity = reader.nextInt();
    }

    String solve()
    {
        StringBuilder stringBuilder = new StringBuilder();
        int firHalf = numCity / 2;
        int secHalf = numCity - firHalf;

        int numEdges = firHalf * secHalf;
        stringBuilder.append ( numEdges + "\n" );

        for (int a = 1; a <= firHalf; a++ )
        {
            for (int b = firHalf+1; b <= numCity; b++)
            {
                stringBuilder.append(a + " " + b + "\n");
            }
        }

        return stringBuilder.toString();
    }
}

