#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
float* read_data(const char* filename, int* num_elements, int* capacity);
float mean(const float* data, int num_elements);
float median(float* data, int num_elements);
float standard_deviation(const float* data, int num_elements, float mean_value);
float mode(float* data, int num_elements);
float geometric_mean(const float* data, int num_elements);
float harmonic_mean(const float* data, int num_elements);
void merge(float* data, int left, int mid, int right);
void merge_sort(float* data, int left, int right);


// Main Function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    int num_elements = 0, capacity = 0;
    float* data = read_data(argv[1], &num_elements, &capacity);

    if (data == NULL) {
        printf("Error reading input file.\n");
        return 1;
    }

    float mean_value = mean(data, num_elements);
    float median_value = median(data, num_elements);
    float stddev_value = standard_deviation(data, num_elements, mean_value);
    float mode_value = mode(data, num_elements);
    float geo_mean_value = geometric_mean(data, num_elements);
    float harm_mean_value = harmonic_mean(data, num_elements);

    printf("Number of elements: %d\n", num_elements);
    printf("Array capacity: %d\n", capacity);
    printf("Mean: %f\n", mean_value);
    printf("Median: %f\n", median_value);
    printf("Standard Deviation: %f\n", stddev_value);
    printf("Mode: %f\n", mode_value);
    printf("Geometric Mean: %f\n", geo_mean_value);
    printf("Harmonic Mean: %f\n", harm_mean_value);

    free(data);
    return 0;
}

// read data function
float* read_data(const char* filename, int* num_elements, int* capacity) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    *capacity = 20;
    float* data = (float*) malloc(*capacity * sizeof(float));
    float value;
    *num_elements = 0;

    // function to read data from file. Array size is modified here as well
    while (fscanf(file, "%f", &value) != EOF) {
        if (*num_elements == *capacity) {
            *capacity *= 2;
            float* new_data = (float*) malloc(*capacity * sizeof(float));
            memcpy(new_data, data, *num_elements * sizeof(float));
            free(data);
            data = new_data;
        }
        data[*num_elements] = value;
        (*num_elements)++;
    }

    fclose(file);
    return data;
}

// Mean SA function
float mean(const float* data, int num_elements) {
    double sum = 0;
    for (int i = 0; i < num_elements; i++) {
        sum += data[i];
    }
    return sum / num_elements;
}

float geometric_mean(const float* data, int num_elements) {
    double product = 1;
    for (int i = 0; i < num_elements; i++) {
        product *= data[i];
    }
    return pow(product, 1.0 / num_elements);
}

float harmonic_mean(const float* data, int num_elements) {
    double reciprocal_sum = 0;
    for (int i = 0; i < num_elements; i++) {
        reciprocal_sum += 1.0 / data[i];
    }
    return num_elements / reciprocal_sum;
}

float median(float* data, int num_elements) {
    merge_sort(data, 0, num_elements - 1);

    if (num_elements % 2 == 0) {
        return (data[num_elements / 2] + data[num_elements / 2 - 1]) / 2;
    } else {
        return data[num_elements / 2];
    }
}

float standard_deviation(const float* data, int num_elements, float mean_value) {
    double sum = 0;
    for (int i = 0; i < num_elements; i++) {
        double diff = data[i] - mean_value;
        sum += diff * diff;
    }
    return sqrt(sum / num_elements);
}

float mode(float* data, int num_elements) {
    merge_sort(data, 0, num_elements - 1);

    int max_count = 1, mode_count = 1;
    float mode_value = data[0];
    float current_value = data[0];

    for (int i = 1; i < num_elements; i++) {
        if (data[i] == current_value) {
            mode_count++;
        } else {
            if (mode_count > max_count) {
                max_count = mode_count;
                mode_value = current_value;
            }
            mode_count = 1;
            current_value = data[i];
        }
    }

    return mode_value;
}



// Merge two sorted subarrays within the data array
// left: the starting index of the left subarray
// mid: the ending index of the left subarray and mid+1 is the starting index of the right subarray
// right: the ending index of the right subarray
void merge(float* data, int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    float* left_data = (float*) malloc(left_size * sizeof(float));
    float* right_data = (float*) malloc(right_size * sizeof(float));

    memcpy(left_data, &data[left], left_size * sizeof(float));
    memcpy(right_data, &data[mid + 1], right_size * sizeof(float));

    int i = 0, j = 0, k = left;
    while (i < left_size && j < right_size) {
        if (left_data[i] <= right_data[j]) {
            data[k++] = left_data[i++];
        } else {
            data[k++] = right_data[j++];
        }
    }

    while (i < left_size) {
        data[k++] = left_data[i++];
    }

    while (j < right_size) {
        data[k++] = right_data[j++];
    }

    free(left_data);
    free(right_data);
}

// Sort the data array using the merge sort algorithm
// left: the starting index of the array to be sorted
// right: the ending index of the array to be sorted
void merge_sort(float* data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(data, left, mid);
        merge_sort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

