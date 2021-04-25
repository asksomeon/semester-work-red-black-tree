#include <iostream>

#include "data_structure.hpp"


using namespace std;
using namespace itis;


int main() {

  RBtree tree =  RBtree();
  tree.Insert(5);
  tree.Insert(1);
  tree.Insert(14);
  tree.Insert(9);
  tree.Insert(23);
  tree.Insert(25);
  tree.Insert(6);
  tree.Insert(3);
  tree.Insert(4);
  tree.Insert(2);
  tree.Show();


  return 0;
}