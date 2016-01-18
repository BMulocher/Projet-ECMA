
<<< setup


<<< generate

Tried aggregator 1 time.
MIP Presolve eliminated 0 rows and 1 columns.
MIP Presolve modified 50 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3337 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (2,45 ticks)
Found incumbent of value 1,000000 after 0,01 sec. (5,29 ticks)
Probing fixed 0 vars, tightened 30 bounds.
Probing time = 0,01 sec. (7,01 ticks)
Tried aggregator 1 time.
MIP Presolve modified 25 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3337 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (1,64 ticks)
Probing time = 0,00 sec. (3,08 ticks)
Clique table members: 2292.
MIP emphasis: balance optimality and feasibility.
MIP search method: dynamic search.
Parallel mode: deterministic, using up to 4 threads.
Root relaxation solution time = 0,01 sec. (12,08 ticks)

        Nodes                                         Cuts/
   Node  Left     Objective  IInf  Best Integer    Best Bound    ItCnt     Gap

*     0+    0                            1,0000       40,0000      415     --- 
      0     0       39,5954   258        1,0000       39,5954      415     --- 
      0     0       39,4937   230        1,0000      Cuts: 98      537     --- 
*     0+    0                            3,0000       39,4937      628     --- 
      0     0       39,4835   203        3,0000      Cuts: 94      628     --- 
      0     0       39,1343   187        3,0000     Cuts: 116      781     --- 
      0     0       38,2233   170        3,0000     Cuts: 104      964     --- 
      0     0       37,7315   146        3,0000      Cuts: 81     1114     --- 
      0     0       37,2467   189        3,0000      Cuts: 97     1361     --- 
      0     0       36,8803   193        3,0000     Cuts: 114     1546     --- 
      0     0       36,3666   160        3,0000     Cuts: 133     1648     --- 
      0     0       34,8007   160        3,0000     Cuts: 207     1836     --- 
      0     0       34,4271   153        3,0000     Cuts: 134     2088     --- 
      0     0       34,2100   149        3,0000     Cuts: 140     2336     --- 
*     0+    0                            6,0000       34,2100     2336  470,17%
      0     0       33,4916   203        6,0000     Cuts: 150     2764  458,19%
*     0+    0                           15,0000       33,4916     2899  123,28%
      0     0       33,0146   186       15,0000     Cuts: 110     2899  110,89%
      0     0       29,5630   174       15,0000     Cuts: 216     3132   97,09%
      0     0       28,6538   176       15,0000      Cuts: 94     3318   91,03%
      0     0       28,1308   182       15,0000      Cuts: 74     3454   87,54%
      0     0       26,9355   203       15,0000     Cuts: 107     3738   79,57%
      0     0       26,7141   209       15,0000      Cuts: 76     4652   78,09%
      0     0       26,1068   200       15,0000      Cuts: 89     5056   74,05%
      0     0       25,3738   142       15,0000      Cuts: 77     5170   69,16%
      0     0       24,9851   273       15,0000      Cuts: 67     5987   66,57%
      0     0       24,1746   190       15,0000      Cuts: 90     6393   61,16%
      0     0       24,0264   271       15,0000      Cuts: 67     8537   60,18%
      0     0       24,0264   263       15,0000      Cuts: 69     8782   60,18%
      0     0       24,0264   294       15,0000      Cuts: 38    10146   60,18%
      0     2       24,0264   283       15,0000       24,0264    10146   60,18%
Elapsed time = 1,87 sec. (1001,13 ticks, tree = 0,01 MB, solutions = 4)
     11    11        cutoff             15,0000       23,5861    16507   57,24%
    122    59       17,7061   115       15,0000       23,2185    38969   54,79%
    430   145       19,1053   114       15,0000       21,0679    63540   40,45%

Clique cuts applied:  8
Flow cuts applied:  13
Mixed integer rounding cuts applied:  53
Zero-half cuts applied:  40

Root node processing (before b&c):
  Real time             =    1,86 sec. (995,29 ticks)
Parallel b&c, 4 threads:
  Real time             =    1,34 sec. (966,84 ticks)
  Sync time (average)   =    0,27 sec.
  Wait time (average)   =    0,00 sec.
                          ------------
Total (root+branch&cut) =    3,20 sec. (1962,12 ticks)

<<< solve


OBJECTIVE: 15

x[1][1] = 0 x[1][2] = 0 x[1][3] = 0 x[1][4] = 0 x[1][5] = 0 x[1][6] = 1 x[1][7] = 1 x[1][8] = 1 
x[2][1] = 0 x[2][2] = 0 x[2][3] = 0 x[2][4] = 0 x[2][5] = 0 x[2][6] = 1 x[2][7] = 1 x[2][8] = 1 
x[3][1] = 0 x[3][2] = 0 x[3][3] = 0 x[3][4] = 0 x[3][5] = 0 x[3][6] = 1 x[3][7] = 1 x[3][8] = 1 
x[4][1] = 0 x[4][2] = 0 x[4][3] = 0 x[4][4] = 0 x[4][5] = 0 x[4][6] = 1 x[4][7] = 1 x[4][8] = 1 
x[5][1] = 0 x[5][2] = 0 x[5][3] = 0 x[5][4] = 0 x[5][5] = 0 x[5][6] = 1 x[5][7] = 1 x[5][8] = 1 


<<< post process


<<< done

