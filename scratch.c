#include <stdio.h>

/* Ascii is problem 7. Max ops: 15
    Less or Equal is problem 8. Max ops: 24 */

int fB(int x, int n) {
    int TMin_n = -(1 << (n-1));
    int TMax_n = (1 << (n-1)) - 1;
    
    int TMin_c = ~(1 << ~(~n + 1)) + 1; 
    int TMax_c = ~(~(1 << ~(~n + 1)) + 1); 
    
    int less_than = (~x) & TMax_n; 
    int greater_than = x & (~TMin_n); 
    return less_than & greater_than; 
}


    
int test_isAsciiDigit(int x) {
  return (0x30 <= x) && (x <= 0x39);
}

int isAsciiDigit(int x) {
    int max_digit = 0x39;
    int min_digit = 0x30;

    int lessCheck = (x + (~min_digit + 1));
    int less = (lessCheck >> 31) & 0x1;
    
    int greaterCheck = (max_digit + (~x + 1));
    int greater = (greaterCheck >> 31) & 0x1;

    return !(less | greater);
}


int test_isLessOrEqual(int x, int y)
{
  return x <= y;
}

int isLessOrEqual(int x, int y)
{
    int x_sign = (x >> 31) & 0x1;
    int y_sign = (y >> 31) & 0x1;
    int sameSign = x_sign ^ y_sign;
    
    printf("sameSign = %d\n", sameSign);
    
    int difference = (x + (~y + 1));
    int diff_sign = (difference >> 31) & 0x1;
    int is_equal = !difference;
    int lessEq = diff_sign | is_equal;
    
    return (x_sign & sameSign) | (lessEq & ~(sameSign));
}

int main() {
    int control = test_isLessOrEqual(-2147483648,-2147483648);
    int check = isLessOrEqual(-2147483648,-2147483648);
    
    printf("LessOrEqual control = 0x%x\n", control);
    printf("self check = 0x%x\n", check);
    return 0;
}