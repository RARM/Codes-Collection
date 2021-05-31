// verify_numeric_input.cpp -- verifies that the input only contains numbers.
// This program is a simple solution to verify if a specific input through the
// terminal is a number or not.

#include <iostream>
#include <string>
#include <vector>

bool is_numeric_input(std::string user_input, bool use_decimals);
std::string get_user_input(void);
std::vector<std::string> get_array_of_words(std::string line);

int main(void)
{
	size_t n_words{}, valid_nubers{0};

	std::string user_input{get_user_input()};
	std::vector<std::string> words{get_array_of_words(user_input)};
	n_words = words.size();

	for (unsigned i{0}; i < n_words; i++)
	{
		bool is_number{is_numeric_input(words.at(i), true)};
		valid_nubers += (is_number) ? 1 : 0;

		std::cout << "\"" << words.at(i) << "\" is " << ((is_number) ? "" : "not ") << "a number.\n";
	}

	std::cout << "\nOf the " << n_words << " words recognized, only " << valid_nubers << " are recognized as valid numbers.\n";

	return 0;
}

bool is_numeric_input(std::string user_input, bool use_decimals)
{
	bool is_numeric{true};

	if (use_decimals)
	{
		bool using_decimal{false};
		for (auto c: user_input) {
			if (
				(std::isdigit(c) == 0 && c != '.') ||
				(std::isdigit(c) == 0 && (c == '.' && using_decimal))
			) is_numeric = false;
			if (c == '.') using_decimal = true;
		}
	}
	else
		for (auto c: user_input)
			if (std::isdigit(c) == 0) is_numeric = false;

	return is_numeric;
}

std::string get_user_input(void)
{
	std::string user_input{};

	std::cout << "Please, enter numbers (can contain \".\" for decimals but no thousands separators) separated by spaces: ";
	std::getline(std::cin, user_input);

	std::cout << "\nInput received: \"" << user_input << "\".\n\n";

	return user_input;
}

std::vector<std::string> get_array_of_words(std::string line)
{
	std::vector<std::string> list_of_words{};
	std::string word{};
	char c{};

	for (unsigned i{0};  i < line.size(); i++)
	{
		c = line.at(i);
		if (c != ' ') word.push_back(c);

		if (c == ' ' || i == line.size() - 1) {
			list_of_words.push_back(word);
			word.clear();
		}
	};

	return list_of_words;
}
