#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define SIZE 32
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define BLUE_P "\033[1;45m"

typedef enum {
  number = 1,
  x = 2,
  plus = 3,
  minus = 4,
  mull = 5,
  del = 6,
  scale = 7,
  mod = 8,
  s21_sin = 9,
  s21_cos = 10,
  s21_tan = 11,
  s21_acos = 12,
  s21_asin = 13,
  s21_atan = 14,
  s21_sqrt = 15,
  s21_ln = 16,
  s21_log = 17,
  bracket_l = 18,
  bracket_r = 19,
  un_minus = 20
} type_t;

typedef struct {
  double value; 
  int priority;
  type_t type;
  int num;
} s21_SmartCalc[SIZE];


int parser(char* str, s21_SmartCalc data);
void init_struct(s21_SmartCalc);
void print_struct(s21_SmartCalc, int, int);
void if_digit(char* str, s21_SmartCalc, int);
// void revers_struct(s21_SmartCalc tmp, s21_SmartCalc data);
int notation(s21_SmartCalc src, s21_SmartCalc data);
double calculate(s21_SmartCalc digit, s21_SmartCalc support);
void push(s21_SmartCalc name, double num);
int peek_priority(s21_SmartCalc data);
void print_struct_for_str(s21_SmartCalc src);
void del_struct(s21_SmartCalc *tmp);

