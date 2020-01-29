#pragma once

#include <stddef.h>

// Generic object.
class Object {

	public:

		size_t hash_;

		/**
		* The constructor for this object.
		*/
		Object() {
			this->hash_ = 0;
		}

		/**
		* Is this object equal to that object?
		* @param o is the object to compare equality to.
		* @return	whether this object is equal to that object.
		*/
		virtual bool equals(Object* o) {
			void *p1 = dynamic_cast<void *>(o);
			void *p2 = dynamic_cast<void *>(this);
			
			return p1 == p2;
		}

		/**
		* Calculate this object's hash.
		* @return a natural number of a hash for this object.
		*/
		virtual size_t hash() {
			if (hash_ == 0) {
				hash_ = this->hash_me_();
			}
			return hash_;
		}

		/**
		* Calculate this object's hash (helper method).
		* @return a natural number of a hash for this object.
		*/
		virtual size_t hash_me_() {
			return reinterpret_cast<size_t>(this);
		}

};
