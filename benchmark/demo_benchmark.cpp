#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds


#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main() {
  /* Так-то тестовые данные уже сгенерированы, но если нужны новые, то переходим в dataset, удаляем три папочки:
   * insert, remove и search. Переходим в  generate_csv_dataset.py, нажимаем на зеленую стрелочку. Оп, появились.
   * Если не нужны, то смотрим ниже.
   */
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  int trials = 1;
  string files[1] = {"01"};
  RBtree rBtree;
  for(string elem : files) {
    for (int i = 0; i < trials; i++) {
      string line = "1";
      //Вставляете путь к файлу, из которого хотите брать данные
      // Пример
      auto input_file = ifstream(path + "/insert/data(5000000).txt");


      if (input_file) {
        while (line != "") {

          getline(input_file, line);
          if (line == "") {
            break;
          }
          rBtree.Insert(stoi(line));
        }
      }
      const auto time_point_before = chrono::steady_clock::now();
      // Это для операции, время которой замеряется(Insert, Remove или Find), и элемент, с которым её проворачиваете
      // Пример:
      rBtree.Insert(145678);
      const auto time_point_after = chrono::steady_clock::now();
      input_file.close();
      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
      cout << time_elapsed_ns << endl;
    }
  }
  return 0;
}