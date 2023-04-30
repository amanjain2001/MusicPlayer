#include<iostream>
#include<limits>

int takeUserInput(){
    int userInput;
    while(true){
        std::cin>>userInput;

        if(std::cin.fail()){
            std::cout<<"Error: Invalid input. Please enter an integer value."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if(std::cin.peek() != '\n'){
            std::cout<<"Error: Invalid input. Please enter an integer value."<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    return userInput;
}