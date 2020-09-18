#pragma once
class Deque {
	friend void PrintElements(Deque& d);

private:
	int* queue;
	int count;

public:
	Deque();
	Deque(int queueSize);
	virtual ~Deque();
	int PushBack(int _num);
	int PushFront(int _num);
	int PopBack();
	int PopFront();
	bool IsEmpty();
	bool Clear();
};
