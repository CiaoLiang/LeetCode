// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
/tData* data;
public:
/tIterator(const vector<int>& nums);
/tIterator(const Iterator& iter);
/tvirtual ~Iterator();
/t// Returns the next element in the iteration.
/tint next();
/t// Returns true if the iteration has more elements.
/tbool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
/tPeekingIterator(const vector<int>& nums) : Iterator(nums) {
/t    // Initialize any member here.
/t    // **DO NOT** save a copy of nums and manipulate it directly.
/t    // You should only use the Iterator interface methods.
/t    
/t}

    // Returns the next element in the iteration without advancing the iterator.
/tint peek() {
        return Iterator(*this).next();
/t}

/t// hasNext() and next() should behave the same as in the Iterator interface.
/t// Override them if needed.
/tint next() {
/t   return  Iterator::next();
/t}

/tbool hasNext() const {
/t    return Iterator::hasNext();
/t}
};