#include <vector>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h> 
#include <random>
#include <stdlib.h>

#pragma once

using namespace std;

// Function prototypes

//Sorting Functions
void quickSort(vector<int>& arr, const unsigned int left, const unsigned int right);
void insertionSort(vector<int>& arr, const unsigned int low, const unsigned int n);
void mergeSort(vector<int>& arr, int l, int r);
void quickInsertionSort(vector<int>& arr, const unsigned int left, const unsigned int right, const unsigned int k);




// Helper Functions
void merge(vector<int>& arr, int l, int m, int r);
int findPiv(vector<int>& arr,int left, int right);
void print(vector<int>& arr, const unsigned int n);