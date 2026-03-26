#pragma once
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;

__declspec(dllexport) double area(double radius);
__declspec(dllexport) double volume(double radius);
__declspec(dllexport) vector<int> numbers_that_are_divisible_without_a_remainder(int number);

__declspec(dllexport) double the_radius_of_the_inscribed_circle(double a, double b, double c);

__declspec(dllexport) double the_radius_of_the_circle(double a, double b, double c);
__declspec(dllexport) int fact(int q);
__declspec(dllexport) double arcsin(double x, int n);