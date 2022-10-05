#!/bin/python3

import math
import os
import random
import re
import sys

def aVeryBigSum(ar):
    s=0
    for i in ar:
        s+=i
    return s

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    ar_count = int(input())
    ar = list(map(int, input().rstrip().split()))
    result = aVeryBigSum(ar)
    fptr.write(str(result) + '\n')
    fptr.close()
"""
Input
5
1000000001 1000000002 1000000003 1000000004 1000000005

Your Output
5000000015

"""
