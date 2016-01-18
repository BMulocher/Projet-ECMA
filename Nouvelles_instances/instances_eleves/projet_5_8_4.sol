
<<< setup


<<< generate

Tried aggregator 1 time.
MIP Presolve eliminated 0 rows and 1 columns.
MIP Presolve modified 39 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3350 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (2,47 ticks)
Found incumbent of value 1,000000 after 0,01 sec. (5,33 ticks)
Probing fixed 0 vars, tightened 11 bounds.
Probing time = 0,01 sec. (6,21 ticks)
Tried aggregator 1 time.
MIP Presolve modified 11 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3350 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (1,65 ticks)
Probing time = 0,00 sec. (2,97 ticks)
Clique table members: 2292.
MIP emphasis: balance optimality and feasibility.
MIP search method: dynamic search.
Parallel mode: deterministic, using up to 4 threads.
Root relaxation solution time = 0,01 sec. (12,35 ticks)

        Nodes                                         Cuts/
   Node  Left     Objective  IInf  Best Integer    Best Bound    ItCnt     Gap

*     0+    0                            1,0000       40,0000      424     --- 
      0     0       39,8619   271        1,0000       39,8619      424     --- 
      0     0       39,8619   206        1,0000      Cuts: 16      450     --- 
*     0+    0                           10,0000       39,8619      544  298,62%
      0     0       39,8594   190       10,0000      Cuts: 64      544  298,59%
      0     0       39,8485   162       10,0000      Cuts: 80      629  298,48%
      0     0       39,8428   145       10,0000      Cuts: 58      729  298,43%
      0     0       39,8347   163       10,0000      Cuts: 83      852  298,35%
      0     0       39,8144   158       10,0000      Cuts: 79      952  298,14%
      0     0       39,7807   140       10,0000      Cuts: 87     1048  297,81%
      0     0       39,7133   195       10,0000     Cuts: 139     1203  297,13%
      0     0       39,6579   183       10,0000     Cuts: 122     1269  296,58%
      0     0       39,5999   189       10,0000     Cuts: 125     1387  290,00%
      0     0       39,0000   186       10,0000     Cuts: 137     1537  290,00%
      0     0       39,0000   183       10,0000      Cuts: 98     1666  290,00%
      0     0       39,0000    71       10,0000    MIRcuts: 4     1712  290,00%
      0     0       39,0000   111       10,0000      Cuts: 96     1850  290,00%
*     0+    0                           11,0000       39,0000     1850  254,55%
*     0+    0                           14,0000       39,0000     1850  178,57%
      0     2       39,0000   100       14,0000       39,0000     1850  178,57%
Elapsed time = 0,68 sec. (408,45 ticks, tree = 0,01 MB, solutions = 4)
*     4+    4                           15,0000       39,0000     2120  160,00%
*   317   257      integral     0       33,0000       39,0000    17015   18,18%
    937   508       36,3454    89       33,0000       37,9577    35308   15,02%
   1572   910       36,3635    61       33,0000       37,5757    55008   13,87%
   2229  1211       35,7669    98       33,0000       37,1149    78433   12,47%
   2414  1279       39,0000   106       33,0000       36,9019    83488   11,82%
   2503  1196       35,4105   108       33,0000       36,9019    86125   11,82%
   3004  1045       34,6173   127       33,0000       36,9019    99133   11,82%
   3784  1011       34,9762   109       33,0000       36,7682   119631   11,42%
   4462  1042       34,2692   181       33,0000       36,2225   139757    9,77%
   7162   880       34,5784   115       33,0000       34,9747   221458    5,98%
Elapsed time = 5,90 sec. (3616,02 ticks, tree = 0,32 MB, solutions = 7)

Clique cuts applied:  2
Cover cuts applied:  1
Flow cuts applied:  12
Mixed integer rounding cuts applied:  31
Zero-half cuts applied:  10

Root node processing (before b&c):
  Real time             =    0,68 sec. (408,04 ticks)
Parallel b&c, 4 threads:
  Real time             =    5,98 sec. (3571,20 ticks)
  Sync time (average)   =    0,75 sec.
  Wait time (average)   =    0,00 sec.
                          ------------
Total (root+branch&cut) =    6,66 sec. (3979,23 ticks)

<<< solve


OBJECTIVE: 33

x[1][1] = 0 x[1][2] = 1 x[1][3] = 1 x[1][4] = 0 x[1][5] = 0 x[1][6] = 1 x[1][7] = 1 x[1][8] = 1 
x[2][1] = 1 x[2][2] = 1 x[2][3] = 0 x[2][4] = 1 x[2][5] = 0 x[2][6] = 1 x[2][7] = 1 x[2][8] = 1 
x[3][1] = 1 x[3][2] = 1 x[3][3] = 1 x[3][4] = 1 x[3][5] = 1 x[3][6] = 1 x[3][7] = 1 x[3][8] = 1 
x[4][1] = 1 x[4][2] = 1 x[4][3] = 1 x[4][4] = 1 x[4][5] = 1 x[4][6] = 1 x[4][7] = 1 x[4][8] = 1 
x[5][1] = 0 x[5][2] = 1 x[5][3] = 1 x[5][4] = 1 x[5][5] = 0 x[5][6] = 1 x[5][7] = 1 x[5][8] = 1 


<<< post process


<<< done

