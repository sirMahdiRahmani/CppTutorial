#include <iostream>
#include <string>
#include <vector>
#include <tuple>


const std::vector<std::tuple<std::string, int>> GetNameAndAge()
{
	std::vector<std::tuple<std::string, int>>* NameAndAge = new std::vector<std::tuple<std::string, int>>;
	
	std::tuple<std::string, int> Mahdi = std::make_tuple<std::string, int>("Mahdi", 19); // we can use the type to store variable
	auto Dani = std::make_tuple<std::string, int>("Daniyal", 30); // or we can use auto to store variable (Much Cleaner)
	
	NameAndAge->reserve(2);
	NameAndAge->emplace_back(Mahdi);
	NameAndAge->emplace_back(Dani);
	return *NameAndAge;
}	

std::ostream& operator<<(std::ostream& stream, std::vector<std::tuple<std::string, int>>& NameAndAge) 
{
	for(int i = 0; i < NameAndAge.size(); i++)
	{
		stream << std::get<0>(NameAndAge[i]) << ", " << std::get<1>(NameAndAge[i])<< std::endl;
	}
	return stream;
}

int main()
{
	auto NameAndAge =  GetNameAndAge(); // We Can use auto (Much Cleaner)
	std::vector<std::tuple<std::string, int>> NameAndAge2 =  GetNameAndAge(); // Or We Can use exact type (both work same way)
	
	std::cout << NameAndAge << std::endl;
	std::cout << NameAndAge2 << std::endl;
}

