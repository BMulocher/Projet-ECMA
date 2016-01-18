
<<< setup


<<< generate

Tried aggregator 1 time.
MIP Presolve eliminated 0 rows and 1 columns.
MIP Presolve modified 50 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3340 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (2,46 ticks)
Found incumbent of value 1,000000 after 0,01 sec. (5,30 ticks)
Probing fixed 0 vars, tightened 24 bounds.
Probing time = 0,01 sec. (7,12 ticks)
Tried aggregator 1 time.
MIP Presolve modified 24 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3340 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (1,64 ticks)
Probing time = 0,00 sec. (3,10 ticks)
Clique table members: 2292.
MIP emphasis: balance optimality and feasibility.
MIP search method: dynamic search.
Parallel mode: deterministic, using up to 4 threads.
Root relaxation solution time = 0,01 sec. (10,17 ticks)

        Nodes                                         Cuts/
   Node  Left     Objective  IInf  Best Integer    Best Bound    ItCnt     Gap

*     0+    0                            1,0000       40,0000      379     --- 
      0     0       39,7799   220        1,0000       39,7799      379     --- 
      0     0       39,0000   199        1,0000      Cuts: 84      512     --- 
*     0+    0                            2,0000       39,0000      799     --- 
      0     0       39,0000   245        2,0000      Cuts: 72      799     --- 
      0     0       39,0000   166        2,0000      Fract: 1      826     --- 
      0     0       39,0000   175        2,0000      Cuts: 94      940     --- 
*     0+    0                            3,0000       39,0000      940     --- 
      0     2       39,0000   154        3,0000       39,0000      940     --- 
Elapsed time = 0,57 sec. (329,48 ticks, tree = 0,01 MB, solutions = 3)
*     4+    4                            4,0000       39,0000     1105  875,00%
*     5+    5                            5,0000       39,0000     1189  680,00%
    127   109       36,9350   179        5,0000       39,0000     9936  680,00%
    282   202    infeasible              5,0000       37,9022    22665  658,04%
    653   425       32,2269   143        5,0000       37,5058    43500  650,12%
   1316   860    infeasible              5,0000       36,8725    68850  637,45%
   2017  1263       35,9741   146        5,0000       36,7882    93246  635,76%
   2456  1520       33,7733   156        5,0000       36,6995   114123  633,99%
*  2544+ 1053                            8,0000       35,9164   119574  348,96%
*  2544+  701                           10,0000       35,9164   119574  259,16%
*  2544+  466                           13,0000       34,5832   120208  166,02%
*  2544+  310                           25,0000       33,1045   120481   32,42%
*  2544+  206                           27,0000       32,8336   120947   21,61%
*  2544+  137                           28,0000       31,6710   121167   13,11%
*  2544+   90                           29,0000       31,4935   121492    8,60%
   2544    91       31,4935    75       29,0000       31,4935   121496    8,60%
   2584     6       30,2516    72       29,0000       30,5177   123679    5,23%

Cover cuts applied:  1
Flow cuts applied:  76
Mixed integer rounding cuts applied:  201
Zero-half cuts applied:  14

Root node processing (before b&c):
  Real time             =    0,57 sec. (329,08 ticks)
Parallel b&c, 4 threads:
  Real time             =    4,99 sec. (2863,35 ticks)
  Sync time (average)   =    0,57 sec.
  Wait time (average)   =    0,00 sec.
                          ------------
Total (root+branch&cut) =    5,56 sec. (3192,43 ticks)

<<< solve


OBJECTIVE: 29

x[1][1] = 0 x[1][2] = 0 x[1][3] = 1 x[1][4] = 1 x[1][5] = 1 x[1][6] = 1 x[1][7] = 1 x[1][8] = 1 
x[2][1] = 0 x[2][2] = 0 x[2][3] = 1 x[2][4] = 1 x[2][5] = 1 x[2][6] = 1 x[2][7] = 1 x[2][8] = 1 
x[3][1] = 0 x[3][2] = 0 x[3][3] = 0 x[3][4] = 1 x[3][5] = 1 x[3][6] = 1 x[3][7] = 1 x[3][8] = 1 
x[4][1] = 0 x[4][2] = 0 x[4][3] = 1 x[4][4] = 1 x[4][5] = 1 x[4][6] = 1 x[4][7] = 1 x[4][8] = 1 
x[5][1] = 0 x[5][2] = 0 x[5][3] = 1 x[5][4] = 1 x[5][5] = 1 x[5][6] = 1 x[5][7] = 1 x[5][8] = 1 


<<< post process


<<< done

