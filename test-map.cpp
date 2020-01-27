#include "object.h"
#include "string.h"
#include "map.h"
#include "pair.h"

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
  t_true(map->get(one)->equals(s1));
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

void test_pop_item() {
  Map* map = new Map();
  map->add(one, s1);
  map->add(two, s2);
  t_true(map->pop_item(one)->equals(s1));
  t_true(map->pop_item(two)->equals(s2));
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
}

void test_pair() {
  Pair* p = new Pair(one, two);
  t_true(p->o1->equals(one));
  t_true(p->o2->equals(two));

  p->o1 = two;
  t_false(p->o1->equals(one));
  t_true(p->o1->equals(two));
  t_true(p->o2->equals(two));
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
  test_pop();
  test_pop_item();
  test_hash_and_equals();
  test_pair();
  return 0;
}
