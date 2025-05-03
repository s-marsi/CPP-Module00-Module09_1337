#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T> Array<T>::Array(): _size(0) { elements = new T(); }

template<typename T> Array<T>::Array(unsigned int n) : _size(n) { elements = new T[n](); }

template<typename T> Array<T>::Array(Array &rhs)
{
    elements = NULL;
    *this = rhs;
}

template<typename T> Array<T> &Array<T>::operator=(Array &rhs)
{
    if (this != &rhs) {
        if (elements)
            delete []elements;
        _size = rhs.size();
        elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            elements[i] = rhs.elements[i];
        }
    }
    return (*this);
}

template<typename T> unsigned int Array<T>::size() const{
    return (_size);
}

template<typename T> T &Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("index is out of bounds.");
    return (elements[index]);
}

template<typename T> T &Array<T>::operator[](unsigned int index) const{
    if (index >= _size)
        throw std::out_of_range("index is out of bounds.");
    return (elements[index]);
}

template<typename T> Array<T>::~Array() { delete []elements; }


#endif
