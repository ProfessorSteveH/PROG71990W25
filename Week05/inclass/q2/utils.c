// steveh - week05 - prog71990w25

// impl for various utilities


int get_max_of_3_ints(int a, int b, int c) {
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;

	return max;
}


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
