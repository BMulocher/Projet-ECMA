
<<< setup


<<< generate

Tried aggregator 1 time.
MIP Presolve eliminated 0 rows and 1 columns.
MIP Presolve modified 50 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3344 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (2,47 ticks)
Found incumbent of value 1,000000 after 0,01 sec. (5,32 ticks)
Probing fixed 0 vars, tightened 27 bounds.
Probing time = 0,01 sec. (7,08 ticks)
Tried aggregator 1 time.
MIP Presolve modified 20 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3344 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (1,64 ticks)
Probing time = 0,00 sec. (3,08 ticks)
Clique table members: 2292.
MIP emphasis: balance optimality and feasibility.
MIP search method: dynamic search.
Parallel mode: deterministic, using up to 4 threads.
Root relaxation solution time = 0,01 sec. (14,29 ticks)

        Nodes                                         Cuts/
   Node  Left     Objective  IInf  Best Integer    Best Bound    ItCnt     Gap

*     0+    0                            1,0000       40,0000      466     --- 
      0     0       39,6928   291        1,0000       39,6928      466     --- 
      0     0       39,6141   236        1,0000      Cuts: 29      503     --- 
*     0+    0                            3,0000       39,6141      628     --- 
      0     0       39,5838   171        3,0000     Cuts: 137      628     --- 
      0     0       39,5647   153        3,0000      Cuts: 85      711     --- 
      0     0       38,9898   238        3,0000      Cuts: 98     1140     --- 
      0     0       38,8745   222        3,0000      Cuts: 87     1599     --- 
      0     0       38,7170   196        3,0000     Cuts: 111     1717     --- 
      0     0       35,6637   180        3,0000     Cuts: 246     1870     --- 
      0     0       35,2001   167        3,0000     Cuts: 149     1975     --- 
      0     0       34,8188   153        3,0000     Cuts: 134     2075     --- 
*     0+    0                            4,0000       34,8188     2075  770,47%
*     0+    0                            5,0000       34,8188     2075  596,38%
      0     0       34,5250   164        5,0000     Cuts: 151     2250  590,50%
      0     0       33,7639   151        5,0000      Cuts: 92     2339  575,28%
      0     0       33,3183   162        5,0000      Cuts: 87     2484  566,37%
      0     0       33,0004   144        5,0000      Cuts: 90     2638  560,01%
      0     0       32,8936   150        5,0000      Cuts: 87     2784  557,87%
      0     0       32,4586   147        5,0000     Cuts: 157     2890  549,17%
      0     0       32,3006   152        5,0000      Cuts: 83     3038  546,01%
      0     0       31,1582   203        5,0000     Cuts: 153     3388  523,16%
      0     0       30,7809   175        5,0000     Cuts: 106     3482  515,62%
      0     0       30,4200   150        5,0000      Cuts: 86     3639  508,40%
      0     0       30,1039   153        5,0000     Cuts: 200     3769  502,08%
      0     0       29,8636   153        5,0000      Cuts: 89     3935  497,27%
      0     0       29,6949   163        5,0000      Cuts: 65     4172  493,90%
*     0+    0                            7,0000       29,6949     4172  324,21%
*     0+    0                            8,0000       29,6949     4172  271,19%
*     0+    0                           11,0000       29,6949     4172  169,95%
*     0+    0                           13,0000       29,6949     4172  128,42%
      0     0       29,6949   157       13,0000      Cuts: 57     4222  128,42%
      0     0       29,6949   119       13,0000   ZeroHalf: 1     4229  128,42%
      0     0       29,6949   124       13,0000      Cuts: 52     4303  128,42%
*     0+    0                           14,0000       29,3723     4303  109,80%
*     0+    0                           15,0000       29,3723     4303   95,82%
      0     2       29,6949   103       15,0000       29,3723     4303   95,82%
Elapsed time = 1,13 sec. (571,00 ticks, tree = 0,01 MB, solutions = 10)
    140    85        cutoff             15,0000       28,8682    19117   92,45%
    247   163       23,3202   209       15,0000       26,8688    34182   79,13%
    312   212       23,0386   148       15,0000       26,8410    51340   78,94%
    509   361       26,0067   236       15,0000       26,5827    74581   77,22%
*   631+  414                           24,0000       26,5508    85381   10,63%
    729    62       25,4826    81       24,0000       26,2032    93555    9,18%

Clique cuts applied:  15
Flow cuts applied:  17
Mixed integer rounding cuts applied:  107
Zero-half cuts applied:  32

Root node processing (before b&c):
  Real time             =    1,12 sec. (565,41 ticks)
Parallel b&c, 4 threads:
  Real time             =    2,02 sec. (1356,86 ticks)
  Sync time (average)   =    0,49 sec.
  Wait time (average)   =    0,00 sec.
                          ------------
Total (root+branch&cut) =    3,15 sec. (1922,27 ticks)

<<< solve


OBJECTIVE: 24

x[1][1] = 0 x[1][2] = 0 x[1][3] = 0 x[1][4] = 0 x[1][5] = 0 x[1][6] = 1 x[1][7] = 1 x[1][8] = 1 
x[2][1] = 0 x[2][2] = 1 x[2][3] = 1 x[2][4] = 1 x[2][5] = 0 x[2][6] = 1 x[2][7] = 1 x[2][8] = 1 
x[3][1] = 0 x[3][2] = 0 x[3][3] = 1 x[3][4] = 1 x[3][5] = 1 x[3][6] = 1 x[3][7] = 1 x[3][8] = 1 
x[4][1] = 0 x[4][2] = 0 x[4][3] = 1 x[4][4] = 1 x[4][5] = 1 x[4][6] = 1 x[4][7] = 1 x[4][8] = 1 
x[5][1] = 0 x[5][2] = 0 x[5][3] = 0 x[5][4] = 0 x[5][5] = 0 x[5][6] = 1 x[5][7] = 1 x[5][8] = 1 


<<< post process


<<< done

