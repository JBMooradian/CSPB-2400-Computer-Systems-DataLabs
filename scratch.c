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

int test_reverseBytes(int x)
{
    unsigned char byte0 = (x >> 0);
    printf("test byte0 = 0x%X\n", byte0);
    
    unsigned char byte1 = (x >> 8);
    printf("test byte1 = 0x%X\n", byte1);
    
    unsigned char byte2 = (x >> 16);
    printf("test byte2 = 0x%X\n", byte2);
    
    unsigned char byte3 = (x >> 24);
    printf("test byte3 = 0x%X\n", byte3);
    
    unsigned result = (byte0<<24)|(byte1<<16)|(byte2<<8)|(byte3<<0);
    return result;
}


int reverseBytes(int x) {
    int byte0 = (x & 0xFF);
    printf("byte0 = 0x%X\n", byte0);

    int iso_byte1 = (x >> 8);
    int byte1 = (iso_byte1 & 0xFF);
    printf("byte1 = 0x%X\n", byte1);

    int iso_byte2 = (x >> 16);
    int byte2 = (iso_byte2 & 0xFF);
    printf("byte2 = 0x%X\n", byte2);

    int iso_byte3 = (x >> 24);
    int byte3 = (iso_byte3 & 0xFF);
    printf("byte3 = 0x%X\n", byte3);

    int result = (byte0<<24)|(byte1<<16)|(byte2<<8)|(byte3<<0);
    return result;
    
}

int test_bitCount(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result += (x >> i) & 0x1;
  return result;
}

int bitCount(int x) {
    int bitsMask = (0x55 << 8) | 0x55;
    bitsMask = (bitsMask << 16) | bitsMask;
    int totCount = (x & bitsMask) + ((x >> 1) & bitsMask);

    int nybbleMask = (0x33 << 8) | 0x55;
    nybbleMask = (nybbleMask << 16) | nybbleMask;
    totCount = (totCount & nybbleMask) + ((totCount >> 2) & nybbleMask);

    int byteMask = (byteMask << 8) | 0xF;
    byteMask = (byteMask << 16) | 0xF;
    totCount = (totCount & byteMask) + ((totCount >> 4) & byteMask);

    int halfMask = (halfMask << 16) | 0xFF;
    totCount = (totCount & halfMask) + ((totCount >> 8) & halfMask);

    int finalMask = (finalMask << 8) | 0xFF;
    totCount = (totCount & finalMask) + ((totCount >> 16) & halfMask);

    return totCount;
}

int maskCheck(int x) {
    /* x = 0x001F7086 aka 00000000 00011111 01110000 10000110
                          00000000 00011010 01100000 01000101 */
    int bitsMask = 0x55;
    int result;
    bitsMask = (bitsMask << 8) | 0x55; /* 0x5555 0000 */
    bitsMask = (bitsMask << 16) | bitsMask; /* 0x5555 5555 */

    int bitsCount = (x & bitsMask) + ((x >> 1) & bitsMask);
    printf("bitsCount = 0x%X\n", bitsCount);

    int pairMask = 0x33;
    pairMask = (pairMask << 8) | 0x33;
    pairMask = (pairMask << 16) | pairMask;
    printf("pairMask = 0x%X\n", pairMask);
    
    int pairCount = (bitsCount & pairMask) + ((bitsCount >> 2) & pairMask);
    printf("pairCount = 0x%X\n", pairCount);

    int nibbleMask = 0xF;
    nibbleMask = (nibbleMask << 8) | 0xF;
    nibbleMask = (nibbleMask << 16) | nibbleMask;
    printf("nibbleMask = 0x%X\n", nibbleMask);

    int nibbleCount = (pairCount & nibbleMask) + ((pairCount >> 4) & nibbleMask);
    printf("nibbleCount = 0x%X\n", nibbleCount);

    int byteMask = 0xFF;
    byteMask = (byteMask << 16) | 0xFF;
    printf("byteMask = 0x%X\n", byteMask);

    int byteCount = (nibbleCount & byteMask) + ((nibbleCount >> 8) & byteMask);
    printf("byteCount = 0x%X\n", byteCount);

    int halfMask = 0xFF;
    halfMask = (halfMask << 8) | 0xFF;
    printf("halfMask = 0x%X\n", halfMask);

    int halfCount = (byteCount & halfMask) + ((byteCount >> 16) & halfMask);
    printf("halfCount = 0x%X\n", halfCount);

    return halfCount;
}





