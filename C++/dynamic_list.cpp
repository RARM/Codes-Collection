// dynamic_list.cpp -- Demostrate how to use vectors in C++.
// This program is similar to the "dynamic_arr.c" in the C folder.
// However, it uses vectors to manage the list. This program was
// completed before "dynamic_arr.c". This program was a solution to a
//challenge in the Udemy CPP class taught by Dr. Frank Mitropoulos,
// "Beginning C++ Programming - From Beginner to Beyond".
#include <iostream>
#include <vector>

void print_numbers(std::vector<int> numbers);
void add_number(std::vector<int> *list, bool allow_duplicates);
void calculate_mean(std::vector<int> numbers);
void print_smallest(std::vector<int> list);
void print_largest(std::vector<int> list);
void clear_list(std::vector<int> *list);
void edit_settings(std::vector<int> *numbers, bool *duplicates);
void eliminate_duplicates(std::vector<int> *list);

int main() {
	bool done {false};
	bool duplicates {true}; // Setting.
	std::vector<int> numbers {};

	do {
		char selection {};

		// Printing main menu.
		std::cout << "--------------------------------\n"
				  << "Main Menu\n"
				  << "P - Print numbers.\n"
				  << "A - Add number.\n"
				  << "M - Display mean of the numbers.\n"
				  << "S - Display the smallest number.\n"
				  << "L - Display the largest number.\n"
				  << "E - Adjust settings.\n"
				  << "C - Clear the list of numbers.\n"
				  << "Q - Quit.\n\n"
				  << "Enter selection: ";

		std::cin >> selection;

		switch (selection) {
			case 'P':
			case 'p':
				system("@cls||clear");
				print_numbers(numbers);
				std::cout << std::endl;
				break;
			case 'A':
			case 'a':
				add_number(&numbers, duplicates);
				std::cout << std::endl;
				break;
			case 'M':
			case 'm':
				system("@cls||clear");
				calculate_mean(numbers);
				std::cout << std::endl;
				break;
			case 'S':
			case 's':
				system("@cls||clear");
				print_smallest(numbers);
				std::cout << std::endl;
				break;
			case 'L':
			case 'l':
				system("@cls||clear");
				print_largest(numbers);
				std::cout << std::endl;
				break;
			case 'E':
			case 'e':
				system("@cls||clear");
				edit_settings(&numbers, &duplicates);
				std::cout << std::endl;
				break;
			case 'C':
			case 'c':
				system("@cls||clear");
				clear_list(&numbers);
				std::cout << std::endl;
				break;
			case 'Q':
			case 'q':
				done = true;
				system("@cls||clear");
				std::cout << "Thank you for using this program.\n";
				break;
			default:
				system("@cls||clear");
				std::cout << "Error: Invalid selection. Please, enter a letter of the menu.\n\n";
		}
	} while (!done);

	return 0;
}

void print_numbers(std::vector<int> numbers) {
	if (numbers.size() == 0)
		std::cout << "[] - the list is empty.\n";
	else {
		std::cout << "[ ";
		for (auto number: numbers)
			std::cout << number << " ";
		std::cout << "]\n";
	}
}

void add_number(std::vector<int> *list, bool allow_duplicates) {
	int number {};
	std::cout << "Enter an integer to add to the list: ";
	std::cin >> number;

	bool already_exist {false};
	if (!allow_duplicates) {
		for (auto list_number: (*list))
			if (list_number == number) {
				already_exist = true;
				break;
			}
	}

	system("@cls||clear");

	if (!allow_duplicates && already_exist)
		std::cout << "Number not added. Current setting does not allow duplicates.\n";

	else {
		(*list).push_back(number);
		std::cout << "The number \"" << number << "\" was added.\n";
	}
}

void calculate_mean(std::vector<int> numbers) {
	if (numbers.size() == 0)
		std::cout << "Error: Unable to calculate the mean. List empty.\n";

	else {
		int total_sum {0};

		for (auto number: numbers)
			total_sum += number;

		std::cout << "Average: " << static_cast<double>(total_sum) / static_cast<double>(numbers.size()) << ".\n";
	}
}

void print_smallest(std::vector<int> list) {
	if (list.size() == 0)
		std::cout << "Error: Unable to determine the smallest number. List empty.\n";

	else {
		int smallest {list.at(0)};
		for (auto number: list)
			smallest = (number < smallest) ? number : smallest;

		std::cout << "Smallest number: " << smallest << ".\n";
	}
}

void print_largest(std::vector<int> list) {
	if (list.size() == 0)
		std::cout << "Error: Unable to determine the largest number. List empty.\n";

	else {
		int largest {list.at(0)};
		for (auto number: list)
			largest = (number > largest) ? number : largest;

		std::cout << "Largest number: " << largest << ".\n";
	}
}

void clear_list(std::vector<int> *list) {
	list->clear();
	std::cout << "List cleared.\n";
}

void edit_settings(std::vector<int> *numbers, bool *duplicates) {
	bool done {false};
	std::cout << std::boolalpha;

	do {
		char selection {};

		std::cout << "--------------------------------\n"
				  << "Settings\n"
				  << "1 - Allow duplicates: " << *duplicates << "\n"
				  << "2 - Exit settings menu.\n\n"
				  << "Select what you want to change: ";

		std::cin >> selection;

		switch (selection) {
			case '1':
				system("@cls||clear");
				{
					bool interselection_done {false};

					do {
						char selection {};

						std::cout << "Do you want to allow duplicates in your list?\n"
								  << "Y - Yes\n"
								  << "N - No: Current duplicates are going to be removed.\n"
								  << "E - Exit without editing.\n\n"
								  << "Enter selection: ";

						std::cin >> selection;

						switch (selection) {
							case 'y':
							case 'Y':
								system("@cls||clear");
								(*duplicates) = true;
								interselection_done = true;
								std::cout << "Now, duplicates are allowed.\n\n";
								break;
							case 'n':
							case 'N':
								system("@cls||clear");
								eliminate_duplicates(numbers);
								(*duplicates) = false;
								interselection_done = true;
								std::cout << "Duplicates removed.\n"
										  << "Now, duplicates are not allowed.\n\n";
								break;
							case 'e':
							case 'E':
								system("@cls||clear");
								interselection_done = true;
								std::cout << "No edits applied.\n\n";
								break;
							default:
								system("@cls||clear");
								std::cout << "Error: Invalid selection. Please, try again.\n\n"
										  << "--------------------------------\n";
						}
					} while (!interselection_done);
				}
				break;
			case '2':
				system("@cls||clear");
				done = true;
				break;
			default:
				system("@cls||clear");
				std::cout << "Error: Invalid selection. Please, try again.\n"
						  << "Enter an integer from the selection.\n"
						  << std::endl;
		}
	} while (!done);

	std::cout << "Settings updated.\n"
			  << "Allow duplicates: " << *duplicates << "\n";
}

void eliminate_duplicates(std::vector<int> *list) {
	if ((*list).size() > 1) {
		for (unsigned i {0}; i < (*list).size(); ++i) {
			int current_number {(*list).at(i)};
			bool duplicate_found {};
			for (unsigned j {i + 1}; j < (*list).size(); j += (duplicate_found) ? 0 : 1) {
				duplicate_found = false;
				if (current_number == (*list).at(j)) {
					duplicate_found = true;
					for (unsigned k {j}; k < (*list).size() - 1; k++)
						list->at(k) = list->at(k + 1);
					(*list).pop_back();
				}
			}
		}
	}
}
