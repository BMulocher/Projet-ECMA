
<<< setup


<<< generate

Tried aggregator 1 time.
MIP Presolve eliminated 0 rows and 1 columns.
MIP Presolve modified 44 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3350 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (2,47 ticks)
Found incumbent of value 1,000000 after 0,01 sec. (5,33 ticks)
Probing fixed 0 vars, tightened 34 bounds.
Probing time = 0,01 sec. (6,72 ticks)
Tried aggregator 1 time.
MIP Presolve modified 21 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3350 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (1,65 ticks)
Probing time = 0,00 sec. (3,04 ticks)
Clique table members: 2292.
MIP emphasis: balance optimality and feasibility.
MIP search method: dynamic search.
Parallel mode: deterministic, using up to 4 threads.
Root relaxation solution time = 0,01 sec. (9,41 ticks)

        Nodes                                         Cuts/
   Node  Left     Objective  IInf  Best Integer    Best Bound    ItCnt     Gap

*     0+    0                            1,0000       40,0000      364     --- 
      0     0       39,8766   243        1,0000       39,8766      364     --- 
*     0+    0                            3,0000       39,8766      373     --- 
      0     0       39,8766   178        3,0000      Cuts: 21      373     --- 
      0     0       39,8765   152        3,0000      Cuts: 73      431     --- 
      0     0       39,8743   137        3,0000      Cuts: 58      489     --- 
      0     0       39,0000   136        3,0000      Cuts: 71      594     --- 
      0     0       39,0000   159        3,0000      Cuts: 77      695     --- 
      0     0       39,0000   113        3,0000       Cuts: 4      823     --- 
      0     0       39,0000   100        3,0000      Cuts: 85      913     --- 
      0     0       39,0000   151        3,0000     Cuts: 105     1056     --- 
*     0+    0                            4,0000       39,0000     1056  875,00%
      0     2       39,0000    80        4,0000       39,0000     1056  875,00%
Elapsed time = 0,70 sec. (362,12 ticks, tree = 0,01 MB, solutions = 3)
*     4+    4                            5,0000       39,0000     1234  680,00%
*     4+    4                            8,0000       39,0000     1234  387,50%
*   718+  493                           33,0000       38,6301    21041   17,06%
    869   565       36,4553   102       33,0000       38,5603    23775   16,85%
   1720  1088       37,9967   148       33,0000       38,0000    45432   15,15%
   2439  1527       36,3927   109       33,0000       36,3927    65337   10,28%
   2459  1185       34,3639    90       33,0000       35,8171    67220    8,54%

Clique cuts applied:  6
Flow cuts applied:  110
Mixed integer rounding cuts applied:  426
Zero-half cuts applied:  24

Root node processing (before b&c):
  Real time             =    0,70 sec. (361,72 ticks)
Parallel b&c, 4 threads:
  Real time             =    3,50 sec. (2233,11 ticks)
  Sync time (average)   =    0,30 sec.
  Wait time (average)   =    0,00 sec.
                          ------------
Total (root+branch&cut) =    4,19 sec. (2594,83 ticks)

<<< solve


OBJECTIVE: 33

x[1][1] = 0 x[1][2] = 1 x[1][3] = 1 x[1][4] = 1 x[1][5] = 1 x[1][6] = 1 x[1][7] = 1 x[1][8] = 1 
x[2][1] = 0 x[2][2] = 1 x[2][3] = 1 x[2][4] = 1 x[2][5] = 1 x[2][6] = 1 x[2][7] = 1 x[2][8] = 1 
x[3][1] = 0 x[3][2] = 1 x[3][3] = 0 x[3][4] = 1 x[3][5] = 1 x[3][6] = 1 x[3][7] = 1 x[3][8] = 1 
x[4][1] = 1 x[4][2] = 1 x[4][3] = 1 x[4][4] = 0 x[4][5] = 1 x[4][6] = 1 x[4][7] = 1 x[4][8] = 1 
x[5][1] = 1 x[5][2] = 1 x[5][3] = 1 x[5][4] = 0 x[5][5] = 0 x[5][6] = 1 x[5][7] = 1 x[5][8] = 1 


<<< post process


<<< done

