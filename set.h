/*
 * Itay Volk <ivolk@scu.edu>,
 * David Chousal Cantu <dchousal@scu.edu>,
 * Ding-Shiuan Yang <dyang2@scu.edu>,
 * Rushil Kumar <rkumar3@scu.edu>,
 * Alexander Anokhin <aanokhin@scu.edu>
 * recipe for containers using pointers
 */
#ifndef SET_H
#define SET_H
namespace csen79 {

class Set {
public:
    using Data = int;   // create an alias for the data
    Set(): data{0}, count{0} {}

    // rule of 5
    ~Set() = default;
    Set(const Set &);
    Set(Set &&);
    Set &operator=(const Set &);
    Set &operator=(Set &&rhs);

    // access functions
    void insert(const Data &);
    Data deQ();
    void print() const;

private:
    // data storage
    int count;
    size_t DATASIZE;    // array size
    Data* data;
};

}
#endif // SET_H