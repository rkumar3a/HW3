/*
 * Itay Volk <ivolk@scu.edu>,
 * David Chousal Cantu <dchousal@scu.edu>,
 * Ding-Shiuan Yang <dyang2@scu.edu>,
 * Rushil Kumar <rkumar3@scu.edu>,
 * Alexander Anokhin <aanokhin@scu.edu>
 * recipe for containers using pointers
 */
#ifndef STACK_H
#define STACK_H
namespace csen79 {

class Stack {
    static constexpr size_t DATASIZE = 1000;    // array size
public:
    using Data = int;   // create an alias for the data
    Stack(): data{0}, first{0}, count{0} {}

    // rule of 5
    ~Stack() = default;
    Stack(const Stack &);
    Stack(Stack &&);
    Stack &operator=(const Stack &);
    Stack &operator=(Stack &&rhs);

    // access functions
    void enQ(const Data &);
    Data deQ();
    void print() const;

private:
    // data storage
    int first;
    int count;
    Data data[DATASIZE];
};

}
#endif // STACK_H