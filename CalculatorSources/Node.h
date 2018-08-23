#ifndef NODE_H
#define NODE_H

namespace List
{
	template<typename T>
	struct Node
	{
		T value;
		Node* next;
		Node* previous;
		Node(const T& val) :value(val), next(nullptr), previous(nullptr) {}
	};
}

#endif;
