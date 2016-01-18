
<<< setup


<<< generate

Tried aggregator 1 time.
MIP Presolve eliminated 0 rows and 1 columns.
MIP Presolve modified 46 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3335 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (2,45 ticks)
Found incumbent of value 1,000000 after 0,01 sec. (5,28 ticks)
Probing fixed 0 vars, tightened 15 bounds.
Probing time = 0,01 sec. (6,72 ticks)
Tried aggregator 1 time.
MIP Presolve modified 12 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3335 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (1,63 ticks)
Probing time = 0,00 sec. (3,06 ticks)
Clique table members: 2292.
MIP emphasis: balance optimality and feasibility.
MIP search method: dynamic search.
Parallel mode: deterministic, using up to 4 threads.
Root relaxation solution time = 0,01 sec. (12,39 ticks)

        Nodes                                         Cuts/
   Node  Left     Objective  IInf  Best Integer    Best Bound    ItCnt     Gap

*     0+    0                            1,0000       40,0000      431     --- 
      0     0       39,7471   273        1,0000       39,7471      431     --- 
      0     0       39,7029   218        1,0000      Cuts: 22      471     --- 
*     0+    0                            6,0000       39,7029      582  561,72%
      0     0       39,6976   191        6,0000     Cuts: 110      582  561,63%
      0     0       39,0000   184        6,0000     Cuts: 101      684  550,00%
      0     0       39,0000   184        6,0000      Cuts: 94      823  550,00%
      0     0       38,9704   159        6,0000      Cuts: 28     1014  549,51%
      0     0       38,9584   147        6,0000     Cuts: 129     1120  549,31%
      0     0       38,4946   140        6,0000     Cuts: 135     1266  541,58%
      0     0       38,3579   147        6,0000      Cuts: 99     1367  539,30%
      0     0       38,1525   154        6,0000     Cuts: 131     1454  535,87%
      0     0       38,0176   153        6,0000      Cuts: 99     1535  533,63%
      0     0       37,9184   142        6,0000     Cuts: 173     1653  531,97%
      0     0       37,3653   167        6,0000     Cuts: 239     1842  522,75%
      0     0       36,9129   144        6,0000     Cuts: 217     1931  515,22%
      0     0       36,4245   140        6,0000     Cuts: 135     2061  507,08%
      0     0       35,8555   141        6,0000     Cuts: 159     2201  497,59%
      0     0       35,3795   118        6,0000     Cuts: 128     2295  489,66%
*     0+    0                           10,0000       35,3795     2295  253,80%
*     0+    0                           15,0000       35,3795     2295  135,86%
      0     0       34,8660   139       15,0000     Cuts: 108     2362  132,44%
      0     0       34,7169   147       15,0000     Cuts: 113     2454  131,45%
      0     0       34,3333   140       15,0000     Cuts: 111     2604  128,89%
      0     0       33,6714   141       15,0000     Cuts: 173     2769  124,48%
      0     0       33,2133   130       15,0000     Cuts: 135     2898  121,42%
      0     0       32,8804   143       15,0000     Cuts: 160     3024  119,20%
      0     0       32,4433   150       15,0000     Cuts: 121     3155  116,29%
      0     0       31,9375   150       15,0000      Cuts: 98     3306  112,92%
*     0+    0                           26,0000       31,9375     3306   22,84%
      0     0       31,7313   181       26,0000     Cuts: 118     3427   22,04%
      0     0       31,6262   151       26,0000     Cuts: 114     3630   21,64%
      0     0       31,5399   160       26,0000      Cuts: 99     3713   21,31%
      0     0       31,4566   183       26,0000      Cuts: 97     4145   20,99%
      0     0       31,4566   167       26,0000      Cuts: 47     4219   20,99%
      0     2       31,4566   167       26,0000       30,6461     4219   17,87%
Elapsed time = 1,22 sec. (638,79 ticks, tree = 0,01 MB, solutions = 5)
*   115+   83                           28,0000       30,5716    14917    9,18%
    281    77       29,0136    90       28,0000       30,3515    18999    8,40%

Clique cuts applied:  6
Flow cuts applied:  17
Mixed integer rounding cuts applied:  159
Zero-half cuts applied:  34

Root node processing (before b&c):
  Real time             =    1,21 sec. (633,29 ticks)
Parallel b&c, 4 threads:
  Real time             =    0,48 sec. (286,83 ticks)
  Sync time (average)   =    0,09 sec.
  Wait time (average)   =    0,00 sec.
                          ------------
Total (root+branch&cut) =    1,69 sec. (920,12 ticks)

<<< solve


OBJECTIVE: 28

x[1][1] = 0 x[1][2] = 1 x[1][3] = 1 x[1][4] = 1 x[1][5] = 1 x[1][6] = 1 x[1][7] = 1 x[1][8] = 1 
x[2][1] = 0 x[2][2] = 0 x[2][3] = 1 x[2][4] = 1 x[2][5] = 1 x[2][6] = 1 x[2][7] = 1 x[2][8] = 1 
x[3][1] = 0 x[3][2] = 0 x[3][3] = 1 x[3][4] = 1 x[3][5] = 1 x[3][6] = 1 x[3][7] = 1 x[3][8] = 1 
x[4][1] = 0 x[4][2] = 0 x[4][3] = 0 x[4][4] = 1 x[4][5] = 1 x[4][6] = 1 x[4][7] = 1 x[4][8] = 1 
x[5][1] = 0 x[5][2] = 0 x[5][3] = 0 x[5][4] = 0 x[5][5] = 1 x[5][6] = 1 x[5][7] = 1 x[5][8] = 1 


<<< post process


<<< done

