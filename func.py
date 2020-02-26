# -*- coding: utf-8 -*-
"""
Created on Sat Feb 22 15:22:18 2020

@author: furkan
"""
import re
import time
import numpy as np


function = "x^3-6.5x^3+13.5x+9"

def func(x, function):
    pattern = "(?P<c1>[+-]? *\d+(?:\.\d+)?)? *\*? *[xX] *(?:\^ *(?P<e1>-? *\d+(?:\.\d+)?)|(?P<e2>-? *\d+(?:\.\d+)?)?)|(?P<c2>[+-]? *\d+(?:\.\d+)?)"
    sum = 0
    result = re.split(pattern, function)
    for i in range(0, len(result)-1,5):
        if(result[i+4] == None):
            if(result[i+2] != None):
                if(result[i+1] != None):
                    #print(f"{result[i+1]}({x})^{result[i+2]}={float(result[i+1])*(x**int(result[i+2]))}")
                    sum += float(result[i+1])*(x**int(result[i+2]))
                else:
                    #print(f"({x})^{result[i+2]}={(x**int(result[i+2]))}")
                    sum += (x**int(result[i+2]))
                    
            else:
                #print(f"{result[i+1]}({x})={float(result[i+1])*(x)}")
                sum += float(result[i+1])*(x)
        else: 
            #print(f"{result[i+4]}={float(result[i+4])}")
            sum += float(result[i+4])
    return sum

func(1,function)

def graphical(function, start_value=0, delta_value=0.25, error_rate=0.02):
    start_time = time.time()
    step = 0
    if(func(start_value,function) != 0):
        if(func(start_value,function) > 0):
            sign = -1
        elif(func(start_value,function) < 0):
            sign = +1
        previous_value = start_value
        next_value = start_value*2
        while(True):
            step += 1
            next_value = previous_value + (sign*delta_value)
            print(f"{next_value} = {previous_value} + ({sign} * {delta_value})")
            if(abs(next_value - previous_value)<error_rate):
                print("-------------------------------------------------")
                print(f"{next_value} - {previous_value} < {error_rate}")
                print(f"value = {previous_value} ")
                break
            if((func(previous_value,function)*func(next_value,function)) < 0):
                delta_value /= 2
            elif((func(previous_value,function)*func(next_value,function)) > 0):
                previous_value = next_value
            else:
                print(f"f(previous_value) = {func(previous_value,function)}")
                print(f"f(next_value) = {func(next_value,function)}")
                break
    end_time = time.time()
    total_time = end_time - start_time
        
    return previous_value, total_time, step

def bisection(function, left_bracket=0, right_bracket=1, error_rate=0.001):
    start_time = time.time()
    step = 0
    if(func(left_bracket,function)*func(right_bracket,function) == 0):
        if(func(left_bracket,function) == 0):
            end_time = time.time()
            total_time = end_time - start_time
            print("left_bracket is the root")
            return left_bracket, total_time, 1
        
        else:
            end_time = time.time()
            total_time = end_time - start_time
            print("left_bracket is the root")
            return right_bracket, total_time, 1
    elif(func(left_bracket,function)*func(right_bracket,function) > 0):
        end_time = time.time()
        total_time = end_time - start_time
        print("no root in the interval")
        return None, total_time, 1
    elif(func(left_bracket,function)*func(right_bracket,function) < 0):
        while(abs(left_bracket-right_bracket)>error_rate):
            step += 1
            mid = (left_bracket + right_bracket)/2
            print(f"{mid} = ({left_bracket} + {right_bracket}) / 2")
            if(func(left_bracket,function)*func(mid,function) < 0):
                print("mid <------ right")
                right_bracket = mid
            elif(func(mid,function)*func(right_bracket,function) < 0):
                print("left ------> mid")
                left_bracket = mid 
        mid = (left_bracket + right_bracket)/2
        end_time = time.time()
        total_time = end_time - start_time
        print("found the root")
        print("--------------------------------------------------------")
        return mid, total_time, step
    
def regula_falsi(function, left_bracket=0, right_bracket=1, error_rate=0.001):
    start_time = time.time()
    step = 0
    if(func(left_bracket,function)*func(right_bracket,function) == 0):
        if(func(left_bracket,function) == 0):
            end_time = time.time()
            total_time = end_time - start_time
            print("left_bracket is the root")
            return left_bracket, total_time, 1
        
        else:
            end_time = time.time()
            total_time = end_time - start_time
            print("left_bracket is the root")
            return right_bracket, total_time, 1
    elif(func(left_bracket,function)*func(right_bracket,function) > 0):
        end_time = time.time()
        total_time = end_time - start_time
        print("no root in the interval")
        return None, total_time, 1
    elif(func(left_bracket,function)*func(right_bracket,function) < 0):
        mid = ((left_bracket * func(right_bracket,function))-(right_bracket * func(left_bracket,function)))/(func(right_bracket,function)-func(left_bracket,function))
        while(abs(func(mid,function))>error_rate):
            step += 1
            mid = ((left_bracket * func(right_bracket,function))-(right_bracket * func(left_bracket,function)))/(func(right_bracket,function)-func(left_bracket,function))
            print(f"{mid} = ({left_bracket} * {func(right_bracket,function)}) - ({right_bracket} * {func(left_bracket,function)}) /({func(right_bracket,function)}-{func(left_bracket,function)}))")
            if(func(left_bracket,function)*func(mid,function) < 0):
                print("mid <------ right")
                right_bracket = mid
            elif(func(mid,function)*func(right_bracket,function) < 0):
                print("left ------> mid")
                left_bracket = mid 
        mid = (left_bracket + right_bracket)/2
        end_time = time.time()
        total_time = end_time - start_time
        print("found the root")
        print("--------------------------------------------------------")
        return mid, total_time, step
    


print("Graphical Method")
print("/////////////////////////////////////////////////////////////")
print()
print(graphical("x^2-6x+5", start_value=1.5, delta_value=0.75, error_rate=0.02))
print()
print("Bisection Method")
print("/////////////////////////////////////////////////////////////")
print()
print(bisection("x^3-6.5x^3+13.5x+9", left_bracket=1.75, right_bracket=2.5, error_rate=0.001))
print()
print("Regula Falsi Method")
print("/////////////////////////////////////////////////////////////")
print()
print(regula_falsi("x^2-6x+5", left_bracket=1.5, right_bracket=8, error_rate=0.001))