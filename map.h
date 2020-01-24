#include "string.h"
#include "object.h"

/* An object that represents a map to store keys and values*/
class Map : public Object {
public:

  /* the map to store keys and values */
  Object* map_;

  /* The constructor*/
  Map() {
    this->map_ = new Object();
  }

  /* The destructor*/
  ~Map() {

  }

  /**
  * Determines the number of items in the map
  * @return the size of the map
  */
  size_t size() {
    return 0;
  }

  /**
  * Adds the given key value pair to the Map
  * @param key is the object to map the value to
  * @param value the object to add to the Map
  */
  void add(Object key, Object value) {

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
    return new Map();
  }

  /**
  * Returns the value of the specified key
  * @param key the key to get the value from
  * @return the value associated with the key
  */
  Object* get(Object key) {
    return new Object();
  }

  /**
  * Returns the Map's keys
  *
  */
  Object* keys() {
    return new Object();
  }

  /**
  * Returns all the Map's values
  */
  Object* values() {
    return new Object();
  }

  /**
  * Removes the element with the specified key
  * @param key the key
  * @return the value of the element removed
  */
  Object* pop_item(Object key) {
    return new Object();
  }

  /**
  * Removes the last key-value pair
  * @return the value of the element removed
  */
  Object* pop() {
    return new Object();
  }
};
