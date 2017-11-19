# include <iostream>
using std::cin; using std::cout; using std::endl;
# include <string>
using std::string; using std::to_string;
# include <vector>
using std::vector;
# include <iterator>
using std::begin; using std::end; using std::iterator;
# include <sstream>
using std::ostringstream;

void display(vector<int> v) {
	/*
		This part of the code allows us to see what is inside of the array
	*/

	// Print out each number to see what is inside vector
	string string_print;
	int b;

	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		string_print += to_string(*i) + ", ";
	}
	
	//// Need to get rid of trailing commas
	//ostringstream ss;

	//// Copy from beinging to end, -1 and 
	//std::copy(v.begin(), v.end() - 1, std::ostream_iterator<int>(ss, ", "));
	//ss << v.back();

	// making the input look like a array
	cout << "[" << string_print << "]";

	// pause
	//cin >> b;
}

vector<int> array_shift(vector<int> &v, int shift, int const len) {
	/*
		This function will shift the array d spaces
	*/
	
	vector<int> new_v;
	new_v.resize(len);

	
	for (size_t n = 0 ; n < len - 1; ++n) {
		cout << "value of i" << n << endl;
		int new_index = (n - shift) % len;
		new_v[new_index] = v[n];
	}
	new_v[1] = 2;
	return new_v;
}


int main() {
	vector <int> myvec;
	int b;
	int input;
	int length;
	int move;
	int stop = 0;

	//inputing the length of the vector
	cout << "Enter length of array: ";
	cin >> length;

	//inputing the number of shifts
	cout << "Enter num of moves: ";
	cin >> move;

	// Want to grab a list of numbers
	while (stop != length) {
		cout << "Add numbers to insert to the array: ";
		cin >> input;
		myvec.push_back(input);
		stop += 1;
	}
	// Shows the newly created array
	display(myvec);

	// Shifting the elements leftward
	vector<int> shift_array;
	shift_array = array_shift(myvec, move, length);

	display(shift_array);

	cin >> b;
}
