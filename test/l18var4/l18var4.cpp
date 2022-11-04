#include <iostream>      
#include <string> 
#include <map>

#include "l18var4.hpp"

using namespace std;

LfuCashe::LfuCashe(size_t size){
    this->size = size;
}


map <string, int>::iterator LfuCashe::find_value(const int value){
	map<string, int>::iterator it;
	it = cashe.begin();

    while (it!=cashe.end()){
        if (it->second==value) 
		return it;
        it++;
    }
    return cashe.end();
}

int LfuCashe::findMin(){
	map<string, int>::iterator it;
	it = cashe.begin();
	int min = it->second;
	while (it!=cashe.end()) {
		if (min > (*it).second) min = (*it).second;
		it++;
	}
    return min;
}

int LfuCashe::getMin(){
	return min;
}

bool LfuCashe::find_and_add(const string &address){
	auto result = cashe.find(address);
	if (result == cashe.end()){
		if (count < size){
			cashe.insert (pair<string,int>(address, 1));
			min = 1;
			count++;
		}
		else {
			auto res = find_value(min);
			cashe.erase(res);

			cashe.insert (pair<string,int>(address, 1));			
		}
		return false;
	}
	else{
		cashe[address] += 1;
		int value = cashe[address];
		min = findMin();
	}
	return true;	
}

bool LfuCashe::find(const string &address) {
	auto result = cashe.find(address);
	
	if (result != cashe.end()){
		cashe[address] += 1;
		int value = cashe[address];
		min = findMin();
		return true;
	}
	else return false;
}

std::ostream& operator<<(std::ostream& os, LfuCashe& c){
	cout<<"Cashe size: "<< c.size<<endl;
	map<std::string, int> :: iterator it = c.cashe.begin();
    for (int i = 0; it != c.cashe.end(); it++, i++) { 
        cout<<"Address: "<<it->first<<endl;
		cout<<"Number of requests: "<<it->second<<endl<<endl;
    }

	return os;
}