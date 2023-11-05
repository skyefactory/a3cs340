#include <vector>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h> 
#pragma once;

using namespace std;

// Function prototypes

//Sorting Functions
bool quickSort(vector<int>& arr, const unsigned int n);
bool insertionSort(vector<int>& arr, const unsigned int n);
bool mergeSort(vector<int>& arr, const unsigned int n);
bool quickInsertionSort(vector<int>& arr, const unsigned int n, const unsigned int k);

void print(vector<int>& arr, const unsigned int n);
void sort(vector<int>& arr, const unsigned int n, const unsigned int k);

/*
Find the pair of values (N, K) where :
(a) Quick-insertion outperforms all the other algorithms.
(b) Insertion sort outperforms all the other algorithms.
(c) Quicksort outperforms all the other algorithms
*/
int findBestCaseInsertion(vector<int>& arr, const unsigned int n);
int findBestCaseQuickInsertion(vector<int>& arr, const unsigned int n, const unsigned int k);
int findBestCaseQuickSort(vector<int>& arr, const unsigned int n);

int findBest(vector<int>& arr, const unsigned int n, const unsigned int k);

// Helper Functions
void merge(vector<int>& arr, int l, int m, int r);
void partition(vector<int>& arr, int l, int r, int& i, int& j);