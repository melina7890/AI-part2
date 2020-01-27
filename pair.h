#include "string.h"
#include "object.h"

#pragma once

/**
* A pair of objects.
* NOTE: This pair has its objects PURPOSELY as public. Rather than implement
* any sort of getters, just access the fields.
*/
class Pair {

  public:
    Object * o1; // object1 to hold (NOT OWNED)
    Object * o2; // object2 to hol (NOT OWNED)

    /**
    * Create a pair.
    */
    Pair(Object * o1, Object * o2) {
      this->o1 = o1;
      this->o2 = o2;
    }

    // Delete this pair.
    ~Pair() {}

}
