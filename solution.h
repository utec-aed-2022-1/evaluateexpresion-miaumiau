/*
#include <iostream>



using namespace std;

struct Result{
    double result;
    bool error;
}


Result evaluate(string input)
{
    // 1- descomponer el input y validar

    // 2- convertir de Infijo a Postfijo
    
    // 3- resolver la expresion

    //* Si no cumple la validacion retornar Result.error = true;

    return Result();
}
*/

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