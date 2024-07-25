#include "pch.h"

std::optional<std::string> ReadFile(const std::string& filePath)
{
	std::ifstream stream(filePath);
	if (stream) 
	{
		
		std::string result;

		std::getline(stream, result);
		stream.close();
		return result;
	}

	return std::nullopt;
}

int main()
{
	std::optional<std::string> data = ReadFile("D:/Projects/sirMahdiRahmani/CppTutorial/CppTutorial/src/file.text");
	auto text = data.value(); // or data.value().

	if (data.has_value())
	{
		std::cout << "Successful!" << std::endl;
	}
	else
	{
		std::cout << "Not Successful!" << std::endl;
	}

	std::cout << text << std::endl;
}
