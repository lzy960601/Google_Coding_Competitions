import java.math.BigInteger;
import java.util.*;

public class A
{

    public static final Integer len = 105;
    public static BigInteger[] num = new BigInteger[len];
    public static BigInteger[][] fj = new BigInteger[len][2];
    public static Integer T = 0;
    public static BigInteger N = null;
    public static Integer n = 0;

    public static Scanner cin = null;

    public static void ReadForOne()
    {
        N = cin.nextBigInteger();
        n = cin.nextInt();
        for(Integer i = 1; i <= n; ++ i) num[i] = cin.nextBigInteger();
    }

    public static String Solve()
    {
        String ans = "";

        Integer label = 0;
        for(Integer i = 1; i < n; ++ i) if(!num[i].equals(num[i + 1])) {label = i; break;}
        BigInteger f1 = num[label].gcd(num[label + 1]);
        fj[label][1] = f1; fj[label][0] = num[label].divide(f1);
        for(Integer i = label - 1; i >= 1; -- i)
        {
            fj[i][1] = fj[i + 1][0];
            fj[i][0] = num[i].divide(fj[i][1]);
        }
        for(Integer i = label + 1; i <= n; ++ i)
        {
            fj[i][0] = fj[i - 1][1];
            fj[i][1] = num[i].divide(fj[i][0]);
        }
        Set<BigInteger> s = new HashSet<>(); s.clear();
        Map<BigInteger, Integer> m = new HashMap<>(); m.clear();
        for(Integer i = 1; i <= n; ++ i)
        {
            s.add(fj[i][0]);
            s.add(fj[i][1]);
        }
        List<BigInteger> lis = new ArrayList<>(); lis.clear();
        for(BigInteger p : s) lis.add(p);
        Collections.sort(lis);
        for(Integer i = 0; i < 26; ++ i) m.put(lis.get(i), i);
        for(Integer i = 1; i <= n; ++ i) ans += (char)(m.get(fj[i][0]) + 65);
        ans += (char)(m.get(fj[n][1]) + 65);

        return ans;
    }

    public static void main(String[] args)
    {
        cin = new Scanner(System.in);
        T = cin.nextInt();
        for(Integer cas = 1; cas <= T; ++ cas)
        {
            System.out.print("Case #" + cas.toString() + ": ");
            ReadForOne();
            System.out.println(Solve());
        }
    }
}
