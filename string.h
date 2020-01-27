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
		// the hash value so as to not need to recalculate
		size_t hash_;
		// the size of this string
		size_t size;
		// The data for this string
		char* str_;

		/**
		* Create a string and copy the contents of the given array.
		* @param c is the character array to be copied and used.
		*/
		String(const char* c) {
			this->size = strlen(c);
			char* cstr = new char[this->size + 1];
			strcpy(cstr, c);
			this->str_ = cstr;
		}

		/**
		* Delete this string and the character array associated with it.
		*/
		~String() {
			delete[] this->str_;
		}

		/**
		* Hash this string.
		* @return an integer hash of this string.
		*/
		size_t hash() {
			// This is the one_at_a_time hashing algorithm from:
			// https://en.wikipedia.org/wiki/Jenkins_hash_function
			if (this->hash_ != 0) {
				return this->hash_;
			}

			size_t i = 0;
			size_t h = 0;
			while (i != this->size) {
  				h += this->str_[i++];
  				h += h << 10;
  				h ^= h >> 6;
			}

			h += h << 3;
			h ^= h >> 11;
			h += h << 15;
 			this->hash_ = h;
			return h;
		}

		/**
		* Is this string equal to that object?
		* @param o is the object to be compared to.
		* @return a boolean determining if these two objects are the same.
		*/
		bool equals(Object* o) {
			String* s = dynamic_cast<String*> (o);
			return (s != nullptr) && (strcmp(s->str_, this->str_) == 0);
		}

		/**
		* Print this string.
		*/
		void print() {
			std::cout << this->str_;
		}

		/**
		* Take the other string, and compare to see if we are bigger.
		* @param s is the string to compare to.
		* @return an integer smaller than 0 if this is smaller, equal to 0 if
		* they are the same, and greater than 0 if we are bigger.
		*/
		int compare(String* s) {
			return strcmp(this->str_, s->str_);
		}

		/**
		* Concatenate this string with that string. Do not modify either.
		* @param s is the string to concatenate to.
		* @return a concatenated version of both strings.
		*/
		String* concat(String* s) {
			char cstr[this->size + 1];
			strcpy(cstr, this->str_);
			String* ret = new String(strcat(cstr, s->str_));
			return ret;
		}

		/**
		* Return the size of this string.
		*/
		size_t size() {
			return this->size();
		}

};
