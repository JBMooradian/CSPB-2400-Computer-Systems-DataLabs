/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically and a negative shift value results in zero.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES, FOLLOW THE DIRECTIONS in README.md
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~(~x & ~y);
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
    /* Takes advantage of the def of the NOT op as logical: 1 == True, 0 == False.
     * Therefore, if x == 0 (read as False) then NOT False == True (read as 1). Any other input will give
     * NOT input, which is False, i.e. 0. Basically, 0 the integer overlaps with 0 the boolean.
     */
    return !x;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
    /* Had to build a scratch main.c to trial and error this one! I found that left-shifting max legal int 
    of 0xFF by larger and larger numbers got me closer to max, but once I went for the mathematical  
    definition of 2^31 (ignoring -1 for testing), I hit overflow, and got a negative close to max (-2147483393). 
    Since this is the complement, I recalled the bitOr walkthrough and tried out the bitwise NOT on the shift, and I got it!
    */
    int x = 0xFF;
    return ~(x << 31);
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
    /* Reference: Check if 1 | 0: (X & 1 = X) Mask to 0: (X & 0 = 0). Need to create a mask that will cover 
    each odd bit; AND-ing int x with an odd bit mask will be nonzero if an odd bit exists. From slides: 1010 = 0xA.
    Must build full mask: 0xAAAAAAAA using bitshift and OR (Just saw the hint on DataLab report thread. 
    Glad I'm on the right  track! The final product performs 2 OR shifts to "append" sufficient AAs to oddMask. Return bitwise NOT of mask to 0*/
    int oddMask = 0xAA;
    int result;
    oddMask = (oddMask << 8) | 0xAA; /* 0xAAAA 0000 */
    oddMask = (oddMask << 16) | oddMask; /* 0xAAAA AAAA */
   
    result = !(x & oddMask); /* mask all odd bits against input, and also make it a bool (troubleshooting for edge case) */
    
    return !result; /* Same logic as isZero: bits exist = 1; bits don't exist = 0 */
}

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    /* We're tracking the number of bits an int can fit within, and comparing it to input n. I like to think of this trick as a "compactor". 
    First, find how big the compactor is by determining the number of unused bits (total - n). 
    Next, turn on the compactor by left shifting input x all the way to the "wall" of the MSB, leaving only enough room for int n (fit size). 
    Finally, turn off the compactor by right shifting the result back to normal. 
    If x fits, its value will be retained even after this squish and stretch, so compare the transformed x with the original. 
    It's important that the right shift is arithmetic (standard for this machine), because the "squish" part (left shift) is determining the 
    bit size of the two's complement of x, not x itself. That way, "danger zones" like (-4, 3) will retain x's signage by stretching a series of 1's back across the compactor. 
    Kind of a gross image!*/
    
    int result;
    int num_bits = 32 + ~(n) + 1;
    int left_flood = (x << num_bits);

    int arith_right = (left_flood >> num_bits);

    result = (x ^ arith_right);

    return !result;
    
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
    /* This one took me a long time. I implemented an isZero check that worked fine, but getting the mask to work was killer. 
    I stepped through every combination of operations between a large/small mask (partially for learning), but nothing was getting close. 
    There's an example of a get_MSB function in the textbook, but I couldn't find a feasible inverse. Finally, I had to look it up, and learned about the x & -x solution, 
    implemented here. I also learned that the isZero check I put together was unnecessary. Whew! */
    return x & (~(x) + 1);
}

/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    /* I spent a long time on fitsBits translating the test code verbatim to bitwise, and that was a massive help for this puzzle. 
    Essentially, lessCheck takes x - the min, and 'less' holds the MSB, which, if 1, means the difference was negative, i.e. x < min. 
    greaterCheck/greater does the same in reverse. Finally, less and greater are OR'd together, and, since either flagging as True puts x out of range, the ! of the OR is returned.
    */
    int max_digit = 0x39;
    int min_digit = 0x30;

    int lessCheck = (x + (~min_digit + 1));
    int less = (lessCheck >> 31) & 0x1;
    
    int greaterCheck = (max_digit + (~x + 1));
    int greater = (greaterCheck >> 31) & 0x1;

    return !(less | greater);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    /* I was initially confused why this puzzle had such a high ops threshold; I just added 1 to y and copy/pasted lessCheck from above. 
    Then I ran the tests, and saw the problem. It was also good that I needlessly added a if/then check on my first attempt at leastBitPos, because I had a better foundation to figure one 
    out here. I spent a while building a check for when x is TMin and y is TMax, only to hit another bump when both are set to TMin. 
    I realized I had neglected the "equal" part of <=, so adding another check on the sign of the difference resolved cases where both inputs are negative and equal.
    */
    int x_sign = (x >> 31) & 0x1;
    int y_sign = (y >> 31) & 0x1;
    int sameSign = x_sign ^ y_sign;
    
    int difference = (x + (~y + 1));
    int diff_sign = (difference >> 31) & 0x1;
    int is_equal = !difference;
    int lessEq = diff_sign | is_equal;
    
    return (x_sign & sameSign) | (lessEq & ~(sameSign));
}

