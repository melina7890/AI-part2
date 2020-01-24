## Assignment 1 Part 2
### What's included:

#### An object.h file and a tring.h file
This is the same file as the one used for warm ups 1 through 3. We believed that
this file was necessary because it is the parent class for all object classes
such as the string class. Additionally, the assignment specified that it was necessary
for the Map to support String to String and String to Object.
This is why we included these files.

#### test-map.cpp
We include simple test examples for all of the functions described in the sections
below. 

#### map.h file
The map.h contains the Map class that represents a mapping between keys and values.
We felt that there were a few very key functions that are necessary for a map.
These are: add, get, and pop-item functions. The reset of the functions are
reasonable methods to expect from a Map class. add, get, and pop-item (AKA remove),
are necessary for the functionality of a Map.

#### Map file method overview:
It contains the following methods:
1. The method size() which determines the number of key-value pairs in the map.
2. This was a helpful method to have in our tests to check the functionality of our other methods.
3. The method add() which allows one to put new key-value pair within the map.
4. The method get() which given a key, returns the associated value.
5. The method clear() removes all key-value pairs from within the map.
6. This method is very useful in the case that the map needs to be emptied.
7. The method copy() returns a deep copy of the map.
8. The method keys() returns all keys within the map.
9. The method values() returns all values stored within the map.
10. The method pop() removes the last key-value pair and returns the value from the map.
11. The method pop_item() which removes the key-value pair of the given key and returns the value.
