#pragma once

#include <memory>
#include <map>
#include <string>
#include <iostream>

template <typename T>
class ScopedEnv {

public:
	// constructors
	ScopedEnv() : enclosing(nullptr) {
	}

	ScopedEnv(const std::shared_ptr<ScopedEnv<T>>& enclosing)
		: enclosing(enclosing) {
	}

public:
	// methods
	void define(const std::string& name, const T& value) {
		this->table[name] = value;
	}

	void assign(const std::string& name, const T& value)
	{
		// if contains
		if (table.find(name) != table.end()) {
			table[name] = value;
			return;
		}
		if (enclosing) {
			enclosing->assign(name, value);
			return;
		}

		std::string error_msg = "Undefined variable: '" + name + "'";
		std::cout << error_msg << "\n";
		throw std::exception(error_msg.c_str());
		exit(1);
	}

	T get(const std::string& name) 
	{
		if (table.find(name) != table.end())
			return table[name];

		if (enclosing)
			return enclosing->get(name);

		std::string error_msg = "Undefined variable: '" + name + "'";
		std::cout << error_msg << "\n";
		throw std::exception(error_msg.c_str());
		exit(1);
	}

	size_t size() {
		return table.size();
	}

private:
	// parameters
	std::shared_ptr<ScopedEnv<T>> enclosing;
	std::map < std::string, T> table;
};

