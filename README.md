# Compiler

Just testing the IR code

**Sample input:**

(((24*3)-(56/7))+((18+6)*5))-((72/(9+3))+((20-5)*4))


**Output:**
t1= 24*3
t2= 56/7
t3= t1-t2
t4= 18+6
t5= t4*5
t6= t3+t5
t7= 9+3
t8= 72/t7
t9= 20-5
t10= t9*4
t11= t8+t10
t12= t6-t11