/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */


int reverseBytes(int x) {
    /* This one, comparatively, was much easier for me. The test code was much more involved, and that gave me a bigger hint as to how I should
    isolate each byte. The real trick for me was finding a translation that would work for signed ints, rather than unsigned char. 
    But this was really only a matter of adding a mask that zeroed out any bits but the first 8, which, after shifting, would always be the target byte.
    Then, just like the test example, I simply had to shift each back into place and OR them all together. 
    */
    
    int byte0 = (x & 0xFF);

    int iso_byte1 = (x >> 8);
    int byte1 = (iso_byte1 & 0xFF);

    int iso_byte2 = (x >> 16);
    int byte2 = (iso_byte2 & 0xFF);

    int iso_byte3 = (x >> 24);
    int byte3 = (iso_byte3 & 0xFF);

    int result = (byte0<<24)|(byte1<<16)|(byte2<<8)|(byte3<<0);
    return result;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */

int bitCount(int x) {
    /* This was a whopper. It took me a few hours to figure out how to construct masks that would produce a single-word count for each
    number of bits. I have many lines of printfs in my scratch.c, but I finally managed to crack it. Then, it took me at least another
    two hours to figure out why my code was passing btest but throwing undeclared errors on driver. After a few searches, I realized I needed
    to collapse the "anyOddBit" model I was using into single lines, and then perform the final operations on x sequentially, after all of the
    masks were declared. */ 
    
    int everyOther = 0x55 | (0x55 << 8) | (0x55 << 16) | (0x55 << 24);
    int nibbles = 0x33 | (0x33 << 8) | (0x33 << 16) | (0x33 << 24);
    int bytes = 0x0F | (0x0F << 8) | (0x0F << 16) | (0x0F << 24);
    int lsHalf = 0xFF | (0xFF << 16);
    int msHalf = 0xFF | (0xFF << 8);

    x = (x & everyOther) + ((x >> 1) & everyOther);
    x = (x & nibbles) + ((x >> 2) & nibbles);
    x = (x & bytes) + ((x >> 4) & bytes);
    x = (x & lsHalf) + ((x >> 8) & lsHalf);
    x = (x & msHalf) + ((x >> 16) & msHalf);
    return x;
}

    
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    /* Ugh, another killer. My first thoughts were to OR the input against ~0, which floods it to all 1s, and then add 0x1 which overflows back to 0x0. This worked... 
    for all numbersincluding 0. Then I went back to the FLAG DataLab tip, and recalled how I had attempted to implement an "isZero" check on my first overthink of TMAX. I tried a version of this, 
    which would take ~(x) and XOR it against either 0 or ~(0), which was a more complicated walk back to the original problem. I went through several printf commands trying x and ~(x)
    against 0 and ~(0) using all of the legal ops, but I could only ever get a function that returned 0 for ALL numbers, or returned 1 for 0, and then some form of a very large number for
    anything else. I set it in the corner for a while. When I came back, I remembered how in fitsBits, I used an arithmetic shift on the "compactor" release, and was reminded of how I
    could "squish out" all of the information of a bit word by doing a maximum left shift. Since bit 32 is reserved for the sign, left shifting any positive number by 31 will zero it
    out, and left-shifting any negative number will max it out. OR'ing these two together guarantees a max fill, which should mean that adding 1 to it will result in 0 for ints and 1
    for zero. However, in my printchecks, it was still frustratingly giving 0x0 for all numbers including zero. Finally, I realized the trick to getting 1 out of ~0: adding 1 to it. For
    any other positive or negative number, this is irrelevant, as it will just get shifted out anyway. However, for 0 and -1, adding 1 on that side will overflow before the left shift
    happens, guaranteeing two 0s OR'd together, with 1 added to it at the end. 
    */
    
  return ((x >> 31) | ((~x + 1) >> 31)) + 1;
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
int trueFiveEighths(int x) {
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
    
    int div8 = x >> 3;
    int noBias = (div8 << 2) + div8;
    int bias = x & 7;
    int withBias = (((bias << 2) + bias) + ((x >> 31) & 7)) >> 3; 
    return noBias + withBias;
}





/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  return 2;
}
