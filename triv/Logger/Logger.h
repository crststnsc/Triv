#pragma once
#include <string>
#include <iostream>

#ifdef LOGGER_EXPORTS
	#define LOGGER_API __declspec(dllexport)
#else
	#define LOGGER_API __declspec(dllimport)
#endif

class LOGGER_API Logger
{
public:
	enum class MessegeType {
		Info,
		Warning,
		Error
	};

private:
	std::ostream& os; 
};

