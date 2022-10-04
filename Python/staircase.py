#!/bin/python3

import math
import os
import random
import re
import sys

def staircase(n):
    for i in range(n):
        s=""
        for j in range(n):
            if(j<n-i-1):
                s+=" "
            else:
                s+="#"
        print(s)
                
if __name__ == '__main__':
    n = int(input())

    staircase(n)
"""
input
6

Output
     #
    ##
   ###
  ####
 #####
######

"""
