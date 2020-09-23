#include "Deque.h"
const int default_size = 3;

Deque::Deque() {
	size = default_size;
	queue = new int[size]();
	count = 0;
}

Deque::Deque(int size) {
	this->size = size;
	queue = new int[size]();
	count = 0;
}

Deque::~Deque() {
	delete[] queue;
}

int Deque::PushFront(int _num) {
	if (count > size)
		return -1;

	queue[count++] = _num;
	return 0;
}

int Deque::PushBack(int _num) {
	if (count > size)
		return -1;
	for (int i = count; i > 0; i--)
		queue[i] = queue[i - 1];
	queue[0] = _num;
	count++;
	return 0;
}

int Deque::PopFront() {
	if (count < 1)
		return 0;
	return queue[(count--) - 1];
}

int Deque::PopBack() {
	if (count < 1)
		return 0;
	int c = queue[0];
	for (int i = 0; i < count - 1; i++)
		queue[i] = queue[i + 1];
	count--;
	return c;
}

bool Deque::IsEmpty() {
	if (count == 0) return 1;
	return 0;
}

bool Deque::Clear() {
	count = 0;
	return 0;
}
