#pragma once

#include "string.h"
#include "object.h"

class MapItem {
  /*
  Represents an item / entry in the Map's interal storage structure.
  nullptr key and value represent a deleted ("trash") item.
  */
  public:

    Object *key;
    Object *value;

    MapItem(Object *key_, Object *value_) {
      this->key = key_;
      this->value = value_;
    }

    /* Copy constructor */
    MapItem(MapItem *o) {
      this->key = o->key;
      this->value = o->value;
    }

};

/**
* An object that represents a map to store keys and values.
* Map does not own any objects passed to it.
*/
class Map : public Object {
  /*
  A linear probing hash map implementation.
  */

  public:
    
    const size_t INITIAL_CAPACITY = 4;
    // Current "load" = (size_ + trash_size_) / capacity_
    const float LOAD_FACTOR_MAX = 0.8;
    const float LOAD_FACTOR_MIN = 0.2;
    size_t size_;
    size_t trash_size_;
    size_t capacity_;
    MapItem **storage_;

    /* The constructor*/
    Map() {
      this->size_ = 0;
      this->trash_size_ = 0;
      this->capacity_ = this->INITIAL_CAPACITY;
      this->storage_ = reinterpret_cast<MapItem**>(malloc(this->capacity_ * sizeof(void*)));
      fprintf(stderr, "storage: %p\n", this->storage_);
      this->_init_storage();
    }

    Map(size_t capacity) {

    }

    /* Copy constructor */
    Map(Map *o) {
      this->size_ = o->size_;
      this->trash_size_ = o->trash_size_;
      this->capacity_ = o->capacity_;
      this->storage_ = reinterpret_cast<MapItem**>(malloc(this->capacity_ * sizeof(void*)));
      for (size_t i = 0; i < this->capacity_; i++) {
        MapItem **p = this->storage_ + i;
        MapItem *other_item = *(o->storage_ + i);
        if (other_item != nullptr) {
          *p = new MapItem(other_item);
        } else {
          *p = nullptr;
        }
        
      }
    }

    /* The destructor*/
    virtual ~Map() {
      this->_delete_contents();
      free(this->storage_);
    }

    void _init_storage() {
      for (size_t i = 0; i < this->capacity_; i++) {
        MapItem **p = this->storage_ + i;
        *p = nullptr;
      }
    }

    void _delete_contents() {
      for (size_t i = 0; i < this->capacity_; i++) {
        MapItem **p = this->storage_ + i;
        MapItem *item = *p;
        if (item != nullptr) {
          delete item;
          *p = nullptr;
        }
      }
    }

    size_t _index_for_key(Object *key) {
      // Must be at least one available space open
      assert(this->size_ < this->capacity_);

      size_t hash = key->hash();
      size_t index = hash % this->capacity_;

      // Go to the next index until no MenuItem exists at that key, 
      MapItem *item;
      do {
        item = *(this->storage_ + index);
        if (index >= this->capacity_ - 1) {
          index = 0;
        }
        index++;
        fprintf(stderr, "p: %p\n", item);
      } while (item != nullptr && (item->key == nullptr || item->key->hash() != hash));
      fprintf(stderr, "index: %d\n", index-1);
      return index - 1;
    }

    void _maintain_load() {
      float occupied = this->_percent_occupied();
      if (occupied >= this->LOAD_FACTOR_MAX) {
        this->_grow();
      } else if (this->capacity_ != this->INITIAL_CAPACITY && occupied <= this->LOAD_FACTOR_MIN) {
        this->_shrink();
      }
    }

    void _grow() {
      // Map *temp = new Map()
    }

    void _shrink() {

    }

    void _rehash_with_size(size_t new_size) {

    }

    float _percent_occupied() {
      return (this->size_ + this->trash_size_) / this->capacity_;
    }

    /**
    * Determines the number of items in the map
    * @return the size of the map
    */
    size_t size() {
      return this->size_;
    }

    /**
    * Adds the given key value pair to the Map
    * @param key is the object to map the value to
    * @param value the object to add to the Map
    */
    void add(Object* key, Object* value) {
      this->_maintain_load();
      size_t index = this->_index_for_key(key);
      MapItem **p = this->storage_ + index;
      MapItem *item = *p;
      if (item == nullptr) {
        fprintf(stderr, "new item\n");
        item = new MapItem(key, value);
        *p = item;
        this->size_++;
      } else {
        fprintf(stderr, "overwrite item\n");
        item->key = key;
        item->value = value;
      }
      
    }

    /**
    * Removes all the elements from the Map
    */
    void clear() {
      this->_delete_contents();
      this->size_ = 0;
      this->trash_size_ = 0;
    }

    /**
    * Returns a copy of the Map
    * @return the copy of this map
    */
    Map* copy(){
      return new Map(this);
    }

    /**
    * Returns the value of the specified key
    * @param key the key to get the value from
    * @return the value associated with the key
    */
    Object* get(Object* key) {
      size_t index = this->_index_for_key(key);
      MapItem *item = *(this->storage_ + index);
      if (item == nullptr) {
        return nullptr;
      }
      return item->value;
    }

    /**
    * Returns the Map's keys.
    */
    Object** keys() {
      Object **result = reinterpret_cast<Object**>(malloc(this->size() * sizeof(Object*)));
      size_t index = 0;
      for (size_t i = 0; i < this->capacity_; i++) {
        MapItem *item = *(this->storage_ + i);
        if (item != nullptr && item->key != nullptr) {
          // This is a real item that should be added to the list of keys
          Object **p = result + index;
          *p = item->key;
          index++;
        }
      }
      return result;
    }

    /**
    * Returns all the Map's values
    */
    Object** values() {
      Object **result = reinterpret_cast<Object**>(malloc(this->size() * sizeof(Object*)));
      size_t index = 0;
      for (size_t i = 0; i < this->capacity_; i++) {
        MapItem *item = *(this->storage_ + i);
        if (item != nullptr && item->key != nullptr) {
          // This is a real item that should be added to the list of keys
          Object **p = result + index;
          *p = item->value;
          index++;
        }
      }
      return result;
    }

    /**
    * Removes the element with the specified key
    * @param key the key
    * @return the value of the element removed
    */
    Object* pop_item(Object* key) {
      return nullptr;
    }

    /**
		* Is this object equal to that object?
		* @param o is the object to compare equality to.
		* @return	whether this object is equal to that object.
		*/
		virtual bool equals(Object* o) {
      return true;
    }

		/**
		* Calculate this object's hash.
		* @return a natural number of a hash for this object.
		*/
		virtual size_t hash() {
      return 0;
    }

};
