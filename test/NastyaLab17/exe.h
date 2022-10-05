#pragma once
#include<string>

class Exception {
	std::string msg;
public:
	Exception(std::string a) {

		msg = a;
	}
	std::string get() {
		return msg;
	};
}; 
