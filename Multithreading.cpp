// Multithreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void anyFunction1()
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID thread - " << this_thread::get_id() << "\tanyFunction1\t" << i << endl;;
        this_thread::sleep_for(chrono::milliseconds(3000));
    }
    
}

void anyFunction2()
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID thread - " << this_thread::get_id() << "\tanyFunction2\t" << i << endl;;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

}
int main()
{
    thread thread_object1(anyFunction1);

        /*The class thread represents a single thread of execution.Threads allow multiple functions to execute concurrently.

        Threads begin execution immediately upon construction of the associated thread object (pending any OS scheduling delays),
        starting at the top - level function provided as a constructor argument.The return value of the top - level function 
        is ignored and if it terminates by throwing an exception, std::terminate is called.The top - level function may communicate 
        its return value or an exception to the caller via std::promise or by modifying shared variables(which may require synchronization, 
        see std::mutex and std::atomic)

        std::thread objects may also be in the state that does not represent any thread(after default construction, move from, detach, or join), 
        and a thread of execution may be not associated with any thread objects(after detach).

        No two std::thread objects may represent the same thread of execution; std::thread is not CopyConstructible or CopyAssignable, 
        although it is MoveConstructibleand MoveAssignable.*/

    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID thread - " << this_thread::get_id() << "\tmain\t" << i << endl;;
        this_thread::sleep_for(chrono::milliseconds(3000));
    }

    thread_object1.join(); //waits for a thread to finish its execution
    
    //thread_object.detach(); //permits the thread to execute independently from the thread handle
    
    
   /* thread thread_object2(anyFunction2);
    thread_object1.swap(thread_object2);
    thread_object2.join();*/

    return 0;
}


