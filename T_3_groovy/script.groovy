#!groovy

///////////////////////////////////////////////////////////////////////////////////////////
//
//       Author : Abdul Mateen
//       Email : abdul.mateen59@yahoo.com
//       Todo : ->
//
///////////////////////////////////////////////////////////////////////////////////////////

import java.util.*;
import java.lang.*;
import java.util.HashMap;


List getSlowestTests(String log){
    def List lines = log.split(System.getProperty("line.separator"));
    for (int i = 0; i < lines.size(); i++){
        lines[i] = lines[i].replace('***' , '   ')
        lines[i] = lines[i].tokenize()
        lines[i][6] = Double.parseDouble(lines[i][6])
    }
    for(int i = 0; i < (lines.size())-1; ++i)
        for(int j = i+1; j < lines.size; ++j) {
            if(lines[i][6] < lines[j][6])
            lines = lines.swap(i,j);
        }
    //lines = lines.reverse()                           // Uncomment this for top 10 Fastest
    return lines
}

void showSlowestTests(List slowest){
    def TopTen = 10;
    for (int i = 0; i < TopTen; i++){
        slowest[i] = slowest[i].join(",")
        slowest[i] = slowest[i].replace(',',' ')
        slowest[i] = slowest[i].replace('Failed','***Failed')
        slowest[i] = slowest[i].replace('Timeout','***Timeout')
        println slowest[i]
    }
}


def  log = """\
4/9 Test #13: foo4 .............................   Passed    5000.00 sec 
5/9 Test #11: foo2 .............................***Failed    3.13 sec 
7/9 Test #10: foo1 .............................   Passed    22.01 sec 
9/9 Test #15: foo6 .............................   Passed    10.66 sec 
3/9 Test #16: foo7 .............................***Failed    33.02 sec 
1/9 Test #12: foo3 .............................   Passed    2.71 sec 
6/9 Test #14: foo5 .............................***Failed    3.13 sec 
1/9 Test #03: foo9 .............................***Timeout   38.55 sec 
4/9 Test #13: foo4 .............................   Passed    3.12 sec 
5/9 Test #11: foo2 .............................***Failed    61.13 sec 
7/9 Test #10: foo1 .............................   Passed    1.01 sec 
9/9 Test #15: foo6 .............................   Passed    10.66 sec 
3/9 Test #16: foo7 .............................***Failed    3.02 sec 
1/9 Test #12: foo3 .............................   Passed    7.71 sec 
6/9 Test #14: foo5 .............................***Failed    11.13 sec 
1/9 Test #03: foo9 .............................   Passed   31.59 sec 
4/9 Test #13: foo4 .............................   Passed    3.12 sec 
5/9 Test #11: foo2 .............................***Failed    3.13 sec 
7/9 Test #10: foo1 .............................   Passed    1.01 sec 
9/9 Test #15: foo6 .............................   Passed    10.66 sec 
3/9 Test #16: foo7 .............................***Failed    3.02 sec 
1/9 Test #12: foo3 .............................   Passed    8.71 sec 
6/19 Test #14: foo5 .............................  Passed   20.13 sec 
1/19 Test #03: foo9 .............................***Timeout   38.51 sec 
4/19 Test #13: foo4 .............................   Passed    3.12 sec 
5/19 Test #11: foo2 .............................***Failed    1.13 sec 
7/19 Test #10: foo1 .............................   Passed    1.01 sec 
9/19 Test #15: foo6 .............................   Passed    10.66 sec 
3/19 Test #16: foo7 .............................***Failed    3.02 sec 
1/19 Test #12: foo3 .............................   Passed    8.71 sec 
6/19 Test #14: foo5 .............................***Failed    3.13 sec 
1/19 Test #03: foo9 .............................***Timeout   15.55 sec 
1/9 Test #3: foo ........   Passed   38.55 sec
2/9 Test #4: foo2 ........***Timeout 100.04 sec
3/9 Test #5: foo3 ........***Failed   55.05 sec"""

/*
    As I am not fimiliar with your jenkins pipeline's 
    ctest string so I have assumed Multiline, 
    Interpolated string with escape character (/).
*/

def mylist = getSlowestTests(log);
showSlowestTests(mylist);






