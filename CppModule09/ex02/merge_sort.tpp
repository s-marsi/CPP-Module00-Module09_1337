#ifndef MERGE_SORT_TPP
#define MERGE_SORT_TPP

template <typename T>
bool array_is_sorted(T &arr_to_sort) {
    if (arr_to_sort.size() <= 1)
     return (true);
    bool is_sorted = false;
    for (size_t i = 0; i < arr_to_sort.size() - 1; i++) {
        if (arr_to_sort[i] > arr_to_sort[i+1])
        {
            is_sorted = 1;
            break;
        }
    }
    if (!is_sorted)
        return (true);
    return (false);
}

template <typename T>
void merge(T &arr_to_sort, int left, int mid, int right) {
    int len_left, len_right, k = left;
    len_left = mid - left + 1;
    len_right = right - mid;
    T left_tmp(len_left);
    T right_tmp(len_right);

    for (int i = 0; i < len_left; i++)
        left_tmp[i] = arr_to_sort[left + i];
    for (int j = 0; j < len_right; j++)
        right_tmp[j] = arr_to_sort[mid + 1 + j];

    int i = 0, j = 0;
    while (i < len_left && j < len_right) {
        if (left_tmp[i] <= right_tmp[j]) {
            arr_to_sort[k] = left_tmp[i];
            i++;
        }
        else {
            arr_to_sort[k] = right_tmp[j];
            j++;
        }
        k++;
    }

    while (i < len_left) {
        arr_to_sort[k] = left_tmp[i];
        i++;
        k++;
    }

    while (j < len_right) {
        arr_to_sort[k] = right_tmp[j];
        j++;
        k++;
    }
}


template <typename T>
void merge_sort(T &arr_to_sort, int left, int right) {
    if (left >= right) 
        return;
    int middle = (left + right) / 2;
    merge_sort(arr_to_sort, left, middle);   
    merge_sort(arr_to_sort, middle + 1, right);
    merge(arr_to_sort, left, middle, right);
}

#endif