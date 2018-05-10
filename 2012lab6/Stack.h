using namespace std;
const int STACK_CAPACITY = 64;
#include <iostream>
template <class Type>
class Stack {
public:
	Stack() {};
	~Stack() {};

	/****** START YOUR DELARATION FOR PART 1 HERE ******/

	// ACCESSOR member functions:
	bool empty() const;    // Check if the stack is empty
	bool full() const;	   // Check if the stack is full
	int size() const;	   // Give the number of data currently stored

	// TODO: Overload operator "~" to retrieve the top item from the stack
	Type operator~() const;
	// TODO: Overload operator "==" to check the equality of stack objects
	bool operator==(Stack<Type>) const;
	// TODO: Overload operator "<<" to show the items stored in the stack object
	friend ostream& operator<<(ostream& os, Stack<Type>& A){
		int size=A.size();
	for(int i=size-1;i>=0;i--)
	{
		os<<A.data[i]<<'\n';
	}

	return os;
}
	// MUTATOR member functions:

	// TODO: Overload operator "+=" to add a new item to the top
	Stack<Type>& operator+=(Type);

	// TODO: Overload operator "--" to remove the top item from the stack
	//       and return the new top item (** SYNTAX: Stack<int> A; --stack; **)
	Type operator--();

	// TODO: Overload operator "--" to return the top item and remove it
	//       from the stack (** SYNTAX: Stack<int> A; stack--; **)
	Type operator--(int t);
	/******* END YOUR DELARATION FOR PART 1 HERE *******/

private:
	Type data[STACK_CAPACITY];   // Use an array to store the data
	int top_index {-1};		    // Start from 0; -1 when empty
};

/****** START YOUR IMPLEMENTATION FOR PART 1 HERE ******/


template <class Type>
bool Stack<Type>::empty() const { return (top_index == -1); }
// Check if the int_stack is full

template <class Type>
bool Stack<Type>::full() const { return (top_index == STACK_CAPACITY-1); }
// Give the number of data currently stored

template <class Type>
int Stack<Type>::size() const { return top_index + 1; }

template <class Type>
Type Stack<Type>::operator~() const
{
	if (empty()==false)
{return data[top_index];}
	else
		{cerr << "[ERROR] Stack is empty, returning a garbage value" << endl;
		return data[top_index];
		}
}

template <class Type>
bool Stack<Type>::operator==(Stack<Type> A) const
{
	int Asize=A.size();
	if(Asize!=this->size()){return false;}
	for(int i=0;i<A.size();i++)
	{
		if(A.data[i]!=this->data[i]){return false;}
	}
	return true;
}



template <class Type>
Stack<Type>& Stack<Type>::operator+=(Type num)
{
	if (full()==false)
	{data[++top_index] = num;
	return *this;
	}

	else
	{
	cerr << "[ERROR] Stack is full, can't add new value" << endl;
	return *this;
	}

}



template <class Type>
 Type Stack<Type>::operator--(int t)
{
	if (size()!=0)

	{--top_index;
	return data[top_index+1];}

			cerr << "[ERROR] Stack is empty, returning a garbage value" << endl;
			return 0.0;


}

template <class Type>
Type Stack<Type>::operator--()
{
	--top_index;
	if (size()!=0)
	{
	return data[top_index];
	}

	cerr << "[ERROR] Stack is empty, returning a garbage value" << endl;
	return 0.0;
}
/******* END YOUR IMPLEMENTATION FOR PART 1 HERE *******/
