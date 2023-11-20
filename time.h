#include "./sort.h"
#pragma once

// Time measurement functions
double measureTimeInsertion(vector<int>& arr, const unsigned int n);
double measureTimeQuick(vector<int>& arr, const unsigned int n);
double measureTimeQuickInsert(vector<int>& arr, const unsigned int n, const unsigned int k);
double measureTimeMerge(vector<int>& arr, const unsigned int n);

// Finders
vector<int> findBestCaseInsertion();
vector<int> findBestCaseQuickInsertion();
vector<int> findBestCaseQuickSort();