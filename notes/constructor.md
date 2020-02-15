# Comma in Constructor

对于赋值引用与常量非常重要！

It's an **initialisation list**. You can use it for two things:

* Calling base class constructors
* Initialising member variables before the body of the constructor executes.

## Case 1:

For case #1, I assume you understand inheritance 
(if that's not the case, let me know in the comments). 
So you are simply calling the constructor of your base class.

## Case 2:

For case #2, the question may be asked: "Why not just initialise it in the body of the constructor?" 
The importance of the initialisation lists is particularly evident for const members. 
For instance, take a look at this situation, where I want to initialise m_val based on the constructor parameter:


    class Demo
    {
        Demo(int& val) 
         {
             m_val = val;
         }
    private:
        const int& m_val;
    };

By the C++ specification, this is illegal. 
We cannot change the value of a const variable in the constructor, because it is marked as const. 
So you can use the initialisation list:

    class Demo
    {
        Demo(int& val) : m_val(val)
         {
         }
    private:
        const int& m_val;
    };
    
That is the only time that you can change a **const member variable**. 
And it is also the only way to initialise a **reference** that is a class member.

Outside of using it to initialise const member variables, it seems to have been generally accepted as "the way" of initialising variables, so it's clear to other programmers reading your code.    
