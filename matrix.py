#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 14:35:07 2020

@author: furkan
"""

import numpy as np
import pandas as pd

class matrix:
    
    def __init__(self, mat):
        self.mat = np.asanyarray(mat,dtype=float)
        self.shape = np.shape(mat)
        self.identity_mat = self.identity_matrix()
        self.inverse_mat = self.gauss_jordan_inverse()
        self.det = self.determinant(1,mat)
        self.trps = self.transpose(self.mat)
        self.cofac = self.cofactor_matrix()
        self.adjoint_matrix = self.adjoint_matrix()
        
        
        
    def transpose(self, mat):
        trps = np.ones(np.shape(mat))
        for i in range(np.shape(mat)[0]):
            trps[:,i] = mat[i,:]
        return trps
    
    def identity_matrix(self):
        mat = np.zeros(self.shape)
        for i in range(self.shape[0]):
            mat[i,i] = 1
        return mat
    
    def gauss_jordan_inverse(self):
        matrix = np.copy(self.mat)
        matrix.astype(float)
        identity = np.copy(self.identity_mat)
        # U matrix begin
        temp = np.copy(matrix)
        temp.astype(float)
        for j in range(np.shape(matrix)[1]):
            calc = temp[j,j]
            temp[j] = temp[j] / calc
            identity[j] = identity[j] / calc
            for i in range(0,np.shape(matrix)[1]):
                if(i != j):
                    calc = temp[i,j]
                    temp[i] -= temp[j]*calc
                    identity[i] -= identity[j]*calc
        return identity 
    
    def determinant(self, sign = 1, matrix = np.ones((2,2))):
        delta = 0
        if(np.shape(matrix)[0] == 2):
            delta = (matrix[0,0]*matrix[1,1]) - (matrix[0,1]*matrix[1,0])
        else:
            sign *= -1
            for i in range(np.shape(matrix)[0]):
                sign *= -1
                mat = np.delete(matrix,0,0)
                mat = np.delete(mat,i,1)
                delta += matrix[0,i]*self.determinant(sign,mat)
        return sign*delta    

    def cofactor_matrix(self):
        mat = np.copy(self.mat)
        cofac = np.ones(np.shape(mat))
        sign = 1
        for i in range(np.shape(mat)[1]):
            for j in range(np.shape(mat)[0]):
                tmp = np.delete(mat,i,0)
                tmp = np.delete(tmp,j,1)
                cofac[i,j] = sign * self.determinant(1,tmp)
                sign *= -1
        return cofac
    
    def adjoint_matrix(self):
        mat = np.copy(self.cofac)
        return self.transpose(mat)
    def copy(self):
        copy = matrix(self.mat)
        return copy



#%% solving linear equations

f1 = "x + 2z = 9"
f2 = "2y + z = 8"
f3 = "4x -3y = -2"

# i should develope a parser method to parse function form into matrix form




mat = [[1,0,2],[0,2,1],[4,-3,0]]
res = [9,8,-2]


def cramers_method(mat,res):
    mat = np.asarray(mat,dtype=float)
    res = np.asarray(res,dtype=float)
    dets = np.zeros(mat.shape[1],dtype=float)
    main = matrix(mat)
    D = main.det
    for i in range(mat.shape[1]):
        x = np.copy(mat)
        x[:,i] = res
        m = matrix(x)
        dets[i] = m.det
    dets = dets / D
    return dets


mat = [[1,1,-1],[0,1,3],[-1,0,-2]]
res = [9,3,2]



def gaussian_elimination(mat,res):
    mat = np.asarray(mat,dtype=float)
    res = np.asarray(res,dtype=float)
    t_mat = np.copy(mat)
    t_res = np.copy(res)
    for j in range(t_mat.shape[1]):
        calc = t_mat[j,j]
        t_mat[j] = t_mat[j] / calc
        t_res[j] = t_res[j] / calc
        for i in range(j+1,t_mat.shape[0]):
            calc = t_mat[i,j]
            t_mat[i] -= t_mat[j]*calc
            t_res[i] -= t_res[j]*calc
    dets = np.zeros(t_res.shape,dtype=float)

    for j in range(t_mat.shape[1]-1,-1,-1):
        dets[j] = t_res[j] - (t_mat[j]@dets)
    return dets


mat = [[12,3,-5],[1,5,3],[3,7,13]]
res = [1,28,76]


def jacobi(mat,res):
    mat = np.asarray(mat,dtype=float)
    res = np.asarray(res,dtype=float)
    x = np.zeros(res.shape,dtype=float)
    diagonalley = np.copy(x)
    tmp = np.copy(mat)
    error = 100
    for i in range(mat.shape[0]):
        diagonalley[i] = tmp[i,i]
        tmp[i,i] = 0
    step = 0
    
    while error > 0.000001:
        x_old = x
        x = (res -(tmp@x))/diagonalley     
        error = np.max(((x-x_old)/x)*100)
        step += 1
    return x, step


def gauss_seidel(mat,res):
    mat = np.asarray(mat,dtype=float)
    res = np.asarray(res,dtype=float)
    x = np.asarray([1,0,1],dtype=float)
    diagonalley = np.copy(x)
    tmp = np.copy(mat)
    
    for i in range(mat.shape[0]):
        diagonalley[i] = tmp[i,i]
        tmp[i,i] = 0
    step = 0
    
    while step < 1000:
        for i in range(x.shape[0]):
            x[i] = (res[i] -(tmp[i]@x))/diagonalley[i]        
        step += 1
    return x



# for the vandermonde matrix you should give an input lists of x and y values
degree = 2
x = [0, 1, 0.6666666]
y = [1, 0, 0.5]




class vandermonde_interpolation:
    def __init__(self, x, y, degree):
        self.inputs = x
        self.outputs = y
        self.degree = degree
        self.vandermonde_matrix = self.make_vandermonde()
        self.coefficients = self.calculate_coefficients()
        
    
    def make_vandermonde(self):
        vandermonde_matrix = []
        for i in range(self.degree + 1):
            temp_list = []
            for j in range(self.degree + 1):
                temp_list.append(self.inputs[i]**j)
            vandermonde_matrix.append(temp_list)
        return vandermonde_matrix
    
    def calculate_coefficients(self):
        coefficients = gaussian_elimination(self.vandermonde_matrix, self.outputs)
        return coefficients
    
    def interpolate(self, coefficients, x):
        y = 0
        for i in range(len(coefficients)):
            y += coefficients[i]*(x**i)
        return y


def lagrange_approximation(value, inputs, outputs):
    degree = len(inputs)-1
    total = 0
    for i in range(degree + 1):
        mul = 1
        for j in range(degree + 1):
            if(j != i):
                mul = mul * ((value - inputs[j]) / (inputs[i] - inputs[j]))
        total += mul*outputs[i]
    return total
    
    
x = [ 2, 2.75, 4]   
y = [0.5, 0.36363636363636365, 0.25]

lagrange_approximation(3,x,y)    


inputs = np.array([65,65,62,67,69,65,61,67])
outputs = np.array([105,125,110,120,140,135,95,130])

class linear_regression:
    def __init__(self,inputs, outputs):
        self.coefficients = self.make_line(inputs,outputs)
        
        
    def make_line(self, inputs,outputs):
        sumx_sumy = np.sum(inputs)*np.sum(outputs)
        sum_xy = np.sum(np.multiply(inputs,outputs))
        sum_x2 = np.sum(inputs**2)
        sumx_2 = np.sum(inputs)**2
        
        b1 = (sum_xy - (sumx_sumy/len(inputs))) / (sum_x2 - (sumx_2/len(inputs)))
        b0 = (np.sum(outputs)/len(outputs)) - b1*(np.sum(inputs)/len(inputs))
        print(f"y = {b1}x + {b0}")
        return np.array([b0,b1])
    
    def calculate(self, value, coefficients):
        return (coefficients[1]*value) + coefficients[0]

x = linear_regression(inputs, outputs)



