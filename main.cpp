#include <iostream>
#include <vector>


using namespace std;

int getPlusCount(int number, int number_vec_size, int target) {
  for (int count = 0; count <= number_vec_size; count++) {
    int result = 0;
    result += count * number;
    result -= (number_vec_size - count) * number;
    if (target == result) {
      return count;
    }
  }
  return -1;
}

int factorial(int number) {
  int result = 1;
  for (int i = 1; i <= number; i++) {
    result *= i;
  }
  return result;
}

int solution(vector<int> number_vec, int target) {
  int answer = 0;

  int number_vec_size = number_vec.size();
  int number = number_vec[0];

  int plus_count = getPlusCount(number, number_vec_size, target);
  int minus_count = number_vec_size - plus_count;

  if (plus_count != -1) {
    answer = factorial(number_vec_size) / factorial(plus_count) / factorial(minus_count);
  }

  return answer;
}

int main() {
  cout << solution({2, 2, 2, 2, 2}, 2) << endl;
  return 0;
}