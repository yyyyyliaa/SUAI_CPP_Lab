#include <iostream>      
#include <string> 
#include <map>

#include "LFUcashe.hpp"

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

void LfuCashe::printSearch(){
	multimap<int, string>::iterator it;
	it = search.begin();
	while (it!=search.end()) {
		cout<<it->first<<" "<<it->second<<endl;
		it++;
	}
}

string LfuCashe::findMin(){
	multimap<int, string>::iterator it;
	it = search.begin();
    return it->second;
}

bool LfuCashe::find_and_add(const string &address){
	auto result = cashe.find(address);
	if (result == cashe.end()){
		if (count < size){
			cashe.insert (pair<string,int>(address, 1));
			search.insert(pair<int, string>(1, address));
			count++;
		}
		else {
			string res = findMin();
			multimap<int, string>::iterator it;
			it = search.begin();
			while (it!=search.end()) {
				if (it->second == res) {
					search.erase(it);
					break;
				}
				it++;
			}
			cashe.erase(res);

			cashe.insert(pair<string,int>(address, 1));	
			search.insert(pair<int, string>(1, address));		
		}
		return false;
	}
	else{
		multimap<int, string>::iterator it;
		it = search.begin();
		while (it!=search.end()) {
			if (it->second == address) {
				int tmp = it->first + 1;
				search.erase(it);
				search.insert(pair<int, string>(tmp, address));
				break;
			}
			it++;
		}
		cashe[address] += 1;
	}
	return true;	
}

void LfuCashe::apply(const string &address) {
	auto result = cashe.find(address);
	
	if (result != cashe.end()){
		multimap<int, string>::iterator it;
		it = search.begin();
		while (it!=search.end()) {
			if (it->second == address) {
				int tmp = it->first + 1;
				search.erase(it);
				search.insert(pair<int, string>(tmp, address));
				break;
			}
			it++;
		}
		cashe[address] += 1;
	}
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




