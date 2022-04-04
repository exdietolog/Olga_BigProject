template <class MyType>
void MySwap(MyType& v1, MyType& v2) {
	MyType v3 = v1;
	v1 = v2;
	v2 = v3;
}

template <class ArrayType, class LessFunctionType>
int FindMinimumIndex(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) {
	int minimumIndex = beginIndex;
	for (int element_number = beginIndex + 1; element_number <= endIndex; ++element_number) {
		if (LessFunction(data_array[element_number], data_array[minimumIndex])) {
			minimumIndex = element_number;
		}
	}
	return minimumIndex;
}

template <class ArrayType, class LessFunctionType>
void SeletionSort(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) {
	for (int element_number = beginIndex; element_number < endIndex; ++element_number) {
		int minimumIndex = FindMinimumIndex(data_array, element_number, endIndex, LessFunction);
		MySwap(data_array[minimumIndex], data_array[element_number]);
	}
}