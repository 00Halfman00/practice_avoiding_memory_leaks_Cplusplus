#include <iostream>

using namespace std;

int *create_arr(size_t size);
int *apply_all(int arr1[], size_t size1, int arr2[], size_t size2);
void display_arr(const int *const arr_ptr, size_t size);

int main(){
  size_t size1{}, size2{};
  cout << "Enter two numbers representing the size/s of two arrays seperated by a space  ";
  cin >> size1 >> size2;
  int *arr1 = create_arr(size1);    // must erase this pointer to memory in the heap or it will create a memory leak
  int *arr2 = create_arr(size2);    // must erase this pointer to memory in the heap or it will create a memory leak 
  //so arr1/2/3 is a pointer to the dynmically created array which lies in heap memory
  cout << "The product of the elements in both arrays is: "; 
  int *arr3 = apply_all(arr1, size1, arr2, size2);  // must erase this pointer to memory in the heap or it will create a memory leak
  delete [] arr1;
  delete [] arr2;
  delete [] arr3;
  return 0;
}

int *create_arr(size_t size){
  int *tmp {nullptr};
  tmp = new int[size];
  for(size_t i {}; i < size; ++i){
    int num {};
    cout << "enter a number to place in the array  ";
    cin >> num;
    tmp[i] = num;
  }
  display_arr(tmp, size);
  return tmp;
}

void display_arr(const int *const arr_ptr, size_t size){
  cout << "[ ";
  for(size_t i {}; i < size; ++i){
    cout << arr_ptr[i] << " ";
  }
  cout << "] and the size is " << size << "." << endl;
}

int *apply_all(int arr1[], size_t size1, int arr2[], size_t size2){
  size_t size3 {size1 * size2};
  int *results {nullptr}, count {};
  results = new int[size3];
  for(size_t i {}; i < size1; ++i){
    for(size_t j {}; j < size2; ++j){
      results[count] = arr1[i] * arr2[j];
      ++count; 
    }
  }
  display_arr(results, size3);
  return results;
}





