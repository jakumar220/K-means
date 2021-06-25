#pragma once
#include<iostream>
#include<string>
bool ver_format(const char* filename, const char* extension); // funkcja do sprawdzenia poprawnosci rozszerzenia pliku
void help_arg();
bool ver_arg(int argc, char** argv, char*& filename, int& centroids_number);