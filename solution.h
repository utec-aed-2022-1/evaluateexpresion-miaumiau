#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <string>
#include "forward.h"
#include "stack.h"

using namespace std;

struct Result{
    double result;
    bool error;
};

Result solvePostfixOperation(ForwardList<string>* &container_postfix){
    StackList<double>* stack_operation = new StackList<double>();
    int container_postfix_size = container_postfix->size();
    for(int i=0; i<container_postfix_size; ++i){
        string back_element = container_postfix->back();
        if (back_element=="+" || back_element=="-" || back_element=="*" || back_element=="/"){
            if (stack_operation->empty()){
                //Error checking
                Result obj_result;
                obj_result.result = 0;
                obj_result.error = true;
                return obj_result;
            }
            double firstBackNumber= stack_operation->top();
            stack_operation->pop();
            if (stack_operation->empty()){
                //Error checking
                Result obj_result;
                obj_result.result = 0;
                obj_result.error = true;
                return obj_result;
            }
            double secondBackNumber= stack_operation->top();
            stack_operation->pop();
            double result;
            if (back_element=="+"){
                result = secondBackNumber+firstBackNumber;
            }
            else if (back_element=="-"){
                result = secondBackNumber-firstBackNumber;
            }
            else if (back_element=="*"){
                result = secondBackNumber*firstBackNumber;
            }
            else if (back_element=="/"){
                result = secondBackNumber/firstBackNumber;
            }
            stack_operation->push(result);
            container_postfix->pop_back();
        }
        else{
            double backNumber= stoi(back_element);
            container_postfix->pop_back();
            stack_operation->push(backNumber);
        }
    }
    Result obj_result;
    obj_result.result = stack_operation->top();
    obj_result.error = false;
    return obj_result;
}

Result evaluate(string input)
{
    StackList<char>* stack_symbols = new StackList<char>();
    ForwardList<string>* container_postfix = new ForwardList<string>();
    bool is_it_a_consecutive_number = false;
    int counter = 0;
    bool am_i_after_a_closing_parenthesis = false;
    while(counter<input.length()){
        char element = input[counter];
        if (element=='(' || element==')'){
            if (element=='('){
                stack_symbols->push(element);
            }
            else if (element==')'){
                bool has_not_been_finded_op_parenthesis = true;
                while (has_not_been_finded_op_parenthesis){
                    char top_element = stack_symbols->top();
                    if (top_element == '('){
                       has_not_been_finded_op_parenthesis = false;
                    }
                    else if (top_element == ')'){
                        //Error checking
                        Result obj_result;
                        obj_result.result = 0;
                        obj_result.error = true;
                        return obj_result;
                    }
                    else{
                        string s_top_element(1, top_element);
                        container_postfix->push_front(s_top_element);
                    }
                    stack_symbols->pop();
                }
                am_i_after_a_closing_parenthesis = true;
            }
            ++counter;
        }
        else if (element=='+' || element=='-' || element=='*' || element=='/'){
            if (stack_symbols->empty()){;}
            else if (element=='+' || element=='-'){
                bool exist_operator_of_greater_or_equal_precedence = true;
                while (exist_operator_of_greater_or_equal_precedence && !stack_symbols->empty()){
                    char top_element = stack_symbols->top();
                    if (top_element=='+' || top_element=='-' || top_element=='*' || top_element=='/'){
                        string s_top_element(1, top_element);
                        container_postfix->push_front(s_top_element);
                        stack_symbols->pop();
                    }
                    else{
                        exist_operator_of_greater_or_equal_precedence=false;
                    }
                }
            }
            else if (element=='*' || element=='/'){
                bool exist_operator_of_greater_or_equal_precedence = true;
                while (exist_operator_of_greater_or_equal_precedence && !stack_symbols->empty()){
                    char top_element = stack_symbols->top();
                    if (top_element=='*' || top_element=='/'){
                        string s_top_element(1, top_element);
                        container_postfix->push_front(s_top_element);
                        stack_symbols->pop();
                    }
                    else{
                        exist_operator_of_greater_or_equal_precedence=false;
                    }
                }
            }
            stack_symbols->push(element);
            ++counter;
            if (am_i_after_a_closing_parenthesis){
                am_i_after_a_closing_parenthesis = false;
            }
        }
        else if (element==' '){++counter;}
        else{
            if (am_i_after_a_closing_parenthesis){
                //Error checking
                Result obj_result;
                obj_result.result = 0;
                obj_result.error = true;
                return obj_result;
            }
            string number;
            char searching_for_a_number = input[counter];
            while (48<=searching_for_a_number && searching_for_a_number<=57){
                string str_searching_for_a_number(1, searching_for_a_number);
                number.append(str_searching_for_a_number);
                ++counter;
                searching_for_a_number = input[counter];
            }
            container_postfix->push_front(number);
        }
    }
    while (!stack_symbols->empty()){
          char top_element = stack_symbols->top();
          if (top_element == '(' || top_element == ')'){
              //Error checking
              Result obj_result;
              obj_result.result = 0;
              obj_result.error = true;
              return obj_result;
          }
          stack_symbols->pop();
          string s_top_element(1, top_element);
          container_postfix->push_front(s_top_element);
    }
      
    return solvePostfixOperation(container_postfix);
}

/*
    containerPostfixToString(container_postfix){
        This function will go through each element of container_postfix and concatenate each element into a string
        reeturn containerPostfixString
    }


    transformToPostfix(string of operation to calculate){
        stack_symbols = stack which will store parentheses and operators
        container_postfix = container which will store the numbers of the operation and at the end the result
        for (each element of the used container){
            if (element == parenthesis)
                if (element == opening parenthesis)
                    push element to stack_simbols
                    back to pass through the loop
                else if (element == closing parenthesis)
                    go through the stack_symbols and do multiple pops. At the same time add those
                    poped elements to the container_postfix container until we found the opening parenthesis
                    associated to the closing parenthesis that we have in the element variable
                    if instead we find before that the first parenthesis isn't the corresponding to the 
                    opening parenthesis. We will throw a message that says 'check parentheses there is
                    a bad colocation of at least one of those' and finish execution of the program.
            if (element == operator)
                check if at the top of stack_symbols exist another operation whit equal or greater precedence
                order. If thats the case pop those operator and inmediatly add those poped elements to the
                container_postfix container until you don't find at the top one operator with an equal or greater 
                precedence
                then push the element in the stack_symbols container
            if (element == number)
                push the number into the container_postfix container
            Then we have to validate if the stack_symbols container is empty
            And finally we return the container posfix
            return container_postfix
        }
    }

    solvePostfixOperation(container_postfix){
        stack_operation = stack where we'll operate the numbers and operators of the operation
        for(each element of stack_operation container){
            if(element == number){
                push the number into stack_operation container
            }
            if(element == operator){
                pop two times the stack_operation container and immediatly use those 2 numbers poped
                to with the operator in the variable element calculate the operator. Follow the next syntax:
                secondNumberPoped (operator) firstNumberboped
                finally the value obtained of the operation will be pushed into the stack_operation container.
            }
        }
    }

*/

#endif