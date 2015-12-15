# USACO Bronze Solutions
## 2012
### November 2012
#### Problem 1: Find the Cow! `cowfind.cpp`
`*********t` 9/10 (timeout @ `10`)

#### Problem 2: Typo `typo.cpp`
`******tttt` 6/10 (4 timeouts @ `7-10`)

O(**N<sup>2</sup>**) is too slow…

#### Problem 3: Horseshoes `hshoe.cpp`
`**x***x***` 8/10 (2 wrong answers @ `3,8`)

### December 2012
#### Problem 1: Meet and Greet `greetings.cpp`
`**********` 10/10 (perfect)

#### Problem 2: Scrambled Letters `scramble.cpp`
`*xxxxxtttt` 1/10 (5 wrong answers @ `2-6`, 4 timeouts @ `7-10`)

#### Problem 3: Crazy Fences `crazy.cpp`
`xsxssssssx` 0/10 (why were there signals? 3 wrong @ `1,3,10`, 7 signals @ `2,4-9`)

I have given up on this one. As a result, I just submitted code that will return C, in hopes that no boxes are formed by the fences for as many test cases as possible.

## 2013
### February 2013
#### Problem 1: Message Relay `relay.cpp`
`**********` 10/10 (perfect)

#### Problem 2: Cow Crossings `crossings.cpp`
`*xx*xxxxxxttttt` 2/15 (8 wrong answers @ `2-3,5-10`, 5 timeouts @ `11-15`)

I realized that I have made a mistake by not checking subsequent cows against cows that have already collided.

Example: Cow 1 collides with Cow 2, so they are both marked as collided. Cow 3 will not be checked against Cow 2.

#### Problem 3: Perimeter `perimeter.cpp`
`*xxxxxxxxx` 1/10 (9 wrong answers @ `2-10`)

I found out that this solution is flawed because it doesn't "fill the holes" correctly. It fails when there are two adjacent hole cells.

### November 2013
#### Problem 1: Combination Lock `combo.cpp`
`*x*xxxx**x` 4/10 (6 wrong answers @ `2,4-7,10`)

I optimized it near the end, but then I realized that the overlap() function fails when N < 5.

##### Correction `combo2.cpp`
`**********` 10/10 (perfect)

Upon review, I beat the solution! Although N is no larger than 100, my solution runs in O(1) time and theirs runs in O(N^3) time.

##### Correction 2 `combo3.cpp`
`**********` 10/10 (perfect)

This is more optimized than my previous correction though still in O(1) time.

#### Problem 2: Goldilocks and the N Cows `milktemp.cpp`
`*******ttt` 7/10 (3 timeouts @ `8-10`)

I think that testing every boundary line might be slow, but it's the only way I can think of that does it completely.

#### Problem 3: Farmer John has no Large Brown Cow `nocow.cpp`
`**ssx*ssss` 3/10 (6 signals @ `3-4,7-10`, 1 wrong answer @ `5`)

I somehow ran out of memory and the permutations were not correct in one case.

### December 2013
#### Problem 1: Record Keeping `records.cpp`
`**********` 10/10 (perfect)

As long as there aren't any hash collisions, this is a fast solution.

#### Problem 2: Cow Baseball `baseball.cpp`
`*xxxxxxxxx` 1/10 (9 wrong answers @ `2-10`)

O(**N<sup>2</sup> log N**) time might be too slow.

#### Problem 3: Wormholes `wormhole.cpp`
(`incomplete`)

It's too difficult, but I had it partially done. Other partial work is in the recycling by now.

## 2014
### January 2014
#### Problem 1: Ski Course Design `skidesign.cpp`
`**********` 10/10 (perfect)

My solution is O(**N<sup>2</sup>**), but up to 83*99 iterations.

#### Problem 2: Bessie Slows Down `slowdown.cpp`
`*xxxxxxxxx` 1/10 (9 wrong answers @ `2-10`)

My solution is O(**N log N**), but I somehow made an error somewhere (probably rounding errors).

