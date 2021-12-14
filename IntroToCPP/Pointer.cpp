#include <iostream>

template <class T>
class DynamicArray
{
private:
	size_t m_size = 0;
	T* m_array = nullptr;
public:
	DynamicArray(size_t size)
		: m_size(size),
	      m_array(new T[size])
	{

	}
	~DynamicArray() {
		delete []  m_array;
	}

	T get(size_t index) {
		return m_array[index];
	}
	void set(size_t index, T value)
	{
		m_array[index] = value;
	}
	void print()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			std::cout << i << ": " << m_array[i] << "\n";
		}
	}

	T& operator [](size_t index)
	{
		return m_array[index];
	}
};


int main()
{
	DynamicArray<int> array(10);
	array.set(0,10);
	array.set(1,50);
	array[9] = 55;
	array.print();
	

	std::cout << array[1];
	
}