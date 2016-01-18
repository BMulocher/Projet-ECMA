
<<< setup


<<< generate

Tried aggregator 1 time.
MIP Presolve eliminated 0 rows and 1 columns.
MIP Presolve modified 47 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3350 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (2,47 ticks)
Found incumbent of value 1,000000 after 0,01 sec. (5,33 ticks)
Probing fixed 0 vars, tightened 25 bounds.
Probing time = 0,01 sec. (6,84 ticks)
Tried aggregator 1 time.
MIP Presolve modified 19 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3350 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (1,65 ticks)
Probing time = 0,00 sec. (3,07 ticks)
Clique table members: 2292.
MIP emphasis: balance optimality and feasibility.
MIP search method: dynamic search.
Parallel mode: deterministic, using up to 4 threads.
Root relaxation solution time = 0,01 sec. (10,48 ticks)

        Nodes                                         Cuts/
   Node  Left     Objective  IInf  Best Integer    Best Bound    ItCnt     Gap

*     0+    0                            1,0000       40,0000      387     --- 
      0     0       39,8182   261        1,0000       39,8182      387     --- 
      0     0       39,8182   241        1,0000      Cuts: 85      497     --- 
*     0+    0                            2,0000       39,8182      600     --- 
      0     0       39,8177   220        2,0000      Cuts: 29      600     --- 
      0     0       39,8083   216        2,0000      Cuts: 40      637     --- 
      0     0       39,0000   203        2,0000      Cuts: 43      724     --- 
      0     0       39,0000   197        2,0000      Cuts: 89      827     --- 
      0     0       39,0000   194        2,0000      Cuts: 73      923     --- 
      0     0       39,0000   107        2,0000      Cuts: 42      969     --- 
      0     0       39,0000   137        2,0000      Cuts: 88     1071     --- 
      0     2       39,0000    43        2,0000       39,0000     1071     --- 
Elapsed time = 0,59 sec. (302,71 ticks, tree = 0,01 MB, solutions = 2)
*     5+    5                           18,0000       39,0000     1261  116,67%
*    13+   13                           22,0000       39,0000     1643   77,27%
    213   155       38,4610    59       22,0000       38,6053    15017   75,48%
    350   228       35,4539   205       22,0000       38,5169    25570   75,08%
    741   408    infeasible             22,0000       37,8034    38756   71,83%
   1126   652       36,6724    72       22,0000       37,7102    52855   71,41%
*  1231+  723                           28,0000       37,6844    62173   34,59%
*  1249   718      integral     0       29,0000       37,6844    62463   29,95%
   1754  1039       31,8967   310       29,0000       37,6056    76709   29,67%
   2346  1381       33,2059    67       29,0000       37,4684    93876   29,20%
*  2477+  961                           30,0000       37,4684    97401   24,89%
   2477   962       33,7942    94       30,0000       33,7942   102236   12,65%
   2491   970       31,7499   138       30,0000       33,0022   105425   10,01%

Clique cuts applied:  6
Flow cuts applied:  9
Mixed integer rounding cuts applied:  84
Zero-half cuts applied:  44

Root node processing (before b&c):
  Real time             =    0,59 sec. (302,31 ticks)
Parallel b&c, 4 threads:
  Real time             =    6,03 sec. (3814,31 ticks)
  Sync time (average)   =    0,81 sec.
  Wait time (average)   =    0,00 sec.
                          ------------
Total (root+branch&cut) =    6,61 sec. (4116,61 ticks)

<<< solve


OBJECTIVE: 30

x[1][1] = 0 x[1][2] = 0 x[1][3] = 0 x[1][4] = 1 x[1][5] = 1 x[1][6] = 1 x[1][7] = 1 x[1][8] = 1 
x[2][1] = 0 x[2][2] = 0 x[2][3] = 1 x[2][4] = 0 x[2][5] = 1 x[2][6] = 1 x[2][7] = 1 x[2][8] = 1 
x[3][1] = 1 x[3][2] = 1 x[3][3] = 1 x[3][4] = 1 x[3][5] = 1 x[3][6] = 1 x[3][7] = 1 x[3][8] = 1 
x[4][1] = 0 x[4][2] = 0 x[4][3] = 1 x[4][4] = 1 x[4][5] = 1 x[4][6] = 1 x[4][7] = 1 x[4][8] = 1 
x[5][1] = 0 x[5][2] = 0 x[5][3] = 1 x[5][4] = 1 x[5][5] = 1 x[5][6] = 1 x[5][7] = 1 x[5][8] = 1 


<<< post process


<<< done

