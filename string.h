#pragma once

#include "object.h"
#include "helper.h"
#include <string.h>
#include <stddef.h>
#include <iostream>

/**
* Represents a string class standard in most libraries.
*/
class String : public Object {

	public:

		char *str_;
		size_t size_;

		/**
		* Create a string and copy the contents of the given array.
		* @param c is the character array to be copied and used.
		*/
		String(const char* c) {
			this->size_ = strlen(c) - 1;
			this->str_ = reinterpret_cast<char *>(malloc((sizeof(char) * (size_ + 1))));
			strcpy(this->str_, c);
		}

		/**
		* Delete this string and the character array associated with it.
		*/
		~String() {
			delete str_;
		}

		/**
		* Hash this string.
		* @return an integer hash of this string.
		*/
		size_t hash() {
			size_t result = 0;
			for (int i = 0; i <= this->size(); i++) {
				char c = *(this->str_ + i);
				result += rotl32c(c, i % 32);
			}
			return result;
		}

		/**
		* Is this string equal to that object?
		* @param o is the object to be compared to.
		* @return a boolean determining if these two objects are the same.
		*/
		bool equals(Object* o) {
			String *s = dynamic_cast<String *>(o);
			if (s == nullptr) {
				return false;  // object was not of type String
			}
			return this->compare(s) == 0;
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
			return strcmp(this->str_, s->str_);
		}

		/**
		* Concatenate this string with that string. Do not modify either.
		* @param s is the string to concatenate to.
		* @return a concatenated version of both strings.
		*/
		String* concat(String* s) {
			if (s == nullptr) {
				// Guard against other being nullptr. Just return copy of self
				return new String(this->str_);
			}
			
			size_t len_other = strlen(s->str_);
			size_t len_this = strlen(this->str_);
			size_t len = len_other + len_this;
			char *n = reinterpret_cast<char *>(malloc((sizeof(char) * (len + 1))));
			strcpy(n, this->str_);
			strcat(n, s->str_);
			return new String(n);
		}

		/**
		* Return the size of this string.
		*/
		size_t size() {
			return this->size_;
		}

};
