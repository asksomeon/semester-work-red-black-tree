#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <utility>

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<memory.h>


// Заголовочный файл с объявлением структуры данных

namespace itis {
  /*
  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct MyStructure {
   public:
    int size_{0};
    int capacity_{0};
    int* data_{nullptr};

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };
     */


  class RBtree{
    struct node_st{node_st *p1,*p2; int value; bool red;}; // структура узла
    node_st *tree_root{};                 //!< корень
    int nodes_count{};                    //!< число узлов дерева
   private:
    node_st *NewNode(int value);        //!< выделение новой вешины
    void DelNode(node_st*);             //!< удаление вершины
    void Clear(node_st*);               //!< снос дерева (рекурсивная часть)
    node_st *Rotate21(node_st*);        //!< вращение влево
    node_st *Rotate12(node_st*);        //!< вращение вправо
    void BalanceInsert(node_st**);      //!< балансировка вставки
    bool BalanceRemove1(node_st**);     //!< левая балансировка удаления
    bool BalanceRemove2(node_st**);     //!< правая балансировка удаления
    bool Insert(int,node_st**);         //!< рекурсивная часть вставки
    bool GetMin(node_st**,node_st**);   //!< найти и убрать максимальный узел поддерева
    bool Remove(node_st**,int);         //!< рекурсивная часть удаления
   public: // отладочная часть
    enum check_code{error_balance,error_struct,ok}; // код ошибки
    void Show();                        //!< вывод дерева
    check_code Check();                 //!< проверка дерева
    bool TreeWalk(bool*,int);           //!< обход дерева и сверка значений с массивом
    RBtree(int i);

    void Show(node_st*,int,char);
   private: // отладочная часть
    //!< вывод дерева, рекурсивная часть
    check_code Check(node_st*,int,int&);//!< проверка дерева (рекурсивная часть)
    bool TreeWalk(node_st*,bool*,int);  //!< обход дерева и сверка значений с массивом (рекурсивная часть)
   public:
    RBtree();
    ~RBtree();
    void Clear();           //!< снести дерево
    bool Find(int);         //!< найти значение
    void Insert(int);       //!< вставить значение
    void Remove(int);       //!< удалить значение
    int GetNodesCount();    //!< узнать число узлов
  };
  inline RBtree::RBtree()
  {
    tree_root=0;
    nodes_count=0;
  }

  inline RBtree::~RBtree()
  {
    Clear(tree_root);
  }


}  // namespace itis