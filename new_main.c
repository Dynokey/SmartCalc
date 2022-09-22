#include "s21_SmartCalc.h"

int main() {
  s21_SmartCalc for_pars;
  init_struct(for_pars);
  // char str[SIZE] = {'k', '0', '-', '2', '-', '5', 'l', '^', 'k', '0', '-', '2', 'l'};
  char str[SIZE] = {'k', 'k','m', '2', 'l','-', '5', 'l', '^', 'k', 'm', '2', 'l'};
  // char str[SIZE] = {'k','k', 'k', '2', '-', '3', 'l', '/', '2', '+', 'k', '3', '-', '7', 'l', 'l', '*', '8', '-', '1', 'l', '^', '2'};
  // char str[SIZE] = {'2', '+', '3', '-', '7'};
  parser(str, for_pars);
  printf("%sin str = %s%s\n", BLUE, str, RESET);
  // print_struct(for_pars, 0, 10);
  // printf("%f\n", for_pars[for_pars[0].num + 4].value);

  s21_SmartCalc for_notation;
  init_struct(for_notation);
  notation(for_pars, for_notation);

  // print_struct(for_notation, 0 , 8);
  print_struct_for_str(for_pars);
  print_struct_for_str(for_notation);

  return 0;
}

int parser(char* str, s21_SmartCalc tmp) {
  // s21_SmartCalc tmp;
  // init_struct (tmp);
  int num_struct = 0;
  size_t str_len = strlen(str);
  for (size_t i = 0; i < str_len; i++) {
    if ((str[i] > 47 && str[i] < 58) || str[i] == '.') {
      if_digit(str + i, tmp, num_struct);
      i += strspn(str + i, "1234567890.") - 1;
      num_struct++;
    } else {
      switch (str[i]) {
        case '+':
          tmp[num_struct].type = 3;
          tmp[num_struct].priority = 2;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case '-':
          tmp[num_struct].type = 4;
          tmp[num_struct].priority = 2;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case '*':
          tmp[num_struct].type = 5;
          tmp[num_struct].priority = 3;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case '/':
          tmp[num_struct].type = 6;
          tmp[num_struct].priority = 3;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case '^':
          tmp[num_struct].type = 7;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'a':
          tmp[num_struct].type = 8;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'b':
          tmp[num_struct].type = 9;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'c':
          tmp[num_struct].type = 10;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'd':
          tmp[num_struct].type = 11;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'e':
          tmp[num_struct].type = 12;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'f':
          tmp[num_struct].type = 13;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'g':
          tmp[num_struct].type = 14;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'h':
          tmp[num_struct].type = 15;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'i':
          tmp[num_struct].type = 16;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'j':
          tmp[num_struct].type = 17;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'k':
          tmp[num_struct].type = 18;
          tmp[num_struct].priority = 1;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'l':
          tmp[num_struct].type = 19;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'm':
          tmp[num_struct].type = 20;
          tmp[num_struct].priority = 2;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        default:
          break;
      }
    }
  }
  return 0;
}

void init_struct(s21_SmartCalc src) {
  for (int i = 0; i < SIZE; i++) {
    src[i].value = 0.0;
    src[i].priority = 0;
    src[i].type = 0;
    src[i].num = -1;
  }
}

void print_struct(s21_SmartCalc src, int in, int out) {
  for (int i = in; i <= out; i++) {
    if (i % 2 == 0)
      printf(
          "%sstruct № %d\nvalue = %.2f priority = %d type = %d num = "
          "%d%s\n",
          YELLOW, i, src[i].value, src[i].priority, src[i].type, src[i].num,
          RESET);
    else
      printf(
          "%sstruct № %d\nvalue = %.2f priority = %d type = %d num = "
          "%d%s\n",
          GREEN, i, src[i].value, src[i].priority, src[i].type, src[i].num,
          RESET);
  }
}

void if_digit(char* str, s21_SmartCalc src, int n_struct) {
  double digit = atof(str);
  src[n_struct].value = digit;
  src[n_struct].priority = 0;
  src[n_struct].type = 1;
  src[n_struct].num = n_struct;
}

void print_struct_for_str(s21_SmartCalc src) {
  char mod[] = "mod";
  char sin[] = "sin";
  char cos[] = "cos";
  char tan[] = "tan";
  char acos[] = "acos";
  char asin[] = "asin";
  char atan[] = "atan";
  char sqrt[] = "sqrt";
  char ln[] = "ln";
  char log[] = "log";
  // char bracket_l[] = "bracket_l";
  // char bracket_r[] = "bracket_r";
  // char un_minus[] = "un_minus";

  for (int i = 0; src[i].num != -1; i++) {

    switch (src[i].type) {
      case 1:
        printf("%s%.2f %s ", YELLOW, src[i].value, RESET);
        break;
      case 2:
        printf("%s%c %s ", YELLOW, 'x', RESET);
        break;
      case 3:
        printf("%s%c %s ", YELLOW, '+', RESET);
        break;
      case 4:
        printf("%s%c %s ", YELLOW, '-', RESET);
        break;
      case 5:
        printf("%s%c %s ", YELLOW, '*', RESET);
        break;
      case 6:
        printf("%s%c %s ", YELLOW, '/', RESET);
        break;
      case 7:
        printf("%s%c %s ", YELLOW, '^', RESET);
        break;
      case 8:
        printf("%s%s %s ", YELLOW, mod, RESET);
        break;
      case 9:
        printf("%s%s %s ", YELLOW, sin, RESET);
        break;
      case 10:
        printf("%s%s %s ", YELLOW, cos, RESET);
        break;
      case 11:
        printf("%s%s %s ", YELLOW, tan, RESET);
        break;
      case 12:
        printf("%s%s %s ", YELLOW, acos, RESET);
        break;
      case 13:
        printf("%s%s %s ", YELLOW, asin, RESET);
        break;
      case 14:
        printf("%s%s %s ", YELLOW, atan, RESET);
        break;
      case 15:
        printf("%s%s %s ", YELLOW, sqrt, RESET);
        break;
      case 16:
        printf("%s%s %s ", YELLOW, ln, RESET);
        break;
      case 17:
        printf("%s%s %s ", YELLOW, log, RESET);
        break;
      case 18:
        printf("%s%c %s ", YELLOW, '(', RESET);
        break;
      case 19:
        printf("%s%c %s ", YELLOW, ')', RESET);
        break;
      case 20:
        printf("%s%c %s ", YELLOW, '~', RESET);
        break;
    }
  }
  printf("\n");
}