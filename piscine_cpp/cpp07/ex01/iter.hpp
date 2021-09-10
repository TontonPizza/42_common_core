

template <typename T>
void 	iter(T *array, size_t size, void(*f)(const T &))
{
	size_t i = 0;
	while (i < size)
	{
		f(array[i]);
		i++;
	}
}