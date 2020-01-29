#include "object.h"
#include "string.h"
#include "map.h"
#include <stdlib.h>

void FAIL() {   exit(1);    }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

String* one = new String("1");
String* two = new String("2");
String* not_one = new String("1");
String* s1 = new String("Hello");
String* s2 = new String("World");

/**
* Does this array of object points have the object we are looking for?
* @param ol the array of pointers
* @param o the object to search for.
*/
bool in(Object** ol, Object* o, size_t len) {
  bool is_in = false;
  int i = 0;
  while (i != len) {
      is_in = ol[i]->equals(o) || is_in;
      i++;
  }

  return is_in;
}

void test_add() {
  Map* map = new Map();
  t_true(map->size() == 0);
  map->add(one, s1);
  t_true(map->size() == 1);
  t_true(map->get(one)->equals(s1));

  // the previous key value pair is overwritten
  map->add(one, s2);
  t_true(map->get(one)->equals(s2));
  t_true(map->size() == 1);

  // add/get overwrites with different objects
  map->add(not_one, s1);
  t_true(map->get(one)->equals(s1));
  t_true(map->size() == 1);

  std::cout << "done add\n";

  delete map;
}

void test_clear() {
  Map* map = new Map();
  t_true(map->size() == 0);
  map->clear();
  t_true(map->size() == 0);
  map->add(one, s1);
  map->add(two, s2);
  t_true(map->size() == 2);
  map->clear();
  t_true(map->size() == 0);

  std::cout << "done clear\n";

  delete map;
}

void test_copy() {
  Map* map = new Map();
  map->add(one, s1);
  map->add(two, s2);
  t_true(map->size() == 2);
  Map* map2 = map->copy();
  t_true(map2->size() == 2);
  t_true(map2->get(one)->equals(s1));
  t_true(map2->get(two)->equals(s2));
  String* s3 = new String("Hi");
  map->add(one, s3);
  t_false(map2->get(one)->equals(s3));

  std::cout << "done copy\n";

  delete map;
  delete map2;
}

void test_keys() {
  Map* map = new Map();
  map->add(one, s1);
  map->add(two, s2);
  t_true(in(map->keys(), one, 2));
  t_true(in(map->keys(), two, 2));
  t_false(in(map->keys(), s1, 2));
  t_false(in(map->keys(), s2, 2));

  // show deleting from map-> doesn't do anything.
  Object** tmp = map->keys();
  tmp[0] = s1;
  t_true(in(map->keys(), one, 2));
  t_true(in(map->keys(), two, 2));
  t_false(in(map->keys(), s1, 2));
  t_false(in(map->keys(), s2, 2));

  std::cout << "done keys\n";

  delete tmp;
  delete map;
}

void test_values() {
  Map* map = new Map();
  map->add(one, s1);
  map->add(two, s2);
  t_true(in(map->values(), s1, 2));
  t_true(in(map->values(), s2, 2));
  t_false(in(map->values(), one, 2));
  t_false(in(map->values(), two, 2));

  // show deleting from map->values doesn't do anything.
  Object** tmp = map->values();
  tmp[0] = one;
  t_true(in(map->values(), s1, 2));
  t_true(in(map->values(), s2, 2));
  t_false(in(map->values(), one, 2));
  t_false(in(map->values(), two, 2));

  std::cout << "done values\n";

  delete tmp;
  delete map;
}

void test_pop_item() {
  Map* map = new Map();
  map->add(one, s1);
  map->add(two, s2);
  t_true(map->pop_item(one)->equals(s1));
  t_true(map->pop_item(two)->equals(s2));

  std::cout << "done pop item\n";

  delete map;
}

void test_hash_and_equals() {
  Map* map1 = new Map();
  Map* map2 = new Map();

  t_true(map1->equals(map2));
  t_true(map2->equals(map1));
  t_true(map1->hash() == map2->hash());

  map1->add(one, s1);
  map1->add(two, s2);

  t_false(map1->equals(map2));
  t_false(map2->equals(map1));
  t_false(map1->hash() == map2->hash());

  map2->add(one, s1);
  map2->add(two, s2);

  t_true(map1->equals(map2));
  t_true(map2->equals(map1));
  t_true(map1->hash() == map2->hash());

  std::cout << "done hash and equals\n";

  delete map1;
  delete map2;
}

void test_map_delete() {
  Map * m = new Map();
  m->add(one, s1);
  delete m;

  t_true(one->equals(one));
  t_true(s1->equals(s1));
}

int main() {
  test_add();
  test_clear();
  test_copy();
  test_keys();
  test_values();
  test_pop_item();
  test_hash_and_equals();
  return 0;
}
