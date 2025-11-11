#ifndef _CALCULATOR_20_
#define _CALCULATOR_20_

#include <string>

double FtoC(double temp_f);
double FtoK(double temp_f);
double CtoF(double temp_c);
double CtoK(double temp_c);
double KtoC(double temp_k);
double KtoF(double temp_k);

double ask_F(void);  // depr
double ask_C(void);  // depr
double ask_K(void);  // depr
double ask_temp(char unit);

double check(double temp, char unit);

void show_menu(void);
void show_hist(double* conv_hist, char* unit_hist, int hist_size, int hist_ptr);

//void pause(void);
//void pause(string msg);

#endif // !_CALCULATOR_20_