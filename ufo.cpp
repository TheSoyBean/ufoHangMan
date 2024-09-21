#include <iostream>
#include "ufo_functions.hpp"

int main() {
  greet();
  std::string codeword = "codecademy";
  std::string answer = "__________";
  int misses = 0;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;
  while(answer != codeword && misses < 7){
    display_misses(misses);
    display_status(incorrect, answer);
    std::cout << "\nPlease enter your guess: ";
    std::cin >> letter;
    for(int i = 0; i < codeword.length(); i++){
      if(letter == codeword[i]){
        answer[i] = letter;
        guess = true;
      }
    }
    if(guess){
      std::cout << "Correct!";
    }
    else{
      std::cout << "Incorrect! The tractor beam pulls the person in further.";
      incorrect.push_back(letter);
      misses++;
    }
    end_game(answer, codeword);
    guess = false;
  }
}
