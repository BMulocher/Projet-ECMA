
<<< setup


<<< generate

Tried aggregator 1 time.
MIP Presolve eliminated 0 rows and 1 columns.
MIP Presolve modified 50 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3334 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (2,45 ticks)
Found incumbent of value 1,000000 after 0,01 sec. (5,28 ticks)
Probing fixed 0 vars, tightened 50 bounds.
Probing time = 0,01 sec. (7,56 ticks)
Tried aggregator 1 time.
MIP Presolve modified 25 coefficients.
Reduced MIP has 764 rows, 642 columns, and 3334 nonzeros.
Reduced MIP has 560 binaries, 0 generals, 0 SOSs, and 0 indicators.
Presolve time = 0,00 sec. (1,64 ticks)
Probing time = 0,00 sec. (3,13 ticks)
Clique table members: 2292.
MIP emphasis: balance optimality and feasibility.
MIP search method: dynamic search.
Parallel mode: deterministic, using up to 4 threads.
Root relaxation solution time = 0,01 sec. (12,77 ticks)

        Nodes                                         Cuts/
   Node  Left     Objective  IInf  Best Integer    Best Bound    ItCnt     Gap

*     0+    0                            1,0000       40,0000      411     --- 
      0     0       39,6879   289        1,0000       39,6879      411     --- 
      0     0       39,2938   236        1,0000      Cuts: 42      532     --- 
*     0+    0                            6,0000       39,2938      686  554,90%
      0     0       38,9351   185        6,0000     Cuts: 162      686  548,92%
      0     0       38,8528   171        6,0000     Cuts: 150      766  547,55%
      0     0       38,8133   150        6,0000      Cuts: 98      844  546,89%
      0     0       38,7838   150        6,0000     Cuts: 108      989  546,40%
      0     0       38,3396   150        6,0000     Cuts: 115     1148  538,99%
      0     0       38,1336   145        6,0000      Cuts: 76     1304  535,56%
      0     0       37,4694   135        6,0000     Cuts: 145     1442  524,49%
      0     0       37,0900   137        6,0000     Cuts: 128     1608  518,17%
      0     0       36,3918   132        6,0000     Cuts: 107     1724  506,53%
      0     0       36,0700   152        6,0000     Cuts: 126     1803  501,17%
      0     0       35,4687   147        6,0000      Cuts: 81     1943  491,14%
      0     0       35,1127   141        6,0000     Cuts: 115     2089  485,21%
      0     0       34,9127   171        6,0000      Cuts: 74     2277  481,88%
      0     0       34,1437   168        6,0000      Cuts: 97     2415  469,06%
*     0+    0                            7,0000       34,1437     2415  387,77%
*     0+    0                            8,0000       34,1437     2415  326,80%
      0     0       33,3795   160        8,0000     Cuts: 118     2520  317,24%
      0     0       32,6345   164        8,0000     Cuts: 140     2633  307,93%
      0     0       31,6169   149        8,0000     Cuts: 147     2731  295,21%
      0     0       30,5106   197        8,0000      Cuts: 58     2882  281,38%
      0     0       29,5965   179        8,0000      Cuts: 67     2947  269,96%
      0     0       28,8124   180        8,0000      Cuts: 81     3264  260,16%
      0     0       28,5977   154        8,0000     Cuts: 132     3364  257,47%
      0     0       27,6428   121        8,0000      Cuts: 84     3501  245,53%
      0     0       27,5728   153        8,0000     Cuts: 248     3733  244,66%
      0     0       26,5552   126        8,0000     Cuts: 100     3878  231,94%
      0     0       25,5799   103        8,0000      Cuts: 75     4006  219,75%
      0     0       25,5799   160        8,0000      Cuts: 61     4115  219,75%
*     0+    0                           15,0000       25,5799     4115   70,53%
      0     2       25,5799   115       15,0000       25,5799     4115   70,53%
Elapsed time = 1,02 sec. (551,97 ticks, tree = 0,01 MB, solutions = 5)
    201    77       17,0039   142       15,0000       23,6471    20134   57,65%

Clique cuts applied:  7
Implied bound cuts applied:  10
Flow cuts applied:  7
Mixed integer rounding cuts applied:  115
Zero-half cuts applied:  23

Root node processing (before b&c):
  Real time             =    1,01 sec. (546,15 ticks)
Parallel b&c, 4 threads:
  Real time             =    0,40 sec. (281,10 ticks)
  Sync time (average)   =    0,09 sec.
  Wait time (average)   =    0,00 sec.
                          ------------
Total (root+branch&cut) =    1,41 sec. (827,26 ticks)

<<< solve


OBJECTIVE: 15

x[1][1] = 0 x[1][2] = 0 x[1][3] = 0 x[1][4] = 0 x[1][5] = 0 x[1][6] = 1 x[1][7] = 1 x[1][8] = 1 
x[2][1] = 0 x[2][2] = 0 x[2][3] = 0 x[2][4] = 0 x[2][5] = 0 x[2][6] = 1 x[2][7] = 1 x[2][8] = 1 
x[3][1] = 0 x[3][2] = 0 x[3][3] = 0 x[3][4] = 0 x[3][5] = 0 x[3][6] = 1 x[3][7] = 1 x[3][8] = 1 
x[4][1] = 0 x[4][2] = 0 x[4][3] = 0 x[4][4] = 0 x[4][5] = 0 x[4][6] = 1 x[4][7] = 1 x[4][8] = 1 
x[5][1] = 0 x[5][2] = 0 x[5][3] = 0 x[5][4] = 0 x[5][5] = 0 x[5][6] = 1 x[5][7] = 1 x[5][8] = 1 


<<< post process


<<< done

