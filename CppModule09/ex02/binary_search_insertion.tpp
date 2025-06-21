#ifndef BINARY_SEARCH__INSERTION_TPP
#define BINARY_SEARCH__INSERTION_TPP

template <typename T>
void    binary_search(T&arr, int target, int start, int end)
{
    if (start > end) {
        std::cout << "Not Found" << std::endl;
        return ;
    }
    int middle = (start + end) / 2;
    if (arr[middle] == target) {
        std::cout << "Found at index[" << middle << "]" << std::endl;
        return ;
    }
    if (target < arr[middle]) {
        binary_search(arr, target, start, middle - 1);
    }
    else {
        binary_search(arr, target, middle + 1, end);
    }
}

template <typename T>
void binary_search_insert(T& arr, int target, int start, int end) {
    if (start > end) {
        arr.insert(arr.begin() + start, target);
        return;
    }

    int middle = (start + end) / 2;

    if (target < arr[middle]) {
        binary_search_insert(arr, target, start, middle - 1);
    } else {
        binary_search_insert(arr, target, middle + 1, end);
    }
}



#endif