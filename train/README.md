# USACO Training Solutions
## Chapter 1
### Section 1.1
#### Submitting Solutions `submit.cpp`
This one is really easy; copy, paste, upload... not much of a challenge!
#### Problem 108: Your Ride Is Here `ride.cpp`
This one is also easy! It's too bad I failed a few times due to const-correctness.

You pretty much "hash" each string, as a product of letters, and compare both hashes mod 47. If they match, "GO", otherwise "STAY" and then print a newline.

On second thought, I could have placed the modulus in the `s_product` function. Then I also realized that it could be put in after each multiplication operation.
#### Problem 77: Greedy Gift Givers `gift1.cpp`
I failed 18 times due to division by zero, modulus of zero, etc.

This one is similar to "accounting". Create accounts for everyone, and change their amount of balance from each transaction. Then print everyone's final balances.

I used heap memory allocation, but that doesn't matter much. I just had to prevent null pointers from causing a crash.
#### Problem 109: Friday the Thirteenth `friday.cpp`
Today is Friday the thirtieth (30<sup>th</sup>)!

Not that hard, but I somehow misread 1900 as 1990 once...

Simply find the day of week of the 13<sup>th</sup> day of the next month.  
Then count the days that pass with each month mod 7 for the day of the week for the "zero"th day of the next month.
#### Problem 99: Broken Necklace `beads.cpp`
First attempt! w00t! For the last Section 1.1 too!

We're clearly supposed to brute-force every possibility.  
Just traverse the maximum number of beads from each possible starting point.

### Section 1.2
#### Problem 101: Milking Cows `milk2.cpp`
I failed this, the first challenge in Section 1.2, a few times. It won't be easy to get another perfect submission, like last time.

This is basically handling timespans, and merging them. Then traverse over them to find the following:

* The maximum timespan length, and
* The maximum delay between timespans, but not
  * between 0 and t[0].start
  * between t[n-1].end and infinity
#### Problem 75: Transformations `transform.cpp`
Failed a quite few times, as usual...

This one requires a variable-sized matrix to be rotated/flipped. I just had to check every operation in the order provided. The analysis wastes more approximately 7 times memory than mine; thus, I consider mine is better.
#### Problem 29: Name That Number `namenum.cpp`
Friday the 13th...

Another first-attempt! w00t again! This one is done differently then their analysis.  
C++ allows you to use std::string, so you can check length. The length of the serial must be equal to the name.

Then I "serialize" or "hash" every name that has the same length, and check if it matches the number.

This is better than doing a binary search of each possible number upon the dictionary.
#### Problem 81: Palindromic Squares `palsquare.cpp`
This one requires base conversion, but I'm basically testing every square from 1 to 300 (90 000 fits into a 32-bit signed int; no intervention required). I reverse the string and test if it matches. If so, print the number and its palindromic square, in the requested base.
#### Problem 90: Dual Palindromes `dualpal.cpp`
I accidentally thought it was "dual square palindromes", which made me fail until I noticed it.

This one is the last for Chapter 1's Section 1.2!

### Section 1.3
#### Problem 76: Mixing Milk `milk.cpp`
Only 2 failures due to the final cost costing the product of the available number and required, not the price and required number.

I didn't use qsort for it like the analysis. It looks like my solution is similar to the good exemplars.  
This one is easy, as two farmers selling the same same price could be combined into one "provider" selling both amounts at the same price each. Since this is a greedy match, take as many as possible from the lowest price, and move on to the next expensive, ..., until there's no more.
