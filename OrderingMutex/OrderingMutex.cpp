#include <iostream>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::thread;

std::mutex mtx;
int cpt = 0;

void evenNumbers(char id) {
    //for (int i = 0; i <= 1000; i += 2) {
    //    std::lock_guard<std::mutex> lock(mtx);
    //    cout << id << ": " << i << endl;
    //}
    ////cout << endl;
    while (cpt <= 1000)
    {
        if (cpt % 2 == 0)
        {
            std::lock_guard<std::mutex> lock(mtx);
            cout << id << ": " << cpt << endl;
            cpt++;
        }
    }
}

void oddNumbers(char id) {
    /*for (int i = 1; i <= 1000; i += 2) {
        std::lock_guard<std::mutex> lock(mtx);
        cout << id << ": " << i << endl;
    }
    //cout << endl;
    */
    while (cpt <= 1000)
    {
        if (cpt % 2 == 1)
        {
            std::lock_guard<std::mutex> lock(mtx);
            cout << id << ": " << cpt << endl;
            cpt++;
        }
    }
}

int main() {
    thread thread1(evenNumbers, 'a');
    thread thread2(oddNumbers, 'b');

    thread1.join();
    thread2.join();

    return 0;
}
