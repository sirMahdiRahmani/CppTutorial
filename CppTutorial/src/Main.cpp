#include <iostream>
#include <string>
#include <vector>
#include <tuple>

std::string reverse_words(std::string text)
{
	text = text + " ";
	std::vector<std::string> split_text;
	std::string NewString = "";

	std::string reverseWord = "";

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] != ' ')
		{
			reverseWord = reverseWord + text[i];
		}
		else
		{
			split_text.emplace_back(reverseWord);
			reverseWord = "";
		}
	}

	for (std::string s : split_text)
	{
		std::reverse(s.begin(), s.end());
		NewString = NewString + s + " ";
	}
	return NewString.substr(0, NewString.size() - 1);
}

int main()
{
	auto text = reverse_words("The quick brown fox jumps over the lazy dog.");
	std::cout << text;
}

