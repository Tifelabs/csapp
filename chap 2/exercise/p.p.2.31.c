/* 
    Your coworker gets impatient with your analysis of the overflow conditions for two's complement addition
    and presents you with the following implementation of tadd_ok:

    // Determine whether arguments can be added without overflow
    // WARNING: This code is buggy

    int tadd_ok(int x, int y){
        int sum = x+y;
        return (sum - x == y) && (sum - y == x);
    }
*/

/* SOLUTION */

/* 
    The coworker could have learned, by using the solution in p.p.30.c, that two's complement
    addition forms an abelian group, and so the expression (x+y)-x will evaluate to y regardless of
    whether or not the addition overlflows, and that (x+y)-y will always evaluate to x

*/