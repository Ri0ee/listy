#pragma once

template<class TE>
class element {
public:
	element() {};
	element(TE data_, element<TE>* next_element_ptr_) : m_data(data_), m_next_element_ptr(next_element_ptr_) {}
	element(TE data_) : m_data(data_) {}
	element(element<TE>* next_element_ptr_) : m_next_element_ptr(next_element_ptr_) {}
	~element() {};

	element<TE>*& next() {
		return m_next_element_ptr;
	}

	TE& get_data() {
		return m_data;
	}

private:
	TE m_data{};
	element<TE>* m_next_element_ptr = nullptr;
};

template<class TL>
class list {
public:
	list() {}
	~list() {}

	// Push data to the end of the list
	void push(TL data_) {
		if (m_head == nullptr) {
			m_head = new element<TL>(data_);
			m_size++;
			return;
		}

		element<TL>* current_element = m_head;
		while (current_element->next() != nullptr)
			current_element = current_element->next();
		
		current_element->next() = new element<TL>(data_);

		m_size++;
	}

	// Push data before the first element (head)
	void push_front(TL data_) {
		element<TL>* new_head = new element<TL>(data_, m_head);
		m_head = new_head;

		m_size++;
	}

	// Remove last element. Returns true if removed anything
	bool pop() {
		if (m_head == nullptr) return false;

		element<TL>* current_element = m_head;
		element<TL>* previous_element = nullptr;
		while (current_element->next() != nullptr) {
			previous_element = current_element;
			current_element = current_element->next();
		}

		delete current_element;
		if (previous_element != nullptr)
			previous_element->next() = nullptr;
		else
			m_head = nullptr;

		m_size--;
		return true;
	}

	// Remove first element. Returns true if removed anything
	bool pop_front() {
		if (m_head == nullptr) return false;

		element<TL>* temp_element = m_head->next();
		delete m_head;
		m_head = temp_element;

		m_size--;
		return true;
	}

	// Inserts one element into the list
	void insert(int pos_, TL data_) {
		if (m_head == nullptr || pos_ <= 0) {
			push_front(data_);
			return;
		}

		if (pos_ >= m_size) {
			push(data_);
			return;
		}

		int current_pos = 0;
		element<TL>* current_element = m_head;
		element<TL>* previous_element = nullptr;
		while (current_element->next() != nullptr && current_pos < pos_) {
			previous_element = current_element;
			current_element = current_element->next();
			current_pos++;
		}

		previous_element->next() = new element<TL>(data_, current_element);

		m_size++;
	}

	// Removes one element from the list. Returns true if removed anything
	bool remove(int pos_) {
		if (m_head == nullptr || pos_ < 0 || pos_ >= m_size) return false;
		if (pos_ == 0) return pop_front();
		if (pos_ == m_size - 1) return pop();

		int current_pos = 0;
		element<TL>* current_element = m_head;
		element<TL>* previous_element = nullptr;
		while (current_element->next() != nullptr && current_pos < pos_) {
			previous_element = current_element;
			current_element = current_element->next();
			current_pos++;
		}

		previous_element->next() = current_element->next();
		delete current_element;

		m_size--;
		return true;
	}

	// Removes all elements from the list
	void clear() {
		while (pop_front());
	}

	// Provides one element from the list
	TL& operator[] (int index_) {
		element<TL>* current_element = m_head;
		for (int index = 0; index < index_; index++) 
			current_element = current_element->next();

		return current_element->get_data();
	}

	// Returns amount of elements in list
	int size() {
		return m_size;
	}

private:
	element<TL>* m_head = nullptr;
	int m_size = 0;
};