int test_logicalNeg(int x)
{
  return !x;
}
//any number that isn't zero needs to return zero. I need a way to convert any number
int logicalNeg(int x)
{    
    int not0 = ~(0); //full fill mask
    //printf("not0 = 0x%X\n", not0);
    
    int step1 = (5 >> 31); //all positive signs will be shoved off to zero
    printf("step1 = 0x%X\n", step1);
    
    int step2 = ((~5 + 1) >> 31) + 1; //all negative signs will be shoved off to 0xFFFFFFFF (-1)
    printf("step2 = 0x%X\n", step2);

    int combine = ((x >> 31) | ((~x) >> 31)) + 1; // combining both cases will result in 0xFFFFFFFF (-1) for any nonzero, so then add 1 to it. if zero, output will be 1. 
                                              // if not, output will be zero. 
    printf("combine = 0x%X\n", combine);

}
int troubleshoot(int x)
{
    return ((x >> 31) | ((~x) >> 31)) + 1;
}

/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */

int test_trueFiveEighths(int x)
{
  return (int) (((long long int) x * 5)/8);
}
/*
int trueFiveEighths(int x)
{
    int times5 = (x << 2) + x;
  
    int bias = (times5 >> 31) & 7; //generate bias to handle negative inputs, per textbook & slides
 
    int div8 = ((times5 + bias) >> 3);
    
    return div8;
}
*/
/* I worked on this sequentially. First, I set up the normal bitwise mult/div. This worked as expected for small positive integers. 
Next, I tried to tackle negative numbers, and had to review biases in the textbook. Here, bias is a number equal to the preceeding 
bits of the target division, which, in this case, is int 7. i.e. left shift 3 bits, add bias of 3 "on" bits; 0111 = 7. This didn't 
work as intended right away. It took me a while to realize that in cases where bias is needed, I also needed to perform division first, 
making me reorder my operations from the original, something like div8 = (times5 >> 3). However, just adding bias to my equations disrupted 
the rest of the expected outcomes. Trying and failing a few different attempts at (result0 & flag) | (result1 & ~(flag) got me nowhere. 
While floating point is not used here, after reading the section and watching the lectures, I came to see how doing two separate sets of operations 
on input--one without the bias and one with the bias--creates a split between them, something we saw in lecture as denormalization. Because bitwise 
operations are changes done on the word, rather than "creating a new number", the operations without bias changes them in one direction, and with bias 
changes them in another. This creates a difference, which can be "normalized" by inverting the difference, i.e. adding the two "pieces of the whole" back 
together. This handles both negative number cases and protects against overflow cases by keeping positive numbers over a 2-bit buffer (right shift 2) and 
negative numbers under a 3-bit buffer (2-bit buffer + MS sign bit = 3 bits, via bias 0111).  */
int trueFiveEighths(int x) {
    int div8 = x >> 3;
    int noBias = (div8 << 2) + div8;
    int bias = x & 7;
    int withBias = (((bias << 2) + bias) + ((x >> 31) & 7)) >> 3; 
    return noBias + withBias;
}

    

int main() {
    int control = test_trueFiveEighths(11);
    int selftest = trueFiveEighths(11);
    
    int checkOver = trueFiveEighths(0x30000000);
    int checkneg = trueFiveEighths(-9);

    int proof = 0xFF | (0xFF << 8);
    printf("Proof = 0x%X\n", proof);
    
    printf("trueFiveEighths control = 0x%X\n", control);
    printf("selftest = 0x%X\n", selftest);
    printf("checkOverFlow = 0x%X\n", checkOver);
    printf("checkneg = %d\n", checkneg);
    
    return 0;
}





































