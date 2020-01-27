#include "object.h"
#include "string.h"
#include "map.h"

void FAIL() {   exit(1);    }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

String* one = new String("1");
String* two = new String("2");
String* not_one = new String("1");
String* s1 = new String("Hello");
String* s2 = new String("World");

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
  t_true(map->get(one)->equals(s));
  t_true(map->size() == 1);
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
}

void test_keys() {
  Map* map = new Map();
  map->add(one, s1);
  map->add(two, s2);
  t_true(map->keys()[0]->equals(one));
  t_true(map->keys()[1]->equals(two));
}

void test_values() {
  Map* map = new Map();
  map->add(one, s1);
  map->add(two, s2);
  t_true(map->values()[0]->equals(s1));
  t_true(map->values()[1]->equals(s2));
}

void test_pop() {
  Map* map = new Map();
  map->add(one, s1);
  map->add(two, s2);
  t_true(map->pop()->equals(s2));
  t_true(map->pop()->equals(s1));
}

void test_pop_item() {
  Map* map = new Map();
  map->add(one, s1);
  map->add(two, s2);
  t_true(map->pop_item(one)->equals(s1));
  t_true(map->pop_item(two)->equals(s2));
}

int main() {
  test_add();
  test_clear();
  test_copy();
  test_keys();
  test_values();
  test_pop();
  test_pop_item();
  return 0;
}
