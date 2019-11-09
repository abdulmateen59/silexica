#!/bin/bash
#!/usr/bin/python3

'''
    Author : Abdul Mateen
    Email : abdul.mateen59@yahoo.com
    Todo : -
'''

import sys , os , argparse

class analytics:
    
    failed_tc , started_tc = [] , []
    
    def __init__(self):
        pass
    
    def summary(self,file):
        try:
            with open(file,'r') as f:
                f = f.readlines()
                i , j = 0 , 0
            for line in f:
                if "Test" and "Failed" in line:
                    self.failed_tc.append(line)
                    i =  i + 1
                if "Start" in line:
                    self.started_tc.append(line)
                    j = j + 1
            return i , j
        except IOError:
            print("Could not read file : " , file )

    def print(self, failed_count , started_count):
        print(35 * "<" , " FAILED TESTS SUMMARY " , 35 * ">" , "\n")
        print(*self.failed_tc , sep = "\n")
        print(35 * "<" , " STARTED TESTS SUMMARY " , 35 * ">" , "\n")
        print(*self.started_tc , sep = "\n")
        print(" Total Number of Failed Test Cases = " , failed_count , "\n" , "Total Number of Started Test Cases = " , started_count )



if __name__ == '__main__' : 
    parser = argparse.ArgumentParser()
    parser.add_argument('-F' , '--File', default = 'ctestOutput.txt' , help = " Enter Test File")
    args = parser.parse_args()
    try:
        print(next(open(args.File)))
    except:
        print("File Reading Err..")

    obj = analytics()
    failed_count , started_count = obj.summary(args.File)
    obj.print(failed_count,started_count) 