#### Problem 3: Balanced Teams `bteams.cpp`
(`incomplete`)

It's too difficult, so I give up.

### February 2014
#### Problem 1: Mirror Field `mirror.cpp`
`**x*x*****` 8/10 (2 wrong @ `3,5`)

This is actually more difficult than Problem 2, which I completed first.

#### Problem 2: Auto-complete `auto.cpp`
`*****tt**t` 7/10 (3 timeouts @ `6-7,10`)

Just sort the entries, but also store the original position, then process the requests.

#### Problem 3: Secret Code `scode.cpp`
`**********` 10/10 (perfect)

This one took more time than Problem 1 and Problem 2, but at least I actually finished this Problem 3, unlike the last few ones.

# USACO Silver Solutions
## 2014
### March 2014
#### Problem 2: The Lazy Cow `lazy.cpp`
`*****ttttt` 5/10 (5 timeouts @ `5-10`)

Silver is significantly more difficult than bronze.

#### Problem 3: Mooo Moo `mooomoo.cpp`
(`incomplete`)

I gave up, and the partial code in this file is pointless.

### April (US Open) 2014
#### Problem 1: Fair Photography `fairphoto.cpp`
`*****t*ttt` 6/10 (4 timeouts @ `6,8-10`)

I'm not sure how to implement this faster.

#### Problem 2: Dueling GPSs `gpsduel.cpp`
(`incomplete`)

I've never implemented Dijkstra's algorithm before, and I couldn't do it in time.

## 2015
### April (US Open) 2015
#### Problem 1: Bessie Goes Moo `bgm.cpp`
(`incomplete`)

I didn't finish implementing it in time during the contest.

#### Problem 2: Dueling GPSs `gpsduel.cpp`
`****tttttttttt` 4/14 (10 timeouts @ `5-14`)

My solution is too slow.

### December 2015
They made all of the divisions easier, and my skills have also improved.

I solved them all with over 90 minutes to spare!

#### Problem 1: Switching on the Lights `lightson.cpp`
`***************` 15/15 (perfect)

I pretty much used BFS (breadth-first search) until everything possible is reached.

#### Problem 2: High Card Wins `highcard.cpp`
`***************` 15/15 (perfect)

This is just a greedy problem.

#### Problem 3: Breed Counting `bcount.cpp`
`***************` 15/15 (perfect)

I used 3 arrays to counts the number of a type of breed to the left. Then the count from A to B is just array[B+1] - array[A].

# USACO Gold Solutions
### December 2015
I didn't have as much time left over (~25 minutes) as I did in Silver.

#### Problem 1: High Card Low Card `cardgame.cpp`
`***************` 15/15 (perfect)

I didn't expect this greedy algorithm to work, but it did.

#### Problem 2: Fruit Feast `feast.cpp`
`************` 12/12 (perfect)

I used the cyclic property of modular arithmetic to avoid checking every possibility.

#### Problem 3: Bessie's Dream `dream.cpp`
`****************` 16/16 (perfect)

Maybe BFS could be faster than Dijkstra's algorithm.

My earlier version without the priority queue was too slow.

# USACO Platinum Solutions
## 2015
### December 2015
#### Problem 1: Max Flow `maxflow.cpp`
`******ttttttttt` 6/15 (9 timeouts @ `7-15`)

There isn't enough space to store the paths in something resembling a routing table, so I did BFS Q times, which is too slow.

#### Problem 2: High Card Low Card `cardgame.cpp`
`***x*tttttttttt` 4/15 (1 wrong answer @ `4`, 10 timeouts @ `6-15`)

I tried all N possibilities with my Gold solution, but it was too slow.

#### Problem 3: Counting Haybales `haybales.cpp`
`***ttttttt` 3/10 (7 timeouts @ `4-10`)

I'm not sure what kind of data structure is suitable. After it ended, Google searches show that maybe a BIT (binary indexed tree or Fenwick tree) or a Cartesian tree would work.
