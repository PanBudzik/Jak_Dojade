#ifndef STRING_H
#define STRING_H

#pragma once 
#pragma warning(disable:4996)

#include <cstring> 
#include <iostream>

class myString
{
private:
	char* data;
	int length;

public:
	myString();
	myString(const char* str);
	myString(const myString& other);
	~myString();
	myString& operator=(const myString& other);
	char& operator[](int index);
	const char& operator[](int index) const;
	int size() const;
	bool operator==(const myString& other) const;
	bool operator!=(const myString& other) const;
	myString operator+(const myString& other) const;
	myString& operator+=(const myString& other);
	myString operator+(const char& c) const;
	friend std::ostream& operator<<(std::ostream& out, const myString& str);
	friend std::istream& operator>>(std::istream& in, myString& str);
};

#endif