import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class BalanceString {
    private final char minChar;
    private final char maxChar;
    private final int distinctChars; // total distinct char count,

    //public static final BalanceString EN_UPPER_INSTANCE = new BalanceString('A', 'Z');

    public BalanceString(char minChar, char maxChar) {
        this.minChar = minChar;
        this.maxChar = maxChar;
        this.distinctChars = maxChar - minChar + 1;

        if (distinctChars <= 0)
            throw new IllegalArgumentException("invalid range of chars: [" + minChar + ", " + maxChar + "]");
    }
    public int balanceCount(String str) {
        // System.out.printf("string to balance:\t%s\n", str);
        int len = str.length(); // get length,
        if (len <= 2) return 0; // corner cases,

        Map<Character, Integer> coMap = figureOccurs(str); // figure occurrences,
        Integer[] occurs = sortOccursReversely(coMap); // reversely order occurrences,

        int m = coMap.size(); // distinct char count,
        int maxN = (len < distinctChars ? len : distinctChars); // get max possible distinct char count, included,

        int smallestMoves = Integer.MAX_VALUE; // smallest moves, among all possible n,

        // check each possible n, and get its moves,
        for (int n = 1; n <= maxN; n++) {
            if (len % n == 0) {
                int moves = figureMoves(len, coMap, occurs, m, n);
                if (moves < smallestMoves) smallestMoves = moves;
            }
        }

        return smallestMoves;
    }

    protected Map<Character, Integer> figureOccurs(String str) {
        Map<Character, Integer> coMap = new HashMap<>();
        for (char c : str.toCharArray()) {
            if (c < minChar || c > maxChar)
                throw new IllegalArgumentException(c + " is not within range 'A-Z'");

            if (!coMap.containsKey(c)) coMap.put(c, 1);
            else coMap.put(c, coMap.get(c) + 1);
        }

        return coMap;
    }

    protected Integer[] sortOccursReversely(Map<Character, Integer> coMap) {
        Integer[] occurs = new Integer[coMap.size()];

        coMap.values().toArray(occurs);
        Arrays.sort(occurs, Collections.reverseOrder());

        return occurs;
    }

    protected int figureMoves(int len, Map<Character, Integer> coMap, Integer[] occurs, int m, int n) {
        int avgOccur = len / n; // average occurrence,
        int moves = 0;

        if (n == m) { // distinct chars don't change,
            for (Integer occur : occurs) {
                if (occur <= avgOccur) break;
                moves += (occur - avgOccur);
            }
        } else if (n < m) { // distinct chars decrease,
            for (int i = 0; i < n; i++) moves += Math.abs(occurs[i] - avgOccur); // for elements kept,
            for (int i = n; i < m; i++) moves += occurs[i]; // for elements to replace,
            moves >>= 1;
        } else { // distinct chars increase,
            for (int i = 0; i < occurs.length; i++) moves += Math.abs(occurs[i] - avgOccur); // for existing elements,
            moves += ((n - m) * avgOccur); // for new elements,
            moves >>= 1;
        }

        return moves;
    }

    public char getMinChar() {
        return minChar;
    }

    public char getMaxChar() {
        return maxChar;
    }

    public int getDistinctChars() {
        return distinctChars;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t;
        t=sc.nextInt();
        sc.nextLine();
        for(int i=0;i<t;i++){
            BalanceString m=new BalanceString('A', 'Z');
            String s;
            s=sc.nextLine();
            int ans=m.balanceCount(s);
            System.out.println(ans);
        }
    }
}