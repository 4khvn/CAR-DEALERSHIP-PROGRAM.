#pragma once
#define NOMINMAX
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<Windows.h>
using namespace std;
//All Declarations
void menu_screen();
class vehicles;
class bikes;
class cars;
class trucks;
class customer;
class admin;
int main();
fstream& operator<<(fstream& file, bikes& obj);
fstream& operator>>(fstream& file, bikes& obj);
fstream& operator<<(fstream& file, cars& obj);
fstream& operator>>(fstream& file, cars& obj);
fstream& operator<<(fstream& file, trucks& obj);
fstream& operator>>(fstream& file, trucks& obj);
ostream& operator<<(ostream& dout, vehicles& obj);
ostream& operator<<(ostream& dout, customer& obj);
