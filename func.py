# -*- coding: utf-8 -*-
"""
Created on Sat Feb 22 15:22:18 2020

@author: furkan
"""
import re
import time
import numpy as np


function = "x^2-1x+(-5)"

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
def derivative_of_function(point, function, sensitivity, choice=0, degree=1):
    if choice == 0:
        # central derivation
        return (func((point+sensitivity),function) - func((point-sensitivity),function)) / (sensitivity*2)
    elif choice == -1:
        # backward derivation
        return (func((point),function) - func((point-sensitivity),function)) / (sensitivity)
    elif choice == 1:
        # forward derivation
        return (func((point+sensitivity),function) - func((point),function)) / (sensitivity)
    elif choice == 2:
        # taylor's series 
        return 0

def integral_of_function(left, right, function, sensitivity, choice=0):
    def alternate(size):
        alter = np.ones(size)
        for i in range(1,size-1):
            if i % 2 == 0:
                alter[i] = 2
            else:
                alter[i] = 4
        return alter
    if choice == 0:
        # trapezoid
        summary = 0
        for x in np.arange(left + sensitivity, right, sensitivity):
            summary += func(x,function)
        summary += (func(left,function) + func(right,function))/2
        print(summary*sensitivity)
        return summary*sensitivity
    elif choice == 1:
        # simpson rule
        summary = 0
        spacing = np.arange(left + sensitivity, right, sensitivity)
        alter = alternate(spacing.size)
        for x,y in zip(alter,spacing):
            summary += x*func(y,function)
        summary = summary*sensitivity/3
        return summary
    
func(2,"x^3")
integral_of_function(0,3,"x^2",0.0001,1)    
    
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



def newton_raphson(function, start_value=0, error_rate=0.01):
    def next_value(x_cur):
        x_next = x_cur - (func(x_cur,function) / derivative_of_function(x_cur,function,0.000001))
        print(f"{x_next} <-- {x_cur} - ({func(x_cur,function)} / {derivative_of_function(x_cur,function,0.000001)})")
        return x_next
    start_time = time.time()
    step = 0
    x_cur = start_value
    x_next = next_value(x_cur)
    cntrl = x_next - 5
    while(abs(x_next - cntrl) > error_rate):
        x_next = next_value(x_cur)
        cntrl = x_cur 
        x_cur = x_next
        step += 1
    end_time = time.time()
    total_time = end_time - start_time
            
    return x_next, total_time, step

def secant(function, first_value=1,second_value=2, error_rate=0.00001):
    def next_value(function, x_cur, x_prev):
        x_next = x_cur - (func(x_cur,function)*(x_cur-x_prev))/(func(x_cur,function)-func(x_prev,function))
        print(f"{x_next} <-- {x_cur} - ({func(x_cur,function)}*{(x_cur-x_prev)}) / ({func(x_cur,function)}-{func(x_prev,function)})")
        return x_next
    start_time = time.time()
    step = 0
    
    x_prev = first_value
    x_cur = second_value
    
    x_next = next_value(function, x_cur ,x_prev)
    x_prev = x_cur
    x_cur = x_next

    
    while((abs(x_next - next_value(function,x_cur,x_prev)) > error_rate)):
        x_next = next_value(function,x_cur,x_prev)
        x_prev = x_cur
        x_cur = x_next
        step += 1
    end_time = time.time()
    total_time = end_time - start_time
            
    return x_next, total_time, step





#%%
print("Newton-Raphson Method")
print("/////////////////////////////////////////////////////////////")
print()
print(newton_raphson("x^2-6x+5", start_value=1.5,error_rate=0.0000000001))
print()  
print("Secant Method")
print("/////////////////////////////////////////////////////////////")
print()
print(secant("x^4-1x+(-10)", first_value=1.0, second_value=2.0 , error_rate=0.0000000001))
print()  
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