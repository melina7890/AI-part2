#include <stddef.h>
#pragma once

// Generic object.
class Object {

	public:

		/**
		* The constructor for this object.
		*/
		Object() {
		}

		/**
		* Is this object equal to that object?
		* @param o is the object to compare equality to.
		* @return	whether this object is equal to that object.
		*/
		virtual bool equals(Object* o) {

		}

		/**
		* Calculate this object's hash.
		* @return a natural number of a hash for this object.
		*/
		virtual size_t hash() {

		}

		/**
		* Calculate this object's hash (helper method).
		* @return a natural number of a hash for this object.
		*/
		virtual size_t hash_me_() {}

};
