# MathEquation

## How to run:

1. Clone this repository 
2. Go to the directory that you want this program in and type "git clone " followed by the "HTTPS" link you can find from the "Code" button
3. Enter the "MathEquation" folder using ```cd MathEquation```
4. Compile using this command: ```g++ -o Solver LinkedLists.cpp StacksQueues.cpp main.cpp```
5. In terminal, type: ```./Solver.exe```
6. click space to simulate every step the robot takes in the virtual map!
### Alternatively:
1. Download the files of this repository by zipping it, and then open that folder through file explorer
2. If you are on a linux based shell: ```g++ -o Solver LinkedLists.cpp StacksQueues.cpp main.cpp``` should compile and ```./Solver``` should run it
3. If you are on windows: ```gcc LinkedLists.cpp StacksQueues.cpp main.cpp -o Solver.exe``` should compile and ```Solver.exe``` should run it

## How it works

* This program uses Stacks and Queues to implement Reverse Polish Notation to solve any math equation dealing with +, -. *, /, and parenthesis
* First, it stores numbers in a queue and operators in a stack, to convert infix to postfix notation
* Then that postfix notation is used to formulate a final answer
* Here is an example of how the algorithm arrives to the answer:
![image](https://user-images.githubusercontent.com/42700917/161365655-3d190783-8bf6-4e79-a3c9-f4ddf741a1c1.png)

![image](https://user-images.githubusercontent.com/42700917/161365684-b93b8adf-d051-4021-846c-88d71687eb48.png)
