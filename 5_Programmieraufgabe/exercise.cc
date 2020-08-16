#include <iostream>
#include <string>
#include "exercise.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;	

// Aufgabe 1
uchar hex_xor(uchar &hex1, uchar &hex2)
{
	return (hex1 ^ hex2);
}

// Aufgabe 2
ByteArray hex_vector_xor(ByteArray &vec1, ByteArray &vec2)
{
	ByteArray result(vec1.size(), 0x00);

	for (int i = 0; i != vec1.size(); ++i)
	{
		result[i] = hex_xor(vec1[i], vec2[i]);
	}

	return result;
}