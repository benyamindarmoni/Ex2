/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using namespace std;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
 .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
   .CHECK_OK    (emptytree.insert(50)) 
   .CHECK_OK    (emptytree.insert(5)) 
   .CHECK_OK    (emptytree.insert(60)) 
   .CHECK_OK    (emptytree.remove(50))
   .CHECK_EQUAL (emptytree.size() ,2)
    .CHECK_EQUAL (emptytree.root() ,5)
    .CHECK_EQUAL (emptytree.right(5) ,60)
   .CHECK_OK    (emptytree.insert(61)) 
    .CHECK_OK    (emptytree.insert(62)) 
         .CHECK_OK    (emptytree.remove(5))
         .CHECK_THROWS(emptytree.remove(5))
          .CHECK_EQUAL(emptytree.root(),60)
           .CHECK_THROWS(emptytree.left(60))
            .CHECK_THROWS(emptytree.right(62))
           .CHECK_THROWS(emptytree.parent(60))
            .CHECK_OK    (emptytree.insert(2)) 
              .CHECK_EQUAL (emptytree.size() ,4)
               .CHECK_OK    (emptytree.remove(60))
                .CHECK_EQUAL (emptytree.root() ,2)
                .CHECK_EQUAL (emptytree.right(2) ,61)
                  .CHECK_EQUAL (emptytree.size() ,3)
                  .CHECK_THROWS(emptytree.insert(62))
                  .CHECK_THROWS(emptytree.remove(1))
                  .CHECK_EQUAL (emptytree.contains(2),1)
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 20)
  .CHECK_EQUAL (threetree.parent(10), 20)

  
  .CHECK_THROWS(threetree.insert(10))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK(threetree.insert(6))
     .CHECK_OK(threetree.insert(8))

    .CHECK_EQUAL (threetree.size(), 5)
    .CHECK_EQUAL (threetree.left(10), 6)
     .CHECK_OK(threetree.remove(10))
        .CHECK_EQUAL (threetree.size(), 4)
 .CHECK_EQUAL (threetree.left(20), 6)
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK(threetree.insert(5))
  .CHECK_OK(threetree.insert(21))
  .CHECK_OK(threetree.insert(50))
  .CHECK_OK(threetree.insert(1))
  .CHECK_OK(threetree.insert(7))
   .CHECK_OK    (threetree.remove(20))
    .CHECK_EQUAL (threetree.right(6), 7)
     .CHECK_EQUAL (threetree.root(), 8)
      .CHECK_EQUAL (threetree.right(8),30 )
       .CHECK_EQUAL (threetree.size(), 8)
        .CHECK_THROWS(threetree.left(11))
         .CHECK_THROWS(threetree.left(1))
          .CHECK_OK    (threetree.remove(6))
          .CHECK_EQUAL (threetree.left(5), 1)
             .CHECK_EQUAL (threetree.size(), 7)
              .CHECK_OK(threetree.insert(2))
               .CHECK_OK(threetree.insert(3))
                .CHECK_OK(threetree.insert(4))
                 .CHECK_OK    (threetree.remove(5))
                  .CHECK_OK    (threetree.remove(4))
                  .CHECK_OK(threetree.insert(6))
                     .CHECK_OK    (threetree.remove(8))
                     .CHECK_OK(threetree.insert(51))
                     .CHECK_OK(threetree.insert(53))
                      .CHECK_OK    (threetree.remove(50))
                        .CHECK_OK    (threetree.remove(3))
                        .CHECK_OK    (threetree.remove(2))
                        .CHECK_OK    (threetree.remove(1))
                        .CHECK_OK    (threetree.remove(6))
                        .CHECK_OK    (threetree.remove(7))
                  .CHECK_OK(threetree.insert(29))
                  .CHECK_OK    (threetree.remove(53))
                        .CHECK_OK    (threetree.remove(51))

                            .CHECK_OK    (threetree.remove(21)) 
         .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
