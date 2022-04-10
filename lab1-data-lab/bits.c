/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Zhouzh
 * 28/32
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
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	int op1 = ~ (x & (~y));
	int op2 = ~ ((~x) & y);
	int op3 = ~(op1 & op2);
	return op3;
}

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	// may better
	return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	int op1 = x + 1;
	int op2 = op1 + x;
	int op3 = ~0;
	return !(op3 ^ op2) & (!!op1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	// 3 + 3 + 2 = 8 ops
	int op1 = 0xaa;
	int op2 = op1 << 8;
	int op3 = op2 << 8;
	int op4 = op3 << 8;
	int op5 = op1 + op2 + op3 + op4;
	int op6 = op5 ^ (x & op5);
	return !op6;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	// -x = ~x + 1
	int op1 = ~x;
	int op2 = op1 + 1;
	return op2;
}
//3
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
	// 14 ops
	// 1. ensure all 0 outside 0~7
	int a = ~(0xff);
	int op1 = x & a; // must be 0
	// 2. ensure 0b0011 in 4~7
	int b = 0x30;
	int c = 0xf0;
	int op2 = (x & c) ^ b; // must be 0
	// 3. ensure it's between 0b0000 and 0b1001 in 0~3
	// 卡诺图
	// 0000 11xx
	a = 0x0c;
	int op3 = (x & a) ^ a; // must not be 0
	// 0000 1x1x
	b = 0x0a;
	int op4 = (x & b) ^ b; // must not be 0
	return !(op1 + op2 + !op3 + !op4);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	// 1. x is various but !x can either be 0 or 1
	int op0 = !x;
	// 2. -!x and ~(-!x)can be used as mask, -!x
	// mask1 is 0, mask2 is -1 when x is true
	// vice versa
	int mask1 = ~op0 + 1;
	int mask2 = ~mask1;
	return (y & mask2) + (z & mask1);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	// 17 ops
	// 1. pos-neg or neg-pos
	int mask1 = 1 << 31;
	int op1 = !(x & mask1);
	int op2 = !(y & mask1);
	int op3 = op1 ^ op2;
	int mask2 = ~op3 + 1; 
	int mask3 = ~mask2;
	// if pos-neg, op2 = 0; if neg-pos, op2 = 1
	int re1 = op2;
	// 2. pos-pos or neg-neg
	// -x
	int op4 = ~x + 1;
	// y-x
	int op5 = y + op4;
	// y-x >= 0
	// if >= 0, op6 = 1; else op6 = 0
	int op6 = !(mask1 & op5);
	int re2 = op6;
	return (mask2 & re1) + (mask3 & re2);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	// 7 ops
	// if 0 then 1
	// 1. if pos, shift right to make neg
	// 2. then or x
	int op1 = ~x + 1;
	int op2 = (x >> 31) | (op1 >> 31);
	int op3 = ~op2 + 1;
	return op3;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	// how without looping?
	// 1. xp = abs(x)
	// IF op1 = 1 -> bits + 1
	// 
	// not completed
	return 0;
	/*int mask1 = 1 << 31;
	int op1 = !(x & mask1);
	int mask2 = ~op1 + 1;
	int mask3 = ~mask2;
	int op2 = ~x + 1;
	int xp = (mask3 & op2) + (mask2 & x);
	// 2.
	int i = 0;
	while(xp)
	{
		xp = xp >> 1;
		i = i + 1;
	}
	return i + op1;*/
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
	// I got a all-bit-op ver func which contains 35 ops but no if
	// and tested it on my phone only to get 0.0 always
	// At first i thought it was because i made mistakes during my steps
	// even after thorough consideration, but only to find that 
	// %f is only for **double** in the end
	//
	// 18 ops
	unsigned mask1 = 0xff << 23;
	unsigned mask2 = ~mask1;
	unsigned op0 = 1 << 31;
	// to retain signed bit
	unsigned mask3 = mask1 | op0;
	// E
	unsigned op1 = uf & mask1;
	// if all 1
	unsigned op2 = op1 ^ mask1;
	unsigned ans = 0;
	if(op2) // normal or subnormal
	{
		// if all 0 in E,
		// all 0 in E -> 0
		if(op2 ^ mask1)
		{
			// normal
			unsigned op3 = op1 + (1 << 23);
			// if normal turns infinite
			unsigned op4 = uf & mask2;
			unsigned op5 = op4 | op3;
			if(op3 ^ mask1)
			{
				// not infinite;
				ans = op5;
			}
			else 
			{
				// infinite
				ans = op5 & mask3;
			}
		}
		else 
		{
			// subnormal
			unsigned op6 = uf << 1;
			unsigned op7 = op6 | (uf & op0);
			ans = op7;
		}
	}
	else // all 1 in E, nan or infinite
	{
		ans = uf;
	}
	return ans;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	unsigned def = 1 << 31;
	// 1. nan or infinity
	// return 0x80000000u (not directly)
	unsigned mask1 = 0xff << 23;
	unsigned mask2 = ~mask1 & (~def);
 	unsigned op1 = mask1 & uf;
	unsigned op2 = op1 ^ mask1;
	unsigned ans2 = def & uf;
    unsigned ans = 0;
	// if all 1 -> op2 == 0
	if(op2)
	{
		// normal or subnormal
		unsigned op3 = op2 ^ mask1;
		// if all 0 -> op2 == mask1 -> op3 = 0
		if(op3)
		{
	// 3. normal
	//    0 0000 0000 0
	//                +2(22th bit)
	      unsigned op4 = 1 << 23;
		  unsigned op5 = (uf & mask2) + op4; 

		  unsigned op6 = (op1 >> 23);
		  if(op6 < 127)
		  {
			  ans = 0;
		  }
		  else if(op6 == 127)
		  {
			  ans = 1;
		  }
		  else if(op6 <= 150)
		  {
			  ans = op5 >> (150 - op6);
		  }
		  else if(op6 <= 157) 
		  {
			  ans = op5 << (op6 - 150);
		  }
		  else 
		  {
		  	ans = def;
		  }
	//    (1) E - 127 <= 0
	//       >> 23
	//    (2) 0 < E - 127 <= 157
	//       << (E - 127)
	//       >> 23
	//    (3) E - 127 == 158
	//        positive -> return 0x80000000u
	//        negative && decimal part == 0 -> return 0x80000000u
	//    (4) E - 127 > 158
	//        return 0x80000000u
		}
		else
		{
			// 2. subnormal
			ans = 0x0;
		}
	}
	else
	{
		// nan or infinity
		ans = def;
	}
	if(ans2)
	{
		ans = ~ans + 1;
	}
    return ans;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	// too small
	if(x <= -150){
		return 0;
	}
	// subnormal -149 ~ -127
	if(x <= -127){
		unsigned y = x + 149;
		return 1 << y;
	}
	// normal -126 ~ 127
	if (x <= 127)
	{
		unsigned y = x + 127;
		return y << 23;
	}
	// infinite
    return 0xff << 23;
}
