#include "string.h"
#include "object.h"

/**
* An object that represents a map to store keys and values.
* Map does not own any objects passed to it.
*/
class Map : public Object {

  public:

    /* The constructor*/
    Map() { }

    /* The destructor*/
    ~Map() { }

    /**
    * Determines the number of items in the map
    * @return the size of the map
    */
    size_t size() {

    }

    /**
    * Adds the given key value pair to the Map
    * @param key is the object to map the value to
    * @param value the object to add to the Map
    */
    void add(Object* key, Object* value) {

    }

    /**
    * Removes all the elements from the Map
    */
    void clear() {

    }

    /**
    * Returns a copy of the Map
    * @return the copy of this map
    */
    Map* copy(){

    }

    /**
    * Returns the value of the specified key
    * @param key the key to get the value from
    * @return the value associated with the key
    */
    Object* get(Object* key) {

    }

    /**
    * Returns the Map's keys.
    */
    Object** keys() {

    }

    /**
    * Returns all the Map's values
    */
    Object** values() {

    }

    /**
    * Removes the element with the specified key
    * @param key the key
    * @return the value of the element removed
    */
    Object* pop_item(Object* key) {

    }

    /**
		* Is this object equal to that object?
		* @param o is the object to compare equality to.
		* @return	whether this object is equal to that object.
		*/
		virtual bool equals(Object* o) {}

		/**
		* Calculate this object's hash.
		* @return a natural number of a hash for this object.
		*/
		virtual size_t hash() {}

};
