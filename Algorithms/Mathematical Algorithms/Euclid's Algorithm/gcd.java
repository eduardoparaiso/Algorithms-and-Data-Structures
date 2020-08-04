/**
 * O(log(min(a, b)))
 */

public class gcd{
    public int recursive_gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return recursive_gcd(b, a%b);
    }

    public int iterative_gcd(int a, int b){
        while(b != 0){
            int r= a%b;
            a= b;
            b= r;
        }
        
        return a;
    }
}