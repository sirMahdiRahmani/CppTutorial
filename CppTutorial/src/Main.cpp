#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <chrono>
#include "Print.h"


int Add(int a, int b) {
    return a + b;
}

void GetResult(int a ,int b, int(*addfunc)(int, int))
{
	std::cout << addfunc(a ,b) << std::endl;
}

int main()
{
    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    int(*add)(int,int) = Add;

    print("Mahdi");
    GetResult(5, 4, add);


    // End the timer
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration
    std::chrono::duration<double> duration = end - start;
    // Print the duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;
    return 0;
}
