#include <stddef.h>
#pragma once

// Generic object.
class Object {

	public:
		// the hash function so we do not have to recalculate later.
		size_t h_;

		/**
		* The constructor for this object.
		*/
		Object() {
			this->h_ = 0;
		}

		/**
		* Is this object equal to that object?
		* @param o is the object to compare equality to.
		* @return	whether this object is equal to that object.
		*/
		virtual bool equals(Object* o) {
			return this->h_ == o->h_;
		}

		/**
		* Calculate this object's hash.
		* @return a natural number of a hash for this object.
		*/
		virtual size_t hash() {
			if (this->h_ == 0) {
				this->h_ = (size_t) this;
			}

			return this->h_;
		}

		/**
		* Print this object.
		*/
		virtual void print() {

		}

};
