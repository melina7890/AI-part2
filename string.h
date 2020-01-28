#include "object.h"
#include <string.h>
#include <stddef.h>
#include <iostream>
#pragma once

/**
* Represents a string class standard in most libraries.
*/
class String : public Object {

	public:
		/**
		* Create a string and copy the contents of the given array.
		* @param c is the character array to be copied and used.
		*/
		String(const char* c) {

		}

		/**
		* Delete this string and the character array associated with it.
		*/
		~String() {
		}

		/**
		* Hash this string.
		* @return an integer hash of this string.
		*/
		size_t hash() {

		}

		/**
		* Is this string equal to that object?
		* @param o is the object to be compared to.
		* @return a boolean determining if these two objects are the same.
		*/
		bool equals(Object* o) {

		}

		/**
		* Print this string.
		*/
		void print() {

		}

		/**
		* Take the other string, and compare to see if we are bigger.
		* @param s is the string to compare to.
		* @return an integer smaller than 0 if this is smaller, equal to 0 if
		* they are the same, and greater than 0 if we are bigger.
		*/
		int compare(String* s) {

		}

		/**
		* Concatenate this string with that string. Do not modify either.
		* @param s is the string to concatenate to.
		* @return a concatenated version of both strings.
		*/
		String* concat(String* s) {

		}

		/**
		* Return the size of this string.
		*/
		size_t size() {

		}

};
