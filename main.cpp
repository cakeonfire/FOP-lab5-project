#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

#include "main.h"

using namespace std;

const double K_limit = 0.0;
const double C_limit = -273.15;
const double F_limit = -459.67;
const double invalid_temp = -999.9;


//void debug_print(int* arr) {
//
//}
//
//void debug_print(char* arr) {
//
//}
//
//void debug_print(int* arr) {
//
//}


double FtoC(double temp_f) {
	return (temp_f - 32.0) * (5.0 / 9.0);
}


double FtoK(double temp_f) {
	return (temp_f + 459.67) * (5.0 / 9.0);
}


double CtoF(double temp_c) {
	return temp_c * (9.0 / 5.0) + 32.0;
}


double CtoK(double temp_c) {
	return temp_c + 273.15;
}


double KtoC(double temp_k) {
	return temp_k - 273.15;
}


double KtoF(double temp_k) {
	return temp_k * (9.0 / 5.0) - 459.67;
}


double ask_F(void) {
	double temp;
	cout << "Enter temperature (F): ";
	cin >> temp;
	return temp;
}


double ask_C(void) {
	double temp;
	cout << "Enter temperature (C): ";
	cin >> temp;
	return temp;
}


double ask_K(void) {
	double temp;
	cout << "Enter temperature (K): ";
	cin >> temp;
	return temp;
}


double ask_temp(char unit) {
	double temp;
	cout << "Enter temperature (" << unit << "): ";
	cin >> temp;
	return temp;
}


double check(double temp, char unit) {
	if (
			(unit == 'F' && temp < F_limit)
		|| (unit == 'C' && temp < C_limit)
		|| (unit == 'K' && temp < K_limit)
		) {
		return invalid_temp;
	}
	return temp;
}


void pause(void) {
	string dummy;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, dummy);
}


void pause(string msg) {
	string dummy;

	cout << msg;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, dummy);
}

void show_menu(void) {
	cout << "1 - convert Fahr -> Cels" << "\n";
	cout << "2 - convert Fahr -> Kelv" << "\n";
	cout << "3 - convert Cels -> Fahr" << "\n";
	cout << "4 - convert Cels -> Kelv" << "\n";
	cout << "5 - convert Kelv -> Cels" << "\n";
	cout << "6 - convert Kelv -> Fahr" << "\n";
	cout << "7 - show conversion history" << "\n";
	cout << "8 - exit program" << "\n";
	cout << endl;
	return;
}


void show_hist(double* conv_hist, char* unit_hist, int hist_size, int hist_ptr) {
	/*
	const int max_elements = hist_size / 2;
	int element_count, i, j, ec;
	if (hist_ptr <= hist_size) {
		element_count = hist_ptr / 2;
		i = 0;
	}
	else {
		element_count = max_elements;
		i = hist_ptr - hist_size;
	}
	
	ec = element_count;
	while (ec > 0) {
		j = i % hist_size;
		cout << (element_count-ec+1) << ") " << conv_hist[j] << unit_hist[j] << " = " << conv_hist[j+1] << unit_hist[j+1] << "\n";

		ec--;
		i += 2;
	}
	cout << endl;
	*/

	if (hist_ptr == 0) {
		cout << "No data found.";
		return;
	}

	for (int i = 0; (i < hist_size) && (i < hist_ptr); i += 2) {
		//cout << (element_count - ec + 1) << ") " << conv_hist[j] << unit_hist[j] << " = " << conv_hist[j + 1] << unit_hist[j + 1] << "\n";
		cout << (i / 2)+1 << ") " << conv_hist[i] << unit_hist[i] << " = " << conv_hist[i + 1] << unit_hist[i + 1] << "\n";
	}

	cout << endl;
}


int main(void) {
	const int hist_size = 100;  // space for 50 records
	int data_counter = 0;
	double conv_hist[hist_size];
	char unit_hist[hist_size];

	int option;
	double orig_temp, conv_temp;
	char orig_unit, conv_unit, tmp;

	cout << fixed << setprecision(2);

	while (1) {
		system("cls");
		show_menu();
		cout << "Enter option: ";
		cin >> option;

		if (option >= 1 && option <= 6) {  // do conversion

			switch (option) {
			case 1:  // Fahr -> Cels
				orig_unit = 'F';
				conv_unit = 'C';
				break;
			case 2:  // Fahr -> Kelv
				orig_unit = 'F';
				conv_unit = 'K';
				break;
			case 3:  // Cels -> Fahr
				orig_unit = 'C';
				conv_unit = 'F';
				break;
			case 4:  // Cels -> Kelv
				orig_unit = 'C';
				conv_unit = 'K';
				break;
			case 5:  // Kelv -> Cels
				orig_unit = 'K';
				conv_unit = 'C';
				break;
			case 6:  // Kelv -> Fahr
				orig_unit = 'K';
				conv_unit = 'F';
				break;
			}

			orig_temp = check(ask_temp(orig_unit), orig_unit);
			if (orig_temp == invalid_temp) {
				cout << "Invalid temperature value for (" << orig_unit << ")!" << endl;
				break;
			}

			switch (option) {
			case 1:  // Fahr -> Cels
				conv_temp = FtoC(orig_temp);
				break;
			case 2:  // Fahr -> Kelv
				conv_temp = FtoK(orig_temp);
				break;
			case 3:  // Cels -> Fahr
				conv_temp = CtoF(orig_temp);
				break;
			case 4:  // Cels -> Kelv
				conv_temp = CtoK(orig_temp);
				break;
			case 5:  // Kelv-> Cels
				conv_temp = KtoC(orig_temp);
				break;
			case 6:  // Kelv -> Fahr
				conv_temp = KtoF(orig_temp);
				break;
			default:
				conv_temp = invalid_temp;
			}

			cout << "\n";
			cout << "Original temperature (" << orig_unit << "): " << orig_temp << "\n";
			cout << "Converted temperature (" << conv_unit << "): " << conv_temp << "\n";
			cout << "\n";

			//system("pause");
			/*cout << ". . .";
			cin.ignore(1000, '\n');
			getline(cin, pause);*/

			// update conversion history
			// OLD solution with wrapped history (once reached the end, wrap to the beginning)
			/*
			conv_hist[data_counter % hist_size] = orig_temp;
			conv_hist[(data_counter % hist_size)+1] = conv_temp;
			unit_hist[data_counter % hist_size] = orig_unit;
			unit_hist[(data_counter % hist_size)+1] = conv_unit;
			data_counter += 2;
			*/

			// new solution - max at buffer size
			if (data_counter < hist_size) {
				conv_hist[data_counter] = orig_temp;
				conv_hist[data_counter + 1] = conv_temp;
				unit_hist[data_counter] = orig_unit;
				unit_hist[data_counter + 1] = conv_unit;
				data_counter += 2;
			}
			else {
				cout << "No more space in the history to save the record";
			}
		}
		else if (option == 7) {
			show_hist(conv_hist, unit_hist, hist_size, data_counter);
		}
		else {
			break;
		}
		pause();
	}

	return 0;
}
