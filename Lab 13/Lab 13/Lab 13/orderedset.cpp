#include <cstddef> // needed for NULL on newer compilers
#include "orderedset.h"

OrderedSet::OrderedSet() {
	size = 0;
	first = last = NULL;
}

bool OrderedSet::Insert(int v) {
	Node* new_node = new Node;
	new_node->value = v; new_node->prev = NULL; new_node->next = first;
	while (new_node->next != NULL) {
		if (new_node->value == new_node->next->value) return false;
		if (new_node->value < new_node->next->value) break;
		new_node->prev = new_node->next;
		new_node->next = new_node->next->next;
	}
	Node* pred = new_node->prev;
	if (pred == NULL) first = new_node;
	else pred->next = new_node;
	if (new_node->next == NULL) last = new_node;
	else new_node->next->prev = new_node;
	++size;
	return true;
}

bool OrderedSet::Delete(int v) {
	Node* prev = first;
	Node* current = first;
	while (current != NULL) {
		if (current->value == v)
			break;
		else {
			prev = current;
			current = current->next;
		}
	}
	if (current == NULL)
		return false;
	if (current->value == first->value) {
		DeleteFirst();
		return true;
	}
	else if (current->value == last->value && current->next == NULL) {
		DeleteLast();
		return true;
	}
	else {
		Node* store_next = current->next;
		store_next->prev = prev;
		prev->next = store_next;
		delete current;
		size--;
		return true;
	}
}

bool OrderedSet::InsertFirst(int new_int) {
	Node* new_node = new Node;
	if (new_node == NULL)
		return false;
	else {
		new_node->value = new_int;
		new_node->prev = NULL;
		new_node->next = first;
		if (size != 0)
			first->prev = new_node;
		first = new_node;
		if (size == 0)
			last = first;
		size++;
	}
	return true;
}

bool OrderedSet::InsertLast(int new_int) {
	Node* new_node = new Node;
	new_node->value = new_int;
	if (first == NULL) {
		new_node->prev = new_node->next = NULL;
		first = last = new_node;
	}
	else {
		new_node->prev = last;
		last->next = new_node;
		new_node->next = NULL;
		last = new_node;
	}
	++size;
	return true;
}

bool OrderedSet::DeleteFirst() {
	if (first == 0) {
		return false;
	}
	else {
		Node* ptr = first;
		first = first->next;
		free(ptr);
		size--;
		return true;
	}
}

bool OrderedSet::DeleteLast() {
	Node* ptr = first;
	if (size < 2)
		return DeleteFirst();
	else {
		while (ptr->next != last) {
			ptr = ptr->next;
		}
		delete(ptr->next);
		ptr->next = NULL;
		last = ptr;
		size--;
		return true;
	}
}

OrderedSet::OrderedSet(const OrderedSet& other) {
	first = new Node;
	last = new Node;
	size = 0;
	Node* new_node = other.first;
	first->value = new_node->value;
	first->next = new_node->next;
	first->prev = NULL;
	last = first;
	size++;
	while (new_node->next != NULL) {
		new_node = new_node->next;
		InsertLast(new_node->value);
	}
}

void OrderedSet::apply(void function(int& param)) {
	for (Node* n = last; n != NULL; n = n->prev) {
		function(n->value);
	}
}

bool OrderedSet::operator==(const OrderedSet& other) const {
	if (this->size == other.size) {
		Node* pointer_1 = this->first;
		Node* pointer_2 = other.first;
		while (pointer_2->value != NULL) {
			if (pointer_1->value != pointer_2->value)
				return false;
			else
				return true;
			pointer_1->next;
			pointer_2->next;
		}
	}
	return false;
}

OrderedSet OrderedSet::operator+(const OrderedSet& other) {
	Node* node_b = other.first;
	for (node_b; node_b != NULL; node_b = node_b->next) {
		if (!exists(node_b->value))
			Insert(node_b->value);
	}
	return *this;
}

OrderedSet OrderedSet::operator*(const OrderedSet& other) {
	clear();
	Node* node_b = other.first;
	for (node_b; node_b != NULL; node_b = node_b->next) {
		if (node_b->value % 2 == 0)
			Insert(node_b->value);
	}
	return *this;
}

void OrderedSet::PrintBackwards(ostream& out) {
	Node* ptr = last;
	for (int i = 0; i < size; ++i) {
		out << ptr->value << " ";
		if (ptr)
			ptr = ptr->prev;
	}
}

void OrderedSet::clear() {
	while (size > 0)
		DeleteFirst();
}
bool OrderedSet::exists(int v) {
	int exists_value = 0;
	Node* new_node = this->first;
	for (int finder = 0; finder < size; ++finder) {
		if (new_node->value == v)
			exists_value = 1;
		new_node = new_node->next;
	}
	return exists_value;
}

ostream& operator<< (ostream& out, const OrderedSet& LL) {
	Node* ptr = LL.first;
	for (int i = 0; i < LL.size; ++i) {
		out << ptr->value << " ";
		if (ptr)
			ptr = ptr->next;
	}
	return out;
}